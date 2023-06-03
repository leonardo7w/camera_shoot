/**************************************************
 *
 * This file contains an interrupt vector for Cortex-M written in C.
 * The actual interrupt functions must be provided by the application developer.
 *
 * Copyright 2007-2017 IAR Systems AB.
 *
 * $Revision$
 *
 **************************************************/

#pragma language=extended
#pragma segment="CSTACK"

extern void __iar_program_start( void );

extern void NMI_Handler( void );
extern void HardFault_Handler( void );
extern void MemManage_Handler( void );
extern void BusFault_Handler( void );
extern void UsageFault_Handler( void );
extern void SVC_Handler( void );
extern void DebugMon_Handler( void );
extern void PendSV_Handler( void );
extern void SysTick_Handler( void );
/*Specific interrupts*/
extern void TIMER0_Handler( void );
extern void TIMER1A_Handler(void);
extern void TIMER3A_Handler(void);
extern void GPIOF_Handler( void );

typedef void( *intfunc )( void );
typedef union { intfunc __fun; void * __ptr; } intvec_elem;

// The vector table is normally located at address 0.
// When debugging in RAM, it can be located in RAM, aligned to at least 2^6.
// If you need to define interrupt service routines,
// make a copy of this file and include it in your project.
// The name "__vector_table" has special meaning for C-SPY, which
// is where to find the SP start value.
// If vector table is not located at address 0, the user has to initialize
// the  NVIC vector table register (VTOR) before using interrupts.


#pragma location = ".intvec"
const intvec_elem __vector_table[] =
{
  { .__ptr = __sfe( "CSTACK" ) },
  __iar_program_start,

  NMI_Handler,
  HardFault_Handler,
  MemManage_Handler,
  BusFault_Handler,
  UsageFault_Handler,
  0,
  0,
  0,
  0,
  SVC_Handler,
  DebugMon_Handler,
  0,
  PendSV_Handler,
  SysTick_Handler,
  /*---------------Specific interrupts-----------------*/
  0,
  0,//GPIOB_Handler,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  TIMER0_Handler,
  0,
  TIMER1A_Handler,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  GPIOF_Handler,
  0,
  0,
  0,
  0,
  TIMER3A_Handler
};

#pragma call_graph_root = "interrupt"
__weak void NMI_Handler( void ) { while (1) {} }
#pragma call_graph_root = "interrupt"
__weak void HardFault_Handler( void ) { while (1) {} }
#pragma call_graph_root = "interrupt"
__weak void MemManage_Handler( void ) { while (1) {} }
#pragma call_graph_root = "interrupt"
__weak void BusFault_Handler( void ) { while (1) {} }
#pragma call_graph_root = "interrupt"
__weak void UsageFault_Handler( void ) { while (1) {} }
#pragma call_graph_root = "interrupt"
__weak void SVC_Handler( void ) { while (1) {} }
#pragma call_graph_root = "interrupt"
__weak void DebugMon_Handler( void ) { while (1) {} }
#pragma call_graph_root = "interrupt"
__weak void PendSV_Handler( void ) { while (1) {} }
#pragma call_graph_root = "interrupt"
__weak void SysTick_Handler( void ) { while (1) {} }
/*Specific interrupts*/
#pragma call_graph_root = "interrupt"
__weak void TIMER0_Handler( void ) { while (1) {} }
#pragma call_graph_root = "interrupt"
__weak void TIMER1A_Handler( void ) { while (1) {} }
#pragma call_graph_root = "interrupt"
__weak void TIMER3A_Handler( void ) { while (1) {} }
#pragma call_graph_root = "interrupt"
__weak void GPIOF_Handler( void ) { while (1) {} }

void __cmain( void );
__weak void __iar_init_core( void );
__weak void __iar_init_vfp( void );

#pragma required=__vector_table
void __iar_program_start( void )
{
#if __ARM_ISA_THUMB >= 2
  asm("mov32   r0, #0xfef5eda5\n"
#else
#ifndef __NO_LITERAL_POOL__
  asm("ldr     r0, =0xfef5eda5\n"
#else
  asm("movs    r0,     #0xfe\n"
      "lsls    r0, r0, #8\n"
      "adds    r0, r0, #0xf5\n"
      "lsls    r0, r0, #8\n"
      "adds    r0, r0, #0xed\n"
      "lsls    r0, r0, #8\n"
      "adds    r0, r0, #0xa5\n"
#endif
#endif
      "mov     r1, r0\n"
      "push    {r0, r1}\n"
      "mov     r0, sp\n"
      "msr     PSP, r0\n");
  __iar_init_core();
  __iar_init_vfp();
  __cmain();
}
