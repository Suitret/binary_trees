#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 0 or 1
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int has_incomplete = 0, front = 0, rear = -1, nodes_count = 0, i;
	binary_tree_t **queue = NULL, *node = NULL;

	queue = (binary_tree_t **)malloc(sizeof(binary_tree_t *) * 1000);
	if (tree == NULL || queue == NULL)
		return (0);
	queue[++rear] = (binary_tree_t *)tree;
	while (front <= rear)
	{
		node = queue[front++];
		if (node)
		{
			if (has_incomplete)
			{
				free(queue);
				return (0);
			}
			nodes_count++;
			queue[++rear] = node->left;
			queue[++rear] = node->right;
			if (node->left == NULL || node->right == NULL)
				has_incomplete = 1;
		}
		else
		{
			queue[++rear] = NULL;
			queue[++rear] = NULL;
		}
	}
	for (i = 0; i < nodes_count; i++)
	{
		if (queue[i] == NULL)
		{
			free(queue);
			return (0);
		}
	}
	free(queue);
	return (1);
}
