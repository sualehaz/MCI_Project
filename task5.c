//motor A on rhs
int enA = 26;   // ENABLE pin (PB4) for motor A PWM 
int in1 = 11;   // IN1 pin (PB0) for motor A direction
int in2 = 12;   // IN2 pin (PB1) for motor A direction

//motor B on lhs
int enB = 25;    // ENABLE pin (PC4) for motor B PWM 
int in3 = 13;    // IN3 pin (PC6) for motor B direction
int in4 = 8;    // IN4 pin (PC7) for motor B direction

void setup() {
  Serial.begin(115200); // serial initialization 
  
  //  pin modes for motor A
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  //  pin modes for motor B
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // initially motors are off
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop() {
  // to move forward
  digitalWrite(in2, LOW); // motor a moves forward
  digitalWrite(in1, HIGH);
  digitalWrite(in4, LOW);  //motor b moves forward
  digitalWrite(in3, HIGH);
  
  analogWrite(enA, 160);  // high speed for motor a
  analogWrite(enB, 255);  // high speed for motor b

  delay(9000);  // move forward for 5 secs

////for a left turn
//  digitalWrite(in1, LOW); // motor a moves forward
//  digitalWrite(in2, HIGH);
//  digitalWrite(in3, LOW);  //motor b moves forward
//  digitalWrite(in4, HIGH);
//  
//  analogWrite(enA, 255);   //high speed for motor a
//  analogWrite(enB, 64);  // low speed for motor b
//
//  delay(9000);
}
