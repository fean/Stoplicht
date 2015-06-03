#include "EEPROM.h"
#include "Settings.h"

void Settings::read() {
	byte _country, _mode, _new;
	_new = 0;

	// Get the country value
	_country = EEPROM.read(0);
	// Check the validity of the retrieved value
	if (_country < Settings::CountriesSupported)
		country = _country;
	else {
		country = Settings::Default;
		_new = 1;
	}

	// Get the mode value
	_mode = EEPROM.read(1);
	// Check the validity of the mode value
	if (_mode < Settings::ModesSupported)
		mode = _mode;
	else
	{
		mode = Settings::Normal;
		_new = 1;
	}

	// Write the default values to the persistent store
	if (_new == 1)
		write();
}

void Settings::setMode(Settings::Mode setMode) {
	mode = setMode;
	write();
}

void Settings::setCountry(Settings::Country setCountry) {
	country = setCountry;
	write();
}

void Settings::write() {
	EEPROM.write(0, country);
	EEPROM.write(1, mode);
}

char* Settings::translateCountry() {
	if (country == Settings::Default)
		return "Default";
	else if (country == Settings::Germany)
		return "Germany";
	else if (country == Settings::Austria)
		return "Austria";
}

char* Settings::translateMode() {
	if (mode == Settings::Normal)
		return "Normal";
	else if (mode == Settings::Maintenance)
		return "Maintenance";
}