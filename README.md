# jalice-ng
A C++ AIML engine forked from J-ALICE engine created by Jonathan Roewen and Taras Glek and further updated by Cuong Thai.

## Plans

* be more or less compatible with [AIML 2.0](http://callmom.pandorabots.com/static/reference/)
* adapt [Program-O's XSD schema](https://github.com/Program-O/Program-O/blob/master/admin/aiml.xsd) and use xmllint to validate against it

## History / Changelog

* v0.4
  * separated jalice into an AIML library and clients
  * removed unnecessary features (IRC, webserver, etc.)

* v0.3 by Jonathan Roewen and Taras Glek
  * J-Alice is an AIML engine written in C++. It comes with a builtin IRC client, with support for multiple channels and servers, and a small webserver. Each IRC setup (per irc network/server) supports configuration of an IRC Server, to allow the botmaster, for example, to connect and control the bot, and even pretend to be a bot with your favourite IRC client.

## Changes to the original AIML interpreter

* **case:** condition is not met
    * **original behaviour:** use the first <li> without the "value" attribute
    * **jalice-ng behaviour:** random <li> item without the "value" attribute is chosen when condition is not met

    ```xml
    <category>
            <pattern>I AM _ YEARS OLD</pattern>
            <template>
                    <think>
                            <set name="age">
                                    <star/>
                            </set>
                    </think>
                    <condition name="age">
                            <li value="27">Most people die at 27, we just bury them at 72. Mark Twain said that.</li>
                            <!-- if not 27, random list item below will be selected -->
                            <li>Only <star/>? You are quite mature.</li>
                            <li>You are too old for me.</li>
                            <li>Can you explain how it feels to be <star/> years old?</li>
                            <li>What is your fondest memory?</li>
                            <li>Oh, you were born in the 20th century!</li>
                            <li>What are the advantages to being <star/> years old?</li>
                    </condition>
            </template>
    </category>
    ```
