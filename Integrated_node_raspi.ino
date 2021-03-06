//This file is to recieve temperature sensor data from ESP8266 and send binary values(1 or 0) to control LED connected to ESP8266.
//This program send data from raspberry pi to ESP8266 as well as recieve data from ESp8266.

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into pin D4 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices 
// (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);


// Update these with values suitable for your network.
const char* ssid = "SMART_JOULES_24";
const char* password = "joulesO23";
const char* mqtt_server = "IP address of broker";


WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
float temp = 0;
int inPin = 5;
const byte ledPin=14;

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}


void callback(char* topic, byte* payload, unsigned int length) {
 Serial.print("Message arrived [");
 Serial.print(topic);
 Serial.print("] ");
 for (int i=0;i<length;i++) {
  char receivedChar = (char)payload[i];
  Serial.print(receivedChar);
  if (receivedChar == '0'){
  digitalWrite(ledPin, HIGH);
   }
  if (receivedChar == '1'){
   digitalWrite(ledPin, LOW);
  }
  }
  Serial.println();
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a client ID
     String clientId = "Raspberry_Client-";
     clientId += String(random(0xffff), HEX);
      // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
       // ... and subscribe to topic
      client.subscribe("temp/led");
          } 
          else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup()
{
  Serial.begin(115200);
  setup_wifi(); 
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  pinMode(ledPin, OUTPUT);
  pinMode(inPin, INPUT);
  sensors.begin();
  
}

void loop()
{
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

 long now = millis();
  if (now - lastMsg > 30000) {
    lastMsg = now;
    sensors.setResolution(12);
    sensors.requestTemperatures(); // Send the command to get temperatures
    temp = sensors.getTempCByIndex(0);
    Serial.println(temp);
    if((temp > -20) && (temp <60))
      {
     
      client.publish("Temp", String(temp).c_str(),TRUE);
      }
  }
}

       
  
