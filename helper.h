#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>


std::map<char, std::string> color_palette;      // map_obj for changing color
char print_char = 219;      // full block ascii character code 

void set_color_palette() {
    color_palette['R'] = "\033[1;31m";
    color_palette['G'] = "\033[1;32m";
    color_palette['Y'] = "\033[1;33m";
    color_palette['B'] = "\033[1;34m";
    color_palette['W'] = "\033[1;37m";
    color_palette['O'] = "\033[1;38;5;208m";
    color_palette[' '] = "";
}


// simple swap function
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// returns total moves in the solution (solved for recurring spaces)
int count_moves(std::string solution) {
    bool space_before=false;
    int answer = 0;
    for (char i: solution) {
        if (i==' ') {
            if (space_before) continue;
            answer += 1;
            space_before = true;
        }
        else space_before = false;
    }
    return answer;
}



// 1 clockwise rotation = 1 unit
int quarter_turns_count(char a) {
    switch (a) {
        case '\'': return -1; break;
        case '2': return 2; break;
        default: return 1; break;
    }
}

// combines 2 move if they are performed on same face
std::string combine(std::string a, std::string b) {
    if (a[0]!=b[0]) return "";

    std::string ans = a;
    int count = (quarter_turns_count(a[1]) + quarter_turns_count(b[1]))%4;  // using math :sunglasses:
    count = count>0 ? count : -count;   // count = abs(count)

    // 1 unit = 1 clockwise turn
    if (count==0) return "";
    if (count==1) ans[1] = ' ';
    if (count==2) ans[1] = '2';
    if (count==3) ans[1] = '\'';

    return ans;
}

/*
    this function does the following:
        -> removes all recurring spaces
        -> if same face moves are repeating, it merges them to one
        -> uses recursion to solve for multiple repeated moves

    # I have no idea how I got this working so sorry for no comments :')
*/
std::string cleanify(std::string solution) {
    int count = 0;
    std::string answer   = "",
                previous = "  ",
                temp     = "  ";
    bool reading_first = true,
         space_last    = false;

    for (char i: solution+" Q ") {
        if (i==' ') {
            if (space_last) continue;
            if (previous[0]!=temp[0]) {
                if(previous[0]!=' ') {
                    answer += previous;
                    if (previous[1]!=' ') answer+=' ';
                }
                previous = temp;
            }
            else {
                count += 1;
                answer += combine(previous, temp) + " ";
                previous = "  ";

            }
            space_last = true;
            reading_first = true;
        }
        else {
            space_last = false;
            if (reading_first) {
                temp[0] = i;
                temp[1] = ' ';
                reading_first = false;
            }
            else {
                temp[1] = i;
            }
        }
    }
    if (count==0)
        return answer;
    return cleanify(answer);
}


// returns random number from [0, upper)
int random_number(int upper) {
    return rand() % upper;
}

// generate random scramble with argument for maximum move
std::string generate_scramble(int max_moves) {
    std::string answer = "";
    for (int i=0; i<max_moves; i++) {
        answer += "RUDLFB"[random_number(6)];
        answer += "'2"[random_number(3)];
        answer += " ";
    }
    return cleanify(answer);
}