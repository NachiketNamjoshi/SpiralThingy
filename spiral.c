#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 4


void printm(int [SIZE][SIZE]);
void spiral(int [SIZE][SIZE]);
void checkData(int [SIZE][SIZE]);


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
printf("\n\n - Outs:\n\n");
checkData(m);
}

void checkData(int m[SIZE][SIZE]) {

int row,col,col2;

row=SIZE/2-1; 		// Start From mid row
col=0;
col2=0;
while(row>=0) {		// Dont Reach Unrealistic Values

/*
 * col2 = index of upper matrix
 * col = index of lower matrix
 *
 */

	if(m[row][col2] == 1){	// col2++ if the spot is filled
		col2++;
		if(col2>=SIZE){
			row--;
			col2=0;
		}
		continue;
	}

	if(col2 < SIZE) {	// Dont Reach Unrealistic Values

		if(m[SIZE-row-1][col] == 1) {		// "Outlier" Check
			int t = m[SIZE-row-1][col];
			m[SIZE-row-1][col] = m[row][col2];		// swap
			m[row][col2] = t;
			col2++;							// increment indices
			col++;
		} else {
			col++;					// No Outlier, go elsewhere
		}
	} else {
		col2=0;						// Nothing on this row, reset me & go away
	}

	if(row>=0 && col == SIZE-1) {
		row--;
		col=0;					// Housekeeping
	}
	if(row<0)					// Please. Dont Reach Unrealistic Values.
		break;
}
printm(m);
}