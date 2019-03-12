#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class LinkedList
{
private:
    Node *head;
public:
    LinkedList()
    {
        head = NULL;
    }
    
    bool empty()
    {
        return (head==NULL);
    }
    void push(int value)
    {
        Node *temp = new Node();
        temp->data = value;
        temp->next = head;
        head = temp;
    }
    int pop()
    {
        int temp = head->data;
        Node *oldHead=head;
        head=head->next;
        delete oldHead;
        return temp;
    }
    int peek()
    {
        if (!empty())
        {
            return head->data;
        }
        else
        {
            return -99;
        }
    }
};

class MyStack
{
private:
    LinkedList data;
    int s = 0;
public:
    bool empty()
    {
        return data.empty();
    }
    void push(int value)
    {
        cout << "Pushing  " << value << endl;
        data.push(value);
        s++;
    }
    int pop()
    {
        if (data.empty())
        {
            cout << "Error on pop: Stack is empty" << endl;
            return -99;
            
        }
        else
        {
            s--;
            return data.pop();
        }
    }
    int peek()
    {
        if (empty())
        {
            cout << "Error on peek: Stack is empty" << endl;
            return -99;
        }
        else
        {
            return data.peek();
        }
    }
};

int main(int argc, char* argv[])
{
    MyStack m;
    cout << "Popping too soon " << m.pop() << endl;
    for (int i=0;i<12;i++)
    {
        m.push(i);
    }
    cout << "Peeking: " << m.peek() << endl;
    while (!m.empty())
    {
        cout << "Popping: " << m.pop() << endl;
    }
    return 0;
}
