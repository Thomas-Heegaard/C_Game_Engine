/*
=================================== ===== ==== === == = =  =   =    =     =
|File     : entity.h
|Author   : Thomas Heegaard
|Created  : 11/07/2014
|Purpose  : 
|
|Comments : 
|
=================================== ===== ==== === == = =  =   =    =     =
*/

#ifndef ENTITY_H
#define ENTITY_H

#include "global_defines.h"
#include "sprite.h"
#include "physics.h"
#include "collision_object.h"

typedef struct Entity
{
    unsigned short  type;
    unsigned char   flags;

    double              center_x;
    double              center_y;
    float               angle;
    double              x_speed;
    double              y_speed;
    float               a_speed;

    unsigned short      bounding_radius;

    Sprite*             sprite;
    PhysicsObject*      physics_object;
    CollisionObject*    collision_object;
} Entity;

//=====================================================================
//          FLAGS
//=====================================================================

#define CUSTOM_INIT     1
#define CUSTOM_UPDATE   2
#define CUSTOM_DRAW     4
#define CUSTOM_EXIT     8
#define HAS_SPRITE      16
#define HAS_PHYSICS     32
#define HAS_COLLISION   64


Entity* NewEntity(const char* entity_file);

Entity* CopyEntity(Entity* original);

ERR     UpdateEntity(Entity* entity);

ERR     DrawEntity(Entity* entity);

ERR     FreeEntity(Entity* entity);

#endif //ENTITY_H
