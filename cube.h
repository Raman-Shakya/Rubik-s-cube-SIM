#pragma once

#include <iostream>
#include "helper.h"

// representation of solved grid/ cube state
char solved_grid[9][13] = {
    "   WWW      ",
    "   WWW      ",
    "   WWW      ",
    "OOOGGGRRRBBB",
    "OOOGGGRRRBBB",
    "OOOGGGRRRBBB",
    "   YYY      ",
    "   YYY      ",
    "   YYY      ",
};

// this class handles everything happening to the cube (state, turning, printing)
class Cube {
public:
    char grid[9][13];   // this variable will store cube state

    // instantiating cube state
    Cube () {
        reset_to_solved_state(); // setting the cube state to solved
    }

    // copy cube state from other cube if it is referenced in the initializer
    Cube(const Cube& other) {
        for (int i=0; i<9; i++) {
            for (int j=0; j<12; j++) {
                grid[i][j] = other.grid[i][j];
            }
        }
    } 

    // prints the cube state in the net view
    void print_cube() {
        std::cout << "\n"; // padding-top: 1em;

        for (int i=0; i<9; i++) {
            for (int j=0; j<12; j++) {
                if (grid[i][j]!=' ')
                    // changing color and printing full ascii character (i.e. █ (ascii 219))
                    // printing 2 of them because 1 character height = 2 character width, so it makes a square
                    std::cout << color_palette[grid[i][j]] << print_char << print_char << "\033[0m";
                else
                    // leave space as it is, useless memory consumer :|
                    std::cout << "  ";
                if ((j+1)%3==0) std::cout << " "; // adding space for (border)
            }
            std::cout << "\n";  // next line
            if ((i+1)%3==0) std::cout << "\n";  // padding between white, green and yellow faces
        }
        std::cout << "\n";  // padding-bottom: 1em;
    }

    void rotate(char move) {
        // rotates the pieces in the face clockwise
        rotate_face_clockwise(move);
        // rotates the rest of pieces affected by the face
        rotate_edges(move);
    }

    // rotation helpers defined in (rotation.h)
    void rotate_face_clockwise(char);
    void rotate_edges(char);

    // movers and scramblers, defined in (rotation.h)
    void move(std::string);
    void scramble(std::string);


    // returns if the cube is solved
    bool is_solved() {
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {   // checking upto level 9 for optimization (if you solve 5 sides 6th side is complete)
                if(grid[i][j]!=solved_grid[i][j]) return false;    // if 1 sticker isn't solve, cube isn't solved
            }
        }
        return true;
    }

    bool coor_is_solved(int, int);

    // resets to solved state (copies from solved_grid)
    void reset_to_solved_state() {
        for (int i=0; i<9; i++) {
            for (int j=0; j<12; j++) {
                grid[i][j] = solved_grid[i][j];
            }
        }
    }
// private:
//     char *solved_grid[9][13] = &&solved_grid;

};

