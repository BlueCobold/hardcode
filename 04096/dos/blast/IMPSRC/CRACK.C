/*
컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
                                                                          �
      複�  複� 複�  複� 複� 複� 複�  複� 複複複複 複�     複� 複�  複�    �
      栢�  栢� 栢栢蔔栢 栢� 栢� 栢栢蔔栢 栢�  栢� 栢�     栢� 栢栢蔔栢    |
      栢�  栢� 栢� 賞栢 栢� 栢� 栢� 賞栢 栢�  栢� 栢�     栢� 栢� 賞栢    �
      栢�  栢� 栢�  栢� 栢幡白� 栢�  栢� 栢�  栢� 栢�     栢� 栢�  栢�    �
      栢�  栢� 栢�  栢� 栢� 栢� 栢�  栢� 栢�  栢� 栢�     栢� 栢�  栢�    �
      栢�  栢� 栢�  栢� 栢� 栢� 栢�  栢� 栢�  栢� 栢�  �  栢� 栢�  栢�    �
      栢�  栢� 栢�  栢� 栢� 栢� 栢�  栢� 栢�  栢� 栢白幡白栢� 栢�  栢�    �
      賽賽賽賽 賽�  賽� 賽� 賽� 賽�  賽� 賽賽賽賽 賽賽   賽賽 賽�  賽�    �
                                                                          �
      갚갚굉꾼白複複複複                             複複複複蔔昉껑굅굅   �
                       賽三꾼複複複       複複複昉꿉賽                    �
       같갚� 같같   겨複                              複丙   같같 굇같�   �
� � 캅같굇껑같같�   査百   갚굅같 � � 컴� � 解같굇�   査百   같같갚껑굅같켸
     三굇께旁같같�   같�  갛栢旁              글栢껐  같�   같같갚昉껑굉�
          三께丙같같같� 겨栢꿉                  三栢丙 같같같같兵께�
              薩굅같굇굉栢賽                      賽栢껑굇같갚긋

                         旼컴컴컴컴컴컴컴컴컴컴컴컴커
                         � UNKNOWN PRODUCTIONS NTM. �
                         �    (Not a TradeMark)     �
                         읕컴컴컴컴컴컴컴컴컴컴컴컴켸   

                               by Jcl of Unknown

        This is my contribution to the Imphobia #11 - CodeGems #5 compo.

        It creates an EXE (yep, not COM) of 56 bytes that put the words
        "ImphobiaCoderCompo" in the screen.
        Please note that the compo was made in December 1995, but I read
        it yesterday!
        See the compo rules in the file COMPO.RLZ included in the package.


        Notes:
              - It can be 4 bytes less if I don't exit to DOS (the
              instructions "mov ah,4Ch" and "int 21h" are quite big.
              - It can be just 30 bytes as a COM, but the compo
              rules said it MUST be an EXE.
              - The complete listing for TASM is available in IMP.ASM
              - The instructions are from a COM file I generated with
              IMP.ASM, then I faked an EXE header so it didn't have
              relocations, etc...
              - If you compile IMP.ASM to an EXE it will not work, bcoz
              the offset of the string is not accurate and it will be
              about 80h bytes before (I think if I quit the "ORG 100h"
              directive it will be fixed... but who cares?)


        Well, if ya wanna contact me, do it!

                Snail-Mail:
                        Javier Campos Laencina
                           C/Bolos, 1, 3-A
                            30005, Murcia
                                Spain

                Phone:
                        +34-68-298639 (Outta Spain)
                         (968) 298639 (From Spain)

                e-Mail:
                        laencina@lander.es



                   This was an Unknown production in 1996

컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
*/

#include <dos.h>
#include <stdlib.h>

typedef unsigned char byte;

/*
        The header of the Exe, modified to change the entry point, so that
        the instructions can be put at offset 26, instead of 512 (flushed
        out relocation tables, changed number of paragraphs and the initial
        CS:IP). Starts with the two characters 'MZ'.
*/
byte exe_header[26]={
	77,90,56,0,1,0,0,0,1,0,0,0,255,255,0,0,0,0,0,0,
	10,0,0,0,62,0
};

/*
        A COM file containing the instructions and the data in the same
        segment. This array is the same as linking IMP.ASM with the TLINK
        /t option. It will generate a 30bytes COM file containing all this.
*/
byte program_instructions[30]={
        186,0x15,0x01    // mov dx,[115h]  (This comes from LEA DX,[String])
        180, 0x9,        // mov ah,9h
        205,0x21,        // int 21h
        180,0x4C,        // mov ah,4Ch
        205,0x21,        // int 21h

        73,109,112,104,111,98,105,97,67,       //The String is at offset 115h
        111,100,101,114,67,111,109,112,111,36  //inside the program, taking
                                               //in account the initial CS:IP
                                               //and the Entry Point in the
                                               //EXE header. Also, take notice
                                               //of that the program is at
                                               //100h due to the "ORG 100h"
                                               //TASM directive.
                                               //The string is finished with
                                               //a '$' character (24h=36d)
};


// Now, let's create our 56 bytes long EXE file
void main(void) {
	int handle;
	int error;

        error=_dos_creat("COMPO.EXE", _A_NORMAL, &handle); // Create a new file
        if(error!=0) exit(1);                              // called COMPO.EXE

        _dos_write(handle,exe_header,26,NULL);             // Write the header

        _dos_write(handle,program_instructions,30,NULL);   // Write the program
                                                           // itself

        _dos_close(handle);                                // And close the file
}
