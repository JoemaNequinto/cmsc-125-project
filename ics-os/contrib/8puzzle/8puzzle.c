#include "../../sdk/dexsdk.h"
#include "../../sdk/time.h"
#include "../../kernel/stdlib/stdlib.h"

void setup_difficulty(); //self explanatory
void randomizeBoard(int dim, int config[dim][dim]);
void swapTile(int dim, int config[dim][dim], int r1, int c1, int r2, int c2);
void print_board(int dim, int config[dim][dim], int x, int y); //set up initial board
int isSolvable();
void print_square(int dim, int config[dim][dim], int r, int c, int x, int y);
void update_board(int dim, int config[dim][dim], int x, int y);
int goalTest(int difficulty);
void erase(int x, int y, int w, int h); //covers an area with a black rectangle

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
int easyboard[easyrow][easycol] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 0} };
int mediumboard[mediumrow][mediumcol] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0} };
int hardboard[hardrow][hardcol] = { {1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 0} };
int rowEmpty, colEmpty;

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
									if (colEmpty != 2){
										moves++;
										erase(190, 150, 25, 20);
										sprintf(str, "%d", moves);
										write_text(str, 190, 150, WHITE, 0);

										swapTile(3, easyboard, rowEmpty, colEmpty, rowEmpty, colEmpty + 1);
										update_board(3, easyboard, 120, 55);
									}
								} else if (keypress == left_key){
									if (colEmpty != 0){
										moves++;
										erase(190, 150, 25, 20);
										sprintf(str, "%d", moves);
										write_text(str, 190, 150, WHITE, 0);
										
										swapTile(3, easyboard, rowEmpty, colEmpty, rowEmpty, colEmpty - 1);
										update_board(3, easyboard, 120, 55);
									}
								} else if (keypress == up_key){
									if (rowEmpty != 0){
										moves++;
										erase(190, 150, 25, 20);
										sprintf(str, "%d", moves);
										write_text(str, 190, 150, WHITE, 0);
										
										swapTile(3, easyboard, rowEmpty, colEmpty, rowEmpty - 1, colEmpty);
										update_board(3, easyboard, 120, 55);
									}
								} else if (keypress == down_key){
									if (rowEmpty != 2){
										moves++;
										erase(190, 150, 25, 20);
										sprintf(str, "%d", moves);
										write_text(str, 190, 150, WHITE, 0);
										
										swapTile(3, easyboard, rowEmpty, colEmpty, rowEmpty + 1, colEmpty);
										update_board(3, easyboard, 120, 55);
									}
								}

								if (goalTest(1) == 1){
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
					
					do{
						if (keypress == medium){
							difficulty = 2; //initialize difficulty
							moves = 0;
							erase(1, 1, 400, 220);
							setup_difficulty();
							erase(190, 150, 20, 20);
							write_text("0", 190, 150, WHITE, 0);
						}

						do {
							if (keypress = (char)getch()){
								if (keypress == right_key){
									if (colEmpty != 3){
										moves++;
										erase(190, 150, 25, 20);
										sprintf(str, "%d", moves);
										write_text(str, 190, 150, WHITE, 0);

										swapTile(4, mediumboard, rowEmpty, colEmpty, rowEmpty, colEmpty + 1);
										update_board(4, mediumboard, 110, 45);
									}
								} else if (keypress == left_key){
									if (colEmpty != 0){
										moves++;
										erase(190, 150, 25, 20);
										sprintf(str, "%d", moves);
										write_text(str, 190, 150, WHITE, 0);
										
										swapTile(4, mediumboard, rowEmpty, colEmpty, rowEmpty, colEmpty - 1);
										update_board(4, mediumboard, 110, 45);
									}
								} else if (keypress == up_key){
									if (rowEmpty != 0){
										moves++;
										erase(190, 150, 25, 20);
										sprintf(str, "%d", moves);
										write_text(str, 190, 150, WHITE, 0);
										
										swapTile(4, mediumboard, rowEmpty, colEmpty, rowEmpty - 1, colEmpty);
										update_board(4, mediumboard, 110, 45);
									}
								} else if (keypress == down_key){
									if (rowEmpty != 3){
										moves++;
										erase(190, 150, 25, 20);
										sprintf(str, "%d", moves);
										write_text(str, 190, 150, WHITE, 0);
										
										swapTile(4, mediumboard, rowEmpty, colEmpty, rowEmpty + 1, colEmpty);
										update_board(4, mediumboard, 110, 45);
									}
								}

								if (goalTest(2) == 1){
									keypress = (char) getch();
									keypress = medium;
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
							if (keypress == yes) keypress = medium;
							erase(35, 180, 240, 40);	
						}

					} while (keypress != yes);
				}

				else if(keypress == hard){
					
					do{
						if (keypress == hard){
							difficulty = 3; //initialize difficulty
							moves = 0;
							erase(1, 1, 400, 220);
							setup_difficulty();
							erase(190, 150, 20, 20);
							write_text("0", 190, 150, WHITE, 0);
						}

						do {
							if (keypress = (char)getch()){
								if (keypress == right_key){
									if (colEmpty != 4){
										moves++;
										erase(190, 150, 25, 20);
										sprintf(str, "%d", moves);
										write_text(str, 190, 150, WHITE, 0);

										swapTile(5, hardboard, rowEmpty, colEmpty, rowEmpty, colEmpty + 1);
										update_board(5, hardboard, 85, 35);
									}
								} else if (keypress == left_key){
									if (colEmpty != 0){
										moves++;
										erase(190, 150, 25, 20);
										sprintf(str, "%d", moves);
										write_text(str, 190, 150, WHITE, 0);
										
										swapTile(5, hardboard, rowEmpty, colEmpty, rowEmpty, colEmpty - 1);
										update_board(5, hardboard, 85, 35);
									}
								} else if (keypress == up_key){
									if (rowEmpty != 0){
										moves++;
										erase(190, 150, 25, 20);
										sprintf(str, "%d", moves);
										write_text(str, 190, 150, WHITE, 0);
										
										swapTile(5, hardboard, rowEmpty, colEmpty, rowEmpty - 1, colEmpty);
										update_board(5, hardboard, 85, 35);
									}
								} else if (keypress == down_key){
									if (rowEmpty != 4){
										moves++;
										erase(190, 150, 25, 20);
										sprintf(str, "%d", moves);
										write_text(str, 190, 150, WHITE, 0);
										
										swapTile(5, hardboard, rowEmpty, colEmpty, rowEmpty + 1, colEmpty);
										update_board(5, hardboard, 85, 35);
									}
								}

								if (goalTest(3) == 1){
									keypress = (char) getch();
									keypress = hard;
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
							if (keypress == yes) keypress = hard;
							erase(35, 180, 240, 40);	
						}

					} while (keypress != yes);
				}

				else 
					continue;

			} while (keypress != back);
		}
	} while (keypress != quit_game);

	set_graphics(VGA_TEXT80X25X16);
	clrscr();
}

void setup_difficulty(){

	switch(difficulty){
	
		case 1:
			randomizeBoard(3, easyboard);
			print_board(3, easyboard, 120, 55);
			break;

		case 2:
			randomizeBoard(4, mediumboard);
			print_board(4, mediumboard, 110, 45);
			break;
	
		case 3:
			randomizeBoard(5, hardboard);
			print_board(5, hardboard, 85, 35);
			break;

	}	
	
}

int isSolvable(int dim, int config[dim][dim]){

	int i, j;
	int newArray[dim * dim], inversions = 0;

	for (i = 0; i < dim; i++){
		for (j = 0; j < dim; j++){
			newArray[(i * dim) + j] = config[i][j];
		}
	}

	for (i = 0; i < (dim * dim - 1); i++){
		for (j = i + 1; j < (dim * dim); j++){
			if (newArray[i] > newArray[j]) inversions++;
			if (newArray[i] == 0 && i%2 == 1) inversions++;
		}
	}	

	if (inversions%2 == 0) return 1;
	else return 0;
}

void randomizeBoard(int dim, int config[dim][dim]){
	int i, j;
	for (i = 0; i < dim; i++){
		for (j = 0; j < dim; j++){
			swapTile(dim, config, i, j, rand() % 3, rand() % 3);
		}
	}
	if (isSolvable(dim, config) == 0) randomizeBoard(dim, config);
}

void swapTile(int dim, int config[dim][dim], int r1, int c1, int r2, int c2){
	int temp = config[r1][c1];
	config[r1][c1] = config[r2][c2];
	config[r2][c2] = temp;
}

void print_board(int dim, int config[dim][dim], int x, int y){ //set up initial board 

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
	// for (i = 0; i < dim; i++, b+=24){
	// 	for (j = 0; j < dim; j++, a+=31){
	// 		print_square(dim, config, i, j , a, b);
	// 	}
	// 	a = x;
	// }
	update_board(dim, config, a, b);

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

void print_square(int dim, int config[dim][dim], int r, int c, int x, int y){
	char str[15];

	if (config[r][c] != 0){
		sprintf(str,"%d",config[r][c]);
		write_text(str,x,y,WHITE,0);
	} else {
		rowEmpty = r;
		colEmpty = c;
		write_text(" ",x,y,WHITE,0);
	}
}

void update_board(int dim, int config[dim][dim], int x, int y){
	int i, j, a, b;
	a = x;
	b = y;
	if (dim == 3) {
		erase(x, y, 75, 75);
		// out border
		drawHorizontalBorder(a-4, b-6, 75, 1);
		drawVerticalBorder(a-4, b-6, 1, 68);
		drawVerticalBorder(a+70, b-6, 1, 68);
		drawHorizontalBorder(a-4, b+61, 75, 1);
		// in border
		drawHorizontalBorder(a-4, b+18, 75, 1);
		drawHorizontalBorder(a-4, b+40, 75, 1);
		drawVerticalBorder(a+21, b-6, 1, 68);
		drawVerticalBorder(a+46, b-6, 1, 68);
	}
	if (dim == 4) {
		erase(x, y, 110, 100);
		// out border
		drawHorizontalBorder(a-4, b-6, 115, 1);
		drawVerticalBorder(a-4, b-6, 1, 94);
		drawVerticalBorder(a+111, b-6, 1, 94);
		drawHorizontalBorder(a-4, b+87, 115, 1);
		// in border
		drawVerticalBorder(a+25, b-6, 1, 94);
		drawVerticalBorder(a+53, b-6, 1, 94);
		drawVerticalBorder(a+81, b-6, 1, 94);
		drawHorizontalBorder(a-4, b+18, 115, 1);
		drawHorizontalBorder(a-4, b+42, 115, 1);
		drawHorizontalBorder(a-4, b+66, 115, 1);
	}
	if (dim == 5) {
		erase(x, y, 140, 110);
		// out border
		drawHorizontalBorder(a-4, b-6, 146, 1);
		drawVerticalBorder(a-4, b-6, 1, 113);
		drawVerticalBorder(a+142, b-6, 1, 113);
		drawHorizontalBorder(a-4, b+106, 146, 1);
		// in border
		drawVerticalBorder(a+26, b-6, 1, 113);
		drawVerticalBorder(a+56, b-6, 1, 113);
		drawVerticalBorder(a+86, b-6, 1, 113);
		drawVerticalBorder(a+116, b-6, 1, 113);
		drawHorizontalBorder(a-4, b+17, 146, 1);
		drawHorizontalBorder(a-4, b+40, 146, 1);
		drawHorizontalBorder(a-4, b+63, 146, 1);
		drawHorizontalBorder(a-4, b+86, 146, 1);
	}

	for (i = 0; i < dim; i++, b+=24){
		for (j = 0; j < dim; j++, a+=31){
			print_square(dim, config, i, j , a, b);
		}
		a = x;
	}
}


int goalTest(int difficulty){
	int i, j;

	if (difficulty == 1){
		int goalState[3][3] = {
			{1, 2, 3},
			{4, 5, 6},
			{7, 8, 0}
		};
		for (i = 0; i < 3; i++){
			for (j = 0; j < 3; j++){
				if (easyboard[i][j] != goalState[i][j]){
					return 0;
				}
			}
		}
		write_text("NICE! Press any key!", 80, 180, WHITE, 0);
		return 1;
	} else if (difficulty == 2) {
		int goalState[4][4] = {
			{1, 2, 3, 4}, 
			{5, 6, 7, 8}, 
			{9, 10, 11, 12}, 
			{13, 14, 15, 0} 
		};
		for (i = 0; i < 4; i++){
			for (j = 0; j < 4; j++){
				if (mediumboard[i][j] != goalState[i][j]){
					return 0;
				}
			}
		}
		write_text("NICE! Press any key!", 80, 180, WHITE, 0);
		return 1;
	} else if (difficulty == 3) {
		int goalState[5][5] = { 
			{1, 2, 3, 4, 5}, 
			{6, 7, 8, 9, 10}, 
			{11, 12, 13, 14, 15}, 
			{16, 17, 18, 19, 20}, 
			{21, 22, 23, 24, 0} 
		};
		for (i = 0; i < 5; i++){
			for (j = 0; j < 5; j++){
				if (hardboard[i][j] != goalState[i][j]){
					return 0;
				}
			}
		}
		write_text("NICE! Press any key!", 80, 180, WHITE, 0);
		return 1;
	}
}


void erase(int x, int y, int w, int h){ //basically covers an area with a black rectangle 
	int i, j;
	for (i = y; i <= (y + h); i++)
		for (j = x; j <= (x + w); j++)
			write_pixel(j, i, 100);
}

void drawVerticalBorder(int x, int y, int w, int h){ //basically covers an area with a black rectangle 
	int i, j;
	for (i = y; i <= (y + h); i++)
		for (j = x; j <= (x + w); j++)
			write_pixel(j, i, WHITE);
}

void drawHorizontalBorder(int x, int y, int w, int h){ //basically covers an area with a black rectangle 
	int i, j;
	for (i = y; i <= (y + h); i++)
		for (j = x; j <= (x + w); j++)
			write_pixel(j, i, WHITE);
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