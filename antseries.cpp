#include <stdio.h>

int N, A[50];

int main()
{
	int i, j;

	for (;;) {
		scanf("%d", &A[ N++ ]);
		if (!A[N - 1]) break;
	}
	N--;
	
	j = 0;
	for (;;) {
		for (i = j; i < N; i++) {
			if (A[i] != A[i + 1]) {
				printf("%d %d ", i - j + 1, A[i]);
				j = i + 1;
				break;
			}
		}
		if (j == N) break;
	}
	return 0;
}