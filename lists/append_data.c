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
int pop(node** headRef);
void insert_nth(node** headRef, int n, int data);
void sorted_insert(node** headRef, int data);

int main() {
    printf("Hello World!\n");
  
    node* head = create_node(10);
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
    insert_nth(&head, 1, 15);
    insert_nth(&head, 1, 13);
    insert_nth(&head, 0, 4);    
    print_list(head);

    sorted_insert(&head, 33);
    sorted_insert(&head, 13);
    sorted_insert(&head, 3);
    sorted_insert(&head, 41);
    sorted_insert(&head, 20);
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
    printf("getting node at position %d\n", n);
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

int pop(node** headRef) {
    assert(headRef != NULL);
    if (*headRef != NULL) {
        node* head = (*headRef)->next;        
        int data = (*headRef)->data;

        (*headRef)->next = NULL;      
        *headRef = head;

        printf("popping: %d\n", data);
        return data;
    }
    return 0;
}

void insert_nth(node** headRef, int n, int data) {
    assert(headRef != NULL);
    assert(n >= 0);

    // possible cases (will write each case first time)
    // head is null : create new node and make it the new head pointing to null
    // n == 0 : create new node, make it new head and get it pointing to current head
    if (*headRef == NULL || n == 0) {
        node* head = create_node(data);
        head->next = *headRef;
        *headRef = head;
        return;
    }

    node* prev = *headRef;
    node* next = (*headRef)->next;
    int p = 1;

    // n < length : insert it at the middle of the list
    // n > length : append to the list
    while (p < n && next != NULL) {
        prev = next;
        next = next->next;
        p++;
    }

    node* newNode = create_node(data);
    prev->next = newNode;
    newNode->next = next;    

}

void sorted_insert(node** headRef, int data) {
    assert(headRef != NULL);

    node* prev = NULL;
    node* current = *headRef;

    while (current != NULL && current->data < data) {
      prev = current;
      current = current->next;
    }
  
    node* newNode = create_node(data);
    newNode->next = current;
    if (prev != NULL) {
        prev->next = newNode;
    }
    else {
      *headRef = newNode;
    }
    
}