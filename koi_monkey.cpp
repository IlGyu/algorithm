#include <stdio.h>
#define Max_n 100000

int N;

int List[Max_n + 1][3], Lcnt[Max_n + 1];
int Group[Max_n + 1], A[Max_n + 1];

void init()
{
	int i, j;

	scanf("%d", &N);

	for (i = 1; i <= N; i++) {
		scanf("%d", &Lcnt[i]);
		for (j = 0; j < Lcnt[i]; j++) {
			scanf("%d", &List[i][j]);
		}
	}
}

void process()
{
	int i, j, k, index, next;

	for (i = N / 2 + 1; i <= N; i++) Group[i] = 1;

	for (i = 1; i <= N; i++) {
		for (j = 0; j < Lcnt[i]; j++) {
			k = List[i][j];
			if (Group[i] == Group[k]) A[i] ++;
		}
	}

	for (;;) {
		index = 0;
		for (i = 1; i <= N; i++) {
			if (A[i] > 1) {
				index = i;
				break;
			}
		}
		if (index == 0) break;
		
		next = index;
		while(next) {
			index = next;
			next = 0;
			
			A[index] = Lcnt[index] - A[index];
			for (i = 0; i < Lcnt[index]; i++) {
				j = List[index][i];
				if (Group[index] == Group[j]) {
					A[j] --;
				} else {
					A[j] ++;

					if (A[j] > 1) {
						next = j;
					}
				}
			}

			Group[index] = !Group[index];			
		}
	}
}

void output()
{
	int i;

	for (i = 1; i <= N; i++) {
		if (Group[i] == 0) printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= N; i++) {
		if (Group[i]) printf("%d ", i);
	}
}

int main()
{
	init();
	process();
	output();
	return 0;
}