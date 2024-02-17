#include <WiFi.h>
#include <HTTPClient.h>


const char* ssid = "Dina2G";
const char* password = "janneerkul";


class DirServer {
  public:
    String url;
    
    String GetData(String path) {
      while (true){
        HTTPClient http;

        String p = url + "/GET/" + path;

        http.begin(p.c_str());
    
        int re = http.GET();

        if (re) {
          return http.getString();
        }
    
        http.end();
      }
    }


    String PostData(String path, String value_) {
      while (true){
        HTTPClient http;

        String p = url + "/POST/" + path + "/" + value_;

        http.begin(p.c_str());
    
        int re = http.GET();

        if (re) {
          return http.getString();
        }
    
        http.end();
      }
    }
};

DirServer server;

void setup() {
  Serial.begin(9600); 

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

  
  server.url = "http://192.168.10.142:5555";
}

void loop() {
  if(WiFi.status() == WL_CONNECTED) {
    Serial.print("PostData: ");
    Serial.println(server.PostData("serverdata-temp", "69.99999"));
    
    delay(2000);
    
    Serial.print("GetData: ");
    Serial.println(server.GetData("serverdata-temp"));
    
    delay(15000);
    
  }
}
