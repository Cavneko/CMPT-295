.data
    num: .word 5
    result: .space 4

.globl main
.text

main:
    lw $a0, num
    jal fib
    sw $v0, result

    li $v0, 10
    syscall

fib:
    #base case
    beqz $a0, endif_zero   # return 0 if n=0
    beq $a0, 1, endif_one  # return 1 if n=1

    addi $sp, $sp, -4   #space for return address on stack
    sw $ra, 0($sp)
    addi $a0, $a0, -1
    jal fib         #fib(n-1)
        
    addi $a0, $a0, 1
    lw $ra, 0($sp)      #get return address from stack
    addi $sp, $sp, 4
    addi $sp, $sp, -4   #push return value
    sw $v0, 0($sp)
    addi $sp, $sp, -4   #push return address
    sw $ra, 0($sp)
    addi $a0, $a0, -2
    jal fib         #fib(n-2)

    addi $a0, $a0, 2
    lw $ra, 0($sp)   #get return address from stack
    addi $sp, $sp, 4
    lw $s0, 0($sp)   #get return value from stack
    addi $sp, $sp, 4
    add $v0, $v0, $s0 # fib(n-1) + fib(n-2)
    jr $ra

endif_zero:
    li $v0, 0
    jr $ra
endif_one:
    li $v0, 1
    jr $ra

