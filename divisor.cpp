#include <stdio.h>

int N, Sol;

int main()
{
	int i, cnt = 0, t, j = 0;

	scanf("%d", &t);
	while (t) {
		t--;
		scanf("%d", &N);
		Sol = 0;

		for (i = 1; i * i <= N; i++) {
			if (N%i == 0) {
				Sol += 2;
			}
		}
		i--;
		if (i*i == N) Sol--;

		printf("#testcase%d\n", ++j);
		printf("%d\n", Sol);
	}
	return 0;
}