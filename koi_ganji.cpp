#include <stdio.h>

int N;

int main()
{
	char str[3] = "F9";
	int n = 2013;

	scanf("%d", &N);
	if (N >= 2013) {
		while (n < N) {
			n++; 
			str[0] ++;
			str[1] ++;
			
			if (str[0] > 'L') {
				str[0] = 'A';
			}

			if (str[1] > '9') {
				str[1] = '0';
			}
			
		}
	} else {
		while (n > N) {
			n--;
			str[0] --;
			str[1] --;
			
			if (str[0] < 'A') {
				str[0] = 'L';
			}

			if (str[1] < '0') {
				str[1] = '9';
			}
		}
	}
	printf("%s", str);

	return 0;
}