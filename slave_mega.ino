#define FL_PWM 2
#define FL_IN1 3
#define FL_IN2 4

#define FR_PWM 5
#define FR_IN1 6
#define FR_IN2 7

#define RL_PWM 8
#define RL_IN1 9
#define RL_IN2 10

#define RR_PWM 11
#define RR_IN1 12
#define RR_IN2 13


float speedFL, speedFR, speedRL, speedRR;
unsigned long lastCmdTime = 0;
const unsigned long TIMEOUT = 500;

void setup() {
  Serial.begin(38400);

  int pins[] = {
    FL_IN1, FL_IN2, FR_IN1, FR_IN2,
    RL_IN1, RL_IN2, RR_IN1, RR_IN2
  };
  for (int i = 0; i < 8; i++) pinMode(pins[i], OUTPUT);

  stopAll();
  Serial.println("Slave ready");
}

void loop() {
  if (Serial.available()) {
    speedFL = Serial.parseFloat();
    speedFR = Serial.parseFloat();
    speedRL = Serial.parseFloat();
    speedRR = Serial.parseFloat();

    Serial.print("RX: ");
    Serial.print(speedFL); Serial.print(" ");
    Serial.print(speedFR); Serial.print(" ");
    Serial.print(speedRL); Serial.print(" ");
    Serial.println(speedRR);

    setMotor(FL_IN1, FL_IN2, FL_PWM, speedFL);
    setMotor(FR_IN1, FR_IN2, FR_PWM, speedFR);
    setMotor(RL_IN1, RL_IN2, RL_PWM, speedRL);
    setMotor(RR_IN1, RR_IN2, RR_PWM, speedRR);

    lastCmdTime = millis();
  }

  if (millis() - lastCmdTime > TIMEOUT) {
    stopAll();
  }
}

void setMotor(int IN1, int IN2, int PWM, int speed) {
  if (speed > 0) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  } else if (speed < 0) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  } else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  }
  analogWrite(PWM, abs(speed));
}

void stopAll() {
  setMotor(FL_IN1, FL_IN2, FL_PWM, 0);
  setMotor(FR_IN1, FR_IN2, FR_PWM, 0);
  setMotor(RL_IN1, RL_IN2, RL_PWM, 0);
  setMotor(RR_IN1, RR_IN2, RR_PWM, 0);
}
