/*
 * Program1.c
 *
 *  Created on: Feb 9, 2023
 *      Author: alexisng
 */

#include <stdio.h>
#define MONTHS 12
char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int sales_report(float sales[])
{
	printf("Month\tSales\n");
	for (int i = 0; i < MONTHS; ++i){
		printf("%s\t %.2f\n", months[i], sales[i]);
	}
	printf("\n");
 return 0;
}
void f_swap(float* xp, float* yp) //swapping for floats
{
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void c_swap(char* xp[], char* yp[]) //swapping for strings
{
    char *temp = *xp;
    *xp = *yp;
    *yp = temp;
}
float sum(float arr[], int length){
		float total = 0;
		for (int i = 0; i < length; ++i){
			total+=arr[i];
		}
		return total;
}

float min(float arr[]){
	float min = arr[0];
	for (int i = 0; i <= MONTHS; ++i){
			for (int j = 0; j < MONTHS; ++j){
				if (min > arr[j]){
					min = arr[j];
				}
			}
		}
	return min;
}
float max(float arr[]){
	float max = arr[0];
	for (int i = 0; i <= MONTHS; ++i){
			for (int j = 0; j < MONTHS; ++j){
				if (max < arr[j]){
					max = arr[j];
				}
			}
		}
	return max;
}

char* match(float arr[], float value){
	for (int i = 0; i < MONTHS; ++i){
		if (value == arr[i]){
			return months[i];
		}
	}
	return months[0];

}
int sorting(float sales[]){
	//bubble sort
	for (int i = 0; i < MONTHS - 1; i++){
		for (int j = 0; j < MONTHS - i - 1; j++){
			if (sales[j] < sales[j + 1]){
				c_swap(&months[j], &months[j+1]);
			     f_swap(&sales[j], &sales[j + 1]);
			}
		}
	}
	return 0;
}

void sales_summary(float sales[]){
	//assuming already sorted
	float min_sales = min(sales);
	float max_sales = max(sales);
	printf("Sales Summary\n");
	printf("Minimum Sales: %.2f (%s)\n", min_sales , match(sales, min_sales)); //minimum
	printf("Maximum Sales: %.2f (%s)\n", max_sales, match(sales, max_sales)); //maximum
	printf("Average Sales: %.2f\n\n",sum(sales, MONTHS)/MONTHS); //average
	return;
}

int six_moving_average(float sales[]){
	//before sorted
	printf("Six-Month Moving Average Report: \n");
	for (int i = 0; i < MONTHS/2; ++i){
		float temp_total = 0;
		for (int j = i; j < i+6; ++j){
			temp_total+=sales[j];
		}
		printf("%s - %s $%.2f\n", months[i], months[i+6], temp_total/6);
	}
	printf("\n");
	return 0;
}

int sorted_sales_report(float sales[]){
		printf("Sales Report (Highest to Lowest): \n");
		sorting(sales);
		sales_report(sales);
		return 0;
}
int main(){
	FILE *fp;
	float sales[MONTHS];
	fp = fopen("input.txt", "r");
	if (fp == NULL){
		printf("Error opening file\n");
		return 1;
	}
	for (int i = 0; i < MONTHS; ++i){
		fscanf(fp, "%f", &sales[i]);

	}
	fclose(fp);
	printf("Month sales report for 2022\n");
	sales_report(sales);
	sales_summary(sales);
	six_moving_average(sales);
	sorted_sales_report(sales);

	return 0;


}


