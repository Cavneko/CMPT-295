.data

mystring: .asciiz "Hello, World!"
msg: .asciiz "Length of string : "

.text
.globl main

main:
       
        #load parameter address to $a0
        la $a0, mystring
        #$t0 is the counter of the function, set it as 0
        li $t0, 0 
        #make room for parameter and return value
        addi $sp, $sp, -8
        #push parameter
        sw $a0, 4($sp)
        #call the function
        jal strlen
        #get return value
        lw $v0, 0($sp)
        #pop return
        addi $sp, $sp, 8
        #function end, print the msg
        la $a0, msg
        li $v0, 4
        syscall
        #print the length of string
        move $a0, $t0
        li $v0, 1
        syscall
        #exit
        li $v0, 10
        syscall

#function strlen
strlen:
        #push $ra
        addi $sp, $sp, -4
        sw $ra, 0($sp)
#loop for counting string length
loop:
        #load each byte in array
        lb $t1, 0($a0)
        #if $t1 ia equal to 0(reach the end of array), jump to the return label
        beq $t1, 0, return
        #increase the counter
        addi $t0, $t0, 1
        #increase the array index
        addi $a0, $a0, 1
        b loop

return:
        #store answer in stack
        sw $t0, 4($sp)
        #pop return address
        lw $ra, 0($sp)
        addi $sp, $sp, 4
        jr $ra
        