#include <stdio.h>
#define Max_n 10

int N, Sw;

int Oper[Max_n], Sol[2][Max_n], V[Max_n];

void init()
{
	char str[10];
	int i;

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%s", str);
		Oper[i] = str[0];
	}
}

void findMax(int index)
{
	int i;

	if (index == N + 1) {
		Sw = 1;
		return;
	}

	for (i = 9; i >= 0; i--) {
		if (V[i] == 0) {
			if (Oper[index - 1] == '<') {
				if (Sol[0][index - 1] < i) {
					Sol[0][index] = i;
					V[i] = 1;
					findMax(index + 1);
					V[i] = 0;
				}
			}
			else {
				if (Sol[0][index - 1] > i) {
					Sol[0][index] = i;
					V[i] = 1;
					findMax(index + 1);
					V[i] = 0;
				}
			}
			if (Sw) return;
		}
	}
}

void findMin(int index)
{
	int i;

	if (index == N + 1) {
		Sw = 1;
		return;
	}

	for (i = 0; i <= 9; i++) {
		if (V[i] == 0) {
			if (Oper[index - 1] == '<') {
				if (Sol[1][index - 1] < i) {
					Sol[1][index] = i;
					V[i] = 1;
					findMin(index + 1);
					V[i] = 0;
				}
			}
			else {
				if (Sol[1][index - 1] > i) {
					Sol[1][index] = i;
					V[i] = 1;
					findMin(index + 1);
					V[i] = 0;
				}
			}
			if (Sw) return;
		}
	}
}

void process()
{
	int i;

	for (i = 9; i >= 0; i--) {
		Sol[0][0] = i;
		V[i] = 1;
		findMax(1);
		V[i] = 0;
		if (Sw) break;
	}
	Sw = 0;
	for (i = 0; i <= 9; i++) {
		Sol[1][0] = i;
		V[i] = 1;
		findMin(1);
		V[i] = 0;
		if (Sw) break;
	}
}

void output()
{
	int i;

	for (i = 0; i <= N; i++) {
		printf("%d", Sol[0][i]);
	}
	printf("\n");
	for (i = 0; i <= N; i++) {
		printf("%d", Sol[1][i]);
	}
}

int main()
{
	init();
	process();
	output();
	return 0;
}