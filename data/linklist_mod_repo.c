#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "mod_repo.h"

struct node {
    struct model data;
    struct node *next;
};

struct node *head = NULL;
long int global_id = 0;

int count_mod() {
    if (head == NULL) {
        return 0;
    }

    int size = 0;
    for (struct node *p = head->next; p != NULL; p = p->next) {
        size++;
    }

    return size;
}

void insert(struct model mod) {
    mod.id = ++global_id;
    struct node *node = malloc(sizeof(struct node));
    node->next = head->next;
    node->data = mod;
    head->next = node;
}

void update_link(struct model mod) {
    for (struct node *p = head->next; p != NULL; p = p->next) {
        if (p->data.id == mod.id) {
            p->data.name = mod.name;
            p->data.age = mod.age;
            p->data.days = mod.days;
            p->data.height = mod.height;
        }
    }
}

void save_mod(struct model mod) {
    if (head == NULL) {
        head = malloc(sizeof(struct node));
        head->next=NULL;
    }

    if (mod.id > 0) {
        update_link(mod);
        return;
    }

    insert(mod);
}

struct model *find_mod(unsigned int id) {
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

int find_all_mod(struct model mods[]) {
    if (head == NULL) {
        return 0;
    }

    int count = 0;
    for (struct node *p = head->next; p != NULL; p = p->next, count++) {
        mods[count] = p->data;
    }

    return count;
}

void delete_mod(unsigned int id) {
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
