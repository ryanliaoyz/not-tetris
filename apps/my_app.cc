// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <cinder/app/App.h>
#include <cinder/gl/gl.h>

namespace myapp {

using cinder::app::KeyEvent;
using cinder::Color;
using cinder::ColorA;
using cinder::Rectf;
using cinder::TextBox;
using cinder::app::KeyEvent;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::system_clock;
using std::string;

const int END_LINE = 3;
#if defined(CINDER_COCOA_TOUCH)
    const char kNormalFont[] = "Arial";
const char kBoldFont[] = "Arial-BoldMT";
const char kDifferentFont[] = "AmericanTypewriter";
#elif defined(CINDER_LINUX)
    const char kNormalFont[] = "Arial Unicode MS";
    const char kBoldFont[] = "Arial Unicode MS";
    const char kDifferentFont[] = "Purisa";
#else
    const char kNormalFont[] = "Arial";
const char kBoldFont[] = "Arial Bold";
const char kDifferentFont[] = "Papyrus";
#endif
MyApp::MyApp() {

}
void MyApp::setup() {


    windows_size = cinder::app::getWindowSize();
    block_.setup();
    block_.generateBox();

}

void MyApp::update() {
    if (!game_over) {
        float timeStep = 1.0f / 60.0f;
        int32 velocityIterations = 6;
        int32 positionIterations = 2;
        block_.step(timeStep, velocityIterations, positionIterations);
        if (block_.getPosition().x == rec_pos_x && rec_pos_y == block_.getPosition().y &&
            rec_pos_angle == block_.getAngle()) {
            detect_erase();
            block_.generateBox();
            block_.setcurrent(block_.getcurrent() + 1);
        }
        rec_pos_x = block_.getPosition().x;
        rec_pos_y = block_.getPosition().y;
        rec_pos_angle = block_.getAngle();
    }


}

void MyApp::draw() {
    if (!game_over) {
        DrawBackground();

        DrawBlock(block_);
        DrawPrevBlocks();
    }



}

void MyApp::keyDown(KeyEvent event) {
    switch (event.getCode()) {


        case KeyEvent::KEY_q: {
            block_.move(-0.02f);
            break;
        }
        case KeyEvent::KEY_e: {
            block_.move(0.02f);
            break;
        }
        case KeyEvent::KEY_w: {
            block_.rotate();
            break;
        }
        case KeyEvent::KEY_r: {
            Reset();
            break;
        }
    }
}

void MyApp::DrawPrevBlocks() {
    cinder::gl::color(1,1,0);
    std::vector<b2Body*> b = block_.getBodies();
    if (b.size() < 1) {
        return;
    }
    for (int i = 0; i < b.size() - 1; i++) {
        float32 x = b[i]->GetPosition().x * 200;
        float32 y = b[i]->GetPosition().y * 200;
        for (b2Fixture* f = b[i]->GetFixtureList(); f; f = f->GetNext()){
            b2PolygonShape* s = reinterpret_cast<b2PolygonShape *>(f->GetShape());
            b2Body* temp = f->GetBody();
            int size = s->GetVertexCount();
            std::vector<float32> vx(size);
            std::vector<float32> vy(size);
            for (int i = 0; i < size; i++) {
                vx[i] = temp->GetWorldPoint(s->GetVertex(i)).x * 200;
                vy[i] = temp->GetWorldPoint(s->GetVertex(i)).y * 200;
            }

//        float32 vx1 = s->GetVertex(0).x * 200;
//        float32 vx2 = s->GetVertex(1).x * 200;
//        float32 vx3 = s->GetVertex(2).x * 200;
//        float32 vx4 = s->GetVertex(3).x * 200;
//        float32 vy1 = s->GetVertex(0).y * 200;
//        float32 vy2 = s->GetVertex(1).y * 200;
//        float32 vy3 = s->GetVertex(2).y * 200;
//        float32 vy4 = s->GetVertex(3).y * 200;
//        cout << vx1 << " " << vy1 << " " <<vx2 << " " <<vy2 << " " <<vx3 << " " <<vy3 << " " <<vx4 << " " <<vy4 << " " <<endl;


            ci::PolyLine2f pl;




//        pl.push_back(vec2( x+vx1 + r , 800 - y-vy1 + r));
//        pl.push_back(vec2( x+ vx2 + r, 800 - y - vy2 - r));
//        pl.push_back(vec2( x+ vx3 - r, 800 - y-vy3 - r));
//        pl.push_back(vec2( x + vx4 - r, 800 - y - vy4 + r));
            for (int i = 0; i < size; i++) {
                pl.push_back(vec2(vx[i], 800 - vy[i]));
            }
            gl::drawSolid(pl);

        }
    }
}

void MyApp::DrawBlock(Block block) const{
    b2Vec2 pos = block.getPosition();
    cinder::gl::color(1,1,0);
    float32 x = pos.x * 200;
    float32 y = pos.y * 200;
    float32 r = block.getAngle() + 1;
    float32 ny = 40;
    float32 nx1=0;
    float32 nx2=0;
    for (b2Fixture* f = block.getCurrentBody()->GetFixtureList(); f; f = f->GetNext()){
        b2PolygonShape* s = reinterpret_cast<b2PolygonShape *>(f->GetShape());
        b2Body* temp = f->GetBody();
        int size = s->GetVertexCount();
        std::vector<float32> vx(size);
        std::vector<float32> vy(size);
        for (int i = 0; i < size; i++) {
            vx[i] = temp->GetWorldPoint(s->GetVertex(i)).x * 200;
            vy[i] = temp->GetWorldPoint(s->GetVertex(i)).y * 200;
        }
//        float32 vx1 = temp->GetWorldPoint(s->GetVertex(0)).x * 200;
//        float32 vx2 = temp->GetWorldPoint(s->GetVertex(1)).x * 200;
//        float32 vx3 = temp->GetWorldPoint(s->GetVertex(2)).x * 200;
//        float32 vx4 = temp->GetWorldPoint(s->GetVertex(3)).x * 200;
//        float32 vy1 = temp->GetWorldPoint(s->GetVertex(0)).y * 200;
//        float32 vy2 = temp->GetWorldPoint(s->GetVertex(1)).y * 200;
//        float32 vy3 = temp->GetWorldPoint(s->GetVertex(2)).y * 200;
//        float32 vy4 = temp->GetWorldPoint(s->GetVertex(3)).y * 200;
//        if (vy1>ny){
//            if (vy2<ny){
//                nx1 = (vx1-vx2)*(vy1-ny)/(vy1-vy2)+vx2;
//                if (vy3>ny){
//                    nx2 = (vx3-vx2)*(vy3-ny)/(vy3-vy1)+vx2;;
//                }else{
//                    if (vy4>ny) {
//                        nx2 = (vx4 - vx3) * (vy4 -ny)/(vy4- vy3)+vx3;
//                    }else{
//                        nx2 = (vx1-vx4)*(vy1-ny)/(vy1-vy4)+vx4;
//                    }
//                }
//            }else{
//                if (vy3<ny){
//                    nx1 = (vx2-vx3)*(vy2-ny)/(vy2-vy3)+vx3;
//                    if (vy4>ny) {
//                        nx2 = (vx4 - vx3) * (vy4 -ny)/(vy4- vy3)+vx3;
//                    }else{
//                        nx2 = (vx4-vx1)*(vy4-ny)/(vy4-vy1)+vx1;
//                    }
//                }else{
//                    if (vy4<ny){
//                        nx1 = (vx3 - vx4) * (vy3 -ny)/(vy3- vy4)+vx4;
//                        nx2 = (vx1-vx4)*(vy1-ny)/(vy1-vy4)+vx4;
//                    }
//                }
//            }
//        }else{
//            if (vy2>ny){
//                nx1 = (vx2-vx1)*(vy2-ny)/(vy2-vy1)+vx1;
//                if (vy3<ny){
//                    nx2 =(vx2-vx3)*(vy2-ny)/(vy2-vy3)+vx3;
//                }else{
//                    if (vy4<ny) {
//                        nx2 = (vx3 - vx4) * (vy3 -ny)/(vy3- vy4)+vx4;
//                    }else{
//                        nx2 = (vx4-vx1)*(vy4-ny)/(vy4-vy1)+vx1;
//                    }
//                }
//            }else{
//                if (vy3>ny){
//                    nx1 = (vx3-vx2)*(vy3-ny)/(vy3-vy2)+vx2;
//                    if (vy4<ny) {
//                        nx2 = (vx3 - vx4) * (vy3 -ny)/(vy3- vy4)+vx4;
//                    }else{
//                        nx2 = (vx4-vx1)*(vy4-ny)/(vy4-vy1)+vx1;
//                    }
//                }else{
//                    if (vy4>ny){
//                        nx1 = (vx4 - vx3) * (vy4 -ny)/(vy4- vy3)+vx3;
//                        nx2 = (vx4-vx1)*(vy4-ny)/(vy4-vy1)+vx1;
//                    }
//                }
//            }
//        }

//        float32 vx1 = s->GetVertex(0).x * 200;
//        float32 vx2 = s->GetVertex(1).x * 200;
//        float32 vx3 = s->GetVertex(2).x * 200;
//        float32 vx4 = s->GetVertex(3).x * 200;
//        float32 vy1 = s->GetVertex(0).y * 200;
//        float32 vy2 = s->GetVertex(1).y * 200;
//        float32 vy3 = s->GetVertex(2).y * 200;
//        float32 vy4 = s->GetVertex(3).y * 200;
//        cout << vx1 << " " << vy1 << " " <<vx2 << " " <<vy2 << " " <<vx3 << " " <<vy3 << " " <<vx4 << " " <<vy4 << " " <<endl;


        ci::PolyLine2f pl;




//        pl.push_back(vec2( x+vx1 + r , 800 - y-vy1 + r));
//        pl.push_back(vec2( x+ vx2 + r, 800 - y - vy2 - r));
//        pl.push_back(vec2( x+ vx3 - r, 800 - y-vy3 - r));
//        pl.push_back(vec2( x + vx4 - r, 800 - y - vy4 + r));
        for (int i = 0; i < size; i++) {
            pl.push_back(vec2(vx[i], 800 - vy[i]));
        }
//        pl.push_back(vec2( vx1, 800 - vy1));
//        pl.push_back(vec2( vx2,  800 - vy2));
//        pl.push_back(vec2( vx3,  800 - vy3));
//        pl.push_back(vec2( vx4, 800 - vy4));
        gl::drawSolid(pl);

    }






//    gl::drawSolidRect( Rectf( x-20.0f,
//                              800 - y-10.0f,
//                              x+22.0f,
//                              800 - y+10.0f ) );
}

void MyApp::DrawBackground() const {
    cinder::gl::clear(Color(0, 0, 1));

    for (int i = 778; i > 0; i-=40) {
        cinder::gl::color(0,0,0);
        vec2 a;
        vec2 b;
        a.x = 0;
        a.y = i;
        b.x = 800;
        b.y = i;
        gl::drawLine(a, b);
    }
    cinder::gl::color(1,1,1);
    gl::drawSolidRect(Rectf(0, 780, 800, 800));
    gl::drawSolidRect(Rectf(0, 0, 20, 800));
    gl::drawSolidRect(Rectf(780, 0, 800, 800));
}
    template <typename C>
    void PrintText(const string& text, const C& color, const cinder::ivec2& size,
                   const cinder::vec2& loc) {
        cinder::gl::color(color);

        auto box = TextBox()
                .alignment(TextBox::CENTER)
                .font(cinder::Font(kNormalFont, 30))
                .size(size)
                .color(color)
                .backgroundColor(ColorA(0, 0, 0, 0))
                .text(text);

        const auto box_size = box.getSize();
        const cinder::vec2 locp = {loc.x - box_size.x / 2, loc.y - box_size.y / 2};
        const auto surface = box.render();
        const auto texture = cinder::gl::Texture::create(surface);
        cinder::gl::draw(texture, locp);
    }
    int MyApp::detect_erase() {
        struct{ GLubyte blue, yellow, white; } pixel;
        ivec2 size = getWindowSize();
        int counter = 0;
        for (int i = 21; i < 800; i+=40) {
            int countyellow = 0;
            for (int j = 11; j < 789; j++) {
                gl::readPixels(j, i, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &pixel);
                if (static_cast<int>(pixel.yellow) != 0) {
                    countyellow++;
                }
            }
            score += (countyellow - 18);

            if (counter == END_LINE) {
                if (countyellow == 18) {
                    score = 0;
                } else {
                    game_over = true;
                    cinder::gl::clear(Color(0, 0, 0));

                    GameOver(score);
                }
            }
            if (countyellow >600) {
                block_.deleteBody(counter);
            }
            cout << "row"<< counter << ":" <<countyellow << endl;
            counter++;
        }



        return 1;
    }

    void MyApp::Reset() {

        block_.reset();
        rec_pos_x = 0;
        rec_pos_y = 0;
        rec_pos_angle = 0;
        score = 0;
        game_over = false;
        setup();
}

    void MyApp::GameOver(int score) {
        const cinder::vec2 center = getWindowCenter();
        const cinder::ivec2 size = {500, 50};
        const Color color = Color::white();

        size_t row = 0;
        PrintText("Game Over :(", color, size, center);
        std::stringstream ss;
        ss << "your score is: " << score;
        PrintText(ss.str(), color, size, {center.x, center.y + (++row) * 50});

    }


}  // namespace myapp

