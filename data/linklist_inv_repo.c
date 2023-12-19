#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "inv_repo.h"

struct node {
    struct invitation data;
    struct node *next;
};

struct node *head = NULL;
long int global_id = 0;

int count_inv() {
    if (head == NULL) {
        return 0;
    }

    int size = 0;
    for (struct node *p = head->next; p != NULL; p = p->next) {
        size++;
    }

    return size;
}

void insert(struct invitation inv) {
    inv.id = ++global_id;
    struct node *node = malloc(sizeof(struct node));
    node->next = head->next;
    node->data = inv;
    head->next = node;
}

void update(struct invitation inv) {
    for (struct node *p = head->next; p != NULL; p = p->next) {
        if (p->data.id == inv.id) {
            p->data.title = inv.title;
            p->data.description = inv.description;
            p->data.days = inv.days;
            strcpy(p->data.start_date, inv.start_date);
            strcpy(p->data.deadline, inv.deadline);
        }
    }
}

void save_inv(struct invitation inv) {
    if (head == NULL) {
        head = malloc(sizeof(struct node));
    }

    if (inv.id > 0) {
        update(inv);
        return;
    }

    insert(inv);
}

struct invitation *find_inv(unsigned int id) {
    if (head == NULL) {
        return NULL;
    }

    for (struct node *p = head->next; p != NULL; p = p->next) {
        if (p->data.id == id) {
            return &p->data;
        }
    }

    return NULL;
}

int find_all_inv(struct invitation invs[]) {
    if (head == NULL) {
        return 0;
    }

    int count = 0;
    for (struct node *p = head->next; p != NULL; p = p->next, count++) {
        invs[count] = p->data;
    }

    return count;
}

void delete_inv(unsigned int id) {
    if (head == NULL) {
        return;
    }

    struct node *prev = head;
    for (struct node *current = head->next; current != NULL; current = current->next) {
        if (current->data.id == id) {
            prev->next = current->next;
            free(current);
            break;
        }
    }
}
