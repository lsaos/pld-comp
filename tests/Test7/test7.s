.text
.global main

main:
	pushq %rbp
	movq %rsp, %rbp
	movl $2, -8(%rbp)
	movl -4(%rbp), %eax
	addl -8(%rbp), %eax
	movl %eax, -12(%rbp)
	movl -12(%rbp), %eax
	popq %rbp
	ret
