#include "CangkulGame.hpp"

using namespace std;

CangkulGame::CangkulGame()
{
    mainDeck_.fillDeck();
    Coloring clr;
    for (int i = 0; i < 4; i++)
    {
        string nickname;
        try
        {
            cout << "Enter the nickname of Player " << i + 1 << ": ";

            clr.lgreen();
            cin >> nickname;
            clr.reset();

            if (cin.fail())
            {
                throw StringException();
            }

            CangkulPlayer playerElmt(nickname);
            this->listOfPlayers_.push_back(playerElmt);
        }
        catch (StringException &e)
        {
            e.what();
        }
    }
    for (int i = 0; i < 7; i++)
    {
        for (auto &p : listOfPlayers_)
        {
            p.addPlayerCard(mainDeck_.getFromMainDeck());
        }
    }
}

void CangkulGame::startGame()
{
    ColorCard tableCard;       // card opened for all player to see
    ColorCard highestCard;     // the highest card amongst the opened cards
    CangkulPlayer roundWinner; // the winner of the round
    bool found = false;
    tableCard = mainDeck_.getFromMainDeck();
    vector<ColorCard> thrownCards;
    bool checkEndGame = false;
    while (!checkEndGame)
    {
        cout << "Table card " << endl;
        thrownCards.push_back(tableCard);
        tableCard.printInfo();
        for (auto &p : listOfPlayers_)
        {
            cout << "Your cards : " << endl;
            p.printCards();
            ColorCard *selectedCard = p.getLargestCard(tableCard);
            if (selectedCard == nullptr)
            {
                cout << "Oops! too bad.. you can't open any card";
                p.takeCardFromDeck(mainDeck_, tableCard);
            }
            else
            {
                cout << p.getNickname() << "'s opened card " << endl;
                if (found && selectedCard->getValue() > highestCard.getValue())
                {
                    highestCard = *selectedCard;
                    roundWinner = p;
                }
                else if (!found)
                {
                    found = true;
                    highestCard = *selectedCard;
                    roundWinner = p;
                }
                selectedCard->printInfo();
                thrownCards.push_back(*selectedCard);
                p.removePlayerCard(*selectedCard);
                mainDeck_.randomizeCard(); // shuffle main deck every time
            }
        }
        if (found)
        {
            cout << roundWinner.getNickname() << " is the winner of the round." << endl;
            // if ga empty
            if (roundWinner.getDeck().empty())
            {
                cout << roundWinner.getNickname() << " has managed to throw all cards away" << endl;
                cout << "Congratulations for winning the game!" << endl;
                checkEndGame = true;
            }
            else
            {
                cout << roundWinner.getNickname() << " can choose the card to open" << endl;
                int choice = -1;
                while (choice == -1)
                {
                    try
                    {
                        choice = getCardChoice(roundWinner);
                        tableCard = roundWinner.getDeck()[choice - 1];
                        roundWinner.removePlayerCard(tableCard);
                    }
                    catch (IntegerException &e)
                    {
                        cout << e.what();
                    }
                    catch (OptionException &e)
                    {
                        cout << e.what();
                    }
                }
            }
        }
        else
        {
            if (mainDeck_.getDeck().empty())
            {
                for (auto &c : thrownCards)
                {
                    mainDeck_.addCard(c);
                }
                thrownCards.clear();
            }
            mainDeck_.randomizeCard();
            tableCard = mainDeck_.getFromMainDeck();
        }
    }
}

int CangkulGame::getCardChoice(CangkulPlayer roundWinner)
{
    for (int i = 0; i < roundWinner.getDeck().size(); i++)
    {
        cout << "[" << i + 1 << "]" << endl;
        roundWinner.getDeck()[i].printInfo();
        cout << endl;
    }
    int choice;
    cin >> choice;
    if (cin.fail())
    {
        throw IntegerException();
    }
    if (choice < 1 || choice > roundWinner.getDeck().size())
    {
        throw OptionException();
    }
    return choice;
}