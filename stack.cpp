#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top == MAX - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int evaluatePostfix(string exp) {
    Stack s;

    for (char ch : exp) {

        if (ch >= '0' && ch <= '9') {
            s.push(ch - '0');
        }

        else {
            int val2 = s.pop();
            int val1 = s.pop();

            switch (ch) {
                case '+':
                    s.push(val1 + val2);
                    break;

                case '-':
                    s.push(val1 - val2);
                    break;

                case '*':
                    s.push(val1 * val2);
                    break;

                case '/':
                    s.push(val1 / val2);
                    break;

                case '%':
                    s.push(val1 % val2);
                    break;
            }
        }
    }

    return s.pop();
}

int main() {
    string postfix;

    cout << "Enter Postfix Expression: ";
    cin >> postfix;

    cout << "Result = " << evaluatePostfix(postfix);

    return 0;
}