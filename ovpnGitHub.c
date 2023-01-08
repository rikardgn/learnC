//Program to randomly choose beetween different vpn sites that uses the openvpn protocol.
//The var maxIndVpn tells the program how many sites you wish to choose from.
//Add as many char vectors and if clauses as the number of open vpn sites you wish to choose from
//This program has room for 18 sites
//Rikard Grossman-Nielsen
//8th jan 2023
// Updated: Moshe Zadka, Jan 8, 2023.
// * Removed copy/pasted template
// * Changed if/elif ladder to snprintf
// Should be easier to change number of sites now.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {

    int maxIndVpn=18, indVpnSel;
    char *template = "sudo openvpn --auth-nocache --config ./site%d.ovpn";
    char output[1024];

    //generate random number
    srand(time(0));
    indVpnSel = (rand() % maxIndVpn) + 1;

    // TODO: Add defensive programming here
    snprintf(output, sizeof(output), template, indVpnSel);

    //enter the randomly chosen ovpn site in the terminal
    system(output);

    return 0;
}
