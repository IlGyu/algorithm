#include <stdio.h>
#define Max_n 30

int N, K;
char S[Max_n + 1];

void recall(int depth, int cnt)
{
	if (depth == N) {
		if (cnt == K) {
			printf("%s\n", S);
		}
		return;
	}

	if (cnt + 1 <= K) {
		S[depth] = '1';
		recall(depth + 1, cnt + 1);
	}
	S[depth] = '0';
	recall(depth + 1, cnt);
}

int main()
{
	scanf("%d %d", &N, &K);
	S[N] = '\0';
	recall(0, 0);

	return 0;
}