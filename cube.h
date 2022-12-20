#include <iostream>
#include "helper.h"
#pragma once


class Cube {
public:
    char grid[9][13];

    Cube () {
        reset_to_solved_state();
    }

    void print_cube() {
        for (int i=0; i<9; i++) {
            for (int j=0; j<12; j++) {
                std::cout << color_palette[grid[i][j]] << " ";
                if ((j+1)%3==0) std::cout << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    void rotate(char move) {
        rotate_face_clockwise(move);
        rotate_edges(move);
    }

    void rotate_face_clockwise(char);
    void rotate_edges(char);







private:
    void reset_to_solved_state() {
        char temp_grid_solved[9][13] = {
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
        for (int i=0; i<9; i++) {
            for (int j=0; j<12; j++) {
                grid[i][j] = temp_grid_solved[i][j];
            }
        }
    }

    

};






void scramble(Cube *cube, std::string scram) {
    char temp[2];
    scram += " ";
    int write_i = 0;
    for (char i: scram) {
        if(i==' ') {
            if (temp[1]=='\'') {
                cube->rotate(temp[0]);
                cube->rotate(temp[0]);
                cube->rotate(temp[0]);
            }
            else if (temp[1]=='2') {
                cube->rotate(temp[0]);
                cube->rotate(temp[0]);
            }
            else {
                cube->rotate(temp[0]);
            }
            temp[1] = '\0';
            write_i = 0;
            continue;
        }
        temp[write_i] = i;
        write_i++;
    }
}