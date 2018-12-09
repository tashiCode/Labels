/*------------------------------------------------------------------------
  Example sketch for Adafruit Thermal Printer library for Arduino.
  Demonstrates a few text styles & layouts, bitmap printing, etc.

  IMPORTANT: DECLARATIONS DIFFER FROM PRIOR VERSIONS OF THIS LIBRARY.
  This is to support newer & more board types, especially ones that don't
  support SoftwareSerial (e.g. Arduino Due).  You can pass any Stream
  (e.g. Serial1) to the printer constructor.  See notes below.

  You may need to edit the PRINTER_FIRMWARE value in Adafruit_Thermal.h
  to match your printer (hold feed button on powerup for test page).
  ------------------------------------------------------------------------*/

#include "Adafruit_Thermal.h"

// Here's the new syntax when using SoftwareSerial (e.g. Arduino Uno) ----
// If using hardware serial instead, comment out or remove these lines:

#include "SoftwareSerial.h"
#define TX_PIN 6 // Arduino transmit  YELLOW WIRE  labeled RX on printer
#define RX_PIN 5 // Arduino receive   GREEN WIRE   labeled TX on printer

SoftwareSerial mySerial(RX_PIN, TX_PIN); // Declare SoftwareSerial obj first
Adafruit_Thermal printer(&mySerial);     // Pass addr to printer constructor
// Then see setup() function regarding serial & printer begin() calls.

boolean __ardublockDigitalReadPullup(int pinNumber)
{
  pinMode(pinNumber, INPUT_PULLUP);
  return digitalRead(pinNumber);
}

bool F = false;

String questions [7] = {
  "What is your name?",
  "What year were you born in?",
  "What did people call you in high school?",
  "One word to describe yourself:",
  "What's your father's name?",
  "Mother's name?",
  "Thank you, please wait while you are labelled..."};
  
String answer [6] = {"","","","","",""};

int i = 0;
int n = 0;

char n_byte = 0;
String n_str = "";

// -----------------------------------------------------------------------

void setup() {

  // NOTE: SOME PRINTERS NEED 9600 BAUD instead of 19200, check test page.
  mySerial.begin(19200);  // Initialize SoftwareSerial
  //Serial1.begin(19200); // Use this instead if using hardware serial
  printer.begin();        // Init printer (same regardless of serial type)

  // The following calls are in setup(), but don't *need* to be.  Use them
  // anywhere!  They're just here so they run one time and are not printed
  // over and over (which would happen if they were in loop() instead).
  // Some functions will feed a line when called, this is normal.
  Serial.println("Welcome");
  Serial.println("");
  Serial.println(questions[0]);
}

void loop() {
  while (i<=5) {
    if (Serial.available() > 0) {    // is a character available?
      n_byte = Serial.read();       // get the character
    
      if (n_byte != '\n') {
        // a character of the string was received
        n_str += n_byte;
      }
      else {
        // end of string
        answer[i] = n_str;
        n_str = ""; // clear n string
        Serial.println(answer[i]);
        Serial.println("");
        Serial.println(questions[i+1]);
        i++;
       }
     } // end: if (Serial.available() > 0)
  }
    if (( ( __ardublockDigitalReadPullup(A1) ) == F ))
  {
    printDataSerial();
    printDataThermal();
    clearAll();
  }
}

void printDataSerial()
{
  Serial.print("");
  Serial.print("Name:");
  Serial.print(" ");
  Serial.print(answer[0]);
  Serial.print(" ");
  Serial.print("(b.");
  Serial.print(answer[1]);
  Serial.print(" A.D.");
  Serial.print(")");
  Serial.print(" ");
  Serial.println();
  Serial.print("Labels:");
  Serial.print(" ");
  Serial.print(answer[2]);
  Serial.print(" ");
  Serial.print(",");
  Serial.print(" ");
  Serial.print(answer[3]);
  Serial.print(" ");
  Serial.println();
  Serial.print("Homo Sapiens, 197982 B.C.");
  Serial.print(" ");
  Serial.println();
  Serial.print("Courtesy of");
  Serial.print(" ");
  Serial.print(answer[4]);
  Serial.print(" ");
  Serial.print("and");
  Serial.print(" ");
  Serial.print(answer[5]);
  Serial.print(" ");
  Serial.println();
}

void printDataThermal()
{
  printer.println("");
  printer.println("");
  printer.print("Name:");
  printer.print(" ");
  printer.print(answer[0]);
  printer.print(" ");
  printer.print("(b.");
  printer.print(answer[1]);
  printer.print(" A.D.");
  printer.print(")");
  printer.print(" ");
  printer.println();
  printer.boldOn();
  printer.print(answer[2]);
  printer.boldOff();
  printer.print(" ");
  printer.print(",");
  printer.print(" ");
  printer.boldOn();
  printer.print(answer[3]);
  printer.boldOff();
  printer.print(" ");
  printer.println();
  printer.inverseOn();
  printer.print("Homo Sapiens");
  printer.inverseOff();
  printer.print(", 197982 B.C.");
  printer.print(" ");
  printer.println();
  printer.print("Courtesy of");
  printer.print(" ");
  printer.underlineOn();
  printer.print(answer[4]);
  printer.underlineOff();
  printer.print(" ");
  printer.print("and");
  printer.print(" ");
  printer.underlineOn();
  printer.print(answer[5]);
  printer.underlineOff();
  printer.print(" ");
  printer.println();

  printer.sleep();      // Tell printer to sleep
  delay(3000L);         // Sleep for 3 seconds
  printer.wake();       // MUST wake() before printing again, even if reset
  printer.setDefault(); // Restore printer to defaults
}

void clearAll() 
{
  answer[0]="";
  answer[1]="";
  answer[2]="";
  answer[3]="";
  answer[4]="";
  answer[5]="";
}
