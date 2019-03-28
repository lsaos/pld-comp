.text
.global main
main:
	pushq %rbp
	movq %rsp, %rbp
	movl $17, -4(%rbp)
	movl $42, -8(%rbp)
	movl %eax, -12(%rbp)
	movl -12(%rbp), %eax
	popq %rbp
	ret
