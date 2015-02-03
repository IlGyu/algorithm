#include <stdio.h>
#define Max_n 31

int T, N, M;

int D[Max_n + 1][Max_n + 1];

int main()
{
	int t, i, j, sum = 0;

	D[0][0] = 1;
	for (i = 1; i <= Max_n; i++) {
		D[i][0] = 1;
		for (j = 1; j <= i; j++) {
			D[i][j] = D[i - 1][j - 1] + D[i - 1][j];
		}
	}

	scanf("%d", &T);
	for (t = 0; t < T; t++) {
		scanf("%d%d", &N, &M);
		sum = 0;
		for (i = 0; i <= M; i++) {
			sum += D[N][i];
		}
		printf("%d\n", sum);
	}
	
	return 0;
}