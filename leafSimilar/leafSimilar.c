/**
 * 叶子相似的树
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdio.h>
#include <stdbool.h>

struct TreeNode
{
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct LinkNode
{
    struct TreeNode *value;
    struct TreeNode *next;
};

bool isLeaf(struct TreeNode *node)
{
    return (node->left == NULL) && (node->right == NULL);
}

void getLeaf(struct LinkNode *link)
{
    struct LinkNode *next = link;
    //(int*)malloc(2*sizeof(int));
    while (next != NULL)
    {
        if(next->value != NULL){

        }
    }
}

bool leafSimilar(struct TreeNode *root1, struct TreeNode *root2)
{
    return true;
}