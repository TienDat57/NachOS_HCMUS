#include "syscall.h"

#define MODE_READWRITE 0
#define MODE_READ 1

#define stdin 0
#define stdout 1

int main() {
    char buffer[100];
    int i;
    int write;
    char* str;

    int fileid = Open("datdu.txt", MODE_READ);
    int read = Read(buffer, 50, fileid);
    int len = 0;
    while (buffer[len] != '\0') ++len;
    PrintString("Read ");
    PrintNum(len);
    PrintString(" characters: ");
    PrintString(buffer);
    PrintString("\n");
    Close(fileid);

    fileid = Open("test_write.txt", MODE_READWRITE);
    str = "Hello world!";
    write = Write(str, 13, fileid);

    PrintString("Write ");
    PrintNum(write);
    PrintString(" characters: ");
    PrintString(str);
    PrintString("\n");
    Close(fileid);

    return 0;
}
