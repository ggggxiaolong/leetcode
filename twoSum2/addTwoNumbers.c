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

bool isLonger(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *next1 = l1;
    struct ListNode *next2 = l2;
    while (next1 != NULL && next2 != NULL)
    {
        next1 = next1->next;
        next2 = next2->next;
    }
    if (next2 == NULL)
        return true;
    return false;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *res;
    struct ListNode *shortLink;
    struct ListNode *longLink;
    if (isLonger(l1, l2))
    {
        res = l1;
        longLink = l1;
        shortLink = l2;
    }
    else
    {
        res = l2;
        longLink = l2;
        shortLink = l1;
    }
    int inc = 0;
    while (shortLink != NULL)
    {
        longLink->val = longLink->val + shortLink->val + inc;
        if (longLink->val > 9)
        {
            longLink->val -= 10;
            inc = 1;
        }
        else
        {
            inc = 0;
        }
        longLink = longLink->next;
        shortLink = shortLink->next;
    }
    if (inc)
    {
        if (longLink != NULL)
        {
            //长度不同，有进位
            if (longLink->val == 9)
            {
                longLink->val = 0;
                struct ListNode *tem = (struct ListNode *)malloc(sizeof(struct ListNode));
                tem->val = 1;
                tem->next = NULL;
                longLink->next = tem;
            } else{
                longLink->val += 1;
            }
            return res;
        }
        //长度相同且有进位， 末尾一直是9的问题
        struct ListNode *tem = (struct ListNode *)malloc(sizeof(struct ListNode));
        tem->val = 1;
        tem->next = NULL;
        longLink = res;
        while (longLink->next != NULL)
        {
            longLink = longLink->next;
        }
        longLink->next = tem;
    }
    return res;
}