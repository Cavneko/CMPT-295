.data

a1Msg: .asciiz "enter the integer n"
a2Msg: .asciiz "the result is : "
result: .space 4 #store the nth fibpnacci number

.text
.globl main

main:
        #print header
        la $a0, a1Msg
        li $v0, 4
        syscall

        #read input integer n
        li $v0, 5
        syscall
        #get n to $s0
        move $s0, $v0
        #t0 is counter for loop
        li $t0, 1
        #$t1 is 0th element in fibonacci numbers
        li $t1, 0
        #$t2 is 1th element in fibonacci numbers
        li $t2, 1
loop:
        beq $t0, $s0, end
        #adding first two element in series
        add $t3, $t1, $t2
        #renew the first two element
        addi $t1, $t2, 0
        addi $t2, $t3, 0
        #increse the counter
        addi $t0, $t0, 1
        b loop
end:    
        #store the result
        sb $t3, result
        #loop finish, print the a2Msg
        la $a0, a2Msg
        li $v0, 4
        syscall

        
        #print the result
        move $a0, $t3
        li $v0, 1
        syscall
        
        #exit
        li $v0, 10
        syscall
        


