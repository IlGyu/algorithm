#include <stdio.h>

int main()
{
	char str[10] = "EABCD";
	int i, j, num, cnt;

	for (i = 0; i < 3; i++) {
		cnt = 0;
		for (j = 0; j < 4; j++) {
			scanf("%d", &num);
			cnt += (!num);
		}
		printf("%c\n", str[cnt]);
	}
}