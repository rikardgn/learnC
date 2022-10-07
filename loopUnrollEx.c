//Example of loop unrolling
//Inspired by https://en.wikipedia.org/wiki/Loop_unrolling
//In this example it seems that the overhead of reducing the loop 
//contributes to the fact that the unrolled loop takes the same time
//to excute as the normal loop
//It is however a good and practical example of how loop unrolling
//and algorithm timing can look for learning purposes
//Rikard Grossman-Nielsen 6th oct 2022

void incr(int val);
#include <stdio.h>
#include <time.h>
int main(void){
    int vector[100000], i;
    clock_t start, end;
    double cpu_time_used;

    for(i=0; i<100000; i++)
        vector[i]=0;
    //normal loop excutes 100000 times
    start = clock();
    for(i=0; i<100000; i++)
        incr(vector[i]);
    end = clock();
    cpu_time_used =( ( (double) (end-start) ) / CLOCKS_PER_SEC ) * 1000;
    printf("time for normal loop%lf\n", cpu_time_used);
    //unrolled loop
    start = clock();
    for(i=0; i<20000; i++){
        incr(vector[i]);
        incr(vector[i+1]);
        incr(vector[i+2]);
        incr(vector[i+3]);
        incr(vector[i+4]);
    }
    end = clock();
    printf("time for unrolled loop%lf\n", cpu_time_used);

    return 0;
}

void incr(int val){
    val++;
}