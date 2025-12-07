#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

void displayMenu();
ListNode* createNode(int data);
ListNode* addListHead(ListNode* head, int data);
ListNode* addListTail(ListNode* head, int data);
ListNode* insertList(ListNode* head, int i, int x);
ListNode* searchNode(ListNode* head, int data);
int findPos(ListNode* head, int data);
int posData(ListNode* head, int pos);
ListNode* deleteNode(ListNode* head, int data);
ListNode* deleteNodePos(ListNode* head, int pos);
ListNode* modifyNodePos(ListNode* head, int pos, int newData);
ListNode* modifyNodeValue(ListNode* head, int oldData, int newData);
void printNode(ListNode* head);
void freeList(ListNode *head);
int lenList(ListNode* head);

int main() {
    ListNode *head = NULL;
    int choice, data, pos, oldData, newData;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("要插入(头)的节点数据：\n");
                scanf("%d", &data);
                head = addListHead(head, data);
                printf("插入成功!\n");
                break;

            case 2:
                printf("要插入(尾)的节点数据：\n");
                scanf("%d", &data);
                head = addListTail(head, data);
                printf("插入成功!\n");
                break;

            case 3: {
                int i, x;
                printf("插入的位置：\n");
                scanf("%d", &i);
                if(i < 0) {
                    printf("输入位置不合法!\n");
                    break;
                }
                printf("插入的节点数据：\n");
                scanf("%d", &x);
                head = insertList(head, i, x);
                printf("插入成功!\n");
            }
            break;

            case 4:
                printf("输入要查找的数据：\n");
                scanf("%d", &data);
                ListNode* foundNode;
                foundNode = searchNode(head, data);
                if(foundNode == NULL) {
                    printf("没有找到数据%d\n", data);
                } else {
                    int pos = findPos(head, data);
                    printf("数据%d位于%d位置\n", data, pos);
                }
                break;

            case 5:
                printf("输入要查找的位置(0~%d)：\n", lenList(head) - 1);
                scanf("%d", &pos);
                if(pos < 0 || pos >= lenList(head)) {
                    printf("输入位置无效！\n");
                    break;
                } else {
                    printf("%d位置的数据是%d\n", pos, posData(head, pos));
                }
                break;

            case 6:
                printf("输入要删除的数据：\n");
                scanf("%d", &data);
                head = deleteNode(head, data);
                break;

            case 7:
                printf("输入要删除的位置 (0-%d): ", lenList(head) - 1);
                scanf("%d", &pos);
                head = deleteNodePos(head, pos);
                break;

            case 8:
                printf("输入要修改的位置：\n");
                scanf("%d", &pos);
                printf("输入要替换的数据：\n");
                scanf("%d", &newData);
                head = modifyNodePos(head, pos, newData);
                break;

            case 9:
                printf("输入要修改的原数据！\n");
                scanf("%d", &oldData);
                printf("输入要替换的新数据：\n");
                scanf("%d", &newData);
                head = modifyNodeValue(head, oldData, newData);
                break;

            case 10:
                printNode(head);  
                break;

            case 11:
                freeList(head);
                printf("链表释放，程序退出！\n");
                system("pause");
                exit(0);
                break;

            default:
                printf("无效输入！\n");
        }

    } while(choice != 11);

    return 0;
}

ListNode* createNode(int x) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));

    if(newNode == NULL) {
        printf("开辟新节点失败\n");
        return NULL;
    }

    newNode->data = x;
    newNode->next = NULL;

    return newNode;
}

ListNode* addListHead(ListNode* head, int x) {
    ListNode* newNode = createNode(x);
    if(newNode == NULL) {
        return head;
    }

    newNode->next = head;
    return newNode;
}

ListNode* addListTail(ListNode* head, int x) {
    ListNode* newNode = createNode(x); 
    if(newNode == NULL) {
        return head;
    }

    if(head == NULL) {
        return newNode; 
    }

    ListNode* tempNode = head;
    while(tempNode->next != NULL) {
        tempNode = tempNode->next;
    }

    tempNode->next = newNode;
    return head;
}

ListNode* insertList(ListNode* head, int i, int x) {
    if(i == 0) {
        return addListHead(head, x);
    }

    ListNode* newNode = createNode(x);
    if(newNode == NULL) {
        return head;
    }

    ListNode* tempNode = head;
    int countPos = 0;

    while(tempNode != NULL && countPos < i - 1) {
        tempNode = tempNode->next;
        countPos++;
    }

    if(tempNode == NULL) {
        printf("输入位置超出最大，已默认插入最后!\n");  
        
        ListNode* last = head;
        while(last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
    } else {
        newNode->next = tempNode->next;
        tempNode->next = newNode;
        printf("插入成功!\n");
    }
    return head;
}

ListNode* searchNode(ListNode* head, int data) {
    ListNode* tempNode = head;

    while(tempNode != NULL) {
        if(tempNode->data == data) {
            return tempNode;
        }
        tempNode = tempNode->next;
    }
    return NULL;
}

int findPos(ListNode* head, int data) {
    ListNode* tempNode = head;
    int countPos = 0;

    while(tempNode != NULL) {
        if(tempNode->data == data) {
            return countPos;
        }
        tempNode = tempNode->next;
        countPos++;
    }
    return -1;
}

int posData(ListNode* head, int pos) {
    ListNode* tempNode = head;

    for(int i = 0; i < pos && tempNode != NULL; i++) {
        tempNode = tempNode->next;
    }
    if(tempNode != NULL) {
        return tempNode->data;
    }
    return -1;
}

ListNode* deleteNode(ListNode* head, int data) {  
    if(head == NULL) {
        printf("链表已经是空的！\n");
        return NULL;
    }

    if(head->data == data) {
        ListNode* tempNode = head;
        head = head->next;
        free(tempNode);
        printf("删除成功！\n");
        return head;
    }

    ListNode* tempNode = head;
    while(tempNode->next != NULL && tempNode->next->data != data) {
        tempNode = tempNode->next;
    }

    if(tempNode->next == NULL) {
        printf("未找到数据%d!\n", data);
        return head;
    } else {
        ListNode* tempNode2 = tempNode->next;
        tempNode->next = tempNode2->next;
        free(tempNode2);
        printf("删除成功！\n");
        return head;
    }
}

ListNode* deleteNodePos(ListNode* head, int pos) {
    if(head == NULL) {
        printf("链表已经是空的！\n");
        return NULL;
    }

    if(pos < 0) {
        printf("输入位置无效！\n");
        return head;
    }

    if(pos == 0) {
        ListNode* tempNode = head;
        head = head->next;
        free(tempNode);
        printf("删除成功！\n");
        return head;
    }

    ListNode* tempNode = head;
    int countPos = 0;

    while(tempNode != NULL && countPos < pos - 1) {
        tempNode = tempNode->next;
        countPos++;
    }

    if(tempNode == NULL || tempNode->next == NULL) {
        printf("输入的位置超出范围！\n");
        return head;
    } else {
        ListNode* tempNode2 = tempNode->next;  
        tempNode->next = tempNode2->next;
        free(tempNode2);
        printf("删除成功！\n");
        return head;
    }
}

ListNode* modifyNodePos(ListNode* head, int pos, int newData) {  
    if(head == NULL) {
        printf("链表已经是空的！\n");
        return NULL;
    }

    if(pos < 0) {
        printf("输入位置无效！\n");
        return head;
    }

    ListNode* tempNode = head;
    int countPos = 0;

    while(tempNode != NULL && countPos < pos) {
        tempNode = tempNode->next;
        countPos++;
    }

    if(tempNode == NULL) {
        printf("输入的位置超出范围！\n");
        return head;
    }

    tempNode->data = newData;
    printf("修改成功！\n");
    return head;
}

ListNode* modifyNodeValue(ListNode* head, int oldData, int newData) {  
    if(head == NULL) {
        printf("链表已经是空的！\n");
        return NULL;
    }

    ListNode* tempNode = head;

    while(tempNode != NULL) {
        if(tempNode->data == oldData) {
            tempNode->data = newData;
            printf("修改成功！\n");
            return head;
        }
        tempNode = tempNode->next;
    }

    printf("没有找到要修改的数据！\n");
    return head;
}

void printNode(ListNode* head) {
    if(head == NULL) {
        printf("链表为空！\n");
        return;
    }

    ListNode* tempNode = head;
    printf("链表元素（共%d个）：", lenList(head));
    while(tempNode != NULL) {
        printf("%d", tempNode->data);
        if(tempNode->next != NULL) {
            printf(" -> ");
        }
        tempNode = tempNode->next;
    }
    printf(" -> NULL\n");
}

int lenList(ListNode* head) {
    int len = 0;
    ListNode* tempNode = head;

    while(tempNode != NULL) {
        len++;
        tempNode = tempNode->next;
    }
    return len;
}

void freeList(ListNode* head) {
    ListNode* tempNode = head;
    ListNode* temp;

    while(tempNode != NULL) {
        temp = tempNode;
        tempNode = tempNode->next;
        free(temp);
    }
    printf("链表内存已释放！\n");
}

void displayMenu() {
    //system("cls");  
    printf("========== 单链表操作菜单 ==========\n");
    printf("1. 头部插入节点\n");
    printf("2. 尾部插入节点\n");
    printf("3. 指定位置插入节点\n");
    printf("4. 按值查找节点\n");
    printf("5. 按位置查找节点\n");
    printf("6. 按值删除节点\n");
    printf("7. 按位置删除节点\n");
    printf("8. 按位置修改节点\n");
    printf("9. 按值修改节点\n");
    printf("10. 显示链表\n");
    printf("11. 退出程序\n");
    printf("====================================\n");
}
