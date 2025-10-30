
// LCD Declarations 
extern void delay_ms(unsigned int ms);
extern void lcd_data(unsigned char  data);
extern void lcd_cmd(unsigned char cmd);
extern void lcd_init(void );
extern void lcd_string(char *ptr);
extern void lcd_integer( long long int num);
extern void lcd_cgram(void );

// BLUTHOOTH Declarations 
extern void bluetooth(void );
extern void mannual(void );

// UART0 Declartions
extern void uart0_tx(unsigned char data);
extern unsigned char uart0_rx(void);
extern void uart0_tx_string(char *ptr);
extern void uart0_init(unsigned int baud);
extern unsigned char uart0_rx(void );
extern void uart0_tx_integer(int num);
extern void uart0_tx_float(float num);
extern void uart0_rx_sting(char *s);
extern char *uart0_rx_string(char *s, int ele);

// ADC Declartions
extern unsigned int adc_read(unsigned char ch_num);;
extern void adc_init(void);


// INTERRUPT Declartions
extern void config_eint0(void );
extern void config_vic_for_eint0(void );
extern void config_vic_for_uart0(void );
extern void config_vic_for_EINT0(void );

// SPI Declartions
extern unsigned int mcp3204read (unsigned char );
extern void spi0_init(void );
extern unsigned char spi0(unsigned char );

// I2C Declartions
extern void i2c_init(void);
extern void i2c_send(char sa,char mr,char data);
extern char i2c_read(char sa,char mr);
extern char  i2c_write(char sw );

// CAN Declartions
typedef struct CAN1_MSG{
	unsigned int  id;
	unsigned int byteA;
	unsigned int  byteB;
	char  rtr;
	char  dlc;
}CAN1;

extern void can1_tx(CAN1 v);
extern void can1_init(void);


/////// project 
extern void config_vic(void);
extern void uart0_interrupt(void);
