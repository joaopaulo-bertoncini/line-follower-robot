#include "TCS3200.h"
#include "SensorMH.h"

void setup()
{
  Serial.begin(9600);
  configSensorLine();
  configSensorColor();
}

void loop()
{
  bool valueLeft = digitalRead(pinSensorLeft);
  bool valueRight = digitalRead(pinSensorRight);

  Serial.print("Left ");
  Serial.println(valueLeft);
  Serial.print("Right "); 
  Serial.println(valueRight);

  if (valueLeft == LINE && valueRight == LINE) {
       // motorEsq(PARADO);
       // motorDir(PARADO);
       // LEITURA DO SENSOR TCS3200
       digitalWrite(pinLED, HIGH);
       delay(250);
       readColor();
       digitalWrite(pinLED, LOW);
       delay(250);
      //Verifica se a cor vermelha foi detectada
      if (red < blue && red < green && red < 100)
      {
        Serial.println("Vermelho");
      }
     
      //Verifica se a cor azul foi detectada
      else if (blue < red && blue < green && blue < 1000)
      {
        Serial.println("Azul");
      }
     
      //Verifica se a cor verde foi detectada
      else if (green < red && green < blue)
      {
        Serial.println("Verde");
      }
    
  } else if (valueRight == LINE) {
   //   motorEsq(FRENTE, 100);
   //  motorDir(TRAS  , 100);
  } else if (valueLeft == LINE) {
   // motorEsq(TRAS  , 100);
   // motorDir(FRENTE, 100);
  } else {
   // motorEsq(FRENTE);
   // motorDir(FRENTE);
  }

  delay(50);
}
 
