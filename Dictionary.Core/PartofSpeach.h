
#ifndef PartofSpeach_h
#define PartofSpeach_h

using namespace std;

class PartofSpeach : public Node<PartofSpeach,string>
{
	private:
	string data;

	public:

	PartofSpeach(string data)
	{
		this->data = data;
	}

	PartofSpeach(PartofSpeach  &partofspeach)
	{
		this->data = partofspeach.Getdata();
	}
	string Getdata()
	{
		return this->data;
	}

	void Setdata(string data)
	{
		this->data = data;
	}

	string GetValue()
	{
		return this->data;
	}
	void SetValue(string data)
	{
		this->data = data;
	}
};


#endif