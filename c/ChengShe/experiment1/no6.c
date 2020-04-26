/*
6、	第九章第6题修改版
键盘输入人数n，从第一个人开始顺序报号1、2、3。凡报到3者退出，找出最后留在圈子中的人原来的序号。用链表实现。
输入
25
输出
3
*/
#include <stdio.h>
#include <stdlib.h>

struct people
{
    int num;
    struct people *next;
};

int len = sizeof(struct people);

int create(struct people *head, int n)
{
    if (n == 0)
    {
        return 0;
    }
    int i = 0;
    struct people *curr, *pre = head;
    for (i = 0; i < n; i++)
    {
        curr = (struct people *)malloc(len);
        if (!curr)
        {
            return 0;
        }
        curr->num = i + 1;
        pre->next = curr;
        pre = curr;
    }
    curr->next = head->next;
    return 1;
}

int get_length(struct people *head)
{
    int i = 0;
    if (head->next == NULL)
    {
        return 0;
    }
    i++;
    struct people *curr = head->next;
    while (curr->next != head->next)
    {
        i++;
        curr = curr->next;
    }
    return i;
}

int del(struct people *curr, struct people *pre, struct people *head)
{
    pre->next = curr->next;
    if (head->next == curr)
        head->next = curr->next;
    free(curr);
    curr = NULL;
    return 1;
}

int main()
{
    struct people head, *curr, *pre;
    int n;
    head.next = NULL;
    scanf("%d", &n);
    create(&head, n);
    if (!head.next)
        return 0;
    curr = &head;
    pre = curr->next->next;
    curr = curr->next->next->next;
    while (get_length(&head) > 1)
    {
        del(curr, pre, &head);
        pre = pre->next->next;
        curr = pre->next;
    }
    printf("%d", head.next->num);
    return 0;
}