#include "syscall.h"

int main()
{
   PrintString("\t\tBEAUTIFUL TEAM \n");
   PrintString("\t20127458 - Dang Tien Dat\n");
   PrintString("\t20127011 - Le Tan Dat\n");
   PrintString("\t20127680 - Pham Thi Anh Phat\n\n");

   PrintString("\t\tHelp Project NachOS-4.0\n");
   PrintString("   -sort: use bubble sort to sort array in ascending or decrease, run ../build.linux/nachos -x bubbleSort\n");
   PrintString("   -ascii: to print the ascii encoding, run ../build.linux/nachos -x ascii\n");
   PrintString("   -createfile: to check system call Create, run ../build.linux/nachos -x createfile\n");
   PrintString("   -createfile: to check system call Create, run ../build.linux/nachos -x createfile\n");
   PrintString("   -open_close: to check system call Open and Close file, run ../build.linux/nachos -x open_close\n");
   PrintString("   -cat: request to enter filename, then display the contents of that file, run ../build.linux/nachos -x cat\n");
   PrintString("   -copy: ask to enter the source and destination file names and execute the copy, run ../build.linux/nachos -x copy\n");
   PrintString("   -delete: to check system call Remove, run ../build.linux/nachos -x delete\n\n");
   PrintString("\t----------END HELP-------------\n\n\n");

   return 0;
}