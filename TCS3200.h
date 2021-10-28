#define s0 2
#define s1 3
#define s2 4
#define s3 5
#define out 6
#define pinLED 7

//Variaveis cores
int red = 0;
int green = 0;
int blue = 0;
int white = 0;

void configSensorColor() {
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(pinLED, OUTPUT);
  pinMode(out, INPUT);
  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);
  digitalWrite(pinLED, LOW);
}

void readColor()
{
  //Rotina que le o valor das cores
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  //count OUT, pRed, RED
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s3, HIGH);
  //count OUT, pBLUE, BLUE
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s2, HIGH);
  //count OUT, pGreen, GREEN
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  //Mostra valores no serial monitor
  Serial.print(" Value Red :");
  Serial.print(red, DEC);
  Serial.print(" Value Green : ");
  Serial.print(green, DEC);
  Serial.print(" Value Blue : ");
  Serial.print(blue, DEC);
  Serial.println();
}
