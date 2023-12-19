#include "app.h"

#ifndef DS_DESIGN_INVITATION_SERVICE_H
#define DS_DESIGN_INVITATION_SERVICE_H

void add_inv(struct invitation inv);

void remove_inv(unsigned int id);

void update_inv(unsigned int id, struct invitation inv);

struct invitation *get_inv(unsigned int id);

int list_inv(struct invitation[]);

#endif //DS_DESIGN_INVITATION_SERVICE_H
