#include <stdio.h>
#include <malloc.h>
#include "inv_repo.h"

struct arc_node {
    int adj_vex;
    struct arc_node *next;
};

struct ver_node {
    struct invitation data;
    struct ver_node *next_ver_node;
    struct arc_node *first_arc;
};

struct ver_node *head = NULL;
long int global_id = 0;

int count_inv() {
    if (head == NULL) {
        return 0;
    }

    int size = 0;
    for (struct ver_node *p = head; p != NULL; p = p->next_ver_node) {
        size++;
    }

    return size;
}

void insert(struct invitation inv) {
    inv.id = ++global_id;
}

void update(struct invitation inv) {}

void save_inv(struct invitation inv) {
    if (inv.id > 0) {
        update(inv);
        return;
    }

    insert(inv);
}

int dfs(struct invitation invs[]) {
    int size = 0;

    // TODO 实现深度搜索
    return size;
}

int bfs(struct invitation invs[]) {
    int size = 0;
    // TODO 实现宽度搜索
    return size;
}

// 深度遍历
struct invitation *find_inv(unsigned int id) {
    struct invitation list[MAX_SIZE];
    int size = dfs(list);

    if (size == 0) {
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        if (list[i].id == id) {
            return &list[i];
        }
    }

    return NULL;
}

int find_all_inv(struct invitation invs[]) {
    return bfs(invs);
}

void delete_inv(unsigned int id) {
    // TODO 实现按深度删除
}

