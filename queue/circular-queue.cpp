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
        setQueue(new int[size]) // allocate dynamic array in heap
            .setSize(s)
            .setFront(0)
            .setRear(0); // init, queue is empty
    }

    void enqueue(int x)
    {
        // In circular queue, rear is one position before front when queue is full
        if (getRearPosition() == getFront())
        {
            cout << "Queue is Full" << endl;
        }
        else
        {
            setRear(getRearPosition());
            Q[getRear()] = x;
        }
    }

    int dequeue()
    {
        int x = -1;

        if (getFront() == getRear())
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            x = Q[getFront()];
            Q[getFront()] = 0; // Optional: Clear the memory
            setFront((getFront() + 1) % getSize());
        }

        return x;
    }

    void display()
    {
        if (getFront() == getRear())
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            int i = getFront();
            while (i != getRear())
            {
                cout << Q[i] << " ";
                i = (i + 1) % getSize();
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
        return (getRear() + 1) % getSize();
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
