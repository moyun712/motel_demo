#include "app.h"

#ifndef DS_DESIGN_INVITATION_REPOSITORY_H
#define DS_DESIGN_INVITATION_REPOSITORY_H

void save_inv(struct invitation inv);

struct invitation *find_inv(unsigned int id);

int find_all_inv(struct invitation[]);

void delete_inv(unsigned int id);

int count_inv();

#endif //DS_DESIGN_INVITATION_REPOSITORY_H
