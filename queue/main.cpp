#include <iostream>

using namespace std;

class Queue
{
private:
    int size;
    int front;
    int rear;
    // pointer Q is stored on the stack, pointing to an array in the heap.
    // store the address of a dynamic array for the queue
    int *Q; // dynamic heap array to store queue elements

public:
    // constructor
    Queue(int s)
    {
        size = s;
        front = -1;
        // init, queue is empty
        rear = -1;
        Q = new int[size]; // allocate dynamic array in heap
    }

    void enqueue(int x)
    {
        if (rear == size - 1)
        {
            cout << "Queue is Full" << endl;
        }
        else
        {
            rear++;
            Q[rear] = x;
        }
    }

    int dequeue()
    {
        // If queue empty, returns -1.
        int x = -1;

        if (front == rear)
        {
            cout << "Queue is Empty" << endl;
            rear == size - 1;
        }
        else
        {
            front++;
            x = Q[front];
            Q[front] = 0; // Clear the memory (optional)
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
            for (int i = front + 1; i <= rear; i++)
            {
                cout << Q[i] << " ";
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

    bool isEmpty() const
    {
        return front == rear;
    }

    bool isFull() const
    {
        return rear == size - 1;
    }

    // Destructor is called and memory is freed
    ~Queue()
    {
        delete[] Q;
        Q = nullptr;
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
