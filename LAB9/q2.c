#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert node at the end
struct Node* insert(struct Node* head, int data) {
    if (head == NULL)
        return createNode(data);
    
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    
    temp->next = createNode(data);
    return head;
}

// Check if element exists in the list
int isPresent(struct Node* head, int data) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data)
            return 1;
        temp = temp->next;
    }
    return 0;
}

// UNION of two linked lists without header node
struct Node* unionWithoutHeader(struct Node* head1, struct Node* head2) {
    struct Node* result = NULL;
    struct Node* temp = head1;

    while (temp != NULL) {
        result = insert(result, temp->data);
        temp = temp->next;
    }

    temp = head2;
    while (temp != NULL) {
        if (!isPresent(result, temp->data))
            result = insert(result, temp->data);
        temp = temp->next;
    }

    return result;
}

// INTERSECTION of two linked lists without header node
struct Node* intersectionWithoutHeader(struct Node* head1, struct Node* head2) {
    struct Node* result = NULL;
    struct Node* temp = head1;

    while (temp != NULL) {
        if (isPresent(head2, temp->data))
            result = insert(result, temp->data);
        temp = temp->next;
    }

    return result;
}

// Display list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    head1 = insert(head1, 10);
    head1 = insert(head1, 20);
    head1 = insert(head1, 30);

    head2 = insert(head2, 20);
    head2 = insert(head2, 30);
    head2 = insert(head2, 40);

    printf("Set 1: ");
    display(head1);
    printf("Set 2: ");
    display(head2);

    struct Node* unionResult = unionWithoutHeader(head1, head2);
    printf("Union: ");
    display(unionResult);

    struct Node* intersectionResult = intersectionWithoutHeader(head1, head2);
    printf("Intersection: ");
    display(intersectionResult);

    return 0;
}
