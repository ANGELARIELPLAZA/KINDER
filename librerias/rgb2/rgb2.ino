
//LED Connections
const int bluepin = 16; // D0
const int redpin = 5;    // D1
const int greenpin = 4; // D2

int val;
void setup () {
  pinMode (redpin, OUTPUT);
  pinMode (bluepin, OUTPUT);
  pinMode (greenpin, OUTPUT);
}
void loop ()
{
  for (val = 255; val> 0; val --)
  {
    analogWrite (bluepin, val);
    analogWrite (greenpin, 255-val);
    analogWrite (redpin, 128-val);
    delay (15);
  }
  for (val = 0; val <255; val ++)
  {
     analogWrite (bluepin, val);
    analogWrite (greenpin, 255-val);
    analogWrite (redpin, 128-val);
    delay (15);
  }
}
