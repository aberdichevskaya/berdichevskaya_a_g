#ifndef QUEUE_H
#define QUEUE_H

class Queue
{

private:
	int* i_first{ 0 };
	int* i_last{ 0 };
	int size_{ 20 };
	double* data_ = new double[size_];
public:
	Queue() = default;
	Queue(const Queue& data);
	~Queue();
	Queue& operator=(const Queue& rhs);
	bool operator==(const Queue& rhs);
	bool operator!=(const Queue& rhs);
	void Push(int value);
	void Pop() noexcept;
	int Front();
	int Back();
	bool IsEmpty();
};


#endif
