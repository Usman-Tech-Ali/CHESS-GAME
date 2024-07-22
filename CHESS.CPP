#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <fstream>
#include <climits>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;
void start();
void K_Moves();
void Q_Moves();
void B_Moves();
void R_Moves();
void N_Moves();
void emptyGrid();
void Grid(string (*grid)[8]);
int main()
{
    start();
    return 0;
}
void start()
{
    int start, moves;
    cout << "\n\n"
         << setw(80) << "WELCOME TO USMAN'S CHESS GAME\n\n";
    while (start != 3)
    {
        cout << "------------------------\n";
        cout << "|1.Possible Piece moves|\n";
        cout << "|2.Start 2 player Game |\n";
        cout << "|3.Exit                |\n";
        cout << "------------------------\n";
        cout << "Select from above options : ";
        cin >> start;
        if (start == 1)
        {
            while (moves != 6)
            {
                cout << "----------\n";
                cout << "|1.King  |\n";
                cout << "|2.Queen |\n";
                cout << "|3.Bishop|\n";
                cout << "|4.Rock  |\n";
                cout << "|5.Knight|\n";
                cout << "|6.Exit  |\n";
                cout << "----------\n";
                cout << "Select from above options : ";
                cin >> moves;
                if (moves == 1)
                {
                    emptyGrid();
                    K_Moves();
                }
                else if (moves == 2)
                {
                    emptyGrid();
                    Q_Moves();
                }
                else if (moves == 3)
                {
                    emptyGrid();
                    B_Moves();
                }
                else if (moves == 4)
                {
                    emptyGrid();
                    R_Moves();
                }
                else if (moves == 5)
                {
                    emptyGrid();
                    N_Moves();
                }
            }
        }
        else if (start == 2)
        {
            int i, j, r1, c1, r2, c2, r3, c3, choice, b = 1, R1, R2, R3, C1, C2, C3;
            string select1;
            string grid[8][8], grid2[8][8];

            cout << setw(90) << "-----------------------------------------------CHESS GAME (CHECKMATE)--------------------------------------------------" << endl;

            Grid(grid);

            cout << endl;
            cout << "Player 2 Choose two Chess Pieces for attacking" << endl
                 << endl;
            cout << "(Press 'RK' for 'Rook' || Press 'KT' for 'Knight' || Press 'BP' for 'Bishop' || Press 'QN' for 'Queen')" << endl;
            cout << endl;

            cout << "Press 'e' to exit" << endl;

            cin >> select1;

            if (select1 == "E" || select1 == "e")
            {
                exit(1);
            }

            while (!((select1 == "RK") || (select1 == "KT") || (select1 == "BP") || (select1 == "QN")))
            {
                cout << endl;
                cout << "Invalid Selection! Please Try again!" << endl;
                cout << endl;
                cout << "Player 2 Choose two Chess Pieces for attacking" << endl
                     << endl;
                cout << "(Press 'RK' for 'Rook' || Press 'KT' for 'Knight' || Press 'BP' for 'Bishop' || Press 'QN' for 'Queen')" << endl;

                cout << endl;
                cout << "Press 'e' to exit" << endl;

                cin >> select1;

                if (select1 == "E" || select1 == "e")
                {
                    exit(1);
                }
            }

            if (select1 == "KT")
            {

                cout << "Sorry! You can only checkmate with Rooks || Queens." << endl;
                cout << endl;
                cout << "Choose either Rooks || Queens" << endl;

                cout << endl;
                cout << "Press 'e' to exit" << endl;

                cin >> select1;

                if (select1 == "E" || select1 == "e")
                {
                    exit(1);
                }

                while (!(select1 == "RK" || select1 == "QN"))
                {
                    cout << "Sorry! You can only checkmate with Rooks || Queens." << endl;
                    cout << endl;
                    cout << "Choose either Rooks || Queens" << endl;

                    cout << endl;
                    cout << "Press 'e' to exit" << endl;

                    cin >> select1;

                    if (select1 == "E" || select1 == "e")
                    {
                        exit(1);
                    }
                }
            }

            if (select1 == "BP")
            {
                cout << "Sorry! You can only checkmate with Rooks || Queens." << endl;
                cout << endl;
                cout << "Choose either Rooks || Queens" << endl;

                cout << endl;
                cout << "Press 'e' to exit" << endl;

                cin >> select1;

                if (select1 == "E" || select1 == "e")
                {
                    exit(1);
                }

                while (!(select1 == "RK" || select1 == "QN"))
                {
                    cout << "Sorry! You can only checkmate with Rooks || Queens." << endl;
                    cout << endl;
                    cout << "Choose either Rooks || Queens" << endl;
                    /*cin >> select1;*/
                    cout << endl;
                    cout << "Press 'e' to exit" << endl;

                    cin >> select1;

                    if (select1 == "E" || select1 == "e")
                    {
                        exit(1);
                    }
                }
            }

            if (select1 == "RK")
            {

                cout << "This is the Range of Rook on the Chess Board" << endl;
                cout << endl;

                cout << endl;
                cout << setw(8);
                for (i = 0; i < 3; i++)
                {
                    cout << i << "   ";
                }
                cout << endl;

                // Print rows and board
                for (i = 0; i < 6; i++)
                {
                    cout << setw(5) << i << " "; // Print row number

                    for (j = 0; j < 4; j++)
                    {
                        if ((i + j) % 2 == 0)
                        {
                            cout << "\033[43m"; // Set background color to white
                        }
                        else if ((((i + j) % 2) != 0))
                        {
                            cout << "\033[40m"; // Set background color to black
                        }

                        if (i == 2 && j == 2)
                        {
                            grid[i][j] = "*";
                        }
                        else if (i == 2 || j == 2)
                        {
                            grid[i][j] = "* ";
                        }
                        /*grid[i][j] = "**";*/
                        cout << " " << grid[i][j] << " ";
                        cout << "\033[0m"; // Reset background color
                    }
                    cout << endl;
                }

                cout << endl;

                cout << "This is the Range of King on the Chess Board" << endl;
                cout << endl;

                cout << endl;
                cout << setw(8);
                for (i = 0; i < 3; i++)
                {
                    cout << i << "   ";
                }
                cout << endl;

                // Print rows and board
                for (i = 0; i < 3; i++)
                {
                    cout << setw(5) << i << " "; // Print row number

                    for (j = 0; j < 3; j++)
                    {
                        if ((i + j) % 2 == 0)
                        {
                            cout << "\033[43m"; // Set background color to white
                        }
                        else if ((((i + j) % 2) != 0))
                        {
                            cout << "\033[40m"; // Set background color to black
                        }
                        grid[i][j] = "*";
                        cout << " " << grid[i][j] << " ";
                        cout << "\033[0m"; // Reset background color
                    }
                    cout << endl;
                }

                cout << "Write 'C' to 'continue'" << endl;
                cout << endl;
                cout << "Press 'e' to exit" << endl;

                cin >> select1;

                if (select1 == "E" || select1 == "e")
                {
                    exit(1);
                }
                /*cin >> select1;*/

                while (!(select1 == "c" || select1 == "C"))
                {
                    cout << "Invalid Input! Please Try Again!" << endl;
                    cout << endl;
                    cout << "Write 'C' to 'continue'" << endl;
                    /*cin >> select1;*/
                    cout << endl;
                    cout << "Press 'e' to exit" << endl;

                    cin >> select1;

                    if (select1 == "E" || select1 == "e")
                    {
                        exit(1);
                    }
                }
            }

            if (select1 == "C" || select1 == "c")
            {

                srand(time(NULL));
                r1 = (rand() % 8);
                c1 = (rand() % 8);

                /* system("cls");*/

                cout << endl;
                cout << setw(8);
                for (i = 0; i < 8; i++)
                {
                    cout << i << "   ";
                }
                cout << endl;

                // Print rows and board
                for (i = 0; i < 8; i++)
                {
                    cout << setw(5) << i << " "; // Print row number

                    for (j = 0; j < 8; j++)
                    {
                        if ((i + j) % 2 == 0)
                        {
                            cout << "\033[43m"; // Set background color to white
                        }
                        else
                        {
                            cout << "\033[40m"; // Set background color to black
                        }

                        if (i == r1 && j == c1)
                        {

                            grid[i][j] = "RK";
                        }
                        else
                        {
                            grid[i][j] = "  ";
                        }
                        /*grid[i][j] = "  ";*/
                        cout << " " << grid[i][j] << " ";
                        cout << "\033[0m"; // Reset background color
                    }
                    cout << endl;
                }

                cout << endl;

                srand(time(NULL));
                r2 = (rand() % 8);
                c2 = (rand() % 8);

                while (r1 == r2 && c1 == c2)
                {

                    srand(time(NULL));
                    r2 = (rand() % 8);
                    c2 = (rand() % 8);
                }
                system("cls");

                cout << endl;
                cout << setw(8);
                for (i = 0; i < 8; i++)
                {
                    cout << i << "   ";
                }
                cout << endl;

                // Print rows and board
                for (i = 0; i < 8; i++)
                {
                    cout << setw(5) << i << " "; // Print row number

                    for (j = 0; j < 8; j++)
                    {
                        if ((i + j) % 2 == 0)
                        {
                            cout << "\033[43m"; // Set background color to white
                        }
                        else
                        {
                            cout << "\033[40m"; // Set background color to black
                        }
                        if (i == r1 && j == c1)
                        {
                            grid[i][j] = "RK";
                        }
                        /*else {
                            grid[i][j] = "  ";
                        }*/
                        if (i == r2 && j == c2)
                        {
                            grid[i][j] = "RK";
                        }
                        /*else {
                            grid[i][j] = "  ";
                        }*/
                        /*grid[i][j] = "  ";*/
                        cout << " " << grid[i][j] << " ";
                        cout << "\033[0m"; // Reset background color
                    }
                    cout << endl;
                }

                cout << endl;
                srand(time(NULL));
                r3 = (rand() % 8);
                c3 = (rand() % 8);

                while ((r3 == r1 || c3 == c1) || (r3 == r2 || c3 == c2))
                {
                    srand(time(NULL));
                    r3 = (rand() % 8);
                    c3 = (rand() % 8);
                }

                while ((r3 == r1 || c3 == c1) || (r3 == r2 || c3 == c2))
                {
                    cout << "Invalid! Please Try Again." << endl;
                    cout << endl;
                    cout << "Player 1 Your King cannot move here!" << endl;
                    cout << "Enter Row : ";
                    cin >> r3;
                    cout << "Enter Column : ";
                    cin >> c3;
                }
                system("cls");

                cout << endl;
                cout << setw(8);
                for (i = 0; i < 8; i++)
                {
                    cout << i << "   ";
                }
                cout << endl;

                // Print rows and board
                for (i = 0; i < 8; i++)
                {
                    cout << setw(5) << i << " "; // Print row number

                    for (j = 0; j < 8; j++)
                    {
                        if ((i + j) % 2 == 0)
                        {
                            cout << "\033[43m"; // Set background color to white
                        }
                        else
                        {
                            cout << "\033[40m"; // Set background color to black
                        }

                        if (i == r1 && j == c1)
                        {
                            grid[i][j] = "RK";
                        }
                        if (i == r2 && j == c2)
                        {
                            grid[i][j] = "RK";
                        }
                        if (i == r3 && j == c3)
                        {
                            grid[i][j] = "KG";
                        }
                        /*else {
                            grid[i][j] = "  ";
                        }*/
                        /*grid[i][j] = "  ";*/
                        cout << " " << grid[i][j] << " ";
                        cout << "\033[0m"; // Reset background color
                    }
                    cout << endl;
                }

                cout << endl;

                cout << "Player 2 Your Both Rooks are placed randomly on the board!" << endl;
                cout << endl;
                cout << "Player 1 Your King is also placed randomly on the board!" << endl;
                cout << endl;
                cout << "Now lets start the game PLAYER 1 you have to SAVE YOUR KING and PLAYER 2 you have to CHECKMATE THE KING!" << endl;

                // player2

                while (b != 0)
                {
                    cout << endl;
                    cout << "Player's 2 turn : " << endl;
                    cout << endl;
                    cout << "Which Rock you want to move? ("
                         << "RK[" << r1 << "][" << c1 << "] || RK[" << r2 << "][" << c2 << "])" << endl;
                    cout << "(For "
                         << "RK[" << r1 << "][" << c1 << "]"
                         << "Press '1'"
                         << " || For "
                         << "RK[" << r2 << "][" << c2 << "]"
                         << "Press '2')" << endl;
                    cin >> choice;

                    while (!((choice == 1) || (choice == 2)))
                    {

                        cout << endl;
                        cout << "Invalid Selection! Please try again!" << endl;
                        cout << endl;
                        cout << "Which Rock you want to move? ("
                             << "RK[" << r1 << "][" << c1 << "] || RK[" << r2 << "][" << c2 << "])" << endl;
                        cout << "(For "
                             << "RK[" << r1 << "][" << c1 << "]"
                             << "Press '1'"
                             << " || For "
                             << "RK[" << r2 << "][" << c2 << "]"
                             << "Press '2')" << endl;
                        cin >> choice;
                    }

                    if (choice == 1)
                    {
                        R1 = r1;
                        C1 = c1;
                        cout << "Where you want to move your First Rook in the Grid? (Enter row and column number)" << endl;
                        cout << endl;
                        cout << "Enter Row : ";
                        cin >> r1;
                        cout << "Enter Column : ";
                        cin >> c1;

                        while (!((r1 >= 0 && r1 <= 7) && (c1 >= 0 && c1 <= 7)))
                        {
                            cout << endl;
                            cout << "Where you want to move your First Rook in the Grid? (Enter row and column number)" << endl;
                            cout << endl;
                            cout << "Invalid Input! Please Try Again!" << endl;
                            cout << endl;

                            cout << "Enter Row : ";
                            cin >> r1;
                            cout << "Enter Column : ";
                            cin >> c1;
                        }

                        while ((((r1 != R1) && (c1 != C1)) || (r1 == r2 && c1 == c2)) || (R1 == r1 && C1 == c1))
                        {
                            cout << endl;
                            cout << "Invalid! Please Try Again." << endl;
                            cout << endl;
                            cout << "Player 2 your Rook cannot move here!" << endl;
                            cout << endl;
                            cout << "Enter Row : ";
                            cin >> r1;
                            cout << "Enter Column : ";
                            cin >> c1;
                        }

                        system("cls");
                        // exp

                        cout << endl;
                        cout << setw(8);
                        for (i = 0; i < 8; i++)
                        {
                            cout << i << "   ";
                        }
                        cout << endl;

                        // Print rows and board
                        for (i = 0; i < 8; i++)
                        {
                            cout << setw(5) << i << " "; // Print row number

                            for (j = 0; j < 8; j++)
                            {
                                if ((i + j) % 2 == 0)
                                {
                                    cout << "\033[43m"; // Set background color to white
                                }
                                else
                                {
                                    cout << "\033[40m"; // Set background color to black
                                }

                                if (i == r1 && j == c1)
                                {
                                    grid[i][j] = "RK";
                                }

                                else
                                {

                                    grid[i][j] = "  ";
                                }
                                if (i == r2 && j == c2)
                                {
                                    grid[i][j] = "RK";
                                }
                                if (i == r3 && j == c3)
                                {
                                    grid[i][j] = "KG";
                                }
                                /*grid[i][j] = "  ";*/
                                cout << " " << grid[i][j] << " ";
                                cout << "\033[0m"; // Reset background color
                            }
                            cout << endl;
                        }
                    }

                    else if (choice == 2)
                    {
                        R2 = r2;
                        C2 = c2;
                        cout << "Where you want to place your Second Rock in the Grid? (Enter row and column number)" << endl;
                        cout << endl;
                        cout << "Enter Row : ";
                        cin >> r2;
                        cout << "Enter Column : ";
                        cin >> c2;

                        while (!((r1 >= 0 && r1 <= 7) && (c1 >= 0 && c1 <= 7)))
                        {
                            cout << endl;
                            cout << "Where you want to move your First Rook in the Grid? (Enter row and column number)" << endl;
                            cout << endl;
                            cout << "Invalid Input! Please Try Again!" << endl;
                            cout << endl;

                            cout << "Enter Row : ";
                            cin >> r1;
                            cout << "Enter Column : ";
                            cin >> c1;
                        }

                        while ((((r2 != R2) && (c2 != C2)) || (r2 == r1 && c2 == c1)) || (R2 == r2 && C2 == c2))
                        {
                            cout << endl;
                            cout << "Invalid! Please Try Again." << endl;
                            cout << endl;
                            cout << "Player 2 your Rook cannot move here!" << endl;
                            cout << endl;
                            cout << "Enter Row : ";
                            cin >> r2;
                            cout << "Enter Column : ";
                            cin >> c2;
                        }

                        system("cls");

                        cout << endl;
                        cout << setw(8);
                        for (i = 0; i < 8; i++)
                        {
                            cout << i << "   ";
                        }
                        cout << endl;

                        // Print rows and board
                        for (i = 0; i < 8; i++)
                        {
                            cout << setw(5) << i << " "; // Print row number

                            for (j = 0; j < 8; j++)
                            {
                                if ((i + j) % 2 == 0)
                                {
                                    cout << "\033[43m"; // Set background color to white
                                }
                                else
                                {
                                    cout << "\033[40m"; // Set background color to black
                                }
                                if (i == r1 && j == c1)
                                {
                                    grid[i][j] = "RK";
                                }
                                else
                                {
                                    grid[i][j] = "  ";
                                }
                                if (i == r2 && j == c2)
                                {
                                    grid[i][j] = "RK";
                                }
                                /*else {
                                    grid[i][j] = "  ";
                                }*/
                                if (i == r3 && j == c3)
                                {
                                    grid[i][j] = "KG";
                                }

                                /*grid[i][j] = "  ";*/
                                cout << " " << grid[i][j] << " ";
                                cout << "\033[0m"; // Reset background color
                            }
                            cout << endl;
                        }

                        cout << endl;
                    }

                    // Checkmate

                    // Left corner Checkmate

                    if (r3 == 0)
                    {

                        if (((r1 == r3 || r2 == r3) && ((r1 + 1 == r2) || (r2 + 1 == r1))) /*&& !((r1 != r2) && ((((r3 - 1 != r2) && (c3 - 1 != c2)) || ((r3 + 1 != r2) && (c3 + 1 != c2))) || (((r3 - 1 != r1) && (c3 - 1 != c1)) || ((r3 + 1 != r1) && (c3 + 1 != c1)))))*/)
                        {
                            b = 0;
                            cout << endl;
                            cout << "Checkmate Player 2 has won" << endl;
                            exit(1);
                        }
                    }

                    if (c3 == 0)
                    {

                        if (((c1 == c3 || c2 == c3) && ((c1 + 1 == c2) || (c2 + 1 == c1))) /*&& !((r1 != r2) && ((((r3 - 1 != r2) && (c3 - 1 != c2)) || ((r3 + 1 != r2) && (c3 + 1 != c2))) || (((r3 - 1 != r1) && (c3 - 1 != c1)) || ((r3 + 1 != r1) && (c3 + 1 != c1)))))*/)
                        {
                            b = 0;
                            cout << endl;
                            cout << "Checkmate Player 2 has won" << endl;
                            exit(1);
                        }
                    }

                    if (r3 == 7)
                    {

                        if (((r1 == r3 || r2 == r3) && ((r1 + 1 == r2) || (r2 + 1 == r1))) /*&& !((r1 != r2) && ((((r3 - 1 != r2) && (c3 - 1 != c2)) || ((r3 + 1 != r2) && (c3 + 1 != c2))) || (((r3 - 1 != r1) && (c3 - 1 != c1)) || ((r3 + 1 != r1) && (c3 + 1 != c1)))))*/)
                        {
                            b = 0;
                            cout << endl;
                            cout << "Checkmate Player 2 has won" << endl;
                            exit(1);
                        }
                    }

                    if (c3 == 7)
                    {

                        if (((c1 == c3 || c2 == c3) && ((c1 + 1 == c2) || (c2 + 1 == c1))) /*&& !((r1 != r2) && ((((r3 - 1 != r2) && (c3 - 1 != c2)) || ((r3 + 1 != r2) && (c3 + 1 != c2))) || (((r3 - 1 != r1) && (c3 - 1 != c1)) || ((r3 + 1 != r1) && (c3 + 1 != c1)))))*/)
                        {
                            b = 0;
                            cout << endl;
                            cout << "Checkmate Player 2 has won" << endl;
                            exit(1);
                        }
                    }

                    // player1

                    R3 = r3;
                    C3 = c3;
                    cout << endl;

                    cout << "Player's 1 turn : " << endl;
                    cout << endl;
                    cout << "Player 1 please enter the position of your King (Enter row and column number)" << endl;
                    cout << endl;
                    cout << "Enter Row : ";
                    cin >> r3;
                    cout << "Enter Column : ";
                    cin >> c3;

                    system("cls");

                    //
                    cout << endl;
                    cout << setw(8);
                    for (i = 0; i < 8; i++)
                    {
                        cout << i << "   ";
                    }
                    cout << endl;

                    // Print rows and board
                    for (i = 0; i < 8; i++)
                    {
                        cout << setw(5) << i << " "; // Print row number

                        for (j = 0; j < 8; j++)
                        {
                            if ((i + j) % 2 == 0)
                            {
                                cout << "\033[43m"; // Set background color to white
                            }
                            else
                            {
                                cout << "\033[40m"; // Set background color to black
                            }

                            if (i == r1 && j == c1)
                            {
                                grid[i][j] = "RK";
                            }
                            else
                            {
                                grid[i][j] = "  ";
                            }
                            if (i == r2 && j == c2)
                            {
                                grid[i][j] = "RK";
                            }
                            /*if (i == r3 && j == c3) {
                                grid[i][j] = "RK";
                            }*/
                            if (i == R3 && j == C3)
                            {
                                grid[i][j] = "KG";
                            }

                            /*grid[i][j] = "  ";*/
                            cout << " " << grid[i][j] << " ";
                            cout << "\033[0m"; // Reset background color
                        }
                        cout << endl;
                    }

                    if (((r3 == r1 && c3 == c1) || (r3 == r2 && c3 == c2)) && !((r1 == r2) || (c1 == c2)))
                    {

                        cout << endl;
                        cout << setw(8);
                        for (i = 0; i < 8; i++)
                        {
                            cout << i << "   ";
                        }
                        cout << endl;
                        for (i = 0; i < 8; i++)
                        {
                            cout << setw(5) << i << " "; // Print row number

                            for (j = 0; j < 8; j++)
                            {
                                if ((i + j) % 2 == 0)
                                {
                                    cout << "\033[43m"; // Set background color to white
                                }
                                else
                                {
                                    cout << "\033[40m"; // Set background color to black
                                }

                                if (i == r1 && j == c1)
                                {
                                    grid[i][j] = "RK";
                                }
                                else
                                {
                                    grid[i][j] = "  ";
                                }
                                if (i == r2 && j == c2)
                                {
                                    grid[i][j] = "RK";
                                }
                                if (i == r3 && j == c3)
                                {
                                    grid[i][j] = "KG";
                                }

                                /*grid[i][j] = "  ";*/
                                cout << " " << grid[i][j] << " ";
                                cout << "\033[0m"; // Reset background color
                            }
                            cout << endl;
                        }
                        cout << "Game is Tied as One Rook cannot checkmate alone King!" << endl;
                        exit(1);
                    }

                    while (((r3 == r1 || c3 == c1) || (r3 == r2 || c3 == c2)) || (R3 == r3 && C3 == c3) || ((r1 == r2) && ((((r3 - 1 == r2) && (c3 - 1 == c2)) || ((r3 + 1 == r2) && (c3 + 1 == c2))) || (((r3 - 1 == r1) && (c3 - 1 == c1)) || ((r3 + 1 == r1) && (c3 + 1 == c1))))))
                    {

                        cout << "Invalid! Please Try Again." << endl;
                        cout << endl;
                        cout << "Player 1 Your King cannot move here!" << endl;
                        cout << endl;
                        cout << "Enter Row : ";
                        cin >> r3;
                        cout << "Enter Column : ";
                        cin >> c3;

                        if ((r3 == r1 && c3 == c1) || (r3 == r2 && c3 == c2))
                        {

                            cout << endl;
                            cout << setw(8);
                            for (i = 0; i < 8; i++)
                            {
                                cout << i << "   ";
                            }
                            cout << endl;
                            for (i = 0; i < 8; i++)
                            {
                                cout << setw(5) << i << " "; // Print row number

                                for (j = 0; j < 8; j++)
                                {
                                    if ((i + j) % 2 == 0)
                                    {
                                        cout << "\033[43m"; // Set background color to white
                                    }
                                    else
                                    {
                                        cout << "\033[40m"; // Set background color to black
                                    }

                                    if (i == r1 && j == c1)
                                    {
                                        grid[i][j] = "RK";
                                    }
                                    else
                                    {
                                        grid[i][j] = "  ";
                                    }
                                    if (i == r2 && j == c2)
                                    {
                                        grid[i][j] = "RK";
                                    }
                                    if (i == r3 && j == c3)
                                    {
                                        grid[i][j] = "KG";
                                    }

                                    /*grid[i][j] = "  ";*/
                                    cout << " " << grid[i][j] << " ";
                                    cout << "\033[0m"; // Reset background color
                                }
                                cout << endl;
                            }
                            cout << "Game is Tied as One Rook cannot checkmate alone King!" << endl;
                            exit(1);
                        }
                    }

                    while (!(((r3 + c3) <= (R3 + C3) + 2) && ((r3 + c3) >= (R3 + C3) - 2) && ((r3 == R3 || r3 == R3 + 1 || r3 == R3 - 1) && (c3 == C3 || c3 == C3 + 1 || c3 == C3 - 1))))
                    {

                        while ((R3 >= 2) && (r3 == 0))
                        {
                            cout << "Invalid! Please Try Again." << endl;
                            cout << endl;
                            cout << "Player 1 Your King cannot move here!" << endl;
                            cout << endl;
                            cout << "Enter Row : ";
                            cin >> r3;
                            cout << "Enter Column : ";
                            cin >> c3;
                        }

                        cout << "Invalid! Please Try Again." << endl;
                        cout << endl;
                        cout << "Player 1 Your King cannot move here!" << endl;
                        cout << endl;
                        cout << "Enter Row : ";
                        cin >> r3;
                        cout << "Enter Column : ";
                        cin >> c3;
                    }

                    system("cls");

                    cout << endl;
                    cout << setw(8);
                    for (i = 0; i < 8; i++)
                    {
                        cout << i << "   ";
                    }
                    cout << endl;

                    // Print rows and board
                    for (i = 0; i < 8; i++)
                    {
                        cout << setw(5) << i << " "; // Print row number

                        for (j = 0; j < 8; j++)
                        {
                            if ((i + j) % 2 == 0)
                            {
                                cout << "\033[43m"; // Set background color to white
                            }
                            else
                            {
                                cout << "\033[40m"; // Set background color to black
                            }

                            if (i == r1 && j == c1)
                            {
                                grid[i][j] = "RK";
                            }
                            else
                            {
                                grid[i][j] = "  ";
                            }
                            if (i == r2 && j == c2)
                            {
                                grid[i][j] = "RK";
                            }
                            if (i == r3 && j == c3)
                            {
                                grid[i][j] = "KG";
                            }

                            /*grid[i][j] = "  ";*/
                            cout << " " << grid[i][j] << " ";
                            cout << "\033[0m"; // Reset background color
                        }
                        cout << endl;
                    }
                }
            }

            // Queen

            if (select1 == "QN")
            {

                cout << "This is the Range of Queen on the Chess Board" << endl;
                cout << endl;

                cout << endl;
                cout << setw(8);
                for (i = 0; i < 3; i++)
                {
                    cout << i << "   ";
                }
                cout << endl;

                // Print rows and board
                for (i = 0; i < 6; i++)
                {
                    cout << setw(5) << i << " "; // Print row number

                    for (j = 0; j < 6; j++)
                    {
                        if ((i + j) % 2 == 0)
                        {
                            cout << "\033[43m"; // Set background color to white
                        }
                        else if ((((i + j) % 2) != 0))
                        {
                            cout << "\033[40m"; // Set background color to black
                        }

                        if (i == 3 && j == 3)
                        {
                            grid[i][j] = " *";
                        }
                        else if (i == 3 || j == 3)
                        {
                            grid[i][j] = "*";
                        }
                        else if (i == j)
                        {
                            grid[i][j] = "*";
                        }
                        else if ((i + j) == 6)
                        {
                            grid[i][j] = "*";
                        }
                        /*grid[i][j] = "**";*/
                        cout << " " << grid[i][j] << " ";
                        cout << "\033[0m"; // Reset background color
                    }
                    cout << endl;
                }

                cout << endl;

                cout << "This is the Range of King on the Chess Board" << endl;
                cout << endl;

                cout << endl;
                cout << setw(8);
                for (i = 0; i < 3; i++)
                {
                    cout << i << "   ";
                }
                cout << endl;

                // Print rows and board
                for (i = 0; i < 3; i++)
                {
                    cout << setw(5) << i << " "; // Print row number

                    for (j = 0; j < 3; j++)
                    {
                        if ((i + j) % 2 == 0)
                        {
                            cout << "\033[43m"; // Set background color to white
                        }
                        else if ((((i + j) % 2) != 0))
                        {
                            cout << "\033[40m"; // Set background color to black
                        }
                        grid[i][j] = "*";
                        cout << " " << grid[i][j] << " ";
                        cout << "\033[0m"; // Reset background color
                    }
                    cout << endl;
                }

                cout << "Write 'C' to 'continue'" << endl;
                cout << endl;
                cout << "Press 'e' to exit" << endl;

                cin >> select1;

                if (select1 == "E" || select1 == "e")
                {
                    exit(1);
                }
                /*cin >> select1;*/

                while (!(select1 == "c" || select1 == "C"))
                {
                    cout << "Invalid Input! Please Try Again!" << endl;
                    cout << endl;
                    cout << "Write 'C' to 'continue'" << endl;
                    cout << endl;
                    cout << "Press 'e' to exit" << endl;

                    cin >> select1;

                    if (select1 == "E" || select1 == "e")
                    {
                        exit(1);
                    }
                    /*cin >> select1;*/
                }
            }

            if ((select1 == "C" || select1 == "c"))
            {

                srand(time(NULL));
                r1 = (rand() % 8);
                c1 = (rand() % 8);

                system("cls");

                cout << endl;
                cout << setw(8);
                for (i = 0; i < 8; i++)
                {
                    cout << i << "   ";
                }
                cout << endl;

                // Print rows and board
                for (i = 0; i < 8; i++)
                {
                    cout << setw(5) << i << " "; // Print row number

                    for (j = 0; j < 8; j++)
                    {
                        if ((i + j) % 2 == 0)
                        {
                            cout << "\033[43m"; // Set background color to white
                        }
                        else
                        {
                            cout << "\033[40m"; // Set background color to black
                        }

                        if (i == r1 && j == c1)
                        {

                            grid[i][j] = "QN";
                        }
                        else
                        {
                            grid[i][j] = "  ";
                        }
                        /*grid[i][j] = "  ";*/
                        cout << " " << grid[i][j] << " ";
                        cout << "\033[0m"; // Reset background color
                    }
                    cout << endl;
                }

                cout << endl;
                srand(time(NULL));
                r2 = (rand() % 8);
                c2 = (rand() % 8);

                while (r1 == r2 && c1 == c2)
                {

                    srand(time(NULL));
                    r2 = (rand() % 8);
                    c2 = (rand() % 8);
                }
                system("cls");

                cout << endl;
                cout << setw(8);
                for (i = 0; i < 8; i++)
                {
                    cout << i << "   ";
                }
                cout << endl;

                // Print rows and board
                for (i = 0; i < 8; i++)
                {
                    cout << setw(5) << i << " "; // Print row number

                    for (j = 0; j < 8; j++)
                    {
                        if ((i + j) % 2 == 0)
                        {
                            cout << "\033[43m"; // Set background color to white
                        }
                        else
                        {
                            cout << "\033[40m"; // Set background color to black
                        }
                        if (i == r1 && j == c1)
                        {
                            grid[i][j] = "QN";
                        }
                        /*else {
                            grid[i][j] = "  ";
                        }*/
                        if (i == r2 && j == c2)
                        {
                            grid[i][j] = "QN";
                        }
                        /*else {
                            grid[i][j] = "  ";
                        }*/
                        /*grid[i][j] = "  ";*/
                        cout << " " << grid[i][j] << " ";
                        cout << "\033[0m"; // Reset background color
                    }
                    cout << endl;
                }

                cout << endl;
                srand(time(NULL));
                r3 = (rand() % 8);
                c3 = (rand() % 8);

                while ((r3 == r1 || c3 == c1) || (r3 == r2 || c3 == c2) || (r1 == c1 && r3 == c3) || (r2 == c2 && r3 == c3) || (r1 + c1 == r3 + c3) || (r2 + c2 == r3 + c3) || (r1 + c3 == r3 + c1) || (r2 + c3 == r3 + c2))
                {
                    srand(time(NULL));
                    r3 = (rand() % 8);
                    c3 = (rand() % 8);
                }

                while ((r3 == r1 || c3 == c1) || (r3 == r2 || c3 == c2))
                {
                    cout << "Invalid! Please Try Again." << endl;
                    cout << endl;
                    cout << "Player 1 Your King cannot move here!" << endl;
                    cout << "Enter Row : ";
                    cin >> r3;
                    cout << "Enter Column : ";
                    cin >> c3;
                }
                system("cls");

                cout << endl;
                cout << setw(8);
                for (i = 0; i < 8; i++)
                {
                    cout << i << "   ";
                }
                cout << endl;

                // Print rows and board
                for (i = 0; i < 8; i++)
                {
                    cout << setw(5) << i << " "; // Print row number

                    for (j = 0; j < 8; j++)
                    {
                        if ((i + j) % 2 == 0)
                        {
                            cout << "\033[43m"; // Set background color to white
                        }
                        else
                        {
                            cout << "\033[40m"; // Set background color to black
                        }

                        if (i == r1 && j == c1)
                        {
                            grid[i][j] = "QN";
                        }
                        if (i == r2 && j == c2)
                        {
                            grid[i][j] = "QN";
                        }
                        if (i == r3 && j == c3)
                        {
                            grid[i][j] = "KG";
                        }
                        /*else {
                            grid[i][j] = "  ";
                        }*/
                        /*grid[i][j] = "  ";*/
                        cout << " " << grid[i][j] << " ";
                        cout << "\033[0m"; // Reset background color
                    }
                    cout << endl;
                }

                cout << endl;

                cout << "Player 2 Your Both Queens are placed randomly on the board!" << endl;
                cout << endl;
                cout << "Player 1 Your King is also placed randomly on the board!" << endl;
                cout << endl;
                cout << "Now lets start the game PLAYER 1 you have to SAVE YOUR KING and PLAYER 2 you have to CHECKMATE THE KING!" << endl;

                // player2

                while (b != 0)
                {
                    cout << endl;
                    cout << "Player's 2 turn : " << endl;
                    cout << endl;
                    cout << "Which Queen you want to move? ("
                         << "QN[" << r1 << "][" << c1 << "] || QN[" << r2 << "][" << c2 << "])" << endl;
                    cout << "(For "
                         << "QN[" << r1 << "][" << c1 << "]"
                         << "Press '1'"
                         << " || For "
                         << "QN[" << r2 << "][" << c2 << "]"
                         << "Press '2')" << endl;
                    cin >> choice;

                    while (!((choice == 1) || (choice == 2)))
                    {

                        cout << endl;
                        cout << "Invalid Selection! Please try again!" << endl;
                        cout << endl;
                        cout << "Which Queen you want to move? ("
                             << "QN[" << r1 << "][" << c1 << "] || QN[" << r2 << "][" << c2 << "])" << endl;
                        cout << "(For "
                             << "QN[" << r1 << "][" << c1 << "]"
                             << "Press '1'"
                             << " || For "
                             << "QN[" << r2 << "][" << c2 << "]"
                             << "Press '2')" << endl;
                        cin >> choice;
                    }

                    if (choice == 1)
                    {
                        R1 = r1;
                        C1 = c1;
                        cout << "Where you want to move your First Queen in the Grid? (Enter row and column number)" << endl;
                        cout << endl;
                        cout << "Enter Row : ";
                        cin >> r1;
                        cout << "Enter Column : ";
                        cin >> c1;

                        while (!((r1 >= 0 && r1 <= 7) && (c1 >= 0 && c1 <= 7)) || ((r1 == r2 && c1 == c2) || (r1 == r3 && c1 == c3) || (r1 == R1 && c1 == C1)))
                        {
                            cout << endl;
                            cout << "Where you want to move your First Queen in the Grid? (Enter row and column number)" << endl;
                            cout << endl;
                            cout << "Invalid Input! Please Try Again!" << endl;
                            cout << endl;

                            cout << "Enter Row : ";
                            cin >> r1;
                            cout << "Enter Column : ";
                            cin >> c1;
                        }

                        /*while (R1==0 && C1==4) {
                            grid[r1][c1];
                            break;
                        }*/

                        while (/*(0,0)*/ ((R1 == 0 && C1 == 0) && !((r1 == c1) || (r1 == R1) || (c1 == C1))) || /*(0,1)*/ ((R1 == 0 && C1 == 1) && !((r1 == 1 && c1 == 0) || (r1 == 1 && c1 == 2) || (r1 == 2 && c1 == 3) || (r1 == 3 && c1 == 4) || (r1 == 4 && c1 == 5) || (r1 == 5 && c1 == 6) || (r1 == 6 && c1 == 7) || (r1 == R1) || (c1 == C1))) || /*(0,2)*/ ((R1 == 0 && C1 == 2) && !((r1 == 1 && c1 == 1) || (r1 == 2 && c1 == 0) || (r1 == 1 && c1 == 3) || (r1 == 2 && c1 == 4) || (r1 == 3 && c1 == 5) || (r1 == 4 && c1 == 6) || (r1 == 5 && c1 == 7) || (r1 == R1) || (c1 == C1))) || /*(0,3)*/ ((R1 == 0 && C1 == 3) && !((r1 == 3 && c1 == 0) || (r1 == 2 && c1 == 1) || (r1 == 1 && c1 == 2) || (r1 == 1 && c1 == 4) || (r1 == 2 && c1 == 5) || (r1 == 3 && c1 == 6) || (r1 == 4 && c1 == 7) || (r1 == R1) || (c1 == C1))) || /*(0,4)*/ ((R1 == 0 && C1 == 4) && !(((r1 + c1) == 4) || (c1 == r1 + 4) || (r1 == R1) || (c1 == C1))) || /*(0,5)*/ ((R1 == 0 && C1 == 5) && !((r1 == 1 && c1 == 6) || (r1 == 2 && c1 == 7) || ((r1 + c1) == 5) || (r1 == R1) || (c1 == C1))) || /*(0,6)*/ ((R1 == 0 && C1 == 6) && !((r1 == 1 && c1 == 7) || ((r1 + c1) == 6) || (r1 == R1) || (c1 == C1))) || /*(0,7)*/ ((R1 == 0 && C1 == 7) && !(((r1 + c1) == 7) || (r1 == R1) || (c1 == C1))) || /*(1,0)*/ ((R1 == 1 && C1 == 0) && !(((r1 + c1) == 1) || (r1 == c1 + 1) || (r1 == R1) || (c1 == C1))) || /*(1,1)*/ ((R1 == 1 && C1 == 1) && !(((r1 + c1) == 2) || (r1 == c1) || (r1 == R1) || (c1 == C1))) || /*(1,2)*/ ((R1 == 1 && C1 == 2) && !(((r1 + c1) == 3) || (c1 == r1 + 1) || (r1 == R1) || (c1 == C1))) || /*(1,3)*/ ((R1 == 1 && C1 == 3) && !(((r1 + c1) == 4) || (c1 == r1 + 2) || (r1 == R1) || (c1 == C1))) || /*(1,4)*/ ((R1 == 1 && C1 == 4) && !(((r1 + c1) == 5) || (c1 == r1 + 3) || (r1 == R1) || (c1 == C1))) || /*(1,5)*/ ((R1 == 1 && C1 == 5) && !(((r1 + c1) == 6) || (c1 == r1 + 4) || (r1 == R1) || (c1 == C1))) || /*(1,6)*/ ((R1 == 1 && C1 == 6) && !(((r1 + c1) == 7) || (c1 == r1 + 5) || (r1 == R1) || (c1 == C1))) || /*(1,7)*/ ((R1 == 1 && C1 == 7) && !(((r1 + c1) == 8) || (c1 == r1 + 6) || (r1 == R1) || (c1 == C1))) || /*(2,0)*/ ((R1 == 2 && C1 == 0) && !(((r1 + c1) == 2) || (r1 == c1 + 2) || (r1 == R1) || (c1 == C1))) || /*(2,1)*/ ((R1 == 2 && C1 == 1) && !(((r1 + c1) == 3) || (r1 == c1 + 1) || (r1 == R1) || (c1 == C1))) || /*(2,2)*/ ((R1 == 2 && C1 == 2) && !(((r1 + c1) == 4) || (r1 == c1) || (r1 == R1) || (c1 == C1))) || /*(2,3)*/ ((R1 == 2 && C1 == 3) && !(((r1 + c1) == 5) || (c1 == r1 + 1) || (r1 == R1) || (c1 == C1))) || /*(2,4)*/ ((R1 == 2 && C1 == 4) && !(((r1 + c1) == 6) || (c1 == r1 + 2) || (r1 == R1) || (c1 == C1))) || /*(2,5)*/ ((R1 == 2 && C1 == 5) && !(((r1 + c1) == 7) || (c1 == r1 + 3) || (r1 == R1) || (c1 == C1))) || /*(2,6)*/ ((R1 == 2 && C1 == 6) && !(((r1 + c1) == 8) || (c1 == r1 + 4) || (r1 == R1) || (c1 == C1))) || /*(2,7)*/ ((R1 == 2 && C1 == 7) && !(((r1 + c1) == 9) || (c1 == r1 + 5) || (r1 == R1) || (c1 == C1))) || /*(3,0)*/ ((R1 == 3 && C1 == 0) && !(((r1 + c1) == 3) || (r1 == c1 + 3) || (r1 == R1) || (c1 == C1))) || /*(3,1)*/ ((R1 == 3 && C1 == 1) && !(((r1 + c1) == 4) || (r1 == c1 + 2) || (r1 == R1) || (c1 == C1))) || /*(3,2)*/ ((R1 == 3 && C1 == 2) && !(((r1 + c1) == 5) || (r1 == c1 + 1) || (r1 == R1) || (c1 == C1))) || /*(3,3)*/ ((R1 == 3 && C1 == 3) && !(((r1 + c1) == 6) || (r1 == c1) || (r1 == R1) || (c1 == C1))) || /*(3,4)*/ ((R1 == 3 && C1 == 4) && !(((r1 + c1) == 7) || (c1 == r1 + 1) || (r1 == R1) || (c1 == C1))) || /*(3,5)*/ ((R1 == 3 && C1 == 5) && !(((r1 + c1) == 8) || (c1 == r1 + 2) || (r1 == R1) || (c1 == C1))) || /*(3,6)*/ ((R1 == 3 && C1 == 6) && !(((r1 + c1) == 9) || (c1 == r1 + 3) || (r1 == R1) || (c1 == C1))) || /*(3,7)*/ ((R1 == 3 && C1 == 7) && !(((r1 + c1) == 10) || (c1 == r1 + 4) || (r1 == R1) || (c1 == C1))) || /*(4,0)*/ ((R1 == 4 && C1 == 0) && !(((r1 + c1) == 4) || (r1 == c1 + 4) || (r1 == R1) || (c1 == C1))) || /*(4,1)*/ ((R1 == 4 && C1 == 1) && !(((r1 + c1) == 5) || (r1 == c1 + 3) || (r1 == R1) || (c1 == C1))) || /*(4,2)*/ ((R1 == 4 && C1 == 2) && !(((r1 + c1) == 6) || (r1 == c1 + 2) || (r1 == R1) || (c1 == C1))) || /*(4,3)*/ ((R1 == 4 && C1 == 3) && !(((r1 + c1) == 7) || (r1 == c1 + 1) || (r1 == R1) || (c1 == C1))) || /*(4,4)*/ ((R1 == 4 && C1 == 4) && !(((r1 + c1) == 8) || (r1 == c1) || (r1 == R1) || (c1 == C1))) || /*(4,5)*/ ((R1 == 4 && C1 == 5) && !(((r1 + c1) == 9) || (c1 == r1 + 1) || (r1 == R1) || (c1 == C1))) || /*(4,6)*/ ((R1 == 4 && C1 == 6) && !(((r1 + c1) == 10) || (c1 == r1 + 2) || (r1 == R1) || (c1 == C1))) || /*(4,7)*/ ((R1 == 4 && C1 == 7) && !(((r1 + c1) == 11) || (c1 == r1 + 3) || (r1 == R1) || (c1 == C1))) || /*(5,0)*/ ((R1 == 5 && C1 == 0) && !(((r1 + c1) == 5) || (r1 == c1 + 5) || (r1 == R1) || (c1 == C1))) || /*(5,1)*/ ((R1 == 5 && C1 == 1) && !(((r1 + c1) == 6) || (r1 == c1 + 4) || (r1 == R1) || (c1 == C1))) || /*(5,2)*/ ((R1 == 5 && C1 == 2) && !(((r1 + c1) == 7) || (r1 == c1 + 3) || (r1 == R1) || (c1 == C1))) || /*(5,3)*/ ((R1 == 5 && C1 == 3) && !(((r1 + c1) == 8) || (r1 == c1 + 2) || (r1 == R1) || (c1 == C1))) || /*(5,4)*/ ((R1 == 5 && C1 == 4) && !(((r1 + c1) == 9) || (r1 == c1 + 1) || (r1 == R1) || (c1 == C1))) || /*(5,5)*/ ((R1 == 5 && C1 == 5) && !(((r1 + c1) == 10) || (r1 == c1) || (r1 == R1) || (c1 == C1))) || /*(5,6)*/ ((R1 == 5 && C1 == 6) && !(((r1 + c1) == 11) || (c1 == r1 + 1) || (r1 == R1) || (c1 == C1))) || /*(5,7)*/ ((R1 == 5 && C1 == 7) && !(((r1 + c1) == 12) || (c1 == r1 + 2) || (r1 == R1) || (c1 == C1))) || /*(6,0)*/ ((R1 == 6 && C1 == 0) && !(((r1 + c1) == 6) || (r1 == c1 + 6) || (r1 == R1) || (c1 == C1))) || /*(6,1)*/ ((R1 == 6 && C1 == 1) && !(((r1 + c1) == 7) || (r1 == c1 + 5) || (r1 == R1) || (c1 == C1))) || /*(6,2)*/ ((R1 == 6 && C1 == 2) && !(((r1 + c1) == 8) || (r1 == c1 + 4) || (r1 == R1) || (c1 == C1))) || /*(6,3)*/ ((R1 == 6 && C1 == 3) && !(((r1 + c1) == 9) || (r1 == c1 + 3) || (r1 == R1) || (c1 == C1))) || /*(6,4)*/ ((R1 == 6 && C1 == 4) && !(((r1 + c1) == 10) || (r1 == c1 + 2) || (r1 == R1) || (c1 == C1))) || /*(6,5)*/ ((R1 == 6 && C1 == 5) && !(((r1 + c1) == 11) || (r1 == c1 + 1) || (r1 == R1) || (c1 == C1))) || /*(6,6)*/ ((R1 == 6 && C1 == 6) && !(((r1 + c1) == 12) || (r1 == c1) || (r1 == R1) || (c1 == C1))) || /*(6,7)*/ ((R1 == 6 && C1 == 7) && !(((r1 + c1) == 13) || (c1 == r1 + 1) || (r1 == R1) || (c1 == C1))) || /*(7,0)*/ ((R1 == 7 && C1 == 0) && !(((r1 + c1) == 7) || (r1 == R1) || (c1 == C1))) || /*(7,1)*/ ((R1 == 7 && C1 == 1) && !(((r1 + c1) == 8) || (r1 == c1 + 6) || (r1 == R1) || (c1 == C1))) || /*(7,2)*/ ((R1 == 7 && C1 == 2) && !(((r1 + c1) == 9) || (r1 == c1 + 5) || (r1 == R1) || (c1 == C1))) || /*(7,3)*/ ((R1 == 7 && C1 == 3) && !(((r1 + c1) == 10) || (r1 == c1 + 4) || (r1 == R1) || (c1 == C1))) || /*(7,4)*/ ((R1 == 7 && C1 == 4) && !(((r1 + c1) == 11) || (r1 == c1 + 3) || (r1 == R1) || (c1 == C1))) || /*(7,5)*/ ((R1 == 7 && C1 == 5) && !(((r1 + c1) == 12) || (r1 == c1 + 2) || (r1 == R1) || (c1 == C1))) || /*(7,6)*/ ((R1 == 7 && C1 == 6) && !(((r1 + c1) == 13) || (r1 == c1 + 1) || (r1 == R1) || (c1 == C1))) || /*(7,7)*/ ((R1 == 7 && C1 == 7) && !((r1 == c1) || (r1 == R1) || (c1 == C1))))
                        {

                            cout << endl;
                            cout << "Invalid! Please Try Again." << endl;
                            cout << endl;
                            cout << "Player 2 your Queen cannot move here!" << endl;
                            cout << endl;
                            cout << "Enter Row : ";
                            cin >> r1;
                            cout << "Enter Column : ";
                            cin >> c1;
                        }

                        system("cls");
                        // exp

                        cout << endl;
                        cout << setw(8);
                        for (i = 0; i < 8; i++)
                        {
                            cout << i << "   ";
                        }
                        cout << endl;

                        // Print rows and board
                        for (i = 0; i < 8; i++)
                        {
                            cout << setw(5) << i << " "; // Print row number

                            for (j = 0; j < 8; j++)
                            {
                                if ((i + j) % 2 == 0)
                                {
                                    cout << "\033[43m"; // Set background color to white
                                }
                                else
                                {
                                    cout << "\033[40m"; // Set background color to black
                                }

                                if (i == r1 && j == c1)
                                {
                                    grid[i][j] = "QN";
                                }

                                else
                                {

                                    grid[i][j] = "  ";
                                }
                                if (i == r2 && j == c2)
                                {
                                    grid[i][j] = "QN";
                                }
                                if (i == r3 && j == c3)
                                {
                                    grid[i][j] = "KG";
                                }
                                /*grid[i][j] = "  ";*/
                                cout << " " << grid[i][j] << " ";
                                cout << "\033[0m"; // Reset background color
                            }
                            cout << endl;
                        }
                    }

                    else if (choice == 2)
                    {
                        R2 = r2;
                        C2 = c2;
                        cout << "Where you want to place your Second Queen in the Grid? (Enter row and column number)" << endl;
                        cout << endl;
                        cout << "Enter Row : ";
                        cin >> r2;
                        cout << "Enter Column : ";
                        cin >> c2;

                        while (!((r2 >= 0 && r2 <= 7) && (c2 >= 0 && c2 <= 7)) || ((r2 == r1 && c2 == c1) || (r2 == r3 && c2 == c3) || (r2 == R2 && c2 == C2)))
                        {
                            cout << endl;
                            cout << "Where you want to move your First Queen in the Grid? (Enter row and column number)" << endl;
                            cout << endl;
                            cout << "Invalid Input! Please Try Again!" << endl;
                            cout << endl;

                            cout << "Enter Row : ";
                            cin >> r2;
                            cout << "Enter Column : ";
                            cin >> c2;
                        }

                        while (/*(0,0)*/ ((R2 == 0 && C2 == 0) && !((r2 == c2) || (r2 == R2) || (c2 == C2))) || /*(0,1)*/ ((R2 == 0 && C2 == 1) && !((r2 == 1 && c2 == 0) || (r2 == 1 && c2 == 2) || (r2 == 2 && c2 == 3) || (r2 == 3 && c2 == 4) || (r2 == 4 && c2 == 5) || (r2 == 5 && c2 == 6) || (r2 == 6 && c2 == 7) || (r2 == R2) || (c2 == C2))) || /*(0,2)*/ ((R2 == 0 && C2 == 2) && !((r2 == 1 && c2 == 1) || (r2 == 2 && c2 == 0) || (r2 == 1 && c2 == 3) || (r2 == 2 && c2 == 4) || (r2 == 3 && c2 == 5) || (r2 == 4 && c2 == 6) || (r2 == 5 && c2 == 7) || (r2 == R2) || (c2 == C2))) || /*(0,3)*/ ((R2 == 0 && C2 == 3) && !((r2 == 3 && c2 == 0) || (r2 == 2 && c2 == 1) || (r2 == 1 && c2 == 2) || (r2 == 1 && c2 == 4) || (r2 == 2 && c2 == 5) || (r2 == 3 && c2 == 6) || (r2 == 4 && c2 == 7) || (r2 == R2) || (c2 == C2))) || /*(0,4)*/ ((R2 == 0 && C2 == 4) && !(((r2 + c2) == 4) || (c2 == r2 + 4) || (r2 == R2) || (c2 == C2))) || /*(0,5)*/ ((R2 == 0 && C2 == 5) && !((r2 == 1 && c2 == 6) || (r2 == 2 && c2 == 7) || ((r2 + c2) == 5) || (r2 == R2) || (c2 == C2))) || /*(0,6)*/ ((R2 == 0 && C2 == 6) && !((r2 == 1 && c2 == 7) || ((r2 + c2) == 6) || (r2 == R2) || (c2 == C2))) || /*(0,7)*/ ((R2 == 0 && C2 == 7) && !(((r2 + c2) == 7) || (r2 == R2) || (c2 == C2))) || /*(1,0)*/ ((R2 == 1 && C2 == 0) && !(((r2 + c2) == 1) || (r2 == c2 + 1) || (r2 == R2) || (c2 == C2))) || /*(1,1)*/ ((R2 == 1 && C2 == 1) && !(((r2 + c2) == 2) || (r2 == c2) || (r2 == R2) || (c2 == C2))) || /*(1,2)*/ ((R2 == 1 && C2 == 2) && !(((r2 + c2) == 3) || (c2 == r2 + 1) || (r2 == R2) || (c2 == C2))) || /*(1,3)*/ ((R2 == 1 && C2 == 3) && !(((r2 + c2) == 4) || (c2 == r2 + 2) || (r2 == R2) || (c2 == C2))) || /*(1,4)*/ ((R2 == 1 && C2 == 4) && !(((r2 + c2) == 5) || (c2 == r2 + 3) || (r2 == R2) || (c2 == C2))) || /*(1,5)*/ ((R2 == 1 && C2 == 5) && !(((r2 + c2) == 6) || (c2 == r2 + 4) || (r2 == R2) || (c2 == C2))) || /*(1,6)*/ ((R2 == 1 && C2 == 6) && !(((r2 + c2) == 7) || (c2 == r2 + 5) || (r2 == R2) || (c2 == C2))) || /*(1,7)*/ ((R2 == 1 && C2 == 7) && !(((r2 + c2) == 8) || (c2 == r2 + 6) || (r2 == R2) || (c2 == C2))) || /*(2,0)*/ ((R2 == 2 && C2 == 0) && !(((r2 + c2) == 2) || (r2 == c2 + 2) || (r2 == R2) || (c2 == C2))) || /*(2,1)*/ ((R2 == 2 && C2 == 1) && !(((r2 + c2) == 3) || (r2 == c2 + 1) || (r2 == R2) || (c2 == C2))) || /*(2,2)*/ ((R2 == 2 && C2 == 2) && !(((r2 + c2) == 4) || (r2 == c2) || (r2 == R2) || (c2 == C2))) || /*(2,3)*/ ((R2 == 2 && C2 == 3) && !(((r2 + c2) == 5) || (c2 == r2 + 1) || (r2 == R2) || (c2 == C2))) || /*(2,4)*/ ((R2 == 2 && C2 == 4) && !(((r2 + c2) == 6) || (c2 == r2 + 2) || (r2 == R2) || (c2 == C2))) || /*(2,5)*/ ((R2 == 2 && C2 == 5) && !(((r2 + c2) == 7) || (c2 == r2 + 3) || (r2 == R2) || (c2 == C2))) || /*(2,6)*/ ((R2 == 2 && C2 == 6) && !(((r2 + c2) == 8) || (c2 == r2 + 4) || (r2 == R2) || (c2 == C2))) || /*(2,7)*/ ((R2 == 2 && C2 == 7) && !(((r2 + c2) == 9) || (c2 == r2 + 5) || (r2 == R2) || (c2 == C2))) || /*(3,0)*/ ((R2 == 3 && C2 == 0) && !(((r2 + c2) == 3) || (r2 == c2 + 3) || (r2 == R2) || (c2 == C2))) || /*(3,1)*/ ((R2 == 3 && C2 == 1) && !(((r2 + c2) == 4) || (r2 == c2 + 2) || (r2 == R2) || (c2 == C2))) || /*(3,2)*/ ((R2 == 3 && C2 == 2) && !(((r2 + c2) == 5) || (r2 == c2 + 1) || (r2 == R2) || (c2 == C2))) || /*(3,3)*/ ((R2 == 3 && C2 == 3) && !(((r2 + c2) == 6) || (r2 == c2) || (r2 == R2) || (c2 == C2))) || /*(3,4)*/ ((R2 == 3 && C2 == 4) && !(((r2 + c2) == 7) || (c2 == r2 + 1) || (r2 == R2) || (c2 == C2))) || /*(3,5)*/ ((R2 == 3 && C2 == 5) && !(((r2 + c2) == 8) || (c2 == r2 + 2) || (r2 == R2) || (c2 == C2))) || /*(3,6)*/ ((R2 == 3 && C2 == 6) && !(((r2 + c2) == 9) || (c2 == r2 + 3) || (r2 == R2) || (c2 == C2))) || /*(3,7)*/ ((R2 == 3 && C2 == 7) && !(((r2 + c2) == 10) || (c2 == r2 + 4) || (r2 == R2) || (c2 == C2))) || /*(4,0)*/ ((R2 == 4 && C2 == 0) && !(((r2 + c2) == 4) || (r2 == c2 + 4) || (r2 == R2) || (c2 == C2))) || /*(4,1)*/ ((R2 == 4 && C2 == 1) && !(((r2 + c2) == 5) || (r2 == c2 + 3) || (r2 == R2) || (c2 == C2))) || /*(4,2)*/ ((R2 == 4 && C2 == 2) && !(((r2 + c2) == 6) || (r2 == c2 + 2) || (r2 == R2) || (c2 == C2))) || /*(4,3)*/ ((R2 == 4 && C2 == 3) && !(((r2 + c2) == 7) || (r2 == c2 + 1) || (r2 == R2) || (c2 == C2))) || /*(4,4)*/ ((R2 == 4 && C2 == 4) && !(((r2 + c2) == 8) || (r2 == c2) || (r2 == R2) || (c2 == C2))) || /*(4,5)*/ ((R2 == 4 && C2 == 5) && !(((r2 + c2) == 9) || (c2 == r2 + 1) || (r2 == R2) || (c2 == C2))) || /*(4,6)*/ ((R2 == 4 && C2 == 6) && !(((r2 + c2) == 10) || (c2 == r2 + 2) || (r2 == R2) || (c2 == C2))) || /*(4,7)*/ ((R2 == 4 && C2 == 7) && !(((r2 + c2) == 11) || (c2 == r2 + 3) || (r2 == R2) || (c2 == C2))) || /*(5,0)*/ ((R2 == 5 && C2 == 0) && !(((r2 + c2) == 5) || (r2 == c2 + 5) || (r2 == R2) || (c2 == C2))) || /*(5,1)*/ ((R2 == 5 && C2 == 1) && !(((r2 + c2) == 6) || (r2 == c2 + 4) || (r2 == R2) || (c2 == C2))) || /*(5,2)*/ ((R2 == 5 && C2 == 2) && !(((r2 + c2) == 7) || (r2 == c2 + 3) || (r2 == R2) || (c2 == C2))) || /*(5,3)*/ ((R2 == 5 && C2 == 3) && !(((r2 + c2) == 8) || (r2 == c2 + 2) || (r2 == R2) || (c2 == C2))) || /*(5,4)*/ ((R2 == 5 && C2 == 4) && !(((r2 + c2) == 9) || (r2 == c2 + 1) || (r2 == R2) || (c2 == C2))) || /*(5,5)*/ ((R2 == 5 && C2 == 5) && !(((r2 + c2) == 10) || (r2 == c2) || (r2 == R2) || (c2 == C2))) || /*(5,6)*/ ((R2 == 5 && C2 == 6) && !(((r2 + c2) == 11) || (c2 == r2 + 1) || (r2 == R2) || (c2 == C2))) || /*(5,7)*/ ((R2 == 5 && C2 == 7) && !(((r2 + c2) == 12) || (c2 == r2 + 2) || (r2 == R2) || (c2 == C2))) || /*(6,0)*/ ((R2 == 6 && C2 == 0) && !(((r2 + c2) == 6) || (r2 == c2 + 6) || (r2 == R2) || (c2 == C2))) || /*(6,1)*/ ((R2 == 6 && C2 == 1) && !(((r2 + c2) == 7) || (r2 == c2 + 5) || (r2 == R2) || (c2 == C2))) || /*(6,2)*/ ((R2 == 6 && C2 == 2) && !(((r2 + c2) == 8) || (r2 == c2 + 4) || (r2 == R2) || (c2 == C2))) || /*(6,3)*/ ((R2 == 6 && C2 == 3) && !(((r2 + c2) == 9) || (r2 == c2 + 3) || (r2 == R2) || (c2 == C2))) || /*(6,4)*/ ((R2 == 6 && C2 == 4) && !(((r2 + c2) == 10) || (r2 == c2 + 2) || (r2 == R2) || (c2 == C2))) || /*(6,5)*/ ((R2 == 6 && C2 == 5) && !(((r2 + c2) == 11) || (r2 == c2 + 1) || (r2 == R2) || (c2 == C2))) || /*(6,6)*/ ((R2 == 6 && C2 == 6) && !(((r2 + c2) == 12) || (r2 == c2) || (r2 == R2) || (c2 == C2))) || /*(6,7)*/ ((R2 == 6 && C2 == 7) && !(((r2 + c2) == 13) || (c2 == r2 + 1) || (r2 == R2) || (c2 == C2))) || /*(7,0)*/ ((R2 == 7 && C2 == 0) && !(((r2 + c2) == 7) || (r2 == R2) || (c2 == C2))) || /*(7,1)*/ ((R2 == 7 && C2 == 1) && !(((r2 + c2) == 8) || (r2 == c2 + 6) || (r2 == R2) || (c2 == C2))) || /*(7,2)*/ ((R2 == 7 && C2 == 2) && !(((r2 + c2) == 9) || (r2 == c2 + 5) || (r2 == R2) || (c2 == C2))) || /*(7,3)*/ ((R2 == 7 && C2 == 3) && !(((r2 + c2) == 10) || (r2 == c2 + 4) || (r2 == R2) || (c2 == C2))) || /*(7,4)*/ ((R2 == 7 && C2 == 4) && !(((r2 + c2) == 11) || (r2 == c2 + 3) || (r2 == R2) || (c2 == C2))) || /*(7,5)*/ ((R2 == 7 && C2 == 5) && !(((r2 + c2) == 12) || (r2 == c2 + 2) || (r2 == R2) || (c2 == C2))) || /*(7,6)*/ ((R2 == 7 && C2 == 6) && !(((r2 + c2) == 13) || (r2 == c2 + 1) || (r2 == R2) || (c2 == C2))) || /*(7,7)*/ ((R2 == 7 && C2 == 7) && !((r2 == c2) || (r2 == R2) || (c2 == C2))))
                        {

                            cout << endl;
                            cout << "H Invalid! Please Try Again." << endl;
                            cout << endl;
                            cout << "Player 2 your Queen cannot move here!" << endl;
                            cout << endl;
                            cout << "Enter Row : ";
                            cin >> r2;
                            cout << "Enter Column : ";
                            cin >> c2;
                        }
                        system("cls");

                        cout << endl;
                        cout << setw(8);
                        for (i = 0; i < 8; i++)
                        {
                            cout << i << "   ";
                        }
                        cout << endl;

                        // Print rows and board
                        for (i = 0; i < 8; i++)
                        {
                            cout << setw(5) << i << " "; // Print row number

                            for (j = 0; j < 8; j++)
                            {
                                if ((i + j) % 2 == 0)
                                {
                                    cout << "\033[43m"; // Set background color to white
                                }
                                else
                                {
                                    cout << "\033[40m"; // Set background color to black
                                }
                                if (i == r1 && j == c1)
                                {
                                    grid[i][j] = "QN";
                                }
                                else
                                {
                                    grid[i][j] = "  ";
                                }
                                if (i == r2 && j == c2)
                                {
                                    grid[i][j] = "QN";
                                }
                                /*else {
                                    grid[i][j] = "  ";
                                }*/
                                if (i == r3 && j == c3)
                                {
                                    grid[i][j] = "KG";
                                }

                                /*grid[i][j] = "  ";*/
                                cout << " " << grid[i][j] << " ";
                                cout << "\033[0m"; // Reset background color
                            }
                            cout << endl;
                        }

                        cout << endl;
                    }

                    // Checkmate

                    // Left corner Checkmate

                    if (r3 == 0)
                    {

                        if (((r1 == r3 || r2 == r3) && ((r1 + 1 == r2) || (r2 + 1 == r1))) /*&& !((r1 != r2) && ((((r3 - 1 != r2) && (c3 - 1 != c2)) || ((r3 + 1 != r2) && (c3 + 1 != c2))) || (((r3 - 1 != r1) && (c3 - 1 != c1)) || ((r3 + 1 != r1) && (c3 + 1 != c1)))))*/)
                        {
                            b = 0;
                            cout << endl;
                            cout << "Checkmate Player 2 has won" << endl;
                            exit(1);
                        }
                    }

                    if (c3 == 0)
                    {

                        if (((c1 == c3 || c2 == c3) && ((c1 + 1 == c2) || (c2 + 1 == c1))) /*&& !((r1 != r2) && ((((r3 - 1 != r2) && (c3 - 1 != c2)) || ((r3 + 1 != r2) && (c3 + 1 != c2))) || (((r3 - 1 != r1) && (c3 - 1 != c1)) || ((r3 + 1 != r1) && (c3 + 1 != c1)))))*/)
                        {
                            b = 0;
                            cout << endl;
                            cout << "Checkmate Player 2 has won" << endl;
                            exit(1);
                        }
                    }

                    if (r3 == 7)
                    {

                        if (((r1 == r3 || r2 == r3) && ((r1 + 1 == r2) || (r2 + 1 == r1))) /*&& !((r1 != r2) && ((((r3 - 1 != r2) && (c3 - 1 != c2)) || ((r3 + 1 != r2) && (c3 + 1 != c2))) || (((r3 - 1 != r1) && (c3 - 1 != c1)) || ((r3 + 1 != r1) && (c3 + 1 != c1)))))*/)
                        {
                            b = 0;
                            cout << endl;
                            cout << "Checkmate Player 2 has won" << endl;
                            exit(1);
                        }
                    }

                    if (c3 == 7)
                    {

                        if (((c1 == c3 || c2 == c3) && ((c1 + 1 == c2) || (c2 + 1 == c1))) /*&& !((r1 != r2) && ((((r3 - 1 != r2) && (c3 - 1 != c2)) || ((r3 + 1 != r2) && (c3 + 1 != c2))) || (((r3 - 1 != r1) && (c3 - 1 != c1)) || ((r3 + 1 != r1) && (c3 + 1 != c1)))))*/)
                        {
                            b = 0;
                            cout << endl;
                            cout << "Checkmate Player 2 has won" << endl;
                            exit(1);
                        }
                    }

                    // player1

                    R3 = r3;
                    C3 = c3;
                    cout << endl;

                    cout << "Player's 1 turn : " << endl;
                    cout << endl;
                    cout << "Player 1 please enter the position of your King (Enter row and column number)" << endl;
                    cout << endl;
                    cout << "Enter Row : ";
                    cin >> r3;
                    cout << "Enter Column : ";
                    cin >> c3;

                    system("cls");

                    //
                    cout << endl;
                    cout << setw(8);
                    for (i = 0; i < 8; i++)
                    {
                        cout << i << "   ";
                    }
                    cout << endl;

                    // Print rows and board
                    for (i = 0; i < 8; i++)
                    {
                        cout << setw(5) << i << " "; // Print row number

                        for (j = 0; j < 8; j++)
                        {
                            if ((i + j) % 2 == 0)
                            {
                                cout << "\033[43m"; // Set background color to white
                            }
                            else
                            {
                                cout << "\033[40m"; // Set background color to black
                            }

                            if (i == r1 && j == c1)
                            {
                                grid[i][j] = "QN";
                            }
                            else
                            {
                                grid[i][j] = "  ";
                            }
                            if (i == r2 && j == c2)
                            {
                                grid[i][j] = "QN";
                            }
                            /*if (i == r3 && j == c3) {
                                grid[i][j] = "RK";
                            }*/
                            if (i == R3 && j == C3)
                            {
                                grid[i][j] = "KG";
                            }

                            /*grid[i][j] = "  ";*/
                            cout << " " << grid[i][j] << " ";
                            cout << "\033[0m"; // Reset background color
                        }
                        cout << endl;
                    }

                    if (((r3 == r1 && c3 == c1) || (r3 == r2 && c3 == c2)) && !((r1 == r2) || (c1 == c2)) /* || !((r1+c1==r2+c2) || (r1+c2==r2+c1)))*/)
                    {

                        cout << endl;
                        cout << setw(8);
                        for (i = 0; i < 8; i++)
                        {
                            cout << i << "   ";
                        }
                        cout << endl;
                        for (i = 0; i < 8; i++)
                        {
                            cout << setw(5) << i << " "; // Print row number

                            for (j = 0; j < 8; j++)
                            {
                                if ((i + j) % 2 == 0)
                                {
                                    cout << "\033[43m"; // Set background color to white
                                }
                                else
                                {
                                    cout << "\033[40m"; // Set background color to black
                                }

                                if (i == r1 && j == c1)
                                {
                                    grid[i][j] = "QN";
                                }
                                else
                                {
                                    grid[i][j] = "  ";
                                }
                                if (i == r2 && j == c2)
                                {
                                    grid[i][j] = "QN";
                                }
                                if (i == r3 && j == c3)
                                {
                                    grid[i][j] = "KG";
                                }

                                /*grid[i][j] = "  ";*/
                                cout << " " << grid[i][j] << " ";
                                cout << "\033[0m"; // Reset background color
                            }
                            cout << endl;
                        }
                        cout << "Game is Tied as One Queen cannot checkmate alone King!" << endl;
                        exit(1);
                    }

                    while ((r3 == r1 || c3 == c1) || (r3 == r2 || c3 == c2) || (r1 == c1 && r3 == c3) || (r2 == c2 && r3 == c3) || (r1 + c1 == r3 + c3) || (r2 + c2 == r3 + c3) || (r1 + c3 == r3 + c1) || (r2 + c3 == r3 + c2) || ((r1 == r2) && ((r3 == r1 && c3 == c1) || (r3 == r2 && c3 == c2))) || ((c1 == c2) && ((r3 == r1 && c3 == c1) || (r3 == r2 && c3 == c2))))
                    {

                        cout << endl;
                        cout << "Invalid! Please Try Again." << endl;
                        cout << endl;
                        cout << "Player 1 your KING cannot move here!" << endl;
                        cout << endl;
                        cout << "Enter Row : ";
                        cin >> r3;
                        cout << "Enter Column : ";
                        cin >> c3;
                    }

                    while (((r3 == r1 || c3 == c1) || (r3 == r2 || c3 == c2)) || (R3 == r3 && C3 == c3))
                    {

                        cout << "Invalid! Please Try Again." << endl;
                        cout << endl;
                        cout << "Player 1 Your King cannot move here!" << endl;
                        cout << endl;
                        cout << "Enter Row : ";
                        cin >> r3;
                        cout << "Enter Column : ";
                        cin >> c3;

                        if ((r3 == r1 && c3 == c1) || (r3 == r2 && c3 == c2))
                        {

                            cout << endl;
                            cout << setw(8);
                            for (i = 0; i < 8; i++)
                            {
                                cout << i << "   ";
                            }
                            cout << endl;
                            for (i = 0; i < 8; i++)
                            {
                                cout << setw(5) << i << " "; // Print row number

                                for (j = 0; j < 8; j++)
                                {
                                    if ((i + j) % 2 == 0)
                                    {
                                        cout << "\033[43m"; // Set background color to white
                                    }
                                    else
                                    {
                                        cout << "\033[40m"; // Set background color to black
                                    }

                                    if (i == r1 && j == c1)
                                    {
                                        grid[i][j] = "QN";
                                    }
                                    else
                                    {
                                        grid[i][j] = "  ";
                                    }
                                    if (i == r2 && j == c2)
                                    {
                                        grid[i][j] = "QN";
                                    }
                                    if (i == r3 && j == c3)
                                    {
                                        grid[i][j] = "KG";
                                    }

                                    /*grid[i][j] = "  ";*/
                                    cout << " " << grid[i][j] << " ";
                                    cout << "\033[0m"; // Reset background color
                                }
                                cout << endl;
                            }
                            cout << "Game is Tied as One Queen cannot checkmate alone King!" << endl;
                            exit(1);
                        }
                    }

                    while (!(((r3 + c3) <= (R3 + C3) + 2) && ((r3 + c3) >= (R3 + C3) - 2) && ((r3 == R3 || r3 == R3 + 1 || r3 == R3 - 1) && (c3 == C3 || c3 == C3 + 1 || c3 == C3 - 1))))
                    {

                        while ((R3 >= 2) && (r3 == 0))
                        {
                            cout << "Invalid! Please Try Again." << endl;
                            cout << endl;
                            cout << "Player 1 Your King cannot move here!" << endl;
                            cout << endl;
                            cout << "Enter Row : ";
                            cin >> r3;
                            cout << "Enter Column : ";
                            cin >> c3;
                        }

                        cout << "Invalid! Please Try Again." << endl;
                        cout << endl;
                        cout << "Player 1 Your King cannot move here!" << endl;
                        cout << endl;
                        cout << "Enter Row : ";
                        cin >> r3;
                        cout << "Enter Column : ";
                        cin >> c3;
                    }

                    system("cls");

                    cout << endl;
                    cout << setw(8);
                    for (i = 0; i < 8; i++)
                    {
                        cout << i << "   ";
                    }
                    cout << endl;

                    // Print rows and board
                    for (i = 0; i < 8; i++)
                    {
                        cout << setw(5) << i << " "; // Print row number

                        for (j = 0; j < 8; j++)
                        {
                            if ((i + j) % 2 == 0)
                            {
                                cout << "\033[43m"; // Set background color to white
                            }
                            else
                            {
                                cout << "\033[40m"; // Set background color to black
                            }

                            if (i == r1 && j == c1)
                            {
                                grid[i][j] = "QN";
                            }
                            else
                            {
                                grid[i][j] = "  ";
                            }
                            if (i == r2 && j == c2)
                            {
                                grid[i][j] = "QN";
                            }
                            if (i == r3 && j == c3)
                            {
                                grid[i][j] = "KG";
                            }

                            /*grid[i][j] = "  ";*/
                            cout << " " << grid[i][j] << " ";
                            cout << "\033[0m"; // Reset background color
                        }
                        cout << endl;
                    }
                }
            }
        }
    }
}

void K_Moves()
{
    int row, col;
    char m_grid[8][8];
    cout << "Enter Initial Position Row & Column Number \n";
    cin >> row >> col;
    cout << "Possible moves of King from [" << row << "][" << col << "] \n";
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            m_grid[i][j] = '.';
            if ((i == row - 1 && j == col) ||     // Up
                (i == row + 1 && j == col) ||     // Down
                (i == row && j == col - 1) ||     // Left
                (i == row && j == col + 1) ||     // Right
                (i == row - 1 && j == col - 1) || // Up-left
                (i == row - 1 && j == col + 1) || // Up-right
                (i == row + 1 && j == col - 1) || // Down-left
                (i == row + 1 && j == col + 1))   // Down-right
            {
                m_grid[i][j] = 'X'; // Valid move
            }
            m_grid[row][col] = 'K';
            cout << m_grid[i][j] << " ";
        }
        cout << endl;
    }
}

void Q_Moves()
{
    int row, col;
    char m_grid[8][8];
    cout << "Enter Initial Position Row & Column Number \n";
    cin >> row >> col;
    cout << "Possible moves of Queen from [" << row << "][" << col << "] \n";
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            m_grid[i][j] = '.';
            if ((i - j == row - col) || (i + j == row + col))
            {
                m_grid[i][j] = 'X'; // Valid move
            }
            int currRow_1 = row, currRow_2 = row;
            while (currRow_1 < 8)
            {
                if (i == currRow_1 && j == col)
                {
                    m_grid[i][j] = 'X'; // Valid move
                }
                currRow_1++;
            }
            while (currRow_2 >= 0)
            {
                if (i == currRow_2 && j == col && (currRow_2 != row))
                {
                    m_grid[i][j] = 'X'; // Valid move
                }
                currRow_2--;
            }
            int currCol_1 = col, currCol_2 = col;
            while (currCol_1 < 8)
            {
                if (i == row && j == currCol_1)
                {
                    m_grid[i][j] = 'X'; // Valid move
                }
                currCol_1++;
            }
            while (currCol_2 >= 0)
            {
                if (i == row && j == currCol_2 && (currCol_2 != col))
                {
                    m_grid[i][j] = 'X'; // Valid move
                }
                currCol_2--;
            }
            m_grid[row][col] = 'Q';
            cout << m_grid[i][j] << " ";
        }
        cout << endl;
    }
}
void B_Moves()
{
    int row, col;
    char m_grid[8][8];
    cout << "Enter Initial Position Row & Column Number \n";
    cin >> row >> col;
    cout << "Possible moves of Bishop from [" << row << "][" << col << "] \n";
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            m_grid[i][j] = '.';
            if ((i - j == row - col) || (i + j == row + col))
            {
                m_grid[i][j] = 'X'; // Valid move
            }
            m_grid[row][col] = 'B';
            cout << m_grid[i][j] << " ";
        }
        cout << endl;
    }
}

void R_Moves()
{
    int row, col;
    char m_grid[8][8];
    cout << "Enter Initial Position Row & Column Number \n";
    cin >> row >> col;
    cout << "Possible moves of Rock from [" << row << "][" << col << "] \n";
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            m_grid[i][j] = '.';
            int currRow_1 = row, currRow_2 = row;
            while (currRow_1 < 8)
            {
                if (i == currRow_1 && j == col)
                {
                    m_grid[i][j] = 'X'; // Valid move
                }
                currRow_1++;
            }
            while (currRow_2 >= 0)
            {
                if (i == currRow_2 && j == col && (currRow_2 != row))
                {
                    m_grid[i][j] = 'X'; // Valid move
                }
                currRow_2--;
            }
            int currCol_1 = col, currCol_2 = col;
            while (currCol_1 < 8)
            {
                if (i == row && j == currCol_1)
                {
                    m_grid[i][j] = 'X'; // Valid move
                }
                currCol_1++;
            }
            while (currCol_2 >= 0)
            {
                if (i == row && j == currCol_2 && (currCol_2 != col))
                {
                    m_grid[i][j] = 'X'; // Valid move
                }
                currCol_2--;
            }
            m_grid[row][col] = 'R';
            cout << m_grid[i][j] << " ";
        }
        cout << endl;
    }
}

void N_Moves()
{
    int row, col;
    char m_grid[8][8];
    cout << "Enter Initial Position Row & Column Number \n";
    cin >> row >> col;
    cout << "Possible moves of Knight from [" << row << "][" << col << "] \n";
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            m_grid[i][j] = '.';
            if ((i == row - 2 && j == col + 1) ||
                (i == row - 2 && j == col - 1) ||
                (i == row + 2 && j == col + 1) ||
                (i == row + 2 && j == col - 1) ||
                (j == col + 2 && i == row + 1) ||
                (j == col + 2 && i == row - 1) ||
                (j == col - 2 && i == row + 1) ||
                (j == col - 2 && i == row - 1))
            {
                m_grid[i][j] = 'X'; // Valid move
            }
            m_grid[row][col] = 'N';
            cout << m_grid[i][j] << " ";
        }
        cout << endl;
    }
}
void emptyGrid()
{
    char grid[9][9] = {
        {' ', '0', '1', '2', '3', '4', '5', '6', '7'},
        {'0', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'1', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'2', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'3', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'4', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'5', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'6', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'7', '.', '.', '.', '.', '.', '.', '.', '.'}};
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
void Grid(string (*grid)[8])
{
    int i, j;
    // string grid[8][8];

    cout << endl;
    cout << setw(8);
    for (i = 0; i < 8; i++)
    {
        cout << i << "   ";
    }
    cout << endl;

    // Print rows and board
    for (i = 0; i < 8; i++)
    {
        cout << setw(5) << i << " "; // Print row number

        for (j = 0; j < 8; j++)
        {
            if ((i + j) % 2 == 0)
            {
                cout << "\033[43m"; // Set background color to white
            }
            else
            {
                cout << "\033[40m"; // Set background color to black
            }
            grid[i][j] = "  ";
            cout << " " << grid[i][j] << " ";
            cout << "\033[0m"; // Reset background color
        }
        cout << endl;
    }
}