#include <stdio.h>
#include <memory.h>
#define S 16
#define Max_k 1000
#define MOD 42043

int N, K, T, Sol;

int C[S + 1][Max_k + 1], A[Max_k + 1];

void init()
{
	int i, num;

	scanf("%d%d%d", &N, &K, &T);
	for (i = 0; i < T; i++) {
		scanf("%d", &num);
		if (num <= K) C[1][num] ++;
	}
}

void process()
{
	int pow[S + 1] = { 0, }, temp[Max_k + 1] = { 0, };
	int i, j, k, sw;

	for (i = 2; i <= S; i++) {
		for (j = 0; j <= K; j++) {
			for (k = 0; k <= K - j; k++) {
				C[i][j + k] += C[i - 1][j] * C[i - 1][k];
				C[i][j + k] %= MOD;
			}
		}
	}

	pow[1] = 1;
	for (i = 2; i <= S; i++) {
		pow[i] = pow[i - 1] * 2;
	}

	i = S;
	sw = 0;
	while (N) {
		if (N >= pow[i]) {
			N -= pow[i];
			if (sw == 0) {
				for (j = 0; j <= K; j++) {
					A[j] = C[i][j];
				}
				sw = 1;
			} else {
				memset(temp, 0, sizeof(temp));
				for (j = 0; j <= K; j++) {
					for (k = 0; k <= K - j; k++) {
						temp[j + k] += A[j] * C[i][k];
						temp[j + k] %= MOD;
					}
				}
				for (j = 0; j <= K; j++) {
					A[j] = temp[j];
				}
			}
		} else {
			i--;
		}
	}
	for (j = 0; j <= K; j++) {
		Sol += A[j];
		Sol %= MOD;
	}
}

void output()
{
	printf("%d", Sol);
}

int main()
{
	init();
	process();
	output();
	return 0;
}