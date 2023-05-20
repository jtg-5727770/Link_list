#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, int value)
{
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element value)
{
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value; 
    p->link = pre->link; 
    pre->link = p; 
    return head; 
}


ListNode* delete_first(ListNode* head)
{
    ListNode* removed;
    if (head == NULL) return NULL;
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}

ListNode* delete(ListNode* head, ListNode* pre)
{
    ListNode* removed;
    removed = pre->link;
    pre->link = removed->link; 
    free(removed); 
    return head; 
}

void print_list(ListNode* head)
{
    for (ListNode* p = head; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL\n");
}

int main(void)
{
    ListNode* head = NULL;
    int n;
    int value, position;

    while (1) {
        int count = 0;
        printf("=========메뉴=========\n");
        printf("1.리스트에 추가하는 숫자와 위치를 입력 받아서 리스트에 삽입\n");
        printf("2.리스트에서 삭제할 위치를 입력 받아서 삭제\n");
        printf("3.리스트를 차례로 출력\n");
        printf("0.종료\n");
        printf("번호를 선택하세요: ");
        scanf_s("%d", &n);

        switch (n) {
        case 1:
            printf("삽입할 숫자와 위치를 입력하세요: ");
            scanf_s("%d %d", &value, &position);
            if (head == NULL && position != 0) {
                printf("리스트가 비어 있습니다. 0번째 위치에 삽입합니다.\n");
                head = insert_first(head, value);
                printf("이동 횟수: %d\n", count);
            }
            else if (position == 0) {
                head = insert_first(head, value);
                printf("이동 횟수: %d\n",count);
            }
            else {
                ListNode* pre = head;
                for (int i = 0; i < position - 1 && pre != NULL; i++) {
                    pre = pre->link;
                    count++;
                }
                if (pre == NULL) {
                    printf("마지막 위치가 %d번째입니다. %d번째 위치에 삽입합니다.\n", count-1, count);
                    pre = head;
                    for (int i = 0; i < count - 1 && pre != NULL; i++) {
                        pre = pre->link;
                    }
                    count--;
                }
                head = insert(head, pre, value);
                count++;
                printf("이동 횟수: %d\n", count);
            }
            break;

        case 2:
            if (head == NULL) {
                printf("리스트가 비어 있습니다.\n");
                break;
            }
            printf("삭제할 위치를 입력하세요: ");
            scanf_s("%d", &position);
            if (position == 0) {
                head = delete_first(head);
                printf("이동 횟수: %d\n", count);
            }
            else {
                ListNode* pre = head;
                for (int i = 0; i < position - 1 && pre != NULL; i++) {
                    pre = pre->link;
                    count++;
                }
                head = delete(head, pre);
                count++;
                printf("이동 횟수: %d\n", count);
            }
            break;
        case 3:
            if (head == NULL) {
                printf("리스트가 비어 있습니다.\n");
                break;
            }
            print_list(head);
            break;
        case 0:
            printf("프로그램을 종료합니다.\n");
            exit(0);
        default:
            printf("다시 선택해주세요.\n");
        }
    }
    system("pause");
    return 0;
}
