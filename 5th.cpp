
#include <bits/stdc++.h>
using namespace std;

template<class T>
class node
{
public:
    T data;
    node* prv;
    node* nxt;
};

template<class T>
class Deque
{
public:
    node<T>* head;
    node<T>* tail;
    int sz;

    Deque()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
    }

    node <T> * CreateNewNode(T value)
    {
        node<T>* newnode = new node<T>;
        newnode->data = value;
        newnode->nxt = NULL;
        newnode->prv = NULL;
        return newnode;
    }

    void push_back(T value)
    {
        node<T>* newnode = CreateNewNode(value);
        if(sz==0)
        {
            head = newnode;
            tail = newnode;
            sz++;
            return;
        }
        tail->nxt = newnode;
        newnode->prv = tail;
        tail = newnode;
        sz++;
    }

    void push_front(T value)
    {
        node<T>* newnode = CreateNewNode(value);
        if(sz==0)
        {
            head = newnode;
            tail = newnode;
            sz++;
            return;
        }
        head->prv = newnode;
        newnode->nxt = head;
        head = newnode;
        sz++;
    }

    void pop_back()
    {
        if(sz==0)
        {
            cout<<"Deque is empty\n";
            return;
        }
        if(sz==1)
        {
            delete tail;
            head = NULL;
            tail = NULL;
            sz--;
            return;
        }
        node<T> *a = tail;
        tail= tail->prv;
        delete a;
        tail->nxt = NULL;
        sz--;
    }

    void pop_front()
    {
        if(sz==0)
        {
            cout<<"Deque is empty\n";
            return;
        }
        if(sz==1)
        {
            delete tail;
            head = NULL;
            tail = NULL;
            sz--;
            return;
        }

        node<T> *a = head;
        head = head->nxt;
        delete a;
        head->prv = NULL;
        sz--;
    }

    T front()
    {
        if(sz==0)
        {
            cout<<"Deque is empty\n";
            return -1;
        }
        return head->data;
    }

    T back()
    {
        if(sz==0)
        {
            cout<<"Deque is empty\n";
            return -1;
        }
        return tail->data;
    }
};


int main()
{
    Deque <double>d;
    d.push_back(5.23);
    d.push_back(10.234);
    d.push_back(15.25);

    cout<<"Back : "<<d.back()<<" Front : "<<d.front()<<endl;

    d.push_front(20.23);
    cout<<"Back : "<<d.back()<<" Front : "<<d.front()<<endl;
    d.pop_front();
    cout<<"Back : "<<d.back()<<" Front : "<<d.front()<<endl;

    d.pop_back();
    cout<<"Back : "<<d.back()<<" Front : "<<d.front()<<endl;

    return 0;
}
