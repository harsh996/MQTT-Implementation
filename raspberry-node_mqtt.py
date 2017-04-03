import paho.mqtt.publish as publish
import time
print("Sending 0........")
publish.single("ledstatus","0",hostname="192.168.0.107")
time.sleep(20)
print("Sending 1........")
publish.single("ledstatus", "1", hostname="192.168.0.107")
