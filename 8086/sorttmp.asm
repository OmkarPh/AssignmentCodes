
mov al, cl
cmp al, 0Ah
jc lessthan10

; More than 10 ---
mov ah, 31h
mov [si], ah
sub al, 0Ah

cmp al, 0Ah
jc lessthan10

; More than 20 ---
mov ah, 32h
mov [si], ah
sub al, 0Ah

lessthan10:
add al, 30h
mov [si+1], al
