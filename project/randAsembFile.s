	.arch msp430g2553



	.text

JT:				

	.word default

	.word case1

	.word case2

	.global state_advance	

state_advance:

	mov.b state, r12

	cmp.b #5, state		

	jc default

	add r12, r12

	mov JT(r12), r0

Case0:

	mov.b #0, &red_on

	mov.b #0, green_on

	add #1, &state

	jmp end

Case1:

	mov.b #1, &red_on

	mov.b #0, green_on

	add #1, &state

	jmp end

default:

end:
	pop r12
	pop r0
