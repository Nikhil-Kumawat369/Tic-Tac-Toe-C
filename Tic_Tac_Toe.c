#include <stdio.h>
#include <string.h>

void Rules () ;
void Print_Board (char board[]) ;
void Clear_Buffer_Completely () ;

int main () {

    Rules () ;

    // Taking Players Name As Input

    char player1[50] , player2[50] ;

    printf("\n=========================================\n");
    printf("           PLAYER SETUP\n");
    printf("=========================================\n\n");

    printf("Enter name for Player 1 (X): ");
    scanf("%49s", player1);

    printf("Enter name for Player 2 (O): ");
    scanf("%49s", player2);

    printf("\n=========================================\n");
    printf("        PLAYERS REGISTERED!\n");
    printf("=========================================\n\n");

    printf("Player 1 (X) : %s\n", player1);
    printf("Player 2 (O) : %s\n", player2);
    getchar() ;

    printf("\n=========================================\n");
    printf("        GET READY TO PLAY!\n");
    printf("=========================================\n\n");

    // -------------Over-------------

    char board[9] = {'1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9'} ;
    int Winner = 100 ; // stores who is winner , if X wins its 0 , if O wins its 1 , And if its a draw the it will be 100 {non affected & unchanged}

    int Win_Condition[8][3] = { {0,1,2} , {3,4,5} , {6,7,8} , {0,3,6} , {1,4,7} , {2,5,8} , {0,4,8} , {2,4,6} } ; // Win condition position for all

    int index ;

    Print_Board(board) ;

    for(int i = 1 ; i <= 9 ; i++) {

        char a ; // Stores Players Responce

        if(i%2 == 1) { // Player 1 Turn (X)

            printf("\n=========================================\n");
            printf("          %s's TURN (X)\n", player1);
            printf("=========================================\n");

            printf("Make your move!\n");
            printf("Choose a position (1 - 9) to place your mark: ");
            scanf(" %c" , &a) ;
            Clear_Buffer_Completely () ; // Clears The buffer completely

            // -------------Over-------------

            // It Will Check if the move is legal or not And ristrict players from entering illegal moves

            // i fucked up so bad while checking the condition Reason :- i forgot its not "int" its "char"
            // (board[a-1] == 'X' || board[a-1] == 'O' || a < 1 || a > 9)

            while(a < '1' || a > '9' || board[a-'1'] == 'X' || board[a-'1'] == 'O') {

                printf("\n  Invalid move!\n");
                printf("That is an illegal position.\n");
                printf("Please choose another position.\n\n");

                printf("Make your move!\n");
                printf("Choose a position (1 - 9) to place your mark: ");
                scanf(" %c" , &a) ;
                Clear_Buffer_Completely () ; // Clears The buffer completely

            }

            // -------------Over-------------

            // Updates the value of the board

            index = a - '1'; // converts '1'..'9' -> 0..8
            board[index] = 'X';       // or 'O'

            // -------------Over-------------

            Print_Board(board) ;
            
            // Checks Win Condition

            for(int j = 0 ; j < 8 ; j++) {

                if(board[Win_Condition[j][0]] == board[Win_Condition[j][1]] && board[Win_Condition[j][1]] == board[Win_Condition[j][2]]) {

                    Winner = 0 ;
                    break ; // remember u lerned this , this break will only exit the j loop and not i loop , recall it 

                }

            }

            if(Winner == 0) {

                break ;

            }

            // -------------Over-------------

        }else { // Player 2 Turn (X)

            printf("\n=========================================\n");
            printf("          %s's TURN (O)\n", player2);
            printf("=========================================\n");

            printf("Make your move!\n");
            printf("Choose a position (1 - 9) to place your mark: ");
            scanf(" %c" , &a) ;
            Clear_Buffer_Completely () ; // Clears The buffer completely

            // -------------Over-------------

            // It Will Check if the move is legal or not And ristrict players from entering illegal moves

            while(a < '1' || a > '9' || board[a-'1'] == 'X' || board[a-'1'] == 'O') {

                printf("\n  Invalid move!\n");
                printf("That is an illegal position.\n");
                printf("Please choose another position.\n\n");

                printf("Make your move!\n");
                printf("Choose a position (1 - 9) to place your mark: ");
                scanf(" %c" , &a) ;
                Clear_Buffer_Completely () ; // Clears The buffer completely

            }

            // -------------Over-------------

            // Updates the value of the board

            index = a - '1'; // converts '1'..'9' -> 0..8
            board[index] = 'O';       // or 'X'

            // -------------Over-------------

            Print_Board(board) ;

            // Checks Win Condition

            for(int j = 0 ; j < 8 ; j++) {

                if(board[Win_Condition[j][0]] == board[Win_Condition[j][1]] && board[Win_Condition[j][1]] == board[Win_Condition[j][2]]) {

                    Winner = 1 ;
                    break ; // remember u lerned this , this break will only exit the j loop and not i loop , recall it

                }

            }

            if(Winner == 1) {

                break ;

            }

            // -------------Over-------------

        }

    }

    // Now seing the Winner variable value & deciding who won Or draw

    if(Winner == 0) {

    printf("\n=========================================\n");
    printf("        # CONGRATULATIONS! #\n");
    printf("=========================================\n");
    printf("%s (X) WINS THE GAME!\n", player1);
    printf("=========================================\n\n");

    }else if(Winner == 1) {

    printf("\n=========================================\n");
    printf("        # CONGRATULATIONS! #\n");
    printf("=========================================\n");
    printf("%s (O) WINS THE GAME!\n", player2);
    printf("=========================================\n\n");

    }else{

    printf("\n=========================================\n");
    printf("            GAME DRAW  \n");
    printf("=========================================\n");
    printf("No more moves left.\n");
    printf("Well played, %s and %s!\n", player1, player2);
    printf("=========================================\n\n");


    }

    // -------------Over-------------

    return 0 ;

}

void Rules () {

    printf("\n=========================================\n");
    printf("        WELCOME TO TIC TAC TOE\n");
    printf("=========================================\n\n");

    printf("OBJECTIVE:\n");
    printf("Be the first player to get THREE marks\n");
    printf("in a straight line.\n");
    printf("(Horizontal, Vertical, or Diagonal)\n\n");

    printf("PLAYERS:\n");
    printf("Player 1  ->  X\n");
    printf("Player 2  ->  O\n\n");

    printf("GAME BOARD POSITIONS:\n\n");
    printf(" 1 | 2 | 3 \n");
    printf("---+---+---\n");
    printf(" 4 | 5 | 6 \n");
    printf("---+---+---\n");
    printf(" 7 | 8 | 9 \n\n");

    printf("HOW TO PLAY:\n");
    printf("- Players take turns.\n");
    printf("- Enter a number (1-9) to place your mark.\n");
    printf("- You cannot choose an occupied position.\n\n");

    printf("IMPORTANT INPUT RULE:\n");
    printf("- Only the FIRST character of your input is concidered as your move.\n");
    printf("- Extra characters are ignored.\n\n");

    printf("EXAMPLES:\n");
    printf("- Input: 4890        -> Move taken as: 4\n");
    printf("- Input: 4877abc     -> Move taken as: 4\n");
    printf("- Input: 5xyz        -> Move taken as: 5\n");
    printf("- Input: abc         -> Invalid move\n\n");

    printf("WIN CONDITION:\n");
    printf("- First player to align 3 marks wins.\n\n");

    printf("DRAW CONDITION:\n");
    printf("- If all positions are filled and\n");
    printf("  no player wins, the game is a DRAW.\n\n");

    printf("=========================================\n");
    printf("        LET THE GAME BEGIN!\n");
    printf("=========================================\n\n");

}

void Print_Board (char board[]) {

    printf("\nCurrent Board:\n\n");

    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);

    printf("\n");

}

void Clear_Buffer_Completely () {

    char a ;

    while((a = getchar()) != '\n' && a != EOF) ;

}