/* { dg-do compile } */
/* { dg-options "-O2 -mno-push-args -maccumulate-outgoing-args" } */

typedef unsigned int uword_t __attribute__ ((mode (__word__)));

extern int bar (int);

__attribute__ ((interrupt))
void
foo (uword_t ip, uword_t cs, uword_t eflags, uword_t sp, uword_t ss)
{
  int a,b,c,d,e,f,i;
  a = bar (5);
  b = bar (a);
  c = bar (b);
  d = bar (c);
  e = bar (d);
  f = bar (e);
  for (i = 1; i < 10; i++)
  {
    a += bar (a + i) + bar (b + i) +
	 bar (c + i) + bar (d + i) +
	 bar (e + i) + bar (f + i);
  }
}
/* { dg-final { scan-assembler-times "push(?:l|q)\[\\t \]*%(?:e|r)ax" 1 } } */
/* { dg-final { scan-assembler-times "push(?:l|q)\[\\t \]*%(?:e|r)bx" 1 } } */
/* { dg-final { scan-assembler-times "push(?:l|q)\[\\t \]*%(?:e|r)cx" 1 } } */
/* { dg-final { scan-assembler-times "push(?:l|q)\[\\t \]*%(?:e|r)dx" 1 } } */
/* { dg-final { scan-assembler-times "push(?:l|q)\[\\t \]*%(?:e|r)si" 1 } } */
/* { dg-final { scan-assembler-times "pushl\[\\t \]*%edi" 2 { target ia32 } } } */
/* { dg-final { scan-assembler-times "pushq\[\\t \]*%rdi" 1 { target { ! ia32 } } } } */
/* { dg-final { scan-assembler-times "pushq\[\\t \]*%r8" 1 { target { ! ia32 } } } } */
/* { dg-final { scan-assembler-times "pushq\[\\t \]*%r9" 1 { target { ! ia32 } } } } */
/* { dg-final { scan-assembler-times "pushq\[\\t \]*%r10" 1 { target { ! ia32 } } } } */
/* { dg-final { scan-assembler-times "pushq\[\\t \]*%r11" 1 { target { ! ia32 } } } } */
/* { dg-final { scan-assembler-times "pushq\[\\t \]*%r12" 1 { target { ! ia32 } } } } */
/* { dg-final { scan-assembler-times "pushq\[\\t \]*%r13" 1 { target { ! ia32 } } } } */
/* { dg-final { scan-assembler-times "pushq\[\\t \]*%r14" 1 { target { ! ia32 } } } } */
/* { dg-final { scan-assembler-times "pushq\[\\t \]*%r15" 1 { target { ! ia32 } } } } */
/* { dg-final { scan-assembler-times "pop(?:l|q)\[\\t \]*%(?:e|r)ax" 1 } } */
/* { dg-final { scan-assembler-times "pop(?:l|q)\[\\t \]*%(?:e|r)bx" 1 } } */
/* { dg-final { scan-assembler-times "pop(?:l|q)\[\\t \]*%(?:e|r)cx" 1 } } */
/* { dg-final { scan-assembler-times "pop(?:l|q)\[\\t \]*%(?:e|r)dx" 1 } } */
/* { dg-final { scan-assembler-times "pop(?:l|q)\[\\t \]*%(?:e|r)si" 1 } } */
/* { dg-final { scan-assembler-times "popl\[\\t \]*%edi" 2 { target ia32 } } } */
/* { dg-final { scan-assembler-times "popq\[\\t \]*%rdi" 1 { target { ! ia32 } } } } */
/* { dg-final { scan-assembler-times "popq\[\\t \]*%r8" 1 { target { ! ia32 } } } } */
/* { dg-final { scan-assembler-times "popq\[\\t \]*%r9" 1 { target { ! ia32 } } } } */
/* { dg-final { scan-assembler-times "popq\[\\t \]*%r10" 1 { target { ! ia32 } } } } */
/* { dg-final { scan-assembler-times "popq\[\\t \]*%r11" 1 { target { ! ia32 } } } } */
/* { dg-final { scan-assembler-times "popq\[\\t \]*%r12" 1 { target { ! ia32 } } } } */
/* { dg-final { scan-assembler-times "popq\[\\t \]*%r13" 1 { target { ! ia32 } } } } */
/* { dg-final { scan-assembler-times "popq\[\\t \]*%r14" 1 { target { ! ia32 } } } } */
/* { dg-final { scan-assembler-times "popq\[\\t \]*%r15" 1 { target { ! ia32 } } } } */
/* { dg-final { scan-assembler "iret" } }*/
