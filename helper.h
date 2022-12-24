#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>


std::map<char, std::string> color_palette;


void set_color_palette() {
    color_palette['R'] = "\033[1;31m█\033[0m";
    color_palette['G'] = "\033[1;32m█\033[0m";
    color_palette['Y'] = "\033[1;33m█\033[0m";
    color_palette['B'] = "\033[1;34m█\033[0m";
    color_palette['W'] = "\033[1;37m█\033[0m";
    color_palette['O'] = "\033[1;38;5;208m█\033[0m";
    color_palette[' '] = " ";
}



void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}


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




int quarter_turns_count(char a) {
    switch (a) {
        case '\'': return -1; break;
        case '2': return 2; break;
        default: return 1; break;
    }
}

std::string combine(std::string a, std::string b) {
    std::string ans = a;
    int count = (quarter_turns_count(a[1]) + quarter_turns_count(b[1]))%4;
    count = count>0 ? count : -count;
    if (count==0) return "";
    if (count==1) ans[1] = ' ';
    if (count==2) ans[1] = '2';
    if (count==3) ans[1] = '\'';

    return ans;
}

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


int random_number(int upper) {
    return rand() % upper;
}

std::string generate_scramble(int moves) {
    std::string answer = "";
    for (int i=0; i<moves; i++) {
        answer += "RUDLFB"[random_number(6)];
        answer += "'2"[random_number(3)];
        answer += " ";
    }
    return cleanify(answer);
}