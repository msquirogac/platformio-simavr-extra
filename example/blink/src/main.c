#include <avr/io.h>
#include <avr/delay.h>

int main(void)
{
  DDRD |= (1<<2)|(1<<3);
  while(1)
  {
    PORTD |= (1<<2);
    _delay_ms(1);
    PORTD &= ~(1<<2);
    _delay_ms(1);
    PORTD ^= (1<<3);
    _delay_ms(5);
  }
}

#include <avr_mcu_section.h>
AVR_MCU(F_CPU, "atmega328");
const struct avr_mmcu_vcd_trace_t _mytrace[]  _MMCU_ = {
  { AVR_MCU_VCD_SYMBOL("PD2"), .mask = (1 << 2), .what = (void*)&PORTD}
};

