.text
.global main

main:
	pushq %rbp
	movq %rsp, %rbp
	movl $3, -8(%rbp)
	movl -8(%rbp), %eax
	movl %eax, -4(%rbp)
	movl $2, -12(%rbp)
	movl -4(%rbp), %eax
	cmpl -12(%rbp), %eax
	sete %al
	movzbl %al, %eax
	movl %eax, -16(%rbp)
	cmpl $0, -16(%rbp)
	je main_bb_3
	jne main_bb_1

main_bb_1:
	movl $1, -20(%rbp)
	movl -4(%rbp), %eax
	addl -20(%rbp), %eax
	movl %eax, -24(%rbp)
	movl -24(%rbp), %eax
	movl %eax, -4(%rbp)
	jmp main_bb_2

main_bb_2:
	movl $2, -36(%rbp)
	movl -4(%rbp), %eax
	cmpl -36(%rbp), %eax
	sete %al
	movzbl %al, %eax
	movl %eax, -40(%rbp)
	cmpl $0, -40(%rbp)
	je main_bb_5
	jne main_bb_4

main_bb_3:
	movl $1, -28(%rbp)
	movl -4(%rbp), %eax
	subl -28(%rbp), %eax
	movl %eax, -32(%rbp)
	movl -32(%rbp), %eax
	movl %eax, -4(%rbp)
	jmp main_bb_2

main_bb_4:
	movl $1, -44(%rbp)
	movl -44(%rbp), %eax
	movl %eax, -4(%rbp)
	jmp main_bb_5

main_bb_5:
	movl -4(%rbp), %eax
	popq %rbp
	ret
