#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
    clock_t start, end;
    double timeUsed;
    start = clock();
    end = clock();
    timeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%fl %s", timeUsed, "\n");
    return 0;
}