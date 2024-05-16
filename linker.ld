
ENTRY(reset_handler)

/*Stack starts at the top ORIGIN + LENGTH of SRAM*/
_estack = 0x20017700;

MEMORY
 {
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 512K
    RAM(rxw) : ORIGIN = 0x20000000, LENGTH = 96K
 }

SECTIONS
{
  /* The vector table goes at the start of flash. */
  .vector_table :
  {
    . = ALIGN(4);
    KEEP (*(.vector_table))
    . = ALIGN(4);
  } >FLASH

  /* The reset should be the next thing in the flash. */
  .reset_handler :
  {
    . = ALIGN(4);
    KEEP (*(.reset_handler))
    . = ALIGN(4);
  } >FLASH

  /* The 'text' section contains the main program code. */
  .text :
  {
    . = ALIGN(4);
    *(.text)
    *(.text*)
    . = ALIGN(4);
    _etext = .;
  } >FLASH

   .data :
  {
    . = ALIGN(4);
    /* Mark start/end locations for the 'data' section. */
    _sdata = .;
    *(.data)
    *(.data*)
    . = ALIGN(4);
    _edata = .;
  
  } >RAM AT > FLASH

  bss :
  {
    . = ALIGN(4);
    /* Also mark the start/end of the BSS section. */
    _sbss = .;
    *(.bss)
    *(.bss*)
    *(COMMON)
    . = ALIGN(4);
    _ebss = .;
  } >RAM


  /* The 'rodata' section contains read-only data,
   * constants, strings, information that won't change. */
  .rodata :
  {
    . = ALIGN(4);
    *(.rodata)
    *(.rodata*)
    . = ALIGN(4);
  } >FLASH

}