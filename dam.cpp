#include <stdio.h>
#define Max_n 100

int N, T, Sol;
int Map[Max_n + 1][Max_n + 1];
int Q[Max_n*Max_n][2], Front, Back;
int Sy, Sx;

void init()
{
	int i, j;

	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++){
			scanf("%d", &Map[i][j]);
			if (Map[i][j] == 1) Map[i][j] = -1;
		}
	}
	scanf("%d%d%d", &Sx, &Sy, &T);
}

void inque(int a, int b)
{
	Q[Back][0] = a;
	Q[Back][1] = b;
	Back++;
}

void deque(int &a, int &b)
{
	a = Q[Front][0];
	b = Q[Front][1];
	Front++;
}

void process()
{
	int dir[4][2] = {
		{ -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }
	};
	int y, x, i, q, w;
	
	Map[Sy][Sx] = 1;
	inque(Sy, Sx);
	while (Front <= Back) {
		deque(y, x);
		for (i = 0; i < 4; i++) {
			q = y + dir[i][0];
			w = x + dir[i][1];
			
			if (q >= 1 && w >= 1 && q <= N && w <= N) {
				if (Map[q][w] == 0) {
					Map[q][w] = Map[y][x] + 1;
					inque(q, w);
				}
			}
		}
	}

	for (y = 1; y <= N; y++) { 
		for (x = 1; x <= N; x++) {
			if (Map[y][x] == T + 1) {
				Sol++;
			}
		}
	}
}

void output()
{
	if (Sol == 0) {
		printf("OH, MY GOD");
	} else {
		printf("%d", Sol);
	}
}

int main()
{
	init();
	process();
	output();
	return 0;
}