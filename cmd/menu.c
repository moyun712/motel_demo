#include <stdio.h>
#include "mod.h"
#include "mod_repo.h"
#include "app.h"




void display() {
    printf("model管理信息系统\n");
    printf("1. 增加model信息\n");
    printf("2. 删除model信息\n");
    printf("3. 修改model信息\n");
    printf("4. 查询model信息\n");
    printf("5. 统计model个数\n");
    printf("6. 输出model信息\n");
    printf("7. 退出\n");
    printf("请输入你的选择（1-7）：");
    fflush(stdout);
}


void add_model() {
    struct model mod = {};
    mod.id = global_id++;
    printf("请输入model姓名：");
    fflush(stdout);
    int result = scanf("%ms", &mod.name);
    if (result != 1) {
        printf("输入错误");
        fflush(stdout);
    }

    while (getchar() != '\n');
    printf("请输入年龄信息：");
    fflush(stdout);

    if (scanf("%ud", &mod.age) != 1) {
        printf("输入错误");
        fflush(stdout);
    }
    while (getchar() != '\n');
    printf("请输入身高：");
    fflush(stdout);
    if (scanf("%ud", &mod.height) != 1) {
        printf("输入错误");
        fflush(stdout);
    }
    printf("%s",mod.name);
    fflush(stdout);

    add_mod(mod);
}

void delete_model() {
    unsigned int id;
    printf("请输入要删除的编号：");
    fflush(stdout);
    if (scanf("%u", &id) != 1) {
        printf("输入错误");
        fflush(stdout);
    }

    remove_mod(id);
}

void update_model() {
    unsigned int id;
    printf("请输入要更新的编号：");
    fflush(stdout);
    if (scanf("%u", &id) != 1) {
        printf("输入错误");
        fflush(stdout);
    }

    struct model mod = {};

    printf("请输入标题：");
    if (scanf("%s", &mod.name) != 1) {
        printf("输入错误");
    }

    while (getchar() != '\n');
    printf("请输入年龄信息：");
    if (scanf("%u", &mod.age) != 1) {
        printf("输入错误");
    }

    while (getchar() != '\n');
    printf("请输入开始日期：");
    if (scanf("%u", &mod.height) != 1) {
        printf("输入错误");
    }

    update_mod(id, mod);
}

void search_model() {
    unsigned int id;
    printf("请输入要查询的编号：");
    fflush(stdout);
    if (scanf("%ud", &id) != 1) {
        printf("输入错误");
        fflush(stdout);
    }

    struct model* mod = get_mod(id);

    if(mod!=NULL){
        printf("编号：%u\n", mod->id);
        printf("姓名：%s\n", mod->name);
        printf("年龄：%u\n", mod->age);
        printf("身高：%u\n", mod->height);
        fflush(stdout);
    }else printf("未找到该model信息");

}

void count_model() {
    printf("当前共有%d个model\n", count_mod());
    fflush(stdout);
}

void list_models() {
    struct model list[MAX_SIZE];
    int size = list_mod(getmod(list));

    for (int i = 0; i < size; i++) {
        printf("-----------编号：%u-------------\n", list[i].id);
        printf("姓名：%s\n", list[i].name);
        printf("年龄：%u\n", list[i].age);
        printf("身高：%u\n", list[i].height);
        fflush(stdout);
    }
}

int main() {
    while (1) {
        display();

        int choice = 0;
        if (scanf("%d", &choice) != 1) {
            printf("输入错误");
            fflush(stdout);
        }

        if (choice > 7 || choice < 1) {
            continue;
        }

        if (choice == 7) {
            break;
        }

        switch (choice) {
            case 1:
                add_model();
                break;
            case 2:
                delete_model();
                break;
            case 3:
                update_model();
                break;
            case 4:
                search_model();
                break;
            case 5:
                count_model();
                break;
            case 6:
                list_models();
                break;
            default:
                break;
        }

        getchar();
        getchar();
    }
    return 0;
}