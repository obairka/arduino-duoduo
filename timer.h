#ifndef TIMER_H
#define TIMER_H

typedef unsigned long time_t;
typedef void (*task_t)();

time_t startTime;

class Timer{

public:	
	Timer(time_t startDelay, time_t interval, task_t task, int repeats);
	~Timer();
	void stop();
private:
	time_t startDelay;
	time_t interval;
	int repeats;
	int runs = 0; 
	task_t task;
};

class TimerManager{

public:
	TimerManager(Timer * timers, int length);
	~TimerManager();

	void tick();
	void add(Timer * timer);
private:
	Timer * timers;
	int length;
};

#endif