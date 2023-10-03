assume cs:code, ds:data,ss:stack, es:extra 

data segment  
prompt db "Enter string: $" 
sorted db "Sorted string: $" 
strln db "String length: $" 
s1 db 40 dup (?) 

slen db "$$$$$$"
debug db "      debug placeholder$"
newline db 0ah, 0dh, "$" 
data ends

extra segment 
extra ends 

stack segment stack 
stack ends 

code segment  
start: 
mov ax, data 
mov ds,ax 
mov ax, extra 
mov es, ax 


; Ask user for string input 
lea dx,prompt 
mov ah, 09h 
int 21h 

mov cx, 0000h 
lea si, s1 
next: 
  mov ah, 01h 
  int 21h 
  mov [si], al
  inc si 
  inc cl 
  cmp al, 0dh
  jnz next

; Exclude newline ? 
dec cl 
dec si 

; Add $ to end of str 
mov al, 24h
mov [si], al

lea si, slen


; Handle length digits
; Handle max - CL=FF ie. 2^8 -> 256
; 100 - 10 - 1 - done

mov ax, 0000h
mov al, cl
mov dx, 0064h;    64h -> 100

lea di, slen
cmp cl, 00h
jnz digitcalculation

; Handle 0 len
mov al, 30h
mov [di], al
inc di
mov al, 24h
mov [di], al
jmp skipdigitcalc


digitcalculation:
; Digits started or not
mov ch, 00h

lea di, slen
figureoutdecimals:
  div dl
  cmp al, 00h
  jnz putinslen
  cmp ch, 01h
  jnz skipputinslen
  
  putinslen:
  add al, 30h
  mov [di], al
  inc di
  mov ch, 01h

  skipputinslen:
  ; Set remaining number in bx for storing it later in ax
  mov al, ah
  mov ah, 00h
  mov bx, ax

  mov dh, dl
  ; Divide factor from 100->10->1
  mov ah, 00h
  mov al, dl
  mov dl, 0Ah
  div dl
  mov dl, al

  mov ax, bx
  cmp dl, 00h
  jnz figureoutdecimals
breakout:
; mov al, 24h
; mov [di], al
; int 3
skipdigitcalc:

; Show string length 
lea dx, strln 
mov ah,09h
int 21h 
lea dx, slen
mov ah, 09h
int 21h 
call printnewline


lea si, slen
dec cl
jz preventsortforsingle
mov dl, cl
mov dh, cl

; Bubble sort 
mov cl, dl
iterate:
  lea si, s1

  mov ch, dh
  bubble:
    mov al, [si]
    cmp al, [si+1]
    jc skipxchg
    
    ; swap
    xchg al, [si+1]
    mov [si], al

    skipxchg:
    inc si
    dec ch
    jnz bubble
dec cl
dec dh
jnz iterate
preventsortforsingle:

; Show sorted string
lea dx, sorted 
mov ah,09h 
int 21h 

lea dx, s1 
mov ah,09h 
int 21h

call printnewline 
int 3 
; mov ah,4ch 
; int 21h 

printnewline: 
  ; Print newline 
  lea dx, newline 
  mov ah, 09h 
  int 21h 
  ret
code ends  
end start