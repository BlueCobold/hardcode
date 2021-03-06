%define	width 320
%define	height 200
%define	states 65
		org   100h
		pop cx
		les di,[bx]
		mov al,0x13
		int 0x10
		mov ds,di
		inc byte [height / 2 * width + width / 2 + 16]
NextPixel:	
		mov al,[di]
		or al, al
		jz Check
		inc ax
Check:		
		mov dl,	[di+1]
		add dl,	[di-1]
		mov bx,width-1
		call prog		
		neg bx
		call prog
		dec dl
		jnz CheckEnd
re:		inc ax
CheckEnd:	
		test al,0x40
		jnz re
SetNext:	
		stosb
		loop NextPixel
		push ds
		push es
		pop ds
		pop es
		jmp short NextPixel
prog:
		add dl,[bx+di]
		inc bx
		add dl,[bx+di]
		inc bx
		add dl,[bx+di]
ret