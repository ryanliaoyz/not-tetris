//
// Created by ryan on 4/22/20.
//

#include "Block.h"
#include <vector>

b2Vec2 gravity(0.0f, -1.0f);
b2World world(gravity);
b2Body* body;
std::vector<b2Body*> bodies;
b2Vec2 position;
float32 angle;
int current_ = 0;

void Block::setup() {


    //groundbox

    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);

    b2Body* groundBody = world.CreateBody(&groundBodyDef);

    b2PolygonShape groundBoxbot;
    groundBoxbot.SetAsBox(1000.0f, 10.1f);

    groundBody->CreateFixture(&groundBoxbot, 0.0f);

    b2BodyDef groundBodyDefleft;
    groundBodyDefleft.position.Set(0.0f, 0.0f);

    b2Body* groundBodyleft = world.CreateBody(&groundBodyDefleft);

    b2PolygonShape groundBoxleft;
    groundBoxleft.SetAsBox(.1f, 10.1f);

    groundBodyleft->CreateFixture(&groundBoxleft, 0.0f);


    b2BodyDef groundBodyDefright;
    groundBodyDefright.position.Set(4.0f, 0.0f);

    b2Body* groundBodyright = world.CreateBody(&groundBodyDefright);

    b2PolygonShape groundBoxright;
    groundBoxright.SetAsBox(.1f, 10.1f);

    groundBodyright->CreateFixture(&groundBoxright, 0.0f);


}

void Block::generateBox() {
//    b2BodyDef bodyDef;
//    bodyDef.type = b2_dynamicBody;
//    bodyDef.position.Set(2.0f, 4.0f);
//    body = world.CreateBody(&bodyDef);
//
//    b2PolygonShape dynamicBox;
//
//    dynamicBox.SetAsBox(0.1f, 0.1f);
//
//    b2FixtureDef fixtureDef;
//    fixtureDef.shape = &dynamicBox;
//    fixtureDef.density = 1.0f;
//    fixtureDef.friction = 0.3f;
//
//    body->CreateFixture(&fixtureDef);
    body = generateRandomBlock();
    bodies.push_back(body);

}

b2Body* Block::generateRandomBlock() {
    b2Body* temp_body;
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(2.0f, 4.0f);
    temp_body = world.CreateBody(&bodyDef);



    //left Z shape
    b2PolygonShape dynamicBox1;
    b2PolygonShape dynamicBox2;
    b2PolygonShape dynamicBox3;
    b2PolygonShape dynamicBox4;

    b2Vec2 offset1;
    b2Vec2 offset2;
    b2Vec2 offset3;
    b2Vec2 offset4;

    srand(time(0));  // Initialize random number generator.

    int id = rand() % 7 + 1;

    switch (id) {

        case 1: //left Z shape
            offset1.x = 0.0f;
            offset1.y = 0.0f;
            offset2.x = 0.2f;
            offset2.y = 0.0f;
            offset3.x = 0.2f;
            offset3.y = -0.2f;
            offset4.x = 0.4;
            offset4.y = -0.2f;
            break;
        case 2: //right Z shape
            offset1.x = 0.0f;
            offset1.y = 0.0f;
            offset2.x = 0.2f;
            offset2.y = 0.0f;
            offset3.x = 0.2f;
            offset3.y = 0.2f;
            offset4.x = 0.4;
            offset4.y = 0.2f;
            break;
        case 3: //T shape
            offset1.x = 0.0f;
            offset1.y = 0.0f;
            offset2.x = 0.2f;
            offset2.y = 0.0f;
            offset3.x = 0.2f;
            offset3.y = 0.2f;
            offset4.x = 0.4;
            offset4.y = 0.0f;
            break;
        case 4: //left L shape
            offset1.x = 0.0f;
            offset1.y = 0.0f;
            offset2.x = 0.0f;
            offset2.y = -0.2f;
            offset3.x = 0.2f;
            offset3.y = -0.2f;
            offset4.x = 0.4;
            offset4.y = -0.2f;
            break;
        case 5: //right L shape
            offset1.x = 0.0f;
            offset1.y = 0.0f;
            offset2.x = 0.2f;
            offset2.y = 0.0f;
            offset3.x = 0.4f;
            offset3.y = 0.0f;
            offset4.x = 0.4;
            offset4.y = 0.2f;
            break;
        case 6: //I shape
            offset1.x = 0.0f;
            offset1.y = 0.0f;
            offset2.x = 0.2f;
            offset2.y = 0.0f;
            offset3.x = 0.2f;
            offset3.y = 0.0f;
            offset4.x = 0.4;
            offset4.y = 0.0f;
            break;
        default: // O shape
            offset1.x = 0.0f;
            offset1.y = 0.0f;
            offset2.x = 0.2f;
            offset2.y = 0.0f;
            offset3.x = 0.2f;
            offset3.y = -0.2f;
            offset4.x = 0.0;
            offset4.y = -0.2f;

    }


    dynamicBox1.SetAsBox(0.1f, 0.1f, offset1, .0f);
    dynamicBox2.SetAsBox(0.1f, 0.1f, offset2, .0f);
    dynamicBox3.SetAsBox(0.1f, 0.1f, offset3, .0f);
    dynamicBox4.SetAsBox(0.1f, 0.1f, offset4, .0f);

    b2FixtureDef fixtureDef1;
    b2FixtureDef fixtureDef2;
    b2FixtureDef fixtureDef3;
    b2FixtureDef fixtureDef4;

    fixtureDef1.shape = &dynamicBox1;
    fixtureDef2.shape = &dynamicBox2;
    fixtureDef3.shape = &dynamicBox3;
    fixtureDef4.shape = &dynamicBox4;

    fixtureDef1.density = 1.0f;
    fixtureDef1.friction = 0.3f;
    fixtureDef2.density = 1.0f;
    fixtureDef2.friction = 0.3f;
    fixtureDef3.density = 1.0f;
    fixtureDef3.friction = 0.3f;
    fixtureDef4.density = 1.0f;
    fixtureDef4.friction = 0.3f;

    temp_body->CreateFixture(&fixtureDef1);
    temp_body->CreateFixture(&fixtureDef2);
    temp_body->CreateFixture(&fixtureDef3);
    temp_body->CreateFixture(&fixtureDef4);
    return temp_body;
    bodies.push_back(body);
}
void Block::move(float32 val) {
    float32 x = body->GetPosition().x + val;
    b2Vec2 newVec;
    newVec.x = x;
    newVec.y = body->GetPosition().y;
    body->SetTransform(newVec, body->GetAngle());
}




void Block::rotate() {
    body->SetTransform(body->GetPosition(), body->GetAngle() + 0.1f);
}


void Block::step(float32 f, int32 s, int32 t) {

        world.Step(f, s, t);
        position = bodies[current_]->GetPosition();
        angle = bodies[current_]->GetAngle();

//        printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
}


b2Vec2 Block::getPosition() {
    return position;
}

float32 Block::getAngle() {
    return angle;
}

int Block::getcurrent() {
    return current_;
}

void Block::setcurrent(int i) {
    current_ = i;
}

std::vector<b2Body *> Block::getBodies() {
    return bodies;
}


b2Body *Block::getCurrentBody() {
    return body;
}
