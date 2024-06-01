// Sensor pins
const int leftSensorPin = A4;
const int middleSensorPin = A3;
const int rightSensorPin = A2;

// Motor control pins
const int LM_EN = 2;   // Left motor enable (PWM)
const int LM_IN1 = 3;  // Left motor input 1
const int LM_IN2 = 4;  // Left motor input 2
const int RM_EN = 5;   // Right motor enable (PWM)
const int RM_IN1 = 6;  // Right motor input 1
const int RM_IN2 = 7;  // Right motor input 2

// Threshold for sensor reading to differentiate between black and white
const int maxtreshold = 700;
const int threshold = 100;
const int motorSpeed = 100; // Maximum speed (PWM value from 0 to 255)

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  
  // Set motor control pins as outputs
  pinMode(LM_EN, OUTPUT);
  pinMode(LM_IN1, OUTPUT);
  pinMode(LM_IN2, OUTPUT);
  pinMode(RM_EN, OUTPUT);
  pinMode(RM_IN1, OUTPUT);
  pinMode(RM_IN2, OUTPUT);
  
  // Initialize motors to be off
  analogWrite(LM_EN, 0);
  analogWrite(RM_EN, 0);
}

void loop() {
  // Read the sensor values
  int leftSensorValue = analogRead(leftSensorPin);
  int middleSensorValue = analogRead(middleSensorPin);
  int rightSensorValue = analogRead(rightSensorPin);
  
  // Print sensor values to the Serial Monitor for debugging
  Serial.print("Left: ");
  Serial.print(leftSensorValue);
  Serial.print("  Middle: ");
  Serial.print(middleSensorValue);
  Serial.print("  Right: ");
  Serial.println(rightSensorValue);

  // Determine motor actions based on sensor readings
  if (maxtreshold >= middleSensorValue >= threshold) {
    moveForward();
  } else if (maxtreshold >= leftSensorValue >= threshold) {
    turnLeft();
  } else if (maxtreshold >= rightSensorValue >= threshold) {
    turnRight();
  } else {
    stopMotors();
  }

  delay(100); // Short delay to allow for sensor reading stabilization
}

void moveForward() {
  Serial.println("Moving Forward");
  analogWrite(LM_EN, motorSpeed);
  digitalWrite(LM_IN1, HIGH);
  digitalWrite(LM_IN2, LOW);
  
  analogWrite(RM_EN, motorSpeed);
  digitalWrite(RM_IN1, HIGH);
  digitalWrite(RM_IN2, LOW);
}

void turnLeft() {
  Serial.println("Turning Left");
  analogWrite(LM_EN, 0);
  digitalWrite(LM_IN1, LOW);
  digitalWrite(LM_IN2, LOW);
  
  analogWrite(RM_EN, motorSpeed);
  digitalWrite(RM_IN1, HIGH);
  digitalWrite(RM_IN2, LOW);
}

void turnRight() {
  Serial.println("Turning Right");
  analogWrite(LM_EN, motorSpeed);
  digitalWrite(LM_IN1, HIGH);
  digitalWrite(LM_IN2, LOW);
  
  analogWrite(RM_EN, 0);
  digitalWrite(RM_IN1, LOW);
  digitalWrite(RM_IN2, LOW);
}

void stopMotors() {
  Serial.println("Stopping Motors");
  analogWrite(LM_EN, 0);
  digitalWrite(LM_IN1, LOW);
  digitalWrite(LM_IN2, LOW);
  
  analogWrite(RM_EN, 0);
  digitalWrite(RM_IN1, LOW);
  digitalWrite(RM_IN2, LOW);
}
