#include "app.h"

#ifndef DS_DESIGN_MODEL_SERVICE_H
#define DS_DESIGN_MODEL_SERVICE_H

void add_mod(struct model mod);

void remove_mod(unsigned int id);

void update_mod(unsigned int id, struct model mod);

struct model *get_mod(unsigned int id);

int list_mod(struct model[]);

struct model *getmod(struct model mod[]);



#endif //DS_DESIGN_MODEL_SERVICE_H
