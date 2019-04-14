#include <stdint.h>
#include <stdlib.h>
#include "uart.h"
#include "twi.h"
#include "utility.h"
#include "accel.h"
#include "ubit_led_matrix.h"

int main(){
	uart_init();
    ubit_led_matrix_init();
	twi_init();

/*
	uint8_t* data_buffer;
	data_buffer=(uint8_t*) malloc(8*sizeof(uint8_t));
	twi_multi_read(0b0011001,0x0F, 2,data_buffer);
	uart_send(data_buffer[0]);
	free(data_buffer);
*/
    accel_init();

	
	

	

	
    //int x_dot, y_dot;
	
    /*while(1)
    {	
		int * data_bufferr=(int*) malloc(3*sizeof(int));
	
		accel_read_x_y_z(data_bufferr);
		
		int x_acc=data_bufferr[0];
		int y_acc=data_bufferr[1];
		int z_acc=data_bufferr[2];

		utility_print(&uart_send, "X: %6d Y: %6d Z: %6d\n\r", x_acc, y_acc, z_acc);
        
		x_dot = data_bufferr[0] / 50;
        y_dot = data_bufferr[1] / 50;

        ubit_led_matrix_light_only_at(x_dot, y_dot);

        utility_print(
            &uart_send,
            "X: %6d Y: %6d Z: %6d\n\r",
            data_bufferr[0],
            data_bufferr[1],
            data_bufferr[2]
        );
	free(data_bufferr);
    }*/

	return 0;
}
