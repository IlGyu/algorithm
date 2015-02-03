#include <stdio.h>
#define Max_n 100

int N, Sol;

int A[Max_n];
int Stack[Max_n], Top;

void init()
{
	int i;

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
}

void process()
{
	int i = 1, j = 0;

	for (;;) {
		if (Top && A[j] == Stack[Top - 1]) {
			j ++;
			Stack[--Top] = 0;	// pop

			if (j == N && Top == 0) {
				Sol = 1;
				break;
			}
		} else {
			Stack[Top++] = i;	// push
			if (i == N + 1) break;
			i ++;
		}
	}
}

void output()
{
	if (Sol) printf("YES");
	else printf("NO");
}

int main()
{
	init();
	process();
	output();
	return 0;
}