/*
 * Program2.c
 *
 *  Created on: Feb 9, 2023
 *      Author: alexisng
 */
#include <stdio.h>
#define TDP2 8
#define TDP1 7
#define TDP 6
#define FG 3
#define SAFETY 2

int combinations(int points){
	int total = 0;
	for (int i = 0; i <= (points / TDP2); ++i){
		for (int j = 0; j <= (points/ TDP1); ++j){
			for (int k = 0; k <= (points/ TDP); ++k){
				for (int l = 0; l <= (points / FG); ++l){
					for (int m = 0; m <= (points / SAFETY); ++m){
						total= (i * TDP2) + (j * TDP1) + (k*TDP) + (l*FG) + (m * SAFETY);
						if (total == points){
						printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", i, j, k, l, m);
						}
					}


				}



			}

		}
	}
	return 0;

}

int main(){
	int stop;
	int score;
	do{
		printf("Enter 0 or 1 to STOP: ");
		scanf("%d", &stop);
		if (stop >1){
			printf("Enter the NFL Score: ");
			scanf("%d", &score);
			if (score < 2){
				printf("Score is too low");
				return 1;
			}
			combinations(score);
		}



	}while (stop > 1);
	return 0;
}

