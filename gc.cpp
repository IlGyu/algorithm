#include <stdio.h>
#include <memory.h>

int T, N;
int D[40];

int main()
{
	int t, i, j;

	scanf("%d", &T);

	for (t = 1; t <= T; t++) {
		scanf("%d", &N);
		N *= 2;
		D[0] = D[2] = 1;

		for (i = 4; i <= N; i += 2) {
			for (j = 2; j <= i; j += 2) {
				D[i] += D[j - 2] * D[i - j];
			}
		}

		printf("#testcase%d\n%d\n", t, D[N]);

		memset(D, 0, sizeof(D));
	}

	return 0;
}