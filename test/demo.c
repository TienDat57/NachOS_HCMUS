#include "syscall.h"

char str[256];

#define MODE_READWRITE 0
#define MODE_READ 1

#define stdin 0
#define stdout 1

int main() {
    // read num and print num
    // int num;
    // PrintString("Input number: ");
    // PrintNum(ReadNum(&num));

    // read char and print char
    // PrintString("Input character: ");
    // PrintChar(ReadChar());

    // read string and print string
    // PrintString("Input string: ");
    // ReadString(str, 10);
    // PrintString(str);

    // Ramdom number
    //  PrintNum(RandomNum());

    // Create file to test system call Create
    char fileName[256];
    PrintString("Enter file's name: ");
    ReadString(fileName, 5);
    if (CreateFile(fileName) == 0) {
        PrintString("Created successfully file: ");
        PrintString(fileName);
    } else
        PrintString("Error create file");

    //Open file and close file system call
    // char fileName[] = "datdu.txt";
    // int id;

    // if ((id = Open(fileName, 0)) != -1) {
    //     PrintString("File ");
    //     PrintString(fileName);
    //     PrintString(" opened successfully!\n");
    //     PrintString("Id: ");
    //     PrintNum(id);
    //     PrintString("\n");

    //     Close(id);
    // } else
    //     PrintString("Open file failed\n");


    // Read file and write file
    // char buffer[100];
    // int i;
    // int write;

    // int fileid = Open("datdu.txt", MODE_READ);
    // int read = Read(buffer, 50, fileid);
    // int len = 0;
    // while (buffer[len] != '\0') ++len;
    // PrintString("Read ");
    // PrintNum(len);
    // PrintString(" characters: ");
    // PrintString(buffer);
    // PrintString("\n");
    // Close(fileid);

    // fileid = Open("datdu.txt", MODE_READWRITE);
    // write = Write(buffer, len, fileid);

    // PrintString("Write ");
    // PrintNum(write);
    // PrintString(" characters: ");
    // PrintString(buffer);
    // PrintString("\n");
    // Close(fileid);

    // fileid = Open("datdu.txt", MODE_READWRITE);
    // read = Read(buffer, 50, fileid);
    // len = 0;
    // while (buffer[len] != '\0') ++len;

    // PrintString("Read ");
    // PrintNum(len);
    // PrintString(" characters: ");
    // PrintString(buffer);
    // PrintString("\n");
    // // Write to the same file
    // write = Write(buffer, len, fileid);
    // PrintString("Write ");
    // PrintNum(write);
    // PrintString(" characters: ");
    // PrintString(buffer);
    // PrintString("\n");
    // Close(fileid);

    // PrintString("Type a string (use ctrl+D to end typing):\n");
    // for (i = 0; i < len; ++i) {
    //     buffer[i] = 0;
    // }
    // Read(buffer, 50, stdin);
    // len = 0;
    // while (buffer[len] != '\0') ++len;
    // PrintNum(Write(buffer, len, stdout));


    PrintString("\n\n");
    return 0;
}