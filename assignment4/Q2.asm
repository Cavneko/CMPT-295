.data
   num1: .word 33
   num2: .word 55
   num3: .word 44

.globl main
.text

main:
   la $s0, num1   
   la $s1, num2   
   move $s2, $zero  
   addi $sp, $sp, -16 #make space for 3 parameter and return value
   sw $s2, 4($sp)    #pass reference parameter1
   sw $s1, 8($sp)    #pass reference parameter2
   sw $s0, 12($sp)   #pass reference parameter3
   jal conditional_swap
   addi $sp, $sp, 16  #pop (no return in this function)

   la $s0, num2   
   la $s1, num3   
   li $s2, 1
   addi $sp, $sp, -16 #make space for 3 parameter and return value
   sw $s2, 4($sp)    #pass reference parameter1
   sw $s1, 8($sp)    #pass reference parameter2
   sw $s0, 12($sp)   #pass reference parameter3
   jal conditional_swap
   addi $sp, $sp, 16  #pop (no return in this function)
  
   li $v0, 10
   syscall
  
conditional_swap:
   addi $sp, $sp, -4 #push $ra
   sw $ra, 0($sp)
   lw $t0, 16($sp)   #load first parameter
   lw $t1, 12($sp)   #load second parameter
   lw $t2, 8($sp)    #load third parameter

   beqz $t2, end #check conditionn if n = 0, end the function
   #swap the value in two parameter
   lw $t3, ($t0)
   lw $t4, ($t1)
   sw $t3, ($t1)
   sw $t4, ($t0)
end:
   jr $ra