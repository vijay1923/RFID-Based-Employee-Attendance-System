#include<lpc21xx.h>
#include "header.h"
int i=0;
extern int flag;
extern char arr[100];
void uart0_handler(void)__irq
{
int t=U0IIR;
if(t==4)
{
 arr[i++]=U0RBR;
  if(i==12)
 {
arr[i]='\0';
  flag=1;
  i=0;
 }
 }
VICVectAddr=0;
}
void config_vic(void)
{
VICIntSelect=0;
VICVectCntl0=6|(1<<5);
VICVectAddr0=(int)uart0_handler;
VICIntEnable=(1<<6);
}
void uart0_interrupt(void)
{
U0IER=1;
}

