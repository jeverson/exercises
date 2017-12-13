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
void print_node(node* node);
node* get_last_item(node* head);
int get_length(node* head);
node* get_nth(node* head, int n);

int main() {
    printf("Hello World!\n");

    node* head = create_node(10);
    get_length(head);
    append_data(&head, 20);
    append_data(&head, 30);
    append_data(&head, 40);
    get_length(head);
    get_nth(head, 0);
    get_nth(head, 1);
    get_nth(head, 3);
    get_nth(head, 5);
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

int get_length(node* head) {
    int count = 0;
    while (head != NULL) {
        head = head->next;
        count++;
    }
    printf("length: %d\n", count);
    return count;
}

node* get_nth(node* head, int n) {
    assert(n >= 0);

    int p = 0;
    while (head != NULL && p < n) {
        head = head->next;
        p++;
    }    
    printf("getting node at %d position\n", n);
    print_node(head);
    return head;
}


void print_list(node* head) {
    printf("printing list: \n");
    while (head != NULL) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void print_node(node* node) {
    if (node != NULL) {
        printf("data: %d at %p\n", node->data, node);
    }
    else 
    {
        printf("node is null\n");
    }
}

node* get_last_item(node* head) {
    node* current = head;
    while (current != NULL && current->next != NULL) {
        current = current->next;
    }
    return current;
}