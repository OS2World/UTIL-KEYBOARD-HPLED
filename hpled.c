/* hpled */

#include "os2def.h"
#include "string.h"

#include "stdio.h"

APIRET16 APIENTRY16 RPORT(USHORT);
void APIENTRY16 WPORT(USHORT,USHORT);
APIRET16 APIENTRY16 DosPortAccess(USHORT,USHORT,USHORT,USHORT);

int main( int argc, char *argv[] )
{
   int base,value,rc;
   /* I/O access from 000h to FFFh */
   base=0x60;
   value=0;
   rc=DosPortAccess(0,0,0x000,0xFFF);
   if (rc) printf("DosPortAccess()=%d\n",rc);
   if (argc==1) {
    printf ("HP SK-2505 keyboard \"messages\" LED switcher\n");
    printf (" usage: hpled.exe <command>, where command can be \"on\", \"off\" and \"kbdlock\" \n");
    return(0);
    }
   if (strcmp(argv[1],"on")==0) value=0xeb;
   if (strcmp(argv[1],"off")==0) value=0xec;
   if (strcmp(argv[1],"kbdlock")==0) value=0xed;
   if (value!=0) {WPORT(base,value); printf("Done\n");}
   else {printf("Uknown command!\n");return(1);}
   return(0);
}

