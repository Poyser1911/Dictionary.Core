#ifndef Node_h
#define Node_h
template <class T,class TKEY>
class Node
{
protected:
	T* Next;

public:
	Node()
	{
		this->Next = NULL;
	}
	T* GetNextNode()
	{
		return this->Next;
	}
	void SetNextNode(T* Next)
	{
		this->Next = Next;
	}

	TKEY GetValue()
	{
		return new TKEY();
	}
	void virtual SetValue(TKEY)
	{

	}
};
#endif