#include <stdio.h>
#include <memory.h>
#define Max_n 1000

int T, N, M, K, X, Y;

int V[Max_n + 1][Max_n + 1];

void init()
{
	scanf("%d%d%d", &M, &N, &K);
}

void process()
{
	int dir[4][2] = {
		{ -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }
	};
	int y, x, k = 0;

	y = N;
	x = 1;
	V[y][x] = 1;
	K--;

	for (;;) {		
		if (K == 0) {
			Y = y;
			X = x;
			break;
		}

		y += dir[k][0];
		x += dir[k][1];

		if (y < 1 || x < 1 || y > N || x > M || V[y][x]) {
			y -= dir[k][0];
			x -= dir[k][1];
			k = (k + 1) % 4;
			continue;
		}
		V[y][x] = 1;
		K--;
		
	}
}

void output()
{
	if (K == 0) {
		printf("%d %d\n", X, N - Y + 1);
	} else {
		printf("0\n");
	}
}

int main()
{
	int i;

	scanf("%d", &T);

	for (i = 0; i < T; i++) {
		init();
		if (N*M >= K) process();
		printf("#testcase%d\n", i + 1);
		output();

		memset(V, 0, sizeof(V));
	}

	return 0;
}