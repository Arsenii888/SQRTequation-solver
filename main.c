#include <stdio.h>
#include <stdlib.h>
#include "mt.h"

int main() {
    int es=0;
    char string[]="1x+1x+2026=0";
    SQRTequation(string, sizeof(string)/sizeof(char));
    scanf("%i", es);
    return 0;
}
