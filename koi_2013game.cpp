#include <stdio.h>
#include <algorithm>
#define Max_n 100000
using namespace std;

int N, L;

struct data1 {
	int t, d, l;
} Stick[Max_n + 1];
int SortT[Max_n + 1], SortD[Max_n + 1];
long long D[Max_n + 1][2], Sol;

void init()
{
	int i;

	scanf("%d%d", &N, &L);

	for (i = 1; i <= N; i++) {
		scanf("%d%d", &Stick[i].t, &Stick[i].d);
	}
}

int compare(const struct data1 &a, const struct data1 &b)
{
	if (a.t < b.t) return 1;
	if (a.t > b.t) return 0;
	if (a.d < b.d) return 1;
	return 0;
}

void process()
{
	long long v1, v2;
	int i, j, st, ed, mid, t, d;

	for (i = 1; i <= N; i++) {
		SortT[i] = Stick[i].t;
		SortD[i] = Stick[i].d;
		Stick[i].l = Stick[i].t - Stick[i].d;
		if (Stick[i].l < 0) Stick[i].l *= -1;
		Stick[i].l += L;
	}

	sort(SortT + 1, SortT + N + 1);
	sort(SortD + 1, SortD + N + 1);

	for (i = 1; i <= N; i++) {
		st = 1; ed = N;
		while (st <= ed) {
			mid = (st + ed) / 2;

			if (Stick[i].t < SortT[mid]) {
				ed = mid - 1;				
			} else if (Stick[i].t > SortT[mid]) {
				st = mid + 1;
			} else {
				j = mid;
				ed = mid - 1;
			}
		}
		Stick[i].t = j;
		
		st = 1; ed = N;
		while (st <= ed) {
			mid = (st + ed) / 2;

			if (Stick[i].d < SortD[mid]) {
				ed = mid - 1;				
			} else if (Stick[i].d > SortD[mid]) {
				st = mid + 1;
			} else {
				j = mid;
				ed = mid - 1;
			}
		}
		Stick[i].d = j;
	}
	sort(Stick + 1, Stick + N + 1, compare);

	for (i = 1; i <= N; i++) {
		t = Stick[i].t;
		d = Stick[i].d;
		v1 = D[d][1];
		v2 = D[t][0];

		if (D[t][0] < v1 + Stick[i].l) D[t][0] = v1 + Stick[i].l;
		if (D[d][1] < v2 + Stick[i].l) D[d][1] = v2 + Stick[i].l;
		if (Sol < D[t][0]) Sol = D[t][0];
		if (Sol < D[d][1]) Sol = D[d][1];
	}
}

void output()
{
	printf("%lld", Sol);
}

int main()
{
	init();
	process();
	output();
	return 0;
}