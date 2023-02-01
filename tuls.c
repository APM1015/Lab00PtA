#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>//to use strcat to append the path


void tuls(const char *string);//Prints out current dir
void recursiveDir(const char *string, const char *string1);//checks for recursion if arguments

int checkDir(const char *string);//checks if it is a directory

int main(int argc, char const *argv[]) {
    //Prompts error if invalid number of arguments
    if(argc < 0){//error if invalid arguements
        perror("Invalid number of arguments. Program failed.");
        exit(EXIT_FAILURE);
    }
    else if(argc > 2){//error if invalid arguments
        perror("Invalid number of arguments. Program failed.");
        exit(EXIT_FAILURE);
    }
    //No recursion since 0 arguments
    //Lists all directory
   else if(argc == 0 || argc == 1){
        tuls(".");
   }
   //Recursion for more than 1 argument
   else if(argc == 2){
       tuls(".");
      recursiveDir(argv[1], ".");

   }

    return 0;
}

void recursiveDir(const char *string, const char *dir) {
    //Almost same process as tuls
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
        if((strcmp(d->d_name[0], ".") == 0) && (strcmp(d->d_name[0], "..") == 0)){

        }
        else{
            printf("%s \n", d->d_name);

            //Initiates true or false for directory
            int ret = 1;
            ret = checkDir(dir);
            //if 0-> directory: if 1->no directory
            if(ret == 0){
                //array size recomended from discord
                char path[4096] = {0};
                strcat(path, dir);//appends path to add directory
                strcat(path,"/");
                strcat(path, (d=readdir(dh)->d_name));
                tuls(path);
            }
        }


      // d = readdir(dh);

    }
    closedir(dh);

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
        //if(d->d_name[0] == '.' || d->d_name[0] == "..") {
            //continue;
        //}
        if((strcmp(d->d_name, ".") == 0) && (strcmp(d->d_name, "..") == 0)){

        }
        else{
            printf("%s \n", d->d_name);


            if((d = readdir(dh)) == DT_DIR){
                //array size recomended from discord
                char path[4096] = {0};
                strcat(path, dir);
                strcat(path,"/");
                strcat(path, (d=readdir(dh)->d_name));
                tuls(path);
            }
        }


      //d = readdir(dh);

    }
    closedir(dh);
}

int checkDir(const char *filename) {
    struct stat path;
    stat(filename, &path);
    return S_ISREG(path.st_mode);
}





