.text
.global main
main:
	pushq %rbp
	movq %rsp, %rbp
	movl $17, -4(%rbp)
	movl $42, -8(%rbp)
	movl -8(%rbp), %edx
	imull -8(%rbp), %edx
	movl -4(%rbp), %eax
	imull -4(%rbp), %eax
	addl %edx, %eax
	addl $1, %eax
	movl %eax, -12(%rbp)
	movl -12(%rbp), %eax
	popq %rbp
	ret
