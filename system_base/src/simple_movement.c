#include "../game_engine/movement.h"
#include "../game_engine/game_errors.h"
#include "../game_engine/game_bounds.h"

Bounds_Error_Check move_constant_forwards(Global_Position position, const unsigned int x_amount, Bounds_Error_Check bounds) {
    position.global_x_position = position.global_x_position + x_amount;
    if (position.global_x_position >= MAX_X_BOUND) {
      bounds.x_bounds = OUT_OF_BOUNDS_POSITIVE;
      return bounds;
    } else if (position.global_x_position <= MIN_X_BOUND) {
      bounds.x_bounds = OUT_OF_BOUNDS_NEGATIVE;
      return bounds;
    }
    bounds.x_bounds = IN_BOUNDS;
    return bounds; 
}

Bounds_Error_Check move_constant_backwards(Global_Position position, const unsigned int x_amount, Bounds_Error_Check bounds) {
    if (position.global_x_position < x_amount) {
      position.global_x_position = x_amount; // set so it becomes 0 
    }
    position.global_x_position = position.global_x_position - x_amount;
    bounds = move_constant_forwards(position, 0, bounds); // check bounds 
    return bounds; 
}

Bounds_Error_Check move_constant_upwards(Global_Position position, const unsigned int z_amount, Bounds_Error_Check bounds) {
    position.global_z_position = position.global_z_position + z_amount;
    if (position.global_z_position >= MAX_Z_BOUND) {
      bounds.z_bounds = OUT_OF_BOUNDS_POSITIVE;
      return bounds;
    } else if (position.global_z_position <= MIN_Z_BOUND) {
      bounds.z_bounds = OUT_OF_BOUNDS_NEGATIVE;
      return bounds;
    }
    bounds.z_bounds = IN_BOUNDS;
    return bounds; 
}

Bounds_Error_Check move_constant_downwards(Global_Position position, const unsigned int z_amount, Bounds_Error_Check bounds) {
    if (position.global_z_position < z_amount) {
      position.global_z_position = z_amount; // set so it becomes 0 
    }
    position.global_z_position = position.global_z_position - z_amount;
    bounds = move_constant_upwards(position, 0, bounds); // check bounds 
    return bounds; 
}

Bounds_Error_Check move_constant_leftwards(Global_Position position, const unsigned int y_amount, Bounds_Error_Check bounds) {
    position.global_y_position = position.global_y_position + y_amount;
    if (position.global_y_position >= MAX_Y_BOUND) {
      bounds.y_bounds = OUT_OF_BOUNDS_POSITIVE;
      return bounds;
    } else if (position.global_y_position <= MIN_Y_BOUND) {
      bounds.y_bounds = OUT_OF_BOUNDS_NEGATIVE;
      return bounds;
    }
    bounds.y_bounds = IN_BOUNDS;
    return bounds; 
}

Bounds_Error_Check move_constant_rightwards(Global_Position position, const unsigned int y_amount, Bounds_Error_Check bounds) {
    if (position.global_y_position < y_amount) {
      position.global_y_position = y_amount; // set so it becomes 0 
    }
    position.global_y_position = position.global_y_position - y_amount;
    bounds = move_constant_leftwards(position, 0, bounds); // check bounds 
    return bounds; 
}

Bounds_Error_Check move_constant(Global_Position position, const Position vector) {
    Bounds_Error_Check bounds = {.x_bounds=IN_BOUNDS,.y_bounds=IN_BOUNDS,.z_bounds=IN_BOUNDS};
    // Make sure that the positions are above 0 (global position is uint32_t)
    if (position.global_x_position < vector.x_position) {
      position.global_x_position = vector.x_position; // set so it becomes 0 
      bounds.x_bounds = OUT_OF_BOUNDS_NEGATIVE;
    }
    if (position.global_y_position < vector.y_position) {
      position.global_y_position = vector.y_position; // set so it becomes 0 
      bounds.y_bounds = OUT_OF_BOUNDS_POSITIVE;
    }
    if (position.global_z_position < vector.z_position) {
      position.global_z_position = vector.z_position; // set so it becomes 0 
      bounds.z_bounds = OUT_OF_BOUNDS_NEGATIVE;
    }
    // Check max bounds
    if ((MAX_X_BOUND - vector.x_position) < position.global_x_position) {
      position.global_x_position = MAX_X_BOUND - vector.x_position; // set so it becomes max 
      bounds.z_bounds = OUT_OF_BOUNDS_POSITIVE;
    }
    if ((MAX_Y_BOUND - vector.y_position) < position.global_y_position) {
      position.global_y_position = MAX_Y_BOUND - vector.y_position; // set so it becomes max 
      bounds.z_bounds = OUT_OF_BOUNDS_NEGATIVE;
    }
    if ((MAX_Z_BOUND - vector.z_position) < position.global_z_position) {
      position.global_z_position = MAX_Z_BOUND - vector.z_position; // set so it becomes max 
      bounds.z_bounds = OUT_OF_BOUNDS_POSITIVE;
    }
    position.global_x_position = position.global_x_position + vector.x_position;
    position.global_y_position = position.global_y_position + vector.y_position;
    position.global_z_position = position.global_z_position + vector.z_position;

    return bounds; 
}
