#include <stdio.h>

int N, K;
char Stack[10];

void recall(int depth, int win)
{
	if (win == N) {		// win !
		Stack[depth] = '\0';
		printf("%s\n", Stack);
		K++;
		return;		
	}
	else if (depth - win == N) {		// lose !
		return;		
	}

	Stack[depth] = 'o';
	recall(depth + 1, win + 1);
	
	Stack[depth] = 'x';
	recall(depth + 1, win);
}

int main()
{
	scanf("%d", &N);
	recall(0, 0);
	printf("total %d case(s)", K);

	return 0;
}