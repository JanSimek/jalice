#include "SocketHandler.h"

#ifdef WIN32
 #include <winsock.h>
#else
 #include <netdb.h>
 #include <sys/socket.h>
#endif
#include <unistd.h>
#include <stdio.h>

#include "Socket.h"

#include <iostream>

using namespace std;

bool SocketHandler::alreadyRunning = false;
set<Socket *> SocketHandler::sockets;

void SocketHandler::runLoop() {
    if (alreadyRunning) {
        return;
    }
    alreadyRunning = true;
    
    Socket *sock;
    int socket, result;
    set<Socket *>::iterator it;
    
    while (!sockets.empty()) {
        fd_set input_sockets;

        FD_ZERO(&input_sockets);
        for (it = sockets.begin(); it != sockets.end(); ++it) {
            sock = *it;
            if (sock != NULL) {
                socket = sock->getSD();
            } else {
                socket = -1;
            }
            if (socket != -1) {
                FD_SET(socket, &input_sockets);
            }
        }
        
        struct timeval timeout;
        
        timeout.tv_sec = 2;
        timeout.tv_usec = 500 * 1000;
        
        #ifdef WIN32
            result = select(FD_SETSIZE, (fd_set FAR *)&input_sockets, NULL, NULL, (const struct timeval FAR *)&timeout);
        #else
            result = select(FD_SETSIZE, &input_sockets, NULL, NULL, &timeout);
        #endif
        switch (result) {
            case 0:    //    Timeout on the sockets
                continue;
            case -1:
                perror("select");
                alreadyRunning = false;
                return;    //    I guess this is right afterall
                //    Otherwise get stuck in an infinite loop...
        }
        for (it = sockets.begin(); it != sockets.end(); ++it) {
            sock = *it;
            if (sock != NULL) {
                socket = sock->getSD();
            } else {
                socket = -1;
            }
            if (socket != -1 && FD_ISSET(socket, &input_sockets)) {
                sock->process();
            }
        }
    }
    alreadyRunning = false;
}

void SocketHandler::insertSocket(Socket *socket) {
    sockets.insert(socket);
}

void SocketHandler::eraseSocket(Socket *socket) {
    sockets.erase(socket);
}
