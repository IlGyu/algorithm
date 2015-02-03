#include <stdio.h>
#define Max_n 30

int N, M, K;

int D[Max_n + 1][Max_n + 1];

int main()
{
	int i, j, y, x;

	D[0][0] = D[1][0] = D[1][1] = 1;
	for (i = 2; i <= Max_n; i++) {
		D[i][0] = 1;
		for (j = 1; j <= i; j++){
			D[i][j] = D[i - 1][j - 1] + D[i - 1][j];
		}
	}

	scanf("%d%d%d", &N, &M, &K);

	if (K == 0) {
		y = x = 1;
	} else {
		y = (K - 1) / M + 1;
		x = (K - 1) % M + 1;
	}
	printf("%d", D[y + x - 2][y - 1] * D[N - y + M - x][N - y]);

	return 0;
}