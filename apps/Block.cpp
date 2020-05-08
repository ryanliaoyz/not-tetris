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

//    generateBox();
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

void Block::deleteBody(int line) {
    int upperbound = line * 40 + 20;
    int lowerbound = upperbound - 40;
    for (b2Body* b = world.GetBodyList(); b; b = b->GetNext()) {
        for (b2Fixture* f = b->GetFixtureList(); f; f = f->GetNext()) {

            b2PolygonShape* s = reinterpret_cast<b2PolygonShape *>(f->GetShape());
            b2Body* temp = f->GetBody();
            int size = s->GetVertexCount();
            std::vector<float32> intersects(size);
            std::vector<float32> vx(size);
            std::vector<float32> vy(size);
            for (int i = 0; i < size; i++) {
                vx[i] = temp->GetWorldPoint(s->GetVertex(i)).x * 200;
                vy[i] = temp->GetWorldPoint(s->GetVertex(i)).y * 200;
            }

            for (int i = 0; i < size; i++) {
                int loc;
                if (i < size - 1) {
                    loc = i + 1;
                } else {
                    loc = 0;
                }
                float32 x1 = vx[i];
                float32 y1 = vy[i];
                float32 x2 = vx[loc];
                float32 y2 = vy[loc];
                float32 intersect = findIntersect(x1, x2, y1, y2, upperbound);
                if (intersect <= 0 || intersect > 800) {
                    break;
                } else {
                    intersects.push_back(intersect);
                }
            }
            break;
        }
    }
}


float32 Block::findIntersect(float32 x1, float32 x2, float32 y1, float32 y2, float32 height) {
    float32 intersection;
    float32 m1, c1, m2, c2;
    float32 dx, dy;

    m1 = 0;
    c1 = height;

    dx = x2 - x1;
    dy = y2 - y1;
    m2 = dy / dx;
    c2 = y2 - m2 * x2;
    if (m1 - m2 == 0) {
        return 0;
    }
    return (c2 - c1) / (m1 - m2);
}

void Block::reset() {
    for (b2Body* b = world.GetBodyList(); b; b = b->GetNext()) {
        world.DestroyBody(b);
    }
    bodies.clear();
//    generateBox();
}
