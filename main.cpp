#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
//This array of chars represents the game board, and it holds the content of each square (x,o or empty)
char square[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
//The current player (x or o)
char turn = 'X';
//These variables will hold the number of the row and column selected by the players.
int row;
int column;
//The winner (x, o, t(if it`s a tie) or empty)
char winner = ' ';
//Required variables to check if a move is valid or not
bool validmove;
bool validrow;
bool validcolumn;
//The game loop`s again and again until the game is over
while(winner == ' '){
//Draw the board
cout << "     1   2   3" << endl << "   +---+---+---+" << endl;
for(int i=1;i<4;i++){
cout << " " << i << " | " << square[i-1][0] << " | " << square[i-1][1] << " | " << square[i-1][2] << " |" << endl << "   +---+---+---+" << endl;
}
//Check for an eventual winner of for a tie
for(int i=0;i<3;i++){
if(square[i][0] == square[i][1] && square[i][1] == square[i][2] && square[i][0] != ' '){
winner = square[i][0];
}
}
for(int i=0;i<3;i++){
if(square[0][i] == square[1][i] && square[1][i] == square[2][i] && square[0][i] != ' '){
winner = square[0][i];
}
}
if(square[0][0] == square[1][1] && square[1][1] == square[2][2] && square[0][0] != ' '){
winner = square[0][0];
}
if(square[0][2] == square[1][1] && square[1][1] == square[2][0] && square[0][2] != ' '){
winner = square[0][2];
}
if(square[0][0] == square[0][1] && square[0][1] == square[0][2] && square[0][2] == square[1][0] && square[1][0] == square[1][1] && square[1][1] == square[1][2] && square[1][2] == square[2][0] && square[2][0] == square[2][1] && square[2][1] == square[2][2] && square[0][0] != ' '){
winner = 't';
}
//If somebody won
if(winner == 'X' || winner == 'O'){
//Display congratulations message
cout << "Congratulations! Player ";
if(winner == 'X'){
cout << 1;
}
else{
cout << 2;
}
cout << " is the winner!" << endl;
break;
}
else if(winner == 't'){
//Display a message if it`s tie
cout << "Tie!" << endl;
break;
}
//If the game is not yet over show who`s the next player to move
cout << "Player ";
if(turn == 'X'){
cout << 1;
}
else{
cout << 2;
}
cout << "'s turn:" << endl;
//Loop until the player selects a valid square
validmove = false;
while(!validmove){
validrow = false;
//Loop until the player selects a valid row
while(!validrow){
cout << "Row: ";
cin >> row;
if(row == 1 || row == 2 || row == 3){
validrow = true;
}
else{
cout << endl << "Invalid row!" << endl;
}
}
validcolumn = false;
//Loop until the player selects a valid column
while(!validcolumn){
cout << "Column: ";
cin >> column;
if(column == 1 || column == 2 || column == 3){
validcolumn = true;
}
else{
cout << endl << "Invalid column!" << endl;
}
}
//Change the turn to the next player
if(square[row-1][column-1] == ' '){
square[row-1][column-1] = turn;
validmove = true;
if(turn == 'X'){
turn = 'O';
}
else{
turn = 'X';
}
}
//If the selected square is occupied display a message and loop again
else{
cout << "The selected square is occupied!" << endl << "Select again:" << endl;
}
}
}
system("pause");
}
