#include <stdio.h>
#define M 200

int D[M + 1];

int main()
{
	int coin[5] = { 1, 5, 10, 25, 50 };
	int i, j;
	double n;

	D[0] = 1;

	for (i = 0; i < 5; i++) {
		for (j = coin[i]; j <= M; j++){
			D[j] += D[j - coin[i]];
		}
	}

	scanf("%lf", &n);
	printf("%d", D[int(n * 100)]);
}