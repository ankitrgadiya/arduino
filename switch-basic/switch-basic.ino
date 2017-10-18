int  greenLedPin = 13;
int  redLedPin   = 12;
int  blueLedPin  = 11;
int  input       = 0;

bool greenStatus = LOW;
bool redStatus   = LOW;
bool blueStatus  = LOW;

void setup()
{
	Serial.begin(9600);
	pinMode (greenLedPin, OUTPUT);
	pinMode (redLedPin,   OUTPUT);
	pinMode (blueLedPin,  OUTPUT);
}

void loop()
{
	while (Serial.available() == 0);

	input = Serial.parseInt();
	Serial.print(input);

	switch (input) {
		case 1:
			greenStatus = !greenStatus;
			digitalWrite (greenLedPin, greenStatus);
			break;
		case 2:
			redStatus = !redStatus;
			digitalWrite (redLedPin,   redStatus  );
			break;
		case 3:
			blueStatus = !blueStatus;
			digitalWrite (blueLedPin,  blueStatus );
			break;
		default:
			break;
	}

	Serial.println();
}
