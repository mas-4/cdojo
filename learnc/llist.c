#include <stdio.h>

typedef struct node {
    int val;
    struct node *next;
}

void print_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

void push(node_t *head, int val) {
    node_t *current = head;
    while (current->next != NULL) current = current->next;
    current->next = malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}

void push_start(node_t **head, int val) {
    node_t *new_node;
    new_node = malloc(sizeof(node_t));

    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}

// **head is a pointer to *head which is a pointer to the actual head
int pop(node_t **head) {
    int retval = -1;
    node_t *next_node = NULL;
    if (*head == NULL) {
        return -1;
    }
    next_node = (*head)->next; // the actual head's next
    retval = (*head)->val; // the actual head's val
    free(*head); // free the actual head
    *head = next_node; // the head now points to next_node;
    return retval;
}

int pop_last(node_t *head) {
    int retval = 0;
    if (head->next == NULL) {
        retval = head->val;
        free(head);
        return retval;
    }
    node_t *current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    // if we don't actually set current->next to NULL it will still have a
    // pointer, just to a garbage value.
    retval = current->next->val;
    free(current->next);
    current->next = NULL;
    return retval;
}

int remove_by_index(node_t **head, int n) {
    int retval = -1;
    node_t *current = *head;
    node_t *temp_node = NULL;
    if (n == 0) {
        return pop(head);
    }
    for (int i = 0; i < n-1; i++) {
        if (current->next == NULL) return -1;
        current = current->next;
    }
    temp_node = current->next; // current is n-1, temp_node is n
    retval = temp_node->val;
    current->next = temp_node->next;
    free(temp_node);
    return retval;
}

int main() {
    node_t *head = NULL;
    head = malloc(sizeof(node_t));
    if (head == NULL) {
        return 1;
    }
    head->val = 1;
    head->next = NULL;
    head->next = malloc(sizeof(node_t));
    head->next->val = 2;
    head->next->next = NULL;
}
