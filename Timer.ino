#include "Timer.h"

void Timer::init() {
	size = 0;
	actions = new TimerAction*[10];
}

void Timer::queue(TimerAction *action) {
	action->last = millis();
	actions[size] = action;

	size++;
}

void Timer::dequeue(TimerAction *action) {
	for (int i = 0; i < size; i++)
		if (actions[i] == action) {
			memmove(actions + i, actions + i + 1, (size - (i + 1)) * sizeof(TimerAction*));
			size--;
			break;
		}
}

void Timer::dequeueIdx(int idx) {
	memmove(actions + idx, actions + idx + 1, (size - (idx + 1)) * sizeof(TimerAction*));
	size--;
}

void Timer::reset() {
	delete[] actions;
	actions = new TimerAction*[10];
	size = 0;
}

void Timer::run() {
	for (int i = 0; i < size; i++)
		if ((actions[i]->last + actions[i]->interval) <= millis()) {
			TimerAction *action = actions[i];
			action->callback(action);
			action->last = millis();
			if (action->repetitive == 1) {
				if (action->finite > 0)
					action->finite--;
				else
					if (action->finite == 0)
						dequeueIdx(i);
			}
			else
				dequeueIdx(i);
		}
}

void TimerAction::create(long iv, void(*cb)(TimerAction *sender),
						 byte rpt, long fnt) {
	interval = iv;
	callback = cb;
	repetitive = rpt;
	finite = fnt - 1;
}