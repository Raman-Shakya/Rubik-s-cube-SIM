#pragma once

#include "../cube.h"

bool is_oll_solved(Cube *cube) {
    if (
        cube->coor_is_solved(6,3) &&
        cube->coor_is_solved(6,5) &&
        cube->coor_is_solved(8,3) &&
        cube->coor_is_solved(8,5)
    ) return true;
    return false;
}


std::string solve_OLL(Cube *cube, int depth) {
    if (is_oll_solved(cube)) return " ";
    if (depth==0) return "";
    
    std::string sune = "R' D' R D' R' D2 R";
    for (std::string move: {"","D ","D'","D2"}) {
        Cube temp(*cube);
        if (move!="") temp.move(move);
        temp.scramble(sune);
        std::string temp_soln = solve_OLL(&temp, depth-1);
        if (temp_soln.length()!=0) return move+" "+sune+" "+temp_soln;
    }

    return "";

}