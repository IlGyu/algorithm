#include <stdio.h>
#define Max_n 3000

/*
	�ð��� L/2 �϶�, ��� ������� L/2�� ��ġ�ϴ� �κ��� �����Ѵ�.
	���� L/2 �ð��ȿ� ����� ���� �ö� �� �ִ�.

	���̰� L/2 ������ ������� ���� ��ġ�� L/2�� �ǰ�,
	���̰� L/2 �̻��� ������� �׻� L/2�� �����Ѵ�.

	����, ������ �� ����� �� ���� �ʰ� ������ ������, ��� ������� �߾ӿ� ������ �� �� �ִ�.
	���� O(N) !
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