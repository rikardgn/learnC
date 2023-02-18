// Ovpn github /version 2
//Add functionality to launch passmanager by third commandLine Argument
//Rikard Grossman-Nielsen 7th Feb 2022
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#define MAX_STR_LEN 255
int main(int argc, char** argv)
{
    //program vars
    int maxIndVpn=0, indVpnSel, i, k, siteFileExists;
    float randomNum, randomNumIntPart, randomNumFracPart;
    char strLine[255];

    printf("argc=%d", argc);
    printf("%s", argv[1]);
    printf("%s", argv[2]);
    getchar();
    if(argc<3){
        printf("Too few args exiting");
        return -1;
    }
    if(argc>3){
        printf("Too many args exiting");
        return -1;
    }
    
    //open file thats entered in argv/argc 
    // open and count number of line in the file for openvpnsites
    FILE *fp = fopen(*(argv+1), "r");
    if (!fp)
    {
        printf("file error");
        return EXIT_FAILURE;
    }

    while (fgets(strLine, 255, fp))
        maxIndVpn++;
    
    //Generate randomVpnNumber
    srand(time(0));
    randomNum=rand()%(maxIndVpn*3)+1;
    randomNum=randomNum/3;
    randomNumIntPart=(int)randomNum+0.0;
    randomNumFracPart=randomNum-randomNumIntPart;
    if(randomNumFracPart<0.5)
        indVpnSel=(int)randomNumIntPart;
    else
        indVpnSel=(int)(randomNumIntPart+1.0);
    
    //open file and jump the same number of lines as random number, when rand number reached, break and enter the
    //line correspoding ot the random number into terminal
    fp = fopen(*(argv+1), "r");
    i=1;
    while(true){
        fgets(strLine, 255, fp);
        if (i==indVpnSel)
            break;
        i++;
    }
    fclose(fp);           
    //lanch pwManager by using string entered in commandLine.
    system( strcat(argv[2], " &") );
    //launch openvpn with randomized site
    system(strLine);
    return 0;
}