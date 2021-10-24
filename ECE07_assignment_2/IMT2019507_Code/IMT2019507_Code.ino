#include <stdio.h>

// mask_counter variable keeps track of the binary number displayed by the LEDs

int mask_counter = 0;
void outputLEDs(int mask);


// LED_gpio is the array which contains the pins connected to Leds
// To make the code work for 5 (or) 6 Leds instead of 4, just append the new Led Gpio numbers at the end of LED_gpio[] array below

const int LED_gpio[] = {16,17,18,19}; 


// we get to know the length of LED_gpio array by dividing sizeof(array) by sizeof(array's element)

const int arr_len = sizeof(LED_gpio)/sizeof(LED_gpio[0]);  
int LED_masks[arr_len];

void setup() {

  for (int i = 0; i < arr_len; i++) {
    pinMode(LED_gpio[i], OUTPUT);             // Set the GPIO pins where LEDs are connected to OUTPUT mode
  }  

  for(int i = 0; i < arr_len; i++){
    LED_masks[i] = pow(2, arr_len - i - 1);   // Fill the LED_masks Array with the mask values like 0x1000,0x0100,etc. 
  }                                           // I have put them in Integer format instead of hexadecimal as it doesn't matter in the end when using the "&" operation

}                                             // End of void setup()


void loop() {
  
  outputLEDs(mask_counter);
  
  if(mask_counter == 15){      // when the value displayed by LEDs reaches 0x0F (or) 15,
    mask_counter = 0;          // the mask_counter has to be set to 0x00 (or) 0
    delay(4000);               // and a delay of 4 seconds has to be given to indicate that the value of 15 has been reached and the cycle has been completed
  }
  
  else{
    mask_counter += 1;         // if the mask_counter has not reached it's peak value, increment it's value by 1
    delay(2000);               // and give a delay of 2 seconds
  }
  
}                              // End of void loop()


void outputLEDs(int mask){     // when we use & operations in the outputLEDs function, the int values are converted to binary for operation 

  for(int i = 0; i < arr_len; i++){
    
    if(LED_masks[i] & mask){
      digitalWrite(LED_gpio[i], HIGH);
    }
    
    else{
      digitalWrite(LED_gpio[i], LOW);
    }
    
  }
  
}      // End of outputLEDs() function
 
