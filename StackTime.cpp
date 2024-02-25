#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

class ArrayStack
{
private:
    int *arr;
    int top;
    int size;

public:
    ArrayStack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    bool isFull()
    {
        return (top == size - 1);
    }

    bool isEmpty()
    {
        return (top == -1);
    }

    void push(int x)
    {
        top = top + 1;
        if (top >= size)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        else
        {
            arr[top] = x;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return INT_MIN;
        }
        else
        {
            top -= 1;
            return arr[top + 1];
        }
    }

    int stackTop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return INT_MIN;
        }
        else
        {
            return arr[top];
        }
    }

    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class Node
{
public:
    int value;
    Node *next;

    Node(int value)
    {
        this->value = value;
        this->next = nullptr;
    }
};

class LinkedListStack
{
private:
    Node *top;
    Node *head;

public:
    LinkedListStack()
    {
        top = nullptr;
        head = nullptr;
    }

    bool isEmpty()
    {
        return (head == nullptr);
    }

    void push(int x)
    {
        Node *newNode = new Node(x);
        if (isEmpty())
        {
            head = newNode;
            top = newNode;
        }
        else
        {
            top->next = newNode;
            top = newNode;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return INT_MIN;
        }
        else
        {
            int x = top->value;
            if (head == top)
            {
                top = nullptr;
                head = nullptr;
            }
            else
            {
                Node *temp = head;
                while (temp->next != top)
                {
                    temp = temp->next;
                }
                temp->next = nullptr;
                top = temp;
            }
            return x;
        }
    }

    int stackTop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return INT_MIN;
        }
        else
        {
            return top->value;
        }
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    ArrayStack aStack(20);
    LinkedListStack lStack;
    int arr[] = {8, 10, 5, 11, 15, 23, 6, 18, 20, 17, 4, 30, 3, 1};
    ofstream file;
    file.open("output.txt");

    file << "Operation"
         << " "
         << "ArrayStack"
         << " "
         << "LinkedListStack" << endl;

    for (int i = 0; i < 10; i++)
    {
        file << "Push"
             << "(" << arr[i] << ")"
             << " ";

        chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
        aStack.push(arr[i]);
        chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
        file << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ";

        start = chrono::high_resolution_clock::now();
        lStack.push(arr[i]);
        end = chrono::high_resolution_clock::now();
        file << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ";

        file << endl;
    }

    file << "Display1"
         << " ";
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    aStack.display();
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    file << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ";

    start = chrono::high_resolution_clock::now();
    lStack.display();
    end = chrono::high_resolution_clock::now();
    file << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ";

    file << endl;

    int j = 0;
    for (int i = 0; i < 5; i++)
    {
        file << "Pop" << j++ << " ";

        chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
        aStack.pop();
        chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
        file << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ";

        start = chrono::high_resolution_clock::now();
        lStack.pop();
        end = chrono::high_resolution_clock::now();
        file << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ";

        file << endl;
    }

    file << "Display2"
         << " ";
    start = chrono::high_resolution_clock::now();
    aStack.display();
    end = chrono::high_resolution_clock::now();
    file << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ";

    start = chrono::high_resolution_clock::now();
    lStack.display();
    end = chrono::high_resolution_clock::now();
    file << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ";

    file << endl;

    for (int i = 10; i < 14; i++)
    {
        file << "Push"
             << "(" << arr[i] << ")"
             << " ";

        chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
        aStack.push(arr[i]);
        chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
        file << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ";

        start = chrono::high_resolution_clock::now();
        lStack.push(arr[i]);
        end = chrono::high_resolution_clock::now();
        file << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ";
        file << endl;
    }

    file << "Display3"
         << " ";
    start = chrono::high_resolution_clock::now();
    aStack.display();
    end = chrono::high_resolution_clock::now();
    file << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ";

    start = chrono::high_resolution_clock::now();
    lStack.display();
    end = chrono::high_resolution_clock::now();
    file << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ";
    file << endl;

    file.close();
}