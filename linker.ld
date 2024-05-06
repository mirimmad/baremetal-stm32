
/*Stack starts at the top ORIGIN + LENGTH of SRAM*/

_estack = 0x20017700;

MEMORY
 {
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 512K
    RAM(rxw) : ORIGIN = 0x20000000, LENGTH = 96K
 }
