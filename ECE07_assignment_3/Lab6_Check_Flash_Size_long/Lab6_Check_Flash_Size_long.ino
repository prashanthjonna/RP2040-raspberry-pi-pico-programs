/*
 Author: Mouli Sankaran 
 Date: 6th Sep 2021 (recording is being shared)
 Class: Lab 6
 Problem: Check the size of external flash available with the RP2040
 Solution: Use an Machine Learning Neural Network model data file of larger size 
 which is of const type that are filled with known values. Program checks the start and end of the data
 to verify that the actual data is available in the flash and thus the size of the external flash is also verified.
*/

// AIM : To check the external Flash on RP2040 using long long arrays
// The char array's datatype in dummy1_long_long_int_data.h, dummy2_long_long_int_data.h have been changed to long long

#include "dummy1_long_long_int_data.h"
#include "dummy2_long_long_int_data.h"

// Built-in Green LED on RP 2040 board (Raspberry Pico)

#define BUILT_IN_LED 25

void setup() {
  
  // initialize digital pin GREEN_LED as an output.
  pinMode(BUILT_IN_LED, OUTPUT);

  // Start serial communication
  Serial.begin(9600);
  delay(500);
}

void loop() {

  // Changed iVal's datatype from char (in sir's code) to long long
  long long int iVal;

  digitalWrite(BUILT_IN_LED, HIGH);
  delay(2000);                      
  digitalWrite(BUILT_IN_LED, LOW);   
  delay(2000);

  Serial.println("Dummy1_long_long_int_data len is:");
  Serial.println(dummy1_long_long_int_data_len);
  Serial.println(" ");
  Serial.println("Size of the dummy1_long_long_int_data[] in bytes:");
  Serial.println(sizeof(dummy1_long_long_int_data));
  Serial.println(" ");

  // The values at the end and start of array were changed as explained in the video lecture
  Serial.println("Some data values stored in the dummy1_long_long_int_data[]");
  Serial.println("dummy1_long_long_int_data[0] ... the value should be 1234");
  iVal = (long long int) dummy1_long_long_int_data[0];

  // No decimal values is required here 
  Serial.println(iVal);
  Serial.println(" ");
  Serial.println("dummy1_long_long_int_data[812320 - 1] ... the value should be 2345");
  iVal = (long long int) dummy1_long_long_int_data[812320 - 1];  
  Serial.println(iVal);
  Serial.println(" "); 

  Serial.println("Dummy2_long_long_int_data len is:");
  Serial.println(dummy2_long_long_int_data_len);
  Serial.println(" ");
  Serial.println("Size of the dummy2_long_long_int_data[] in bytes:");
  Serial.println(sizeof(dummy2_long_long_int_data));
  Serial.println(" ");
  
  Serial.println("Some data values stored in the dummy2_long_long_int_data[]");
  Serial.println("dummy2_long_long_int_data[0] ... the value should be 3456");
  iVal = (long long int) dummy2_long_long_int_data[0];
  Serial.println(iVal);
  Serial.println(" ");
  Serial.println("dummy2_long_long_int_data[812320 - 1] ... the value should be 4567");
  iVal = (long long int) dummy2_long_long_int_data[812320 - 1];  
  Serial.println(iVal);  
  Serial.println(" ");

  // this println line is just for enhancing readability in output
  
  Serial.println("\n\n--------------------------\n\n");

} // end of loop()
