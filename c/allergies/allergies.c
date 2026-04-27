#include "allergies.h"

bool is_allergic_to(allergen_t allergen, int score) { return score & 1U << allergen; }

allergen_list_t get_allergens(int score) {
    allergen_list_t list = {.count = 0, {false}};
    for (int i = 0; i < ALLERGEN_COUNT; i++)
        if (is_allergic_to(i, score)) {
            list.allergens[i] = true;
            list.count++;
        }
    return list;
}