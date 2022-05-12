/**************************************************************
 *
 * userprog/ksyscallhelper.h
 *
 * Helper function for ksyscall.h
 *
 * by Thuc Le.
 *
 **************************************************************/

#ifndef __USERPROG_KSYSCALLHELPER_H__
#define __USERPROG_KSYSCALLHELPER_H__

#include "kernel.h"
#include "synchconsole.h"

#define LF ((char)10)
#define CR ((char)13)
#define TAB ((char)9)
#define SPACE ((char)' ')

/* maximum length of an interger (included the minus sign) */
#define MAX_NUM_LENGTH 20
/* A buffer to read and write number */
char _numberBuffer[MAX_NUM_LENGTH + 2];

char isBlank(char c) { return c == LF || c == CR || c == TAB || c == SPACE; }

/**
 * Read and store characters in the _numberBuffer until blank or end of file
 *
 * It will read at most MAX_NUM_LENGTH + 1 character
 **/
void readUntilBlank() {
    memset(_numberBuffer, 0, sizeof(_numberBuffer));
    char character = kernel->synchConsoleIn->GetChar();

    if (character == EOF || isBlank(character)) return;

    int count = 0;

    while (!(isBlank(character) || character == EOF)) {
        _numberBuffer[count++] = character;
        if (count > MAX_NUM_LENGTH) return;
        character = kernel->synchConsoleIn->GetChar();
    }
}

/**
 * Return true of the interger equals to the
 * interger stored in the string
 **/
bool compareNumAndString(int integer, const char *s) {
    if (integer == 0) return strcmp(s, "0") == 0;

    int len = strlen(s);

    if (integer < 0 && s[0] != '-') return false;

    if (integer < 0) s++, --len, integer = -integer;

    while (integer > 0) {
        int digit = integer % 10;

        if (s[len - 1] - '0' != digit) return false;

        --len;
        integer /= 10;
    }

    return len == 0;
}

#endif /* ! __USERPROG_KSYSCALLHELPER_H__ */
