#ifndef Timer_h
#define Timer_h
#include <time.h>
#include <iostream>

class Timer
{
private:
	string TimerName;
	clock_t Start;
	clock_t End;
public:
	double seconds;
	Timer()
	{

	}
	Timer(string TimerName,bool AutoStart = true, bool AnounceStart = true)
	{
		this->TimerName = TimerName;
		if(AutoStart)
		{
			Start = clock();
			if(AnounceStart)
				cout << TimerName << " Started." << endl;
		}
	}
	double Stop(bool AnounceStop = true)
	{
		this->End=clock()-this->Start;
		seconds = (double)End / ((double)CLOCKS_PER_SEC);
		if(AnounceStop)
			cout << TimerName << " Stopped within " << seconds << "s." << endl;
		return seconds;
	}

	clock_t GetStart()
	{
		return this->Start;
	}

	void SetStart(clock_t Start)
	{
		this->Start = Start;
	}

	clock_t GetEnd()
	{
		return this->End;
	}

	void SetEnd(clock_t End)
	{
		this->End = End;
	}
};

#endif
