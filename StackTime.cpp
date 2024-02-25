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
    chrono::high_resolution_clock::time_point start1;
    chrono::high_resolution_clock::time_point end1;
    chrono::high_resolution_clock::time_point start2;
    chrono::high_resolution_clock::time_point end2;
    int elapsed_time1;
    int elapsed_time2;
    int average_time1;
    int average_time2;

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

    // Average time for pushing 10 elements
    elapsed_time1 = 0;
    elapsed_time2 = 0;
    for (int i = 0; i < 10; i++)
    {
        start1 = chrono::high_resolution_clock::now();
        aStack.push(arr[i]);
        end1 = chrono::high_resolution_clock::now();
        elapsed_time1 += chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();

        start2 = chrono::high_resolution_clock::now();
        lStack.push(arr[i]);
        end2 = chrono::high_resolution_clock::now();
        elapsed_time2 += chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count();
    }
    average_time1 = elapsed_time1 / 10;
    average_time2 = elapsed_time2 / 10;
    file << "AveragePushTime1"
         << " ";
    file << average_time1 << " " << average_time2 << endl;

    // Average time for popping 5 elements
    elapsed_time1 = 0;
    elapsed_time2 = 0;
    for (int i = 0; i < 5; i++)
    {
        chrono::high_resolution_clock::time_point start1 = chrono::high_resolution_clock::now();
        aStack.pop();
        chrono::high_resolution_clock::time_point end1 = chrono::high_resolution_clock::now();
        elapsed_time1 += chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();

        chrono::high_resolution_clock::time_point start2 = chrono::high_resolution_clock::now();
        lStack.pop();
        chrono::high_resolution_clock::time_point end2 = chrono::high_resolution_clock::now();
        elapsed_time2 += chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count();
    }
    average_time1 = elapsed_time1 / 5;
    average_time2 = elapsed_time2 / 5;
    file << "AveragePopTime"
         << " ";
    file << average_time1 << " " << average_time2 << endl;

    //Average Time for Display
    start1 = chrono::high_resolution_clock::now();
    aStack.display();
    end1 = chrono::high_resolution_clock::now();
    elapsed_time1 = chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();

    start2 = chrono::high_resolution_clock::now();
    lStack.display();
    end2 = chrono::high_resolution_clock::now();
    elapsed_time2 = chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count();
    file << "Display"
         << " ";
    file << elapsed_time1 << " " << elapsed_time2 << endl;


    // Average time for pushing 4 elements
    elapsed_time1 = 0;
    elapsed_time2 = 0;
    for (int i = 10; i < 14; i++)
    {
        start1 = chrono::high_resolution_clock::now();
        aStack.push(arr[i]);
        end1 = chrono::high_resolution_clock::now();
        elapsed_time1+= chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();

        start2 = chrono::high_resolution_clock::now();
        lStack.push(arr[i]);
        end2 = chrono::high_resolution_clock::now();
        elapsed_time2 += chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count();
    }
    average_time1 = elapsed_time1 / 4;
    average_time2 = elapsed_time2 / 4;
    file << "AveragePushTime2"
         << " ";
    file << average_time1 << " " << average_time2 << endl;


    // Average time for popping 3 elements
    start1 = chrono::high_resolution_clock::now();
    aStack.display();
    end1 = chrono::high_resolution_clock::now();
    elapsed_time1 = chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();

    start2 = chrono::high_resolution_clock::now();
    lStack.display();
    end2 = chrono::high_resolution_clock::now();
    elapsed_time2 = chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count();

    file << "Display2"
         << " ";
    file << elapsed_time1 << " " << elapsed_time2 << endl;


    file.close();
}