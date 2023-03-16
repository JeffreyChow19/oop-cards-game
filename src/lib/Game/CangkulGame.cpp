#include "CangkulGame.hpp"

using namespace std;

CangkulGame::CangkulGame()
{
    // Coloring
    Coloring clr;

    // Splash Screen
    clr.pink(true);
    cout << "\n  __  __           _____ ____  _____   ____       _____          _   _  _____ _  ___    _ _      \n"
            " |  \\/  |   /\\    / ____|  _ \\|  __ \\ / __ \\     / ____|   /\\   | \\ | |/ ____| |/ / |  | | |     \n"
            " | \\  / |  /  \\  | (___ | |_) | |__) | |  | |   | |       /  \\  |  \\| | |  __| ' /| |  | | |     \n"
            " | |\\/| | / /\\ \\  \\___ \\|  _ <|  _  /| |  | |   | |      / /\\ \\ | . ` | | |_ |  < | |  | | |     \n"
            " | |  | |/ ____ \\ ____) | |_) | | \\ \\| |__| |   | |____ / ____ \\| |\\  | |__| | . \\| |__| | |____ \n"
            " |_|  |_/_/    \\_\\_____/|____/|_|  \\_\\\\____/     \\_____/_/    \\_\\_| \\_|\\_____|_|\\_\\\\____/|______|\n"
         << endl;
    clr.reset();

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

    mainDeck_.fillDeck();

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
    ColorCard tableCard;   // card opened for all player to see
    ColorCard highestCard; // the highest card amongst the opened cards
    int roundWinnerIdx;    // the winner of the round

    bool found = false;

    tableCard = mainDeck_.getFromMainDeck();

    bool checkEndGame = false;

    int currPlayerIdx = 0;

    while (!checkEndGame)
    {
        int playerMoved = 0;
        cout << "Table card " << endl;
        thrownCards_.push_back(tableCard);
        tableCard.printInfo();
        while (playerMoved < listOfPlayers_.size())
        {
            CangkulPlayer &currPlayer = listOfPlayers_[currPlayerIdx];
            cout << endl
                 << "It's " << currPlayer.getNickname() << "'s turn!" << endl;
            sleep(1);
            cout << "Your cards : " << endl;
            currPlayer.printCards();
            sleep(1);
            ColorCard *selectedCard = currPlayer.getLargestCard(tableCard);
            if (selectedCard == nullptr)
            {
                cout << "Oops! too bad.. you can't open any card" << endl;
                selectedCard = takeCardFromDeck(currPlayer, tableCard);
            }
            else
            {
                cout << currPlayer.getNickname() << "'s opened card " << endl;
                selectedCard->printInfo();
                cout << endl;
                if (found && selectedCard->getValue() > highestCard.getValue())
                {
                    highestCard = *selectedCard;
                    roundWinnerIdx = currPlayerIdx;
                }
                else if (!found)
                {
                    found = true;
                    highestCard = *selectedCard;
                    roundWinnerIdx = currPlayerIdx;
                }
                thrownCards_.push_back(*selectedCard);
                currPlayer.removePlayerCard(*selectedCard);
            }
            cout << "End of " << currPlayer.getNickname() << "'s turn" << endl;

            sleep(2);

            currPlayerIdx = (currPlayerIdx + 1) % listOfPlayers_.size();
            playerMoved++;
        }

        CangkulPlayer &roundWinner = listOfPlayers_[roundWinnerIdx];
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
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    catch (OptionException &e)
                    {
                        cout << e.what();
                    }
                }
            }
            currPlayerIdx = (roundWinnerIdx + 1) % listOfPlayers_.size();
        }
    }
}

int CangkulGame::getCardChoice(CangkulPlayer &roundWinner)
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

ColorCard *CangkulGame::takeCardFromDeck(CangkulPlayer &p, ColorCard tableCard)
{
    ColorCard *selectedCard;
    bool found = false;
    while (!found)
    {
        if (mainDeck_.getDeck().empty())
        {
            for (auto &c : thrownCards_)
            {
                mainDeck_.addCard(c);
            }
            thrownCards_.clear();
        }
        cout << "Press 'c' to take from deck" << endl;
        char a;
        cin >> a;
        ColorCard newCard = mainDeck_.getFromMainDeck();
        if (newCard.getColor() == tableCard.getColor())
        {
            cout << "You found a suitable card!" << endl;
            newCard.printInfo();
            p.addPlayerCard(newCard);
            selectedCard = &p.getDeck().back();
            found = true;
        }
        else
        {
            cout << "You got a nonsuitable card :(" << endl;
            newCard.printInfo();
            p.addPlayerCard(newCard);
        }
    }
    return selectedCard;
}