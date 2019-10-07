#include <Arduino.h>
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

#define RED_PIN D2
#define GREEN_PIN D1
#define BLUE_PIN D0

const char* ssid     = "Freepik";
const char* password = "NewFreepik2018";

//const char* ssid     = "MIWIFI_2G_bgFn";
//const char* password = "5q3AMaaa";

void setup() {
  Serial.begin(115200);

  // We start by connecting to a WiFi network
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  /* Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default,
     would try to act as both a client and an access-point and could cause
     network-issues with your other WiFi-devices on your WiFi-network. */
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void resetColor()
{
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
}

void paintBlue()
{
  resetColor();
  digitalWrite(BLUE_PIN, HIGH);
}

void paintRed()
{
  resetColor();
  digitalWrite(RED_PIN, HIGH); 
}

void paintGreen()
{
  resetColor();
  digitalWrite(GREEN_PIN, HIGH); 
}

void loop() {
  WiFiClient client;
  HTTPClient httpClient;

  // We send check info to endpoint
  httpClient.begin(client, "http://cucumber-clon.duckdns.org/sesame/check?userCookie=XXXXXX");
  httpClient.addHeader("Content-Type", "application/json");

  Serial.println("[HTTP]...Begin connection to http://cucumber-clon.duckdns.org/");

  int httpStatusCode  = httpClient.GET();

  if (httpStatusCode > 0) {
    Serial.println("[HTTP]...GET");
    
    Serial.print("[HTTP]...Code: ");
    Serial.println(httpStatusCode);

    if (httpStatusCode == HTTP_CODE_OK) {
      StaticJsonDocument<100> jsonBuffer;

      // We get request body in string format
      String payload = httpClient.getString();

      // We decode the response using json parser
      DeserializationError err = deserializeJson(jsonBuffer, payload);

      if (err) {
        Serial.print("[JSON]...Error code");
        Serial.print(err.c_str());
        Serial.println("[JSON]...Unable to decode json");
      }

      if(!err) {
        int sesameStatus = jsonBuffer["status"];

        if (sesameStatus == 0) {
          paintBlue();
        }

        if (sesameStatus == 1) {
          paintRed();
        }

        if (sesameStatus == 2) {
          paintGreen();
        }
      
        Serial.print("[HTTP]...Status:");
        Serial.println(sesameStatus);
      }
    }
    
  } else {
    Serial.println("[HTTP]...Unable to connect");
  }

  delay(10000);
}
