// Project: Light Reactor Game
// Date: April 29, 2020
// Description: This game flashes a light between along a line of 5 lights. The lights are Green, Yellow, Red, Yellow, Green. 
// You must press the button when the light cycles on the green light. There are two difficulties, Normal and Advanced.

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

int difficulty;
LiquidCrystal_I2C lcd(0x27,20,4);

// Light pin Variables
  int pin1 = 1;
  int pin2 = 2;
  int pin3 = 3;
  int pin4 = 4;
  int pin5 = 5;
  int pin6 = 6;
  int pin7 = 7;
  int pin8 = 8;
  
// Button pin variables
  int lbuttonPin = 10;
  int lbuttonState = 0;

// Joystick Variables
  int xValue = 0;
  int yValue = 0;
  int joyPin1 = 0;
  int joyPin2 = 1;

void setup() {

  bool diffChosen = false;

  // Pin mode settings

  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin8, OUTPUT);

  pinMode(lbuttonPin, INPUT);
  // Settting pins to "off"

  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
  digitalWrite(pin5, LOW);
  digitalWrite(pin6, LOW);
  digitalWrite(pin7, LOW);
  digitalWrite(pin8, LOW);

  // LCD Initialization and Welcome Message

  lcd.init();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Light Reactor");
  
  lcd.setCursor(0,1);
  lcd.print("Pick Difficulty");
  delay(3000);
  lcd.setCursor(0,0);
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Left: Normal");
  
  lcd.setCursor(0,1);
  lcd.print("Right: Advanced");
  delay(3000);

  // Reading Joystick to see difficulty
  while(diffChosen == false) { 
    xValue = analogRead(joyPin1);
    
    if(xValue > 600) {
      difficulty = 1;
      diffChosen = true;
      break;
    }
    else if(xValue < 400) {
      difficulty = 2;
      diffChosen = true;
      break;
    }
    
  }

  

}

void loop() {


  // Countdown to start
  int countdown = 5;
  bool counter = true;

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Difficulty");
  lcd.setCursor(0,1);
  if(difficulty == 1) {
    lcd.print("Normal");
  }
  else if(difficulty == 2)  {
    lcd.print("Advanced");
  }

  delay(3000);
  
  lcd.clear();
  while(counter = true)  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Starting Game...");
    delay(100);
    lcd.setCursor(0,1);
    lcd.print(countdown);
    countdown--;
    delay(1000);
    if(countdown == -1) {
      break;
    }
  }

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Begin!");

  
  bool level1 = true;
  bool level2 = false;
  bool level3 = false;

  int i = 0;
  
  pinMode(lbuttonPin, INPUT);

  // Difficulty 1 Game
  
  if (difficulty == 1) {
  
    while(level1 == true)   { // Level 1 Difficulty 1
      
      digitalWrite(pin2, HIGH); /////////////////////////////// Light 1 ///////////////////////////////
   
      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        delay(3000);
        exit(0);
      }
      delay(500);

      digitalWrite(pin2, LOW);
      digitalWrite(pin3, HIGH); /////////////////////////////// Light 2 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        delay(3000);
        exit(0);
      }
      delay(500);
      
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, HIGH); /////////////////////////////// Light 3 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }
      delay(500);
      
      digitalWrite(pin4, LOW);
      digitalWrite(pin5, HIGH); // Light 4 / (Middle Light)
      
      for(i = 0; i < 5; i++)  {
        lbuttonState = digitalRead(lbuttonPin);

        if(lbuttonState == HIGH)  {
          
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Nice!"); 
        lcd.setCursor(0,1);
        lcd.print("On to level 2");

        delay(3000);
        digitalWrite(pin5, LOW);
        
        level2 = true;
        
        break;
        }

        delay(100);
      }
      if(level2 == true) {
        level1 = false;
        break;
      }
      digitalWrite(pin5, LOW);
      digitalWrite(pin6, HIGH); /////////////////////////////// Light 5 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }
      delay(500);

      digitalWrite(pin6, LOW);
      digitalWrite(pin7, HIGH); /////////////////////////////// Light 6 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }
      delay(500);

      digitalWrite(pin7, LOW);
      digitalWrite(pin8, HIGH); /////////////////////////////// Light 7 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }
      delay(500);

      //////////////// Looping Back Around //////////////////
      digitalWrite(pin8, LOW);
      digitalWrite(pin8, HIGH); /////////////////////////////// Light 7 ///////////////////////////////
   
      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        delay(3000);
        exit(0);
      }
      digitalWrite(pin8, LOW);
      digitalWrite(pin7, HIGH); /////////////////////////////// Light 6 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        delay(3000);
        exit(0);
      }
      delay(500);
      
      digitalWrite(pin7, LOW);
      digitalWrite(pin6, HIGH); /////////////////////////////// Light 5 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }
      delay(500);

      digitalWrite(pin6, LOW);
      digitalWrite(pin5, HIGH); // Light 4 / (Middle Light)

      for(i = 0; i < 5; i++)  {
        lbuttonState = digitalRead(lbuttonPin);

        if(lbuttonState == HIGH)  {
          
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Nice!"); 
        lcd.setCursor(0,1);
        lcd.print("On to level 2");

        delay(3000);
        digitalWrite(pin5, LOW);
        
        level2 = true;
        
        break;
        }

        delay(100);
      }
      if(level2 == true) {
        level1 = false;
        break;
      } 

      digitalWrite(pin5, LOW);
      digitalWrite(pin4, HIGH); /////////////////////////////// Light 3///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }
      delay(500);

      digitalWrite(pin4, LOW);
      digitalWrite(pin3, HIGH); /////////////////////////////// Light 2 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }
      delay(500);

      digitalWrite(pin3, LOW);
      digitalWrite(pin2, HIGH); /////////////////////////////// Light 1 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }
      delay(500);
    }
    while(level2 == true)   { // Level 2 Difficulty 1
      

      digitalWrite(pin3, HIGH); /////////////////////////////// Light 2 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        delay(3000);
        exit(0);
      }
      delay(500);
      
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, HIGH); /////////////////////////////// Light 3 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }
      delay(500);

      digitalWrite(pin4, LOW);
      digitalWrite(pin5, HIGH); // Light 4 / (Middle Light)

      for(i = 0; i < 5; i++)  {
        lbuttonState = digitalRead(lbuttonPin);

        if(lbuttonState == HIGH)  {
          
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Great!"); 
        lcd.setCursor(0,1);
        lcd.print("Level 3 time...");

        delay(3000);
        digitalWrite(pin5, LOW);
        
        level3 = true;
        
        break;
        }

        delay(100);
      }
      if(level3 == true) {
        level2 = false;
        break;
      }      

      digitalWrite(pin5, LOW);
      digitalWrite(pin6, HIGH); /////////////////////////////// Light 5 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }
      delay(500);

      digitalWrite(pin6, LOW);
      digitalWrite(pin7, HIGH); /////////////////////////////// Light 6 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }
      delay(500);

      ////////////////// Looping Back Around ////////////////////////////
      
      digitalWrite(pin7, LOW);
      digitalWrite(pin7, HIGH); /////////////////////////////// Light 6 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        delay(3000);
        exit(0);
      }
      
      digitalWrite(pin7, LOW);
      digitalWrite(pin6, HIGH); /////////////////////////////// Light 5 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }
      delay(500);

      digitalWrite(pin6, LOW);
      digitalWrite(pin5, HIGH); // Light 4 / (Middle Light)

      for(i = 0; i < 5; i++)  {
        lbuttonState = digitalRead(lbuttonPin);

        if(lbuttonState == HIGH)  {
          
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Great!"); 
        lcd.setCursor(0,1);
        lcd.print("Level 3 time...");

        delay(3000);
        digitalWrite(pin5, LOW);
        
        level3 = true;
        
        break;
        }

        delay(100);
      }
      if(level3 == true) {
        level2 = false;
        break;
      }

      digitalWrite(pin5, LOW);
      digitalWrite(pin4, HIGH); /////////////////////////////// Light 3 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }
      delay(500);

      digitalWrite(pin4, LOW);
      digitalWrite(pin3, HIGH); /////////////////////////////// Light 2 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }
      delay(500);
      
    }
    while(level3 == true)   { // Level 3 Difficulty 1
      
      digitalWrite(pin4, HIGH); /////////////////////////////// Light 3 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }
      delay(250);
      
      digitalWrite(pin4, LOW);
      digitalWrite(pin5, HIGH); // Light 4 / (Middle Light)

      for(i = 0; i < 5; i++)  {
        lbuttonState = digitalRead(lbuttonPin);

        if(lbuttonState == HIGH)  {
          
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("You Win!"); 
        lcd.setCursor(0,1);
        lcd.print("Exiting...");

        delay(3000);
        digitalWrite(pin5, LOW);
        
        level3 = false;
        
        break;
        }

        delay(100);
      }
      if(level3 == false) {
        break;
      }

      digitalWrite(pin5, LOW);
      digitalWrite(pin6, HIGH); /////////////////////////////// Light 5 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }
      delay(250);

      digitalWrite(pin6, LOW);
      digitalWrite(pin6, HIGH); /////////////////////////////// Light 5 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }

      digitalWrite(pin6, LOW);
      digitalWrite(pin5, HIGH); // Light 4 / (Middle Light)

      for(i = 0; i < 5; i++)  {
        lbuttonState = digitalRead(lbuttonPin);

        if(lbuttonState == HIGH)  {
          
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("You Win!"); 
        lcd.setCursor(0,1);
        lcd.print("Exiting...");

        delay(3000);
        digitalWrite(pin5, LOW);
        
        level3 = false;
        
        break;
        }

        delay(100);
      }
      if(level3 == false) {
        break;
      }

      digitalWrite(pin5, LOW);
      digitalWrite(pin4, HIGH); /////////////////////////////// Light 3 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }
      delay(250);
      
    }
  }

  // Difficulty 2 Game

  if (difficulty == 2) {
  
    while(level1 == true) { // Level 1 Difficulty 2
      
      digitalWrite(pin2, HIGH); /////////////////////////////// Light 1 ///////////////////////////////
   
      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        delay(3000);
        exit(0);
      }
      delay(250);

      digitalWrite(pin2, LOW);
      digitalWrite(pin3, HIGH); /////////////////////////////// Light 2 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        delay(3000);
        exit(0);
      }
      delay(250);
      
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, HIGH); /////////////////////////////// Light 3 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }
      delay(250);

      digitalWrite(pin4, LOW);
      digitalWrite(pin5, HIGH); // Light 4 / (Middle Light)

      for(i = 0; i < 5; i++)  {
        lbuttonState = digitalRead(lbuttonPin);

        if(lbuttonState == HIGH)  {
          
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Nice!"); 
        lcd.setCursor(0,1);
        lcd.print("On to level 2");

        delay(3000);
        digitalWrite(pin5, LOW);
        
        level2 = true;
        
        break;
        }

        delay(50);
      }
      if(level2 == true) {
        level1 = false;
        break;
      }

      digitalWrite(pin5, LOW);
      digitalWrite(pin6, HIGH); /////////////////////////////// Light 5 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }
      delay(250);

      digitalWrite(pin6, LOW);
      digitalWrite(pin7, HIGH); /////////////////////////////// Light 6 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }
      delay(250);

      digitalWrite(pin7, LOW);
      digitalWrite(pin8, HIGH); /////////////////////////////// Light 7 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }
      delay(250);

      //////////////// Looping Back Around //////////////////

      digitalWrite(pin8, LOW);
      digitalWrite(pin8, HIGH); /////////////////////////////// Light 7 ///////////////////////////////
   
      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        delay(3000);
        exit(0);
      }

      digitalWrite(pin8, LOW);
      digitalWrite(pin7, HIGH); /////////////////////////////// Light 6 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        delay(3000);
        exit(0);
      }
      delay(250);
      
      digitalWrite(pin7, LOW);
      digitalWrite(pin6, HIGH); /////////////////////////////// Light 5 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }
      delay(250);

      digitalWrite(pin6, LOW);
      digitalWrite(pin5, HIGH); // Light 4 / (Middle Light)

      for(i = 0; i < 5; i++)  {
        lbuttonState = digitalRead(lbuttonPin);

        if(lbuttonState == HIGH)  {
          
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Nice!"); 
        lcd.setCursor(0,1);
        lcd.print("On to level 2");

        delay(3000);
        digitalWrite(pin5, LOW);
        
        level2 = true;
        
        break;
        }

        delay(50);
      }
      if(level2 == true) {
        level1 = false;
        break;
      }

      digitalWrite(pin5, LOW);
      digitalWrite(pin4, HIGH); /////////////////////////////// Light 3///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }
      delay(250);

      digitalWrite(pin4, LOW);
      digitalWrite(pin3, HIGH); /////////////////////////////// Light 2 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }
      delay(250);

      digitalWrite(pin3, LOW);
      digitalWrite(pin2, HIGH); /////////////////////////////// Light 1 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }
      delay(250);
    }
    while(level2 == true) { // Level 2 Difficulty 2
      

      digitalWrite(pin3, HIGH); /////////////////////////////// Light 2 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        delay(3000);
        exit(0);
      }
      delay(250);
      
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, HIGH); /////////////////////////////// Light 3 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }
      delay(250);

      digitalWrite(pin4, LOW);
      digitalWrite(pin5, HIGH); // Light 4 / (Middle Light)

      for(i = 0; i < 5; i++)  {
        lbuttonState = digitalRead(lbuttonPin);

        if(lbuttonState == HIGH)  {
          
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Great!"); 
        lcd.setCursor(0,1);
        lcd.print("Level 3 time...");

        delay(3000);
        digitalWrite(pin5, LOW);
        
        level3 = true;
        
        break;
        }

        delay(50);
      }
      if(level3 == true) {
        level2 = false;
        break;
      }

      digitalWrite(pin5, LOW);
      digitalWrite(pin6, HIGH); /////////////////////////////// Light 5 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }
      delay(250);

      digitalWrite(pin6, LOW);
      digitalWrite(pin7, HIGH); /////////////////////////////// Light 6 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }
      delay(250);

      ////////////////// Looping Back Around ////////////////////////////

      digitalWrite(pin7, LOW);
      digitalWrite(pin7, HIGH); /////////////////////////////// Light 6 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        delay(3000);
        exit(0);
      }
      
      digitalWrite(pin7, LOW);
      digitalWrite(pin6, HIGH); /////////////////////////////// Light 5 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }
      delay(250);

      digitalWrite(pin6, LOW);
      digitalWrite(pin5, HIGH); // Light 4 / (Middle Light)

      for(i = 0; i < 5; i++)  {
        lbuttonState = digitalRead(lbuttonPin);

        if(lbuttonState == HIGH)  {
          
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Great!"); 
        lcd.setCursor(0,1);
        lcd.print("Level 3 time...");

        delay(3000);
        digitalWrite(pin5, LOW);
        
        level3 = true;
        
        break;
        }

        delay(50);
      }
      if(level3 == true) {
        level2 = false;
        break;
      }

      digitalWrite(pin5, LOW);
      digitalWrite(pin4, HIGH); /////////////////////////////// Light 3 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }
      delay(250);

      digitalWrite(pin4, LOW);
      digitalWrite(pin3, HIGH); /////////////////////////////// Light 2 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }
      delay(250);
      
    }
    while(level3 == true) { // Level 3 Difficulty 2
      
      digitalWrite(pin4, HIGH); /////////////////////////////// Light 3 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }
      delay(200
      );

      digitalWrite(pin4, LOW);
      digitalWrite(pin5, HIGH); // Light 4 / (Middle Light)

      for(i = 0; i < 5; i++)  {
        lbuttonState = digitalRead(lbuttonPin);

        if(lbuttonState == HIGH)  {
          
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("You Win!"); 
        lcd.setCursor(0,1);
        lcd.print("Exiting...");

        delay(3000);
        digitalWrite(pin5, LOW);
        
        level3 = false;
        
        break;
        }

        delay(30);
      }
      if(level3 == false) {
        break;
      }

      digitalWrite(pin5, LOW);
      digitalWrite(pin6, HIGH); /////////////////////////////// Light 5 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }
      delay(200);

      digitalWrite(pin6, LOW);
      digitalWrite(pin6, HIGH); /////////////////////////////// Light 5 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }

      digitalWrite(pin6, LOW);
      digitalWrite(pin5, HIGH); // Light 4 / (Middle Light)

      for(i = 0; i < 5; i++)  {
        lbuttonState = digitalRead(lbuttonPin);

        if(lbuttonState == HIGH)  {
          
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("You Win!"); 
        lcd.setCursor(0,1);
        lcd.print("Exiting...");

        delay(3000);
        digitalWrite(pin5, LOW);
        
        level3 = false;
        
        break;
        }

        delay(30);
      }
      if(level3 == false) {
        break;
      }

      digitalWrite(pin5, LOW);
      digitalWrite(pin4, HIGH); /////////////////////////////// Light 3 ///////////////////////////////

      lbuttonState = digitalRead(lbuttonPin);
      if(lbuttonState == HIGH) {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Game Over");
        exit(0);
      }
      delay(200);
      
    }
  }

    
