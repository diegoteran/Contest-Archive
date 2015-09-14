#include <iostream>
#include <cstdio>
using namespace std;

/*Sólo es checar que dos números de la princesa no le ganen a 2 del príncipe con ciertas condiciones */

bool used[53];
int numF[3], numM[3];
int A, B, C, X, Y;

int main() {
	int i,sol;
	
	while(scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y), A){
		
		for(i=0; i<53; i++)
			used[i] = false;
		
		used[A] = true;
		used[B] = true;
		used[C] = true;
		used[X] = true;
		used[Y] = true;
		
		if (X > Y){
			numM[0] = X;
			numM[1] = Y;
		} else {
			numM[1] = X;
			numM[0] = Y;
		}
		
		if(A > B){
			if(A > C){
				if(B > C){
					numF[0] = A;
					numF[1] = B;
					numF[2] = C;
				} else {
					numF[0] = A;
					numF[1] = C;
					numF[2] = B;
				}
			} else{
				numF[0] = C;
				numF[1] = A;
				numF[2] = B;
			}
		} else {
			if(A > C){
				numF[0] = B;
				numF[1] = A;
				numF[2] = C;
			} else{
				if(B > C){
					numF[0] = B;
					numF[1] = C;
					numF[2] = A;
				} else {
					numF[0] = C;
					numF[1] = B;
					numF[2] = A;
				}
			}
		}
		
		if(numF[1] > numM[1]){
			if(numF[0] > numM[0]){
				sol = -1;
			} else {
				for(i=numF[0]; i<53; i++){
					if(used[i] == false){
						sol = i;
						break;
					}
					sol = -1;
				}
			}
		} else {
			if(numF[0] > numM[1]){
				for(i=numF[1]; i<53; i++){
					if(used[i] == false){
						sol = i;
						break;
					}
					sol = -1;
				}
			} else {
				for(i=1; i<53; i++){
					if(used[i] == false){
						sol = i;
						break;
					}
					sol = -1;
				}
			}
		}
		
		printf("%d\n", sol);
		
	}
	
}