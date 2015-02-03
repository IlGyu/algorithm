#include <stdio.h>
#define Max_n 1000
#define MOD 1000000009

int N, K;

long long D[4][4][4][4], E[4][4][4][4], Sol;

void init()
{
	scanf("%d%d", &N, &K);
}

void process()
{
	long long k;
	int i, a, b, c, d, e;

	for (a = 0; a < 4; a++) {
		for (b = 0; b < 4; b++) {
			for (c = 0; c < 4; c++) {
				for (d = 0; d < 4; d++) {					
					D[a][b][c][d] = 1;

					if (a == 3) D[a][b][c][d] *= (K - 3);
					if (b == 3) D[a][b][c][d] *= (K - 3);
					if (c == 3) D[a][b][c][d] *= (K - 3);
					if (d == 3) D[a][b][c][d] *= (K - 3);
				}
			}
		}
	}


	for (i = 4; i < N; i++) {
		for (a = 0; a < 4; a++) {
			for (b = 0; b < 4; b++) {
				for (c = 0; c < 4; c++) {
					for (d = 0; d < 4; d++) {
						for (e = 0; e < 4; e++) {
							if (a == 0 && b == 1 && c == 0 && d == 1 && e == 2) continue;
							if (a == 0 && b == 1 && c == 2 && d == 1 && e == 2) continue;

							if (e == 3) {
								E[b][c][d][e] += D[a][b][c][d] * (K - 3);
							} else {
								E[b][c][d][e] += D[a][b][c][d];
							}
							E[b][c][d][e] %= MOD;
						}
					}
				}
			}
		}

		for (a = 0; a < 4; a++) {
			for (b = 0; b < 4; b++) {
				for (c = 0; c < 4; c++) {
					for (d = 0; d < 4; d++) {
						D[a][b][c][d] = E[a][b][c][d];
						E[a][b][c][d] = 0;
					}
				}
			}
		}
	}
	for (a = 0; a < 4; a++) {
		for (b = 0; b < 4; b++) {
			for (c = 0; c < 4; c++) {
				for (d = 0; d < 4; d++) {
					Sol += D[a][b][c][d];				
					Sol %= MOD;
				}
			}
		}
	}
}

void output()
{
	printf("%lld", Sol);
}

int main()
{
	init();
	process();
	output();
	return 0;
}