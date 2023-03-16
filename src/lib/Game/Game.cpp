#include "Game.hpp"
#include "../Set/SetProcess.hpp"

Game::Game()
{
    // Coloring
    Coloring clr;

    // Splash Screen
    clr.pink(true);
    cout << "\n  __  __           _____ ____  _____   ____       _____          _   _ _______     __\n"
            " |  \\/  |   /\\    / ____|  _ \\|  __ \\ / __ \\     / ____|   /\\   | \\ | |  __ \\ \\   / /\n"
            " | \\  / |  /  \\  | (___ | |_) | |__) | |  | |   | |       /  \\  |  \\| | |  | \\ \\_/ / \n"
            " | |\\/| | / /\\ \\  \\___ \\|  _ <|  _  /| |  | |   | |      / /\\ \\ | . ` | |  | |\\   /  \n"
            " | |  | |/ ____ \\ ____) | |_) | | \\ \\| |__| |   | |____ / ____ \\| |\\  | |__| | | |   \n"
            " |_|  |_/_/    \\_\\_____/|____/|_|  \\_\\\\____/     \\_____/_/    \\_\\_| \\_|_____/  |_|   \n"
         << endl;
    clr.reset();

    // Input players' nickname
    for (int i = 0; i < 7; i++)
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

            CandyPlayer playerElmt(nickname);
            this->listOfPlayer.push_back(playerElmt);
        }
        catch (StringException &e)
        {
            e.what();
        }
    }
}

void Game::startGame()
{
    int firstPlayerIdx = 0;
    while (!checkEndGame())
    {
        SetProcess gameSet(listOfPlayer, firstPlayerIdx);
        gameSet.getCurrPlayerIdx();
        firstPlayerIdx = (gameSet.getCurrPlayerIdx() + 1) % listOfPlayer.size();
    }
}

bool Game::checkEndGame()
{
    // Coloring
    Coloring clr;

    for (auto &p : listOfPlayer)
    {
        if (p.getPoint() >= pow(2, 32))
        {
            sleep(2);
            clr.red(true);
            cout << "\n3..." << endl;
            sleep(1);
            cout << "2..." << endl;
            sleep(1);
            cout << "1..." << endl;
            sleep(1);

            clr.red(true);
            cout << endl;

            cout << "         )     )        (                        (                  (       )     ) (\n"     
                    "   (  ( /(  ( /( (      )\\ )   (      *   )      )\\ )   (      *   ))\\ ) ( /(  ( /( )\\ )\n"  
                    "   )\\ )\\()) )\\()))\\ )  (()/(   )\\   ` )  /(   ( (()/(   )\\   ` )  /(()/( )\\()) )\\()|()/(\n"  
                    " (((_|(_)\\ ((_)\\(()/(   /(_)|(((_)(  ( )(_))  )\\ /(_)|(((_)(  ( )(_))(_)|(_)\\ ((_)\\ /(_))\n";
            clr.pink(true);
            cout << " )\\___ ((_) _((_)/(_))_(_))  )\\ _ )\\(_(_())_ ((_|_))  )\\ _ )\\(_(_()|_))   ((_) _((_|_))\n"   
                    "((/ __/ _ \\| \\| (_)) __| _ \\ (_)_\\(_)_   _| | | | |   (_)_\\(_)_   _|_ _| / _ \\| \\| / __|\n"  
                    " | (_| (_) | .` | | (_ |   /  / _ \\   | | | |_| | |__  / _ \\   | |  | | | (_) | .` \\__ \\ \n"  
                    "  \\___\\___/|_|\\_|  \\___|_|_\\ /_/ \\_\\  |_|  \\___/|____|/_/ \\_\\  |_| |___| \\___/|_|\\_|___/  \n" << endl; 

            clr.green(true);
            cout << "                                        " << p.getNickname() << endl << endl;

            clr.yellow(true);
            cout << "            LEADERBOARD" << endl;

            sort(listOfPlayer.begin(), listOfPlayer.end(), [](const CandyPlayer& a, const CandyPlayer& b) {return a.getPoint() > b.getPoint();});
            
            clr.blue(true);
            cout << left << setw(20) << "Nickname" << setw(10) << "Points" << endl;
            cout << "----------------------------------------" << endl;
            
            clr.cyan(true);
            for (const CandyPlayer& player : listOfPlayer) {
                cout << left << setw(20) << player.getNickname() << setw(10) << player.getPoint() << std::endl;
            }

            cout << endl;

            clr.reset();

            return true;
        }
    }
    return false;
}

Game::~Game()
{
    this->listOfPlayer.clear();
}