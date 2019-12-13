/* { dg-final { check-function-bodies "**" "" "-DCHECK_ASM" } } */

#include "test_sve_acle.h"

/*
** zip1_f64_tied1:
**	zip1	z0\.d, z0\.d, z1\.d
**	ret
*/
TEST_UNIFORM_Z (zip1_f64_tied1, svfloat64_t,
		z0 = svzip1_f64 (z0, z1),
		z0 = svzip1 (z0, z1))

/*
** zip1_f64_tied2:
**	zip1	z0\.d, z1\.d, z0\.d
**	ret
*/
TEST_UNIFORM_Z (zip1_f64_tied2, svfloat64_t,
		z0 = svzip1_f64 (z1, z0),
		z0 = svzip1 (z1, z0))

/*
** zip1_f64_untied:
**	zip1	z0\.d, z1\.d, z2\.d
**	ret
*/
TEST_UNIFORM_Z (zip1_f64_untied, svfloat64_t,
		z0 = svzip1_f64 (z1, z2),
		z0 = svzip1 (z1, z2))
