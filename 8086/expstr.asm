assume cs:code, ds:data, ss:stack

data segment 
prompt db "enter first string: $"
prompt2 db "enter second string: $"
s1 db 20 dup (?)
s2 db 20 dup (?)
issame db "Both strings are equal $"
isnotsame db "Both strings are not equal $"
data ends

stack segment stack
stack ends

code segment 
start:
mov ax,data
mov ds,ax


lea dx,prompt
mov ah, 09h
int 21h

mov cl, 00h
lea si,s1
next:
  mov ah, 01h
  int 21h
  mov [si],al
  inc si
  inc cl
  cmp al, 0dh
  jnz next


lea dx,prompt2
mov ah, 09h
int 21h

mov ch, 00h
lea si,s2
next2:
  mov ah, 01h
  int 21h
  mov [si],al
  inc si
  inc ch
  cmp al, 0dh
  jnz next2

cmp cl, ch
jnz notequalstrings

lea si,s1
lea di,s2
loopthru:
  ; individual character
  mov bl, [si]
  ; mov al, [di]

  cmp bl, [di]
  ; cmp bl, al
  jnz notequalstrings
  inc si
  inc di

  dec cl
jnz loopthru

equalstrings:
  lea dx, issame
  mov ah, 09h
  int 21h
  jmp gotoend

notequalstrings:
  lea dx, isnotsame
  mov ah, 09h
  int 21h

gotoend:
  mov ah,4ch
  int 21h

code ends 
end start