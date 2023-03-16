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
    cout << endl;

    int cnt = 1;
    map<int, int> temp;
    bool found = false;
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
        temp[cnt] = -1;
        cout << "[" << cnt << "] Pass" << endl;
        try
        {
            int n = getCardChoice(cnt);
            if (n != cnt)
            {
                return &deck[temp[n]];
            }
        }
        catch (NumericException &e)
        {
            cout << e.what() << endl;
        }
        catch (OptionException &e)
        {
            cout << e.what() << endl;
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
    return opt;
}
