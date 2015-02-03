#include <stdio.h>
#define Max_n 100000

int N, Q;

int A[Max_n + 1], Sum[Max_n + 1][201];
int Count[201];

int main()
{
	int i, j, st, ed, n, m, sol;

	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		A[i] += 100;
		for (j = 0; j <= 200; j++) {
			Sum[i][j] = Sum[i - 1][j];
		}
		Sum[i][A[i]] ++;
	}

	scanf("%d", &Q);
	for (i = 0; i < Q; i++) {
		scanf("%d%d", &st, &ed);
		n = 0;
		for (j = 0; j <= 200; j++) {
			Count[j] = Sum[ed][j] - Sum[st - 1][j];
			n += Count[j];
		}
		sol = -1;
		m = n / 2 + n % 2;
		for (j = 0; j <= 200; j++) {
			if (m > Count[j]) {
				m -= Count[j];
			} else {
				sol = j;
				break;
			}
		}
		printf("%d\n", sol - 100);
	}

	
	return 0;
}