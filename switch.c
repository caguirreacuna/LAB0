/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */
#include <xc.h>

#define INPUT 1
#define OUTPUT 0

#define ENABLED 1 
#define DISABLED 0

/*void initSwitch1(){
    TRISDbits.TRISD6 = INPUT;
    CNPUDbits.CNPUD6 = ENABLED;
}*/
void initSwitch1(){
    TRISDbits.TRISD6 = 1; //Switch is an input
    CNPUDbits.CNPUD6 = 1; //Enable Pull-up resistor
    CNCONDbits.ON = 1; //Enable overall CN Interrupt CNCONx
    CNENDbits.CNIED6 = 1;//Enable pin CN CNENx
    IFS1bits.CNDIF = 0;//Put down the flag //IFSx
    IPC8bits.CNIP = 7;//Set an interrupt priority //IPCx
    IEC1bits.CNDIE = 1;//Enable interrupt for D pins
}


/* *****************************************************************************
 End of File
 */
