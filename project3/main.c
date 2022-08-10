#include "operations.h"

int main(int argc, char* argv[]){

    if(argc != 2){
        puts("invalid number of parapeters");
        return 1;
    }
    doIt(argv[1]);    

    return 0;
}