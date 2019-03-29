.text
.global main
main:
	pushq %rbp
	movq %rsp, %rbp
	movl $12, -4(%rbp)
	movl $4, -8(%rbp)
	movl $4, %eax
	addl -4(%rbp), %eax
	movl %eax, -8(%rbp)
%eax
	movl %eax, -4(%rbp)
	movl -4(%rbp), %eax
	popq %rbp
	ret
