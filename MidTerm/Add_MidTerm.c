#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

int main(int argc, char* argv[]) {

    char buf[80], pathName[80];
    int fdWrite, readNum;

    if (argc < 3) {
        perror("agrc < 3 error ");
        exit(1);
    }

    bzero(buf, sizeof(buf));  //clear	
    strcat(buf, "==========================================\n");
    write(1, buf, strlen(buf));

    bzero(buf, sizeof(buf));
    strcat(buf, " Hansung University, ");
    strcat(buf, argv[1]);
    strcat(buf, ", ");
    strcat(buf, argv[2]);
    strcat(buf, " \n");
    write(1, buf, strlen(buf));

    bzero(buf, sizeof(buf));
    strcat(buf, "==========================================\n");
    write(1, buf, strlen(buf));




    bzero(buf, sizeof(buf));
    strcat(buf, "Source PathName : ");
    write(1, buf, strlen(buf));



    //keyboard input
    bzero(pathName, sizeof(pathName));
    read(0, pathName, sizeof(pathName));
    pathName[strlen(pathName) - 1] = '\0';  





    fdWrite = open(pathName, O_WRONLY | O_APPEND);
    if (fdWrite == -1) {
        perror("open error");
        exit(1);
    }

    while (1) {
        bzero(buf, sizeof(buf));
        readNum = read(0, buf, sizeof(buf)); 
        if (strcmp(buf, "quit\n") == 0) {
            break;
        }

        write(fdWrite, buf, readNum); 
    }
    close(fdWrite); 

    bzero(buf, sizeof(buf));
    strcat(buf, pathName);
    strcat(buf, "  Created !! Thanks ~~ \n");
    write(1, buf, strlen(buf));

    
        bzero(buf, sizeof(buf));
        strcat(buf, argv[1]);
        strcat(buf, "    ");
        strcat(buf, argv[2]);
        strcat(buf, "\n");
        write(1, buf, strlen(buf));
  

    return 0;
}
