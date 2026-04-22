#include "queen_attack.h"

attack_status_t can_attack(position_t queen_1, position_t queen_2) {
    // out of the chessboard (the position is unsigned)
    if (queen_1.row > 7 || queen_2.row > 7 || queen_1.column > 7 ||
        queen_2.column > 7)
        return INVALID_POSITION;

    position_t distance = {.row = (queen_1.row >= queen_2.row)
                                      ? queen_1.row - queen_2.row
                                      : queen_2.row - queen_1.row,
                           .column = (queen_1.column >= queen_2.column)
                                         ? queen_1.column - queen_2.column
                                         : queen_2.column - queen_1.column};

    // same position
    if (distance.row == 0 && distance.column == 0)
        return INVALID_POSITION;

    return (distance.row == 0 || distance.column == 0 ||
            distance.row == distance.column)
               ? CAN_ATTACK
               : CAN_NOT_ATTACK;
}