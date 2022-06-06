#include <ESP8266WiFi.h>
#define RELAY_PIN D1
#define RELAY_PIN2 D2
#define RELAY_PIN3 D3
#define RELAY_PIN4 D4

const char* ssid = "Karan Rajbhar";
const char* password = "1234567890";
const int port = 8080;

WiFiServer server(8080);

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(RELAY_PIN2, OUTPUT);
  pinMode(RELAY_PIN3, OUTPUT);
  pinMode(RELAY_PIN4, OUTPUT);
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Connected, IP address working: ");
  Serial.println(WiFi.localIP());

server.begin();
    
}

void loop() {
  WiFiClient client = server.available();
  while(client.connected()) {
    if (client.available()) {
      uint8_t buf;
      size_t length = 1;
      client.read(&buf, length);
      client.write(handleCmd(buf));
      
    }
  }
}

char* handleCmd(uint8_t cmd) {
  Serial.println(cmd);
  switch(cmd) {
    case 48:
        digitalWrite(RELAY_PIN, HIGH);
        return "Relay pin set to high\n";
    case 49: 
        digitalWrite(RELAY_PIN, LOW);
        return "Relay pin set to low\n";
    case 50: 
        digitalWrite(RELAY_PIN2, HIGH);
        return "Relay pin set to low\n";
    case 51: 
        digitalWrite(RELAY_PIN2, LOW);
        return "Relay pin set to low\n";
     case 52: 
        digitalWrite(RELAY_PIN3, HIGH);
        return "Relay pin set to low\n";
     case 53: 
        digitalWrite(RELAY_PIN3, LOW);
        return "Relay pin set to low\n";
     case 54: 
        digitalWrite(RELAY_PIN4, HIGH);
        return "Relay pin set to low\n";
     case 55: 
        digitalWrite(RELAY_PIN4, LOW);
        return "Relay pin set to low\n";
    default:
        return "Send ASCII 0 to 7 each relay as per divided into 2\n";
  }
}  
