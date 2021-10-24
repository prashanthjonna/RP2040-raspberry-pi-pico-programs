/*
 Author: Mouli Sankaran 
 Date: 6th Sep 2021 (recording is being shared)
 Class: Lab 6
 Problem: Check the size of external flash available with the RP2040
 Solution: Use an Machine Learning Neural Network model data file of larger size 
 which is of const type that are filled with known values. Program checks the start and end of the data
 to verify that the actual data is available in the flash and thus the size of the external flash is also verified.
*/

// AIM : To check the external Flash on RP2040 using double arrays
// The arrays in dummy1_double_data.h, dummy2_doubl_data.h have been changed to double

#include "dummy1_double_data.h"
#include "dummy2_double_data.h"

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

  // Changed iVal's datatype from char (in sir's code) to double
  double iVal;

  digitalWrite(BUILT_IN_LED, HIGH);
  delay(2000);                      
  digitalWrite(BUILT_IN_LED, LOW);   
  delay(2000);

  Serial.println("Dummy1_double_data len is:");
  Serial.println(dummy1_double_data_len);
  Serial.println(" ");
  Serial.println("Size of the dummy1_double_data[] in bytes:");
  Serial.println(sizeof(dummy1_double_data));
  Serial.println(" ");
  
  // It was stated in the video lecture to set the beginning value of array as 1.234f and the value at the end of array as 2.345f
  Serial.println("Some data values stored in the dummy1_double_data[]");
  Serial.println("dummy1_double_data[0], the value should be 1.234f (Look up the related .h file for reference)");
  iVal = (double) dummy1_double_data[0];
  
  //Although 3 decimals is enough, I have chosen to get up to four decimal values in output
  Serial.println(iVal, 4);
  Serial.println(" ");
  Serial.println("dummy1_double_data[812320 - 1], the value should be 2.345f (Look up the related .h file for reference)");
  iVal = (double) dummy1_double_data[dummy1_double_data_len - 1];  
  Serial.println(iVal, 4); 
  Serial.println(" ");
  
  Serial.println("Dummy2_double_data len is:");
  Serial.println(dummy2_double_data_len);
  Serial.println(" ");
  Serial.println("Size of the dummy2_double_data[] in bytes:");
  Serial.println(sizeof(dummy2_double_data));
  Serial.println(" ");
  
  // It was stated in the video lecture to set the beginning value of 2nd array as 3.456f and the value at the end of array as 4.567f
  Serial.println("Some data values stored in the dummy2_double_data[]");
  Serial.println("dummy2_double_data[0] , the value should be 3.456f");
  iVal = (double) dummy2_double_data[0];
  
  Serial.println(iVal, 4);
  Serial.println(" ");
  Serial.println("dummy2_double_data[812320 - 1] , the value should be 4.567f");
  iVal = (double) dummy2_double_data[dummy2_double_data_len - 1];  
  Serial.println(iVal, 4);  
  Serial.println(" ");
  
  // this println line is just for enhancing readability in output
  
  Serial.println("\n\n--------------------------\n\n");

} // end of loop()
