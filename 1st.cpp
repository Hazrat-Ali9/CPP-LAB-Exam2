#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Queue
{
private:
    T *data;
    int front, rear, size;
    int capacity;

public:
    Queue(int s)
    {
        front = rear = 0;
        size = 0;
        capacity = s;
        data = new T[s];
    }

    ~Queue()
    {
        delete[] data;
    }

    void enqueue(T element)
    {
        if (size == capacity)
        {
            T *temp = data;
            capacity = capacity * 2;
            data = new T[capacity];
            int j = 0;
            for (int i = front; i < size; i++)
            {
                data[j] = temp[i];
                j++;
            }
            front = 0;
            rear = size;
            delete[] temp;
        }

        data[rear] = element;
        rear = (rear + 1) % capacity;
        size++;
    }

    T dequeue()
    {
        if (size == 0)
        {
            std::cout << "Queue is Empty" << std::endl;
            return 0;
        }

        T temp = data[front];
        front = (front + 1) % capacity;
        size--;
        return temp;
    }

    T frontElement()
    {
        if (size == 0)
        {
            std::cout << "Queue is Empty" << std::endl;
            return 0;
        }
        return data[front];
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return (size == 0);
    }
};

int main()
{
    Queue<int> q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    std::cout << "Front element is: " << q.frontElement() << std::endl;
    std::cout << "Dequeued element is: " << q.dequeue() << std::endl;

    q.enqueue(60);

    std::cout << "Queue size is: " << q.getSize() << std::endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    if (q.isEmpty())
        std::cout << "Queue is empty" << std::endl;
    else
        std::cout << "Queue is not empty" << std::endl;

    return 0;
}
