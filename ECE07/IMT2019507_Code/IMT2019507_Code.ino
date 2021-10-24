/*
  
 GP16(Pin no. 21), GP17(Pin no. 22), GP18(Pin no. 24) and GP19(Pin no. 25).

*/

#include <stdio.h>

#define ALL_ON_CMD    ('a')
#define ALL_OFF_CMD   ('f')

// Individual LED states to be extracted from the MASK value
#define LED1_MASK (0x08)  //1000
#define LED2_MASK (0x04)  //0100
#define LED3_MASK (0x02)  //0010
#define LED4_MASK (0x01)  //0001

#define LED_ALL_ON_MASK_VAL  (0x0F)
#define LED_ALL_OFF_MASK_VAL (0x00)

// LED1 to LED4 are connected to GPIO 16 to 19 
#define GPIO16 16   // Pin no. 21
#define GPIO17 17   // Pin no. 22
#define GPIO18 18   // Pin no. 24
#define GPIO19 19   // Pin no. 25

void processCMD(int command);
void outputLEDs(int mask);

#define CR_VAL 10

int incomingCMD = 0; // for incoming serial data


void setup() {
  
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

  // Set the GPIO pins where LEDs are connected to OUTPUT mode
  pinMode(GPIO16, OUTPUT);
  pinMode(GPIO17, OUTPUT);
  pinMode(GPIO18, OUTPUT);
  pinMode(GPIO19, OUTPUT);

  //This is the DEFAULT STATE 
  digitalWrite(GPIO16, HIGH);
  digitalWrite(GPIO17, HIGH);
  digitalWrite(GPIO18, HIGH);
  digitalWrite(GPIO19, HIGH);
  
}


void loop() {
  
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                        // wait for 200 milliseconds
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(200);                        // wait for 200 milliseconds

  // Check if there is any command arrived from the Serial Monitor sent by the user
  if (Serial.available() > 0) {
    // read the incoming command byte:
    incomingCMD = Serial.read();

    // say what you got:
    Serial.print("Received the command: ");
    Serial.println(incomingCMD);
    if(incomingCMD != CR_VAL) // if it is not a carriage return then process the CMD
      processCMD(incomingCMD);
  }
  

}

// Valid single byte commands are:
// a or A: All LEDs ON
// f or F: All LEDs OFF

void processCMD(int commandIn){
  
  int mask = 0;
  
  switch(commandIn){

    
    case 'a':             // All LEDs are On
    case 'A':
    
      mask = LED_ALL_ON_MASK_VAL;
      outputLEDs(mask);
      break;

      
    case 'f':             // All LEDs are Off
    case 'F':

      mask = LED_ALL_OFF_MASK_VAL;
      outputLEDs(mask);
      break;      

    case '1':             // 1st LED is On, remaining off

      mask = LED1_MASK;
      outputLEDs(mask);
      break; 

    case '2':             // 2nd LED is On, remaining off

      mask = LED2_MASK;
      outputLEDs(mask);
      break; 

   case '3':             // 3rd LED is On, remaining off

      mask = LED3_MASK;
      outputLEDs(mask);
      break; 

   case '4':             // 4rth LED is On, remaining off

      mask = LED4_MASK;
      outputLEDs(mask);
      break; 

      
    default: 
      Serial.println("Not a valid command received. No action taken.");
      break; 
      // for any other invalid commands received, maintain the current states of LEDs
      
  }
  
} // end of processCMD()

void outputLEDs(int mask){

  if(LED1_MASK & mask)
    digitalWrite(GPIO16, HIGH);
  else
    digitalWrite(GPIO16, LOW);

  if(LED2_MASK & mask)
    digitalWrite(GPIO17, HIGH);
  else
    digitalWrite(GPIO17, LOW);

  if(LED3_MASK & mask)
    digitalWrite(GPIO18, HIGH);
  else
    digitalWrite(GPIO18, LOW);

  if(LED4_MASK & mask)
    digitalWrite(GPIO19, HIGH);
  else
    digitalWrite(GPIO19, LOW);

} // end of outputLEDs()
 
