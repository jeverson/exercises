#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node node;
struct node {
    int data;
    node* next;
};

node* create_node(int data);
void print_list(node* head, const char* name);
void move_node(node** sourceRef, node** destRef);

int main() {
    printf("Hello World!\n");
  
    node* source = create_node(1);
    node* dest = create_node(1);

    node* currentSource = source;
    node* currentDest = dest;
    int i = 2;
    while (i <= 10) {
        currentSource->next = create_node(i);
        currentSource = currentSource->next;
        currentDest->next = create_node(i);
        currentDest = currentDest->next;
        i++;
    }
    print_list(source, "source");
    print_list(dest, "dest");
    move_node(&source, &dest);
    print_list(source, "source");
    print_list(dest, "dest");

    return 0;
}

node* create_node(int data) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = data;
    return newNode;
}

void print_list(node* head, const char* name) {
    printf("printing list %c: \n", *name);
    while (head != NULL) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void move_node(node** sourceRef, node** destRef) {
    assert(sourceRef != NULL);
    
    if (destRef == NULL) {
        return;        
    }

    if (*sourceRef == NULL) {
        return;
    }

    node* head = *sourceRef;
    *sourceRef = head->next;

    head->next = *destRef;
    *destRef = head;
}