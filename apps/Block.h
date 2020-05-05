//
// Created by ryan on 4/22/20.
//

#ifndef FINALPROJECT_BLOCK_H
#define FINALPROJECT_BLOCK_H
#include <Box2D/Box2D.h>
#include <vector>
class Block {
public:
    Block() {};
    void setup();
    void step(float32 f, int32 s, int32 t);
    b2Vec2 getPosition();
    void generateBox();
    b2Body* generateRandomBlock();
    float32 getAngle();
    int getcurrent();
    void setcurrent(int i);
    std::vector<b2Body*> getBodies();
    void move(float32 val);
    void rotate();
    b2Body* getCurrentBody();
    void deleteBody(int line);
    float32 findIntersect(float32 x1, float32 x2, float32 y1, float32 y2, float32 height);
};


#endif //FINALPROJECT_BLOCK_H
