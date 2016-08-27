# jalice-ng
A C++ AIML engine forked from J-ALICE engine created by Jonathan Roewen and Taras Glek and further updated by Cuong Thai.

## Plans

* be more or less compatible with [AIML 2.0](http://callmom.pandorabots.com/static/reference/)
* adapt [Program-O's XSD schema](https://github.com/Program-O/Program-O/blob/master/admin/aiml.xsd)

## History / Changelog

* v0.4
  * separated jalice into an AIML library and clients
  * removed unnecessary features (IRC, webserver, etc.)

* v0.3 by Jonathan Roewen and Taras Glek
  * J-Alice is an AIML engine written in C++. It comes with a builtin IRC client, with support for multiple channels and servers, and a small webserver. Each IRC setup (per irc network/server) supports configuration of an IRC Server, to allow the botmaster, for example, to connect and control the bot, and even pretend to be a bot with your favourite IRC client.
