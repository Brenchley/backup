section .text
	global main ;must be declared for linker (ld)
main: ;tell linker entry point
;writing the name 'Nyaga Susan'
mov edx,11; message length
mov ecx, name ;message to write
mov ebx,1;file descriptor (stdout)
mov eax, 4 ;system call number (sys_write)
int 0x80 ;call kernel
mov [name], dword 'Wanja' ; Changed the name to Wanja Susan

;writing the name 'Wanja Susan'
mov edx,11 ;message length
mov ecx,name ;message to write
mov ebx,1 ;file descriptor (stdout)
mov eax,4 ;system call number (sys_write)
int 0x80 ;call kernel
mov eax,1 ;system call number (sys_exit)
int 0x80 ;call kernel

section .data
name db 'Nyaga Susan' ;
;