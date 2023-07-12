#include <iostream>
#include <cstdlib>

using namespace std;

int gametie(string board[9]){   // To check if the game finish with no winner //
if(board[1] != " " && board[2] != " " && board[3] != " " && board[4] != " " && board[5] != " " && board[6] != " " && board[7] != " " && board[8] != " " && board[9] != " "){
    cout << "The game has ended in a tie (cat)" << endl;
    return 1;
   }
}
int winner(string arr[9]){    // To check if computer or player win //
     if(arr[1] == arr[2] &&  arr[2] == arr[3]){
        if(arr[1] == "o"){
            cout << "computer win " <<  endl;
            return 1;
        }else if(arr[1] == "x"){
            cout << "you win" << endl;
            return 1;
        }
    }
     if(arr[4] == arr[5]  && arr[5] == arr[6]){
        if(arr[4] == "o"){
            cout << "computer win " <<  endl;
            return 1;
        }else if(arr[4] == "x"){
            cout << "you win" << endl;
            return 1;
        }
    }
     if(arr[7] == arr[8]  && arr[8] == arr[9]){
        if(arr[7] == "o"){
            cout << "computer win " <<  endl;
            return 1;
        }else if(arr[7] == "x"){
            cout << "you win" << endl;
            return 1;
        }
    }
     if(arr[1] == arr[4]  && arr[4] == arr[7]){
        if(arr[1] == "o"){
            cout << "computer win " <<  endl;
            return 1;
        }else if(arr[1] == "x"){
            cout << "you win" << endl;
            return 1;
        }
    }
     if(arr[2] == arr[5]  && arr[5] == arr[8]){
        if(arr[2] == "o"){
            cout << "computer win " <<  endl;
            return 1;
        }else if(arr[2] == "x"){
            cout << "you win" << endl;
            return 1;
        }
    }
     if(arr[3] == arr[6]  && arr[6] == arr[9]){
        if(arr[3] == "o"){
            cout << "computer win " <<  endl;
            return 1;
        }else if(arr[3] == "x"){
            cout << "you win" << endl;
            return 1;
        }
    }
     if(arr[1] == arr[5]  && arr[5] == arr[9]){
        if(arr[1] == "o"){
            cout << "computer win " <<  endl;
            return 1;
        }else if(arr[1] == "x"){
            cout << "you win" << endl;
            return 1;
        }
    }
     if(arr[3] == arr[5]  && arr[5] == arr[7]){
        if(arr[3] == "o"){
            cout << "computer win " <<  endl;
            return 1;
        }else if(arr[3] == "x"){
            cout << "you win" << endl;
            return 1;
        }
    }
}
void computerturn(string arr[10]){         // computer turn //
     string choice[10] = {"  " , "A1" , "B1" , "C1" , "A2" , "B2" , "C2" , "A3" , "B3" , "C3" };
     int pos = (rand() % 9) + 1;
     if(arr[pos] == " "){
       cout << "computer move(O) : " << choice[pos] << endl << endl;
       arr[pos] = 'o';
     }else{
       computerturn(arr);
}
}
void drawtable(string board[9]){         // To draw the table //
    cout << "    |  A  |  B  |  C  | " << endl << endl;
    cout << " 1  |  " << board[1]  << "  |  " << board[2] << "  |  " << board[3]<<"  |" << endl << endl;
    cout << " ----------------------" << endl << endl;
    cout << " 2  |  " << board[4] << "  |  " << board[5] << "  |  " << board[6] <<"  |" << endl << endl;
    cout << " ----------------------" << endl << endl;
    cout << " 3  |  " << board[7] << "  |  " << board[8] << "  |  " << board[9] <<"  |" << endl << endl;
}
void playerturn(string board[9]){        // Player turn //
    string col;
    cin >> col;
    int counter = 0;
    cout << "Player Move (X):" << col <<endl << endl;
    if(col == "A1" || col == "a1" && board[1] == " " ){
     board[1] = 'x';
    }else if(col == "A2" || col == "a2" && board[4] == " " ){
     board[4] = 'x';
    }else if(col == "A3" || col == "a3" && board[7] == " " ){
     board[7] = 'x';
    }else if(col == "B1" || col == "b1" && board[2] == " " ){
     board[2] = 'x';
    }else if(col == "B2" || col == "b2" && board[5] == " " ){
     board[5] = 'x';
    }else if(col == "B3" || col == "b3" && board[8] == " " ){
     board[8] = 'x';
    }else if(col == "C1" || col == "c1" && board[3] == " " ){
     board[3] = 'x';
    }else if(col == "C2" || col == "c2" && board[6] == " " ){
     board[6] = 'x';
    }else if(col == "C3" || col == "c3" && board[9] == " " ){
     board[9] = 'x';
   }
   else if(col != "A1" && col != "A2" && col != "A3" && col != "B1" && col != "B2" && col != "B3" && col != "C1" && col != "C2" && col != "C3"){
   cout << "Invalid Input: Please enter the column and row of your move (Example: A1)."<< endl;
   playerturn(board);
   }else{
   cout << "The space entered is already taken." << endl;
   playerturn(board);
   }
}
int main(){
  int finishgame = 0;
  int countercomputerturn = 0;
    string board[10] = {" " , " "  , " " , " " , " " , " " , " " , " " , " " , " " } ;
    cout << "************" << endl;
    cout << endl;
    cout << "Tic-Tac-Toe!" << endl;
    cout << endl;
    cout << "************" << endl << endl << endl;
    cout << "Please enter the column and then row of your move." << endl << endl << endl;
    drawtable(board);
    cout << endl << endl;
  do{
   playerturn(board);
   drawtable(board);

   int whowin = winner(board);
   if(whowin == 1){
    finishgame = 1;
   }
   if(countercomputerturn < 4 && finishgame != 1){
    computerturn(board);
    countercomputerturn ++;
   }
   if(finishgame != 1){
   drawtable(board);
   }
   if(finishgame != 1){
   int gamecat = gametie(board);
   if(gamecat == 1){
    finishgame =1;
   }
  }
    }
  while(finishgame != 1);
     return 0 ;
}
