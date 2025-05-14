// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>
#include <cstring>

namespace {

bool hasDigits(const char* s) {
    while (*s) {
        if (isdigit(*s++)) return true;
    }
    return false;
}

bool isValidWord2(const char* s) {
    if (!isupper(*s)) return false;
    while (*++s) {
        if (!islower(*s)) return false;
    }
    return true;
}

}  // namespace

unsigned int faStr1(const char* s) {
    unsigned cnt = 0;
    while (*s) {
        while (*s == ' ') s++;
        if (!*s) break;
        
        const char* start = s;
        while (*s && *s != ' ') s++;
        
        char word[256];
        strncpy(word, start, s - start);
        word[s - start] = '\0';
        
        if (!hasDigits(word)) cnt++;
    }
    return cnt;
}

unsigned int faStr2(const char* s) {
    unsigned cnt = 0;
    while (*s) {
        while (*s == ' ') s++;
        if (!*s) break;
        
        const char* start = s;
        while (*s && *s != ' ') s++;
        
        char word[256];
        strncpy(word, start, s - start);
        word[s - start] = '\0';
        
        if (isValidWord2(word)) cnt++;
    }
    return cnt;
}

unsigned int faStr3(const char* s) {
    unsigned total_len = 0, word_cnt = 0;
    while (*s) {
        while (*s == ' ') s++;
        if (!*s) break;
        
        const char* start = s;
        while (*s && *s != ' ') s++;
        
        total_len += s - start;
        word_cnt++;
    }
    return word_cnt ? (total_len + word_cnt/2) / word_cnt : 0;
}
