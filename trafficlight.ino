// Project: Traffic Light
// Date: April 6, 2020
// Description: An Arduino project that simulates a traffic light. Includes a timer rotating through a green, green arrow, yellow, and red light.


int pin10 = 10;
int pin11 = 11;
int pin12 = 12;
int pin13 = 13;

void setup() {
  Serial.begin(9600);

  // Sets pins to output
  
  pinMode(pin10, OUTPUT);
  pinMode(pin11, OUTPUT);
  pinMode(pin12, OUTPUT);
  pinMode(pin13, OUTPUT);

  // Sets pins to "off"
  
  digitalWrite(pin10, LOW);
  digitalWrite(pin11, LOW);
  digitalWrite(pin12, LOW);
  digitalWrite(pin13, LOW);
}

void loop() {
  
  // Starts off with a red light for 7 seconds
  
  digitalWrite(pin10, HIGH);
  Serial.println("Red Light!");
  delay(7000);
  digitalWrite(pin10, LOW);


  // Proceeds to a green light for 10.5 seconds
  
  digitalWrite(pin12, HIGH);
  Serial.println("Green light!");
  // loop blinks second green 
  for(int i = 0; i < 7; i++){
    digitalWrite(pin13, HIGH);
    delay(1000);
    digitalWrite(pin13, LOW);
    delay(500);
  }
  
  digitalWrite(pin12, LOW);

  // Proceeds to a yellow light for 3 seconds
  
  digitalWrite(pin11, HIGH);
  Serial.println("Yellow light!");
  delay(3000);
  digitalWrite(pin11, LOW);
}
