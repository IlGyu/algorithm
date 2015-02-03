#include <stdio.h>
#define Max_n 100000

int N, K;

int V[Max_n * 2];
int Q[Max_n * 2], Front, Back;

void init()
{
	scanf("%d %d", &N, &K);
}

void inque(int a)
{
	Q[Back] = a;
	Back++;
}

void deque(int &a)
{
	a = Q[Front];
	Front++;
}

void process()
{
	int pos;

	V[N] = 1;
	inque(N);
	while (Front <= Back) {
		deque(pos);

		if (pos == K) break;

		if (pos && V[pos - 1] == 0) {
			V[pos - 1] = V[pos] + 1;
			inque(pos - 1);
		}

		if (V[pos + 1] == 0) {
			V[pos + 1] = V[pos] + 1;
			inque(pos + 1);
		}

		if (pos < K * 2 && V[pos * 2] == 0) {
			V[pos * 2] = V[pos] + 1;
			inque(pos * 2);
		}
	}
}

void output()
{
	printf("%d\n", V[K] - 1);
}

int main()
{
	init();
	process();
	output();
	return 0;
}