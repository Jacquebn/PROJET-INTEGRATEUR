#include <ArduinoUnit.h>
#include <Left_Right.h>

// Declare test cases
test(test_Forward) {
	Forward();
	// Verify that the left motor is set to forward with full speed
	assertEqual(digitalRead(HighL), LOW);
	assertEqual(digitalRead(LowL), HIGH);
	assertEqual(analogRead(EnableL), 255);
	// Verify that the right motor is set to forward with full speed
	assertEqual(digitalRead(HighR), LOW);
	assertEqual(digitalRead(LowR), HIGH);
	assertEqual(analogRead(EnableR), 255);
}

test(test_Backward) {
	Backward();
	// Verify that the left motor is set to backward with full speed
	assertEqual(digitalRead(HighL), HIGH);
	assertEqual(digitalRead(LowL), LOW);
	assertEqual(analogRead(EnableL), 255);
	// Verify that the right motor is set to backward with full speed
	assertEqual(digitalRead(HighR), HIGH);
	assertEqual(digitalRead(LowR), LOW);
	assertEqual(analogRead(EnableR), 255);
}

test(test_Left1) {
	Left1();
	// Verify that the left motor is set to forward with speed of 200
	assertEqual(digitalRead(HighL), LOW);
	assertEqual(digitalRead(LowL), HIGH);
	assertEqual(analogRead(EnableL), 200);
	// Verify that the right motor is set to forward with full speed
	assertEqual(digitalRead(HighR), LOW);
	assertEqual(digitalRead(LowR), HIGH);
	assertEqual(analogRead(EnableR), 255);
}

test(test_Left2) {
	Left2();
	// Verify that the left motor is set to forward with speed of 160
	assertEqual(digitalRead(HighL), LOW);
	assertEqual(digitalRead(LowL), HIGH);
	assertEqual(analogRead(EnableL), 160);
	// Verify that the right motor is set to forward with full speed
	assertEqual(digitalRead(HighR), LOW);
	assertEqual(digitalRead(LowR), HIGH);
	assertEqual(analogRead(EnableR), 255);
}

test(test_Left3) {
	Left3();
	// Verify that the left motor is set to forward with speed of 100
	assertEqual(digitalRead(HighL), LOW);
	assertEqual(digitalRead(LowL), HIGH);
	assertEqual(analogRead(EnableL), 100);
	// Verify that the right motor is set to forward with full speed
	assertEqual(digitalRead(HighR), LOW);
	assertEqual(digitalRead(LowR), HIGH);
	assertEqual(analogRead(EnableR), 255);
}

