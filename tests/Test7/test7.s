.text
.global main

main:
	pushq %rbp
	movq %rsp, %rbp
	movl $3, -8(%rbp)
	movl -8(%rbp), %eax
	movl %eax, -4(%rbp)
	movl -4(%rbp), %eax
	popq %rbp
	ret
