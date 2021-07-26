#include <iostream>
using namespace std;

#define MAX 10000

class quene_problem {
private:
	int top;
	int* Array;
public:
	quene_problem() {
		top = 0;
		Array = new int[MAX];
	}
	void push(int push_num);
	int pop();
	int size();
	int empty();
	int front();
	int back();
	~quene_problem() {
		delete[] Array;
	}
};
void quene_problem::push(int push_num) {
	Array[top] = push_num;
	top++;
}
int quene_problem::pop() {
	int tmp = Array[0];
	for (int i = 0; i < top - 1; i++) {
		Array[i] = Array[i + 1];
	}
	Array[top - 1] = '\0';
	top--;
	return tmp;
}
int quene_problem::size() {
	return top;
}
int quene_problem::empty() {
	if (Array[0] == '\0') {
		return 1;
	}
	else return 0;
}
int quene_problem::front() {
	if (this->empty() == 1)
		return -1;
	else
		return Array[0];
}
int quene_problem::back() {
	if (this->empty() == 1)
		return -1;
	else {
		return Array[top - 1];
	}
}

int main() {

	quene_problem qp;

	int input_num;
	cin >> input_num;

	string command;
	int num;
	for (int i = 0; i < input_num; i++) {
		cin >> command;
		if (command == "push") {
			int push_num;
			cin.ignore();
			cin >> push_num;

			qp.push(push_num);
		}
		else if (command == "empty") {
			cout << qp.empty() << endl;
		}
		else if (command == "pop") {
			if (qp.empty() == 1)
				num = -1;
			else num = qp.pop();
			cout << num << endl;
		}
		else if (command == "size") {
			cout << qp.size() << endl;
		}
		else if (command == "front") {
			cout << qp.front() << endl;
		}
		else if (command == "back") {
			cout << qp.back() << endl;
		}
	}
}