/* 21. 合并两个有序链表: https://leetcode.cn/problems/merge-two-sorted-lists/ */
/* https://leetcode.cn/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/ */

/* https://labuladong.github.io/algo/di-ling-zh-bfe1b/shuang-zhi-0f7cc/ */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (!list1) {
        return list2;
    }
    if (!list2) {
        return list1;
    }

    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *t = head;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            t->next = list1;
            list1 = list1->next;
        } else {
            t->next = list2;
            list2 = list2->next;
        }
        t = t->next;
    }

    if (list1) {
        t->next = list1;
    } else {
        t->next = list2;
    }

    return head->next;
}


int main() {

    // Test case 1
    struct ListNode* l1 = NULL;
    struct ListNode* l2 = NULL;

    struct ListNode* merged = mergeTwoLists(l1, l2);

    // Print merged list
    while (merged != NULL) {
        printf("%d ", merged->val);
        merged = merged->next;
    }

    printf("\n");

    // Test case 2
    l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->val = 1;
    l1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next->val = 2;
    l1->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next->next->val = 4;
    l1->next->next->next = NULL;

    l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->val = 1;
    l2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->next->val = 3;
    l2->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->next->next->val = 4;
    l2->next->next->next = NULL;

    merged = mergeTwoLists(l1, l2);

    // Print merged list
    while (merged != NULL) {
        printf("%d ", merged->val);
        merged = merged->next;
    }

    printf("\n");

    return 0;
}