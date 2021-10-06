/*Basic command line file protection software for Unix-like systems.

Copyright (C) 2021 Christofer Koch GPL-3.0-or-later.

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program. If not, see <https://www.gnu.org/licenses/>.*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main()
{
  int test;
  char c, fp[64];

 start:
  system("clear");
  printf("\tFile Protection Software\n\n");
  printf("1: Owner Permissions for File/Directory\n");
  printf("2: Public Permissions for File/Directory\n");
  printf("3: Help\n");
  printf("4: License Information\n\n");
  printf("Q: Quit\n\n");
  printf("Input choice: ");
  
  c = getchar();

  if(c == 81 || c == 113){
    system("clear");
    exit(0);
  }/*Tests if q or Q has been pressed, quitting the program.*/

  switch(c){
  case '1':
    system("clear");
    printf("Input Complete File Path: ");
    scanf("%s", &fp);
    test = chmod(fp, S_IRWXU); /*Sets all permissions to the owner. This is not immediately evident if you are logged into your own account.*/
    if(test == -1)
      printf("Error! Operation cannot be completed.\n");
    else
      printf("Read, write, and execute permissions successfully set to owner.\n\n");
    printf("Press <enter> key to continue.");
    getchar();
    break;
   case '2':
    system("clear");
    printf("Input Complete File Path: ");
    scanf("%s", &fp);
    test = chmod(fp, S_IRWXO | S_IRWXU | S_IRWXG);
    if(test == -1)
      printf("Error! Operation cannot be completed.\n");
    else
      printf("Read, write, and execute permissions successfully set to everyone.\n\n");
    printf("Press <enter> key to continue.");
    getchar();
    break;
  case '3':
    system("clear");
    printf("\t\tHelp\n\n");
    printf("Enter full path name for file or directory.\n\n");
    printf("Example: /home/user/file.txt\n\n");
    printf("Make sure path is spelled correctly and has the correct extension.\n\n");
    printf("Press <enter> key to continue.");
    getchar();
    break;
  case '4':
    system("clear");
    printf("Copyright (C) 2021 Christofer Koch GPL-3.0-or-later.\n\n");
    printf("This program is free software: you can redistribute it and/or modify it under\nthe terms of the GNU General Public License as published by the Free Software\nFoundation, either version 3 of the License, or any later version.\n\n");
    printf("This program is distributed in the hope that it will be useful, but WITHOUT\nANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS\nFOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.\n\n");
    printf("You should have received a copy of the GNU General Public License along with\nthis program. If not, see <https://www.gnu.org/licenses/>.\n\n");
    printf("Press <enter> key to continue.");
    getchar();
    break;
  }

  getchar(); /*Using getchar() twice holds the screen in place.*/
 
  goto start;

  return 0;
}
