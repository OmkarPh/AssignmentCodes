data segment
        a dw 4121h
        b dw 1742h
        ;c dw ?
 data ends
 code segment
        assume cs:code, ds:data
        start:
        mov ax,data
        mov ds,ax
        mov ax,a
        mov bx,b
        add ax,bx
        mov dx, ax
        ;mov cx,ax
        ;mov c,cx
        ;int 3
        

        ; Print
        mov ah, 9
        int 21h


        ; End program
        mov ah,4ch
        int 21h
 code ends
 end start 