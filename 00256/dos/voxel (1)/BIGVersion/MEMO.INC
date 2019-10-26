;�������������������������������������������
;���  Ajusta, prepara y pide memoria
;���  para las pantallas virtuales.
;�������������������������������������������
Memoria PROC
        ;�������������������������������������������
        ;���    Ajusta la memoria asignada al programa
        ;�������������������������������������������
        MOV BX,300                      ;��� Reserva 256*16 = 4 Kb
        MOV AH,4Ah                      ;��� Modifica el tama�o del bloque reservado
        INT 21h                         ;��� al segmento indicado en ES.Ahora ES = Seg.Programa
        PUSH CS                         ;��� DS = Segmento de datos
        POP  DS

        ;�������������������������������������������
        ;���    Pide memoria para guardar imagen 1
        ;�������������������������������������������
        MOV BX,8096                     ;��� N�mero de p�rrafos. 64k/16 bytes por p�rrafo
        MOV AH,48h
        INT 21h                         ;��� Reserva memoria
        MOV WORD PTR [SegImagen],AX

        RET
Memoria ENDP