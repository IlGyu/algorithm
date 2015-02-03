#include <stdio.h>
#include <string.h>

int N, L;

char A[10];
int Cut[10];
int Max, Sol[10], Count;

void init()
{
	scanf("%d %s", &N, A);
	L = strlen(A);
}

void recall(int index)
{
	int i, j, k, sum, num, gop, flag;

	if (index == L - 1){
		Cut[index] = 1;

		flag = sum = j = 0;
		for (i = 0; i < L; i++) {
			if (Cut[i] == 1) {
				num = 0;
				gop = 1;
				for (k = i; k >= j; k --) {
					num += (A[k] - '0') * gop;
					gop *= 10;		
				}
				if (N <= num && i != L - 1) {
					flag = 1;
					break;
				}
				sum += num;
				j = i + 1;
			}
		}
		if (flag == 0 && N >= sum) { // 조건을 만족
			if (Max < sum) {
				Max = sum;
				Count = 1;
				for (i = 0; i < L; i ++) {
					Sol[i] = Cut[i];
				}
			}
			else if (Max == sum) {
				Count ++;
			}
		}
		return;
	}

	recall(index + 1);
	Cut[index] = 1;		// 1이면 자른다
	recall(index + 1);
	Cut[index] = 0;		// 0이면 안자른다
}

void output()
{
	int i, j, k, num, gop;

	if (Max == 0) {		// error
		printf("error");
	}
	else if (Count > 1) {	// rejected
		printf("rejected");
	}
	else {
		printf("%d ", Max);
		
		j = 0;
		for (i = 0; i < L; i++) {
			if (Sol[i] == 1) {
				num = 0;
				gop = 1;
				for (k = i; k >= j; k--) {
					num += (A[k] - '0') * gop;
					gop *= 10;
				}
				j = i + 1;

				printf("%d ", num);
			}
		}
	}
}

int main()
{
	init();
	recall(0);
	output();
	return 0;
}