# MQTT-Implementation
MQTT implementation over mosquitto broker between Raspberry Pi and NodeMCU(ESP8266)

MQTT is a machine-to-machine (M2M)/"Internet of Things" connectivity protocol. It was designed as an extremely lightweight publish/subscribe messaging transport. It is useful for connections with remote locations where a small code footprint is required and/or network bandwidth is at a premium. 

This repository contains codes to send data from raspberry pi to ESP8266, recieve data from ESP8266 onto raspberry pi, Send data from ESP8266 to raspberry pi, receive data from raspberry pi onto ESP8266 and send/recieve data from raspberry pi and node/send/recieve data from esp8266.

The user need to install a broker onto the system, here I have installed it on my raspberru pi.Many open source broker are available like Mosquitto, Mocha and also licensed broker like HIVEMQ and VERNEMQ are also available.

Guide to use this repository:
//The below steps are to recieve data from ESP8266 onto raspberry pi and sending data from ESP8266 onto the raspberry pi.
1. First burn the (NODE_MQTT.ino) file onto the ESP8266 and the file (mqtt-subscriber.py) onto the raspberry pi.
2. Open a broker on the port 1883 which is the default port of MQTT.
3. You can use a open source broker like MOsquitto or Mocha orcan use a licensed versions like HIVEMQ and VerneMQ.

//To use send data from raspberry pi onto the ESP8266 follow the below steps:
1. Burn the file (NODE_MQTT_Raspi-node.ino) onto the ESP8266 and file (raspberry-node_mqtt.py) onto to the raspberry pi.
2. Open the broker on to the port 1883.

//To send and recieve data from ESP8266 to rapsberry as well as from the Raspberry pi to the ESP8266.
1. Burn the file(Integrated_node_raspi.ino) onto the ESP8266 and file (integrated_node_raspi.py) onto to the raspberry pi.
2. Open the broker onto the port 1883
