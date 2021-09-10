#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid          = "RESPALDO";
const char* password = "19080530";
const char* mqttServer = "192.168.0.10";    // IP adress Raspberry Pi
const int mqttPort = 1883;
const char* mqttUser = "ariel";      // if you don't have MQTT Username, no need input
const char* mqttPassword = "123";  // if you don't have MQTT Password, no need input
char miArray[6] = {};
String color;
WiFiClient espClient;
PubSubClient client(espClient);

//LED Connections
const int bluepin = 13; // D0
const int redpin = 12;    // D1
const int greenpin = 14; // D2


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

  if (color == "1" )
  {
    RGB_color(255, 0, 0); // Red
    Serial.print("rojo");
  }
  if (color == "2" )
  {
    RGB_color(0, 255, 0); // Green
    Serial.print("verde");

  }

  if (color == "3" )
  {
    RGB_color(0, 0, 255); // Blue
    Serial.print("azul");

  }
  if (color == "4" )
  {
    RGB_color(255, 0, 255); // Magenta
    Serial.print("magenta");

  }
  if (color == "5" )
  { 
    RGB_color(255, 233, 0); // Yellow
     Serial.print("amarillo");
      
  }
  if (color == "6" )
  {
    RGB_color(255, 255, 255); // white
        Serial.print("blanco");


  }
   if (color == "0" )
  {
    RGB_color(0, 0, 0); // apagado
      Serial.print("apagar");

  }


  Serial.println();
  Serial.println("-----------------------");



}
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
{
  analogWrite(redpin, red_light_value);
  analogWrite(greenpin, green_light_value);
  analogWrite(bluepin, blue_light_value);
}
void loop() {
  client.subscribe("mesa3");
  delay(100);
  client.loop();
}
