#include "SIO.h"
#include "Timer.h"

void switch_mode() {
	if (settings.mode == Settings::Normal){
		settings.setMode(Settings::Maintenance);

		// Reset IO and timer
		timer.reset();
		io.reset();

		// Create time action
		short lightState = 0;
		TimerAction mLight;
		mLight.create(1000, &maintenanceLight, Timer::REPETITIVE, Timer::INFINITE);
		mLight.state = &lightState;

		// Queue the new work
		timer.queue(&mLight);
	}
	else if (settings.mode == Settings::Maintenance) {
		settings.setMode(Settings::Normal);

		// Reset IO and timer
		timer.reset();
		io.reset();


	}
}

void maintenanceLight(TimerAction *sender) {
	short *state = (short*)sender->state;
	if (*state == 0) {
		digitalWrite(IO::YELLOW_LED, HIGH);
		*state = 1;
	}
	else {
		digitalWrite(IO::YELLOW_LED, LOW);
		*state = 0;
	}
}

void car_event() {
	if (doingPedestrian == 1)
		carReady = 1;
	else
		start_car();
}

void pedestrian_event() {
	if (doingCar == 1)
		pedestrianReady = 1;
	else
		start_pedestrian();
}