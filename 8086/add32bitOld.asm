assume cs:code, ds:data, ss:stack
data segment
  ; Add -
  ;        9A23 FC23
  ;        F132 C28F
  ;  1C 8B56 BEB2
  H1 dw 09A23h
  L1 dw 0FC23h
  H2 dw 0F132h
  L2 dw 0C28Fh

  result dd ?
  carry db 00h
  auxcarry db 00h
  
  identifier db 0CCh
data ends
stack segment stack
stack ends
code segment
start:
  mov ax, data
  mov ds, ax

  mov ax, L1
  mov bx, L2
  mov cx, H1
  mov dx, H2
  
  ; add bx, ax
  add bx, L1
  jc set_aux_carry
  set_aux_carry:
    mov auxcarry, 0FFh

  ;adc cx, dx
  adc cx, H2
  jc set_carry
  set_carry:
    mov carry, 0FFh

  mov ax, cx

  mov word ptr result, ax
  mov word ptr result+2, bx

  int 3
code ends
end start