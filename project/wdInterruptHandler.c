#include <msp430.h>

#include "stateM.h"



void

__interrupt_vec(WDT_VECTOR) WDT(){

  /* 200 interrupts/sec */

  static char blink_count = 0;

  if (++blink_count == 100) {

    state_advance();

    blink_count = 0;

  }

}
