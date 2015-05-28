/* { dg-do compile { target *-*-linux* } } */
/* { dg-options "-O2 -fno-pic -fno-plt" } */

extern int bar (void);

int
foo (void)
{
  return bar ();
}

/* { dg-final { scan-assembler "jmp\[ \t\]*.bar@GOTPCREL" { target { ! ia32 } } } } */
/* { dg-final { scan-assembler "jmp\[ \t\]*.bar@GOT" { target { ia32 && branch_via_got } } } } */
