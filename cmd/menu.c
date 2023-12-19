#include <stdio.h>
#include "inv.h"
#include "inv_repo.h"
#include "app.h"

void display() {
    printf("结伴游系统功能菜单\n");
    printf("1. 增加邀请函\n");
    printf("2. 删除邀请函\n");
    printf("3. 修改邀请函\n");
    printf("4. 查询邀请函信息\n");
    printf("5. 统计邀请函个数\n");
    printf("6. 输出邀请函信息\n");
    printf("7. 退出\n");
    printf("请输入你的选择（1-7）：");
}


void add_invitation() {
    struct invitation inv = {};

    printf("请输入标题：");
    if (scanf("%s", inv.title) != 1) {
        printf("输入错误");
    }

    printf("请输入描述信息：");
    if (scanf("%s", inv.description) != 1) {
        printf("输入错误");
    }

    printf("请输入开始日期：");
    if (scanf("%s", inv.start_date) != 1) {
        printf("输入错误");
    }

    printf("请输入报名截止日期：");
    if (scanf("%s", inv.deadline) != 1) {
        printf("输入错误");
    }

    printf("请输入游玩天数：");
    if (scanf("%d", &inv.days) != 1) {
        printf("输入错误");
    }

    printf("请输入报名人数：");
    if (scanf("%d", &inv.number) != 1) {
        printf("输入错误");
    }

    add_inv(inv);
}

void delete_invitation() {
    unsigned int id;
    printf("请输入要删除的编号：");
    if (scanf("%u", &id) != 1) {
        printf("输入错误");
    }

    remove_inv(id);
}

void update_invitation() {
    unsigned int id;
    printf("请输入要更新的编号：");
    if (scanf("%u", &id) != 1) {
        printf("输入错误");
    }

    struct invitation inv = {};

    printf("请输入标题：");
    if (scanf("%s", inv.title) != 1) {
        printf("输入错误");
    }

    printf("请输入描述信息：");
    if (scanf("%s", inv.description) != 1) {
        printf("输入错误");
    }

    printf("请输入开始日期：");
    if (scanf("%s", inv.start_date) != 1) {
        printf("输入错误");
    }

    printf("请输入报名截止日期：");
    if (scanf("%s", inv.deadline) != 1) {
        printf("输入错误");
    }

    printf("请输入游玩天数：");
    if (scanf("%d", &inv.days) != 1) {
        printf("输入错误");
    }

    printf("请输入报名人数：");
    if (scanf("%d", &inv.number) != 1) {
        printf("输入错误");
    }

    update_inv(id, inv);
}

void search_invitation() {
    unsigned int id;
    printf("请输入要查询的编号：");
    if (scanf("%u", &id) != 1) {
        printf("输入错误");
    }

    struct invitation* inv = get_inv(id);

    printf("编号：%u\n", inv->id);
    printf("标题：%s\n", inv->title);
    printf("描述：%s\n", inv->description);
    printf("开始日期：%s\n", inv->start_date);
    printf("游玩天数：%d\n", inv->days);
    printf("报名截止日期：%s\n", inv->deadline);
    printf("报名人数：%d\n", inv->number);
}

void count_invitation() {
    printf("当前共有%d个邀请函\n", count_inv());
}

void list_invitations() {
    struct invitation list[MAX_SIZE];
    int size = list_inv(list);

    for (int i = 0; i < size; i++) {
        printf("-----------编号：%u-------------\n", list[i].id);
        printf("标题：%s\n", list[i].title);
        printf("描述：%s\n", list[i].description);
        printf("开始日期：%s\n", list[i].description);
        printf("游玩天数：%d\n", list[i].days);
        printf("报名截止日期：%s\n", list[i].deadline);
        printf("报名人数：%d\n", list[i].number);
    }
}

int main() {
    while (1) {
        display();

        int choice = 0;
        if (scanf("%d", &choice) != 1) {
            printf("输入错误");
        }

        if (choice > 7 || choice < 1) {
            continue;
        }

        if (choice == 7) {
            break;
        }

        switch (choice) {
            case 1:
                add_invitation();
                break;
            case 2:
                delete_invitation();
                break;
            case 3:
                update_invitation();
                break;
            case 4:
                search_invitation();
                break;
            case 5:
                count_invitation();
                break;
            case 6:
                list_invitations();
                break;
            default:
                break;
        }

        getchar();
        getchar();
    }
    return 0;
}