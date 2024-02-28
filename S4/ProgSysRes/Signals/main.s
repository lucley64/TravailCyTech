	.file	"main.c"
# GNU C17 (Ubuntu 9.4.0-1ubuntu1~20.04.2) version 9.4.0 (x86_64-linux-gnu)
#	compiled by GNU C version 9.4.0, GMP version 6.2.0, MPFR version 4.0.2, MPC version 1.1.0, isl version isl-0.22.1-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -imultiarch x86_64-linux-gnu main.c -mtune=generic
# -march=x86-64 -fverbose-asm -fasynchronous-unwind-tables
# -fstack-protector-strong -Wformat -Wformat-security
# -fstack-clash-protection -fcf-protection
# options enabled:  -fPIC -fPIE -faggressive-loop-optimizations
# -fassume-phsa -fasynchronous-unwind-tables -fauto-inc-dec -fcommon
# -fdelete-null-pointer-checks -fdwarf2-cfi-asm -fearly-inlining
# -feliminate-unused-debug-types -ffp-int-builtin-inexact -ffunction-cse
# -fgcse-lm -fgnu-runtime -fgnu-unique -fident -finline-atomics
# -fipa-stack-alignment -fira-hoist-pressure -fira-share-save-slots
# -fira-share-spill-slots -fivopts -fkeep-static-consts
# -fleading-underscore -flifetime-dse -flto-odr-type-merging -fmath-errno
# -fmerge-debug-strings -fpeephole -fplt -fprefetch-loop-arrays
# -freg-struct-return -fsched-critical-path-heuristic
# -fsched-dep-count-heuristic -fsched-group-heuristic -fsched-interblock
# -fsched-last-insn-heuristic -fsched-rank-heuristic -fsched-spec
# -fsched-spec-insn-heuristic -fsched-stalled-insns-dep -fschedule-fusion
# -fsemantic-interposition -fshow-column -fshrink-wrap-separate
# -fsigned-zeros -fsplit-ivs-in-unroller -fssa-backprop
# -fstack-clash-protection -fstack-protector-strong -fstdarg-opt
# -fstrict-volatile-bitfields -fsync-libcalls -ftrapping-math -ftree-cselim
# -ftree-forwprop -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
# -ftree-loop-optimize -ftree-parallelize-loops= -ftree-phiprop
# -ftree-reassoc -ftree-scev-cprop -funit-at-a-time -funwind-tables
# -fverbose-asm -fzero-initialized-in-bss -m128bit-long-double -m64 -m80387
# -malign-stringops -mavx256-split-unaligned-load
# -mavx256-split-unaligned-store -mfancy-math-387 -mfp-ret-in-387 -mfxsr
# -mglibc -mieee-fp -mlong-double-80 -mmmx -mno-sse4 -mpush-args -mred-zone
# -msse -msse2 -mstv -mtls-direct-seg-refs -mvzeroupper

	.text
	.section	.rodata
.LC0:
	.string	"exercice_1"
.LC1:
	.string	"exercice_2"
.LC2:
	.string	"exercice_3"
.LC3:
	.string	"exercice_4"
.LC4:
	.string	"%s not found.\n"
.LC5:
	.string	"Usage: %s <program> [args].\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movl	%edi, -4(%rbp)	# argc, argc
	movq	%rsi, -16(%rbp)	# argv, argv
# main.c:16:     if (argc >= 2) {
	cmpl	$1, -4(%rbp)	#, argc
	jle	.L2	#,
# main.c:17:         if (strcmp(argv[1], "exercice_1") == 0) {
	movq	-16(%rbp), %rax	# argv, tmp99
	addq	$8, %rax	#, _1
# main.c:17:         if (strcmp(argv[1], "exercice_1") == 0) {
	movq	(%rax), %rax	# *_1, _2
	leaq	.LC0(%rip), %rsi	#,
	movq	%rax, %rdi	# _2,
	call	strcmp@PLT	#
# main.c:17:         if (strcmp(argv[1], "exercice_1") == 0) {
	testl	%eax, %eax	# _3
	jne	.L3	#,
# main.c:18:             exercice_1();
	movl	$0, %eax	#,
	call	exercice_1	#
	jmp	.L4	#
.L3:
# main.c:19:         } else if (strcmp(argv[1], "exercice_2") == 0) {
	movq	-16(%rbp), %rax	# argv, tmp100
	addq	$8, %rax	#, _4
# main.c:19:         } else if (strcmp(argv[1], "exercice_2") == 0) {
	movq	(%rax), %rax	# *_4, _5
	leaq	.LC1(%rip), %rsi	#,
	movq	%rax, %rdi	# _5,
	call	strcmp@PLT	#
# main.c:19:         } else if (strcmp(argv[1], "exercice_2") == 0) {
	testl	%eax, %eax	# _6
	jne	.L5	#,
# main.c:20:             exercice_2();
	movl	$0, %eax	#,
	call	exercice_2	#
	jmp	.L4	#
.L5:
# main.c:21:         } else if (strcmp(argv[1], "exercice_3") == 0) {
	movq	-16(%rbp), %rax	# argv, tmp101
	addq	$8, %rax	#, _7
# main.c:21:         } else if (strcmp(argv[1], "exercice_3") == 0) {
	movq	(%rax), %rax	# *_7, _8
	leaq	.LC2(%rip), %rsi	#,
	movq	%rax, %rdi	# _8,
	call	strcmp@PLT	#
# main.c:21:         } else if (strcmp(argv[1], "exercice_3") == 0) {
	testl	%eax, %eax	# _9
	jne	.L6	#,
# main.c:22:             exercice_3();
	movl	$0, %eax	#,
	call	exercice_3	#
	jmp	.L4	#
.L6:
# main.c:23:         } else if (strcmp(argv[1], "exercice_4") == 0) {
	movq	-16(%rbp), %rax	# argv, tmp102
	addq	$8, %rax	#, _10
# main.c:23:         } else if (strcmp(argv[1], "exercice_4") == 0) {
	movq	(%rax), %rax	# *_10, _11
	leaq	.LC3(%rip), %rsi	#,
	movq	%rax, %rdi	# _11,
	call	strcmp@PLT	#
# main.c:23:         } else if (strcmp(argv[1], "exercice_4") == 0) {
	testl	%eax, %eax	# _12
	jne	.L7	#,
# main.c:24:             exercice_4();
	movl	$0, %eax	#,
	call	exercice_4	#
	jmp	.L4	#
.L7:
# main.c:26:             printf("%s not found.\n", argv[1]);
	movq	-16(%rbp), %rax	# argv, tmp103
	addq	$8, %rax	#, _13
# main.c:26:             printf("%s not found.\n", argv[1]);
	movq	(%rax), %rax	# *_13, _14
	movq	%rax, %rsi	# _14,
	leaq	.LC4(%rip), %rdi	#,
	movl	$0, %eax	#,
	call	printf@PLT	#
	jmp	.L4	#
.L2:
# main.c:29:         fprintf(stderr, "Usage: %s <program> [args].\n", argv[0]);
	movq	-16(%rbp), %rax	# argv, tmp104
	movq	(%rax), %rdx	# *argv_20(D), _15
	movq	stderr(%rip), %rax	# stderr, stderr.0_16
	leaq	.LC5(%rip), %rsi	#,
	movq	%rax, %rdi	# stderr.0_16,
	movl	$0, %eax	#,
	call	fprintf@PLT	#
# main.c:30:         exit(EXIT_FAILURE);
	movl	$1, %edi	#,
	call	exit@PLT	#
.L4:
# main.c:32:     exit(EXIT_SUCCESS);
	movl	$0, %edi	#,
	call	exit@PLT	#
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.section	.rodata
.LC6:
	.string	"Caught signal term."
.LC7:
	.string	"Caught signal kill."
	.text
	.globl	exercice_1_handler
	.type	exercice_1_handler, @function
exercice_1_handler:
.LFB7:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$32, %rsp	#,
	movl	%edi, -4(%rbp)	# signo, signo
	movq	%rsi, -16(%rbp)	# info, info
	movq	%rdx, -24(%rbp)	# context, context
# main.c:36:     if (signo == SIGTERM) {
	cmpl	$15, -4(%rbp)	#, signo
	jne	.L9	#,
# main.c:37:         printf("Caught signal term.\n");
	leaq	.LC6(%rip), %rdi	#,
	call	puts@PLT	#
# main.c:41: }
	jmp	.L11	#
.L9:
# main.c:38:     } else if (signo == SIGKILL) {
	cmpl	$9, -4(%rbp)	#, signo
	jne	.L11	#,
# main.c:39:         printf("Caught signal kill.\n");
	leaq	.LC7(%rip), %rdi	#,
	call	puts@PLT	#
.L11:
# main.c:41: }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE7:
	.size	exercice_1_handler, .-exercice_1_handler
	.section	.rodata
.LC8:
	.string	"sigterm"
.LC9:
	.string	"fok"
	.text
	.globl	exercice_1
	.type	exercice_1, @function
exercice_1:
.LFB8:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$176, %rsp	#,
# main.c:43: void exercice_1() {
	movq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp92
	movq	%rax, -8(%rbp)	# tmp92, D.4064
	xorl	%eax, %eax	# tmp92
# main.c:44:     const pid_t pid = fork();
	call	fork@PLT	#
	movl	%eax, -168(%rbp)	# tmp84, pid
# main.c:45:     struct sigaction handle = {0};
	leaq	-160(%rbp), %rdx	#, tmp85
	movl	$0, %eax	#, tmp86
	movl	$19, %ecx	#, tmp87
	movq	%rdx, %rdi	# tmp85, tmp85
	rep stosq
# main.c:46:     handle.sa_flags = SA_SIGINFO;
	movl	$4, -24(%rbp)	#, handle.sa_flags
# main.c:47:     handle.sa_sigaction = &exercice_1_handler;
	leaq	exercice_1_handler(%rip), %rax	#, tmp88
	movq	%rax, -160(%rbp)	# tmp88, handle.__sigaction_handler.sa_sigaction
# main.c:48:     if (sigaction(SIGTERM, &handle, NULL) == -1) {
	leaq	-160(%rbp), %rax	#, tmp89
	movl	$0, %edx	#,
	movq	%rax, %rsi	# tmp89,
	movl	$15, %edi	#,
	call	sigaction@PLT	#
# main.c:48:     if (sigaction(SIGTERM, &handle, NULL) == -1) {
	cmpl	$-1, %eax	#, _1
	jne	.L13	#,
# main.c:49:         perror("sigterm");
	leaq	.LC8(%rip), %rdi	#,
	call	perror@PLT	#
# main.c:50:         exit(EXIT_FAILURE);
	movl	$1, %edi	#,
	call	exit@PLT	#
.L13:
# main.c:57:     switch (pid) {
	cmpl	$-1, -168(%rbp)	#, pid
	je	.L14	#,
	cmpl	$0, -168(%rbp)	#, pid
	je	.L15	#,
	jmp	.L19	#
.L14:
# main.c:59:             perror("fok");
	leaq	.LC9(%rip), %rdi	#,
	call	perror@PLT	#
# main.c:60:             exit(EXIT_FAILURE);
	movl	$1, %edi	#,
	call	exit@PLT	#
.L15:
# main.c:62:             ppid = getppid();
	call	getppid@PLT	#
	movl	%eax, -164(%rbp)	# tmp90, ppid
# main.c:63:             kill(ppid, SIGTERM);
	movl	-164(%rbp), %eax	# ppid, tmp91
	movl	$15, %esi	#,
	movl	%eax, %edi	# tmp91,
	call	kill@PLT	#
# main.c:65:             break;
	jmp	.L17	#
.L19:
# main.c:67:             pause();
	call	pause@PLT	#
# main.c:68:             pause();
	call	pause@PLT	#
# main.c:69:             break;
	nop	
.L17:
# main.c:71:     exit(EXIT_SUCCESS);
	movl	$0, %edi	#,
	call	exit@PLT	#
	.cfi_endproc
.LFE8:
	.size	exercice_1, .-exercice_1
	.section	.rodata
.LC10:
	.string	"f1"
.LC11:
	.string	"f2"
.LC12:
	.string	"p1"
.LC13:
	.string	"p2"
	.text
	.globl	exercice_2
	.type	exercice_2, @function
exercice_2:
.LFB9:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
# main.c:75:     const pid_t pork = fork();
	call	fork@PLT	#
	movl	%eax, -8(%rbp)	# tmp83, pork
# main.c:76:     switch (pork) {
	cmpl	$-1, -8(%rbp)	#, pork
	je	.L21	#,
	cmpl	$0, -8(%rbp)	#, pork
	je	.L22	#,
	jmp	.L25	#
.L21:
# main.c:78:             perror("fok");
	leaq	.LC9(%rip), %rdi	#,
	call	perror@PLT	#
# main.c:79:             exit(EXIT_FAILURE);
	movl	$1, %edi	#,
	call	exit@PLT	#
.L22:
# main.c:81:             const pid_t ppid = getppid();
	call	getppid@PLT	#
	movl	%eax, -4(%rbp)	# tmp84, ppid
# main.c:82:             printf("f1\n");
	leaq	.LC10(%rip), %rdi	#,
	call	puts@PLT	#
# main.c:83:             kill(ppid, SIGCONT);
	movl	-4(%rbp), %eax	# ppid, tmp85
	movl	$18, %esi	#,
	movl	%eax, %edi	# tmp85,
	call	kill@PLT	#
# main.c:84:             raise(SIGSTOP);
	movl	$19, %edi	#,
	call	raise@PLT	#
# main.c:85:             printf("f2\n");
	leaq	.LC11(%rip), %rdi	#,
	call	puts@PLT	#
# main.c:86:             kill(ppid, SIGCONT);
	movl	-4(%rbp), %eax	# ppid, tmp86
	movl	$18, %esi	#,
	movl	%eax, %edi	# tmp86,
	call	kill@PLT	#
# main.c:88:         break;
	jmp	.L24	#
.L25:
# main.c:90:             raise(SIGSTOP);
	movl	$19, %edi	#,
	call	raise@PLT	#
# main.c:91:             printf("p1\n");
	leaq	.LC12(%rip), %rdi	#,
	call	puts@PLT	#
# main.c:92:             kill(pork, SIGCONT);
	movl	-8(%rbp), %eax	# pork, tmp87
	movl	$18, %esi	#,
	movl	%eax, %edi	# tmp87,
	call	kill@PLT	#
# main.c:93:             raise(SIGSTOP);
	movl	$19, %edi	#,
	call	raise@PLT	#
# main.c:94:             printf("p2\n");
	leaq	.LC13(%rip), %rdi	#,
	call	puts@PLT	#
# main.c:96:         break;
	nop	
.L24:
# main.c:98:     exit(EXIT_SUCCESS);
	movl	$0, %edi	#,
	call	exit@PLT	#
	.cfi_endproc
.LFE9:
	.size	exercice_2, .-exercice_2
	.globl	count
	.bss
	.align 4
	.type	count, @object
	.size	count, 4
count:
	.zero	4
	.section	.rodata
.LC14:
	.string	"No question, no awnser!!"
.LC15:
	.string	"Waiting... (%d)\n"
	.text
	.globl	exercice_3_handle_alarm
	.type	exercice_3_handle_alarm, @function
exercice_3_handle_alarm:
.LFB10:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movl	%edi, -4(%rbp)	# signo, signo
# main.c:104:     if (count >= 3) {
	movl	count(%rip), %eax	# count, count.1_1
# main.c:104:     if (count >= 3) {
	cmpl	$2, %eax	#, count.1_1
	jle	.L27	#,
# main.c:105:         printf("No question, no awnser!!\n");
	leaq	.LC14(%rip), %rdi	#,
	call	puts@PLT	#
# main.c:106:         exit(EXIT_FAILURE);
	movl	$1, %edi	#,
	call	exit@PLT	#
.L27:
# main.c:108:     printf("Waiting... (%d)\n", ++count);
	movl	count(%rip), %eax	# count, count.2_2
	addl	$1, %eax	#, _3
	movl	%eax, count(%rip)	# _3, count
	movl	%eax, %esi	# _3,
	leaq	.LC15(%rip), %rdi	#,
	movl	$0, %eax	#,
	call	printf@PLT	#
# main.c:109:     alarm(5);
	movl	$5, %edi	#,
	call	alarm@PLT	#
# main.c:110: }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE10:
	.size	exercice_3_handle_alarm, .-exercice_3_handle_alarm
	.section	.rodata
.LC16:
	.string	"Enter a question: "
.LC17:
	.string	"%s"
	.text
	.globl	exercice_3
	.type	exercice_3, @function
exercice_3:
.LFB11:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$272, %rsp	#,
# main.c:112: void exercice_3() {
	movq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp84
	movq	%rax, -8(%rbp)	# tmp84, D.4074
	xorl	%eax, %eax	# tmp84
# main.c:113:     signal(SIGALRM, exercice_3_handle_alarm);
	leaq	exercice_3_handle_alarm(%rip), %rsi	#,
	movl	$14, %edi	#,
	call	signal@PLT	#
# main.c:114:     alarm(5);
	movl	$5, %edi	#,
	call	alarm@PLT	#
# main.c:115:     printf("Enter a question: ");
	leaq	.LC16(%rip), %rdi	#,
	movl	$0, %eax	#,
	call	printf@PLT	#
# main.c:117:     scanf("%s", question);
	leaq	-272(%rbp), %rax	#, tmp82
	movq	%rax, %rsi	# tmp82,
	leaq	.LC17(%rip), %rdi	#,
	movl	$0, %eax	#,
	call	__isoc99_scanf@PLT	#
# main.c:118:     printf("%s\n", question);
	leaq	-272(%rbp), %rax	#, tmp83
	movq	%rax, %rdi	# tmp83,
	call	puts@PLT	#
# main.c:119:     exit(EXIT_SUCCESS);
	movl	$0, %edi	#,
	call	exit@PLT	#
	.cfi_endproc
.LFE11:
	.size	exercice_3, .-exercice_3
	.section	.rodata
.LC18:
	.string	"Caught signal SIGCHLD."
	.text
	.globl	exercice_4_handle_sigchld
	.type	exercice_4_handle_sigchld, @function
exercice_4_handle_sigchld:
.LFB12:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movl	%edi, -4(%rbp)	# signo, signo
# main.c:123:     printf("Caught signal SIGCHLD.\n");
	leaq	.LC18(%rip), %rdi	#,
	call	puts@PLT	#
# main.c:124: }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE12:
	.size	exercice_4_handle_sigchld, .-exercice_4_handle_sigchld
	.section	.rodata
.LC19:
	.string	"Gnehehe %d\n"
.LC20:
	.string	"Noooo!"
	.text
	.globl	exercice_4
	.type	exercice_4, @function
exercice_4:
.LFB13:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
# main.c:127:     signal(SIGCHLD, exercice_4_handle_sigchld);
	leaq	exercice_4_handle_sigchld(%rip), %rsi	#,
	movl	$17, %edi	#,
	call	signal@PLT	#
# main.c:128:     switch (fork()) {
	call	fork@PLT	#
# main.c:128:     switch (fork()) {
	cmpl	$-1, %eax	#, _1
	je	.L32	#,
	testl	%eax, %eax	# _1
	je	.L33	#,
	jmp	.L36	#
.L32:
# main.c:130:             perror("fok");
	leaq	.LC9(%rip), %rdi	#,
	call	perror@PLT	#
# main.c:131:             exit(EXIT_FAILURE);
	movl	$1, %edi	#,
	call	exit@PLT	#
.L33:
# main.c:133:             printf("Gnehehe %d\n", getpid());
	call	getpid@PLT	#
	movl	%eax, %esi	# _2,
	leaq	.LC19(%rip), %rdi	#,
	movl	$0, %eax	#,
	call	printf@PLT	#
# main.c:134:             pause();
	call	pause@PLT	#
# main.c:135:             printf("Noooo!\n");
	leaq	.LC20(%rip), %rdi	#,
	call	puts@PLT	#
# main.c:136:             break;
	jmp	.L35	#
.L36:
# main.c:138:             sleep(1);
	movl	$1, %edi	#,
	call	sleep@PLT	#
# main.c:139:             break;
	nop	
.L35:
# main.c:141:     exit(EXIT_SUCCESS);
	movl	$0, %edi	#,
	call	exit@PLT	#
	.cfi_endproc
.LFE13:
	.size	exercice_4, .-exercice_4
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
