/* 
CODIGO PARA VERIFICAR PINES DE ESP8266 Y D1 MINI
D0=16  D1=5  D2=4  D3=0  D4=2  
D5=14  D6=12  D7=13 D8=15 
*/

int rojo  = 4; //D2
int verde = 0; //D3
int azul  = 2; //D4
void setup() {
  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
}
void loop() {
  RGB_color(255, 0, 0); // Red
  delay(1000);          //TIEMPO DE ESPERA ENTRE CAMBIO DE COLOR
  RGB_color(0, 255, 0); // Green
  delay(1000);          //TIEMPO DE ESPERA ENTRE CAMBIO DE COLOR
  RGB_color(0, 0, 255); // Blue
  delay(1000);          //TIEMPO DE ESPERA ENTRE CAMBIO DE COLOR
  RGB_color(255, 255, 125); // Raspberry
  delay(1000);          //TIEMPO DE ESPERA ENTRE CAMBIO DE COLOR
  RGB_color(0, 255, 255); // Cyan
  delay(1000);          //TIEMPO DE ESPERA ENTRE CAMBIO DE COLOR
  RGB_color(255, 0, 255); // Magenta
  delay(1000);           //TIEMPO DE ESPERA ENTRE CAMBIO DE COLOR
  RGB_color(255, 255, 0); // Yellow
  delay(1000);            //TIEMPO DE ESPERA ENTRE CAMBIO DE COLOR
  RGB_color(255, 255, 255); // White
  delay(1000);
}
void RGB_color(int rojoValue, int verdeValue, int azulValue)
{
  analogWrite(rojo, rojoValue); 
//  analogWrite(verde, verdeValue);
  analogWrite(azul, azulValue);
}
