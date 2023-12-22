#include <stdio.h>
#include <malloc.h>
#include "mod_repo.h"



struct ver_node {
    struct model data;
    struct ver_node *next_ver_node;
    struct arc_node *first_arc;
};
struct ver_node *head = NULL;

int count_mod() {
    if (head == NULL) {
        return 0;
    }

    int size = 0;
    for (struct ver_node *p = head; p != NULL; p = p->next_ver_node) {
        size++;
    }

    return size;
}


void update(struct ver_node *node, struct model mod) {
    while (node != NULL) {
        if (node->data.id == mod.id) {
            node->data = mod;  // 找到匹配的节点，更新数据
            return;
        }
        node = node->next_ver_node;
    }
}

void save_mod(struct model mod) {
    struct ver_node *current = head;
    struct ver_node *last = NULL;

    // 检查是否已经有此 ID 的节点
    while (current != NULL) {
        if (current->data.id == mod.id) {
            update(current, mod);  // 已存在，更新节点
            return;
        }
        last = current;
        current = current->next_ver_node;
    }

    // 不存在，添加新节点
    struct ver_node *new_node = malloc(sizeof(struct ver_node));
    new_node->data = mod;
    new_node->next_ver_node = NULL;
    new_node->first_arc = NULL;

    if (last == NULL) {  // 图为空
        head = new_node;
    } else {
        last->next_ver_node = new_node;
    }
}

//int dfs(struct model mods[]) {
//    int size = 0;
//
//    // TODO 实现深度搜索
//    if(mods==NULL){
//        return 0;
//    }
//
//
//    return size;
//}
void  fillModsArray(struct model mods[], int index){
    struct ver_node *current = head;

    while(current!=NULL){
        mods[index].id=current->data.id;
        mods[index].name=current->data.name;
        mods[index].age=current->data.age;
        mods[index].height=current->data.height;
        current = current->next_ver_node;
        index++;
    }
}
void dfs(int index, struct model mods[], int visited[], int size, unsigned int id, struct model **found) {

    fillModsArray(mods,index);
    if (index >= size) {
        return;  // 超出数组范围
    }

    if (visited[index]) {
        return;  // 已访问过，不再重复访问
    }

    visited[index] = 1;  // 标记为已访问

    if (mods[index].id == id) {
        *found = &mods[index];  // 找到匹配的 ID，存储指针
        return;
    }

    for (int nextIndex = 0; nextIndex < size; nextIndex++) {
        if (!visited[nextIndex]) {
            dfs(nextIndex, mods, visited, size, id, found);
            if (*found != NULL) {
                // 如果已经找到，停止搜索
                return;
            }
        }
    }
}

unsigned int* getAdjacent(struct model mods[], unsigned int current_id, int size) {
    // 这里是一个示例实现，具体实现取决于您的图的数据结构
    unsigned int* adjacent_ids = malloc(sizeof(mods)); // 分配足够的空间
    int count = 0;

    // 填充 adjacent_ids 数组，根据您的图结构来确定哪些模型与 current_id 相邻
    for (int i = 0; i < size; i++) {
        if (mods[i].id==current_id) {
            adjacent_ids[count++] = mods[i].id;
        }
    }
    adjacent_ids[count] = 0; // 以 0 结尾，表示数组结束

    return adjacent_ids;
}


int bfs(struct model mods[], int size, unsigned int start_id) {
    int visited[size];
    for (int i = 0; i < size; i++) {
        visited[i] = 0; // 初始化访问标记数组
    }

    // 创建一个队列
    int *queue = (int *)malloc(size * sizeof(int));
    int front = 0, rear = 0;

    // 将起始节点加入队列并标记为已访问
    queue[rear++] = start_id;
    visited[start_id] = 1;

    int count = 0;  // 用于计数已访问的节点数

    while (front != rear) {
        unsigned int current_id = queue[front++];
        count++;  // 每访问一个节点，计数器加一

        // 获取当前模型的所有邻接模型的 ID
        unsigned int *adjacent_ids = getAdjacent(mods, current_id, size);
        for (int i = 0; adjacent_ids[i] != 0; i++) {
            if (!visited[adjacent_ids[i]]) {
                visited[adjacent_ids[i]] = 1;
                queue[rear++] = adjacent_ids[i];
            }
        }
        free(adjacent_ids); // 释放由 getAdjacent 分配的内存
    }

    free(queue); // 释放队列
    return count; // 返回已访问的节点数
}


// 深度遍历
struct model *find_mod(unsigned int id) {
    struct model list[MAX_SIZE];
    int visited[100] = {0};  // 初始化访问标记数组
    struct model *found = NULL;// 用于存储找到的 model 对象的指针


    dfs(0, list, visited, MAX_SIZE, id, &found);  // 调用修改后的 dfs 函数

    return found; // 返回找到的 model 对象的指针，如果未找到，则为 NULL

}


int find_all_mod(struct model mods[]) {
    return bfs(mods,100,1);
}

void delete_mod(unsigned int id) {
    // TODO 实现按深度删除
}

