#include<stdio.h>
#include<string.h>
#define Max_n 100

int T, N, J;

struct data1{
	int x, y;
}Data[Max_n + 2];
int V[Max_n + 2];

void recall(int node)
{
	int i;

	for (i = 1; i <= N + 1; i++){
		if (V[i] == 0 && (Data[node].x - Data[i].x)*(Data[node].x - Data[i].x) 
							+ (Data[node].y - Data[i].y)*(Data[node].y - Data[i].y) <= J*J) {
			V[i] = 1;
			recall(i);
		}
	}
}

int main()
{
	int i, j;

	scanf("%d", &T);

	for (i = 0; i<T; i++){
		scanf("%d", &J);
		scanf("%d%d%d%d", &Data[0].x, &Data[0].y, &Data[1].x, &Data[1].y);
		scanf("%d", &N);
		for (j = 2; j <= N + 1; j++){
			scanf("%d%d", &Data[j].x, &Data[j].y);
		}
		V[0] = 1;
		recall(0);
		if (V[1]) printf("YES\n");
		else printf("NO\n");
		memset(V, 0, sizeof(V));
	}
	return 0;
}