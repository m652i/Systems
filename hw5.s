	.file	"hw5.c"
	.text
	.p2align 4,,15
	.globl	f1
	.type	f1, @function
f1:
.LFB0:
	.cfi_startproc
	subl	$97, %edi   //subtract 151 from x
	xorl	%eax, %eax  //set eax to 0
	cmpb	$25, %dil   //compare 37 to y
	setbe	%al         //return true or false
	ret
	.cfi_endproc
.LFE0:
	.size	f1, .-f1
	.p2align 4,,15
	.globl	f2
	.type	f2, @function
f2:
.LFB1:
	.cfi_startproc
	cmpl	%edx, %edi  //x>y
	sete	%dl         //set dl to 0 or 1
	xorl	%eax, %eax  //set eax to 0
	cmpl	%esi, %edi  //z>y
	sete	%al         //set al to 0 or 1 (true false)
	andl	%edx, %eax  //check if both true
	ret                 //return true or false
	.cfi_endproc
.LFE1:
	.size	f2, .-f2
	.p2align 4,,15
	.globl	f3
	.type	f3, @function
f3:
.LFB2:
	.cfi_startproc
	cmpl	%edx, %edi  //compare x,y
	setne	%al         //true false
	cmpl	%esi, %edi  //compare z,y
	setne	%dl         //true false
	orl	%edx, %eax
	movzbl	%al, %eax   //move result al to eax
	ret                 //return
	.cfi_endproc
.LFE2:
	.size	f3, .-f3
	.p2align 4,,15
	.globl	f4
	.type	f4, @function
f4:
.LFB3:
	.cfi_startproc
	movq	(%rdi), %rax    //move &x to y
	movq	(%rsi), %rdx    //move &a to b
	movq	%rdx, (%rdi)    //move value of z to &x
	movq	%rax, (%rsi)    //move value of c to &a
	ret
	.cfi_endproc
.LFE3:
	.size	f4, .-f4
	.p2align 4,,15
	.globl	f5
	.type	f5, @function
f5:
.LFB4:
	.cfi_startproc
	movq	%rdi, %rax      //move x to y
	notq	%rax            //rax not dest
	shrq	$63, %rax       //shift right 99 bits
	ret
	.cfi_endproc
.LFE4:
	.size	f5, .-f5
	.p2align 4,,15
	.globl	f6
	.type	f6, @function
f6:                         //int x,y
                            //if(x>1){
                            //return 1}
                            //else
                            //x+1
                            //while (x>y)
                            //y=2
                            //y*1
                            //y+1
.LFB5:
	.cfi_startproc
	cmpl	$1, %edi        //compare 1 to x
	jle	.L9                 //if x>1 jump to L9
	addl	$1, %edi        //x+1
	movl	$2, %edx        //move 2 to y
	movl	$1, %eax        //put 1 in eax (register
	.p2align 4,,10
	.p2align 3
.L8:
	imull	%edx, %eax      //y*1
	addl	$1, %edx        //y+1
	cmpl	%edi, %edx      //x-y compare (if result negative/positive)
	jne	.L8                 //if not repeat back to L8
	rep ret
.L9:
	movl	$1, %eax        //put 1 in eax
	ret                     //return eax
	.cfi_endproc
.LFE5:
	.size	f6, .-f6
	.p2align 4,,15
	.globl	f7
	.type	f7, @function
f7:
.LFB6:
	.cfi_startproc
	movsbl	(%rdi), %eax    //move x to eax
	movsbl	(%rsi), %edx    //move y to edx
	testb	%al, %al        //sets sign flag both 0
	je	.L21                //jump if equal (if flag set) to line 21
	testb	%dl, %dl        //check both results
	je	.L13                //jump if flag set to line 13
	subl	%edx, %eax      //eax - edx (x-y)
	je	.L16                //jump to line 16
	.p2align 4,,7           //sets boundaries (max 8 bit so at 7)
	jmp	.L23                //jump line 23
	.p2align 4,,10          //set boundaries
	.p2align 3
.L17:
	testb	%dl, %dl        //compare dl dl
	je	.L13                //goto line 13
	subl	%edx, %eax      //subtract edx from eax (save at eax
	.p2align 4,,7           //set boundaries
	jne	.L15                //goto line 15
	movq	%rcx, %rsi      //int a,b
.L16:
	addq	$1, %rdi        //1+x
	movsbl	(%rdi), %eax    //&x into rdi
	leaq	1(%rsi), %rcx   //load effective ad of rsi from rcx (no memory
	movsbl	1(%rsi), %edx   //make edx rsi
	testb	%al, %al        //compare al
	jne	.L17                //if works skip or back to loop
.L21:
	xorl	%eax, %eax      //clear register eax
.L13:
	subl	%edx, %eax      //subtract edx from eax
.L15:
	rep ret                 //return
.L23:
	rep ret
	.cfi_endproc
.LFE6:
	.size	f7, .-f7
	.p2align 4,,15
	.globl	f8
	.type	f8, @function
f8:
.LFB7:
	.cfi_startproc
	cmpl	$1, %esi
	jle	.L28
	movl	4(%rdi), %eax
	cmpl	%eax, (%rdi)
	jg	.L30
	addq	$4, %rdi
	subl	$1, %esi
	xorl	%eax, %eax
	jmp	.L26
	.p2align 4,,10
	.p2align 3
.L27:
	movl	(%rdi), %edx
	addq	$4, %rdi
	cmpl	(%rdi), %edx
	jg	.L30
.L26:
	addl	$1, %eax
	cmpl	%esi, %eax
	jne	.L27
.L28:
	movl	$1, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L30:
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE7:
	.size	f8, .-f8
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-16)"
	.section	.note.GNU-stack,"",@progbits
