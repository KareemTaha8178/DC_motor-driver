/* 
 * File:   Application.c
 * Author: Kareem Taha Abdelfatah Mohammed
 * https://www.linkedin.com/in/kareem-taha-ba451621a/
 * Created on September 13, 2022, 9:10 PM
 */

#include "Application.h"

STD_ReturnType ret = E_OK;

Dc_motor_t dc_motor_1 = {
    .two_direction[0].pin = GPIO_PIN0,
    .two_direction[0].port = PORTC_INDEX,
    .two_direction[0].status = DC_MOTOR_OFF,
    .two_direction[1].pin = GPIO_PIN1,
    .two_direction[1].port = PORTC_INDEX,
    .two_direction[1].status = DC_MOTOR_OFF
};


Dc_motor_t dc_motor_2 = {
    .two_direction[0].pin = GPIO_PIN2,
    .two_direction[0].port = PORTC_INDEX,
    .two_direction[0].status = DC_MOTOR_OFF,
    .two_direction[1].pin = GPIO_PIN3,
    .two_direction[1].port = PORTC_INDEX,
    .two_direction[1].status = DC_MOTOR_OFF
};

int main() { 
    Application_initialize();
    while(1){
        Dc_motor_turn_left(&dc_motor_1);
        _delay(5000000);
        Dc_motor_turn_left(&dc_motor_2);
        _delay(5000000);
        Dc_motor_stop(&dc_motor_1);
        _delay(5000000);
        Dc_motor_stop(&dc_motor_2);
        _delay(5000000);
        Dc_motor_turn_right(&dc_motor_1);
        _delay(5000000);
        Dc_motor_turn_right(&dc_motor_2);
        _delay(5000000);
        Dc_motor_stop(&dc_motor_1);
        _delay(5000000);
        Dc_motor_stop(&dc_motor_2);
        _delay(5000000);
    }
    return (EXIT_SUCCESS);
}

/* initialize any pin with direction & logic */
void Application_initialize(void){
    ret = Dc_motor_initialize(&dc_motor_1);
    ret = Dc_motor_initialize(&dc_motor_2);
}