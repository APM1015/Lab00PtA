#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>//to use strcat to append the path


void tuls(const char *string);

int main(int argc, char const *argv[]) {
    //Prompts error if invalid number of arguments
   
    //No recursion since 0 arguments
    //Lists all directory
    
        tuls(".");
   

    return 0;
}

void tuls(const char *dir) {
    //list the directoru
    struct dirent *d;
    DIR *dh = opendir(dir);
    if(!dh){
        perror("tuls: cannot open directory\n");
        exit(EXIT_FAILURE);
    }
    // while( (direntStructPtr = readdir(DIRPtr)) != NULL){}
    d = readdir(dh);
    while(d != NULL){
        //skips over
        
       printf("%s ", d->d_name);
       


    }
    closedir(dh);
}
