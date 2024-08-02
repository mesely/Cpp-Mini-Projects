#include <iostream>
#include <string>
using namespace std;

bool checkFormat(string move)
{
    if (move.length() == 3 && move.at(1) == 45 && isdigit(move.at(0)) == 1 && isdigit(move.at(2)) == 1)
    {
        int yukseklik = atoi(move.substr(0,1).c_str());
        int sira = atoi(move.substr(2,1).c_str());
        if (0<yukseklik && yukseklik <4 && sira<4 && 0<sira )
        {
            return 1;
        }
        else
        {
            cout << "Please enter correct move format!" << endl;
            return 0;
        }
    }
    else
    {
        cout << "Please enter correct move format!" << endl;
        return 0;
    }
}
void print(string (tictactoeBoard)[3][3])
{
    cout << "Current board: " << endl;
    for(int i=0; i<=2; i++)
    {
        for (int j=0; j<=2; j++)
    {
        if (j==0 && j!=2)
        {
            cout << " " << tictactoeBoard[i][j] << " | ";
        }
        else if (j!=2)
        {
            cout << tictactoeBoard[i][j] << " | ";
        }
        else if (j==2)
        {
            cout << tictactoeBoard[i][j];
        }
    }
        if(i!=2)
        {
            cout << endl << "-----------" << endl;
        }
    }
    cout << endl;
}
void playerMove(string pName, string sign, string (tictactoeBoard)[3][3])
{
    string move;
    cout << pName << ", please enter your move: ";
    cin >> move;
    while(checkFormat(move) == 0)
    {
        cout << pName << ", please enter your move: ";
        cin >> move;
    }
    int yukseklik = atoi(move.substr(0,1).c_str());
    int sira = atoi(move.substr(2,1).c_str());
    while(tictactoeBoard[yukseklik-1][sira-1] != " ")
    {
        cout << "That location is already full!" << endl;
        cout << pName << ", please enter your move: ";
        cin >> move;
        while(checkFormat(move) == 0)
        {
            cout << pName << ", please enter your move: ";
            cin >> move;
        }
        yukseklik = atoi(move.substr(0,1).c_str());
        sira = atoi(move.substr(2,1).c_str());
    }
    tictactoeBoard[yukseklik-1][sira-1] = sign;
}
bool checkWinner(string tictactoeBoard[3][3], string sign)
{
    bool exit = false;
    if (tictactoeBoard[0][0] == tictactoeBoard[1][1] &&  tictactoeBoard[1][1] == tictactoeBoard[2][2] && tictactoeBoard[0][0] == tictactoeBoard[2][2] && tictactoeBoard[0][0] == sign)
    {
        exit = true;
    }
    if (tictactoeBoard[0][2] == tictactoeBoard[1][1] &&  tictactoeBoard[1][1] == tictactoeBoard[2][0] && tictactoeBoard[0][2] == tictactoeBoard[2][0] && tictactoeBoard[0][2] == sign)
    {
        exit = true;
    }
    for(int i=0; i<=2; i++)
    {
        if (tictactoeBoard[i][0] == tictactoeBoard[i][1] &&  tictactoeBoard[i][1] == tictactoeBoard[i][2] && tictactoeBoard[i][0] == tictactoeBoard[i][2] && tictactoeBoard[i][0] ==sign)
        {
            exit = true;
        }
    }
    for(int i=0; i<=2; i++)
    {
        if (tictactoeBoard[0][i] == tictactoeBoard[1][i] &&  tictactoeBoard[1][i] == tictactoeBoard[2][i] && tictactoeBoard[0][i] == tictactoeBoard[2][i] && tictactoeBoard[0][i] ==sign)
        {
            exit = true;
        }
    }
    if (exit == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void playGame(string p1Name, string p1Sign, string p2Name, string p2Sign, int & p1Score, int & p2Score, string (tictactoeBoard)[3][3], int &turn)
{
   while(checkWinner(tictactoeBoard, p1Sign) == 0 && checkWinner(tictactoeBoard, p2Sign) == 0)
    {
        bool check = false;
        for (int i=0; i<=2; i++)
        {
            for (int j= 0; j<= 2; j++)
                if(tictactoeBoard[i][j] == " ")
                {
                    check = true;
                }
        }
        if(check==0)
        {
            cout << "The game ended in a draw!" << endl << "Current Scores: " << endl <<p1Name << ": "<< p1Score << "   " <<p2Name << ": " << p2Score <<endl;
            break;
        }
       else if (turn==1 && checkWinner(tictactoeBoard, p2Sign) == 0)
       {
           print(tictactoeBoard);
           playerMove(p1Name, "X", tictactoeBoard);
           turn++;
       }
       else if (turn==2 && checkWinner(tictactoeBoard, p1Sign) == 0)
       {
           print(tictactoeBoard);
           playerMove(p2Name, "O", tictactoeBoard);
           turn--;
       }
   }
    if(checkWinner(tictactoeBoard, p1Sign) == 1)
    {
        p1Score +=1;
        cout << p1Name << " is the winner!" << endl<< "Current Scores: " << endl <<p1Name << ": "<< p1Score
        << "   " <<p2Name << ": " << p2Score<< endl;
    }
    if(checkWinner(tictactoeBoard, p2Sign) == 1)
    {
        p2Score+=1;
        cout << p2Name << " is the winner!" << endl<< "Current Scores: " << endl <<p1Name << ": "<< p1Score
        << "   " <<p2Name << ": " << p2Score << endl;
    }
}
int main()
{
    string p1,p2, tictactoeBoard[3][3];
    int s1=0, s2=0, turn=1;
    cout << "Welcome to Tic-Tac-Toe!" << endl << "Player 1, please enter your name: ";
    cin >> p1;
    cout << "Hello, "<<p1 << ". You are going to play with X" << endl;
    cout << "Player 2, please enter your name: ";
    cin >> p2;
    cout << "Hello, "<<p2 << ". You are going to play with O" << endl;
    cout << endl;
 
    for(int i=0; i<=2; i++)
    {
        for (int j=0; j<=2; j++)
        {
            tictactoeBoard[i][j] = " ";
        }
    }
    cout << "Starting a new game..." << endl;
    playGame(p1, "X", p2, "O", s1, s2, tictactoeBoard, turn);
    for(int i=0; i<=2; i++)
    {
        for (int j=0; j<=2; j++)
        {
            tictactoeBoard[i][j] = " ";
        }
    }
    cout << endl <<"Starting a new game..." << endl;
    turn =2;
    playGame(p1, "X", p2, "O", s1, s2, tictactoeBoard, turn);
    cout << endl <<"Final Scores: " << endl <<p1 << ": "<< s1 << "   " <<p2 << ": " << s2 <<endl;
    if(s1>s2) {cout << p1 << " is the overall winner!" << endl;}
    if(s1<s2) {cout << p2 << " is the overall winner!" << endl;}
    if(s1==s2) {cout << "The overall game ended in a draw!" << endl;}
    return 0;
}

