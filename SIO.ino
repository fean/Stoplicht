#include "SIO.h"

void IO::init(void(*modeEventCB)(), void(*carEventCB)(), void(*pedestrianEventCB)()) {
	modeEvent = modeEventCB;
	carEvent = carEventCB;
	pedestrianEvent = pedestrianEventCB;

	pinMode(IO::ONBOARD_LED, OUTPUT);
	pinMode(IO::RED_LED, OUTPUT);
	pinMode(IO::YELLOW_LED, OUTPUT);
	pinMode(IO::GREEN_LED, OUTPUT);

	pinMode(IO::MODE_PIN, INPUT);
	pinMode(IO::CAR_PIN, INPUT);
	pinMode(IO::PEDESTRIAN_PIN, INPUT);

	Serial.begin(9600);
}

void IO::reset() {
	digitalWrite(IO::RED_LED, LOW);
	digitalWrite(IO::YELLOW_LED, LOW);
	digitalWrite(IO::GREEN_LED, LOW);
}

void IO::handleModeEvent() {
	if (digitalRead(IO::MODE_PIN) == HIGH)
		modeEvent();
}

void IO::handleCarPedEvent() {
	if (digitalRead(IO::CAR_PIN) == HIGH)
		carEvent();
	if (digitalRead(IO::PEDESTRIAN_PIN) == HIGH)
		pedestrianEvent();
}

void IO::setRedLight() {
	digitalWrite(IO::GREEN_LED, LOW);
	digitalWrite(IO::YELLOW_LED, LOW);
	digitalWrite(IO::RED_LED, HIGH);
}

void IO::setYellowLight() {
	digitalWrite(IO::GREEN_LED, LOW);
	digitalWrite(IO::RED_LED, LOW);
	digitalWrite(IO::YELLOW_LED, HIGH);
}

void IO::setGreenLight() {
	digitalWrite(IO::RED_LED, LOW);
	digitalWrite(IO::YELLOW_LED, LOW);
	digitalWrite(IO::GREEN_LED, HIGH);
}