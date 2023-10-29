#include "FlowSensor.h"

FlowSensor::FlowSensor(uint16_t type ,uint8_t pin)
{
	this->_pin = pin;
	this->_pulse1liter = type;
}

void FlowSensor::begin(void (*userFunc)(void))
{
	pinMode(this->_pin, INPUT);
	digitalWrite(this->_pin, INPUT_PULLUP); // Optional Internal Pull-Up
	attachInterrupt(digitalPinToInterrupt(this->_pin), userFunc, RISING); // For better compatibility with any board, for example Arduino Leonardo Boards
}

void FlowSensor::count()
{
	this->_pulse++;
}

void FlowSensor::read(long calibration)
{
	this->_flowratesecound = (this->_pulse / (this->_pulse1liter + calibration)) / ((millis() - this->_timebefore) / 1000);
	this->_volume += (this->_pulse / (this->_pulse1liter + calibration));
	this->_totalpulse += this->_pulse;
	this->_pulse = 0;
	this->_timebefore = millis();
}

unsigned long FlowSensor::getPulse()
{
	return this->_totalpulse;
}

void FlowSensor::resetPulse()
{
	this->_pulse=0;
	this->_totalpulse=0;
}

float FlowSensor::getFlowRate_h()
{
	this->_flowratehour = this->_flowratesecound * 3600;
	return this->_flowratehour;
}

float FlowSensor::getFlowRate_m()
{
	this->_flowrateminute = this->_flowratesecound * 60;
	return this->_flowrateminute;
}

float FlowSensor::getFlowRate_s()
{
	return this->_flowratesecound;
}

float FlowSensor::getVolume()
{
	return this->_volume;
}

void FlowSensor::resetVolume()
{
	this->_volume = 0;
}