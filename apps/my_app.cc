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

MyApp::MyApp() {

}
void MyApp::setup() {


    windows_size = cinder::app::getWindowSize();
    block_.setup();

}

void MyApp::update() {
    float timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;
    block_.step(timeStep, velocityIterations, positionIterations);
}

void MyApp::draw() {

    DrawBackground();
    DrawBlock(block_.getPosition());



}

void MyApp::keyDown(KeyEvent event) {
    switch (event.getCode()) {
        case KeyEvent::KEY_o: {

        }
    }
}

void MyApp::DrawBlock(b2Vec2 pos) const{
    cinder::gl::color(1,1,0);
    float32 x = pos.x * 200;
    float32 y = pos.y * 200;
    gl::drawSolidRect( Rectf( x-20.0f,
                              800 - y-20.0f,
                              x+20.0f,
                              800 - y+20.0f ) );
}

void MyApp::DrawBackground() const {
    cinder::gl::clear(Color(0, 0, 1));
}




}  // namespace myapp

