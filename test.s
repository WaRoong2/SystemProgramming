	.file	"test.c"
.globl a
	.data
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.long	10
.globl b
	.align 4
	.type	b, @object
	.size	b, 4
b:
	.long	20
	.section	.rodata
.LC0:
	.string	"C = %d\n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	andl	$-16, %esp
	movl	$0, %eax
	addl	$15, %eax
	addl	$15, %eax
	shrl	$4, %eax
	sall	$4, %eax
	subl	%eax, %esp
	movl	b, %eax
	addl	a, %eax
	movl	%eax, c
	subl	$8, %esp
	pushl	c
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	leave
	ret
	.size	main, .-main
	.comm	c,4,4
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.4.6 (Ubuntu 3.4.6-6ubuntu2)"
