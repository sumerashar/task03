#include <iostream>
using namespace std;

void initializeBoard(char board[3][3]);
void displayBoard(const char board[3][3]);
bool makeMove(char board[3][3], int row, int col, char player);
bool checkWin(const char board[3][3], char player);
bool checkDraw(const char board[3][3]);

int main() {
    char board[3][3];
    char currentPlayer = 'X';
    bool gameWon = false;
    bool draw = false;
    int row, col;

    initializeBoard(board);

    while (!gameWon && !draw) {
        displayBoard(board);
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        if (makeMove(board, row, col, currentPlayer)) {
            gameWon = checkWin(board, currentPlayer);
            if (gameWon) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
            } else {
                draw = checkDraw(board);
                if (draw) {
                    displayBoard(board);
                    cout << "The game is a draw!" << endl;
                } else {
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }
            }
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }

    return 0;
}
void initializeBoard (char board[3][3]) {
	for (int i=0;i<3;	++i){
		for (int j=0;j<3;++j){
			board[i][j]=' ';
		}
	}
}
void displayBoard(const char board[3][3]) {
    cout << "  0   1   2" << endl;
    cout << " +---+---+---+" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << " +---+---+---+" << endl;
    }
}

bool makeMove(char board[3][3], int row, int col, char player) {
	if(row>=0 && row<3 && col >=0&&col<3 &&board[row][col]==' '){
		board[row][col]=player;
		return true ;
	}
	return false;
}
bool checkWin(const char board[3][3], char player){
	//check row and col
	for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
}
 if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}
bool checkDraw(const char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}
