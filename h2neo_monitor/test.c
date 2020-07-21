/*
 * test.h
 *
 *  Created on: Jul 9, 2020
 *      Author: Jenny Cho
 *
 *
 * This file consists of code to test the functionality of each function
 * before integrating into the project files.
 */

#include <msp430f5529.h>
#include "nokia5110.h"
#include "rotary_encoder.h"
#include "test.h"

#define   Num_of_Results   8

extern volatile unsigned int results[Num_of_Results];
static unsigned char index = 0;

/*
 * Function: Set cursor to middle of screen
 *
 * Note:
 * Translations are arbitrary. In the end we want it to be fixed
 * around the decimal point.
 * 	i.e.	 1.25 mL/r		8.12 mL/h
 * 			25.70 mL/r 	   13.64 mL/r
 */
void test_cursDripRate() {
	setCursor((X_PIXELS/2) - 2, (Y_PIXELS/2) - 1);
	prints("1.25 mL/h");
}

/*
 * Function: ADC12 into A0
 *
 * Note:
 * 		Copied code from MSP430F55xx_adc_07.c
 * Reference:
 * 		https://www.youtube.com/watch?v=pT0N8j0tCTM
 */
void test_adc0_init()
{
//	/*
//	 * ADC12SHT0_x   -- sample-and-hold time. Defines num ADC12CLK cycles in the sampling period
//	 * 						 0b100 --> 64 cycles
//	 * ADC12ON       -- ADC12_A on
//	 * ADC12MSC      -- set multiple sample and conversion (valid for sequence or repeated modes)
//	 * ADC12REFON    -- reference generator ON
//	 * ADC12REF2_5V  -- 0b->1.5V, 1b->2.5V (ADC12REFON must be set)
//	 */
//	REF REFMSTR
//	ADC12CTL0 = ADC12ON + ADC12SHT0_8 + ADC12MSC;
//	ADC12CTL0 |= ADC12REFON;
//	ADC12CTL0 &= ~ADC12REF2_5V;  // 0b, ref voltage = 1.5V
//
//	/*
//	 * ADC12SHP      -- sample-and-hold-pulse-mode select (1->SAMPCON sourced from sampling timer)
//	 * ADC12CONSEQ_x -- 2->repeat single channel
//	 */
//	ADC12CTL1 = ADC12SHP+ADC12CONSEQ_2;       // Use sampling timer, set mode
//	ADC12IE = 0x01;                           // Enable ADC12IFG.0
//	ADC12CTL0 |= ADC12ENC;                    // Enable conversions
//	/*
//	 * Enable A/D channel A0 (P6.0)
//	 * If no ports connect to desired A##, then use ADC12MCTLx register (x == ##)
//	 */
//	P6SEL |= 0x01;
//	ADC12MCTL0 =
//	ADC12CTL0 |= ADC12SC;                     // Start conversion
}
void test_adc0()
{
//	// display value
//	prints(results[index]);

}

/*
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=ADC12_VECTOR
__interrupt void ADC12ISR (void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(ADC12_VECTOR))) ADC12ISR (void)
#else
#error Compiler not supported!
#endif
{
//	static unsigned char index = 0;

	switch(__even_in_range(ADC12IV,34))
	{
	case  0: break;                           // Vector  0:  No interrupt
	case  2: break;                           // Vector  2:  ADC overflow
	case  4: break;                           // Vector  4:  ADC timing overflow
	case  6:                                  // Vector  6:  ADC12IFG0
	results[index] = ADC12MEM0;             // Move results
	index++;                                // Increment results index, modulo; Set Breakpoint1 here

	if (index == 8)
	{

//		prints("test ");
		index = 0;
		float n = results[index];
		display_value(&n);
	}
	case  8: break;                           // Vector  8:  ADC12IFG1
	case 10: break;                           // Vector 10:  ADC12IFG2
	case 12: break;                           // Vector 12:  ADC12IFG3
	case 14: break;                           // Vector 14:  ADC12IFG4
	case 16: break;                           // Vector 16:  ADC12IFG5
	case 18: break;                           // Vector 18:  ADC12IFG6
	case 20: break;                           // Vector 20:  ADC12IFG7
	case 22: break;                           // Vector 22:  ADC12IFG8
	case 24: break;                           // Vector 24:  ADC12IFG9
	case 26: break;                           // Vector 26:  ADC12IFG10
	case 28: break;                           // Vector 28:  ADC12IFG11
	case 30: break;                           // Vector 30:  ADC12IFG12
	case 32: break;                           // Vector 32:  ADC12IFG13
	case 34: break;                           // Vector 34:  ADC12IFG14
	default: break;
	}
}
*/
