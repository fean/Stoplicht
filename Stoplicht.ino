#include "SIO.h"
#include "Settings.h"
#include "Timer.h"

Settings settings;
Timer timer;
IO io;

byte doingCar = 0;
byte doingPedestrian = 0;
byte carReady = 0;
byte pedestrianReady = 0;

void setup()
{
	// Load settings
	settings.read();

	// Init the timer
	timer.init();

	// Init IO
	io.init(&switch_mode, &car_event, &pedestrian_event);
}

void loop()
{
	// Progress the timer
	timer.run();

	// Handle button input
	io.handleModeEvent();
	if (settings.mode == Settings::Normal){
		io.handleCarPedEvent();
	}

	// When in maintenance mode handle serial commands
	if (settings.mode == Settings::Maintenance)
		if (Serial.available()) {
			// TODO: handle input
		}
}