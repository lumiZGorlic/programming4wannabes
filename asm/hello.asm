	global _start
_start: mov rax, 1    ; SYS_write = 1

;    push 1111111111

	mov rdi, 1    ; fd = 1
	mov rsi, msg  ; buf = msg 
	mov rdx, 13   ; count = 13 (the number of bytes to write)
	syscall  ; (SYS_write = rax(1), fd = rdi (1), buf = rsi (msg), count = rdx (13))  

	;;  Exit program
	mov rax, 0x3c  ; SYS_exit = 0x3c
	mov rdi, 0     ; status = 0
	syscall ; (SYS_exit = rax (0x3c), status = rdi (0))

msg:	db 'Hello World!',0x0a
