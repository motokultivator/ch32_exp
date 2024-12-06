.text

.globl vga

# 1 cyc = 41,666666667 ns

delay_cyc:
addi a0, a0, -4
#slli a0, a0, 2
1: addi a0, a0, -3
blt zero, a0, 1b
ret
delay_us:
add a1, a0, a0
add a0, a0, a1
slli a0, a0, 3
addi a0, a0, -10
j 1b

vga:
   lui  a5,0x40011
   addi a5,a5,1024
   li      a3,1
   lui     a4,0x10
   la a2, delay_us
1: 
   sw   a4,16(a5)
   li   a0, 4
   jalr a2
   sw      a3,16(a5)
   j 1b
