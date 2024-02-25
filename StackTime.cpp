#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

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
        vector<int> numbers;
        Node *temp = head;
        while (temp != nullptr)
        {
            numbers.push_back(temp->value);
            temp = temp->next;
        }
        reverse(numbers.begin(), numbers.end());
        for (int num : numbers)
        {
            cout << num << " ";
        }
        cout << endl;
    }
};

int main()
{
    ArrayStack aStack(20);
    LinkedListStack lStack;
    chrono::time_point<chrono::system_clock> start, end;
    ofstream file;
    file.open("Output.txt");

    int elapsed_time = 0;
    for (int i = 0; i < 100; i++)
    {
        ArrayStack aStackCopy = aStack;
        start = chrono::system_clock::now();
        aStackCopy.push(8);
        aStackCopy.push(10);
        aStackCopy.push(5);
        aStackCopy.push(11);
        aStackCopy.push(15);
        aStackCopy.push(23);
        aStackCopy.push(6);
        aStackCopy.push(18);
        aStackCopy.push(20);
        aStackCopy.push(17);
        aStackCopy.display();
        aStackCopy.pop();
        aStackCopy.pop();
        aStackCopy.pop();
        aStackCopy.pop();
        aStackCopy.pop();
        aStackCopy.display();
        aStackCopy.push(4);
        aStackCopy.push(30);
        aStackCopy.push(3);
        aStackCopy.push(1);
        aStackCopy.display();
        end = chrono::system_clock::now();
        elapsed_time += chrono::duration_cast<chrono::microseconds>(end - start).count();
    }
    file << "Array Stack: " << elapsed_time / 100 << " microseconds" << endl;

    elapsed_time = 0;
    for (int i = 0; i < 100; i++)
    {
        LinkedListStack lStackCopy = lStack;
        start = chrono::system_clock::now();
        lStackCopy.push(8);
        lStackCopy.push(10);
        lStackCopy.push(5);
        lStackCopy.push(11);
        lStackCopy.push(15);
        lStackCopy.push(23);
        lStackCopy.push(6);
        lStackCopy.push(18);
        lStackCopy.push(20);
        lStackCopy.push(17);
        lStackCopy.display();
        lStackCopy.pop();
        lStackCopy.pop();
        lStackCopy.pop();
        lStackCopy.pop();
        lStackCopy.pop();
        lStackCopy.display();
        lStackCopy.push(4);
        lStackCopy.push(30);
        lStackCopy.push(3);
        lStackCopy.push(1);
        lStackCopy.display();
        end = chrono::system_clock::now();
        elapsed_time += chrono::duration_cast<chrono::microseconds>(end - start).count();
    }
    file << "Linked List Stack: " << elapsed_time / 100 << " microseconds" << endl;
    file.close();
}