#include <fstream>
#include "Cqueue.h"
using namespace std;

int main()
{
    ifstream file("input.txt");
    if (file.fail()) exit(1);

    int testCase, nOperation, capacity, value;
    char oper;

    file >> testCase;
    while (testCase --)
    {
        file >> capacity;
        Cqueue cq(capacity);

        file >> nOperation;
        while (nOperation --)
        {
            file >> oper;
            switch (oper)
            {
                case '+':
                    file >> value;
                    cq.Push(value);
                    break;
                case '-':
                    cq.Pop();
                    break;
                case 'r':
                    cq.Reverse();
                    break;
                case 'p':
                    cq.Print();
                    break;
            }
        }
    }

    return 0;
}