// SPDX-License-Identifier: GPL-2.0-only

#include <stdio.h>
#include "laniakea_data.h"

void display_mono(display_mono_data display_packet)
    { short display_color
    ; printf("@@--------------++--------------++--------------++--------------++@@\n")
    ; for(int row=0;row<32;row++)
        { printf("%c",(row%4==3)?43:124)
        ; for(int column=0;column<32;column++)
            { display_color=233
            ; for(int bitptr=0;bitptr<5;bitptr++)
                { display_color+=((display_packet.line[row][bitptr]>>(31-column))&1)<<(4-bitptr)
                ; }
              printf("\x1B[48;5;%dm  ",(int)display_color)
            ; }
          printf("\x1B[0m %c\n",(row%4==3)?43:124)
        ; }
      printf("@@--------------++--------------++--------------++--------------++@@\n")
    ; return
    ; }
