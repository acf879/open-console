/** 
 * @file            game_errors.h
 * @author          Ashton Fritz
 * @version         0.1
 * @date            Jul 20 2024
 */

#ifndef GAME_ENGINE_GAME_ERRORS_H_
#define GAME_ENGINE_GAME_ERRORS_H_

/**
 * @enum _bounds_error
 * @brief An enum that contains states for bounds checking for individual positions
 * @var _bounds_error::IN_BOUNDS
 * Object is in bounds for the axis
 * @var _bounds_error::OUT_OF_BOUNDS_NEGATIVE
 * Object is out of bounds on negative side
 * @var _bounds_error::OUT_OF_BOUNDS_POSITIVE
 * Object is out of bounds on positive side
 * @typedef Bounds_Error
 * An enum to check if the object is within bounds
 */
typedef enum _bounds_error {
    IN_BOUNDS,
    OUT_OF_BOUNDS_NEGATIVE,
    OUT_OF_BOUNDS_POSITIVE
} Bounds_Error;

/**
 * @struct _bounds_error_check
 * @brief A structure that contains states for bounds checking
 * @var _bounds_error_check::x_bounds
 * An enum to check if it is out of bounds for the axis
 * @var _bounds_error_check::y_bounds
 * An enum to check if it is out of bounds for the axis
 * @var _bounds_error_check::z_bounds
 * An enum to check if it is out of bounds for the axis
 * @typedef Bounds_Error_Check
 * Structure to check bounds for all axis
 */
typedef struct _bounds_error_check {
    Bounds_Error x_bounds;
    Bounds_Error y_bounds;
    Bounds_Error z_bounds;
} Bounds_Error_Check;

#endif