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
        if (top > size)
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            arr[top] = x;
        }
        return;
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
    start = chrono::system_clock::now();
    aStack.push(8);
    aStack.push(10);
    aStack.push(5);
    aStack.push(11);
    aStack.push(15);
    aStack.push(23);
    aStack.push(6);
    aStack.push(18);
    aStack.push(20);
    aStack.push(17);
    aStack.display();
    aStack.pop();
    aStack.pop();
    aStack.pop();
    aStack.pop();
    aStack.pop();
    aStack.display();
    aStack.push(4);
    aStack.push(30);
    aStack.push(3);
    aStack.push(1);
    aStack.display();
    end = chrono::system_clock::now();
    elapsed_time += chrono::duration_cast<chrono::microseconds>(end - start).count();
    file << "Array Stack: " << elapsed_time << " microseconds" << endl;

    elapsed_time = 0;
    start = chrono::system_clock::now();
    lStack.push(8);
    lStack.push(10);
    lStack.push(5);
    lStack.push(11);
    lStack.push(15);
    lStack.push(23);
    lStack.push(6);
    lStack.push(18);
    lStack.push(20);
    lStack.push(17);
    lStack.display();
    lStack.pop();
    lStack.pop();
    lStack.pop();
    lStack.pop();
    lStack.pop();
    lStack.display();
    lStack.push(4);
    lStack.push(30);
    lStack.push(3);
    lStack.push(1);
    lStack.display();
    end = chrono::system_clock::now();
    elapsed_time += chrono::duration_cast<chrono::microseconds>(end - start).count();
    file << "Linked List Stack: " << elapsed_time << " microseconds" << endl;

    file.close();
}