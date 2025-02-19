/* 86. 分隔链表：https://leetcode.cn/problems/partition-list/ */
/* https://leetcode.cn/problems/partition-list/ */

/* https://labuladong.github.io/algo/di-ling-zh-bfe1b/shuang-zhi-0f7cc/ */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *partition(struct ListNode *head, int x) {
    struct ListNode *dummy1 = malloc(sizeof(struct ListNode));
    dummy1->val = -1;
    dummy1->next = NULL;

    struct ListNode *dummy2 = malloc(sizeof(struct ListNode));
    dummy2->val = -1;
    dummy2->next = NULL;

    struct ListNode *p1 = dummy1;
    struct ListNode *p2 = dummy2;

    struct ListNode *p = head;
    while (p != NULL) {
        if (p->val >= x) {
            p2->next = p;
            p2 = p2->next;
        } else {
            p1->next = p;
            p1 = p1->next;
        }
        struct ListNode *tmp = p->next;
        p->next = NULL;
        p = tmp;
    }

    p1->next = dummy2->next;
    return dummy1->next;
}

int main() {
    struct ListNode *head = malloc(sizeof(struct ListNode));
    head->val = 1;

    head->next = malloc(sizeof(struct ListNode));
    head->next->val = 4;

    head->next->next = malloc(sizeof(struct ListNode));
    head->next->next->val = 3;

    head->next->next->next = malloc(sizeof(struct ListNode));
    head->next->next->next->val = 2;

    head->next->next->next->next = malloc(sizeof(struct ListNode));
    head->next->next->next->next->val = 5;

    head->next->next->next->next->next = malloc(sizeof(struct ListNode));
    head->next->next->next->next->next->val = 2;

    head->next->next->next->next->next->next = NULL;

    printf("Original: ");
    struct ListNode *p = head;
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\r\n");

    int x = 3;
    struct ListNode *new_head = partition(head, x);

    printf("After: ");
    p = new_head;
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\r\n");

    return 0;
}