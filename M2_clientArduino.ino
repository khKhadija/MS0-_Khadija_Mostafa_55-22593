/*
    This sketch sends a string to a TCP server, and prints a one-line response.
    You must run a TCP server in your local network.
    For example, on Linux you can use this command: nc -v -l 3000
*/

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#ifndef STASSID
#define STASSID "khadija"
#define STAPSK "khadija1"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

const char* host = "192.168.160.153";
const uint16_t port = 6082;

boolean flag= true;
ESP8266WiFiMulti WiFiMulti;
int outputpin= A0;
void setup() {
  Serial.begin(9600);

  // We start by connecting to a WiFi network
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(ssid, password);

  Serial.println();
  Serial.println();
  Serial.print("Wait for WiFi... ");

  while (WiFiMulti.run() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  delay(500);
}


void loop() {
  Serial.print("connecting to ");
  Serial.print(host);
  Serial.print(':');
  Serial.println(port);

  // Use WiFiClient class to create TCP connections
  WiFiClient client;

  if (!client.connect(host, port)) {
    Serial.println("connection failed");
    Serial.println("wait 5 sec...");
    delay(5000);
    return;
  }
  while(true){
 int analogValue = analogRead(outputpin);
 float millivolts = (analogValue/1024.0) * 3300; //3300 is the voltage provided by NodeMCU
 float celsius = millivolts/10;
 Serial.print("in DegreeC=   ");
 Serial.println(celsius);
 float fahrenheit = ((celsius * 9)/5 + 32);
 Serial.print(" in Farenheit=   ");
 Serial.println(fahrenheit);
 delay(1000);
  // This will send the request to the server
  client.println("hello from ESP8266");
  client.print("in DegreeC=   ");
 client.println(celsius);
 client.print("in Farenheit=   ");
 client.println(fahrenheit);
  client.println("receiving from remote server");

  // read back one line from server
  Serial.println("receiving from remote server");
  String line = client.readStringUntil('\r');
  Serial.println(line);

 // Serial.println("closing connection");
  // client.stop();
  }
  Serial.println("wait 5 sec...");
  delay(5000);
}
