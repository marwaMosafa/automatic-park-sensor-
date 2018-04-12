//sensor pins 
#define trig_pin A0 //analog input 1
#define echo_pin A1 //analog input 2

long duration, distance,FrontSensor;

#define red  3
#define yellow 6  
#define green  5

void setup() {
  // put your setup code here, to run once:
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  do{
    SonarSensor(trig_pin, echo_pin);
    FrontSensor = distance;
    Serial.println(FrontSensor);

   if(FrontSensor >= 25){
    green_l();
  }
else if(  FrontSensor < 25 && FrontSensor >= 10){
      yellow_l();
  }
else{
  red_l();
  }

    }while(FrontSensor!=0);
}
void yellow_l(){
    digitalWrite(yellow, HIGH);
      digitalWrite(red, LOW);
  digitalWrite(green, LOW);
}

void red_l(){
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
}

void green_l(){
    digitalWrite(yellow, LOW);
      digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
}

void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(100);
digitalWrite(trigPin, HIGH);
delayMicroseconds(100);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
 
}
