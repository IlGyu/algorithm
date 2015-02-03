#include <stdio.h>
#define Max_n 3000

/*
	시간이 L/2 일때, 모든 막대들은 L/2에 위치하는 부분이 존재한다.
	따라서 L/2 시간안에 꼭대기 층에 올라갈 수 있다.

	길이가 L/2 이하인 막대들은 시작 위치가 L/2이 되고,
	길이가 L/2 이상인 막대들은 항상 L/2을 포함한다.

	또한, 인접한 두 막대들 중 가장 늦게 만나는 시점에, 모든 막대들이 중앙에 있음을 알 수 있다.
	따라서 O(N) !
*/

int N, L;

struct data1 {
	int l, d;
} Stick[Max_n + 1];

int main()
{
	int i, sol = 0;

	scanf("%d%d", &N, &L);

	for (i = 1; i <= N; i++) {
		scanf("%d%d", &Stick[i].l, &Stick[i].d);
	}
	for (i = 2; i <= N; i++) {
		if (Stick[i - 1].d != Stick[i].d) {
			if (sol < (L - Stick[i - 1].l - Stick[i].l) / 2) {
				sol = (L - Stick[i - 1].l - Stick[i].l) / 2;
			}
		}
	}
	printf("%d", sol);

	return 0;
}