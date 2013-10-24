const int CQ_SIZE = 10;

//OUROBOROS ARRAY
template<class T>
class CircularQueue
{
private:
	int mHead;
	int Tail;
	int mCount;

	T mData[CQ_SIZE];

public:
	CircularQueue();
	~CircularQueue();

	bool isEmpty();
};

template<class T>
CircularQueue<T>::CircularQueue()
{
	mHead = mTail = mCount = 0;
}

template<class T>
CircularQueue<T>::~CircularQueue()
{

}

template<class T>
bool CircularQueue<T>::isEmpty()
{
	return !mCount;
}