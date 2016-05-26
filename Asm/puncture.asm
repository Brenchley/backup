   %macro write_string
    mov edx,%2 
    mov ecx,%1
    mov ebx,1
    mov eax,4
    int 80h
   %endmacro

SECTION.txt

global main                    ; must be declared fo linker (id)

 main:                         ; tell linker entry point of code section

   write_string message1,len
   write_string message2,len
   write_string message3,len
   write_string message4,len
   write_string message5,len
   write_string message6,len
   write_string message7,len
   write_string message8,len
   write_string message9,len
   write_string message10,len
   write_string message11,len
   write_string message12,len
   write_string message13,len
   write_string message14,len
   write_string message15,len










 SECTION.data

   message1 db "Hello our esteemed driver how can we help you"
   len1 equ -message1                 ;
   message2 db "Okay which tire is punctured?"
   len2 equ -message2
   message3 db "Go around your car to see which one it is?"
   len3 equ -message3 
   message4 db "You have now identified which tire is deflated. Now go into the boot of your vehicle and remove the jack , wheel spanner , if you have a special nut and the reflectors. "
   len4 equ -message4
   message5 db "Place the reflectors 20 metres behind and infront of the car "
   len4 equ -message5
   message6 db " Now assemble the jack."
   len6 equ -message6
   message7 db " Now go to the deflated tyre."
   len7 equ -message7s
   message8 db " Place the jack under the car and fix it into position so as not to damage the car's body"
   len8 equ -message8
   message9 db " Start pitching the car."
   len9 equ -message9
   message10 db " Remove the nuts holding the tyre in place using the wheel spanner and remove the special nut if it exists."
   len10 equ -message10
   message11 db " Remove the deflated tyre rom it's mountings"
   len11 equ -message11
   message12 db " Go back to the boot with the deflated tyre and replace it with the spare tyre "
   len12 equ -message12
   message13 db " With the spare tyre, place it on the mountings and screw in the bolts and the special nut if it's present."
   len13 equ -message13
   message14 db " Unpitch the car and collect the jack , disassemble it and collect the wheel spanner and place them in the boot."
   len14 equ -message14
   message15 db " Congratulations that's all enjoy!"
   len15 equ -message15









SECTION.bss









