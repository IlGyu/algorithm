#include <stdio.h>
#define Max_n 1024

int Depth, TwoDegree;
// int Tree[Max_n * 2];

void preorder(int node, int depth)
{
	int new_node, child_cnt = 0;

	if (Depth < depth)
		Depth = depth;

	scanf("%d", &new_node);
//	Tree[node * 2] = new_node;
	if (new_node != -1) {	// left child
		child_cnt++;
		preorder(node * 2, depth + 1);
	}

	scanf("%d", &new_node);
//	Tree[node * 2 + 1] = new_node;
	if (new_node != -1) {	// left child		
		child_cnt++;
		preorder(node * 2 + 1, depth + 1);
	}
	
	if (child_cnt == 2)
		TwoDegree++;
}

int main()
{
	int root;

	scanf("%d", &root);
//	Tree[1] = root;
	preorder(1, 1);

	printf("%d\n%d", TwoDegree, Depth);

	return 0;
}