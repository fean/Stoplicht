#ifndef _SETTINGS_h
	#define _SETTINGS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

struct Settings {
	byte country;
	byte mode;

	enum Country
	{
		Default = 0,
		Germany = 1,
		Austria = 2,
		CountriesSupported = 3,
	};

	enum Mode
	{
		Normal = 0,
		Maintenance = 1,
		ModesSupported = 2
	};
	
	// Store access
	void read();
	void setMode(Mode mode);
	void setCountry(Country country);

	// Logging
	char* translateCountry();
	char* translateMode();
private:
	void write();
};

#endif

