#include <iostream>
#define SIZE 5
using namespace std;

class SamplePointerObjTest
{
    int x;

public:
    SamplePointerObjTest() { this->x = 0; };
    SamplePointerObjTest(int y) { x = y; };
    int getX() { return x; };
};

int main()
{
    SamplePointerObjTest ob[SIZE] = {5, 10, 15};
    SamplePointerObjTest *p = new SamplePointerObjTest();
    cout << p->getX() << endl;
    SamplePointerObjTest *ptr;
    ptr = ob;
    for (int i = 0; i < SIZE; i++)
    {
        cout << "ob[" << i << "]=" << ptr->getX() << endl;
        ptr++; // pointer to another object of array
    }
    return 0;
}
