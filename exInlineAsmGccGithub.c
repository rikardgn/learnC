//Example of gcc inline assembler
//modified from code taken from headLine Remarks
//https://gcc.gnu.org/onlinedocs/gcc/extensions-to-the-c-language-family/how-to-use-inline-assembly-language-in-c-code.html
//
#include <stdio.h>
int func(){
    int src = 10;
    int dst;

    asm( "mov %1, %0\n\t"
         "sub $4, %0"
         : "=r" (dst)
         : "r" (src) );
        //:"=r" (dst) OutputOperands
        //The sub assembler instruction modifies the C variable dst
        //"=r", means the variable will be overwritten
        //"=r" (dst), means the variabe dst will be overwritten and will be in a register
        
        // "r" (src) InputOperands
        // "r" means put the value in register
        // "r" (src) means the variabel src will be read and will be in a register
        //The mov assembler instruction reads src

}
int main(){
    int n;
    n=func();
    printf("%d\n", n);
}
