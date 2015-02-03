#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<memory.h>
#define Max_n 100
using namespace std;

int T, N, M;

struct data1{
	double x, y;
}Data[Max_n + 1];

double L, Dis[Max_n*Max_n], Map[Max_n + 1][Max_n + 1], Sol;
int Visit[Max_n + 1];

bool compare(const double &i, const double &j)
{
	return i < j;
}

void flood_fill(int index)
{
	int i;

	for (i = 1; i <= N; i++){
		if (Map[index][i] <= L && Visit[i] == 0){
			Visit[i] = 1;
			flood_fill(i);
		}
	}
}

void process()
{
	int i, j, st, ed, mid, sw;

	M = 0;
	for (i = 1; i <= N; i++){
		for (j = i + 1; j <= N; j++){
			Map[i][j] = Map[j][i] = sqrt((Data[i].x - Data[j].x)*(Data[i].x - Data[j].x) + (Data[i].y - Data[j].y)*(Data[i].y - Data[j].y));
			Dis[M++] = Map[i][j];
		}
	}
	sort(Dis, Dis + M, compare);

	st = 0; ed = M - 1;
	while (st <= ed){
		mid = (st + ed) / 2;
		L = Dis[mid];
		memset(Visit, 0, sizeof(Visit));
		Visit[1] = 1;
		flood_fill(1);
		sw = 0;
		for (i = 1; i <= N; i++){
			if (Visit[i] == 0){
				sw = 1;
				break;
			}
		}
		if (sw == 0){
			ed = mid - 1;
			Sol = L;
		}
		else{
			st = mid + 1;
		}
	}
}

int main()
{
	int i, j;

	scanf("%d", &T);

	for (i = 0; i<T; i++){
		scanf("%d", &N);
		for (j = 1; j <= N; j++){
			scanf("%lf%lf", &Data[j].x, &Data[j].y);
		}
		process();
		printf("%0.2lf\n", Sol);
	}
	return 0;
}