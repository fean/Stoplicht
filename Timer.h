// Timer.h

#ifndef _TIMER_h
#define _TIMER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

struct TimerAction {
	// Sets whether to repeat the action
	byte repetitive;
	// Sets how many times to repeat the action, -1 for infinite
	// Will only be used when repetitive == 1
	long finite;

	void(*callback)(TimerAction *sender);
	void *state;

	unsigned long last;
	unsigned long interval;

	void create(long interval, void(*callback)(TimerAction *sender), byte repetitive, long finite);
};

struct Timer {
	TimerAction** actions;
	short size;

	enum TimerSettings {
		INFINITE = -1,
		NONREPETITIVE = 0,
		REPETITIVE = 1
	};

	void init();
	void queue(TimerAction *action);
	void dequeue(TimerAction *action);
	void dequeueIdx(int idx);
	void reset();
	void run();
};

#endif

