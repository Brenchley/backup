%macro printmsg 2;
mov eax,4
mov ebx,1
mov ecx,%1
mov edx,%2
int 0x80
%endmacro

%macro readinput 2;
mov eax,3
mov ebx,2
mov ecx,%1
mov edx,%2
int 0x80
%endmacro

section .data
msg1 db "Move the car to the side of the road.",10 ,"Place life-saver triangles or Twigs 10 meters at the front and rear of the car.",10, "Press 0 to continue:",10
len1 equ $-msg1

msg2 db "Do you have necessary tools to change the tyre.",10 ,"Press 1 if YES or find the tools. Press 0 to continue:",10
len2 equ $-msg2 

msg3 db "Check the condition of the spare tyre.",10 ,"If GOOD press 1 else find a good tyre. Press 0 to continue:",10
len3 equ $-msg3

msg4 db "Using jack lift the side of the car with flat tyre",10 ,"And un-screw the nuts using a spanner.",10 ," Remove flat tyre. Press 0 to continue:",10
len4 equ $-msg4

msg5 db "Place spare tyre into position and screw the nuts using spanner.",10 ," Use jack to lower the car. Press 0 to continue:",10
len5 equ $-msg5

msg6 db "Return tools in place clear the road of life-saver triangles or twigs.",10 ," Press 0 to continue.",10
len6 equ $-msg6

msg7 db "Thank you for using Badilisha Mguu service.",10	
len7 equ $-msg7


section .bss

input resb 1
len resb 1

section .text
	global main
main:

printmsg msg1, len1 ;
readinput input, len

printmsg msg2, len2 ;
readinput input, len


printmsg msg3, len3 ;
readinput input, len


printmsg msg4, len4 ;
readinput input, len


printmsg msg5, len5 ;
readinput input, len


printmsg msg6, len6 ;
readinput input, len


printmsg msg7, len7 ;
readinput input, len





