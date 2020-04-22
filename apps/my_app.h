// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <Box2D/Box2D.h>
#include <vector>
#include "cinder/gl/gl.h"
#include "Block.h"

using namespace ci;
using namespace ci::app;
using namespace std;

namespace myapp {

    class MyApp : public cinder::app::App {
    public:
        MyApp();
        void setup() override ;
        void keyDown(KeyEvent event) override ;
        void update() override ;
        void draw() override ;

    private:
        void DrawBackground() const;
        void DrawBlock(b2Vec2 pos) const;
        ivec2 windows_size;
        Block block_;
    };

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
