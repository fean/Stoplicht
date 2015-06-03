// SIO.h

#ifndef _SIO_h
#define _SIO_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

struct IO {
	// Callbacks
	void (*modeEvent)();
	void (*carEvent)();
	void (*pedestrianEvent)();

	// Hardware constants
	static const short MODE_PIN = 2;
	static const short CAR_PIN = 3;
	static const short PEDESTRIAN_PIN = 4;

	static const short ONBOARD_LED = 13;
	static const short GREEN_LED = 12;
	static const short YELLOW_LED = 11;
	static const short RED_LED = 10;

	// Environment functions
	void init(void(*modeEventCB)(), void(*carEventCB)(), void(*pedestrianEventCB)());
	void reset();

	// Event system
	void handleModeEvent();
	void handleCarPedEvent();

	// IO Setters
	void setRedLight();
	void setYellowLight();
	void setGreenLight();
};

#endif

