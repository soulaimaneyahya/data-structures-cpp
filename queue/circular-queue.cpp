#include <iostream>

using namespace std;

class Queue
{
private:
    int size;
    int front;
    int rear;
    int *Q; // dynamic heap array to store queue elements

public:
    // constructor
    Queue(int s)
    {
        size = s;
        front = 0;
        // init, queue is empty
        rear = 0;
        Q = new int[size]; // allocate dynamic array in heap
    }

    void enqueue(int x)
    {
        // In circular queue, rear is one position before front when queue is full
        if (getRearPosition() == front)
        {
            cout << "Queue is Full" << endl;
        }
        else
        {
            rear = getRearPosition();
            Q[rear] = x;
        }
    }

    int dequeue()
    {
        int x = -1;

        if (front == rear)
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            x = Q[front];
            Q[front] = 0; // Optional: Clear the memory
            front = (front + 1) % size;
        }

        return x;
    }

    void display()
    {
        if (front == rear)
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            int i = front;
            while (i != rear)
            {
                cout << Q[i] << " ";
                i = (i + 1) % size;
            }
        }

        cout << endl;
    }

    int *getQueue()
    {
        return Q;
    }

    Queue &setQueue(int *q)
    {
        Q = q;

        return *this;
    }

    // Getter and Chainable Setter for size
    int getSize() const
    {
        return size;
    }

    Queue &setSize(int s)
    {
        size = s;

        return *this;
    }

    // Getter and Chainable Setter for front
    int getFront() const
    {
        return front;
    }

    Queue &setFront(int f)
    {
        front = f;

        return *this;
    }

    // Getter and Chainable Setter for rear
    // const does not modify any class members
    int getRear() const
    {
        return rear;
    }

    Queue &setRear(int r)
    {
        rear = r;

        return *this;
    }

    int getRearPosition() const
    {
        return (rear + 1) % size;
    }

    // Destructor is called and memory is freed
    ~Queue()
    {
        delete[] Q;
        setQueue(nullptr);
    }
};

int main()
{
    int size, n, val;

    cout << "Enter size of queue: ";
    cin >> size;

    // constructor is called
    Queue q(size);

    cout << "Enter number of elements to enqueue: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> val;
        q.enqueue(val);
    }

    cout << "Queue elements: ";
    q.display();

    cout << "Dequeued element: " << q.dequeue() << endl;
    cout << "Queue after dequeue: ";
    q.display();

    return 0;
}
