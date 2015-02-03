#include <stdio.h>
#include <memory.h>
#define Max_n 5000
#define Max_m 65536

int N;

int A[Max_n + 1], D[Max_n + 2][2];

int Check[Max_m + 2];

int main()
{
	int i, j, max, count;

	scanf("%d", &N);
	for (i = 1; i <= N; i++){
		scanf("%d", &A[i]);
	}
	N++;

	D[1][0] = D[1][1] = 1;
	for (i = 2; i <= N; i++){
		max = count = 0;
		for (j = i - 1; j >= 1; j--){
			if (A[j] > A[i]){
				if (max < D[j][0] + 1){
					max = D[j][0] + 1;
					count = D[j][1];
					memset(Check, 0, sizeof(Check));
					Check[ A[j] ] = 1;
				}
				else if (max == D[j][0] + 1 && Check[ A[j] ]==0){
					Check[ A[j] ] = 1;
					count += D[j][1];
				}
			}
		}
		D[i][0] = max;
		D[i][1] = count;
		if (D[i][0] == 0){
			D[i][0] = D[i][1] = 1;
		}
	}
	printf("%d %d", D[N][0]-1, D[N][1]);
}