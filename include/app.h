#ifndef DS_DESIGN_APP_H
#define DS_DESIGN_APP_H

static const int TRUE = 1;
static const int MAX_SIZE = 100;

struct invitation {
    unsigned int id;       // 编号
    char *title;           // 标题
    char *description;     // 描述
    char start_date[12];   // 开始日期
    unsigned int days;     // 游玩天数
    char deadline[12];     // 报名截止日期
    unsigned int number;   // 报名人数
};

#endif //DS_DESIGN_APP_H
