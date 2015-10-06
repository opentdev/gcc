/* { dg-do compile { target *-*-linux* } } */
/* { dg-options "-O2 -mno-avx512f -mno-iamcu -mavx -mpush-args -maccumulate-outgoing-args" } */

typedef unsigned int uword_t __attribute__ ((mode (__word__)));
extern void bar (int) __attribute__ ((no_caller_saved_registers));

void
 __attribute__ ((interrupt))
fn1 (uword_t error, uword_t ip, uword_t cs, uword_t eflags, uword_t sp,
     uword_t ss)
{
  bar (error);
}

void
 __attribute__ ((interrupt))
fn2 (uword_t error, uword_t ip, uword_t cs, uword_t eflags, uword_t sp,
     uword_t ss)
{
  bar (error);
}

/* { dg-final { scan-assembler-not "movups\[\\t .\]*%(x|y|z)mm\[0-9\]+" } } */
/* { dg-final { scan-assembler-not "(push|pop)(l|q)\[\\t \]*%(r|e)(b|c|d)x" } } */
/* { dg-final { scan-assembler-not "(push|pop)(l|q)\[\\t \]*%(r|e)si" } } */
/* { dg-final { scan-assembler-not "(push|pop)l\[\\t \]*%edi" { target ia32 } } } */
/* { dg-final { scan-assembler-not "(push|pop)q\[\\t \]*%rax" { target { ! ia32 } } } } */
/* { dg-final { scan-assembler-not "(push|pop)q\[\\t \]*%r\[0-9\]+" { target { ! ia32 } } } } */
/* { dg-final { scan-assembler-times "push(?:l|q)\[\\t \]*%(?:r|e)bp" 2 } } */
/* { dg-final { scan-assembler-times "leave" 2 } } */
/* { dg-final { scan-assembler-times "pushl\[\\t \]*%eax" 2 { target ia32 } } } */
/* { dg-final { scan-assembler-times "movl\[\\t \]*-4\\(%ebp\\),\[\\t \]*%eax" 2 { target ia32 } } } */
/* { dg-final { scan-assembler-times "pushq\[\\t \]*%rdi" 2 { target { ! ia32 } } } } */
/* { dg-final { scan-assembler-times "movq\[\\t \]*-8\\(%(?:r|e)bp\\),\[\\t \]*%rdi" 2 { target { ! ia32 } } } } */
/* { dg-final { scan-assembler-times "addl\[\\t \]*\\\$4,\[\\t \]*%esp" 2 { target ia32 } } } */
/* { dg-final { scan-assembler-times "add(?:l|q)\[\\t \]*\\\$8,\[\\t \]*%\[re\]?sp" 2 { target { ! ia32 } } } } */
/* { dg-final { scan-assembler-times "iret" 2 } }*/
