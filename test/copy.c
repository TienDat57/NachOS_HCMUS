#include "syscall.h"

#define MODE_READWRITE 0
#define MODE_READ 1

#define stdin 0
#define stdout 1

int main() {
    char fileNameIn[256];
    char fileNameOut[256];
    int fileIDIn, fileIDOut, fileIDOut_;
    int read, write, lenBuffer;
    char buffer[100];

    PrintString("Input file name in: ");
    ReadString(fileNameIn, 9);  // input file datdu.txt

    fileIDIn = Open(fileNameIn, MODE_READ);
    read = Read(buffer, 100, fileIDIn);
    lenBuffer = 0;
    while (buffer[lenBuffer] != '\0') lenBuffer++;
    Close(fileIDIn);

    PrintString("Input file name out: ");
    ReadString(fileNameOut, 8);  // test file oke.txt

    fileIDOut = Open(fileNameOut, MODE_READWRITE);
    if (fileIDOut == -1) {
        if (CreateFile(fileNameOut) == 0) {
            fileIDOut_ = Open(fileNameOut, MODE_READWRITE);
            Write(buffer, lenBuffer, fileIDOut_);
            Close(fileIDOut_);
        } else
            PrintString("Create file failed\n");
    } else
        Write(buffer, lenBuffer, fileIDOut);
        Close(fileIDOut);

    return 0;
}