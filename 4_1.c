//stack method

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void push(struct Node** stack, struct Node* node) {
    node->next = *stack;
    *stack = node;
}
    struct Node* pop(struct Node** stack) {
        if (*stack == NULL) {
            return NULL; 
        }
        struct Node* poppedNode = *stack;
        *stack = poppedNode->next;
        return poppedNode;
    }
void reverseUsingStack(struct Node** head) {
    if (*head == NULL) {
        return; 
    }

    struct Node* stack = NULL; 
         struct Node* current = *head;
         while (current != NULL) {
        struct Node* nextNode = current->next;
        push(&stack, current);
        current = nextNode;
    }

    *head = pop(&stack);
    current = *head;
    while (stack != NULL) {
        current->next = pop(&stack);
        current = current->next;
    }
    current->next = NULL;
}

    void insertAtBeginning(struct Node** head, int data) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = *head;
        *head = newNode;
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

                /
                insertAtBeginning(&head, 1);
                insertAtBeginning(&head, 2);
                insertAtBeginning(&head, 3);
                insertAtBeginning(&head, 4);
                insertAtBeginning(&head, 5);

                printf("Original Linked List: ");
                printList(head);

                reverseUsingStack(&head);

                printf("Reversed Linked List: ");
                printList(head);

                return 0;
            }
/*******************************************************************************************************************/
//iterative method
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

void reverseIterative(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

    void insertAtBeginning(struct Node** head, int data) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = *head;
        *head = newNode;
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

        insertAtBeginning(&head, 1);
        insertAtBeginning(&head, 2);
        insertAtBeginning(&head, 3);
        insertAtBeginning(&head, 4);
        insertAtBeginning(&head, 5);

        printf("Original Linked List: ");
        printList(head);

        reverseIterative(&head);

        printf("Reversed Linked List: ");
        printList(head);

        return 0;
    }
