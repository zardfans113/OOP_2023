#include <iostream>
#include <vector>

using namespace std;

class Cqueue
{
private:
    vector<int> queue;
    int start;
    int end;
    int capacity;
    int size;
public:
    Cqueue(int capacity);
    void Push(int value);
    int Pop();
    void Reverse();
    void Print();
};