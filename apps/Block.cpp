//
// Created by ryan on 4/22/20.
//

#include "Block.h"
#include <vector>

b2Vec2 gravity(0.0f, -1.0f);
b2World world(gravity);
b2Body* body;
b2Vec2 position;
float32 angle;
void Block::setup() {

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(2.0f, 4.0f);
    body = world.CreateBody(&bodyDef);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;

    body->CreateFixture(&fixtureDef);

    //groundbox

    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.8f);

    b2Body* groundBody = world.CreateBody(&groundBodyDef);

    b2PolygonShape groundBox;
    groundBox.SetAsBox(50.0f, 10.0f);

    groundBody->CreateFixture(&groundBox, 0.0f);
}


void Block::step(float32 f, int32 s, int32 t) {

        world.Step(f, s, t);
        position = body->GetPosition();
        angle = body->GetAngle();

        printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
}


b2Vec2 Block::getPosition() {
    return position;
}

float32 Block::getAngle() {
    return angle;
}
