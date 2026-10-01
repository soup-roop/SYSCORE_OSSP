#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 16

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

char *read_dynamic_input() {
    int size = INITIAL_SIZE;
    int length = 0;

    char *buffer = malloc(size);

    if (buffer == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF) {

        if (length + 1 >= size) {
            size *= 2;

            char *temp = realloc(buffer, size);

            if (temp == NULL) {
                free(buffer);
                printf("Reallocation failed\n");
                return NULL;
            }

            buffer = temp;
        }

        buffer[length++] = ch;
    }

    buffer[length] = '\0';

    return buffer;
}

void add_node(Node **head, char *text) {
    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL) {
        printf("Node allocation failed\n");
        free(text);
        return;
    }

    new_node->data = text;
    new_node->next = *head;

    *head = new_node;
}

void display_list(Node *head) {
    printf("\nLinked List:\n");

    while (head != NULL) {
        printf("%s\n", head->data);
        head = head->next;
    }
}

void free_list(Node *head) {
    while (head != NULL) {
        Node *temp = head;
        head = head->next;

        free(temp->data);
        free(temp);
    }
}

int main() {
    Node *head = NULL;

    printf("Dynamic Buffer and Linked List Demo\n");
    printf("Enter commands.\n");
    printf("Type 'exit' to finish.\n\n");

    while (1) {
        printf("input> ");

        char *input = read_dynamic_input();

        if (input == NULL) {
            break;
        }

        if (strcmp(input, "exit") == 0) {
            free(input);
            break;
        }

        add_node(&head, input);
    }

    display_list(head);

    free_list(head);

    printf("\nAll dynamically allocated memory released.\n");

    return 0;
}
