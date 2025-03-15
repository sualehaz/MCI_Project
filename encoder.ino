const int encoder = 30; //PF1
unsigned long ticks = 0;

void setup() {
  Serial.begin(9600);
    pinMode(encoder, INPUT);
    attachInterrupt(digitalPinToInterrupt(encoder), countTicks, CHANGE);


}

void loop() {
  Serial.print(ticks);
 Serial.print("\n");
 delay(100);

  
}

void countTicks(){
  ticks++; 
 }
