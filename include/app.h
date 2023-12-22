#ifndef DS_DESIGN_APP_H
#define DS_DESIGN_APP_H

static const int TRUE = 1;
static const int MAX_SIZE = 100;
static long int global_id = 1;
struct model {
    unsigned int id;       // 编号
    char *name;           //姓名
    unsigned  int age;     // 年龄
    unsigned int height;   // 身高
};

#endif //DS_DESIGN_APP_H
