#ifndef ResetSet_h
#define ResetSet_h

template<typename T>
class ResultSet
{
private:
	int index;
	float time;
	clock_t Start;
	clock_t End;

public:
	T result;
	ResultSet()
	{
		index = 0;
		time = 0.00F;
		Start = clock();
	}
	void Stop()
	{

		this->End=clock()-this->Start;
		time = (float)End / ((float)CLOCKS_PER_SEC);
	}
	void IncrementIndex()
	{
		index++;
	}


	ResultSet(T result,int index,float time)
	{
		this->result = result;
		this->index = index;
		this->time = time;
	}

	T Getresult()
	{
		return this->result;
	}

	void Setresult(T result)
	{
		this->result = result;
	}

	int Getindex()
	{
		return this->index;
	}

	void Setindex(int index)
	{
		this->index = index;
	}

	float Gettime()
	{
		return this->time;
	}

	void Settime(float time)
	{
		this->time = time;
	}

	void Display()
	{
		cout << "result: " << result.ToString() << endl;
		cout << "index: " << index << endl;
		cout << "time: " << time << endl;
	}
};


#endif