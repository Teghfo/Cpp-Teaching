
#include <stdio.h>
#include <iostream>

using namespace std;

class SizeOfLand
{
public:
    void readSqMetres();
    float toSqInches();
    void displayLandSize();

private:
    float sqMetres;
};

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
}

int main()
{
    SizeOfLand fabric;
    fabric.readSqMetres();
    fabric.displayLandSize();
    return 0;
}