     ; 浜様様様様様様様様様様様様様様様様様様様様様様様融
     ; �     樛樛樛 樛樛�  樛樛樛 樛樛樛 樛� 樛 樛�	�
     ; �     樛� 炳 樛� 栩 樛� 炳 樛� 炳 樛� 栩 栩�	�
     ; �     栩桎   栩桎桀 栩桎 � � 炳樛 栩桎栩 栩�	�
     ; �     栩�    栩� 栩 栩桀栩 栩樛栩 栩� 栩 樛�	�
     ; �			     [productions]	�
     ; 把陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳超
     ; �     "hydra" conference3K 256byte intro compo   �
     ; 把陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳超
     ; �     copyright (c)Y2K-1. by BZS/fresh!		�
     ; 藩様様様様様様様様様様様様様様様様様様様様様様様夕

;nasm version

     org 100h

     align 1

     section .text

Start:
     mov  al,13h
     int  10h
     push word 0A000h
     pop  es
     xor  di,di
     mov  bl,200
LoopY:
     mov  eax,dword [CornerA]
     mov  dword [A],eax
     mov  cx,320
LoopX:
     xor  edx,edx
     mov  dword [X],edx
     mov  dword [Y],edx
     dec  dx
LoopC:
     fld  dword [Y]
     fmul st0,st0
     fstp dword [Temp]
     fld  dword [X]
     fmul st0,st0
     fadd dword [Temp]
     fild word [LoopC+1]
     fcomi st0,st1
     ffree st1
     ffree st0
     jc   Exit
     fld  dword [X]
     fmul st0,st0
     fsub dword [Temp]
     fadd dword [A]
     fstp dword [Temp]
     fld  dword [X]
     fmul dword [Y]
     fadd st0, st0
     fadd dword [CornerB]
     fstp dword [Y]
     mov  eax,dword [Temp]
     mov  dword [X],eax
     dec  dx
     jnz  LoopC
Exit:
     mov  al,dl
     not  al
     stosb
     fld  dword [A]
     fadd dword [Step]
     fstp dword [A]
     loop LoopX
     fld  dword [CornerB]
     fadd dword [Step]
     fstp dword [CornerB]
     dec  bx
     jnz  near LoopY
     push cs
     pop  es
     mov  dx,word About
     mov  ah,9
     int  21h
     mov  di,word Palette
     inc  cx
LoopP0:
     mov  al,cl
     and  al,63
     stosb
     not  al
     stosb
     stosb
     inc  di
     inc  cl
     jnz  LoopP0
NoKeyPress:
     mov  eax,dword [Palette+1016]
     mov  si,word Palette+1012
     mov  di,word Palette+1016
     mov  cl,254
     std
     rep  movsd
     cld
     mov  dword [Palette],eax
     mov  dx,03DAh
;NoRetrace:
;     in   al,dx
;     test al,8
;     jnz  NoRetrace
Retrace:
     in   al,dx
     test al,8
     jz   Retrace
     mov  dl,0C8h
     mov  si,di
     inc  bx
LoopP:
     mov  al,bl
     out  dx,al
     inc  dx
     lodsb
     out  dx,al
     lodsb
     out  dx,al
     lodsb
     out  dx,al
     inc  si
     dec  dx
     inc  bl
     jnz  LoopP
     in   al,60h
     cbw
     dec  ax
     jnz  NoKeyPress
     mov  al,3
     int  10h
     ret

     section .data align=1

CornerA: dd -0.099551
CornerB: dd -0.946521
Step: dd 0.00001
About: db "BZS$"

     section .bss

A: resd 1
X: resd 1
Y: resd 1
Temp: resd 1
Palette: resb 1020
