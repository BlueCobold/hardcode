MASM 
Comment *

         Copyright code uk copyright 1993 - Phil Carlisle....

   浜様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
   � Standard Dos Header file, for setting up for tasm.....                �
   藩様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

    Version 0.1a    Revision                Author - Phil Carlisle

    Uses standard dos segment names
    Uses Large Model (shouldn't make a difference)
    Sets up a 512 byte stack (should be enuff)
    Assume's Cs:@code Ds@data
    Errrm, yeah, sets it to 386 code
    And leaves us in Ideal (tasm) mode assembly
    様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様
*
    IDEAL                                 ;set ideal (tasm syntax)
    DOSSEG                                ;use dos standard segment names
    MODEL HUGE                            ;use large mem model (no reason)
    P386N                                 ;386 instructions
    STACK 200h                            ;512 byte stack
    LOCALS                                ;enables local labels (@@label:)
    ASSUME  CS:@CODE, DS:@DATA            ;standard assumes....


