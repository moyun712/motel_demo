#include "inv.h"
#include "inv_repo.h"

int list_inv(struct invitation invs[]) {
    return find_all_inv(invs);
}

void add_inv(struct invitation inv) {
    save_inv(inv);
}

void remove_inv(unsigned int id) {
    delete_inv(id);
}

void update_inv(unsigned int id, struct invitation inv) {
    inv.id = id;
    save_inv(inv);
}

struct invitation *get_inv(unsigned int id) {
    return find_inv(id);
}