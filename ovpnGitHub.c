//Program to randomly choose beetween different vpn sites that uses the openvpn protocol.
//The var maxIndVpn tells the program how many sites you wish to choose from.
//Add as many char vectors and if clauses as the number of open vpn sites you wish to choose from
//This program has room for 18 sites
//Rikard Grossman-Nielsen
//8th jan 2023
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void){
    //program vars
    int maxIndVpn=18, indVpnSel;
    float randomNum, randomNumIntPart, randomNumFracPart;
    char *chrPtr;
    //Input the different ovpn sites in char arrays
    //sudo openvpn --auth-nocache --config ./myfile.ovpn
    char cArrUsOvpn1[]="sudo openvpn --auth-nocache --config ./site1.ovpn";
    char cArrUsOvpn2[]="sudo openvpn --auth-nocache --config ./site2.ovpn";
    char cArrUsOvpn3[]="sudo openvpn --auth-nocache --config ./site3.ovpn ";
    char cArrUsOvpn4[]="sudo openvpn --auth-nocache --config ./site4.ovpn";
    char cArrUsOvpn5[]="sudo openvpn --auth-nocache --config ./site5.ovpn";
    char cArrUsOvpn6[]="sudo openvpn --auth-nocache --config ./site6.ovpn";
    char cArrUsOvpn7[]="sudo openvpn --auth-nocache --config ./site7.ovpn";
    char cArrUsOvpn8[]="sudo openvpn --auth-nocache --config ./site8.ovpn";
    char cArrUsOvpn9[]="sudo openvpn --auth-nocache --config ./site9.ovpn";
    char cArrUsOvpn10[]="sudo openvpn --auth-nocache --config ./site10.ovpn";
    char cArrUsOvpn11[]="sudo openvpn --auth-nocache --config ./site11.ovpn";
    char cArrUsOvpn12[]="sudo openvpn --auth-nocache --config ./site12.ovpn";
    char cArrUsOvpn13[]="sudo openvpn --auth-nocache --config ./site13.ovpn";
    char cArrUsOvpn14[]="sudo openvpn --auth-nocache --config ./site14.ovpn";
    char cArrUsOvpn15[]="sudo openvpn --auth-nocache --config ./site15.ovpn";
    char cArrUsOvpn16[]="sudo openvpn --auth-nocache --config ./site16.ovpn";
    char cArrUsOvpn17[]="sudo openvpn --auth-nocache --config ./site17.ovpn";
    char cArrUsOvpn18[]="sudo openvpn --auth-nocache --config ./site18.ovpn";
    
    //generate random number
    srand(time(0));
    randomNum=rand()%(maxIndVpn*3)+1;
    randomNum=randomNum/3;
    randomNumIntPart=(int)randomNum+0.0;
    randomNumFracPart=randomNum-randomNumIntPart;
    if(randomNumFracPart<0.5)
        indVpnSel=(int)randomNumIntPart;
    else
        indVpnSel=(int)(randomNumIntPart+1.0);
    printf("indVpn%d=", indVpn);
    getchar();
    //choose openvpn site based on the number generated
    if(indVpnSel==1)
        chrPtr=&cArrUsOvpn1[0];
    else if(indVpnSel==2)
        chrPtr=&cArrUsOvpn2[0];
    else if(indVpnSel==3)
        chrPtr=&cArrUsOvpn3[0];
    else if(indVpnSel==4)
        chrPtr=&cArrUsOvpn4[0];
    else if(indVpnSel==5)
        chrPtr=&cArrUsOvpn5[0];
    else if(indVpnSel==6)
        chrPtr=&cArrUsOvpn6[0];
    else if(indVpnSel==7)
        chrPtr=&cArrUsOvpn7[0];
    else if(indVpnSel==8)
        chrPtr=&cArrUsOvpn8[0];
    else if(indVpnSel==9)
        chrPtr=&cArrUsOvpn9[0];
    else if(indVpnSel==10)
        chrPtr=&cArrUsOvpn10[0];
    else if(indVpnSel==11)
        chrPtr=&cArrUsOvpn11[0];
    else if(indVpnSel==12)
        chrPtr=&cArrUsOvpn12[0];
    else if(indVpnSel==13)
        chrPtr=&cArrUsOvpn13[0];
    else if(indVpnSel==14)
        chrPtr=&cArrUsOvpn14[0];
    else if(indVpnSel==15)
        chrPtr=&cArrUsOvpn15[0]; 
    else if(indVpnSel==16)
        chrPtr=&cArrUsOvpn16[0];
    else if(indVpnSel==17)
        chrPtr=&cArrUsOvpn17[0];
    else if(indVpnSel==18)
        chrPtr=&cArrUsOvpn18[0];  
    
    //enter the randomly chosen ovpn site in the terminal
    system(chrPtr);
    return 0;
}