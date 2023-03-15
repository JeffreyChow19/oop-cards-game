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
    int cnt = 1;
    map<int, ColorCard *> temp;
    bool found = false;
    for (auto &cards : deck)
    {
        if (cards.getColor() == tableCard.getColor())
        {
            cout << "[" << cnt << "]" << endl;
            temp[cnt] = &cards;
            cards.printInfo();
            cout << endl;
            cnt++;
            found = true;
        }
    }
    if (found)
    {
        temp[cnt] = nullptr;
        cout << "[" << cnt << "] Pass" << endl;
    }
    try
    {
        int n = getCardChoice(cnt);
        return temp[n];
    }
    catch (NumericException &e)
    {
        cout << e.what() << endl;
    }
    catch (OptionException &e)
    {
        cout << e.what() << endl;
    }
    return nullptr;
};

int CangkulPlayer::getCardChoice(int n)
{
    cout << "Choose card to open: " << endl;
    int opt;
    cin >> opt;
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

void CangkulPlayer::takeCardFromDeck(MainDeck &mainDeck, ColorCard tableCard)
{
    bool found = false;
    while (!found)
    {
        cout << "Press enter to take from deck" << endl;
        char a;
        cin >> a;
        ColorCard newCard = mainDeck.getFromMainDeck();
        if (newCard.getColor() == tableCard.getColor())
        {
            cout << "You found a suitable card!" << endl;
            newCard.printInfo();
            found = true;
        }
        else
        {
            cout << "You got a nonsuitable card :(" << endl;
            newCard.printInfo();
            addPlayerCard(newCard);
        }
    }
}