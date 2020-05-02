# Final Project

[![license](https://img.shields.io/badge/license-MIT-green)](LICENSE)
[![docs](https://img.shields.io/badge/docs-yes-brightgreen)](docs/README.md)

# Tetris

Author: Yunze Liao

---

### Summary
A Tetris game with physics engine, the blocks will not always fall into the grid.
It should be looking like this:
![example](https://github.com/CS126SP20/project-proposal-ryanliaoyz/blob/master/Screenshot%20from%202020-04-15%2004-49-27.png)

The blocks will only be erased if the contents on a horizontal line reached a desired amount(since it's unlikely to be fully filled)

The blocks will be falling from top to bottom as most Tetris game do. However, the rotation of it is not 90 degrees, instead, it will be controlled rotating slightly with a key(or rapidly by holding the key).
### Features
 - increasing difficulty as game continues.
 - leaderboard
 - background music & erasing sound effect
 - randomlize block pattern
 
### Libraries & Cinder Blocks
 - Box2D(https://github.com/erincatto/box2d)
   - A 2D physics engine to simulated colliding effect for blocks.
 - suBox2D(https://github.com/sansumbrella/suBox2D)
   - simple wrapper around Box2D physics for use with the Cinder framework.
 - Cinder-ImGui(https://github.com/simongeilfus/Cinder-ImGui)
   - provide the UI component for the project.
 - gflags(https://github.com/gflags/gflags)
   - handling the arguments.
  
### Background
Some basic physics knowledge could help on developing the collision and erasing effects.


**Author**: Yunze Liao - [`yunze2@illinois.edu`](mailto:yunze2@illinois.edu)
