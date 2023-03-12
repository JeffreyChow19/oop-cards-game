#include "../ColorCard/ColorCard.hpp"

int main()
{
    ColorCard red1(Color::Red, 1);
    ColorCard blue2(Color::Blue, 2);
    ColorCard green3(Color::Green, 3);
    ColorCard yellow4(Color::Yellow, 4);
    cout << "Value of ";
    red1.printInfo();
    cout << " equals " << red1.getValue() << endl;
    cout << "Value of ";
    blue2.printInfo();
    cout << " equals " << blue2.getValue() << endl;
    cout << "Value of ";
    yellow4.printInfo();
    cout << " equals " << yellow4.getValue() << endl;
    cout << "Value of ";
    green3.printInfo();
    cout << " equals " << green3.getValue() << endl;
    cout << "Comparing red 1 and green 3" << endl;
    if (red1 < green3)
    {
        cout << "Red 1 < Green 3" << endl;
    }
    else
    {
        cout << "Red 1 >= Green 3" << endl;
    }
    cout << "Comparing red 1 and yellow 4" << endl;
    if (yellow4 > red1)
    {
        cout << "Red 1 < Yellow 4" << endl;
    }
    else
    {
        cout << "Red 1 >= Yellow 4" << endl;
    }
}