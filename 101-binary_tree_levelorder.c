#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_levelorder - Finds the lowest common ancestor of two nodes.
 *
 * @tree: A pointer to the root of the tree.
 * @func: the function to apply to every node of the
 * tree
 *
 * Return: Pointer to the lowest common ancestor node or NULL if not found.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t binary_height = binary_tree_height(tree);
	size_t i;

	if (!tree)
		return;
	for (i = 0; i < binary_height; i++)
		current_level(tree, i, func);
}

/**
 * binary_tree_height - function that measures the
 * height of a binary tree
 * @tree: a pointer to the root node of
 * the tree to measure the height.
 *
 * Return: an int
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height >= right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

/**
 * current_level - function that measures the
 * height of a binary tree
 * @tree: a pointer to the root node of the tree.
 * @level: the node level
 * @func: a pointer to function to apply to every
 * node
 *
 * Return: an int
 */
void current_level(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (tree == NULL)
		return;

	if (level == 0)
		func(tree->n);

	else if (level > 1)
	{
		current_level(tree->left, level - 1, func);
		current_level(tree->right, level - 1, func);
	}
}
