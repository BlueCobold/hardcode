; Meteors by Karak/MovSD, 256B intro, ??. na Fiasku'98 �
;�������������������������������������������������������
;Tak jsem v patek v noci, tesne pred Fiaskem zacal neco delat, skoncil
;jsem v sobotu (tesne po pulnoci) a takhle to dopadlo :-). Ohlasy
;muzete psat na Karak@bbs.infima.cz. Podekovani patri Redoxovi,
;ten me k tomu dokopal :). Diky.
;
.486
karak segment use16
assume es:karak, cs:karak, ss:karak, ds:karak

org 100h

kod:
jmp hop
credits db "  Meteors by Karak/MovSD, Fiasko'98   "
hop:

 mov ax,ds
 add ax,40   ;Segment pro virtualni obrazovku v 16byte paragrafech, pri
 mov ds,ax   ;spusteni com se pro nej automaticky alokuje 64Kb. Kod ma 256
             ;byte (16 paragrafu) a zacina na 100h (take 16p). Dohromady
             ;tedy musim pricist min. 32p. O zasobnik si starosti nedelam,
             ;ten je az nekde na FFFF.

 push 0a000h ;Segment videopameti
 pop es

 mov ax,13h  ;Nastaveni videomodu
 int 10h

 call setpal ;Nastaveni palety


;---------------------------main
main: xor si,si
      mov dx,200

 l1: mov cx,320

  l2: xor ah,ah
       xor bh,bh
       mov al,ds:[si-1-9]
       mov bl,ds:[si+320-9]
       add ax,bx
       mov bl,ds:[si-320-9]
       add ax,bx
       mov bl,ds:[si+1-9]
       add ax,bx
       shr ax,2               ;Zprumeruji 4 vysledky
       dec al
       mov ds:[si],al
       inc si
      loop l2

      dec dx
     jnz l1
;---------------------------
      xor si,si
      mov dx,200

 _l1: mov cx,320

  _l2: xor ah,ah
       xor bh,bh
       mov al,ds:[si-1]
       mov bl,ds:[si+320]
       add ax,bx
       mov bl,ds:[si-320]
       add ax,bx
       mov bl,ds:[si+1]
       add ax,bx
       shr ax,2               ;Zprumeruji 4 vysledky
       mov ds:[si],al
       inc si
      loop _l2

      dec dx
     jnz _l1
;---------------------------

 call wait_r
 call wait_r
 call wait_r ;To je ale krasna prasarna :-), ale nebudu prece davat
             ;256B intro na timer.

 push 5*320  ;Priprava na flipnuti z virtualni obrazovky do vram,
 pop di      ;zacnu od 5. radky.
 mov si,di

 mov cx,30400
 rep movsw


 mov ah,01h  ;Jestlize byla, nebo je stisknuta klavesa naztavi zf=0
 int 16h
 jz main

 mov ah,10h  ;Vybere klavesu z bufferu a scankod ulozi do ah
 int 16h

 cmp ah,1    ;Jestlize neni scankod 1 (esc) pokracuje v programu
 jnz main
;---------------------------end main

 mov ax,3    ;Nastaveni textoveho modu
 int 10h
retn

;Nastaveni palety
setpal proc near
 mov dx,3c8h
 xor ax,ax
 out dx,al

 inc dx
 xor cx,cx
_p1: mov al,cl
     shr al,2
     out dx,al

     xor al,al
     out dx,al

     mov al,cl
     shr al,1
     out dx,al

     inc cl
     cmp cl,127
    jnz _p1

 inc cl
_p2: mov al,ah
     shr al,2
     add al,32
     out dx,al

     mov al,ah
     shr al,1
     out dx,al

     mov al,63
     out dx,al
     inc ah
    loop _p2
retn
endp

;Cekani na paprsek
wait_r proc near
 mov  dx,3dah                                     
@1: in   al,dx                                                
    test al,8                                                 
   jz   @1                                                  
@2: in   al,dx                                                
    test al,8                                                 
   jnz  @2
retn
endp

karak ends
end kod