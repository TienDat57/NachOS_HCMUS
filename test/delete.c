#include "syscall.h"

int main()
{
   int temp;
   if(Remove("oke.txt") == 1)
      PrintString("File deleted successfully\n");
   else
      PrintString("File not found\n");
   return 0;
}