import paho.mqtt.publish as publish
import paho.mqtt.client as mqtt
import time

# Subscribing to the topic "temp"
def on_connect(client, userdata, flags, rc):
  print(str(client)+'\n'+str(userdata))
  print("Connected with result code "+str(rc))
  client.subscribe("Temp")


def on_message(client, userdata, msg):
       print("Message arrived from "+str(client))
       print(msg.topic+" "+str(msg.payload))
client = mqtt.Client()
x=client.connect("IP address of the broker",1883,60)
client.on_connect = on_connect
client.on_message = on_message

#Publish to the topic "temp/led"
print("Sending 0........")
publish.single("temp/led","0",hostname="IP address of the broker")
time.sleep(30)
print("Sending 1........")
publish.single("temp/led", "1", hostname="IP address of the broker")

client.loop_forever()
