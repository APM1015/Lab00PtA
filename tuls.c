#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>//to use strcat to append the path


void tuls(const char *string);
//void recursiveDir(const char *string);

int main(int argc, char const *argv[]) {
    //Prompts error if invalid number of arguments
    if(argc < 0){
        perror("Invalid number of arguments. Program failed.");
        exit(EXIT_FAILURE);
    }
    else if(argc > 2){
        perror("Invalid number of arguments. Program failed.");
        exit(EXIT_FAILURE);
    }
    //No recursion since 0 arguments
    //Lists all directory
   else if(argc == 0 || argc >= 1){
        tuls(".");
   }
   //else if(argc == 2){
      // tuls(".");
      // recursiveDir(argv[1]);

  // }

    //tuls(".");
    //tuls("..");


    return 0;
}

//void recursiveDir(const char *string) {
//list the directoru
/*
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
    //if(d->d_name[0] == '.' || d->d_name[0] == "..") {
    //continue;
    //}
    if((strcmp(d->d_name, ".") == 0) && (strcmp(d->d_name, "..") == 0)){
    continue;
    }
    printf("%s \n", d->d_name);

    if((d = readdir(dh)) == DT_DIR){
    //array size recomended from discord
    char path[4096] = {0};
    strcat(path, dir);
    strcat(path,"/");
    strcat(path, (d=readdir(dh)->d_name));
    tuls(path);
    }

    // d = readdir(dh);

    }
    closedir(dh);
    */
//}

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
        //if(d->d_name[0] == '.' || d->d_name[0] == "..") {
            //continue;
        //}
        if((strcmp(d->d_name, ".") == 0) && (strcmp(d->d_name, "..") == 0)){
            continue;
        }
       printf("%s \n", d->d_name);

       if((d = readdir(dh)) == DT_DIR){
           //array size recomended from discord
           char path[4096] = {0};
           strcat(path, dir);
           strcat(path,"/");
           strcat(path, (d=readdir(dh)->d_name));
           tuls(path);
       }

      // d = readdir(dh);

    }
    closedir(dh);
}

