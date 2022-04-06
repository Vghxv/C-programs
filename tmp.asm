1.
.text

sll $s3,$s3,2   #i
add $t0,$s6,$s3 #A{i}

lw $t1,24($s6)  #A[6]

sll $s4,$s4,2   #j
add $t2,$s4,$s7 #B[j]

lw $t2,8($t2)   #B[j+2]

sub $t3,$t1,$t2 #A[6]-B[j+2]
sw $t3,12($t0)  #A[i+3] = A[6]-B[j+2]

2.
#include<stdio.h>
int main(){
	int t0;
	int t1;
	int h;
	t0 = 4*(*(A + 2));
	t1 = *(B + h);
	t0 += t1;
	g = f + t0;
	return 0;
}

3.
(1)8D170028
(2)02785820
4.
lw $s4,128($t2)
100011 01100 01010 0000000010000000
5.
101011 01010 01001 0000000000100000
sw $t2,32($t1)
6.
for I format:
opcode be expanded 1 bit to contain two times as many instruction.
rs rt be expanded 3 bits to fit 256 register file.
for R format:
opcode and funct be expanded 1 bit to contain two times as many instruction.
rs rt rd be expanded 3 bits to fit 256 register file.  
7.
.text
sll $s0,$s0,2
addi $s0,$s0,5
addi $t0,$s0,$s2
lw $t0,($t0)
srl $t0,$t0,8
addi $s1,$t0,$0