#include "timer.h"
#include "Arduino.h"

Timer::Timer(time_t startDelay, time_t interval, task_t task, int repeats){
	this->startDelay = startDelay;
	this->interval = interval;
	this->task = task;
	this->repeats = repeats;
	this->runs = 0;
}

Timer::~Timer(){}

void Timer::stop(){
	repeats = 0; 
}

TimerManager::TimerManager(Timer * timers, int length){
	this->timers = timers;
	this->length = length;
  this->startTime = millis();
}

TimerManager::~TimerManager(){}

void TimerManager::tick(){
	int i;
	for (i = 0; i < length; i++){
		struct Timer * timer = &(timers[i]);
		int needToRun = (millis() >= timer->startDelay);

		if (needToRun && timer->runs < timer->repeats){
			timer->task();
			timer->runs++;
			timer->startDelay = millis() + timer->interval;
		}
	}	

}
