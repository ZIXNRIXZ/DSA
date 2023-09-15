#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
struct Node* reverseBetween(struct Node* head, int m, int n) {
    if (head == NULL || m == n) {
        return head; 
    }

    struct Node* dummy = (struct Node*)malloc(sizeof(struct Node));
    dummy->next = head;
    struct Node* prev = dummy;
    struct Node* current = head;
    
    
    for (int i = 1; i < m; i++) {
        prev = current;
        current = current->next;
    }
    
    struct Node* beforeM = prev; 
    struct Node* first = current; 

    
    for (int i = m; i <= n; i++) {
        struct Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    beforeM->next = prev; 
    first->next = current; 

    return dummy->next; 
}


void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    printf("Original Linked List: ");
    printList(head);

    int m = 2; 
    int n = 4; 
    head = reverseBetween(head, m, n);

    printf("Reversed Linked List from position %d to %d: ", m, n);
    printList(head);

    return 0;
}
