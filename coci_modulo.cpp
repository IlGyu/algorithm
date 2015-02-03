#include <stdio.h>

int main()
{
	int A[42] = { 0, };
	int i, n, count = 0;

	for (i = 0; i < 10; i++) {
		scanf("%d", &n);
		A[n % 42] = 1;
	}
	for (i = 0; i < 42; i++) {
		if (A[i]) count++;
	}
	printf("%d", count);
	
	return 0;
}