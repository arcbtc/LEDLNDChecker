
#include <WiFiClientSecure.h>

const char* ssid     = "SSIDNAME";     // your network SSID (name of wifi network)
const char* password = "PASSWORD"; // your network password

const char*  server = "room77.raspiblitz.com";  // Server URL

const char* test_root_ca = // needs to be in this crazy format
    "-----BEGIN CERTIFICATE-----\n" \
    "MIICBTCCAaqgAwIBAgIQBSMZ9g3niBo1jyzK1DvECDAKBggqhkjOPQQDAjAyMR8w\n" \
    "HQYDVQQKExZsbmQgYXV0b2dlbmVyYXRlZCBjZXJ0MQ8wDQYDVQQDEwZSb29tNzcw\n" \
    "HhcNMTkwNTE2MjAwODUwWhcNMjAwNzEwMjAwODUwWjAyMR8wHQYDVQQKExZsbmQg\n" \
    "YXV0b2dlbmVyYXRlZCBjZXJ0MQ8wDQYDVQQDEwZSb29tNzcwWTATBgcqhkjOPQIB\n" \
    "BggqhkjOPQMBBwNCAAQJ3795aca5YP6AaUtcvlSqopqR7ePzLshQoTUeV6FVKbFC\n" \
    "CC+fVGRQsXJx+GVUknnNEcJTt/fQ9CmM6stqGPjAo4GhMIGeMA4GA1UdDwEB/wQE\n" \
    "DVQQDEwZSb29tNzcwWTATBgcqhkjOPQIA1UdEQR0MHKCBlJvb203N4IJbG9jYWxo\n" \
    "b3N0ghVyb29tNzcucmFzcGlibGl0ei5jb22CBHVuaXiCCnVuaXhwYWNrZXSHBH8A\n" \
    "AAGHEAAAAAAAAAAAAAAAAAAAAAGHBMCoskqHEP6AAAAAAAAA+OWZZHfUV0qHBAAA\n" \
    "AAAwCgYIKoZIzj0EAwIDSQAwRgIhALKz3oScii3i+5ltMVQc9u2O38rgfnGCj5Lh\n" \
    "u9iwcAiZAiEA0BjRcisPUlG+SE/s+x6/A2NuT0gtIZ3PKd/GuM5T0jM=\n" \
    "-----END CERTIFICATE-----\n";

WiFiClientSecure client;

void setup() {

  Serial.begin(115200);
  delay(100);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
   pinMode(26, OUTPUT);
   pinMode(27, OUTPUT);
}

void loop() {
  
  client.setCACert(test_root_ca);
  
  if (!client.connect(server, 8077))
  {
    digitalWrite(27, LOW);
    digitalWrite(26, HIGH);
  }
  else {
    digitalWrite(27, HIGH);
    digitalWrite(26, LOW);
  }

    client.stop();

    delay(2000);

}
