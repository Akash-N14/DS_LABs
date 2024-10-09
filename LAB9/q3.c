#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;
void insertEnd(Node **head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void displayList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

// Function to merge two sorted linked lists into one sorted list
Node* mergeLists(Node *list1, Node *list2) {
    Node *mergedList = NULL, **lastPtrRef = &mergedList;
    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            *lastPtrRef = list1;
            list1 = list1->next;
        } else {
            *lastPtrRef = list2;
            list2 = list2->next;
        }
        lastPtrRef = &((*lastPtrRef)->next);
    }
    if (list1 != NULL) {
        *lastPtrRef = list1;
    } else if (list2 != NULL) {
        *lastPtrRef = list2;
    }

    return mergedList;
}

int main() {
    int n1, n2, i, value;
    printf("Enter number of students in Class A and Class B: ");
    scanf("%d %d", &n1, &n2);

    Node *classA = NULL, *classB = NULL;
    printf("Enter heights of students in Class A: ");
    for (i = 0; i < n1; i++) {
        scanf("%d", &value);
        insertEnd(&classA, value);
    }
    printf("Enter heights of students in Class B: ");
    for (i = 0; i < n2; i++) {
        scanf("%d", &value);
        insertEnd(&classB, value);
    }
    printf("Class A: ");
    displayList(classA);
    printf("Class B: ");
    displayList(classB);
    Node *mergedList = mergeLists(classA, classB);
    printf("Merged Line: ");
    displayList(mergedList);

    return 0;
}
