#include <stdio.h>

void
test_1 (const char *path)
{
  FILE *f = fopen (path, "r"); /* { dg-message "opened here" } */
  if (!f)
    return;

  fclose (f); /* { dg-message "\\(4\\) \\.\\.\\.to here" } */
  /* { dg-message "\\(5\\) first 'fclose' here" "" { target *-*-* } .-1 } */
  fclose (f); /* { dg-warning "double 'fclose' of FILE 'f'" } */ 
  /* { dg-message "second 'fclose' here; first 'fclose' was at \\(5\\)" "" { target *-*-* } .-1 } */
}

void
test_2 (const char *src, const char *dst)
{
  FILE *f_in = fopen (src, "r"); /* { dg-message "\\(1\\) opened here" } */
  if (!f_in)
    return;

  FILE *f_out = fopen (src, "w");
  if (!f_out)
    return; /* { dg-warning "leak of FILE 'f_in'" } */
  /* { dg-message "\\(7\\) 'f_in' leaks here; was opened at \\(1\\)" "" { target *-*-* } .-1 } */

  fclose (f_out);
  fclose (f_in);
}

void
test_3 (const char *path)
{
  FILE *f = fopen (path, "r"); /* { dg-message "opened here" } */
  return; /* { dg-warning "leak of FILE 'f'" } */ 
}
