// Ovpn github /version 2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#define MAX_STR_LEN 255
int main(void)
{
    //program vars
    int maxIndVpn=0, indVpnSel, i, k;
    float randomNum, randomNumIntPart, randomNumFracPart;
    char strLine[255];
    char strFileSites[255];

    //read name of file with scanf
    printf("Enter name of file with sites to read:\n");
    scanf("%s", &strFileSites[0]);
    
    // open and count number of line in the file for openvpnsites
    FILE *fp = fopen(&strFileSites[0], "r");

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
    fp = fopen(&strFileSites[0], "r");
    i=1;
    while(true){
        fgets(strLine, 255, fp);
        if (i==indVpnSel)
            break;
        i++;
    }
    fclose(fp);           
    
    system(strLine);

    return 0;
}