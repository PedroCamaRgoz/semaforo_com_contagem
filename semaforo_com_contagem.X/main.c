/*
 * File:   main.c
 * Author: Pedro
 *
 * Created on 10 de Março de 2021, 19:07
 */


#include <xc.h>
#include "config.h"
#include "delay.h"
#include "semaforo.h"
#include "display7seg.h"



void main(void)
{
    int estado = 0;
    int t = 0;
    int i = 0;
    
    while(1)
    {
        switch (estado)
        {
            case 0:
                     estado = 1;
                     break;  
            case 1:
                     semaforo_init();
                     disp7seg_init();
                     estado = 2;
                     break;  
            case 2:
                    vermelho(0);
                    amarelo(0);
                    verdeped(0);
                    verde(1);
                    vermelhoped(1);
                    if(botao()==1)
                    estado = 3;

                    break;  
            case 3: 
                    
                    if(estado==3)
                    { 
                      i = 6;
                      for(i=6;i>0;i--)
                      { 
                        digitos7seg(i);
                        delay(1000); 
                      }
                    }
                    estado = 4;
                    break;  
            case 4:
                   
                  i = 0;
                  digitos7seg(0);
                  estado = 5;
                    break;  
                    
            case 5:
                   verde(0);
                   vermelho(0);
                   verdeped(0);
                   amarelo(1);
                   vermelhoped(1);                 
                    if(estado==5)
                    {
                        i = 4;
                        for(i=4;i>0;i--)
                        {
                            digitos7seg(i);
                            delay(1000);
                        }  
                          
                    }
                   estado = 6;                
                   break;  
            case 6:
              
                   i = 0;
                   digitos7seg(0);
                   estado = 7;
                   break;  
            case 7:
                    verde(0);
                    amarelo(0);
                    vermelhoped(0);
                    vermelho(1);
                    verdeped(1);                  
                      if(estado==7)
                    {   
                          i=8;
                        for(i=8;i>0;i--)
                        {
                            digitos7seg(i);
                            delay(1000);
                        }  
                          
                    }
                    estado = 8;
                    break;  
            case 8:
                    i = 0;
                    digitos7seg(0);
                    estado = 9;
                    break;  
             case 9:
                    estado = 1;
                    break;  
            
        }
                
    }
    
}
