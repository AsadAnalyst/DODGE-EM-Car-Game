
/***********************************
  All Libraries Used in Our Game.
  **********************************/
#include <iostream>
//#include <conio.h>
#include <windows.h>
#include <fstream>
#include <string>
#include <stdlib.h> // only for Exit 
using namespace std;
/***********************
 Globale variable
 ***********************/
char a[23][23];              // Array Used For All.
int score = 0;               // Score in the game.
int carx = 1, cary = 1;      // for storing car index
int a_carx = 1, a_cary = 21; // for storing car index
int row = 1;                 // road in game 1 3 5 7
static int Life = 3;         // life in the Game.

/*****************************
 All Prototypes oF Functions.
 *****************************/
void Loading_Page();
void play_Level_1();
void play_Level_2();
void play_Level_3();
void Manu();
void ManuP();
void road();
void road3();
void food();
void enter();
void run();
void clear_Side();
void end_game();
void pause();

/***********************
  Main Function.
 ***********************/

int main()
{
    Loading_Page(); // it's Load the Game.
    return 0;
}

/***************************************
 Display Loading Page with our Names.
 ***************************************/

void Loading_Page()
{
   // PlaySound(TEXT("asad2.wav"), NULL, SND_ASYNC);       // play Music in Game.
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // it's For Colour only.
    SetConsoleTextAttribute(hConsole, 10);             // Blue Colour.
    cout << endl
        << "\t\t\t* WELCOME TO DODGE EM……* " << endl;
    cout << "\n\n\n";
    cout << endl
        << "\t\t\t* Our Team...* " << endl;
    cout << endl
        << "\t\t\t*1--> Syed Asad Raza. " << endl;
    cout << endl
        << "\t\t\t*2--> Sharaz Shabh. " << endl;
    cout << endl
        << "\t\t\t*3--> Sami Asif. " << endl;
    cout << "\n\n\n";
    Sleep(1000);
    cout << "\t\t\t\tLOADING";
    for (int i = 0; i < 20; i++) // Display dots (.)
    {
        Sleep(100); // Slow Execution Time.
        cout << ".";
    }

    SetConsoleTextAttribute(hConsole, 15); // White Colour
    system("CLS");  // Clear Screan.
    Manu();
}

/********************************
File Handling For Score Saving.
********************************/

void file_ScoreP()
{
    ifstream in;
    string fscore;
    string key;
    bool flag = true;
    in.open("highscore.txt");
    if (in.is_open())
    {
        in >> fscore;
        cout << "\n\t\t***************************************";
        cout << "\n\t\t*\n\t\t*\n\t\t*     High Score : " << fscore << endl;
        cout << "\t\t*";
        cout << "\n ***************************************";
        in.close();
        cout << "\n\t Enter Any Key to Continue : ";
        cin >> key;
        system("CLS"); // Clear Screan.
        ManuP();
}
    else
    {
        cout << "File Not Found !\n";
        Sleep(2000);   // Slow Execution Time.
        system("CLS"); // Clear Screan.
    }
    in.close();
}

/***************************************
 File Handling For Score Saving.
 ***************************************/

void file_Score()
{
    ifstream in;
    string fscore;
    string key;
    in.open("highscore.txt");
    if (in.is_open())
    {
        in >> fscore;
        cout << "\n\t\t***************************************";
        cout << "\n\t\t*\n\t\t*\n\t\t*     High Score : " << fscore << endl;
        cout << "\t\t*";
        cout << "\n ***************************************";
        in.close();
        cout << "\n\t Enter Any Key to Continue : ";
        cin >> key;
        system("CLS"); // Clear Screan.
        Manu();
    }
    else
    {
        cout << "File Not Found !\n";
        Sleep(2000);   // Slow Execution Time.
        system("CLS"); // Clear Screan.
    }
    in.close();
}

/***************************************
 Display Menu Before Play Game.
 ***************************************/

void Manu()
{
   
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 14);  // Yellow Color
    string part;
    cout << "\n\n";
    cout << "  /_____________________________________________/\n\n";
    cout << "\t 1--> Start a New Game \n";
    cout << "\t 2--> See high Scores \n";
    cout << "\t 3--> Help \n";
    cout << "\t 4--> Exit \n";
    cout << "\t Enter your Choice : ";
    cin >> part;
    cout << "  /_____________________________________________/ \n\n";

    if (part == "1")
    {
        Life = 3;
        system("CLS"); // Clear Screan.
        play_Level_1();
    }
    else if (part == "2")
    {
        system("CLS"); // Clear Screan.
        SetConsoleTextAttribute(hConsole, 10); // Blue Color
        file_Score();
    }
    else if (part == "3")
    {
        system("CLS"); // Clear Screan.
        SetConsoleTextAttribute(hConsole, 11);  //  dark blue
        string again;
        cout << "\n\n";
        cout << "\t1.--> Player Vs. Opponent:\n";
        cout << "\t2.--> The game is played in a racing area where the player drives his Red colored car:\n";
        cout << "\t3.--> To pick the maximum Foods :\n";
        cout << "\t4.--> Avoiding a head-on collision with the Yellow opponent car(s) run by the computer:\n";
        cout << "\t5.--> The player car is controlled by the keyboard - arrow keys to turn:\n";
        SetConsoleTextAttribute(hConsole, 14);
        cout << "\n\n\n\t\t Some Important keys...";
        cout << "\n\n\t\t Arrow Up --> Up.";
        cout << "\n\n\t\t Arrow LEFT --> Left.";
        cout << "\n\n\t\t Arrow RIGHT --> Right.";
        cout << "\n\n\t\t Arrow DOWN --> Down.";
        cout << "\n\n\t\t p --> Puase.";
        cout << "\n\n\t\t ESCAPE --> Puase.";
        SetConsoleTextAttribute(hConsole, 8);
        cout << "\n\t Enter any key For Continue : ";
        cin >> again;
        system("CLS"); // Clear Screan.
        Manu();
    }
    else if (part == "4")
    {
        system("CLS"); // Clear Screan.
        SetConsoleTextAttribute(hConsole, 12); // Red Color
        cout << "\n\n\t Thanks For Playing...\n\n";
        SetConsoleTextAttribute(hConsole, 15);
        exit(1);
    }
    else
    {
        system("CLS"); // Clear Screan.
        SetConsoleTextAttribute(hConsole, 13);
        cout << " Enter A Correct Choice : ";
        Manu();
    }
}

/***************************************
 Display Manu After Enter Puase (p) Game.
 ***************************************/

void ManuP()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 14);
    string part;
    cout << "\n\n";
    cout << "  /_____________________________________________/\n\n";
    cout << "\t 1--> Start a New Game \n";
    cout << "\t 2--> Load Game \n";
    cout << "\t 3--> See high Scores \n";
    cout << "\t 4--> Help \n";
    cout << "\t 5--> Exit \n";
    cout << "\t Enter your Choice : ";
    cin >> part;
    cout << "  /_____________________________________________/ \n\n";
    if (part == "1")
    {
        SetConsoleTextAttribute(hConsole, 15);
        system("CLS"); // Clear Screan.
        carx = 1;
        carx = 1;
        a_carx = 1;
        a_cary = 21;
        row = 1;
        //row2 = 21;
        Life = 3;
        score = 0;
        play_Level_1();


    }
    else if (part == "2")
    {
        system("CLS"); // Clear Screan.
        
    }
    else if (part == "3")
    {
        system("CLS"); // Clear Screan.
        SetConsoleTextAttribute(hConsole, 10);
        file_ScoreP();
    }
    else if (part == "4")
    {
        system("CLS"); // Clear Screan.
        SetConsoleTextAttribute(hConsole, 11);
        string again;
        cout << "\n\n";
        cout << "\t1.--> Player Vs. Opponent:\n";
        cout << "\t2.--> The game is played in a racing area where the player drives his Red colored car:\n";
        cout << "\t3.--> To pick the maximum Foods :\n";
        cout << "\t4.--> Avoiding a head-on collision with the Yellow opponent car(s) run by the computer:\n";
        cout << "\t5.--> The player car is controlled by the keyboard - arrow keys to turn:\n";
        SetConsoleTextAttribute(hConsole, 14);
        cout << "\n\n\n\t\t Some Important keys...";
        cout << "\n\n\t\t Arrow Up --> Up.";
        cout << "\n\n\t\t Arrow LEFT --> Left.";
        cout << "\n\n\t\t Arrow RIGHT --> Right.";
        cout << "\n\n\t\t Arrow DOWN --> Down.";
        cout << "\n\n\t\t p --> Puase.";
        cout << "\n\n\t\t ESCAPE --> Puase.";
        SetConsoleTextAttribute(hConsole, 8);
        cout << "\n\t Enter any key For Continue : ";
        cin >> again;
        system("CLS"); // Clear Screan.
        ManuP();
    }
    else if (part == "5")
    {
        system("CLS"); // Clear Screan.
        SetConsoleTextAttribute(hConsole, 12);
        cout << "\n\n\t Thanks For Playing...\n\n";
        SetConsoleTextAttribute(hConsole, 15);
        exit(1);
    }
    else
    {
        system("CLS"); // Clear Screan.
        SetConsoleTextAttribute(hConsole, 13);
        cout << " Enter A Correct Choice : ";
        ManuP();
    }
}

/***********************
 Display Road Or Board.
 ***********************/

void road()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 14);
    for (int l = 0; l < 10; l += 2)
    {
        for (int i = l; i < 23 - l; i++)
        {
            a[l][i] = '_';
            a[22 - l][i] = '_';
            a[i][l] = '|';
            a[i][22 - l] = '|';
            if (i == l && i < 9 && l < 9)
            {
                a[l][i] = '_';
            }
        }
        a[0][0] = '_';
    }
}

/***********************
 Display Road After 2nd Level.
 ***********************/
void road3()//road for 3 level
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 14);
    for (int l = 0; l < 10; l += 2)
    {
        for (int i = l; i < 23 - l; i++)
        {
            a[l][i] = '_';
            a[22 - l][i] = '_';
            a[i][l] = '{';
            a[i][22 - l] = '}';
            if (i == l && i < 9 && l < 9)
            {
                a[l][i] = '_';
            }
        }
        a[0][0] = '_';
    }
}
/************************************
 Spaces Between the Roads in Board.
************************************/
void clear_Side()
{
    for (int i = 0; i < 23; i++)
    {
        for (int w = 10; w < 13; w++)
        {
            a[w][i] = ' ';
            a[i][w] = ' ';
        }
    }
}

/*********************
 Store Food in Array.
 *********************/

 
/***************************************
  Replacing After Player Car Eat Food.
 ***************************************/

void eat_Food(int carx, int cary)
{
    a[carx][cary] = ' ';
}

/****************************************************
  When Player Enter Key Of Game Call enter Function.
 ****************************************************/
void enter()
{
    if ((carx > 9 && carx < 13 && cary < 9))
    {
        if (GetAsyncKeyState(VK_LEFT))
        {
            if (row != 1)
            {
                cary -= 2;  //subtract 2 form row.;
                row -= 2;
            }
            while((GetAsyncKeyState(VK_LEFT))) {}
        }
        else if (GetAsyncKeyState(VK_RIGHT))
        {
            if (row != 7)
            {
                cary += 2;
                row += 2;
            }
            while ((GetAsyncKeyState(VK_RIGHT))) {}
        }
    }
    else if (carx > 13 && carx < 22 && cary > 9 && cary < 13)
    {
        if (GetAsyncKeyState(VK_UP))
        {
            if (row != 7)
            {
                row += 2;
                carx -= 2;
            }
            while ((GetAsyncKeyState(VK_UP))) {}
        }
        else if (GetAsyncKeyState(VK_DOWN))
        {
            if (row != 1)
            {
                row -= 2;
                carx += 2;
            }
            while ((GetAsyncKeyState(VK_DOWN))) {}
        }
    }
    else if ((carx > 9 && carx < 13 && cary > 14 && cary < 22))
    {
        if (GetAsyncKeyState(VK_LEFT))
        {
            if (row != 7)
            {
                cary -= 2;
                row += 2;
            }
            while ((GetAsyncKeyState(VK_LEFT))) {}
        }

        else if (GetAsyncKeyState(VK_RIGHT))
        {
            if (row != 1)
            {
                cary += 2;
                row -= 2;
            }
            while ((GetAsyncKeyState(VK_RIGHT))) {}
        }
    }
    else if (carx < 8 && cary > 9 && cary < 13)
    {
        if (GetAsyncKeyState(VK_UP))
        {
            if (row != 1)
            {
                row -= 2;
                carx -= 2;
            }
            while ((GetAsyncKeyState(VK_UP))) {}
        }
        else if (GetAsyncKeyState(VK_DOWN))
        {
            if (row != 7)
            {
                row += 2;
                carx += 2;
            }
            while ((GetAsyncKeyState(VK_DOWN))) {}
        }
    }
}

/***********************************************
 Pause Game When Enter Escape Button Function.
 ***********************************************/

void pause()
{
    //if (_kbhit())
    //{
    //    switch (_getch())
    //    {
    //        case 'p':
    //        {
    //            system("ClS"); // Clear Screan.
    //            ManuP();
    //            break;
    //        }
    //        case 'P':
    //        {
    //            system("ClS"); // Clear Screan.
    //            ManuP();
    //            break;
    //        }
    //    }
    //}
    if (GetAsyncKeyState(VK_ESCAPE))
    {
        system("ClS"); // Clear Screan.
        ManuP();
    }
}

/*************************
 Both Car Run Function.
**************************/

void run()
{
    /*************************
     This Logic For Auto Car.
    **************************/

    /*
    a_carx as a Colunm.
    a_cary as a Row.
    */

    if (a_carx < 21 && a_cary == 21) // 1st down
    {
        a_carx++;
    }
    else if (a_carx == 21 && a_cary > 1) // 2nd forword
    {
        a_cary--;
    }
    else if (a_cary == 1 && a_carx > 1) // 3rd up
    {
        a_carx--;
    }
    else if (a_carx == 1 && a_cary < 10) // 4th back
    {
        a_cary++;
    }
    else if (a_cary == 10 && a_carx == 1) // part b start_upper
    {
        a_carx += 2;
    }
    else if (a_carx == 3 && a_cary < 19) // 2nd forword and so on...
    {
        a_cary++;
    }
    else if (a_cary == 19 && a_carx < 19)
    {
        a_carx++;
    }
    else if (a_carx == 19 && a_cary > 3)
    {
        a_cary--;
    }
    else if (a_cary == 3 && a_carx > 12)
    {
        a_carx--;
    }
    else if (a_carx == 12 && a_cary == 3)
    {
        a_cary += 2;
    }
    else if (a_cary == 5 && a_carx > 5)
    {
        a_carx--;
    }
    else if (a_cary < 17 && a_carx == 5)
    {
        a_cary++;
    }
    else if (a_cary == 17 && a_carx < 17)
    {
        a_carx++;
    }
    else if (a_cary > 12 && a_carx == 17)
    {
        a_cary--;
    }
    else if (a_cary == 12 && a_carx == 17)
    {
        a_carx -= 2;
    }
    else if (a_cary > 7 && a_carx == 15)
    {
        a_cary--;
    }
    else if (a_cary == 7 && a_carx > 7)
    {
        a_carx--;
    }
    else if (a_cary < 11 && a_carx == 7)
    {
        a_cary++;
    }
    else if (a_cary == 11 && a_carx > 1)
    {
        a_carx -= 6;
        a_carx = 1;
        a_cary = 21;
    }

    /****************************
     This Logic For Player Car.
     ****************************/

     /*
        carx as a Row.
        cary as a Colunm.
     */

    if (carx == row && cary > row) // Run Down only
    {

        cary--;
    }
    else if (cary == row && carx < (22 - row)) // Run Forword only
    {
        carx++;
    }
    else if (carx == (22 - row) && cary < (22 - row)) // Run Upword only
    {
        cary++;
    }
    else if (cary == (22 - row) && carx > row) // Run Backwprd only
    {
        carx--;
    }
}

/***************************
  1st Level Srart Function.
****************************/

void play_Level_1()
{
    //PlaySound(TEXT("asad2.wav"), NULL, SND_ASYNC); // play Music in Game.
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int x=0, y=0, j=0, k=0;
    char character;
    for (int i = 0; i < 23; i++)
    {
        for (int j = 0; j < 23; j++)
        {
            a[i][j] = '.';
            a[9][9] = ' ';
            a[13][13] = ' ';
            a[13][9] = ' ';
            a[9][13] = ' ';
        }
    }
    while (true)
    {
        
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
        cout << "\n\n\n";
        Sleep(50); // Slow Execution Time.
        road();
        clear_Side();
        x = carx;
        y = cary;
        j = a_carx;
        k = a_cary;
        a[carx][cary] = '@'; // Player Car
        a[a_carx][a_cary] = '#'; // Auto Car

        // multiple for getting input correctly.
        pause();
        enter();
        enter();
        enter();
        enter();
        run();
        character = a[a_carx][a_cary];
        cout << " \n\t\t\t Level ...1\n\n\n";
        if (a[carx][cary] == '.')
        {
            int storeScore;
            score++;
            SetConsoleTextAttribute(hConsole, 10);
            cout << "\t Score. | " << score << " |";
            SetConsoleTextAttribute(hConsole, 10);
            cout << "\t\t\t\t Life. | " << Life << " |";
            SetConsoleTextAttribute(hConsole, 15);
            ofstream out;
            ifstream in;
            in.open("highscore.txt");
            in >> storeScore;
            in.close();
            out.open("highscore.txt");
            if (storeScore < score)
            {
                out << score;
            }
            else
            {
                out << storeScore;
            }
            out.close();
            a[carx][cary] = ' ';
        }
        if (score == 166)
        {
            system("CLS"); // Clear Screan.
            cout << "\n\n\n\n\t\t\t\t Level...2\n\n\t\t\t\tYou're Lagend Player :";
            cout << "\t\t\t\t\tLOADING";
            for (int i = 0; i < 20; i++)
            {
                Sleep(100); // Slow Execution Time.
                cout << ".";
            }
            system("CLS"); // Clear Screan.
            play_Level_2();
        }
       // a[carx][cary] = ' ';
        cout << "    ";
        cout << endl;
        
        /*********************************
          Print All Road & Cars in Game
        **********************************/

        for (int i = 0; i < 23; i++)
        {
            for (int j = 0; j < 23; j++)
            {
                if (a[i][j] == '@')
                {
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << ' ' << a[i][j] << ' ';
                    SetConsoleTextAttribute(hConsole, 15);
                }
                else if (a[i][j] == '#')
                {
                    SetConsoleTextAttribute(hConsole, 14);
                    cout << ' ' << a[i][j] << ' ';
                    SetConsoleTextAttribute(hConsole, 15);
                }
                else if (a[i][j] == '|' || a[i][j] == '_')
                {
                    SetConsoleTextAttribute(hConsole, 6);
                    cout << ' ' << a[i][j] << ' ';
                    SetConsoleTextAttribute(hConsole, 15);
                }
                else
                {
                    cout << ' ' << a[i][j] << ' ';
                }
                
            }
            cout << endl;
        }

        eat_Food(x, y);
        a[j][k] = character;
        if (x == j && y-1 == k || carx == a_carx && cary == a_cary)
        {
            end_game();
        }
        
    }
}

/***************************
  2nd Level Srart Function.
****************************/

void play_Level_2()
{
   // PlaySound(TEXT("asad2.wav"), NULL, SND_ASYNC); // play Music in Game.
    system("CLS");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int x, y, j, k;
    char character;
    for (int i = 0; i < 23; i++)
    {
        for (int j = 0; j < 23; j++)
        {
            a[i][j] = '.';
        }
    }
    while (true)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
        cout << "\n\n\n";
        road();
        clear_Side();
        x = carx;
        y = cary;
        j = a_carx;
        k = a_cary;

        a[carx][cary] = '@'; // Player Car.
        a[a_carx][a_cary] = '#'; // Auto Car.

        // Multiple Time Car for getting input correctly.
        pause();
        enter();
        enter();
        enter();
        enter();
        run();
        cout << " \n\t\t\t Level ...2\n\n\n";
        character = a[a_carx][a_cary];
        if (a[carx][cary] == '.')
        {
            int storeScore;
            score++;
            SetConsoleTextAttribute(hConsole, 10);
            cout << "\t Score. | " << score << " |";
            SetConsoleTextAttribute(hConsole, 10);
            cout << "\t\t\t\t Life. | " << Life << " |";
            SetConsoleTextAttribute(hConsole, 15);
            ofstream out;
            ifstream in;
            in.open("highscore.txt");
            in >> storeScore;
            out.close();
            out.open("highscore.txt");
            if (storeScore < score)
            {
                out << score << endl;
            }
            else
            {
                out << storeScore;
            }
            out.close();
        }
        if (score == 326) // When Total Food eaten by Player Car.
        {
            system("CLS"); // Clear Screan.
            cout << "\n\n\n\n\t\t\t\t 3rd Level... \n\n\t\t\t\tYou're Lagend Player :";
            cout << "\t\t\t\t\tLOADING";
            for (int i = 0; i < 20; i++)
            {
                Sleep(100);
                cout << ".";
            }
            system("CLS"); // Clear Screan.
            play_Level_3();
        }
        a[carx][cary] = ' ';
        cout << "    ";
        cout << endl;

        /*********************************
          Print All Road & Cars in Game
        **********************************/

        for (int i = 0; i < 23; i++)
        {
            for (int j = 0; j < 23; j++)
            {
                if (a[i][j] == '@')
                {
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << ' ' << a[i][j] << ' ';
                    SetConsoleTextAttribute(hConsole, 15);
                }
                else if (a[i][j] == '#')
                {
                    SetConsoleTextAttribute(hConsole, 14);
                    cout << ' ' << a[i][j] << ' ';
                    SetConsoleTextAttribute(hConsole, 15);
                }
                else if (a[i][j] == '|' || a[i][j] == '_')
                {
                    SetConsoleTextAttribute(hConsole, 6);
                    cout << ' ' << a[i][j] << ' ';
                    SetConsoleTextAttribute(hConsole, 15);
                }
                else
                {
                    cout << ' ' << a[i][j] << ' ';
                }

            }
            cout << endl;
        }
        eat_Food(x, y);
        a[j][k] = character;
        if (x == j && y - 1 == k || carx == a_carx && cary == a_cary)
        {
            end_game();
        }
    }
}

/***************************
  3rd Level Srart Function.
****************************/

void play_Level_3()
{
    //PlaySound(TEXT("asad2.wav"), NULL, SND_ASYNC); // play Music in Game.
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int x = 0, y = 0, j = 0, k = 0;
    char character;
    for (int i = 0; i < 23; i++)
    {
        for (int j = 0; j < 23; j++)
        {
            a[i][j] = '.';
            a[9][9] = ' ';
            a[13][13] = ' ';
            a[13][9] = ' ';
            a[9][13] = ' ';
        }
    }
    while (true)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
        cout << "\n\n\n";
        road3();
        clear_Side();
        x = carx;
        y = cary;
        j = a_carx;
        k = a_cary;
        a[carx][cary] = '@'; // Player Car
        

        // multiple for getting input correctly.
        pause();
        enter();
        enter();
        enter();
        enter();
        run();
        cout << " \n\t\t\t Bat House      Level ...3\n\n\n";
        character = a[a_carx][a_cary];
        if (a[carx][cary] == '.')
        {
            int storeScore;
            score++;
            SetConsoleTextAttribute(hConsole, 10);
            cout << "\t Score. | " << score << " |";
            SetConsoleTextAttribute(hConsole, 10);
            cout << "\t\t\t\t Life. | " << Life << " |";
            SetConsoleTextAttribute(hConsole, 15);
            ofstream out;
            ifstream in;
            in.open("highscore.txt");
            in >> storeScore;
            in.close();
            out.open("highscore.txt");
            if (storeScore < score)
            {
                out << score;
            }
            else
            {
                out << storeScore;
            }
            out.close();
            a[carx][cary] = ' ';
        }
        a[a_carx][a_cary] = '#'; // Auto Car
        if (score == 456)
        {
            system("CLS"); // Clear Screan.
            cout << "\n\n\n\n\t\t\t\t Congructalation \n\n\t\t\t\tYou Win...! ";
            Sleep(3000);
            cout << "\t\t\t\t\tLOADING";
            for (int i = 0; i < 20; i++)
            {
                Sleep(100); // Slow Execution Time.
                cout << ".";
            }
            system("CLS"); // Clear Screan.
            Manu();
        }
        // a[carx][cary] = ' ';
        cout << "    ";
        cout << endl;

        /*********************************
          Print All Road & Cars in Game 
        **********************************/

        for (int i = 0; i < 23; i++)
        {
            for (int j = 0; j < 23; j++)
            {
                if (a[i][j] == '@')
                {
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << ' ' << a[i][j] << ' ';
                    SetConsoleTextAttribute(hConsole, 15);
                }
                else if (a[i][j] == '#')
                {
                    SetConsoleTextAttribute(hConsole, 14);
                    cout << ' ' << a[i][j] << ' ';
                    SetConsoleTextAttribute(hConsole, 15);
                }
                else if (a[i][j] == '.')
                {
                    SetConsoleTextAttribute(hConsole, 6);
                    cout << ' ' << a[i][j] << ' ';
                    SetConsoleTextAttribute(hConsole, 15);
                }
                else if (a[i][j] == '{'|| a[i][j] == '}')
                {
                    SetConsoleTextAttribute(hConsole, 3);
                    cout << ' ' << a[i][j] << ' ';
                    SetConsoleTextAttribute(hConsole, 15);
                }
                else
                {
                    cout << ' ' << a[i][j] << ' ';
                }

            }
            cout << endl;
        }
        eat_Food(x, y);
        a[j][k] = character;
        if (x == j && y - 1 == k || carx == a_carx && cary == a_cary)
        {
            end_game();
        }

    }
}

/*********************************************
  End OF Game,OR Player Car Hit Oppenent Car.
 *********************************************/

void end_game()
{
    //PlaySound(TEXT("crush.wav"), NULL, SND_SYNC); // Accident in Game.
    //PlaySound(TEXT("asad2.wav"), NULL, SND_ASYNC); // play Music in Game.
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    Life--;
    /*if (Life == 0)
    {
        carx = 1;
        cary = 1;
        a_carx = 1;
        a_cary = 21;
    }*/
    carx = 1;
    cary = 1;
    a_carx = 1;
    a_cary = 21;
    row = 1;
    //row2 = 1;
    if (Life >= 1)
    {
        score = 0;
        system("CLS"); // Clear Screan.
        SetConsoleTextAttribute(hConsole, 12);
        cout << "\n\n\n\n\n\t\t Try Again \n\n\t\t You Can Do it \n\n\n";
        SetConsoleTextAttribute(hConsole, 15);
        Sleep(2000); // Slow Execution Time.
        system("CLS"); // Clear Screan.
        play_Level_1();
    }
    else
    {
        system("CLS"); // Clear Screan.
        SetConsoleTextAttribute(hConsole, 12);
        cout << "\n\n\n\n\t\t Ooo...!\n\n\t\t You Lose...!\n\n\n";
        SetConsoleTextAttribute(hConsole, 15);
        Sleep(2000); // Slow Execution Time.
        score = 0;  // Reintialization of Score After Ending.
        system("CLS"); // Clear Screan.
        Manu();
    }
}