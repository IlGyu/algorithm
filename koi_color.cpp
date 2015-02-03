#include <stdio.h>
#define Max_n 100
#define Max_s 1000

int N, Sol[Max_n];

struct data1{
	int sy, sx, h, w;
}Rect[Max_n];
int Map[Max_s + 1][Max_s + 1];

void init()
{
	int i;

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d %d %d %d", &Rect[i].sx, &Rect[i].sy, &Rect[i].w, &Rect[i].h);
	}
}

void process()
{
	int i, j, k;

	for (i = 0; i < N; i++) {
		for (j = Rect[i].sy; j <= Rect[i].sy + Rect[i].h - 1; j ++) {
			for (k = Rect[i].sx; k <= Rect[i].sx + Rect[i].w - 1; k ++) {
				Map[j][k] = i + 1;
			}
		}
	}

	for (j = 0; j <= Max_s; j++) {
		for (k = 0; k <= Max_s; k++) {
			if (Map[j][k]) {
				Sol[Map[j][k] - 1] ++;
			}
		}
	}
}

void output()
{
	int i;

	for (i = 0; i < N; i++){
		printf("%d\n", Sol[i]);
	}
}

int main()
{
	init();
	process();
	output();
	return 0;
}