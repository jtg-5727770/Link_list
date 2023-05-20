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
        printf("=========�޴�=========\n");
        printf("1.����Ʈ�� �߰��ϴ� ���ڿ� ��ġ�� �Է� �޾Ƽ� ����Ʈ�� ����\n");
        printf("2.����Ʈ���� ������ ��ġ�� �Է� �޾Ƽ� ����\n");
        printf("3.����Ʈ�� ���ʷ� ���\n");
        printf("0.����\n");
        printf("��ȣ�� �����ϼ���: ");
        scanf_s("%d", &n);

        switch (n) {
        case 1:
            printf("������ ���ڿ� ��ġ�� �Է��ϼ���: ");
            scanf_s("%d %d", &value, &position);
            if (head == NULL && position != 0) {
                printf("����Ʈ�� ��� �ֽ��ϴ�. 0��° ��ġ�� �����մϴ�.\n");
                head = insert_first(head, value);
                printf("�̵� Ƚ��: %d\n", count);
            }
            else if (position == 0) {
                head = insert_first(head, value);
                printf("�̵� Ƚ��: %d\n",count);
            }
            else {
                ListNode* pre = head;
                for (int i = 0; i < position - 1 && pre != NULL; i++) {
                    pre = pre->link;
                    count++;
                }
                if (pre == NULL) {
                    printf("������ ��ġ�� %d��°�Դϴ�. %d��° ��ġ�� �����մϴ�.\n", count-1, count);
                    pre = head;
                    for (int i = 0; i < count - 1 && pre != NULL; i++) {
                        pre = pre->link;
                    }
                    count--;
                }
                head = insert(head, pre, value);
                count++;
                printf("�̵� Ƚ��: %d\n", count);
            }
            break;

        case 2:
            if (head == NULL) {
                printf("����Ʈ�� ��� �ֽ��ϴ�.\n");
                break;
            }
            printf("������ ��ġ�� �Է��ϼ���: ");
            scanf_s("%d", &position);
            if (position == 0) {
                head = delete_first(head);
                printf("�̵� Ƚ��: %d\n", count);
            }
            else {
                ListNode* pre = head;
                for (int i = 0; i < position - 1 && pre != NULL; i++) {
                    pre = pre->link;
                    count++;
                }
                head = delete(head, pre);
                count++;
                printf("�̵� Ƚ��: %d\n", count);
            }
            break;
        case 3:
            if (head == NULL) {
                printf("����Ʈ�� ��� �ֽ��ϴ�.\n");
                break;
            }
            print_list(head);
            break;
        case 0:
            printf("���α׷��� �����մϴ�.\n");
            exit(0);
        default:
            printf("�ٽ� �������ּ���.\n");
        }
    }
    system("pause");
    return 0;
}
