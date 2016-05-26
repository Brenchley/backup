SYS_EXIT equ 1
SYS_READ equ 3
SYS_WRITE equ 4
STDIN equ 0
STDOUT equ 1

segment.data
	msg1 db "ENter a digit ", 0xA,0xD
	len1 equ $-msg1
	msg2 db "Please enter a second digit",0xA,0xD
	len2 equ equ $-msg2
	msg3 db "This sum is:"
	len3 equ $-msg3



segment.bss
	num1 resb 2
	num2 resb 2
	res resb 1
segment.text
	global main ; must be declared for using gcc

main: ;tell linker entry point
	mov eax, SYS_WRITE
	mov ebx, STDOUT
	mov ecx, msg1
	mov edx, len1
	int 0x80
	mov eax, SYS_READ
	mov ebx, STDIN
	mov ecx, num1
	mov edx, 2
	int 0x80

	mov eax, SYS_WRITE
	mov ebx, STDOUT
	mov ecx, msg2
	mov edx, len2
	int 0x80

	mov eax, SYS_READ
	mov ebx, STDIN
	mov ecx, num2


	mov edx, 2
	int 0x80
	mov eax, SYS_WRITE
	mov ebx, STDOUT
	mov ecx, msg3
	mov edx, len3
	int 0x80

	; moving the first nuber to eax register and second to ebx
	;and subtractin ascii '0' to convert it into a decimal number

	mov eax [number1] ; check if this generates an error and correct by looking at the data section
	sub eax, '0'

	mov ebx, [number2] ; do as above for an error;
	sub ebx, '0' ; add eax and ebx
	add eax, ebx ; add '0' to to convert the sum from decimal to ASCII
	add eax, '0' ; storing the sum in memory location res
	mov [res], eax ; print the sum
	mov eax, SYS_WRITE
	mov ebx, STDOUT
	mov ecx, res
	mov edx, 1
	int 0x80
exit:
	mov eax, SYS_EXIT
	xor ebx, ebx

	int 0x80
	; run the program and explain what it does


