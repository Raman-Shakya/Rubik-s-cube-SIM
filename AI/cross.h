#pragma once

#include "../cube.h"
#include <string>

bool is_WY(char a) {
    return a=='W' || a=='Y';
}



bool is_daisy_solved(Cube *cube) {
    if (
        cube->grid[6][4]=='W' &&
        cube->grid[7][5]=='W' &&
        cube->grid[7][3]=='W' &&
        cube->grid[8][4]=='W'
    )  return true;
    return false;
}

bool is_Cross_solved(Cube *cube) {
    if (
        cube->coor_is_solved(0,4) &&
        cube->coor_is_solved(1,5) &&
        cube->coor_is_solved(2,4) &&
        cube->coor_is_solved(1,3) &&

        cube->coor_is_solved(3,1) &&
        cube->coor_is_solved(3,4) &&
        cube->coor_is_solved(3,7) &&
        cube->coor_is_solved(3,10)
    )  return true;
    return false;
}

std::string solve_Daisy(Cube *cube, int depth) {
    if (is_daisy_solved(cube)) return " ";
    if (depth==0) return "";

    for (std::string move: {"R ","L ","U ","D ","R'","L'","U'","D'",}) {
        Cube temp(*cube);
        temp.move(move);
        std::string temp_soln = solve_Daisy(&temp, depth-1);
        if (temp_soln.length()!=0) return move+" "+temp_soln;
    }

    return "";
}

std::string solve_Cross(Cube *cube, int depth) {
    if (is_Cross_solved(cube)) return " ";
    if (depth==0) return "";

    Cube temp2(*cube);
    temp2.move("R2");
    temp2.move("D");
    for (std::string move: {"U ","U'","U2"}) {
        Cube temp(temp2);
        temp.move(move);
        std::string temp_soln = solve_Cross(&temp, depth-1);
        if (temp_soln.length()!=0) return "R2 D "+move+" "+temp_soln;
    }

    return "";

}