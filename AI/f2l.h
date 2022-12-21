#pragma once

#include <vector>
#include <string>
#include "../cube.h"

bool is_f2l_pair_1_solved(Cube *cube) {
    if (
        cube->coor_is_solved(2, 5) &&
        cube->coor_is_solved(3,5)
        // cube->coor_is_solved(4,5) &&
        // cube->coor_is_solved()
    )return true;
    return false;
}


std::string solve_pair_1(Cube *cube, int depth, std::vector<std::string> moves={""}) {
    if (depth==0) return "";
    if (is_f2l_pair_1_solved(cube)) return " ";

    for (std::string move: {"R ","D ","R'","D'",}) {
        if (move == moves.back()) continue;
        Cube temp(*cube);
        temp.move(move);
        if (move[0]=='R')
            moves.push_back(move);
        std::string temp_soln = solve_pair_1(&temp, depth-1, moves);
        if (move[0]=='R')
            moves.pop_back();
        if (temp_soln.length()!=0) return move+" "+temp_soln;
    }
    return "";
}