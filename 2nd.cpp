#include<bits/stdc++.h>
using namespace std;

template <class T>
class node
{
public:
    T data;
    node * nxt;
};

template <class T>
class SinglyLinkedList
{
public:
    node<T> * head;
    int sz;
    SinglyLinkedList()
    {
        head = NULL;
        sz=0;
    }

    //Creates a new node with data = value and nxt= NULL
    node<T>* CreateNewNode(T value)
    {
        node<T> *newnode = new node<T>;
        newnode->data = value;
        newnode->nxt = NULL;
        return newnode;
    }

    // Insert new value at Head
    void InsertAtHead(T value)
    {
        sz++;
        node<T> *a = CreateNewNode(value);
        if(head == NULL)
        {
            head = a;
            return;
        }
        //If head is not NULL
        a->nxt = head;
        head = a;
    }

    //Prints the linked list
    void Traverse()
    {
        node<T>* a = head;
        while(a!= NULL)
        {
            cout<<a->data<<" ";
            a = a->nxt;
        }
        cout<<"\n";
    }

    //Returns number of elements in the linked list
    int getSize()
    {
        //O(1)
        return sz;
    }

    //Delete the first element of a linked list
    void DeleteAtHead()
    {
        if(head == NULL)
        {
            return;
        }
        sz--;
        node<T> *a = head;
        head = a->nxt;
        delete a;
    }

};

template <class T>
class Stack{
public:
	SinglyLinkedList<T> l;

	Stack()
	{

	}
	T top()
	{
		if(l.getSize()==0)
		{
			cout<<"Stack is empty!\n";
			T a;
			return a;
		}
		return l.head->data;
	}

	void push(T val)
	{
		l.InsertAtHead(val);
	}

	void pop()
	{
		if(l.getSize()==0)
		{
			cout<<"Stack is empty\n";
			return;
		}
		l.DeleteAtHead();
	}
};

int main()
{
    Stack <double> st;
    st.push(3.5);
    st.push(3.6);
    st.push(7.8);
    cout<<st.top()<<"\n";
    st.pop();
    cout<<st.top()<<"\n";
    st.pop();
    cout<<st.top()<<"\n";
    st.pop();

    Stack <char> st2;
    st2.push('K');
    st2.push('N');
    st2.push('R');
    cout<<st2.top()<<"\n";
    st2.pop();
    cout<<st2.top()<<"\n";
    st2.pop();
    cout<<st2.top()<<"\n";
    st2.pop();
    cout<<st2.top()<<"\n";

    return 0;
}
