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
	if (L == Stick[i].l) {		// ����� ���̰� L
		pos = 0;
		dir = Stick[i].d;
		return;
	}

	double ct, v, l;	// �ݴ��ʱ��� ����Ⱑ �����ϴµ� �ɸ��� �ð�

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

	if (l1 == L || l2 == L) {	// �� ������ �ϳ��� ���̰� L �� ���
		return 0;
	}
	
	if ((pos1 <= pos2 && pos2 <= pos1 + l1) || (pos1 <= pos2 + l2 && pos2 + l2 <= pos1 + l1) || 
		(pos2 <= pos1 && pos1 <= pos2 + l2) || (pos2 <= pos1 + l1 && pos1 + l1 <= pos2 + l2)) {
		return 0;		// �� ���� ���� ������ ��ġ�� ���
	}

	t = 0;										// ���� �ð� ����

	// case 1 - 1 
	if (dir1 == 1 && dir2 == 0 && pos1 + l1 < pos2) {	// 0 �� ������, 1�� �������� �����δ�.
		t1 = pos1 / v1;
		t2 = (L - pos2 - l2) / v2;

		if (t1 < t2) {							// i�� ���ʿ� ���� ����
			pos1 = 0;
			dir1 = 0;							// i�� ���������� ���� ��ȯ
			pos2 += (v2 * t1);					// j�� ���������� �̵�
			t += t1;

		} else if (t1 > t2) {					// j�� �����ʿ� ���� ����
			pos2 = L - l2;
			dir2 = 1;							// j�� �������� ���� ��ȯ
			pos1 -= (v1 * t2);					// i�� �������� �̵�
			t += t2;

		} else {								// ���ÿ� ���� ����
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

		if (t1 < t2) {								// i�� �����ʿ� ���� ����
			pos1 = L - l1;
			dir1 = 1;								// i�� �������� ���� ��ȯ
			pos2 -= (v2 * t1);						// j�� �������� �̵�
			t += t1;

		} else if (t1 > t2) {						// j�� ���ʿ� ���� ����
			pos2 = 0;
			dir2 = 0;								// j�� ���������� �̵�
			pos1 += (v1 * t2);
			t += t2;
		} else {									// ���ÿ� ���� ����
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
			t += t1;								// j�� ������ ���� �����ϱ� ����, i�� j�� ������´�.
			return t;			

		} else {									// j�� ������ ���� ���� �����Ѵ�.
			pos1 += (v1 * t2);
			pos2 = L - l2;
			dir2 = 1;								// j�� ������ �ٲ��.
			t += t2;
		}
	}

	// case 2 - 2 
	if (dir1 == 1 && dir2 == 1 && pos1 + l1 < pos2) {
		t1 = pos1 / v1;
		t2 = (pos2 - pos1 - l1) / (v2 - v1);

		if (v1 < v2 && t2 <= t1) {					// i�� ���� ���� �����ϱ� ����, j�� i�� ������´�.
			t += t2;
			return t;

		} else {									// i�� ���� ���� ���� �����Ѵ�.
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
			t += t2;								// i�� ������ ���� �����ϱ� ����, j�� i�� ������´�.
			return t;

		} else {
			pos1 = L - l1;							// i�� ������ ���� ���� �����Ѵ�
			pos2 += (v2 * t1);
			dir1 = 1;								// i�� ������ �ٲ��.
			t += t1;
		}
	}

	// case 2 - 4 
	if (dir1 == 1 && dir2 == 1 && pos2 + l2 < pos1) {
		t1 = (pos1 - pos2 - l2) / (v1 - v2);
		t2 = pos2 / v2;

		if (v1 > v2 && t1 <= t2) {
			t += t1;							// j�� ���� ���� �����ϱ� ����, i�� j�� ������´�.
			return t;
			
		} else {								// j�� ���� ���� ���� ����
			pos2 = 0;
			pos1 -= (v1 * t2);
			dir2 = 0;							// j�� ������ �ٲ��.
			t += t2;
		}
	}

	// case - 3
	if (dir1 != dir2) {
		if (pos1 + l1 < pos2) {						// i�� j���� ���ʿ� �ִ�.
			t += (pos2 - pos1 - l1) / (v1 + v2);

		} else {									// j�� i���� ���ʿ� �ִ�.
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