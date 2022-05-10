#include "syscall.h"

#define MODE_READWRITE 0
#define MODE_READ 1

#define stdin 0
#define stdout 1

int main() {
    char fileName[256];
    char buffer[100];
    int fileID, read;

    PrintString("Input file name: ");
    ReadString(fileName, 9);
    PrintString(fileName);

    fileID = Open(fileName, MODE_READ);
    read = Read(buffer, 100, fileID);
    PrintString(buffer);
    PrintString("\n");
    Close(fileID);
    
    return 0;
}