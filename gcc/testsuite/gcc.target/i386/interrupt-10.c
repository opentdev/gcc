/* { dg-do compile { target *-*-linux* } } */
/* { dg-options "-O2 -mavx512bw -mno-iamcu -maccumulate-outgoing-args" } */

extern void bar (void);
typedef unsigned int uword_t __attribute__ ((mode (__word__)));

void
 __attribute__ ((interrupt))
foo (uword_t error, uword_t ip, uword_t cs, uword_t eflags)
{
  bar ();
}

/* { dg-final { scan-assembler-times "movups\[\\t \]*%zmm\[0-9\]+,\[\\t \]*-\[0-9\]*\\(%\[re\]?bp\\)" 32 { target { ! ia32 } } } } */
/* { dg-final { scan-assembler-times "movups\[\\t \]*-\[0-9\]*\\(%\[re\]?bp\\),\[\\t \]*%zmm\[0-9\]+" 32 { target { ! ia32 } } } } */
/* { dg-final { scan-assembler-times "movups\[\\t \]*%zmm\[0-9\]+,\[\\t \]*-\[0-9\]*\\(%\[re\]?bp\\)" 8 { target ia32 } } } */
/* { dg-final { scan-assembler-times "movups\[\\t \]*-\[0-9\]*\\(%\[re\]?bp\\),\[\\t \]*%zmm\[0-9\]+" 8 { target ia32 } } } */
/* { dg-final { scan-assembler-times "kmovq\[\\t \]*%k\[0-7\]+,\[\\t \]*-\[0-9\]*\\(%\[re\]?bp\\)" 8 } } */
/* { dg-final { scan-assembler-times "kmovq\[\\t \]*-\[0-9\]*\\(%\[re\]?bp\\),\[\\t \]*%k\[0-7\]+" 8 } } */
/* { dg-final { scan-assembler-not "pushq\[\\t \]*%rbx" { target { ! ia32 } } } } */
/* { dg-final { scan-assembler-not "pushq\[\\t \]*%r1\[2-5\]+" { target { ! ia32 } } } } */
/* { dg-final { scan-assembler-not "pushl\[\\t \]*%ebx" { target ia32 } } } */
/* { dg-final { scan-assembler-not "pushl\[\\t \]*%e(s|d)i" { target ia32 } } } */
