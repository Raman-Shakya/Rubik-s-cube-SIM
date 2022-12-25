#pragma once

#include "../cube.h"


bool is_belt_solved(Cube *cube) {
    if (cube->coor_is_solved(4,5) &&
        cube->coor_is_solved(4,6) &&
        cube->coor_is_solved(4,8) &&
        cube->coor_is_solved(4,9) &&
        cube->coor_is_solved(4,11) &&
        cube->coor_is_solved(4,0) &&
        cube->coor_is_solved(4,2) &&
        cube->coor_is_solved(4,3)
    )   return true;
    return false;
}

std::string solve_Belt(Cube *cube, int depth, std::string prev="") {
    if (is_belt_solved(cube)) return " ";
    if (depth==0) return "";

    for (std::string move: {"R ","R'","L ","L'"}) {
        Cube temp(*cube);
        temp.move(move);
        std::string rev_move = move;
        rev_move[1]=move[1]=='\''?' ':'\'';
        for (std::string move2: {"D ","D'","D2"}) {
            Cube temp2(temp);
            temp2.move(move2);
            temp2.move(rev_move);
            std::string temp_soln = solve_Belt(&temp2, depth-1);
            if (temp_soln.length()>0) return move+" "+move2+" "+rev_move+" "+temp_soln;
        }

    }

    return "";
}
