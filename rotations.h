#pragma once

#include <string>
#include "cube.h"
#include "helper.h"
#include "edge_sticker_map.h"


void Cube::rotate_face_clockwise(char move) {
    int i = center_coor[move][0];
    int j = center_coor[move][1];
    // edges swap
    char temp_edge = grid[i-1][j];
    grid[i-1][j]   = grid[i][j-1];
    grid[i][j-1]   = grid[i+1][j];
    grid[i+1][j]   = grid[i][j+1];
    grid[i][j+1]   = temp_edge;
    // corners swap
    char temp_corner = grid[i-1][j-1];
    grid[i-1][j-1] = grid[i+1][j-1];
    grid[i+1][j-1] = grid[i+1][j+1];
    grid[i+1][j+1] = grid[i-1][j+1];
    grid[i-1][j+1] = temp_corner;
}


void Cube::rotate_edges(char move) {
    for (int i=0; i<6; i+=2) {
        char temp_piece = grid[rotation_edge_map[move][0][i]][rotation_edge_map[move][0][i+1]];
        grid[rotation_edge_map[move][0][i]][rotation_edge_map[move][0][i+1]] = grid[rotation_edge_map[move][3][i]][rotation_edge_map[move][3][i+1]];
        grid[rotation_edge_map[move][3][i]][rotation_edge_map[move][3][i+1]] = grid[rotation_edge_map[move][2][i]][rotation_edge_map[move][2][i+1]];
        grid[rotation_edge_map[move][2][i]][rotation_edge_map[move][2][i+1]] = grid[rotation_edge_map[move][1][i]][rotation_edge_map[move][1][i+1]];
        grid[rotation_edge_map[move][1][i]][rotation_edge_map[move][1][i+1]] = temp_piece;
    }
}

void Cube::move(std::string move) {
    if (move[0]==' ') return;
    if (move[1]=='\'') {
        rotate(move[0]);
        rotate(move[0]);
        rotate(move[0]);
    }
    else if (move[1]=='2') {
        rotate(move[0]);
        rotate(move[0]);
    }
    else {
        rotate(move[0]);
    }
}



void Cube::scramble(std::string scram) {
    char temp[2];
    scram += " ";
    int write_i = 0;
    for (char i: scram) {
        if(i==' ') {
            if(temp[0]==' ') continue;
            move(temp);
            temp[0] = ' ';
            temp[1] = '\0';
            write_i = 0;
            continue;
        }
        temp[write_i] = i;
        write_i++;
    }
}


bool Cube::coor_is_solved(int i, int j) {
    return grid[i][j]==solved_grid[i][j];
}