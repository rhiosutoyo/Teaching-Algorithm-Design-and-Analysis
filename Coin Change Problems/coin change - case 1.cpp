/*
	In a country there are only coin worth 3, 5 and 12.
   	1 Is the return 23 can be formed from these fragments?
   	2 How many coins to form the return value of 23?
   	3 How many combinations of ways to form a value of 23?
*/

#include<stdio.h>

void printC(int C[], int n){
	for(int i=1 ; i<=n ; i++){
		printf("%2c ", C[i]);
	}
	printf("\n");

	for(int i=1 ; i<=n ; i++){
		printf("%2d ", i);
	}
	printf("\n");
	printf("\n");
}

int main(){
	printf("In a country there are only coin worth 3, 5 and 12.\n");
	printf("Case 1: Is the return 23 can be formed from these fragments?\n\n");
	
	int iNilaiCari = 23;
	int iMaxCari = 25;
	
	int iJumKoin = 3;
	int koin[4] = {0, 3, 5, 12};
	int C[iMaxCari+1];

	// 01 set the value of all array of C to 'X' (TIDAK BISA)
	for(int i=1 ; i<=iMaxCari ; i++){
		C[i] = 'X';
	}	
	printC(C, iMaxCari);

	// 02 set the value of specific array of C to 'B' (BISA)
	// specific array: the value of the coin, which are: 3, 5, and 12
	for(int j=1 ; j<=iJumKoin ; j++){
		C[koin[j]] = 'B';
	}
	printC(C, iMaxCari);
	
	// 03 the solution
	// loop through all array index of C
	for(int i=1 ; i<=iMaxCari ; i++){
		// loop through all coins (i.e., 3, 5, 12)
		for(int j=1 ; j<=iJumKoin ; j++){
			// if the current array index minus the value of coins are still more than or equal than one, then
			if( (i-koin[j]) >= 1 )
				// we check whether current index minus our value of coins
				// for example: the current index is 6, and our value of coin is 3, and the C[3] = 'B'
				if( C[i-koin[j]] == 'B' )
					// it means the C[6] can be formed with the help of coin 3
					C[i]='B';
		}
	}
	printC(C, iMaxCari);
	
	
	// result
	printf("%d --> ", iNilaiCari);
	if( C[iNilaiCari] == 'B') printf("can be formed\n");
	else printf("cannot be formed\n");

	return (0);
}
