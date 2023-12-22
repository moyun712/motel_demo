#include "mod.h"
#include "mod_repo.h"

int list_mod(struct model mods[]) {
    return find_all_mod(mods);
}

void add_mod(struct model mod) {
    save_mod(mod);
}

void remove_mod(unsigned int id) {
    delete_mod(id);
}

void update_mod(unsigned int id, struct model mod) {
    mod.id = id;
    save_mod(mod);
}

struct model *get_mod(unsigned int id) {
    return find_mod(id);
}
struct model *getmod(struct model mod[]){

    return ;
}
