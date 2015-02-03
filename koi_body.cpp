#include <stdio.h>
#define Max_n 50

int N;

struct data1 {
	int a, b;
}Data[Max_n + 1];
int Sol[Max_n + 1];

void init()
{
	int i;

	scanf("%d", &N);

	for (i = 1; i <= N; i++) {
		scanf("%d%d", &Data[i].a, &Data[i].b);
	}
}

void process()
{
	int i, j;

	for (i = 1; i <= N; i++) {		
		for (j = 1; j <= N; j++) {
			if (i == j) continue;

			if (Data[i].a < Data[j].a && Data[i].b < Data[j].b) {
				Sol[i]++;
			}
		}
	}
}

void output()
{
	int i;

	for (i = 1; i <= N; i++) {
		printf("%d ", Sol[i] + 1);
	}
}

int main()
{
	init();
	process();
	output();
	return 0;
}