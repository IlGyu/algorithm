#include <stdio.h>
#define Max_n 1000
#define MAX 1999999999

int N, L, K;

struct data1 {
	int d;
	double l, v;
} Stick[Max_n + 1];

double D[Max_n + 1];

void init()
{
	int i;

	scanf("%d%d%d", &N, &L, &K);

	for (i = 1; i <= N; i++) {
		scanf("%lf%d%lf", &Stick[i].l, &Stick[i].d, &Stick[i].v);
	}
}

void getStickState(double t, int i, double &pos, int &dir)
{
	if (L == Stick[i].l) {		// 막대기 길이가 L
		pos = 0;
		dir = Stick[i].d;
		return;
	}

	double ct, v, l;	// 반대쪽까지 막대기가 도달하는데 걸리는 시간

	l = Stick[i].l;
	v = Stick[i].v;
	dir = Stick[i].d;
	if (dir == 0) pos = 0;
	else pos = L;

	ct = (L - l) / v;
	for (;;) {		
		if (dir == 0) {
			if (t >= ct) {
				t -= ct;
				pos = L - l;
				dir = 1;
			} else {
				pos = v * t;
				break;
			}
		} else {			
			if (t >= ct) {
				t -= ct;
				pos = 0;
				dir = 0;
			} else {
				pos = L - l - v * t;
				break;
			}
		}
	}
}

double getMeetingTime(int i, int j, double pos1, int dir1, double pos2, int dir2)
{
	double v1, v2, t, t1, t2, l1, l2;

	l1 = Stick[i].l;
	v1 = Stick[i].v;
	l2 = Stick[j].l;
	v2 = Stick[j].v;

	if (l1 == L || l2 == L) {	// 두 막대중 하나의 길이가 L 인 경우
		return 0;
	}
	
	if ((pos1 <= pos2 && pos2 <= pos1 + l1) || (pos1 <= pos2 + l2 && pos2 + l2 <= pos1 + l1) || 
		(pos2 <= pos1 && pos1 <= pos2 + l2) || (pos2 <= pos1 + l1 && pos1 + l1 <= pos2 + l2)) {
		return 0;		// 두 개의 막대 구간이 겹치는 경우
	}

	t = 0;										// 진행 시간 저장

	// case 1 - 1 
	if (dir1 == 1 && dir2 == 0 && pos1 + l1 < pos2) {	// 0 이 오른쪽, 1이 왼쪽으로 움직인다.
		t1 = pos1 / v1;
		t2 = (L - pos2 - l2) / v2;

		if (t1 < t2) {							// i가 왼쪽에 먼저 도착
			pos1 = 0;
			dir1 = 0;							// i는 오른쪽으로 방향 전환
			pos2 += (v2 * t1);					// j는 오른쪽으로 이동
			t += t1;

		} else if (t1 > t2) {					// j가 오른쪽에 먼저 도착
			pos2 = L - l2;
			dir2 = 1;							// j는 왼쪽으로 방향 전환
			pos1 -= (v1 * t2);					// i는 왼쪽으로 이동
			t += t2;

		} else {								// 동시에 벽에 도착
			pos1 = 0;
			dir1 = 0;
			pos2 = L - l2;
			dir2 = 1;

			t += t1;
		}
	}

	// case 1 - 2 
	if (dir1 == 0 && dir2 == 1 && pos2 + l2 < pos1) {
		t1 = (L - pos1) / v1;
		t2 = pos2 / v2;

		if (t1 < t2) {								// i가 오른쪽에 먼저 도착
			pos1 = L - l1;
			dir1 = 1;								// i는 왼쪽으로 방향 전환
			pos2 -= (v2 * t1);						// j는 왼쪽으로 이동
			t += t1;

		} else if (t1 > t2) {						// j가 왼쪽에 먼저 도착
			pos2 = 0;
			dir2 = 0;								// j는 오른쪽으로 이동
			pos1 += (v1 * t2);
			t += t2;
		} else {									// 동시에 벽에 도착
			pos1 = L - l1;
			dir1 = 1;
			pos2 = 0;
			dir2 = 0;

			t += t1;
		}
	}

	// case 2 - 1 
	if (dir1 == 0 && dir2 == 0 && pos1 + l1 < pos2) {
		t1 = (pos2 - pos1 - l1) / (v1 - v2);
		t2 = (L - pos2 - l2) / v2;

		if (v1 > v2 && t1 <= t2) {									
			t += t1;								// j가 오른쪽 벽에 도달하기 전에, i가 j를 따라잡는다.
			return t;			

		} else {									// j가 오른쪽 벽에 먼저 도달한다.
			pos1 += (v1 * t2);
			pos2 = L - l2;
			dir2 = 1;								// j의 방향이 바뀐다.
			t += t2;
		}
	}

	// case 2 - 2 
	if (dir1 == 1 && dir2 == 1 && pos1 + l1 < pos2) {
		t1 = pos1 / v1;
		t2 = (pos2 - pos1 - l1) / (v2 - v1);

		if (v1 < v2 && t2 <= t1) {					// i가 왼쪽 벽에 도달하기 전에, j가 i를 따라잡는다.
			t += t2;
			return t;

		} else {									// i가 왼쪽 벽에 먼저 도달한다.
			pos1 = 0;
			pos2 -= (v2 * t1);
			dir1 = 0;
			t += t1;
		}
	}

	// case 2 - 3 
	if (dir1 == 0 && dir2 == 0 && pos2 + l2 < pos1) {
		t1 = (L - pos1 - l1) / v1;
		t2 = (pos1 - pos2 - l2) / (v2 - v1);

		if (v2 > v1 && t2 <= t1) {
			t += t2;								// i가 오른쪽 벽에 도달하기 전에, j가 i를 따라잡는다.
			return t;

		} else {
			pos1 = L - l1;							// i가 오른쪽 벽에 먼저 도달한다
			pos2 += (v2 * t1);
			dir1 = 1;								// i의 방향이 바뀐다.
			t += t1;
		}
	}

	// case 2 - 4 
	if (dir1 == 1 && dir2 == 1 && pos2 + l2 < pos1) {
		t1 = (pos1 - pos2 - l2) / (v1 - v2);
		t2 = pos2 / v2;

		if (v1 > v2 && t1 <= t2) {
			t += t1;							// j가 왼쪽 벽에 도달하기 전에, i가 j를 따라잡는다.
			return t;
			
		} else {								// j가 왼쪽 벽에 먼저 도착
			pos2 = 0;
			pos1 -= (v1 * t2);
			dir2 = 0;							// j의 방향이 바뀐다.
			t += t2;
		}
	}

	// case - 3
	if (dir1 != dir2) {
		if (pos1 + l1 < pos2) {						// i가 j보다 왼쪽에 있다.
			t += (pos2 - pos1 - l1) / (v1 + v2);

		} else {									// j가 i보다 왼쪽에 있다.
			t += (pos1 - pos2 - l2) / (v1 + v2);
		}
	}

	return t;
}

void process()
{
	int i, j, k, dir1, dir2;
	double pos1, pos2, t;

	for (i = 2; i <= N; i++) D[i] = MAX;

	for (i = 1; i <= N - 1; i++) {
		k = i + K;
		if (k >= N) k = N;
		
		getStickState(D[i], i, pos1, dir1);
		for (j = i + 1; j <= k; j++) {
			getStickState(D[i], j, pos2, dir2);

			t = D[i] + getMeetingTime(i, j, pos1, dir1, pos2, dir2);
			if (D[j] > t) D[j] = t;
		}
	}
}

void output()
{
	printf("%0.5lf", D[N]);
}

int main()
{
	init();
	process();
	output();
	return 0;
}