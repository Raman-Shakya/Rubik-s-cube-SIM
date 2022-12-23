#pragma once

#include "../cube.h"
#include "../edge_sticker_map.h"

bool is_G2_solved(Cube *cube) {
    int Orange_C_coor_x = center_coor['L'][0],
        Orange_C_coor_y = center_coor['L'][1],
        Red_C_coor_x    = center_coor['R'][0],
        Red_C_coor_y    = center_coor['R'][1];

    for (int i=-1; i<2; i++) {
        for (int j=0; j<2; j++) {
            if (cube->grid[Orange_C_coor_x-i][Orange_C_coor_y-j] != 'O' && cube->grid[Orange_C_coor_x-i][Orange_C_coor_y-j] != 'R') return false;
            if (cube->grid[Red_C_coor_x-i][Red_C_coor_y-j] != 'O' && cube->grid[Red_C_coor_x-i][Red_C_coor_y-j] != 'R') return false;
        }
    }
    return true;
}


std::string solve_G2(Cube *cube, int depth) {
    if (depth==0) return "";
    if (is_G2_solved(cube)) return " ";
    
    for (std::string move: {"L","R","F","B","U2","D2"}) {
        Cube temp(*cube);
        temp.move(move);
        std::string temp_soln = solve_G2(&temp, depth-1);
        if (temp_soln.length()!=0) return move+" "+temp_soln;
    }

    return "";
}