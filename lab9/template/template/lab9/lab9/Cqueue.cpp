#include "Cqueue.h"
using namespace std;

Cqueue::Cqueue(int capacity): start(0), end(-1), capacity(capacity), size(0)
{
    capacity = this->capacity;
    // TODO: set the capacity of this->queue to the input capacity.
    // NOTE:
    //      queue: the array that contains all the elements
    //      capacity: capacity of the queue. For example, if capacity is 10, it means that this queue can store at most 10 elements.
    //      start: the first element’s index
    //      end: the last element’s index
    //      When the queue is empty, the value of start MUST be 0, and the value of end MUST be -1.
    //
    //      The capacity is the total number of cells in the queue.
    //      The size is the number of cells that have data in them.
}

void Cqueue::Push(int value)
{
    if (size != capacity) {
        queue.push_back(value);
        size++;
        end++;
    }
    else if(size == capacity){
        cout << "The queue is full." << endl;
    }
    end = end % capacity;
    // TODO: Insert a new value after the last element in the queue.
    //       If the queue is full before the operation, print “The queue is full.” and stop the operation.
}
int Cqueue::Pop()
{
    int tmp = 0;
    if (size == 0) {
        cout << "The queue is empty." << endl;
        return -1;
    }
    else if (size > 0) {
        tmp = queue[start];
        queue.erase(queue.begin());
        size--;
        start++;
        if (size == 0) {
            start = 0;
            end = -1;
        }
    }
    return tmp;
    // TODO: Extract the first element of the queue and return the element’s value.
    //       1. If the queue is empty after this operation, set start to 0, end to -1.
    //       2. If you don’t have any element that can be popped, just print “The queue is empty.” and return value to -1.

}

void Cqueue::Reverse()
{
    reverse(queue.begin(), queue.end());
    // TODO: Reverse all the elements in the queue.

}

void Cqueue::Print()
{
    cout << "size: " << size << endl;
    cout << "capacity: " << capacity << endl;
    cout << "start: " << start << endl;
    cout << "end: " << end << endl;
    cout << "queue: ";
    for (int i = 0; i < size; i++) {
        cout << queue[(start + i) % capacity] << " ";
    }
    cout << endl;
    // TODO: Output the information of the queue and elements in the queue from start to end.
    // Format:
    //      size: ...
    //      capacity: ...
    //      start: ...
    //      end: ...
    //      queue: ...
}