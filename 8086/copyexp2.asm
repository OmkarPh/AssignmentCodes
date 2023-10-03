assume cs:code, ds:data, ss:stack
data segment
data ends
stack segment stack
stack ends
code segment
  start:
  mov ax, data
  mov ds, ax
  
  mov si, 1000h
  mov di, 1050h
  mov cl, 5
  
  iteration:
    mov ax, [si]
    mov [di], ax
    inc si
    inc si
    inc di
    inc di
    dec cl
    jnz iteration
  
  int 3
code ends
end start

