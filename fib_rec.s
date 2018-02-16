
.global fib_rec
.func fib_rec

fib_rec:
	push {r4, r5, lr}
	cmp r0, #1
	bgt else
	b finish
else:
	mov r4, r0 // store n in r1
	sub r0, r0, #1  //update r0 for n-1
	bl fib_rec //call fib
	mov r5, r0 // store return value from first recursive call
	mov r0, r4 //restore r0 to original n 
	sub r0, r0, #2 //update r0 for n-2
	bl fib_rec //call fib
	add r0, r5, r0 // add recursive results

finish:
	pop {r4, r5, lr}
	bx lr 



