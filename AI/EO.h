#pragma once

#include "../cube.h"
#include "../edge_sticker_map.h"



int EO_no_WYGB_spots[] ={
    3,1, 3,4, 3,7, 3,10,
    5,1, 5,4, 5,7, 5,10,
    4,6, 4,8, 4,0, 4,2,
};

bool is_EO_solved(Cube *cube) {
    int a,b;
    
    for (int i=0; i<24; i+=2) {
        a = EO_no_WYGB_spots[i];
        b = EO_no_WYGB_spots[i+1];
        char temp_color = cube->grid[a][b];
        if (temp_color=='Y' || temp_color=='W') return false;
        if (temp_color=='B' || temp_color=='G') {
            char temp_color_2 = cube->grid[connected_coor_edge[{a,b}][0]][connected_coor_edge[{a,b}][1]];
            if (temp_color_2=='O' || temp_color_2=='R') return false;
        }
    }
    return true;
}



std::string solve_EO(Cube *cube, int depth) {
    if (is_EO_solved(cube)) return " ";
    if (depth==0) return "";
    
    for (std::string move: {"L","R","F","B","U","D"}) {
        Cube temp(*cube);
        temp.move(move);
        std::string temp_soln = solve_EO(&temp, depth-1);
        if (temp_soln.length()!=0) return move+" "+temp_soln;
    }

    return "";

}