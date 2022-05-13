#include "syscall.h"

int main() {
    char fileName[] = "datdu.txt";
    int id;

    if ((id = Open(fileName, 0)) != -1) {
        PrintString("File ");
        PrintString(fileName);
        PrintString(" opened successfully!\n");
        PrintString("Id: ");
        PrintNum(id);
        PrintString("\n");

        PrintString("Pointer position pointer:");
        PrintNum(Seek(2, id));

        Close(id);
    } else
        PrintString("Open file failed\n");
    PrintString("\n");
    return 0;
}