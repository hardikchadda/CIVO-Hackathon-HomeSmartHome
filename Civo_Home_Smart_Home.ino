#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#define fancyLights D5
#define tubeLight D4
#define fan D3
WiFiClientSecure client;
HTTPClient http;  
 
const char* ssid = "Hardik";
const char* password = "hardik123";
 
void setup () {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED, OUTPUT); 
 
  Serial.begin(115200);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
  
    delay(1000);
    Serial.println("Connecting..");
    client.setInsecure(); 
  }
}
 
void loop() {

    //Check of FancyLights
    http.begin(client, "https://shielded-taiga-07974.herokuapp.com/api/devices/2dd5f699-b5b8-497d-9b29-f804718330fe/");  
    int httpCode = http.GET();                                  
    Serial.println("___HTTP GET___");
    Serial.println(http.GET());
    
    if (httpCode > 0) {
 
      String payload = http.getString();   
      Serial.println(payload);             
      if (payload.indexOf("true")>0){
        Serial.println(payload.indexOf("true"));
        digitalWrite(fancyLights, HIGH);
        digitalWrite(LED, HIGH);
      }
      if (payload.indexOf("false")>0){
        Serial.println(payload.indexOf("false"));
        digitalWrite(fancyLights, LOW);
        digitalWrite(LED, LOW);
      }
      client.flush();
    }
    
    http.end();
    delay(10)
    //Check of tubeLight
    http.begin(client, "https://shielded-taiga-07974.herokuapp.com/api/devices/4f494333-eb62-4c76-9d5c-abdcf6068585/");  
    int httpCode = http.GET();                                  
    Serial.println("___HTTP GET___");
    Serial.println(http.GET());
    
    if (httpCode > 0) {
 
      String payload = http.getString();   
      Serial.println(payload);             
      if (payload.indexOf("true")>0){
        Serial.println(payload.indexOf("true"));
        digitalWrite(tubeLight, HIGH);
        digitalWrite(LED, HIGH);
      }
      if (payload.indexOf("false")>0){
        Serial.println(payload.indexOf("false"));
        digitalWrite(LED_BUILTIN, LOW);
        digitalWrite(LED, LOW);
      }
      client.flush();
    }
    
    http.end();
    delay(10);
    //Check of Fan
    http.begin(client, "https://shielded-taiga-07974.herokuapp.com/api/devices/def2e120-313e-4d8f-ba4e-edd5b2771879/");  
    int httpCode = http.GET();                                  
    Serial.println("___HTTP GET___");
    Serial.println(http.GET());
    
    if (httpCode > 0) {
 
      String payload = http.getString();   
      Serial.println(payload);             
      if (payload.indexOf("true")>0){
        Serial.println(payload.indexOf("true"));
        digitalWrite(LED_BUILTIN, HIGH);
        digitalWrite(LED, HIGH);
      }
      if (payload.indexOf("false")>0){
        Serial.println(payload.indexOf("false"));
        digitalWrite(LED_BUILTIN, LOW);
        digitalWrite(LED, LOW);
      }
      client.flush();
    }
    
    http.end();
 
  delay(500);
}
