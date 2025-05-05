#include <iostream>

using namespace std;

class Stack
{
private:
    int size;
    int top;
    int *S; // dynamic heap array to store Stack elements

public:
    // constructor
    Stack(int s)
    {
        size = s;
        top = -1;
        S = new int[size]; // allocate dynamic array in heap
    }

    void push(int x)
    {
        if (isFull())
        {
            cout << "Stack overflow" << endl;
        }
        else
        {
            top++;
            S[top] = x; // push element x onto stack
        }
    }

    int pop()
    {
        int x = -1;

        if (isEmpty())
        {
            cout << "Stack underflow" << endl;
        }
        else
        {
            x = S[top]; // pop element from stack
            top--;
        }

        return x;
    }

    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << S[i] << " ";
        }
        cout << endl;
    }

    int *getStack()
    {
        return S;
    }

    Stack &setStack(int *s)
    {
        S = s;

        return *this;
    }

    // Getter and Chainable Setter for size
    int getSize() const
    {
        return size;
    }

    Stack &setSize(int s)
    {
        size = s;

        return *this;
    }

    // Getter and Chainable Setter for top
    int getTop() const
    {
        return top;
    }

    Stack &setTop(int t)
    {
        top = t;

        return *this;
    }

    bool isEmpty() const
    {
        return top == -1;
    }

    bool isFull() const
    {
        return top == size - 1;
    }

    // Destructor is called and memory is freed
    ~Stack()
    {
        delete[] S;
        setStack(nullptr);
    }
};

int main()
{
    int size, n, val;

    cout << "Enter size of stack: ";
    cin >> size;

    // constructor is called
    Stack st(size);

    cout << "Enter number of elements to push: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> val;
        st.push(val);
    }

    cout << "Stack elements: ";
    st.display();
}
