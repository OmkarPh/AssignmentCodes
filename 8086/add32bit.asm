assume cs:code, ds:data, ss:stack
data segment
  ; Add -
  ;        9A23 FC23
  ;        F132 C28F
  ;  1C 8B56 BEB2
  num1 dd 09A23FC23h;
  num2 dd 0F132C28Fh;
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

  mov ax, word ptr num1
  mov bx, word ptr num2
  mov cx, word ptr num1+2
  mov dx, word ptr num2+2
  
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

  int 3
code ends
end start