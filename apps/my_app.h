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
        void Reset();
        void DrawBackground() const;
        void DrawBlock(Block block) const;
        void DrawPrevBlocks();
        int detect_erase();
        void GameOver(int score);
        ivec2 windows_size;
        Block block_;
        float32 rec_pos_x = 0;
        float32 rec_pos_y = 0;
        float32 rec_pos_angle = 0;
        int score = 0;
        bool game_over = false;
    };

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
