#ifndef FlowSensor_h
#define FlowSensor_h

#include "Arduino.h"
#include "FlowSensor_Type.h"

class FlowSensor
{
private:
	uint8_t _pin;
	volatile unsigned long _totalpulse;
	volatile unsigned long _pulse;
	float _pulse1liter;
	float _flowratehour;
	float _flowrateminute;
	float _flowratesecound;
	float _volume;
	unsigned long _timebefore = 0;

public:
	FlowSensor(uint16_t type ,uint8_t pin);
	void begin(void (*userFunc)(void));
	void count();
	void read(long calibration = 0);
	unsigned long getPulse();
	void resetPulse();
	float getFlowRate_h();
	float getFlowRate_m();
	float getFlowRate_s();
	float getVolume();
	void resetVolume();
};

#endif