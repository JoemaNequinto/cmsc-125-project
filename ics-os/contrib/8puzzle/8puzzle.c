#include "../../sdk/dexsdk.h"
#include "../../sdk/time.h"

void setup_difficulty(); //self explanatory
void print_board(int x, int y); //set up initial board
void update_board();
void erase(); //covers an area with a black rectangle

/* constants */
#define easyrow 3
#define easycol 3
#define mediumrow 4
#define mediumcol 4
#define hardrow 5
#define hardcol 5

#define start '1'
#define quit_game '2'
#define easy 'e'
#define medium 'm'
#define hard 'h'
#define back 'b'

#define up_key 'w'
#define down_key 's'
#define left_key 'a'
#define right_key 'd'

#define quit 'x'
#define reset 'r'
#define yes 'y'
#define no 'n'

#define WHITE 63
#define X_coord 85
#define Y_coord 35

/* global variables */
int difficulty, moves = 0;
int board[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
int row0, col0;

int main(){

	char keypress = start;
	int i, j;
	char str[15];
	
	set_graphics(VGA_320X200X256);
	
	do{
		erase(1, 1, 400, 220);

		header(); //print menu
		
		keypress = (char) getch();
		erase(1, 1, 400, 220); //erase menu

		if(keypress == start){
			
			do{
				erase(1, 1, 400, 220); //erase submenu
				subheader();
				keypress = (char) getch();
				erase(1, 1, 400, 220); //erase submenu
				
				if(keypress == easy){
					
					do{
						if (keypress == easy){
							difficulty = 1; //initialize difficulty
							moves = 0;
							erase(1, 1, 400, 220);
							setup_difficulty();
							erase(190, 150, 20, 20);
							write_text("0", 190, 150, WHITE, 0);
						}



						do {
							if (keypress = (char)getch()){
								if (keypress == right_key){
									if (col0 != 2){
										moves++;
										erase(190, 150, 20, 20);
										sprintf(str, "%d", moves);
										write_text(str, 190, 150, WHITE, 0);

										swapTile(row0, col0, row0, col0 + 1);
										update_board(120, 55);
									}
								} else if (keypress == left_key){
									if (col0 != 0){
										moves++;
										erase(190, 150, 20, 20);
										sprintf(str, "%d", moves);
										write_text(str, 190, 150, WHITE, 0);
										
										swapTile(row0, col0, row0, col0 - 1);
										update_board(120, 55);
									}
								} else if (keypress == up_key){
									if (row0 != 0){
										moves++;
										erase(190, 150, 20, 20);
										sprintf(str, "%d", moves);
										write_text(str, 190, 150, WHITE, 0);
										
										swapTile(row0, col0, row0 - 1, col0);
										update_board(120, 55);
									}
								} else if (keypress == down_key){
									if (row0 != 2){
										moves++;
										erase(190, 150, 20, 20);
										sprintf(str, "%d", moves);
										write_text(str, 190, 150, WHITE, 0);
										
										swapTile(row0, col0, row0 + 1, col0);
										update_board(120, 55);
									}
								}

								if (goalTest() == 1){
									keypress = (char) getch();
									keypress = easy;
									break;
								}
							}
						} while (keypress != quit && keypress != reset);	
						//continue while player is not quitting, restarting or champion
					
						if (keypress == quit){
							//prompt confirmation then erase message
							erase(120, 180, 40, 40);
							write_text("Do you want to exit? y/n ", 50, 180, WHITE, 0); 
							keypress = (char) getch();
							erase(50, 180, 220, 40);	
						} else if (keypress == reset){
							//prompt confirmation then erase message
							erase(120, 180, 40, 40);
							write_text("Do you want to restart? y/n ", 35, 180, WHITE, 0);
							keypress = (char) getch();
							if (keypress == yes) keypress = easy;
							erase(35, 180, 240, 40);	
						}

					} while (keypress != yes);

				}

				else if(keypress == medium){
					
					difficulty = 2; //initialize difficulty
					setup_difficulty();
					//update level display
					erase(25, 125, 40, 30);
					write_text("0", 190, 150, WHITE, 0);
				}

				else if(keypress == hard){
					
					difficulty = 3; //initialize difficulty
					setup_difficulty();
					//update level display
					erase(25, 125, 40, 30);
					write_text("0", 190, 150, WHITE, 0);
				}

				else 
					continue;

			} while (keypress != back);
		}
	} while (keypress != quit_game);

	set_graphics(VGA_TEXT80X25X16);
	clrscr();
}

void swapTile(int r1, int c1, int r2, int c2){
	int temp = board[r1][c1];
	board[r1][c1] = board[r2][c2];
	board[r2][c2] = temp;
}


void randomizeBoard(){
	board[0][0] = 5;
	board[0][1] = 1;
	board[0][2] = 3;
	board[1][0] = 2;
	board[1][1] = 0;
	board[1][2] = 8;
	board[2][0] = 4;
	board[2][1] = 6;
	board[2][2] = 7;
}

void setup_difficulty(){

	switch(difficulty){
	
		case 1:
			randomizeBoard();
			print_board(120, 55);
			break;

		case 2:
			break;
	
		case 3:
			break;

	}	
	
}

void print_square(int r, int c, int x, int y){
	char str[15];

	if (board[r][c] != 0){
		sprintf(str,"%d",board[r][c]);
		write_text(str,x,y,WHITE,0);
	} else {
		row0 = r;
		col0 = c;
		write_text(" ",x,y,WHITE,0);
	}
}

void print_board(int x, int y){ //set up initial board 

	int i, j, a, b;
	a = x;
	b = y;
	char str[15];

	//display level
	if (difficulty == 1){
		write_text("8 PUZZLE", 120, 5, WHITE, 0);
	} else if (difficulty == 2) {
		write_text("15 PUZZLE", 120, 5, WHITE, 0);
	} else if (difficulty == 3) {
		write_text("24 PUZZLE", 120, 5, WHITE, 0);
	}

	// print the board
	for (i = 0; i < easyrow; i++, b+=24){
		for (j = 0; j < easycol; j++, a+=31){
			print_square(i, j , a, b);
		}
		a = x;
	}

	//display legend
	write_text("Slide", 5, 45, WHITE, 0);
	write_text("Up-W", 5, 55, WHITE, 0);
	write_text("Dn-S", 5, 65, WHITE, 0);
	write_text("Lf-A", 5, 75, WHITE, 0);
	write_text("Rt-D", 5, 85, WHITE, 0);
	
	//show number of flips
	write_text("Moves:", 125, 150, WHITE, 0);
	write_text("Reset-R", 40, 170, WHITE, 0);
	write_text("Exit-X", 220, 170, WHITE, 0);
	
}

int goalTest(){
	int i, j;
	int goalState[3][3] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 0}
	};
	for (i = 0; i < easyrow; i++){
		for (j = 0; j < easycol; j++){
			if (board[i][j] != goalState[i][j]){
				return 0;
			}
		}
	}
	write_text("NICE! Press any key!", 80, 180, WHITE, 0);
	return 1;
}

void update_board(int x, int y){
	int i, j, a, b;
	a = x;
	b = y;
	erase(x, y, 75, 75);
	// print the board
	for (i = 0; i < easyrow; i++, b+=24){
		for (j = 0; j < easycol; j++, a+=31){
			print_square(i, j , a, b);
		}
		a = x;
	}
}

void erase(int x, int y, int w, int h){ //basically covers an area with a black rectangle 
	int i, j;
	for (i = y; i <= (y + h); i++)
		for (j = x; j <= (x + w); j++)
			write_pixel(j, i, 100);
}

//displays header
header(){

	write_text("N PUZZLE", 120, 40, WHITE, 1); //title

	//menu options
	write_text("1 - Play", 120, 140, WHITE, 0); 
	write_text("2 - Exit", 120, 160, WHITE, 0);
}


//displays subheader
subheader(){

	write_text("N PUZZLE", 120, 40, WHITE, 1); //title

	//menu options
	write_text("E - Easy", 120, 100, WHITE, 0); 
	write_text("M - Medium", 120, 120, WHITE, 0);
	write_text("H - Hard", 120, 140, WHITE, 0);
	write_text("B - Back to Main Menu", 60, 160, WHITE, 0);
}