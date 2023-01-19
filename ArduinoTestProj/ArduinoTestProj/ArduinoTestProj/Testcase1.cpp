#include <ArduinoUnit.h>
#include "Forward_Backward.h"

// Declare pins as global variables
const int EnableL = 5;
const int HighL = 6;
const int LowL = 7;
const int EnableR = 10;
const int HighR = 8;
const int LowR = 9;

void setup() {
	pinMode(EnableL, OUTPUT);
	pinMode(HighL, OUTPUT);
	pinMode(LowL, OUTPUT);
	pinMode(EnableR, OUTPUT);
	pinMode(HighR, OUTPUT);
	pinMode(LowR, OUTPUT);
}

test(forward_moves_motors_forward) {
	Forward();
	assertEqual(digitalRead(HighL), LOW);
	assertEqual(digitalRead(LowL), HIGH);
	assertEqual(analogRead(EnableL), 255);
	assertEqual(digitalRead(HighR), LOW);
	assertEqual(digitalRead(LowR), HIGH);
	assertEqual(analogRead(EnableR), 255);
}

void loop() {

}
