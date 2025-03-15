const int encoder = 30; //PF1
unsigned long ticks = 0;

int enA = 7;   // ENABLE pin (PB4) for motor A PWM 
int in1 = 3;   // IN1 pin (PB0) for motor A direction
int in2 = 4;   // IN2 pin (PB1) for motor A direction

//motor B on lhs
int enB = 37;    // ENABLE pin (PC4) for motor B PWM 
int in4 = 35;    // IN3 pin (PC6) for motor B direction
int in3 = 34;    // IN4 pin (PC7) for motor B direction


void setup() {
    Serial.begin(9600);
    pinMode(encoder, INPUT);
    attachInterrupt(digitalPinToInterrupt(encoder), countTicks, CHANGE);

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

void loop(){
 Serial.print(ticks);
 Serial.print("\n");

 if (ticks >= 4701){
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite(enA, 0);  // high speed for motor a
    analogWrite(enB, 0);  // high speed for motor b}
  }
  
  else{
    digitalWrite(in2, HIGH); // motor a moves
    digitalWrite(in1, LOW);
    digitalWrite(in4, HIGH); // motor b moves
    digitalWrite(in3, LOW);
   
    analogWrite(enA, 255);  // high speed for motor a
    analogWrite(enB, 98);  // high speed for motor b}

}
}

void countTicks(){
  ticks++; 
 }
