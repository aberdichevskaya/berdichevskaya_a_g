#ifndef STACK_H
#define STACK_H


class StackOnList
{
public:
	StackOnList() = default;
	StackOnList(const StackOnList& rhs);
	StackOnList& operator=(StackOnList& obj);
	~StackOnList();
	bool operator==(const StackOnList& obj);
	bool operator!=(const StackOnList& obj);
	void Push(const int value);
	void Pop() noexcept;
	int Top();
	void Clear()noexcept;
	bool IsEmpty();
	std::ostream& WriteTo(std::ostream& ostr) const;
private:
	struct Node
	{
		Node* next{ nullptr };
		int data{ 0 };
		Node() = default;
		Node(Node* p, int d)
			:next(p)
			, data(d)
		{}
	};
	Node* data_{ nullptr };
};

std::ostream& operator <<(std::ostream& ostr, const StackOnList& rhs);

#endif
