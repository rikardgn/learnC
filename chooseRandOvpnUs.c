//Program to randomly choose beetween the different us ovpn sites
//You can suscribe to the vpn service ovpn by logging onto www.ovpn.com
//Rikard Grossman-Nielsen
//14th dec 2022
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void){
    //program vars
    int maxIndVpn=7, indVpnSel;
    float randomNum, randomNumIntPart, randomNumFracPart;
    char *chrPtr;
    //Input the different ovpn sites in char arrays
    char cArrUsOvpn1[]="sudo openvpn ./us.atlanta.ovpn.com.ovpn";
    char cArrUsOvpn2[]="sudo openvpn ./us.chicago.ovpn.com.ovpn";
    char cArrUsOvpn3[]="sudo openvpn ./us.dallas.ovpn.com.ovpn";
    char cArrUsOvpn4[]="sudo openvpn ./us.denver.ovpn.com.ovpn";
    char cArrUsOvpn5[]="sudo openvpn ./us.los-angeles.ovpn.com.ovpn";
    char cArrUsOvpn6[]="sudo openvpn ./us.new-york.ovpn.com.ovpn";
    char cArrUsOvpn7[]="sudo openvpn ./us.seattle.ovpn.com.ovpn";

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

    //enter the randomly chosen ovpn site in the terminal
    system(chrPtr);
    return 0;
}