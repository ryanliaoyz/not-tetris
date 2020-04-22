//
// Created by ryan on 4/22/20.
//

#ifndef FINALPROJECT_BLOCK_H
#define FINALPROJECT_BLOCK_H
#include <Box2D/Box2D.h>

class Block {
public:
    Block() {};
    void setup();
    void step(float32 f, int32 s, int32 t);
    b2Vec2 getPosition();
    float32 getAngle();
};


#endif //FINALPROJECT_BLOCK_H
