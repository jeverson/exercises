#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node node;
struct node {
    int data;
    node* next;
};

node* create_node(int data);
void append_data(node** headRef, int data);
void print_list(node* head);
node* get_last_item(node* head);

int main() {
    printf("Hello World!\n");

    node* head = create_node(10);

    append_data(&head, 20);
    append_data(&head, 30);
    append_data(&head, 40);
    printf("head %d\n", head->data);    
    print_list(head);

    return 0;
}

node* create_node(int data) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = data;
    return newNode;
}

void append_data(node** headRef, int data) {
    assert(headRef != NULL);

    node* newNode = create_node(data);
    node* last = get_last_item(*headRef);

    if (last == NULL)
    {
        *headRef = newNode;
    }
    else
    {
        last->next = newNode;
    }
}

void print_list(node* head) {
    printf("Printing list: \n");
    while (head != NULL) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

node* get_last_item(node* head) {
    node* current = head;
    while (current != NULL && current->next != NULL) {
        current = current->next;
    }
    return current;
}