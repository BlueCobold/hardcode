X: add al,0x13
int 0x10
sub al,cl
out 0x42,al
out 0x61,al
and cl,ch
mov ah,0x0C
loop X