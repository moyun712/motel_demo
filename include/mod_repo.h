#include "app.h"

#ifndef DS_DESIGN_MODEL_REPOSITORY_H
#define DS_DESIGN_MODEL_REPOSITORY_H

void save_mod(struct model mod);

struct model *find_mod(unsigned int id);

int find_all_mod(struct model[]);

void delete_mod(unsigned int id);

int count_mod();

void fillModsArray(struct model mods[], int index);

#endif //DS_DESIGN_MODEL_REPOSITORY_H
