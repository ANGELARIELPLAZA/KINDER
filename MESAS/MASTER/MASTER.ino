/*
 * Hello world web server
 * circuits4you.com
 */
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WiFi.h>
 
//Nombre de red
const char* nombre = "IZZI-9146";
 
//Password
const char* password = "F82DC0169146";
 
// Puerto (se suele usar 80 por defecto, pero en algunos casos hay que
// consultar al proveedor de internet de cual dispone en su conexion)
WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(50); // breve espera para que se concrete la conexion
 
  // Conexion al WiFi 
  WiFi.begin(nombre, password);
  while (WiFi.status() != WL_CONNECTED)
    delay(100); //aqui debemos esperar unos instantes
  Serial.println("Conexión exitosa a WiFi");
 
// Iniciar el servidor
  server.begin();
  Serial.println("Iniciado el servidor");
 
  // Escribir la direccion IP
  Serial.print("el IP es: ");
  Serial.print(WiFi.localIP());
  Serial.println("");
}
 
void loop() {
  // Comprobar si se ha conectado algun cliente
  WiFiClient client = server.available();
  
  if (client) {
    Serial.println("Nueva conexion");
   
    // Escribir las cabeceras HTML
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
  
    //Escribir el contenido que vamos a visualizar
    client.println("<html>");
    client.println("<body>");
    client.print("Saludos de Robots Argentina");
    client.println("</body>");
    client.println("</html>");
  }
  delay(1000); // reescribe cada 1 segundo
}
