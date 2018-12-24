#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>

class Priority_queue {
public:
	Priority_queue() = default;
	Priority_queue(const Priority_queue& rhs);
	~Priority_queue();
	bool IsEmpty();
	Priority_queue& operator=(const Priority_queue& rhs);
	bool operator==(const Priority_queue& rhs);
	bool operator!=(const Priority_queue& rhs);
	void pop();
	void push(int key, int value);
	int front();
	int back();
	void order();
	std::ostream& WriteTo(std::ostream& ostr) const;
	struct Node {
		int key{ 0 };
		int value{ 0 };
		Node() = default;
		Node(int key, int value)
			: key(key)
			, value(value) {
		}
		bool operator==(const Node& rhs);
		bool operator<(const Node& rhs);
		bool operator>(const Node& rhs);
		Node operator=(const Node& rhs);
	};
private:
	int size{ 10 };
	Node* data = new Node[size];
	int i_last{ 0 };
	int i_first{ 0 };
};

std::ostream& operator<<(std::ostream& ostr, const Priority_queue& rhs);



#endif // !PRIORITY_QUEUE_H

