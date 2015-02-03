#include <stdio.h>
#define Max_n 100

int N, M;

int Map[Max_n + 1][Max_n + 1], V[Max_n + 1];

void init()
{
	int i, j, k;

	scanf("%d%d", &N, &M);
	for (i = 0; i < M; i++) {
		scanf("%d%d", &j, &k);
		Map[j][k] = Map[k][j] = 1;
	}
}

void recall(int node)
{
	int i;

	for (i = 1; i <= N; i++){
		if (Map[node][i] && V[i] == 0) {
			V[i] = 1;
			recall(i);
		}
	}
}

void output()
{
	int cnt = 0, i;

	for (i = 2; i <= N; i++) {
		if (V[i]) cnt++;
	}
	printf("%d", cnt);
}

int main()
{
	init();
	V[1] = 1;
	recall(1);
	output();
	return 0;
}