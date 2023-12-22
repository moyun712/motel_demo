#include <stdio.h>
#include <argp.h>
#include <string.h>
#include <stdlib.h>
#include "mod.h"
#include "mod_repo.h"

static int parse_create_opt(int key, char *arg, struct argp_state *state) {
    struct model *input = state->input;

    char *ptr;
    switch (key) {
        case 1111: // NAME
            input->name = arg;
            break;
        case 2222: // AGE
            input->age = arg;
            break;
        case 3333: // START_DATE
            strcpy(input->start_date, arg);
            break;
        case 4444: // DAYS
            input->days = strtol(arg, &ptr, 10);
            break;
        case 5555: // DEADLINE
            strcpy(input->deadline, arg);
            break;
        case 6666: // NUMBER
            input->number = strtol(arg, &ptr, 10);
            break;
        default:
            break;
    }

    return 0;
}

int create(int argc, char *argv[]) {
    struct model mod;
    struct argp_option options[] = {
            {"name",        1111, "NAME",      0,                    "model姓名"},
            {"age",         2222, "AGE", OPTION_ARG_OPTIONAL,          "年龄"},
            {"start_date",  3333, "START_DATE", 0,                    "开始日期"},
            {"days",        4444, "DAYS",       0,                    "游玩天数"},
            {"deadline",    5555, "DEADLINE",   0,                    "报名截止日期"},
            {"number",      6666, "NUMBER",     0,                    "报名人数"},
            {0}
    };

    struct argp argp = {options, parse_create_opt};

    argp_parse(&argp, argc, argv, 0, 0, &mod);

    add_mod(mod);

    return 0;
}

int list() {
    struct model list[MAX_SIZE];
    int count = list_mod(list);

    if (count == 0) {
        printf("当前没有任何邀请函\n");
    }

    const char *format = "ID: %d, 标题：%s, 开始日期：%s，天数：%d，截止日期：%s，人数：%d\n";
    for (int i = 0; i < count; i++) {
        printf(format, list[i].id, list[i].name, list[i].start_date, list[i].days, list[i].deadline, list[i].number);
    }

    return 0;
}

static int parse_update_opt(int key, char *arg, struct argp_state *state) {
    struct model *input = state->input;

    char *ptr;
    switch (key) {
        case 9999: // ID
            input->id = strtol(arg, &ptr, 10);
        case 1111: // NAME
            input->name = arg;
            break;
        case 2222: // AGE
            input->age = arg;
            break;
        case 3333: // START_DATE
            strcpy(input->start_date, arg);
            break;
        case 4444: // DAYS
            input->days = strtol(arg, &ptr, 10);
            break;
        case 5555: // DEADLINE
            strcpy(input->deadline, arg);
            break;
        case 6666: // NUMBER
            input->number = strtol(arg, &ptr, 10);
            break;
        default:
            break;
    }

    return 0;
}

int update(int argc, char *argv[]) {
    struct model mod;
    struct argp_option options[] = {
            {"id",          9999, "ID",         0,                    "modelID"},
            {"name",       1111, "NAME",      0,                    "model姓名"},
            {"age",        2222, "AGE", OPTION_ARG_OPTIONAL,             "年龄"},
            {"days",        4444, "DAYS",       0,                    "游玩天数"},
            {"start_date",  3333, "START_DATE", 0,                    "开始日期"},
            {"deadline",    5555, "DEADLINE",   0,                    "报名截止日期"},
            {"number",      6666, "NUMBER",     0,                    "报名人数"},
            {0}
    };

    struct argp argp = {options, parse_update_opt};

    argp_parse(&argp, argc, argv, 0, 0, &mod);

    update_mod(mod.id, mod);

    return 0;
}

static int parse_id_opt(int key, char *arg, struct argp_state *state) {
    unsigned int *id = state->input;
    char *ptr;
    if (key == 1111) {
        *id = strtol(arg, &ptr, 10);
    }

    return 0;
}

int delete(int argc, char *argv[]) {
    unsigned int id;
    struct argp_option options[] = {
            {"id", 1111, 0, 0, "邀请函ID"},
            {0}
    };

    struct argp argp = {options, parse_id_opt};

    argp_parse(&argp, argc, argv, 0, 0, &id);

    remove_mod(id);

    return 0;
}

int query(int argc, char *argv[]) {
    unsigned int id;
    struct argp_option options[] = {
            {"id", 1111, 0, 0, "邀请函ID"},
            {0}
    };

    struct argp argp = {options, parse_id_opt};

    argp_parse(&argp, argc, argv, 0, 0, &id);

    struct model mod = *get_mod(id);

    const char *format = "ID: %d, 标题：%s, 开始日期：%s，天数：%d，截止日期：%s，人数：%d\n";
    printf(format, mod.id, mod.name, mod.start_date, mod.days, mod.deadline, mod.number);

    return 0;
}

int count() {
    printf("当前共有 %d 个邀请函\n", count_mod());
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("dsd02 <create|list|update|delete|count> [OPTION...]\n");
        return 0;
    }

    if (strcmp("create", argv[1]) == 0) {
        return create(argc, argv);
    }

    if (strcmp("list", argv[1]) == 0) {
        return list();
    }

    if (strcmp("update", argv[1]) == 0) {
        return update(argc, argv);
    }

    if (strcmp("delete", argv[1]) == 0) {
        return delete(argc, argv);
    }

    if (strcmp("count", argv[1]) == 0) {
        return count();
    }

    if (strcmp("query", argv[1]) == 0) {
        return query(argc, argv);
    }

}