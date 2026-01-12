#include <math.h>

const int SW1_pin = 2;
const int X1_pin = A0;
const int Y1_pin = A1;
const int SW2_pin = 4;
const int X2_pin = A2;
const int Y2_pin = A3;

int x, y, ry;
float vx, vy, vry;
float FR, FL, RR, RL;
float speed_FR, speed_FL, speed_RR, speed_RL;


void setup() {
  Serial.begin(38400);

  pinMode(SW1_pin, INPUT_PULLUP);
  pinMode(SW2_pin, INPUT_PULLUP);
}

void loop() {
  x = analogRead(X1_pin);
  y = analogRead(Y1_pin);
  ry = analogRead(Y2_pin);

  vx = x / 512.0 - 1;
  vy = (1023 - y) / 512.0 - 1;
  vry = ry / 512.0 - 1;

  if (abs(vx) < 0.15) vx = 0;
  if (abs(vy) < 0.15) vy = 0;
  if (abs(vry) < 0.15) vry = 0;

  float den = max(abs(vx) + abs(vy) + abs(vry), 1.0);

  FL = (vy + vx + vry) / den;
  FR = -(vy - vx - vry) / den;
  RL = (vy - vx + vry) / den;
  RR = -(vy + vx - vry) / den;

  speed_FL = set_power(FL);
  speed_FR = set_power(FR);
  speed_RL = set_power(RL);
  speed_RR = set_power(RR);

  Serial.print(speed_FL);
  Serial.print(",");
  Serial.print(speed_FR);
  Serial.print(",");
  Serial.print(speed_RL);
  Serial.print(",");
  Serial.println(speed_RR);

  delay(100);
}

int set_power(float power){
  float max_power = 0.5;
  float power_3 = power * power * power;
  if(abs(power) <= 0.15){
    return 0;
  } else {
    float speed = power_3 * 255 * max_power;
    return int(speed);
  }
}
