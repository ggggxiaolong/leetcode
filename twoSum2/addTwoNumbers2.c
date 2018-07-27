/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

int addNode(struct ListNode *l1, struct ListNode *l2, int inc)
{
    int value = 0;
    value = l1->val + l2->val + inc;
    if (value > 9)
    {
        value -= 10;
        inc = 1;
    }
    else
    {
        inc = 0;
    }
    l1->val = value;
    return inc;
}

int addNode2(struct ListNode *l1, int inc){
    int value = l1->val + inc;
    if (value > 9)
    {
        value -= 10;
        inc = 1;
    }
    else
    {
        inc = 0;
    }
    l1->val = value;
    return inc;
}

bool checkEnd(struct ListNode *l1, int inc){
    if(l1->next == NULL){
        if(inc){
            struct ListNode *tem = (struct ListNode *)malloc(sizeof(struct ListNode));
            tem->val = 1;
            tem->next = NULL;
            l1->next = tem;
        }
        return true;
    }
    return false;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *res = l1;
    int inc = 0, value = 0;
    while (l1->next != NULL && l2->next != NULL)
    {
        inc = addNode(l1, l2, inc);
        l2 = l2->next;
        l1 = l1->next;
    }
    inc = addNode(l1, l2, inc);
    if(l1->next == NULL && l2->next == NULL){
        checkEnd(l1, inc);
        return res;
    }
    if(l1->next == NULL){
        l1->next = l2->next;    
    }
    while(!checkEnd(l1, inc)){
        l1 = l1->next;
        inc = addNode2(l1, inc);
    }
    return res;
}
struct ListNode* createNode(int value){
    struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = value;
    node->next = NULL;
    return node;
}
int main(){
    struct ListNode* l1 = createNode(9);
    l1->next = createNode(8);
    struct ListNode* l2 = createNode(1);
    struct ListNode* res = addTwoNumbers(l1, l2);
    while(res != NULL){
        printf("%d",res->val);
        res = res->next;
    }
}