#include <stdio.h>
#include <algorithm>
#define Max_n 1000
#define Max_m 10000
using namespace std;

int N, Sol;

int A[Max_n + 1], S[Max_n + 1], Pos[Max_n + 1], V[Max_n + 1];

void init()
{
	int i;

	scanf("%d", &N);

	for (i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
}

void process()
{
	int i, j, cnt, min;
	
	for (i = 1; i <= N; i++) S[i] = A[i];
	sort(S + 1, S + 1 + N);

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (A[i] == S[j]) {
				Pos[i] = j;
				break;
			}
		}
	}

	for (i = 1; i <= N; i++) {
		if (V[i] || i == Pos[i]) continue;
		j = i;
		cnt = 0;
		min = A[i];
		V[j] = 1;
		for (;;) {
			j = Pos[j];
			Sol += A[j];
			if (V[j]) break;
			V[j] = 1;
			if (min > A[j]) min = A[j];
			cnt ++;			
		}
		Sol += min * (cnt - 1);
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