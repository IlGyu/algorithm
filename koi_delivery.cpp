#include <stdio.h>
#include <algorithm>
#define Max_n 2000
#define Max_m 10000
#define MAX 1999999999
using namespace std;

int N, C, M, Sol;

struct data1 {
	int a, b, c;
} Data[Max_m + 1];

int A[Max_n + 1];

void init()
{
	int i;

	scanf("%d%d%d", &N, &C, &M);

	for (i = 1; i <= M; i++) {
		scanf("%d%d%d", &Data[i].a, &Data[i].b, &Data[i].c);
	}
}

int compare(const struct data1 &a, const struct data1 &b)
{
	if (a.b < b.b) return 1;
	if (a.b > b.a) return 0;
	if (a.a < b.a) return 1;
	return 0;
}

void process()
{
	int i, j, min;

	sort(Data + 1, Data + 1 + M, compare);

	for (i = 1; i <= M; i++) {
		min = MAX;
		for (j = Data[i].a; j < Data[i].b; j++) {
			if (min > C - A[j]) {
				min = C - A[j];
			}
		}
		if (min < 0) continue;
		if (min > Data[i].c) min = Data[i].c;
		Sol += min;
		for (j = Data[i].a; j < Data[i].b; j++) {
			A[j] += min;
		}
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