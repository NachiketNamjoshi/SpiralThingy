#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 4


void printm(int [SIZE][SIZE]);
void spiral(int [SIZE][SIZE]);


int main() {
int data[SIZE][SIZE];
int i,j;
srand(time(NULL));
for(i=0;i<SIZE;i++) {
	for(j=0;j<SIZE;j++) {
		data[i][j] = rand()%2;
	}	
}
printm(data);
printf("\n\n - Spiral Shitta:\n\n");
spiral(data);
return 0;
}

void printm(int m[SIZE][SIZE]) {
int i,j;
for(i=0;i<SIZE;i++) {
	printf("\n");
	if(i==SIZE/2)
		printf("-------------------------\n");  // A line for reference
	for(j=0;j<SIZE;j++) {
		printf("%d\t", m[i][j]);
			}
}
}

void spiral(int m[SIZE][SIZE]) {

int row,col;

row=SIZE/2-1; 		// Start From mid row

//we need all cols to be traversed
for(col=0;col<SIZE;col++) {
	if(m[row][col] != m[SIZE-row-1][col]) { 

/* if row = 4/2-1 = 1, 
 * then we need to compare with 
 * 4-1-1 = 2 row.
 * if row = 0, 4-0-1 = 3 
 */
		if(m[row][col] == 0) {
			int t = m[row][col];
			m[row][col]=m[SIZE-row-1][col];
			m[SIZE-row-1][col]=t;
		}
	}
	//go 1 row backwards.
	
	if(row>0 && col == SIZE-1) {
		row--;
		col=-1;
	}
}

printm(m);
}
