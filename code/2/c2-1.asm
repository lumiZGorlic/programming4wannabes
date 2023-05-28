	
;$ nasm -f elf64 -o c2-1.o c2-1.asm
;$ ld -o c2-0s c2-1.o
;$ ./c2-0s; echo $?

    global _start
_start:	mov rdi, 10
	mov rbx, 20

	add rdi,rbx

	mov rax, 0x3c
	syscall
