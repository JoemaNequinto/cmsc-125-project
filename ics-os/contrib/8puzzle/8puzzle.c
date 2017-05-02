#include "../../sdk/dexsdk.h"
#include "../../sdk/time.h"

void setup_difficulty(); //self explanatory
void print_board(int x, int y); //set up initial board
void edit_board();
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

#define quit 'x'
#define reset 'r'
#define yes 'y'
#define no 'n'

#define WHITE 63
#define X_coord 85
#define Y_coord 35

/* global variables */
int difficulty, moves = 0;

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
					
					difficulty = 1; //initialize difficulty
					setup_difficulty();
					//update level display
					erase(25, 125, 40, 30);
					write_text("0", 190, 150, WHITE, 0);
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

				else if(keypress == back){
					break;
				}

				else 
					continue;

				do{

					// if (keypress = (char)getch()){

					// }

					do{
						if (keypress = (char)getch()){

						}
					} while (keypress != quit && keypress != reset);	
					//continue while player is not quitting, restarting or champion
				
					if (keypress == quit){
						//prompt confirmation then erase message
						write_text("Do you want to exit? y/n ", 50, 180, WHITE, 0); 
						keypress = (char) getch();
						erase(50, 180, 220, 40);	
					} else if (keypress == reset){
						//prompt confirmation then erase message
						write_text("Do you want to restart? y/n ", 35, 180, WHITE, 0);
						keypress = (char) getch();
						if (keypress == yes) keypress = start;
						erase(35, 180, 240, 40);	
					}

				} while (keypress != yes);

			} while (keypress != back);
		}
	} while (keypress != quit_game);

	set_graphics(VGA_TEXT80X25X16);
	clrscr();
}

void setup_difficulty(){

	switch(difficulty){
	
		case 1:						
			break;

		case 2:
			break;
	
		case 3:
			break;

	}	
	
	erase(190, 5, 30, 20); //erase menu
	print_board(85, 35);
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

// update selected and previously selected bulb colors 
void edit_board(){

	// light(oldrow, oldcol, bulbs_x[oldrow][oldcol], bulbs_y[oldrow][oldcol]);
	// light(row, col, bulbs_x[row][col], bulbs_y[row][col]);
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