#ifndef linkedlist_hpp
#define linkedlist_hpp

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

// Node class
class node
{
public:
    string data;
    node* next;
};

// Linked list class
class linkedlist
{
public:
    node *head, *tail;
public:
    // Constructor
    linkedlist()
    {
        head=NULL;
        tail=NULL;
    }
    // Adds new node to end of list
    void create_node(string value)
    {
        node *temp=new node;
        temp->data=value;
        temp->next=NULL;
        if ( head == NULL )
        {
            head=temp;
            tail=temp;
            temp=NULL;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }
    // Dumps contents of linked list
    void display()
    {
        node *temp=new node;
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"\n";
            temp=temp->next;
        }
    }
    // Inserts new node at the start of list
    void insert_start(string value)
    {
        node *temp=new node;
        temp->data=value;
        temp->next=head;
        head=temp;
    }
    // Inserts new node at specified location
    void insert_position(int pos, string value)
    {
        node *pre=new node;
        node *cur=new node;
        node *temp=new node;
        cur=head;
        for(int i=1;i<pos;i++)
        {
            pre=cur;
            cur=cur->next;
        }
        temp->data=value;
        pre->next=temp;
        temp->next=cur;
    }
    // Deletes first node
    void delete_first()
    {
        node *temp=new node;
        temp=head;
        head=head->next;
        delete temp;
    }
    // Deletes last node
    void delete_last()
    {
        node *current=new node;
        node *previous=new node;
        current=head;
        while(current->next!=NULL)
        {
            previous=current;
            current=current->next;
        }
        tail=previous;
        previous->next=NULL;
        delete current;
    }
    // Deletes node at specified location
    void delete_position(int pos)
    {
        node *current=new node;
        node *previous=new node;
        current=head;
        for(int i=1;i<pos;i++)
        {
            previous=current;
            current=current->next;
        }
        previous->next=current->next;
    }
    // Searches for data within linked list and returns boolean
    bool search(string name)
    {
        node *current=new node;
        current=head;
        while (current!=NULL)
        {
            if (current->data==name)
                return true;
            current = current->next;
        }
        return false;
    }
};


#endif /* linkedlist_hpp */
