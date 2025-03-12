//motor A on rhs
int enA = 7;   // ENABLE pin (PB4) for motor A PWM 
int in1 = 3;   // IN1 pin (PB0) for motor A direction
int in2 = 4;   // IN2 pin (PB1) for motor A direction

//motor B on lhs
int enB = 37;    // ENABLE pin (PC4) for motor B PWM 
int in3 = 35;    // IN3 pin (PC6) for motor B direction
int in4 = 34;    // IN4 pin (PC7) for motor B direction

//ultrasonic1 left
int trig1=9
int echo1=8

//ultrasonic2 front
int trig2=6
int echo2=5

//ultrasonic3 right
int trig3=29
int echo3=28

void setup() {
  Serial.begin(115200); // serial initialization 
  
  //pin modes for motor A
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  //pin modes for motor B
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  //pinmodes for sensors
  pinMode(trig1, OUTPUT); //left
  pinMode(echo1, INPUT);

  pinMode(trig2, OUTPUT); //front
  pinMode(echo2, INPUT);

  pinMode(trig3, OUTPUT); //right
  pinMode(echo3, INPUT);

  // initially motors are off
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
long avg_dist1=0;
long avg_dist2=0;
long avg_dist3=0;

void Update_Ultra_Sonic()
{
  //Setting Trig Signal HIGH for 10us to produce burst of 8 pulses at 40KHz
  for(int j=0; j<15;j++){
    
  digitalWrite(trig1, LOW);
  digitalWrite(trig2, LOW);
  digitalWrite(trig3, LOW);
  
  delayMicroseconds(2);
  
  digitalWrite(trig1, HIGH);
  digitalWrite(trig2, HIGH);
  digitalWrite(trig3, HIGH);
  
  delayMicroseconds(10);
  
  digitalWrite(trig1, LOW);
  digitalWrite(trig2, LOW);
  digitalWrite(trig3, LOW);
  
  duration1 = pulseIn(echo1, HIGH); // Reads duration (microseconds) for which Echo pin reads HIGH till wave is reflected
  duration2 = pulseIn(echo2, HIGH); // Reads duration (microseconds) for which Echo pin reads HIGH till wave is reflected
  duration3 = pulseIn(echo3, HIGH); // Reads duration (microseconds) for which Echo pin reads HIGH till wave is reflected
  
  cm_left = microsecondsToCentimeters(duration1); // convert the time into a distance, refer to function below
  cm_front = microsecondsToCentimeters(duration2); // convert the time into a distance, refer to function below
  cm_right = microsecondsToCentimeters(duration3); // convert the time into a distance, refer to function below
  
//  avg_dist1+=cm1;
//  avg_dist2+=cm2;
//  avg_dist3+=cm3;
  
  //Sending through serial port to print on Monitor
  Serial.print("Distance_left=");
  Serial.print("\t");
  Serial.print(cm_left);
  Serial.print("\n");
  
  Serial.print("Distance_front=");
  Serial.print("\t");
  Serial.print(cm_front);
  Serial.print("\n");
  
  Serial.print("Distance_right=");
  Serial.print("\t");
  Serial.print(cm_right);
  Serial.print("\n");
  delay(1000);
  }
//  avg_dist=avg_dist/15;
//  Serial.print("Average Distance= ");
//  Serial.print("\t");
//  Serial.print(avg_dist);
//  Serial.print("\n");
}

////////////////////////////////////////////////////
//Conversion of microsecond to centimeter
long microsecondsToCentimeters(long microseconds)
{
  distance=microseconds*0.034;
  return distance / 2;

}
void loop() {
  
  //sensor reading
  Update_Ultra_Sonic(); //This function operates HC-SR04
  
  // to move forward
  digitalWrite(in2, HIGH); // motor a moves
  digitalWrite(in1, LOW);
  digitalWrite(in4, HIGH); // motor b moves
  digitalWrite(in3, LOW);
  
  analogWrite(enA, 255);  // high speed for motor a ,255
  analogWrite(enB, 125);  // high speed for motor b, 117 or 125 see which works

  delay(4000);  // move forward for 4 secs

//for a left turn
  digitalWrite(in1, LOW); // motor a moves forward
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);  //motor b stops
  digitalWrite(in4, LOW);
  
  analogWrite(enA, 255);   //high speed for motor a
  analogWrite(enB, 0);  // low speed for motor b

  delay(530); //for a turn
  
  digitalWrite(in2, HIGH); // motor a moves forward
  digitalWrite(in1, LOW);
  digitalWrite(in4, HIGH); // motor b moves forward
  digitalWrite(in3, LOW);
  
  analogWrite(enA, 255);  // high speed for motor a
  analogWrite(enB, 125);  // high speed for motor b,
  
  delay(4000); 

  if(cm1<5){
    //move to right
  }
  if(cm1>5){
    //move to left
  }
  if(cm3<5){
    //move to left
  }
  if(cm3>5){
    //move to right
  }
  if(cm2<11){
    //turn left
  }
  

// //for a stop
//  digitalWrite(in1, LOW); // motor a stops
//  digitalWrite(in2, LOW);
//  digitalWrite(in3, LOW);  //motor b moves forward
//  digitalWrite(in4, LOW);
//  
//  analogWrite(enA, 0);   //high speed for motor a
//  analogWrite(enB, 0);  // low speed for motor b
//
//  while(1);
}
