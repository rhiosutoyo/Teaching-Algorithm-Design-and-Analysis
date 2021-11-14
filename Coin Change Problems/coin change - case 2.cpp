/*
	In a country there are only coin worth 3, 5 and 12.
   	1 Is the return 23 can be formed from these fragments?
   	2 How many coins to form the return value of 23?
   	3 How many combinations of ways to form a value of 23?
*/

#include<stdio.h>

void printC(int C[], int n){
	for(int i=1 ; i<=n ; i++){
		printf("%2d ", C[i]);
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
	printf("2 How many coins to form the return value of 23?\n\n");
	
	int iNilaiCari = 23;
	int iMaxCari = 25;
	
	int iJumKoin = 3;
	int koin[4] = {0, 3, 5, 12};
	int C[iMaxCari+1];

	// 01 set the value of all array of C to '0' (TIDAK BISA)
	for(int i=1 ; i<=iMaxCari ; i++){
		C[i] = 0;
	}	
	printC(C, iMaxCari);

	// 02 set the value of specific array of C to 'B' (BISA)
	// specific array: the value of the coin, which are: 3, 5, and 12
	for(int j=1 ; j<=iJumKoin ; j++){
		C[koin[j]] = 1;
	}
	printC(C, iMaxCari);
	
	// 03 the solution
	// loop through all array index of C
	for(int i=1 ; i<=iMaxCari ; i++){

		// loop through all coins (i.e., 3, 5, 12)
		for(int j=1 ; j<=iJumKoin ; j++){
			
			// if the current array index minus the value of coins are still more than or equal than one
			// if the element of current array index minus the value of coins is more than 0 (it means that it can be formed)
			// then
			if( ((i-koin[j])>=1) && (C[i-koin[j]]>0) ){
				// if the element of current array is 0 or
				// if the element of current array index is more than the previous formed value
				// then
				if( (C[i]==0) || (C[i]>(1 + C[i-koin[j]])) ){
					// the element of current array index is the previous formed value + 1
					C[i] = 1 + C[i-koin[j]];
				} 
			}
		}
	}
	printC(C, iMaxCari);
		
	// result
	printf("%d --> ", iNilaiCari);
	if( C[iNilaiCari] > 0 ) printf("can be formed with minimum of %d\n", C[iNilaiCari]);
	else printf("cannot be formed\n");

	return (0);
}
