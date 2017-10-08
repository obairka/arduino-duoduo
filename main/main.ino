#include "timer.h"

void printHello()
{
  Serial.print("hello\n");
}

TimerManager* tmg;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  Timer timer(1000, 1000, printHello, 100);
  tmg = new TimerManager (&timer, 1);

}

void loop() {
  // put your main code here, to run repeatedly:
  //hello();
  tmg->tick();
}
