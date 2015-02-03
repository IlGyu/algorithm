#include <stdio.h>
#define Max_n 1024

int Tree[Max_n * 2];

void preorder(int node)
{
	int new_node;

	scanf("%d", &new_node);
	Tree[node * 2] = new_node;
	if (new_node != -1) {	// left child
		preorder(node * 2);
	}
		
	scanf("%d", &new_node);
	Tree[node * 2 + 1] = new_node;
	if (new_node != -1) {	// right child		
		preorder(node * 2 + 1);
	}
}

void postorder(int node)
{
	if (Tree[node * 2] != -1) 
		postorder(node * 2);

	if (Tree[node * 2 + 1] != -1) 
		postorder(node * 2 + 1);

	printf("%d ", Tree[node]);
}

int main()
{
	int root;

	scanf("%d", &root);
	Tree[1] = root;
	preorder(1);
	postorder(1);

	return 0;
}