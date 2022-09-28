#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class MyCircularQueueWithQueue
{
    queue<int> queue;
    int size;

public:
    MyCircularQueueWithQueue(int k)
    {
        size = k;
    }

    bool enQueue(int value)
    {
        if (size > queue.size() || queue.empty())
        {
            queue.push(value);
            return true;
        }
        return false;
    }

    bool deQueue()
    {
        int n = queue.size();
        queue.pop();
        if (queue.size() < n)
        {
            return true;
        }
        return false;
    }

    int Front()
    {
        return queue.front();
    }

    int Rear()
    {
        return queue.back();
    }

    bool isEmpty()
    {
        return queue.empty();
    }

    bool isFull()
    {
        return (queue.size() == size) ? true : false;
    }
};

class MyCircularQueueWithVector
{
private:
    int size;
    vector<int> queue;

public:
    MyCircularQueueWithVector(int k)
    {
        size = k;
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;
        if (size > queue.size())
        {
            queue.push_back(value);
            return true;
        }
        return false;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        int n = queue.size();
        queue.erase(queue.begin());
        if (queue.size() < n)
        {
            return true;
        }
        return false;
    }

    int Front()
    {
        return isEmpty() ? -1 : queue[0];
    }

    int Rear()
    {
        return isEmpty() ? -1 : queue[queue.size() - 1];
    }

    bool isEmpty()
    {
        return queue.empty();
    }

    bool isFull()
    {
        return (queue.size() == size) ? true : false;
    }

    void testCase1()
    {

        MyCircularQueueWithVector *myCircularQueue = new MyCircularQueueWithVector(3);

        bool enQueue1 = myCircularQueue->enQueue(1); // return True
        bool enQueue2 = myCircularQueue->enQueue(2); // return True
        bool enQueue3 = myCircularQueue->enQueue(3); // return True
        bool enQueue4 = myCircularQueue->enQueue(4); // return False
        int rear = myCircularQueue->Rear();          // return 3
        bool full = myCircularQueue->isFull();       // return True
        bool deQueue = myCircularQueue->deQueue();   // return True
        bool enQueue = myCircularQueue->enQueue(4);  // return True
        int rear2 = myCircularQueue->Rear();         // return 4
        cout << boolalpha << enQueue1 << "\n"
             << enQueue2 << "\n"
             << enQueue3 << "\n"
             << enQueue4 << "\n"
             << rear << "\n"
             << full << "\n"
             << deQueue << "\n"
             << enQueue << "\n"
             << rear2 << endl;
    }

    void testCase2()
};

{
    MyCircularQueueWithVector *myCircularQueue1 = new MyCircularQueueWithVector(3);
    bool enQueue1 = myCircularQueue1->enQueue(6);
    // bool enQueue2 = myCircularQueue1->enQueue(6);
    int rear1 = myCircularQueue1->Rear();
    int rear2 = myCircularQueue1->Rear();
    bool deQueue1 = myCircularQueue1->deQueue();
    bool enQueue3 = myCircularQueue1->enQueue(5);
    int rear3 = myCircularQueue1->Rear();
    bool deQueue2 = myCircularQueue1->deQueue();
    int front1 = myCircularQueue1->Front();
    bool deQueue3 = myCircularQueue1->deQueue();
    bool deQueue4 = myCircularQueue1->deQueue();
    bool deQueue5 = myCircularQueue1->deQueue();

    cout << boolalpha << enQueue1 << "\n"
         //  << enQueue2 << "\n"
         << rear1 << "\n"
         << rear2 << "\n"
         << deQueue1 << "\n"
         << enQueue3 << "\n"
         << rear3 << "\n"
         << deQueue2 << "\n"
         << front1 << "\n"
         << deQueue3 << "\n"
         << deQueue4 << "\n"
         << deQueue5
         << endl;
}

int main()
{
    MyCircularQueueWithVector *myCircularQueue = new MyCircularQueueWithVector(3);

    myCircularQueue.testCase1();
    myCircularQueue.testCase2();
}