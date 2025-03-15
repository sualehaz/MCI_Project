// initializing the echo pins for Hc-SR04
const int echo_front = 5; //PE4
const int echo_left = 8; //PA5
const int echo_right = 28; //PE2

// initializing the trig pins for Hc-SR04
const int trig_front = 6; //PE5
const int trig_left = 9; //PA6
const int trig_right = 29; //PE3

//Time Update Variables for the front ultrasonic
long duration_front, cm_front; //To measure pulse width and distance in cm
long distance_front = 0; //To return distance of object

//Time Update Variables for the left ultrasonic
long duration_left, cm_left; //To measure pulse width and distance in cm
long distance_left = 0; //To return distance of object

//Time Update Variables for the right ultrasonic
long duration_right, cm_right; //To measure pulse width and distance in cm
long distance_right = 0; //To return distance of object

////////////////////////////////////////////////////
//Initializing Pins Function
void setup()
{
Serial.begin(115200); //Initialize Serial COM Port with 115200 buad rate

//setting the pins for the front ultrasonic
pinMode(trig_front, OUTPUT); 
pinMode(echo_front, INPUT); 

//setting the pins for the left ultrasonic
pinMode(trig_left, OUTPUT); 
pinMode(echo_left, INPUT); 

//setting the pins for the right ultrasonic
pinMode(trig_right, OUTPUT); 
pinMode(echo_right, INPUT); 
}


void loop()
{
Update_Front_Ultra_Sonic(); //This function operates the front HC-SR04
Update_Left_Ultra_Sonic(); //This function operates the left HC-SR04
Update_Right_Ultra_Sonic(); //This function operates the right HC-SR04
delay(200); //Delay between prints on Serial Monitor
}


//Will update the ultrasonic sensor through Serial port
//for the front sensor
void Update_Front_Ultra_Sonic()
{
//Setting Trig Signal HIGH for 10us to produce burst of 8 pulses at 40KHz
digitalWrite(trig_front, LOW);
delayMicroseconds(2);
digitalWrite(trig_front, HIGH);
delayMicroseconds(10);
digitalWrite(trig_front, LOW);
duration_front = pulseIn(echo_front, HIGH); 
cm_front = microsecondsToCentimeters_front(duration_front); // convert the time into a distance, refer to function below
//Sending through serial port to print on Monitor
Serial.print("Distance at front=");
Serial.print("\t");
Serial.print(cm_front);
Serial.print("\n");
}

//for the left sensor
void Update_Left_Ultra_Sonic()
{
//Setting Trig Signal HIGH for 10us to produce burst of 8 pulses at 40KHz
digitalWrite(trig_left, LOW);
delayMicroseconds(2);
digitalWrite(trig_left, HIGH);
delayMicroseconds(10);
digitalWrite(trig_left, LOW);
duration_left = pulseIn(echo_left, HIGH); 
cm_left = microsecondsToCentimeters_left(duration_left); // convert the time into a distance, refer to function below
//Sending through serial port to print on Monitor
Serial.print("Distance at left=");
Serial.print("\t");
Serial.print(cm_left);
Serial.print("\n");
}

//for the right sensor
void Update_Right_Ultra_Sonic()
{
//Setting Trig Signal HIGH for 10us to produce burst of 8 pulses at 40KHz
digitalWrite(trig_right, LOW);
delayMicroseconds(2);
digitalWrite(trig_right, HIGH);
delayMicroseconds(10);
digitalWrite(trig_right, LOW);
duration_right = pulseIn(echo_right, HIGH); 
cm_right = microsecondsToCentimeters_right(duration_right); // convert the time into a distance, refer to function below
//Sending through serial port to print on Monitor
Serial.print("Distance at right=");
Serial.print("\t");
Serial.print(cm_right);
Serial.print("\n");
}


//Conversion of microsecond to centimeter
//for the distance read from the front sensor
long microsecondsToCentimeters_front(long microseconds_front)
{
distance_front = 0.034 * microseconds_front;
return distance_front / 2;
}

//for the distance read from the left sensor
long microsecondsToCentimeters_left(long microseconds_left)
{
distance_left = 0.034 * microseconds_left;
return distance_left / 2;
}

//for the distance read from the right sensor
long microsecondsToCentimeters_right(long microseconds_right)
{
distance_right = 0.034 * microseconds_right;
return distance_right / 2;
}
