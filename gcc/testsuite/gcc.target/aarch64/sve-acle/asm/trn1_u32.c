/* { dg-do compile } */
/* { dg-final { check-function-bodies "**" "" "-DCHECK_ASM" } } */

#include "test_sve_acle.h"

/*
** trn1_u32_tied1:
**	trn1	z0\.s, z0\.s, z1\.s
**	ret
*/
TEST_UNIFORM_Z (trn1_u32_tied1, svuint32_t,
		z0 = svtrn1_u32 (z0, z1),
		z0 = svtrn1 (z0, z1))

/*
** trn1_u32_tied2:
**	trn1	z0\.s, z1\.s, z0\.s
**	ret
*/
TEST_UNIFORM_Z (trn1_u32_tied2, svuint32_t,
		z0 = svtrn1_u32 (z1, z0),
		z0 = svtrn1 (z1, z0))

/*
** trn1_u32_untied:
**	trn1	z0\.s, z1\.s, z2\.s
**	ret
*/
TEST_UNIFORM_Z (trn1_u32_untied, svuint32_t,
		z0 = svtrn1_u32 (z1, z2),
		z0 = svtrn1 (z1, z2))
