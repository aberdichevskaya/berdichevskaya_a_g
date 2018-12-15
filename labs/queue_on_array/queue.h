#ifndef QUEUE_H
#define QUEUE_H

class Queue
{

private:
	int* data_ = new int[size_];
	int* i_first = &data_[0];
	int* i_last = &data_[0];
	int size_{ 20 };
public:
	Queue() = default;
	Queue(const Queue& data);
	~Queue();
	Queue& operator=(const Queue& rhs);
	bool operator==(const Queue& rhs);
	bool operator!=(const Queue& rhs);
	void Push(int value);
	void Pop();
	int Front();
	int Back();
	bool IsEmpty();
	std::ostream& WriteTo(std::ostream& ostr) const;
};

std::ostream& operator<<(std::ostream& ostr, const Queue& rhs);


#endif
