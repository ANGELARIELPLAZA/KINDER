#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid          = "RESPALDO";
const char* password = "19080530";
const char* mqttServer = "192.168.0.17";    // IP adress Raspberry Pi
const int mqttPort = 1883;
const char* mqttUser = "ariel";      // if you don't have MQTT Username, no need input
const char* mqttPassword = "123";  // if you don't have MQTT Password, no need input
char miArray[6] = {};
String color;
WiFiClient espClient;
PubSubClient client(espClient);

//LED Connections
const int bluepin = 16; // D0
const int redpin = 5;    // D1
const int greenpin = 4; // D2


void setup() {

  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");

  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);

  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");

    if (client.connect("ESP8266Client", mqttUser, mqttPassword )) {

      Serial.println("connected");

    } else {

      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);

    }
  }
   pinMode (redpin, OUTPUT);
  pinMode (bluepin, OUTPUT);
  pinMode (greenpin, OUTPUT);

}

void callback(char* topic, byte* payload, unsigned int length) {

  Serial.print("Message arrived in topic: ");
  Serial.println(topic);

  Serial.print("Message:");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
    miArray[i] = (char)payload[i];
  }
  Serial.println();

  Serial.println( miArray);
  color = miArray;


  Serial.println();
  String hexstring = color ;

  // Get rid of '#' and convert it to integer
  int number = (int) strtol( &hexstring[1], NULL, 16);

  // Split them up into r, g, b values
  int r = number >> 16;
  int g = number >> 8 & 0xFF;
  int b = number & 0xFF;
  //  //Saperate Colors are sent through javascript
  //  String red = server.arg("r");
  //  String green = server.arg("g");
  //  String blue = server.arg("b");
  //  int r = red.toInt();
  //  int g = green.toInt();
  //  int b = blue.toInt();
  //
  Serial.print("Red:"); Serial.println(r);
  Serial.print("Green:"); Serial.println(g);
  Serial.print("Blue:"); Serial.println(b);
  //
  //  //PWM Correction 8-bit to 10-bit
  //    r = r * 4;
  //    g = g * 4;
  //    b = b * 4;
  analogWrite (bluepin, b);
  analogWrite (greenpin, 255 - g);
  analogWrite (redpin, 128 - r);
  //
  //  //for ULN2003 or Common Cathode RGB Led not needed
  //  /*
  //   r = 1024 - r;
  //   g = 1024 - g;
  //   b = 1024 - b;
  //  */
  //  //ESP supports analogWrite All IOs are PWM
  //   analogWrite(RedLED,r);
  //   analogWrite(GreenLED,g);
  //   analogWrite(BlueLED,b);

  Serial.println();
  Serial.println("-----------------------");



}

void loop() {
  client.subscribe("mesa1");
  delay(100);
  client.loop();
}
