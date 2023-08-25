section .data
	hello db "Hello, Holberton", 0
	newline db 10, 0	; New line character

section .text
	global main
	extern printf

main:
	sub rsp, 8		; Align the stack
	mov rdi, hello		; Load address of the hello string
	call printf		; Call printf function

	mov rdi, newline	; Load address of the newline character
	call printf		; Call printf function to print the new line

	add rsp, 8		; Restore the stack
	ret
