assume cs:code, ds:data, es:extra, ss:stack
data segment
  abc dw 1324h
data ends
extra segment
  fsd dw 9999h
extra ends
stack segment stack
stack ends
code segment
  start:
  mov ax, data
  mov ds, ax
  mov ax, extra
  mov es, ax
  
  mov si, 1000h
  mov di, 1050h
  mov cl, 5
  
  iteration:
    mov ax, [si]
    mov es:[di], ax
    inc si
    inc si
    inc di
    inc di
    dec cl
    jnz iteration
  
  int 3
code ends
end start

