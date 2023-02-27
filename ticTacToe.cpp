#include<iostream>
#include<vector>
using namespace std;

//prints the tic-tac-toe board
void printBoard(vector<vector<char>> board){
    cout<<"\t\t\t _"<<board[0][0]<<"|_"<<board[0][1]<<"|_"<<board[0][2]<<endl;
    cout<<"\t\t\t _"<<board[1][0]<<"|_"<<board[1][1]<<"|_"<<board[1][2]<<endl;
    cout<<"\t\t\t  "<<board[2][0]<<"| "<<board[2][1]<<"| "<<board[2][2]<<endl;
}

//Clears the gameboard by setting value at each place= ' ' 
void clearBoard(vector<vector<char>> &board){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            board[i][j]=' ';
    }
    }
}

//takes user input 
bool userInput(int player, int playerMove,vector<vector<char>> &board){
    if(playerMove>9){
        return false;
    }
    char inputSymbol;
    player==1? inputSymbol='X': inputSymbol='O';
    char boardVal = board[(playerMove-1)/3][(playerMove-1)%3];
    if( boardVal == ' '){
        board[(playerMove-1)/3][(playerMove-1)%3]=inputSymbol;
        return true;
    } 
    else{
        return false;
    }
}

int checkWin(vector<vector<char>> board){
    int winner=-1;

    if((board[1][1]=='X' || board[1][1]=='O') && ((board[1][1]==board[0][0] && board[1][1]==board[2][2])||(board[0][2]==board[1][1] && board[1][1]==board[2][0]))){
        if(board[1][1]=='X'){
            winner=1;}
        else{winner=2;}
        cout<<winner;
        return winner;
    }
    for(int i=0; i<3; i++){
        
       
            if(board[i][0]==board[i][1] && board[i][0]==board[i][2] && board[i][0]!=' ' ){
                board[i][0]=='X'?winner=1:winner=2;
                return winner;
            }    
        }
    
    for(int i=0; i<3; i++){
       
        
           if(board[0][i]==board[1][i] && board[0][i]==board[2][i] && board[0][i]!=' ' ){
                board[0][i]=='X'?winner=1:winner=2;
                return winner;
            }   
    }
    return -1;

}

bool gameOver(int turn, vector<vector<char>> board){
    if(checkWin(board)==1 || checkWin(board)==2 || turn>9){
        return true;
    }
    return false;
}

void printScoreBoard(vector<pair<string,int>> scoreBoard){
    cout<<"\t\t\t Score Board\n"<<endl;
    cout<<"\t |-----------------------|-----------------------|"<<endl;
    cout<<"\t |    "<<scoreBoard[0].first<<"    |    "<<scoreBoard[1].first<<"    |"<<endl;
    cout<<"\t |-----------------------|-----------------------|"<<endl;
    cout<<"\t |         "<<scoreBoard[0].second<<"\t\t |         "<<scoreBoard[1].second<<"             |"<<endl;
    cout<<"\t |-----------------------|-----------------------|"<<endl;
}



int main(){

    cout<<"\t\t\t Tic-Tac-Toe\n";
    string player1;
    string player2;

    cout<<"Enter name of player 1 : "<<endl;
    cin>>player1;
    
    cout<<"Enter name of player 2 : "<<endl;
    cin>>player2;

    vector<pair<string,int>> scoreboard={{player1,0},{player2,0}};
    scoreboard[0].first.resize(15,' ');
    scoreboard[1].first.resize(15,' ');
    

    vector<vector<char>> board(3, vector<char>(3,' '));
    printBoard(board);
    int playerMove;
    int i=1;
    while(!gameOver(i,board)){
        if(i%2==1){
            cout<<player1 <<" please enter your move "<<endl;
        }else{
            cout<<player2 <<" please enter your move "<<endl;
        }
        cin>>playerMove;
        if(userInput(i%2,playerMove,board)){
            int win = checkWin(board);
            if(win==1){
                cout<<player1<<" is winner "<<endl;
                scoreboard[0].second++;
                i=10;
                
            }
            else if(win==2){
                cout<<player2<<" is winner "<<endl;
                scoreboard[1].second++;
                i=10;
               
            }
            else if(win==-1 && i==9){
                cout<<"Its a draw "<<endl;
                
                i++;
                
            }
            if(i==10){
                string playAgain;

                printScoreBoard(scoreboard);
                cout<< "Would you like to play again(Y,N)?"<<endl;
                cin>>playAgain;
                if(playAgain[0]=='Y'|| playAgain[0]=='y'){
                    clearBoard(board);
                    i=0;
                } 
            }
            i++;
        }
        else{
            cout<<"Wrong move!!!"<<endl;
        }
        printBoard(board);
    }


    return 0;
}