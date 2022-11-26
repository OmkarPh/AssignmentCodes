assume cs:code, ds:data
data segment
  s1 db "Hello World everyone !!$"
  x db 4
  y db 3
data ends

code segment
assume cs:code, ds:data
begin:
  mov ax, data
  mov ds, ax
  lea dx, s1
  ;mov dx, offset s1

  ; Print
  mov ah, 9
  int 21h


  ; End program
  mov ah,4ch
  int 21h
code ends
end begin
