#include <stdio.h>
#define Max_n 50000

long long N, M;

int V[Max_n + 1], A[Max_n + 1];

int Tree[Max_n * 3], K;

void init()
{
	scanf("%d%d", &N, &M);
}

int getCount(int st, int ed)
{
	int sum = 0;

	while (st <= ed) {
		if (st % 2 == 0) {
			st /= 2;
		} else {
			sum += Tree[st];
			st = (st + 1) / 2;
		}
		if (ed % 2 == 0) {
			sum += Tree[ed];
			ed = (ed - 1) / 2;
		} else {
			ed /= 2;
		}
	}

	return sum;
}

void process()
{
	int i, j, cnt, index, st, ed, mid;
	long long n, k;

	K = 1;
	while (K < N) K *= 2;

	for (i = 1; i <= N; i++) {
		index = K + i - 1;
		while (index) {
			Tree[index]++;
			index /= 2;
		}
	}

	for (i = 1; i <= N; i++) {
		n = N - i;
		k = M - n * (n - 1) / 2;

		if (k < 0) k = 0;

		st = 1; 
		ed = N;

		while (st <= ed) {
			mid = (st + ed) / 2;

			cnt = getCount(K, K + mid - 1);

			if (cnt == k + 1) {
				if (Tree[K + mid - 1] == 0) {
					ed = mid - 1;
				} else {
					A[i] = mid;
					j = K + mid - 1;
					while (j) {
						Tree[j] --;
						j /= 2;
					}

					break;
				}
			} else if (cnt < k + 1) {
				st = mid + 1;
			} else {
				ed = mid - 1;
			}
		}

		M -= k;
	}
}

void output()
{
	int i;

	for (i = 1; i <= N; i++) { 
		printf("%d ", A[i]);
	}
}

int main()
{
	init();
	process();
	output();
	return 0;
}