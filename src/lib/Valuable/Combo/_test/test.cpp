#include "../Combo.hpp"
#include "../Flush/Flush.hpp"
#include "../FourOfAKind/FourOfAKind.hpp"
#include "../FullHouse/FullHouse.hpp"
#include "../HighCard/HighCard.hpp"
#include "../Pair/Pair.hpp"
#include "../Straight/Straight.hpp"
#include "../StraightFlush/StraightFlush.hpp"
#include "../ThreeOfAKind/ThreeOfAKind.hpp"
#include "../TwoPair/TwoPair.hpp"

#include <iostream>
#include <iomanip>

using namespace std;

void printInfo(Combo* comb) {
    cout << "=============" << endl;
    cout << comb->getComboName() << endl;
    comb->print();
    cout << setprecision(10) << comb->getValue() << endl << endl;
}

int main() {
    // HC < 2s < 2-2s < 3s < Straight < Flush < FH < 4s < SF 
    // hc
    Combo *hc_min = new HighCard(ColorCard(Color::Green, 1));
    Combo *hc_max = new HighCard(ColorCard(Color::Red, 13));

    printInfo(hc_min);
    printInfo(hc_max);


    delete hc_min;
    delete hc_max;

    // pair
    Combo *p_min = new Pair(make_pair(ColorCard(Color::Green, 1), ColorCard(Color::Blue, 1)));
    Combo *p_max = new Pair(make_pair(ColorCard(Color::Yellow, 13), ColorCard(Color::Red, 13)));

    printInfo(p_min);
    printInfo(p_max);

    delete p_min;
    delete p_max;


    // twopair
    Combo *tp_min = new TwoPair(
        Pair(make_pair(ColorCard(Color::Green, 1), ColorCard(Color::Blue, 1))),
        Pair(make_pair(ColorCard(Color::Green, 2), ColorCard(Color::Blue, 2)))
    );

    Combo *tp = new TwoPair(
        Pair(make_pair(ColorCard(Color::Yellow, 1), ColorCard(Color::Blue, 1))),
        Pair(make_pair(ColorCard(Color::Green, 2), ColorCard(Color::Blue, 2)))
    );

    Combo *tp_max = new TwoPair(
        Pair(make_pair(ColorCard(Color::Yellow, 13), ColorCard(Color::Red, 13))),
        Pair(make_pair(ColorCard(Color::Yellow, 12), ColorCard(Color::Red, 12)))
    );

    printInfo(tp_min);
    printInfo(tp);
    printInfo(tp_max);

    delete tp_min;
    delete tp;
    delete tp_max;

    // three
    Combo *t3_min = new ThreeOfAKind(
        vector<ColorCard>{
            ColorCard(Color::Green, 1),
            ColorCard(Color::Blue, 1),
            ColorCard(Color::Yellow, 1)
        }
    );
    Combo *t3 = new ThreeOfAKind(
        vector<ColorCard>{
            ColorCard(Color::Red, 1),
            ColorCard(Color::Blue, 1),
            ColorCard(Color::Yellow, 1)
        }
    );
    Combo *t3_max = new ThreeOfAKind(
        vector<ColorCard>{
            ColorCard(Color::Red, 13),
            ColorCard(Color::Blue, 13),
            ColorCard(Color::Yellow, 13)
        }
    );

    printInfo(t3_min);
    printInfo(t3);
    printInfo(t3_max);

    delete t3_min;
    delete t3;
    delete t3_max;

    //straight
    Combo *st_min = new Straight(
        vector<ColorCard>{
            ColorCard(Color::Blue, 1),
            ColorCard(Color::Green, 2),
            ColorCard(Color::Green, 3),
            ColorCard(Color::Green, 4),
            ColorCard(Color::Green, 5)
        }
    );
    Combo *st1 = new Straight(
        vector<ColorCard>{
            ColorCard(Color::Yellow, 1),
            ColorCard(Color::Green, 2),
            ColorCard(Color::Green, 3),
            ColorCard(Color::Green, 4),
            ColorCard(Color::Green, 5)
        }
    );
    Combo *st2 = new Straight(
        vector<ColorCard>{
            ColorCard(Color::Blue, 1),
            ColorCard(Color::Blue, 2),
            ColorCard(Color::Green, 3),
            ColorCard(Color::Green, 4),
            ColorCard(Color::Green, 5)
        }
    );
    Combo *st_max = new Straight(
        vector<ColorCard>{
            ColorCard(Color::Yellow, 9),
            ColorCard(Color::Red, 10),
            ColorCard(Color::Red, 11),
            ColorCard(Color::Red, 12),
            ColorCard(Color::Red, 13)
        }
    );

    printInfo(st_min);
    printInfo(st1);
    printInfo(st2);
    printInfo(st_max);

    delete st_min;
    delete st1;
    delete st2;
    delete st_max;


    //flush
    Combo *fmin = new Flush(
        vector<ColorCard>{
            ColorCard(Color::Green, 1),
            ColorCard(Color::Green, 2),
            ColorCard(Color::Green, 3),
            ColorCard(Color::Green, 4),
            ColorCard(Color::Green, 6)
        }
    );
    Combo *fmax = new Flush(
        vector<ColorCard>{
            ColorCard(Color::Red, 8),
            ColorCard(Color::Red, 9),
            ColorCard(Color::Red, 10),
            ColorCard(Color::Red, 11),
            ColorCard(Color::Red, 13)
        }
    );

    printInfo(fmin);
    printInfo(fmax);

    delete fmin;
    delete fmax;

    // fh
    Combo *fhmin = new FullHouse(
        vector<ColorCard>{
                ColorCard(Color::Green, 1),
                ColorCard(Color::Blue, 1),
                ColorCard(Color::Yellow, 1)
                }
        ,
        vector<ColorCard>{
                ColorCard(Color::Green, 2),
                ColorCard(Color::Blue, 2)
        }
    );
    Combo *fhmax = new FullHouse(
        vector<ColorCard>{
                ColorCard(Color::Red, 13),
                ColorCard(Color::Blue, 13),
                ColorCard(Color::Yellow, 13)
                }
        ,
        vector<ColorCard>{
                ColorCard(Color::Yellow, 12),
                ColorCard(Color::Red, 12)
        }
    );
    printInfo(fhmin);
    printInfo(fhmax);

    delete fhmin;
    delete fhmax;
    return 0;
}