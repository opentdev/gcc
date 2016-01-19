/* { dg-do compile { target { ! x32 } } } */
/* { dg-options "-fcheck-pointer-bounds -mmpx -O2 -fdump-tree-chkpopt -fchkp-use-nochk-string-functions" } */
/* { dg-final { scan-tree-dump "memcpy_nochk" "chkpopt" } } */

#include "string.h"

void test (int *buf1, int *buf2, size_t len)
{
  memcpy (buf1, buf2, len);
}
