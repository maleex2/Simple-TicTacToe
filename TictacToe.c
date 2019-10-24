/**************************************************************************
 * Assessment Title:
 *
 * Number of Submitted C Files: 1
 *
 * Date: 28.10.2018
 *
 * 
 * Author: Martin Aleksandrov, Reg no: 201747078
 *
 *
 * Personal Statement: I confirm that this submission is all my own work.
 *
 *          (Signed)______Martin Georgiev Aleksandrov_______
 *
 * 
 *
 **************************************************************************/


/********************************************************************************

Implemented all functions, including bonus problem. 

No global variables used but the the board contains values required for checking.
	They are not shown.

Due of the fact the computer_move() simulates move using random number from 1 to 9, 
it may need some time if the position of the number may be already used.
I preffered it to just picking the next available or doing something too complicated.


When compiling, I have used the command:
gcc -std=c99 -Wall -pedantic ace2.c -o ace2
*********************************************************************************/
#include <stdio.h>

int main()
{
	char *a1, *p1, *p2,*n1, *n2,*nc, *m1, *m2, *m3, *ep, *ea;
	char answer1[1];
	char player1[1];
	char player2[1];
	char gaming[1];
	char nick1[50];
	char nick2[50];
	static char nickCpu[10] = "Cpu";
	static char mes1[] = "Press 'p' for player vs player or 'c' for player vs computer\n";
	static char mes2[] = "Choose X or O\n";
	static char mes3[] = "enter a cool nickname\n";
	static char exit_program[] = " Type 'y' if you want to end the game now?\n If you want to continue playing press any button and the Enter\n";
	

int mode=2, mark=2;	/* mode=0 PvP; mode=1 PvComputer; */

char board[4][3]; 	/* board needs 1 more row to store values required to check if moves are valid and if the game has finished */
	
int i,j; 		/* loop variables */
	
int play=1; 		/* 1 -> game running; 0 -> game was won; -1 -> tie */
	
int wins1=0, wins2=0; 	/* stores the points for each player */
	
int continue_playing=1; /* main check for bonus problem */
	
	a1 = answer1;   /* used in user_prompt() */
	p1 = player1;	/* used in user_prompt() */
	p2 = player2;	/* used in user_prompt() */
	n1 = nick1;	/* used in user_prompt() */
	n2 = nick2;	/* used in user_prompt() */
	nc = nickCpu;	/* used in user_prompt() */
	m1 = mes1;	/* used in user_prompt() */
	m2=mes2;	/* used in user_prompt() */
	m3=mes3;	/* used in user_prompt() */
	
	ep=exit_program; /* for the bonus problem */
	ea=gaming;	 /* for the bonus problem */

	int player = 0;	
	
	do{
		user_prompt(m1,a1);
		if(*a1 == 'p'||*a1 == 'P'){
			printf("Player vs Player mode\n");
			mode=0;
		}
		else if (*a1 =='c'||*a1 == 'C'){
			printf("Player vs Computer mode\n");
			mode=1;
		}
		else{
			printf("ALERT! Wrong input. Try again:\n");
		}
	}
	while (mode==2);


	do{
		user_prompt(m2,p1);
		if(*p1 == 'X' || *p1 == 'x'){
			printf("You have chosen X!\n");
			mark=1;
			*p2='O';
		}
		else if (*p1 =='O' || *p1 =='o'){
			printf("You have chosen O!\n");
			mark=1;
			*p2='X';
		}
		else{
			printf("Alert! Wrong input. Try again:\n");
		}
	}




while (mark==2);

	printf("Player 1, ");
	user_prompt(m3,n1);
	
	printf("Player 1 is now named %s\n",n1);
	if(mode == 0){
		printf("Player 2, ");
		user_prompt(m3,n2);
		printf("Player 2 is now named %s\n",n2);
}

while(continue_playing==1){
	play=1;
	player=0;
	board[3][1]=='c';

	
	clear_board(board);
	display_board(board);

if(mode==1)
{  				/* PLAYER VS COMPUTER */	
	while(play==1)
	{
		player++;
		player = (player % 2) ? 1 : 2;
		printf("player %d's turn:\n",player);
		
	
		mark = (player == 1) ? *p1 : *p2;
		
		if (player==1){
			user_move(board);
			if(board[3][2]!='!')
			{
				player--;
				board[3][2]='!';				
			}
			else 
			{
				for(i=0;i<3;i++){
					for(j=0;j<3;j++){
						if(board[i][j]=='?'){	
							board[i][j]=*p1;
						}		
					}
				}
			}
		}
		else if (player==2)
		{
			computer_move(board);
			for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					if(board[i][j]=='?'){	
						board[i][j]=*p2;
					}		
				}
			}
	
		}
		display_board(board);
		detect_win(board); 

		if(board[3][1]=='w'){
			play=0; /* someone has won */
		}
		if(board[3][1]=='t'){
			play=-1; /* tie */
		}
	}
}






if(mode==0)
{     					/* PLAYER VS PLAYER */	
	while(play==1)
	{
		
		player++;
		player = (player % 2) ? 1 : 2;
		printf("player %d's turn:\n",player);
	
		mark = (player == 1) ? *p1 : *p2;
	
		user_move(board);
		if(board[3][2]!='!')
		{
			player--;
			board[3][2]='!';				
		}
		else {
			for(i=0;i<3;i++){
				for(j=0;j<3;j++){
					if(board[i][j]=='?'){
						if(player==1){
							board[i][j]=*p1;
						}
						else if(player==2){
							board[i][j]=*p2;
					
						}
					}
				
				}
			}
		}
		display_board(board);
		detect_win(board); 

		if(board[3][1]=='w'){
			play=0; /* somebody has won */
		}
		if(board[3][1]=='t'){
			play=-1; /* tie */
		}
		
		
	}
}

if(play==0)
{
	if(mode==0){
	if(player==1){
		printf("%s you won!\n",n1);
		wins1++;
		printf(" Result is %d : %d\n",wins1,wins2);
		play=1;
	}
	else {
		printf("%s you won\n",n2);
		wins2++;
		printf(" Result is %d : %d\n",wins1,wins2);
		play=1;
	}
	}
	else if(mode==1){
	if(player==1){
		printf("%s you won!\n",n1);
		wins1++;
		printf(" Result is %d : %d\n",wins1,wins2);
		play=1;
	}
	else {
		printf("%s you won!\n",nc);
		wins2++;
		printf(" Result is %d : %d\n",wins1,wins2);
		play=1;
	}
}
}

/* decided to give them both points if a game is tie */
else if(play==-1) {
	printf("\nTie!\n");
	wins1++;
	wins2++;
	printf(" Result is %d : %d\n",wins1,wins2);
	play=1;
		
}

/* bonus question. */
user_prompt(ep, ea);
	if(*ea=='Y' || *ea=='y'){
		continue_playing=0;
	}
	else {
		printf("\nNew game\n");
	}
}
	printf("\nEnd of the game. Result is %d : %d\n",wins1,wins2);
}
void user_prompt(char *message, char *answer){
	printf("%s",message);
	scanf("%s",answer);
	
}
void clear_board(char board[4][3]){

	int i =0,j=0,num=-1;
	char a[]={'a','b','c','d','e','f','g','h','i'};
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			num++;
			board[i][j]=a[num];
		}
	}
	board[3][2]='!'; 	/* used when checking if the move is valid */
	board[3][1]='c'; 	/* used to check if the game has been ended (win,tie) */
	
}

void display_board(char board[4][3])
{

    printf("\n\n\tTic Tac Toe\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[0][0], board[0][1], board[0][2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", board[1][0], board[1][1], board[1][2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", board[2][0], board[2][1], board[2][2]);

    printf("     |     |     \n\n\n");
}


void user_move(char board[4][3]){

/* if move is invalid, change board[3][2] to something different from '!' 
	to show the move was invalid */


	char move;
	printf("\nPlease enter your move: \n");
	scanf(" %c",&move);
		
	if(move== 'a' && board[0][0]=='a'){
		board[0][0]='?';
	}
	else if(move=='b' &&  board[0][1]=='b'){
		board[0][1]='?';
	}
	else if(move=='c' && board[0][2]=='c'){
		board[0][2]='?';
	}
	else if(move=='d' && board[1][0]=='d'){
		board[1][0]='?';
	}
	else if(move=='e' && board[1][1]=='e'){
		board[1][1]='?';
	}
	else if(move=='f' && board[1][2]=='f'){
		board[1][2]='?';
	}
	else if(move=='g' && board[2][0]=='g'){
		board[2][0]='?';
	}
	else if(move=='h' && board[2][1]=='h'){
		board[2][1]='?';
	}
	else if(move=='i' && board[2][2]=='i'){
		board[2][2]='?';
	}
	else{
		printf("\nInvalid move\n");
		board[3][2]=move;             
	}
	
}


void computer_move(char board[4][3])
{
	int done=0;
do{	
	srand(time(NULL));   
	int r=rand() % 9+1;

	if(r== 1 && board[0][0]=='a'){
		board[0][0]='?';
		done=1;
	}
	else if(r== 2 &&  board[0][1]=='b'){
		board[0][1]='?';
		done=1;
	}
	else if(r==3 && board[0][2]=='c'){
		board[0][2]='?';
		done=1;
	}
	else if(r== 4 && board[1][0]=='d'){
		board[1][0]='?';
		done=1;
	}
	else if(r== 5 && board[1][1]=='e'){
		board[1][1]='?';
		done=1;
	}
	else if(r== 6 && board[1][2]=='f'){
		board[1][2]='?';
		done=1;
	}
	else if(r== 7 && board[2][0]=='g'){
		board[2][0]='?';
		done=1;
	}
	else if(r== 8 && board[2][1]=='h'){
		board[2][1]='?';
		done=1;
	}
	else if(r== 9 && board[2][2]=='i'){
		board[2][2]='?';
		done=1;
	}
	
	
}while(done==0);
}


void detect_win(char board[4][3]) 
{
	char result;
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2]) {
        result = 'w';
        }
    else if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        result = 'w';
        }
    else if (board[0][0] == board[1][0] && board[1][0] == board[2][0]){
        result = 'w';
        }
    else if (board[0][2] == board[1][2] && board[1][2] == board[2][2]){
        result = 'w';
        }
    else if (board[2][0] == board[2][1] && board[2][1] == board[2][2]){
      result = 'w';
        }
    else if (board[0][2] == board[1][1] && board[1][1] == board[2][0]){
       result = 'w';
        }
    else if (board[1][0] == board[1][1] && board[1][1] == board[1][2]){
       result = 'w';
        }
    else if (board[0][1] == board[1][1] && board[1][1] == board[2][1]){
        result = 'w';
        }
    else if (board[0][0] != 'a' && board[0][1] != 'b' && board[0][2] != 'c' &&
        board[1][0] != 'd' && board[1][1] != 'e' && board[1][2] != 'f' && board[2][0] 
        != 'g' && board[2][1] != 'h' && board[2][2] != 'i')
	{
        		result = 't';     /* tie */
	}    
    else{
        		result = 'c';     /* game running */
	}
	
	if(result=='w'){
		board[3][1]='w';
	}
	else if(result=='t'){
		board[3][1]='t';
	}
		
}
