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

        // If operand
        if (ch >= '0' && ch <= '9') {
            s.push(ch - '0');
        }

        // If operator
        else if (ch == '+' || ch == '-' || ch == '*' ||
                 ch == '/' || ch == '%') {

            int val2 = s.pop();
            int val1 = s.pop();

            // Check for invalid expression
            if (val1 == -1 || val2 == -1) {
                cout << "Invalid Postfix Expression\n";
                return -1;
            }

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
                    if (val2 == 0) {
                        cout << "Division by Zero\n";
                        return -1;
                    }
                    s.push(val1 / val2);
                    break;

                case '%':
                    if (val2 == 0) {
                        cout << "Modulo by Zero\n";
                        return -1;
                    }
                    s.push(val1 % val2);
                    break;
            }
        }

        else {
            cout << "Invalid Character: " << ch << endl;
            return -1;
        }
    }

    return s.pop();
}

int main() {
    string postfix;

    cout << "Enter Postfix Expression: ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);

    if (result != -1) {
        cout << "Result = " << result << endl;
    }

    return 0;
}