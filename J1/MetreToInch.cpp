#include <iostream>

using namespace std;

// inline   =>   inline int max(int a , int b){ return a > b ? a : b}
// OOP  => Car ----> attribute: charkh, sandali, farmun, aineh, kapout, .... | method ---> start(), benzin() , ...
//// Class Car{}   ----> Car car[100]; car[1]
// fasl 17

class SizeOfLand
{

public:
    static int count;
    friend bool equal(SizeOfLand obj1, SizeOfLand obj2);
    SizeOfLand(float, string); // constructor
    ~SizeOfLand();             // destructor ----> delete obj
    void readSqMetres();       // method === function
    float toSqInches();        //dec
    void displayLandSize();

private:
    string name;
    float sqMetres; // property, attribute
    void printHello()
    {
        cout << "Hello" << endl;
    };
} obj1(2, "ashkan"), obj2(5, "ashkan");

int SizeOfLand::count = 0;

bool equal(SizeOfLand obj1, SizeOfLand obj2)
{
    bool result = obj1.name == obj2.name ? true : false;
    return result;
}

SizeOfLand::~SizeOfLand()
{
    cout << "Hello Destructior " << name << endl;
}

SizeOfLand::SizeOfLand(float x, string Name)
{
    sqMetres = x;
    name = Name;
    count++;
}

void SizeOfLand::readSqMetres()
{
    cout << "Enter your Number: ";
    cin >> sqMetres;
}

float SizeOfLand::toSqInches()
{
    return 1550 * sqMetres;
}

void SizeOfLand::displayLandSize()
{
    cout << sqMetres << " Square Metres is " << toSqInches() << " Square Inches." << endl;
    printHello();
}

int main(int argc, char *argv[])
{
    cout << argc << endl;
    string name1 = argv[1];
    SizeOfLand fabric(2, name1);
    fabric.readSqMetres();
    fabric.displayLandSize();
    obj1.displayLandSize();

    if (equal(obj1, fabric))
    {
        cout << "name is equal" << endl;
    }
    else
    {
        cout << "name is not equal" << endl;
    }
    cout << fabric.count << endl;
    cout << obj1.count << endl;
    cout << obj2.count << endl;
    return 0;
}