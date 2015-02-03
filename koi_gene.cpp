/*
	D[i, j] : i부터 j까지를 사용해서 만들 수 있는 최대 KOI 유전자 길이
*/

#include <stdio.h>
#include <string.h>
#define Max_n 500

int N;
char S[Max_n + 2];
int D[Max_n + 1][Max_n + 1];

void init()
{
	scanf("%s", &S[1]);
}

void process()
{
	int p, i, j, k, max;

	N = strlen(&S[1]);
	for (i = 1; i <= N - 1; i++) {
		if ((S[i] == 'a' && S[i + 1] == 't') || (S[i] == 'g' && S[i + 1] == 'c')) {
			D[i][i + 1] = 2;
		}
	}

	for (p = 2; p <= N - 1; p++) {
		for (i = 1; i <= N - p; i++) {
			j = p + i;

			max = D[i + 1][j];
			if (max < D[i][j - 1]) max = D[i][j - 1];
			if ((S[i] == 'a' && S[j] == 't') || (S[i] == 'g' && S[j] == 'c')) {
				if (max < D[i + 1][j - 1] + 2) max = D[i + 1][j - 1] + 2;
			}
			for (k = i + 1; k <= j - 1; k++) {
				if (max < D[i][k] + D[k + 1][j]) max = D[i][k] + D[k + 1][j];
			}
			D[i][j] = max;
		}
	}
}

void output()
{
	printf("%d", D[1][N]);
}

int main()
{
	init();
	process();
	output();
	return 0;
}