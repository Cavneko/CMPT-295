#Question 1
#using operation AND and XOR to do the bitwise OR operation
#A or B = (AB) xor (A xor B)

.data
arg1:	.word 17    #argument A
arg2:	.word 14    #argument B
result:	.space 4    #memory space to store result

.text
.globl main

main:
        #load teh argument A in $t0
		lw $t0, arg1
        #load teh argument B in $t1
        lw $t1, arg2
        #$t2 store (A and B)
        and $t2, $t0, $t1
        #$t3 store (A xor B)
        xor $t3, $t0, $t1
        #t3 store (AB) xor (A xor B)
        xor $t3, $t2, $t3
        #store the result into memory
        sw  $t3, result

        #exit
        li $v0, 10
        syscall
		

