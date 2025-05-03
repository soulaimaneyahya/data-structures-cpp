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

    // Destructor is called and memory is freed
    ~Stack()
    {
        delete[] S;
        setStack(nullptr);
    }
};

int main()
{
    return 0;
}
