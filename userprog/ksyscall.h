/**************************************************************
 *
 * userprog/ksyscall.h
 *
 * Kernel interface for systemcalls
 *
 * by Marcus Voelp  (c) Universitaet Karlsruhe
 *
 **************************************************************/

#ifndef __USERPROG_KSYSCALL_H__
#define __USERPROG_KSYSCALL_H__

#include "kernel.h"
#include "synchconsole.h"
#include "ksyscallTemp.h"
#include <stdlib.h>
#include <stdint.h>
#include <limits>

void SysHalt() { kernel->interrupt->Halt(); }

int SysAdd(int op1, int op2) { return op1 + op2; }

int SysReadNum() {
    readUntilBlank();

    int len = strlen(_numberBuffer);
    // Read nothing -> return 0
    if (len == 0) return 0;

    // Check comment below to understand this line of code
    if (strcmp(_numberBuffer, "-2147483648") == 0) return INT32_MIN;

    bool nega = (_numberBuffer[0] == '-');
    int zeros = 0;
    bool isLead = true;
    int num = 0;
    for (int i = nega; i < len; ++i) {
        char c = _numberBuffer[i];
        if (c == '0' && isLead)
            ++zeros;
        else
            isLead = false;
        if (c < '0' || c > '9') return 0;
        num = num * 10 + (c - '0');
    }

    // 00            01 or -0
    if (zeros > 1 || (zeros && (num || nega))) {
        DEBUG(dbgSys, "Expected number but " << _numberBuffer << " found");
        return 0;
    }

    if (nega) num = -num;

    // It's safe to return directly if the number is small
    if (len <= MAX_NUM_LENGTH - 2) return num;

    if (compareNumAndString(num, _numberBuffer))
        return num;
    else
        DEBUG(dbgSys,
              "Expected int32 number but " << _numberBuffer << " found");

    return 0;
}

void SysPrintNum(int number) {
    if (number == 0) return kernel->synchConsoleOut->PutChar('0');

    if (number == INT32_MIN) {
        kernel->synchConsoleOut->PutChar('-');
        for (int i = 0; i < 10; ++i)
            kernel->synchConsoleOut->PutChar("2147483648"[i]);
        return;
    }

    if (number < 0) {
        kernel->synchConsoleOut->PutChar('-');
        number = -number;
    }
    int count = 0;
    while (number) {
        _numberBuffer[count++] = number % 10;
        number /= 10;
    }
    for (int i = count - 1; i >= 0; --i)
        kernel->synchConsoleOut->PutChar(_numberBuffer[i] + '0');
}

char SysReadChar() { return kernel->synchConsoleIn->GetChar(); }

void SysPrintChar(char character) {
    kernel->synchConsoleOut->PutChar(character);
}

int SysRandomNum() { return random(); }

char* SysReadString(int length) {
    char* buffer = new char[length + 1];
    for (int i = 0; i < length; i++) buffer[i] = SysReadChar();
    buffer[length] = '\0';
    return buffer;
}

void SysPrintString(char* buffer, int length) {
    for (int i = 0; i < length; i++)
        kernel->synchConsoleOut->PutChar(buffer[i]);
}

bool SysCreateFile(char* fileName) {
    int fileNameLength = strlen(fileName);

    if (fileNameLength == 0) {
        DEBUG(dbgSys, "File name emtry\n");
        return false;
    } else if (fileName == NULL) {
        DEBUG(dbgSys, "Not memory allocated\n");
        return false;

    } else {
        DEBUG(dbgSys, "Read successfully\n");
        if (!kernel->fileSystem->Create(fileName)){
            DEBUG(dbgSys, "Error creating file\n");
            return false;
        }
        else return true;
    }
    return false;
}

int SysOpen(char* fileName, int type) {
    if (type != 0 && type != 1) return -1;

    int id = kernel->fileSystem->Open(fileName, type);
    if (id == -1) return -1;
    DEBUG(dbgSys, "\nOpened file");
    return id;
}

int SysClose(int id) { return kernel->fileSystem->Close(id); }

int SysRead(char* buffer, int charCount, int fileId) {
    if (fileId == 0) {
        return kernel->synchConsoleIn->GetString(buffer, charCount);
    }
    return kernel->fileSystem->Read(buffer, charCount, fileId);
}

int SysWrite(char* buffer, int charCount, int fileId) {
    if (fileId == 1) {
        return kernel->synchConsoleOut->PutString(buffer, charCount);
    }
    return kernel->fileSystem->Write(buffer, charCount, fileId);
}

int SysRemove(char* fileName) { return kernel->fileSystem->Remove(fileName); }

int SysSeek(int seekPos, int fileId) {
    if (fileId <= 1) {
        DEBUG(dbgSys, "\nCan't seek in console");
        return -1;
    }
    return kernel->fileSystem->Seek(seekPos, fileId);
}

#endif /* ! __USERPROG_KSYSCALL_H__ */
