#include <iostream>
using namespace std;

#define SIZE 5

int arr[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value)
{
    if ((rear + 1) % SIZE == front)
    {
        cout << "Queue is Full\n";
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % SIZE;
    arr[rear] = value;

    cout << value << " inserted\n";
}

void dequeue()
{
    if (front == -1)
    {
        cout << "Queue is Empty\n";
        return;
    }

    cout << arr[front] << " deleted\n";

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
}

void display()
{
    if (front == -1)
    {
        cout << "Queue is Empty\n";
        return;
    }

    cout << "Queue: ";

    int i = front;

    while (true)
    {
        cout << arr[i] << " ";

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }

    cout << endl;
}

int main()
{
    int choice, value;

    while (true)
    {
        cout << "\n--- Circular Queue ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}