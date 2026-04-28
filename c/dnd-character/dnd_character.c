#include "dnd_character.h"
#include <stdlib.h>

int ability(void) {
    int min = FACES + 1, sum = 0;
    for (int i = 0; i < ROLLS; i++) {
        int roll = rand() % FACES + 1;
        if (roll < min)
            min = roll;
        sum += roll;
    }
    return sum - min;
}

int modifier(int score) {
    // funny way to subtract one if the number is odd and goes negative
    return (score - 10) / 2 - (score < 10 && (score % 2 != 0));
}

dnd_character_t make_dnd_character(void) {
    dnd_character_t character = {
        .strength = ability(),
        .dexterity = ability(),
        .constitution = ability(),
        .intelligence = ability(),
        .wisdom = ability(),
        .charisma = ability(),
    };
    character.hitpoints = 10 + modifier(character.constitution);

    return character;
}