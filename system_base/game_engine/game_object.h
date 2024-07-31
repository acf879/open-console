/** 
 * @file            game_object.h 
 * @author          Ashton Fritz
 * @version         0.1
 * @date            Jul 31 2024
 */

#include <stdint.h>
#include <stdlib.h>
#include "game_bounds.h"

#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

/**
 * @brief A unique identifier to reference the object with
 * @param size_t Identifier is an unique identifier for the object
 */
typedef size_t Identifier;

/**
 * @brief A tag to describe what the object is generally a part of 
 * @param size_t Tag is an identifier for the objects group such as enemies or checkpoints
 */
typedef size_t Tag;

/**
 * @brief A group tag to determine what the object is related to such as head for more complex geometries
 * @param size_t Tag is a group Identifiers for determining what group the objects are related to such as a hand 
 */
typedef size_t Group;

/**
 * @brief A list of nodes to form a geometry to check if it is colliding with 
 * @param size_t Hit_Box is a list of nodes to form a geometry
 */
typedef int16_t* Hit_Box;

/**
 * @brief A boolean to determine if the object is a trigger or not
 * @param bool Is_Trigger is a boolean to check if it is a trigger object or not 
 */
typedef bool Is_Trigger;

/**
 * @struct game_object 
 * @brief A structure that contains a simple game objects data to be added to later
 * @var Identifier::id
 * A unique Identifier for the object
 * @var Global_Position::position
 * An absolute vector for positioning in the game space 
 * @var Tag::object_tag 
 * A tag to determine what type of object it is
 * @var Group object_group 
 * A group tag to determine what group that this object is a part of for more complex
 *  geometrys containing several object structs
 * @var Hit_Box::object_hit_box 
 * A list of integers to form a basic polygon centered around the global position
 * @var size_t::nodes_in_hit_box
 * Number of nodes in the hit_box
 * @var Is_Trigger::is_trigger 
 * A boolean to determine if the object is a trigger for another object or not
 * @typedef Game_Object 
 * Structure to hold basic game object information
 */
typedef struct game_object {
  Identifier id;
  Global_Position position;
  Tag object_tag;
  Group object_group;
  Hit_Box object_hit_box;
  size_t nodes_in_hit_box;
  Is_Trigger is_trigger;
} Game_Object;

/** 
 * @brief           Check if two objects are intersecting 
 * @details         Return true if objects are intersecting
 * @param           game object 1
 * @param           game object 2
 * @result          True if colliding
 */
bool is_colliding(const Game_Object object_1, const Game_Object object_2);

/** 
 * @brief           Check if object is a trigger object 
 * @details         Determine if the object is a trigger
 * @param           game object
 * @result          true if a trigger false otherwise 
 */
bool is_trigger(const Game_Object obj);

/** 
 * @brief           Set if the object is a trigger or not 
 * @details         Returns true if it successfully set, false otherwise 
 * @param           game object 
 * @param           a boolean to set to a trigger or not
 * @result          Sets object to be a trigger or not depending on is_trigger
 */
bool set_is_trigger(Game_Object obj, const bool is_trigger);

/** 
 * @brief           Set the objects group 
 * @details         Returns true if it successfully set, false otherwise 
 * @param           game object 
 * @param           group to assign object to
 * @result          Object is assigned to group which will return true otherwise false 
 */
bool set_group(Game_Object obj, const Group group);

/** 
 * @brief           Sets the hit box of the object
 * @details         Sets the nodes of the hit box along with the length of the hit box 
 * @param           game object
 * @param           hit box nodes 
 * @param           hit box size 
 * @result          Sets the objects hit box to be the new hit box
 */
bool set_hit_box(Game_Object obj, const Hit_Box hit_box, const size_t hit_box_size);

/** 
 * @brief           Sets the objects tag 
 * @details         Returns true if it successfully set, false otherwise 
 * @param           game object
 * @param           tag of game object 
 * @result          Sets the tag of the inputted game object 
 */
bool set_tag(Game_Object obj, const Tag tag);
#endif

