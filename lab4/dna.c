#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 4

char* strnsub (char *p, int n);

int main()
{
    char line[] = "His textbook was bought from that bookstore";
    char *p1, *p2;
    int p1Counter, p2Counter;

    p1,p2 = (char*)malloc((LEN+1)*sizeof(char));
    p1 = strnsub(line, LEN);

    p1Counter = 0;
    while (p1Counter+LEN <= strlen(line)){
        p2Counter = p1Counter + LEN;
        //printf("-- %s --  \n", p1);
        while (p2Counter<=strlen(line)){
            p2 = strnsub(line + p2Counter-1, LEN);
            // printf("%s  ", p2);
            // if(p2Counter%5==0)
            //     printf("\n");
            if(strncmp(p1,p2,LEN)==0){
                printf("Repeat Found!\n\n");
                printf("The original string is:\n%s\n\n", line);
                printf("The first substring:  %s\n", strnsub(p1, LEN));
                printf("The second substring: %s\n", strnsub(p2, LEN));
                return 0;
            }
            p2Counter++;
        }
        //printf("\n");
        p1Counter++;
        p1 = strnsub(line + p1Counter, LEN);
    }
    printf("No repeated patterns of length %d in the following string:\n%s\n",
            LEN, line);
    return 0;
}

// returns a string with the first n characters of string p
char* strnsub (char *p, int n){
  char* result;
  result = (char*) malloc((n+1)*sizeof(char));
  strncpy(result, p, n);
  return result;
}
