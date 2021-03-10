/*
 * File:   semaforo.c
 * Author: Pedro
 *
 * Created on 10 de Março de 2021, 19:17
 */


#include <xc.h>
#include "config.h"

#define VERDE PORTDbits.RD5
#define AMARELO PORTDbits.RD6
#define VERMELHO PORTDbits.RD7
#define VERDEPED PORTDbits.RD2
#define VERMELHOPED PORTDbits.RD3
#define BOTAO PORTDbits.RD1


void semaforo_init (void)
{
    TRISDbits.TRISD7 = 0;
    TRISDbits.TRISD6 = 0;
    TRISDbits.TRISD5 = 0;
    TRISDbits.TRISD3 = 0;
    TRISDbits.TRISD2 = 0;
    TRISDbits.TRISD1 = 1;
    
    PORTDbits.RD7 = 0;
    PORTDbits.RD6 = 0;
    PORTDbits.RD5 = 0;
    PORTDbits.RD3 = 0;
    PORTDbits.RD2 = 0;
    
}

void verde(int x)
{
    VERDE = x;
}
void amarelo(int x)
{
    AMARELO = x;
}
void vermelho(int x)
{
    VERMELHO = x;
}
void verdeped(int x)
{
    VERDEPED = x;
}
void vermelhoped(int x)
{
    VERMELHOPED = x;
}
int botao(void)
{
    return( BOTAO );
}