#include <Arduino.h>
#include <ArduinoJson.h>        // https://github.com/bblanchon/ArduinoJson
#include <WiFi.h>               // In-built

/// mqtt
char* host = "192.168.1.20";  // your own mqtt server IP
int httpPort = 8080; 

const int wash = 45; // washing machine icon at 45°
const int disher = 550 ; //disher icon at 550W 

/// list of values to print : {{"name","IDX","codeJson"},{"Prod","28","CounterToday"}, {} }  // {} --> free zone

// max values
const int max_val=12;
const String mqtt_IDX[max_val][3] = {{"Ballon","61","Data"},{"Batterie","83","Data"},{},{"Linky","28","Usage"},{"Today","28","CounterToday"},{},{"Solaire","29","Usage"},{"Today","29","CounterToday"},{},{"Gazpar","55","CounterToday"}} ; 
String mqtt_result[max_val]; 

String json_mqtt(char* host, int httpPort , String idx){
WiFiClient client;

if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return "connection failed";
  }
  
   String url = "/json.htm?type=devices&rid="+idx;
  Serial.print("requesting URL: ");
  Serial.println(url);

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: BuildFailureDetectorESP8266\r\n" +
               "Connection: close\r\n\r\n");

  Serial.println("request sent");
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("headers received");
      break;
    }
  }
  String line = client.readStringUntil('OK');
  Serial.println("=======DATA ===");
  return line;
}

/////////////////// get "data" in json


void get_data_mqtt() {
  String json_data;
  const size_t capacity = 2*JSON_ARRAY_SIZE(1) + JSON_OBJECT_SIZE(16) + JSON_OBJECT_SIZE(50) + 1270;
  DynamicJsonDocument doc(capacity);

  //récupération des données dans mqtt
   for (int i = 0; i <= max_val ; i++) {

    if (mqtt_IDX[i][0] != NULL ) {
      json_data = json_mqtt(host, httpPort, mqtt_IDX[i][1]);
      DeserializationError error = deserializeJson(doc, json_data);
      JsonObject root = doc.as<JsonObject>();
      JsonObject result0 = root["result"][0];
      const char* clean_data = result0[mqtt_IDX[i][2]];
      mqtt_result[i] = clean_data ;
    //  Serial.println(mqtt_result[i]);
      Serial.println(clean_data);
    }
  }

  
}
