/** 
 * @file            movement.h
 * @author          Ashton Fritz
 * @version         0.2
 * @date            Jul 20 2024
 */

#ifndef GAME_ENGINE_MOVEMENT_H_
#define GAME_ENGINE_MOVEMENT_H_

#include "game_errors.h"
#include "game_bounds.h"

/** 
 * @brief           Move forwards with constant speed
 * @details         Move in the positive x-direction x units
 * @param           x_amount x units
 * @param           position global position for game
 * @result          If the object successfully moved x units 
 */
Bounds_Error_Check move_constant_forwards(Global_Position position, const unsigned int x_amount, Bounds_Error_Check bounds);

/**
 * @brief           Move backwards with constant speed
 * @details         Move in the negative x-direction x units
 * @param           x_amount x units
 * @param           position global position for game 
 * @result          If the object successfully moved x units 
 */
Bounds_Error_Check move_constant_backwards(Global_Position position, const unsigned int x_amount, Bounds_Error_Check bounds);

/**
 * @brief           Move upwards with constant speed
 * @details         Move in the positive z-direction z units
 * @param           z_amount z units
 * @param           position global position for game 
 * @result          If the object successfully moved z units 
 */
Bounds_Error_Check move_constant_upwards(Global_Position position, const unsigned int z_amount, Bounds_Error_Check bounds);

/**
 * @brief           Move downwards with constant speed
 * @details         Move in the negative z-direction z units
 * @param           z_amount z units
 * @param           position global position for game 
 * @result          If the object successfully moved z units 
 */
Bounds_Error_Check move_constant_downwards(Global_Position position, const unsigned int z_amount, Bounds_Error_Check bounds);

/**  
 * @brief           Move leftwards with constant speed
 * @details         Move in the positive y-direction y units
 * @param           y_amount y units
 * @param           position global position for game 
 * @result          If the object successfully moved y units 
 */
Bounds_Error_Check move_constant_leftwards(Global_Position position, const unsigned int y_amount, Bounds_Error_Check bounds);

/**
 * @brief           Move in the direction of the vector and at the speed of the vector
 * @details         Move the object in the direction of the vector 
 * @param           vector A movement vector to move towards
 * @param           position global position for game 
 * @result          If the object successfully moved towards the vector 
 */
Bounds_Error_Check move_constant(Global_Position position, const Position vector);

/**
 * @brief           Set global position to new global position 
 * @details         Teleport object to new global position
 * @param           global position vector
 * @param           new global position vectore 
 * @result          If the object successfully was moved to new global position*/
Bounds_Error_Check set_global_position(Global_Position position, const Global_Position new_position);
#endif
