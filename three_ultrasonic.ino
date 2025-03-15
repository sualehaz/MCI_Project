////////////////////////////////////////////////////
//Ultrasonic Pins Definition, here we specify pin usage for our tivaC Board
//Pin connections for HC-SR04

const int echo_front = 9, Trig_front = 10, // front ultrasonic PA6, PA7
echo_left = 5, Trig_left =6, //left ultrasonic PE4, PE5
echo_right = 28, Trig_right =29; //right ultrasonic PE2, PE3 

//Time Update Variables for the front ultrasonic
long duration_front, cm_front; //To measure pulse width and distance in cm
long distance_front = 0; //To return distance of object at the front

//Time Update Variables for the left ultrasonic
long duration_left, cm_left; //To measure pulse width and distance in cm
long distance_left = 0; //To return distance of object at the front

//Time Update Variables for the right ultrasonic
long duration_right, cm_right; //To measure pulse width and distance in cm
long distance_right = 0; //To return distance of object at the front


void setup()
{
Serial.begin(115200); //Initialize Serial COM Port with 115200 buad rate
pinMode(Trig_front, OUTPUT); 
pinMode(echo_front, INPUT); 

pinMode(Trig_left, OUTPUT); 
pinMode(echo_left, INPUT); 

pinMode(Trig_right, OUTPUT);
pinMode(echo_right, INPUT); 
}


void loop()
{
Update_Front_Ultra_Sonic(); //This function operates HC-SR04
Update_Left_Ultra_Sonic(); //This function operates HC-SR04
Update_Right_Ultra_Sonic(); //This function operates HC-SR04
delay(200); //Delay between prints on Serial Monitor
}


void Update_Front_Ultra_Sonic()
{
//Setting Trig Signal HIGH for 10us to produce burst of 8 pulses at 40KHz
digitalWrite(Trig_front, LOW);
delayMicroseconds(2);
digitalWrite(Trig_front, HIGH);
delayMicroseconds(10);
digitalWrite(Trig_front, LOW);

duration_front = pulseIn(echo_front, HIGH); // Reads duration (microseconds) for which Echo pin reads HIGH till wave is reflected
cm_front = microsecondsToCentimeters_f(duration_front); // convert the time into a distance, refer to functionbelow
//Sending through serial port to print on Monitor
Serial.print("Distance at front=");
Serial.print("\t");
Serial.print(cm_front);
Serial.print("\n");
}


void Update_Left_Ultra_Sonic()
{
//Setting Trig Signal HIGH for 10us to produce burst of 8 pulses at 40KHz
digitalWrite(Trig_left, LOW);
delayMicroseconds(2);
digitalWrite(Trig_left, HIGH);
delayMicroseconds(10);
digitalWrite(Trig_left, LOW);

duration_left = pulseIn(echo_left, HIGH); // Reads duration (microseconds) for which Echo pin reads HIGH till wave is reflected
cm_left = microsecondsToCentimeters_l(duration_left); // convert the time into a distance, refer to function below
//Sending through serial port to print on Monitor

Serial.print("Distance at left=");
Serial.print("\t");
Serial.print(cm_left);
Serial.print("\n");
}


void Update_Right_Ultra_Sonic()
{
//Setting Trig Signal HIGH for 10us to produce burst of 8 pulses at 40KHz
digitalWrite(Trig_right, LOW);
delayMicroseconds(2);
digitalWrite(Trig_right, HIGH);
delayMicroseconds(10);
digitalWrite(Trig_right, LOW);

duration_right = pulseIn(echo_right, HIGH); // Reads duration (microseconds) for which Echo pin reads HIGH till wave is reflected
cm_right = microsecondsToCentimeters_r(duration_right); // convert the time into a distance, refer to functionbelow
//Sending through serial port to print on Monitor
Serial.print("Distance at right=");
Serial.print("\t");
Serial.print(cm_right);
Serial.print("\n");
}

////////////////////////////////////////////////////
//Conversion of microsecond to centimeter
long microsecondsToCentimeters_f(long microseconds)
{
distance_front = 0.034 * microseconds;
return distance_front / 2;
}

long microsecondsToCentimeters_l(long microseconds)
{
distance_left = 0.034 * microseconds;
return distance_left / 2;
}

long microsecondsToCentimeters_r(long microseconds)
{
distance_right = 0.034 * microseconds;
return distance_right / 2;
}
