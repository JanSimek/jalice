#include "../../src/Kernel.h"
#include "../../src/Memory.h"
#include "../../src/Utils.h"

#include <iostream>
#include <string>

#include <Swiften/Swiften.h>
#include <boost/optional/optional_io.hpp>  // because of Swiften::Message()

using namespace std;
using namespace Swift;
using namespace boost;

class Bot
{
 public:
  Bot(BoostNetworkFactories *networkFactories, std::string jid, std::string password)
  {
    client = new Client(jid, password, networkFactories);
    client->setAlwaysTrustCertificates();
    client->onConnected.connect(boost::bind(&Bot::handleConnected, this));
    client->onMessageReceived.connect(boost::bind(&Bot::handleMessageReceived, this, _1));
    client->onPresenceReceived.connect(bind(&Bot::handlePresenceRceived, this, _1));
    client->onDisconnected.connect(bind(&Bot::handleDisconnected, this));

    // xmlTracer = new ClientXMLTracer(client);

    client->connect();

    k = new Kernel();
    std::cout << k->bootstrap() << std::endl;

    botname = k->respond("BOT NAME", "system");
    username = "localhost";
  }

  ~Bot()
  {
    if (client->isActive())
    {
      std::cerr << "BOT: client is still active. Should end the session\n";
    }

    delete client;
    // delete xmlTracer;
  }

 private:
  // XMPP
  Client *client;
  // ClientXMLTracer *xmlTracer;

  // jalice AIML
  Kernel *k;

  std::string botname, username;

  void handleConnected()
  {
    GetRosterRequest::ref rosterRequest = GetRosterRequest::create(client->getIQRouter());
    rosterRequest->onResponse.connect(bind(&Bot::handleRosterReceived, this, _2));
    rosterRequest->send();
    std::cout << "BOT: connected" << std::endl;
  }

  void handleDisconnected() { std::cout << "BOT: disconnected" << std::endl; }
  void handleMessageReceived(Message::ref message)
  {
    if (!message->getBody())
    {
      Message::Type type = message->getType();
      std::string stype = "";

      switch (type)
      {
        case Message::Type::Normal:
          stype = "NORMAL";
          break;
        default:
          stype = "NO TYPE";
      }

      std::cerr << "BOT: received message without body from " << message->getFrom() << "(" << stype << ")" << std::endl;
      return;
    }

    std::cout << "BOT: message received from " << message->getFrom() << ": " << message->getBody() << std::endl;

    if (*message->getBody() == "bye")
    {
      client->disconnect();
      return;
    }

    std::shared_ptr<Message> response(new Message());
    response->setFrom(JID());
    response->setTo(message->getFrom());
    std::string msg = respond(*message->getBody());
    response->setBody(msg);

    ::sleep(5);

    client->sendMessage(response);
  }

  void handlePresenceRceived(Presence::ref presence)
  {
    // Automatically approve presence requests
    if (presence->getType() == Presence::Subscribe)
    {
      Presence::ref response = Presence::create();
      response->setTo(presence->getFrom());
      response->setType(Presence::Subscribed);
      client->sendPresence(presence);
    }
  }

  void handleRosterReceived(ErrorPayload::ref error)
  {
    if (error) std::cerr << "Error receiving roster. Continuing anyway." << std::endl;

    // Send initial available presence
    client->sendPresence(Presence::create("Ready to rock&roll"));
  }

  std::string respond(std::string message)
  {
    string response = "";

    username = Memory::getValue("name", "localhost");
    if (username.empty())
    {
      username = "localhost";
    }

    std::cout << username << " > " << message << std::endl;

    response = Kernel::respond(message, "localhost");
    if (response.length() > 0)
    {
      response = trim(response);
    }

    std::cout << botname << " > " << response << std::endl;
    return response;
  }
};

int main(int argc, char **argv)
{
  if (argc != 3)
  {
    std::cerr << "Usage: " << argv[0] << " nick@example.com password" << std::endl;
    return EXIT_FAILURE;
  }

  SimpleEventLoop eventLoop;
  BoostNetworkFactories factories(&eventLoop);

  Bot bot(&factories, argv[1], argv[2]);

  eventLoop.run();

  return EXIT_SUCCESS;
}
