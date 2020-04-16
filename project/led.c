#include <msp430.h>

#include "led.h"

#include "switches.h"

#include "stateMachines.h"

unsigned char red_on = 0, green_on = 0;

unsigned char led_changed = 0;

char led_state = 0;

char state;


static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};


/* toggles leds */

void toggle_leds() {

  switch (led_state) {

  case 0:

    led_green_on();

    break;

  case 1:

    led_red_on();

    break;

  }
  
  led_state ^= 1;

}

void led_init() {

  P1DIR |= LEDS;// bits attached to leds are output

  led_changed = 1;

  led_update();

}

void led_update() {

  if(led_changed) {

    char ledFlags = redVal[red_on] | greenVal[green_on];

    P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds

    P1OUT |= ledFlags;     // set bit for on leds

    led_changed = 0;

  }

}
