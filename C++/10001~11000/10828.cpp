#include <iostream>
using namespace std;

#define MAX 10000

class stack_problem {
private:
    int Array[MAX];
    int top;
public:
    stack_problem();
    void push(int push_num);
    int empty();
    int pop();
    int size();
    int _top();
};

stack_problem::stack_problem() {
    top = 0;
}
void stack_problem::push(int push_num) {
    Array[top] = push_num;
    top++;
}
int stack_problem::empty() {
    if (Array[0] == '\0') {
        return 1;
    }
    else return 0;
}
int stack_problem::pop() {
    if (this->empty() == 1)
        return -1;
    else {
        int tmp = this->Array[this->top - 1];
        this->Array[this->top - 1] = '\0';
        top--;
        return tmp;
    }
}
int stack_problem::size() {
    return this->top;
}
int stack_problem::_top() {
    if (this->empty() == 1)
        return -1;
    else
        return this->Array[top - 1];
}

int main() {

    stack_problem stp;

    int input;
    cin >> input;

    string command;
    for (int i = 0; i < input; i++) {
        cin >> command;
        if (command == "push") {
            int push_num;
            cin.ignore();
            cin >> push_num;

            stp.push(push_num);
        }
        else if (command == "empty") {
            cout << stp.empty() << endl;
        }
        else if (command == "pop") {
            cout << stp.pop() << endl;
        }
        else if (command == "size") {
            cout << stp.size() << endl;
        }
        else if (command == "top") {
            cout << stp._top() << endl;
        }
    }
}