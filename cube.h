#pragma once

#include <iostream>
#include "helper.h"


class Cube {
public:
    char grid[9][13];

    Cube () {
        reset_to_solved_state();
    }

    Cube(const Cube& other) {
        for (int i=0; i<9; i++) {
            for (int j=0; j<12; j++) {
                grid[i][j] = other.grid[i][j];
            }
        }
    } 

    void print_cube() {
        // for (int i=0; i<12; i++) {
        //     std::cout << i << " " << ((i+1)%3==0?" ":"");
        // }
        std::cout << std::endl;
        for (int i=0; i<9; i++) {
            for (int j=0; j<12; j++) {
                // std::cout << grid[i][j] << " ";
                std::cout << color_palette[grid[i][j]] << color_palette[grid[i][j]];
                if ((j+1)%3==0) std::cout << " ";
            }
            // std::cout << " --- " << i;
            std::cout << "\n";
            if ((i+1)%3==0) std::cout << "\n";
            // std::cout << "\n";
        }
        std::cout << "\n";
    }

    void rotate(char move) {
        rotate_face_clockwise(move);
        rotate_edges(move);
    }

    void rotate_face_clockwise(char);
    void rotate_edges(char);
    void move(std::string);
    void scramble(std::string);



    bool is_solved() {
        for (int i=0; i<9; i++) {
            for (int j=0; j<12; j++) {
                if(grid[i][j]!=solved_grid[i][j]) return false;
            }
        }
        return true;
    }

    bool coor_is_solved(int, int);

    void reset_to_solved_state() {
        for (int i=0; i<9; i++) {
            for (int j=0; j<12; j++) {
                grid[i][j] = solved_grid[i][j];
            }
        }
    }
private:
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


    

};