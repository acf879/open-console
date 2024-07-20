#include "../game_engine/movement.h"
#include "../game_engine/game_errors.h"
#include "../game_engine/game_bounds.h"

Bounds_Error_Check move_constant_forwards(Global_Position position, const unsigned int x_amount) {
    Bounds_Error_Check bounds = {.x_bounds=IN_BOUNDS,.y_bounds=IN_BOUNDS,.z_bounds=IN_BOUNDS};
    return bounds; 
}

Bounds_Error_Check move_constant_backwards(Global_Position position, const unsigned int x_amount) {
    Bounds_Error_Check bounds = {.x_bounds=IN_BOUNDS,.y_bounds=IN_BOUNDS,.z_bounds=IN_BOUNDS};
    return bounds; 
}

Bounds_Error_Check move_constant_upwards(Global_Position position, const unsigned int z_amount) {
    Bounds_Error_Check bounds = {.x_bounds=IN_BOUNDS,.y_bounds=IN_BOUNDS,.z_bounds=IN_BOUNDS};
    return bounds; 
}

Bounds_Error_Check move_constant_downwards(Global_Position position, const unsigned int z_amount) {
    Bounds_Error_Check bounds = {.x_bounds=IN_BOUNDS,.y_bounds=IN_BOUNDS,.z_bounds=IN_BOUNDS};
    return bounds; 
}

Bounds_Error_Check move_constant_leftwards(Global_Position position, const unsigned int y_amount) {
    Bounds_Error_Check bounds = {.x_bounds=IN_BOUNDS,.y_bounds=IN_BOUNDS,.z_bounds=IN_BOUNDS};
    return bounds; 
}

Bounds_Error_Check move_constant_rightwards(Global_Position position, const unsigned int y_amount) {
    Bounds_Error_Check bounds = {.x_bounds=IN_BOUNDS,.y_bounds=IN_BOUNDS,.z_bounds=IN_BOUNDS};
    return bounds; 
}

Bounds_Error_Check move_constant(Global_Position position, const Position vector) {
    Bounds_Error_Check bounds = {.x_bounds=IN_BOUNDS,.y_bounds=IN_BOUNDS,.z_bounds=IN_BOUNDS};
    return bounds; 
}