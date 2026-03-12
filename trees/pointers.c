#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char* argv[3]){

    printf("argv --> %p\n", argv);
    printf("argv +1 --> %p\n", argv+1);
    printf("argv +2 --> %p\n", argv+2);
    printf("argv[0] is pointer at 0 \p--> %p\n", &argv[0]);
    printf("argv[1] is pointer at 1 \p--> %p\n", &argv[1]);
    printf("argv[2] is pointer at 2 \p--> %p\n", &argv[2]);
    printf("argv[0] sting output using \s --> %s\n", argv[0]);
    printf("argv[1] sting output using \s --> %s\n", argv[1]);
    printf("argv[2] sting output using \s --> %s\n", argv[2]);
    printf("argv[2] sting output using *(argv[2]+2)) \c --> %c\n", *(argv[2]+2));
    printf("argv[2] sting output using *(*(argv+2)+2)) \c --> %c\n", *(*(argv+2)+2));
    return 0;


}


