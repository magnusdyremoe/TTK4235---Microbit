

#include "uart.h"
#include <stdio.h>
#include "gpio.h"

ssize_t _write(int fd, const void *buf, size_t count){
	char * letter = (char *)(buf);
	for(int i = 0; i < count; i++){
		uart_send(*letter);
		letter++;
	}
	return count;
}


void SendeFunksjon(){
	if(!(GPIO->IN & (1 << 26))){
		uart_send('B');
	}
	if(!(GPIO->IN & (1 << 17))){
		uart_send('A');
	}
}


void Mottaksfunksjon(){
	if((GPIO->IN)&(1<<25)){
		if((GPIO->IN) & (1 << 13)){
			GPIO->OUTCLR = (1 << 13)|(1 << 14)|(1 << 15);
		}
		if(!((GPIO->IN) & (1 << 13))){
			GPIO->OUTSET = (1 << 13)|(1 << 14)|(1 << 15);
		}
	}
}
		

void GPIOInitialize(){
	// Configure LED Matrix
	for(int i = 4; i <= 15; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}

	// Configure buttons
	GPIO->PIN_CNF[17] = 0;
	GPIO->PIN_CNF[26] = 0;
	
}
	

int main(){
	GPIOInitialize();
	uart_init();
	uart_send('a');
//	iprint("Norway har %d counties. \n\r", 18);

	int sleep = 0;
	while(1){
//	uart_send('a');
		/* Check if button B is pressed;
		 * turn on LED matrix if it is. */

		/* Check if button A is pressed;
		 * turn off LED matrix if it is. */
		iprintf("Norway har %d counties. \n\r", 18);
		if(!(GPIO->IN & (1 << 26))){
			GPIO->OUTSET = (1 << 13)|(1 << 14)|(1 << 15);

		}
		if(!(GPIO->IN & (1<<17))){
			GPIO->OUTCLR = (1 << 13)|(1 << 14)|(1 << 15);
			
		}


		sleep = 10000;
		while(--sleep);
	}
	return 1;
}
	
