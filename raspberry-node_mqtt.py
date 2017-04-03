import paho.mqtt.publish as publish
import time
print("Sending 0........")
publish.single("ledstatus","0",hostname="IP of Broker")
time.sleep(20)
print("Sending 1........")
publish.single("ledstatus", "1", hostname="IP of Broker")
