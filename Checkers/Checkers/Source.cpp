#include<iostream>

using namespace std;
bool GameOver;
int black = 12; //beginning number of black checkers
int red = 12; //beginning number of red checkers
class Player //class for both players, setting and displaying scores
{
public:
	void setScore_1(int score_1)
	{
		if (score_1 < 1) 
		{
			black = 0;
			GameOver = true; 
		}
		else
			black = score_1;
	}
	int getScore_1() //display current black score
	{
		if (black == 0) //if all black pieces are lost
		{
			return black;
			cout << "Player 2 wins!";
			return 0;
		}
		else
			cout << "Black: " << black << "\n";
			return black;
	}
	void setScore_2(int score_2)
	{
		if (score_2 < 1) 
		{
			red = 0;
			GameOver = true;
		}
		else
			red = score_2;
	}
	int getScore_2() //display current red score
	{
		if (red == 0) //if all red pieces are lost
		{
			return red;
			cout << "Player 1 wins!";
			return 0;
		}
		else
			cout << "Red: " << red << "\n";
			return red;
	}
};
const int ROWS = 8;
const int COLUMNS = 8;
char Board[ROWS][COLUMNS] = { {'#', 'b', '#' ,'b', '#', 'b', '#', 'b'} , //# is blank
	{'b', '#', 'b', '#', 'b', '#', 'b', '#'} ,
	{'#', 'b', '#' ,'b', '#', 'b', '#', 'b'} ,
	{'#', '#', '#', '#', '#', '#', '#', '#'} ,
	{'#', '#', '#', '#', '#', '#', '#', '#'} ,
	{'r', '#', 'r', '#', 'r', '#', 'r', '#'} ,
	{'#', 'r', '#', 'r', '#', 'r', '#', 'r'} ,
	{'r', '#', 'r', '#', 'r', '#', 'r', '#'}
};
void Instructions()
{
	cout << "Welcome to Checkers! Here's how you play.\n";
	cout << "Player 1 controls the black pieces ('b') and Player 2 controls the red pieces ('r').\n";
	cout << "To select a piece, you must enter which row and column the piece is (starting from 0 to 8).\n";
	cout << "If I wanted to move the first black piece in the top row, I would enter 0 1.\n";
	cout << "I will then move that piece anywhere on the board with a #.\n";
	cout << "You will then mark that piece as a king (B/R) or a pawn(b/r).\n";
	cout << "You will have the opportunity to jump over another player's piece and claim it as your own.\n";
	cout << "Once you see you can, enter 8 8 for your move. You must then enter where you want your piece and the rank.\n";
	cout << "Then you'll have the opportunity to jump by entering where your piece is.\n";
	cout << "Have fun!\n";
}
void Draw()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			cout << Board[i][j];
		}
		cout << endl;
	}
}
void Player1_Move()
{
	int w, x, y, z, J1, J2;
	char rank; // king or pawn
	int j; //multiple jumps
	cout << "Player 1, choose which piece to move: ";
	cin >> w;
	cin >> x;
	if (Board[w][x] == 'r' || Board[w][x] == 'R' || Board[w][x] == '#') //if Player 1 is trying to move a non black piece
	{
		cout << "Invalid move.\n"; //not allowed
		Player1_Move();
	}
		else
	cout << "Now choose which space you want your piece: ";
	cin >> y;
	cin >> z;
	cout << "Enter piece rank: ";
	cin >> rank;
	if (Board[y][z] != '#') //if Player 1 is trying to move their piece to a non blank space
	{
		cout << "Invalid move.\n";
		Player1_Move();
	}
	else
		Board[w][x] = '#';
	if (w == 8 && x == 8) // 8 8 allows player to jump after entering Board[y][z] and rank
	{
		cout << "Jump. Choose which piece to move: ";
		cin >> w;
		cin >> x;
		cout << "How many jumps can you make?";
		cin >> j;
		if (j > 1)
		{
			for (int i = 0; i <= j; i++)
			{
				cout << "Where was the red piece?";
				cin >> J1;
				cin >> J2;
				Board[w][x] = '#';
				Board[y][z] = rank;
				Board[J1][J2] = '#';
				red = red - j;

			}
		}
		else
			if (j = 1)
			{
				cout << "Where was the red piece? ";
				cin >> J1; //jump row
				cin >> J2; //jump column
				Board[w][x] = '#';
				Board[y][z] = rank;
				Board[J1][J2] = '#';
				red--;
			}
	}
	Board[y][z] = rank;
	for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLUMNS; j++)
			{
				cout << Board[i][j];
			}
			cout << endl;
		}
}
void Player2_Move()
{
	int w, x, y, z, J1, J2;
	char rank;
	int j;
	cout << "Player 2, choose which piece to move: ";
	cin >> w;
	cin >> x;
	if (Board[w][x] == 'b' || Board[w][x] == 'B' || Board[w][x] == '#') //if Player 2 is trying to move a non red piece
	{
		cout << "Invalid move.\n"; //not allowed
		Player2_Move();
	}
	cout << "Now choose which space you want your piece: ";
	cin >> y;
	cin >> z;
	cout << "Enter piece rank: ";
	cin >> rank;
	if (Board[y][z] != '#') //if player 2 is trying to move their piece to a non blank space
	{
		cout << "Invalid move.\n"; //not allowed
		Player2_Move();
	}
	else
		Board[w][x] = '#';
	if (w == 8 && x == 8) // 8 8 allows player to jump after entering Board[y][z] and rank
	{
		cout << "Jump. Choose which piece to move: ";
		cin >> w;
		cin >> x;
		cout << "How many jumps can you make?";
		cin >> j;
		if (j > 1)
		{
			for (int i = 0; i <= j; i++)
			{
				cout << "Where was the black piece?";
				cin >> J1;
				cin >> J2;
				Board[w][x] = '#';
				Board[y][z] = rank;
				Board[J1][J2] = '#';
				black = black - j;
			}
		}
		else
			if (j = 1)
			{
				cout << "Where was the black piece? ";
				cin >> J1; //jump row
				cin >> J2; //jump column
				Board[w][x] = '#';
				Board[y][z] = rank;
				Board[J1][J2] = '#';
				black--;
			}
	}
	Board[y][z] = rank;
	for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLUMNS; j++)
			{
				cout << Board[i][j];
			}
			cout << endl;
		}
}
int main()
{
	GameOver = false; //game has begun
	Instructions(); //display instructions for game
	Draw(); //draw the board
	Player Player_1; //instantiate first object as "Player 1"
	Player Player_2; //instantiate second object as "Player 2"
	Player_1.setScore_1(12); //initial score for player 1
	Player_2.setScore_2(12); //initial score for player 2
	while (!GameOver) //while the game is being played, do the following
	{
		Player_1.getScore_1(); //display number of black checkers
		Player_2.getScore_2(); //display red checkers
		Player1_Move();
		Player_1.getScore_1();
		Player_2.getScore_2();
		Player2_Move();
	}
	return 0;
}
