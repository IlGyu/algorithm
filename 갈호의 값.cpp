#include <stdio.h>
#include <string.h>

char Str[31];
int T, N;

/*
oper °ª
	0 -> ¼ýÀÚ
	1 -> (
	2 -> [
*/
struct data1 {
	int oper, value;
} Stack[31];
int Top;

int main()
{
	int t, i, close, sum, sw, sol;


	scanf("%d", &T);

	for (t = 0; t < T; t++) {

		scanf("%s", Str);
		N = strlen(Str);

		Top = sol = sw = 0;
		for (i = 0; i < N; i++) {
			if (Str[i] == '(') {
				Stack[Top++].oper = 1;
			}
			else if (Str[i] == '[') {
				Stack[Top++].oper = 2;
			}
			else {
				if (Str[i] == ')') close = 1;
				else close = 2;

				sum = 0;
				while (Top) {
					if (Stack[Top - 1].oper == 0) {
						sum += Stack[Top - 1].value;
						Top--;
					}
					else if (Stack[Top - 1].oper == close) {
						Stack[Top - 1].oper = 0;
						if (close == 1) {
							if (sum == 0) Stack[Top - 1].value = 2;
							else Stack[Top - 1].value = 2 * sum;
						}
						else {
							if (sum == 0) Stack[Top - 1].value = 3;
							else Stack[Top - 1].value = 3 * sum;
						}
						break;
					}
					else {
						sw = 1;
						break;
					}
				}
				if (sw) break;
			}
		}
		while (Top) {
			if (Stack[Top - 1].oper) {
				sw = 1;
				break;
			}
			sol += Stack[--Top].value;
		}
		printf("#testcase%d\n", t + 1);
		if (sw == 0) printf("%d\n", sol);
		else printf("0\n");
	}

	return 0;
}