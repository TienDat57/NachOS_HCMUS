#include "syscall.h"

int main() {
    char fileName[256];
    PrintString("Enter file's name: ");
    ReadString(fileName, 8);  // input file k.txt
    if (CreateFile(fileName) == 0) {
        PrintString("Created successfully file: ");
        PrintString(fileName);
    } else
        PrintString("Error create file");
    return 0;
}