/*
    writtern by : Mohamed ElSayed
    m.elsayed4420@gmail.com
*/

#include <stdio.h>
#include <stdlib.h>

double addsubParser();
double muldivParser();
double numParser();
double parParser();

char *equ;

double muldivParser()
{
    double fac2;
    double fac1 = numParser();
    while(*equ == '*')
    {
        ++equ;
        fac2 = numParser();
        fac1 = fac2*fac1;
    }

    while(*equ == '/')
    {
        ++equ;
        fac2 = numParser();
        fac1 = fac1/fac2;
    }
    return fac1;
}

double addsubParser()
{
    double fac2;
    double fac1 = muldivParser();
    while(*equ == '+')
    {
        ++equ;
        fac2 = muldivParser();
        fac1 = fac2+fac1;
    }

    while(*equ == '-')
    {
        ++equ;
        fac2 = muldivParser();
        fac1 = fac1-fac2;
    }
    return fac1;
}

double numParser()
{
    double num=0;
    int  i=0;
    char cnum[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    while(*equ!='+' && *equ!='-' && *equ!='*' && *equ!='/' && *equ!='\0')
    {
        cnum[i]=*equ++;
        ++i;
    }

    num = atof(cnum);
    return num;
}
int main(void)
{
    equ = "22.5+1.5";
    double result = addsubParser();
    printf("%f\n", result);
    return 0;
}
