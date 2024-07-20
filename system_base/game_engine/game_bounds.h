/** 
 * @file            game_bounds.h
 * @author          Ashton Fritz
 * @version         0.1
 * @date            Jul 20 2024
 */

#ifndef GAME_ENGINE_GAME_BOUNDS_H_
#define GAME_ENGINE_GAME_BOUNDS_H_

#include <stdbool.h>

/**
 * @brief A projection of the vector on a global axis
 * @param Global_Position_Axis_Projection An unsigned int that is a projection of a vector on a global axis for a part of the global vector
 */
typedef unsigned int Global_Position_Axis_Projection;

/**
 * @brief A component of the global position vector
 * @param Position_Axis_Projection An int that is a projection of a vector on a global axis for a relative vector
 */
typedef int Position_Axis_Projection;

/**
 * @struct _position
 * @brief A position vector that allows for relative positioning, consisting of a x,y and z component of type Position_Axis_Projection (int)
 * @var _position::x_position 
 * objects relative x coordinates to another object
 * @var _position::y_position 
 * objects relative y coordinates to another object
 * @var _position::z_position 
 * objects relative z coordinates to another object
 * @typedef Position
 * Vector for relative positioning
 */
typedef struct _position{
    Position_Axis_Projection x_position;
    Position_Axis_Projection y_position;
    Position_Axis_Projection z_position;
} Position;

/**
 * @struct _global_position
 * @brief A global position vector that allows for positioning, consisting of a x,y and z component of type Global_Position_Axis_Projection (unsigned int)
 * @var _global_position::global_x_position 
 * objects global x coordinates
 * @var _global_position::global_y_position 
 * objects global x coordinates
 * @var _global_position::global_z_position 
 * objects global x coordinates
 * @typedef Global_Position 
 * Vector for global positioning
 */
typedef struct _global_position{
    Global_Position_Axis_Projection global_x_position;
    Global_Position_Axis_Projection global_y_position;
    Global_Position_Axis_Projection global_z_position;
} Global_Position;

/** 
 * @brief           Determine the magnitude of the relative position vector 
 * @param           vector A vector that is a relative position
 * @result          The magnitude of the vector
 */
unsigned int vector_magnitude(Position vector);

/** 
 * @brief           Determine the phase of the relative position vector 
 * @param           vector A vector that is a relative position
 * @result          The phase of the vector in degrees between -180 and 180 degrees
 */

int vector_phase_degrees(Position vector);

/** 
 * @brief           Determine the phase of the relative position vector 
 * @param           vector A vector that is a relative position
 * @result          The phase of the vector in radians between -pi and pi radians
 */
int vector_phase_radians(Position vector);

#endif
