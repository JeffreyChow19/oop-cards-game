#include "CangkulPlayer.hpp"

CangkulPlayer::CangkulPlayer(){};

/**
 * @brief Construct a new Player object
 *
 * @param nickname
 */
CangkulPlayer::CangkulPlayer(string nickname) : Player(nickname){};

/**
 * @brief Destroy the Player object
 *
 */
CangkulPlayer::~CangkulPlayer(){};

/**
 * @brief Print player's info including their nickname and points
 *
 */
void CangkulPlayer::print()
{
    cout << this->nickname_ << endl;
};

ColorCard *CangkulPlayer::getLargestCard(ColorCard &tableCard)
{
    Coloring clr;

    int cnt = 1;
    map<int, int> temp;
    bool found = false;

    clr.white(true);
    cout << "\nOptions : " << endl << endl;
    clr.reset();

    for (int i = 0; i < deck.size(); i++)
    {
        if (deck[i].getColor() == tableCard.getColor())
        {
            cout << "[" << cnt << "]" << endl;
            temp[cnt] = i;
            deck[i].printInfo();
            cout << endl;
            cnt++;
            found = true;
        }
    }
    if (found)
    {
        int n = -1;
        temp[cnt] = -1;
        cout << "[" << cnt << "] Pass" << endl;
        while (n == -1)
        {
            try
            {
                n = getCardChoice(cnt);
                if (n != cnt)
                {
                    return &deck[temp[n]];
                }
            }
            catch (NumericException &e)
            {
                clr.red();
                cout << e.what();
                clr.reset();

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            catch (OptionException &e)
            {
                clr.red();
                cout << e.what();
                clr.reset();

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }
    return nullptr;
};

int CangkulPlayer::getCardChoice(int n)
{
    Coloring clr;

    cout << "\nChoose card to open : ";
    int opt;

    clr.lgreen();
    cin >> opt;
    clr.reset();

    if (cin.fail())
    {
        throw NumericException();
    }
    if (opt < 1 || opt > n)
    {
        throw OptionException();
    }

    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');

    return opt;
}
