#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Wed Mar 15 16:17:46 2017

@author: harsh
"""

import paho.mqtt.client as mqtt
import time
# This is the Subscriber

def on_connect(client, userdata, flags, rc):
  print(str(client)+'\n'+str(userdata))
  print("Connected with result code "+str(rc))
  client.subscribe("t1")


def on_message(client, userdata, msg):
       print("Message arrived from "+str(client))
       print(msg.topic+" "+str(msg.payload))
client = mqtt.Client()
x=client.connect("192.168.0.107",1883,60)
client.on_connect = on_connect
client.on_message = on_message

client.loop_forever()


