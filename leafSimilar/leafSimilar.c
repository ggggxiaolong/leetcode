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
#include <malloc.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct LinkNode
{
    struct TreeNode *value;
    struct LinkNode *next;
} LinkNode, *pLinkNode;

typedef struct LinkHead
{
    int size;
    struct LinkNode *root;
} LinkHead, *pLinkHead;

bool isOnlyLeft(struct TreeNode *node)
{
    return node->left != NULL && node->right == NULL;
}

bool isOnlyRight(struct TreeNode *node)
{
    return node->left == NULL && node->right != NULL;
}

bool hasTwoChild(struct TreeNode *node)
{
    return node->left != NULL && node->right != NULL;
}

void getLeaf(struct LinkHead *link)
{
    struct LinkNode *next = link->root;
    struct LinkNode *temp;
    bool isNotEnd;
    while (next != NULL)
    {
        isNotEnd = false;

        if (hasTwoChild(next->value))
        {
            //有两个孩子
            temp = (pLinkNode)malloc(sizeof(LinkNode));
            temp->value = next->value->right;
            temp->next = next->next;
            next->value = next->value->left;
            next->next = temp;
            link->size = link->size + 1;
            continue;
        }
        else if (isOnlyLeft(next->value))
        {
            //只有左孩子
            next->value = next->value->left;
            continue;
        }
        else if (isOnlyRight(next->value))
        {
            //只有右孩子
            next->value = next->value->right;
            continue;
        }
        next = next->next;
    }
}

bool isNodeSame(struct TreeNode *node1, struct TreeNode *node2)
{
    return node1->val == node2->val;
}

void printLink(pLinkHead link){
    printf("size: %d\n",link->size);
    pLinkNode tem = link->root;
    while (tem != NULL)
    {
        printf("%d->", tem->value->val);
        tem = tem->next;
    }
    printf("\n");
}

bool leafSimilar(struct TreeNode *root1, struct TreeNode *root2)
{
    pLinkNode link1 = (pLinkNode)malloc(sizeof(LinkNode));
    pLinkNode link2 = (pLinkNode)malloc(sizeof(LinkNode));
    pLinkHead head1 = (pLinkHead)malloc(sizeof(LinkHead));
    pLinkHead head2 = (pLinkHead)malloc(sizeof(LinkHead));
    link1->value = root1;
    link2->value = root2;
    head1->root = link1;
    head1->size = 1;
    head2->root = link2;
    head2->size = 1;
    getLeaf(head1);
    getLeaf(head2);
    printLink(head1);
    printLink(head2);
    if(head1->size == head2->size){
        while(link1 != NULL){
            if (!isNodeSame(link1->value, link2->value)){
                return false;
            }
            link1 = link1->next;
            link2 = link2->next;
        }
    }
    return true;
}

struct TreeNode *leafNode(int value)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode *node1(){
    // struct TreeNode *root;
    // struct TreeNode *node5;
    // struct TreeNode *node1;
    // struct TreeNode *node6;
    // struct TreeNode *node2;
    // struct TreeNode *node9;
    // struct TreeNode *node8;
    // struct TreeNode *node7;
    // struct TreeNode *node4;

    // root = leafNode(3);
    // node5 = leafNode(5);
    // node1 = leafNode(1);
    // node6 = leafNode(6);
    // node2 = leafNode(2);
    // node9 = leafNode(9);
    // node8 = leafNode(8);
    // node7 = leafNode(7);
    // node4 = leafNode(4);
    struct TreeNode *root;
    struct TreeNode *node2;
    struct TreeNode *node3;

    root = leafNode(1);
    node2 = leafNode(2);
    node3 = leafNode(3);
    
    root->left = node2;
    node2->left = node3;
    // root->right = node1;

    // node5->left = node6;
    // node5->right = node2;

    // node2->left = node7;
    // node2->right = node4;

    // node1->left = node9;
    // node1->right= node8;

    return root;
}

struct TreeNode *node2(){
    // struct TreeNode *root;
    // struct TreeNode *node5;
    // struct TreeNode *node1;
    // struct TreeNode *node6;
    // struct TreeNode *node2;
    // struct TreeNode *node9;
    // struct TreeNode *node8;
    // struct TreeNode *node7;
    // struct TreeNode *node4;

    // root = leafNode(3);
    // node5 = leafNode(5);
    // node1 = leafNode(1);
    // node6 = leafNode(6);
    // node2 = leafNode(2);
    // node9 = leafNode(9);
    // node8 = leafNode(8);
    // node7 = leafNode(7);
    // node4 = leafNode(4);

    // root->left = node5;
    // root->right = node1;

    // node5->left = node6;
    // node5->right = node7;

    // node1->left = node4;
    // node1->right = node2;

    // node2->left = node9;
    // node2->right = node8;

     struct TreeNode *root;
    struct TreeNode *node3;

    root = leafNode(1);
    node3 = leafNode(3);
    
    root->left = node3;

    return root;
}


int main()
{
    struct TreeNode *root = node1();
    struct TreeNode *root2 = node2();
    
    pLinkHead link = (pLinkHead)malloc(sizeof(LinkHead));
    pLinkNode tem = (pLinkNode)malloc(sizeof(LinkNode));

    pLinkHead link2 = (pLinkHead)malloc(sizeof(LinkHead));
    pLinkNode tem2 = (pLinkNode)malloc(sizeof(LinkNode));

    tem->value = root;
    link->root = tem;
    link->size = 1;

    tem2->value = root;
    link2->root = tem2;
    link2->size = 1;

    // getLeaf(link);
    // getLeaf(link2);

    // printLink(link);
    // printLink(link2);

    printf("%d", leafSimilar(root, root2));
}