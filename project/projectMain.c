#include <msp430.h>

#include "libTimer.h"

#include "led.h"

#include "switches.h"

#include "buzzer.h"



int main(void) {

  /* setup master oscillator, CPU & peripheral clocks */

  configureClocks();



  switch_init();



  led_init();



  buzzer_init();



  enableWDTInterrupts();/* enable periodic interrupt */



  or_sr(0x18);/* CPU off, GIE on */

}
