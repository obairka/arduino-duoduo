#ifndef TIMER_H
#define TIMER_H

typedef unsigned long time_t;
typedef void (*task_t)();

class Timer{

public:	
	Timer(time_t startDelay, time_t interval, task_t task, int repeats);
	~Timer();
	void stop();

  time_t startDelay;
  time_t interval;
  int repeats;
  int runs = 0; 
  task_t task;
};

class TimerManager {

public:
	TimerManager(Timer * timers, int length);
	~TimerManager();

	void tick();
	void add(Timer * timer);
private:
	Timer * timers;
	int length;
  time_t startTime;

};

#endif
