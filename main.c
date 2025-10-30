#include<lpc21xx.h>
#include "header.h"
 char arr[100];
int flag=0;
int main()
{
int f=0;
char  h,m,s,date,month,year;
i2c_init();
lcd_init();
uart0_init(9600);
config_vic();
uart0_interrupt();

while(1)
{
if(flag==1)
{
i2c_read(0xd0,0x2);  
m=i2c_read(0xd0,0x1);
s=i2c_read(0xd0,0x0);
date=i2c_read(0xD0,0x04);
month=i2c_read(0xD0,0x05);
year=i2c_read(0xD0,0x06);

arr[12]=' ';
arr[15]=':';
arr[16]=(m/0x10)+48;
arr[17]=(m%0x10)+48;
arr[18]=':';
arr[19]=(s/0x10)+48;
arr[20]=(s%0x10)+48;
arr[21]=' ';
arr[22]=(date/0x10)+48;
arr[23]=(date%0x10)+48;
arr[24]='/';
arr[25]=(month/0x10)+48;
arr[26]=(month%0x10)+48;
arr[27]='/';
arr[28]=(year/0x10)+48;
arr[29]=(year%0x10)+48;
arr[30]=' ';
lcd_cmd(0x81);
if(((h>>6)&1)==0)
{
arr[13]=(h/0x10)+48;
arr[14]=(h%0x10)+48;
lcd_data((h/0x10)+48);
lcd_data((h%0x10)+48);
}
if(h>>6&1)
{
if((h&0x20)>>4)
f=1;
else
f=0;
arr[13]=(((h&0x10)>>4)+48);
arr[14]=(h&0x0f)+48;
lcd_data(((h&0x10)>>4)+48);
lcd_data(((h&0x10)>>4)+48);
}
lcd_data(':');
lcd_data((m/0x10)+48);
lcd_data((m%0x10)+48);
lcd_data(':');
lcd_data((s/0x10)+48);
lcd_data((s%0x10)+48);
if(f==1){
arr[31]='P';
arr[32]='M';
arr[33]='\n';
f=0;
lcd_data('P');
lcd_data('M');
}
else
{
 arr[31]='A';
 arr[32]='M';
 arr[33]='\n';
 lcd_data('A');
 lcd_data('M');
}
flag=0;
uart0_tx_string(arr);
lcd_cmd(0x80);
lcd_string(" ID SCANNED ");
delay_ms(50);
lcd_cmd(0x01);
}
else
{
 lcd_cmd(0x80);
 lcd_string("SCAN YOUR ID");
uart0_tx_string(arr);
	delay_ms(200);
 lcd_cmd(0x01);
}
}
}

