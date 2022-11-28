assume cs:code, ds:data, ss:stack
data segment
  ; Add -
  ;        9A23 FC23
  ;        F132 C28F
  ;  1C 8B56 BEB2
  result dd ?
  carry db 00h
  auxcarry db 00h
data ends
stack segment stack
stack ends
code segment
start:
  mov ax, data
  mov ds, ax
  
  mov si, 0010h
  mov [si+8], 1111h
  mov [si+10], 1111h
  ; mov [si], 1111h
  ; mov [si+2], 1111h
  mov ax, [si]
  mov bx, [si+4]
  mov cx, [si+2]
  mov dx, [si+6]
  
  add bx, ax
  jc set_aux_carry
  set_aux_carry:
    mov auxcarry, 0FFh

  adc cx, dx
  jc set_carry
  set_carry:
    mov carry, 0FFh

  mov ax, cx

  mov word ptr result, ax
  mov word ptr result+2, bx
  mov [si+8], ax
  mov [si+10], bx

  int 3
code ends
end start

