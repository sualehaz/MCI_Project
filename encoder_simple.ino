const int encoderA = 30; //PF1
unsigned long ticksA = 0;

void setup() {
  Serial.begin(9600);
  pinMode(encoderA, INPUT);
  attachInterrupt(digitalPinToInterrupt(encoderA), countTicksA, CHANGE);

}

void loop() {
  Serial.print(ticksA);
  Serial.print("\n");
   delay(100);

   if (ticksA >10)
    ticksA = 0;
   
  
}

void countTicksA(){
  ticksA++; 
 }
