#include "robot_simulator.h"
#include <stddef.h>

robot_status_t robot_create(robot_direction_t direction, int x, int y) {
    robot_status_t robot = {.direction =
                                (direction >= DIRECTION_NORTH && direction <= DIRECTION_WEST)
                                    ? direction
                                    : DIRECTION_NORTH,
                            .position.x = x,
                            .position.y = y};
    return robot;
}

void robot_move(robot_status_t *robot, const char *commands) {
    for (size_t i = 0; commands[i] != '\0'; i++) {
        switch (commands[i]) {
        case 'R':
            robot->direction = (robot->direction + 1) % 4;
            break;
        case 'L':
            robot->direction = (robot->direction + 3) % 4;
            // adding 3 is the same as subtracting 1 since the states are circular
            break;
        case 'A': {
            static const int dx[] = {0, 1, 0, -1};
            static const int dy[] = {1, 0, -1, 0};
            robot->position.x += dx[robot->direction];
            robot->position.y += dy[robot->direction];
            break;
        }
        default:
            return;
        }
    }
}