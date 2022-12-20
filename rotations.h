#include "cube.h"
#include "helper.h"
#include "edge_sticker_map.h"
#pragma once


void Cube::rotate_face_clockwise(char move) {
    int i = center_coor[move][0];
    int j = center_coor[move][1];
    // edges swap
    char temp_edge = grid[i-1][j];
    swap(&grid[i-1][j], &grid[i][j-1]);
    swap(&grid[i][j-1], &grid[i+1][j]);
    swap(&grid[i+1][j], &grid[i][j+1]);
    swap(&grid[i][j+1], &temp_edge);
    // corners swap
    char temp_corner = grid[i-1][j-1];
    swap(&grid[i-1][j-1], &grid[i+1][j-1]);
    swap(&grid[i+1][j-1], &grid[i+1][j+1]);
    swap(&grid[i+1][j+1], &grid[i-1][j+1]);
    swap(&grid[i-1][j+1], &temp_corner);

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