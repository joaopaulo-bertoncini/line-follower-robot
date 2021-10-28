#define pinSensorRight 8
#define pinSensorLeft 9
#define LINE HIGH

void configSensorLine() {
  pinMode(pinSensorRight, INPUT);
  pinMode(pinSensorLeft, INPUT);
}
