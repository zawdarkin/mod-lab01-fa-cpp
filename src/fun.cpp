// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>
#include <cstring>

unsigned int faStr1(const char* str) {
    unsigned int word_count = 0;
    bool word = false;
    bool accepted = true;

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            if (word && accepted) {
                word_count++;
            }
            word = false;
            accepted = true;
        } else {
            if (!word) {
                word = true;
            }
            if (isdigit(str[i])) {
                accepted = false;
            }
        }
    }
    if (word && accepted) {
        word_count++;
    }
    return word_count;
}

unsigned int faStr2(const char* str) {
    unsigned int word_count = 0;
    bool word = false;
    bool accepted = true;

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            if (word && accepted) {
                word_count++;
            }
            word = false;
            accepted = true;
        } else {
            if (!word) {
                if (str[i] >= 'A' && str[i] <= 'Z') {
                    accepted = true;
                } else {
                    accepted = false;
                }
                word = true;
            } else {
                if (str[i] < 'a' || str[i] > 'z') {
                    accepted = false;
                }
            }
        }
    }
    if (word && accepted) {
        word_count++;
    }
    return word_count;
}

unsigned int faStr3(const char* str) {
    unsigned int word_count = 0;
    unsigned int length = 0;
    bool word = false;
    unsigned int curr_length = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            if (word) {
                length += curr_length;
                word_count++;
                curr_length = 0;
            }
            word = false;
        } else {
            word = true;
            curr_length++;
        }
    }
    if (word) {
        length += curr_length;
        word_count++;
    }
    double avg = static_cast<double>(length) / word_count;

    return static_cast<unsigned int>(avg + 0.5);
}
