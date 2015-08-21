/*
maman21 - adjacency.c
* Description:
The Program seeks a directed route beween parent and descendant nodes, in a tree which is represented with the help of an adjacency matrix.
It will scan the matrix starting from the descendant up to the parent node.
For each Iteration, it seeks for the parent and check if it is the parent node in question.
If it does, it will return TRUE.
If it does not, it is possible it's a part of the route, therfore it will scan the next column using the current parent's index.
The loop checks that it did not exceed the parent node index, that will indicate that there is not route beween the nodes and will return FALSE.
* Assumptions:
1. Input is valid.
2. Each node has only one parent.
*/

#include <stdio.h>

#define N 11
#define TRUE 1
#define FALSE 0

typedef int adj_mat[N][N];

void fill_matrix(adj_mat matrix)
{	/* this function will fill the matrix with the user data */
	int i,j; /* loops indexes */
  	printf("Enter Values For A %dX%d Sized Matrix:\n",N,N);
	for (i = 0; i < N; i++)
	{
		for (j = 0;  j < N; j++)
		{
      			scanf("%d",&matrix[i][j]);
		}
	}
}


int path(adj_mat matrix, int parent_node, int descendant_node)
{	/* This function seeks for a path between parent_node and descendant_node in a given matrix */
	int i, j, parent_node_index, descendant_node_index;

    if (parent_node >= descendant_node)
    {   /* There's no point in searching for a parent with a larger index than its descendant */
    	return FALSE;
    }
    parent_node_index = parent_node-1; /* This is in order to handle the index offset presented in the question */
    descendant_node_index = descendant_node-1; /* This is in order to handle the index offset presented in the question */
    i=descendant_node_index;
	while (i > parent_node_index)
    {	/* Iterate as long as i does not exceed the parent's index */
		for (j = 0;  j < N; j++)
		{	/* Iterate through the column and search for a parent node */
			if (matrix[j][i] == TRUE)
			{	/* Found a parent node */
				if (j==parent_node_index)
				{	/* Check if this is the requested parent node */
					return TRUE;
				}
				else
				{   /* This is not the requested parent, but it might be part of the route. Hop to the next column by curent parent index. */
					i=j;
				}
				/* Each node has only one parent, therefore we may skip remained iterations for this column. */
				break;
			}
		}
    }
	/* If the above loop was exhausted, it means that there is no route between the two nodes. */
	return FALSE;
}


int main()
{
	adj_mat matrix;
	int parent_node, descendant_node;

	fill_matrix(matrix);

	printf("Enter Two Integer Values, First Value for Parent Node And Second Value For Descendant:\n");
	scanf("%d %d",&parent_node, &descendant_node);

	if (path(matrix, parent_node, descendant_node))
	{
		printf("\nFound a Valid Path Between Parent Node %d And Descendant Node %d\n",parent_node, descendant_node);
	    return 0;
	}
	else
	{
		printf("\nNo Valid Path Between Parent Node %d And Descendant Node %d\n",parent_node, descendant_node);
	    return 1;
	}
}
