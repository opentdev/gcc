/* { dg-do compile } */
/* { dg-final { check-function-bodies "**" "" "-DCHECK_ASM" } } */

#include "test_sve_acle.h"

/*
** mls_f64_m_tied1:
**	fmls	z0\.d, p0/m, z1\.d, z2\.d
**	ret
*/
TEST_UNIFORM_Z (mls_f64_m_tied1, svfloat64_t,
		z0 = svmls_f64_m (p0, z0, z1, z2),
		z0 = svmls_m (p0, z0, z1, z2))

/*
** mls_f64_m_tied2:
**	mov	(z[0-9]+)\.d, z1\.d
**	movprfx	z1, z0
**	fmls	z1\.d, p0/m, \1\.d, z2\.d
**	ret
*/
TEST_UNIFORM_Z (mls_f64_m_tied2, svfloat64_t,
		z1 = svmls_f64_m (p0, z0, z1, z2),
		z1 = svmls_m (p0, z0, z1, z2))

/*
** mls_f64_m_tied3:
**	mov	(z[0-9]+)\.d, z2\.d
**	movprfx	z2, z0
**	fmls	z2\.d, p0/m, z1\.d, \1\.d
**	ret
*/
TEST_UNIFORM_Z (mls_f64_m_tied3, svfloat64_t,
		z2 = svmls_f64_m (p0, z0, z1, z2),
		z2 = svmls_m (p0, z0, z1, z2))

/*
** mls_f64_m_untied:
**	movprfx	z0, z1
**	fmls	z0\.d, p0/m, z2\.d, z3\.d
**	ret
*/
TEST_UNIFORM_Z (mls_f64_m_untied, svfloat64_t,
		z0 = svmls_f64_m (p0, z1, z2, z3),
		z0 = svmls_m (p0, z1, z2, z3))

/*
** mls_x0_f64_m_tied1:
**	mov	(z[0-9]+\.d), x0
**	fmls	z0\.d, p0/m, z1\.d, \1
**	ret
*/
TEST_UNIFORM_ZS (mls_x0_f64_m_tied1, svfloat64_t, double,
		 z0 = svmls_n_f64_m (p0, z0, z1, x0),
		 z0 = svmls_m (p0, z0, z1, x0))

/*
** mls_x0_f64_m_tied2:
**	mov	(z[0-9]+\.d), x0
**	mov	(z[0-9]+)\.d, z1\.d
**	movprfx	z1, z0
**	fmls	z1\.d, p0/m, \2\.d, \1
**	ret
*/
TEST_UNIFORM_ZS (mls_x0_f64_m_tied2, svfloat64_t, double,
		 z1 = svmls_n_f64_m (p0, z0, z1, x0),
		 z1 = svmls_m (p0, z0, z1, x0))

/*
** mls_x0_f64_m_untied:
**	mov	(z[0-9]+\.d), x0
**	movprfx	z0, z1
**	fmls	z0\.d, p0/m, z2\.d, \1
**	ret
*/
TEST_UNIFORM_ZS (mls_x0_f64_m_untied, svfloat64_t, double,
		 z0 = svmls_n_f64_m (p0, z1, z2, x0),
		 z0 = svmls_m (p0, z1, z2, x0))

/*
** mls_d0_f64_m_tied1:
**	mov	(z[0-9]+\.d), d0
**	fmls	z0\.d, p0/m, z1\.d, \1
**	ret
*/
TEST_UNIFORM_ZS (mls_d0_f64_m_tied1, svfloat64_t, double,
		 z0 = svmls_n_f64_m (p0, z0, z1, d0),
		 z0 = svmls_m (p0, z0, z1, d0))

/*
** mls_d0_f64_m_tied2:
**	mov	(z[0-9]+\.d), d0
**	mov	(z[0-9]+)\.d, z1\.d
**	movprfx	z1, z0
**	fmls	z1\.d, p0/m, \2\.d, \1
**	ret
*/
TEST_UNIFORM_ZS (mls_d0_f64_m_tied2, svfloat64_t, double,
		 z1 = svmls_n_f64_m (p0, z0, z1, d0),
		 z1 = svmls_m (p0, z0, z1, d0))

/*
** mls_d0_f64_m_untied:
**	mov	(z[0-9]+\.d), d0
**	movprfx	z1, z0
**	fmls	z1\.d, p0/m, z2\.d, \1
**	ret
*/
TEST_UNIFORM_ZS (mls_d0_f64_m_untied, svfloat64_t, double,
		 z1 = svmls_n_f64_m (p0, z0, z2, d0),
		 z1 = svmls_m (p0, z0, z2, d0))

/*
** mls_2_f64_m_tied1:
**	fmov	(z[0-9]+\.d), #2.0(e\+0)?
**	fmls	z0\.d, p0/m, z1\.d, \1
**	ret
*/
TEST_UNIFORM_Z (mls_2_f64_m_tied1, svfloat64_t,
		z0 = svmls_n_f64_m (p0, z0, z1, 2),
		z0 = svmls_m (p0, z0, z1, 2))

/*
** mls_2_f64_m_tied2:
**	fmov	(z[0-9]+\.d), #2.0(e\+0)?
**	mov	(z[0-9]+)\.d, z1\.d
**	movprfx	z1, z0
**	fmls	z1\.d, p0/m, \3\.d, \1
**	ret
*/
TEST_UNIFORM_Z (mls_2_f64_m_tied2, svfloat64_t,
		z1 = svmls_n_f64_m (p0, z0, z1, 2),
		z1 = svmls_m (p0, z0, z1, 2))

/*
** mls_2_f64_m_untied:
**	fmov	(z[0-9]+\.d), #2.0(e\+0)?
**	movprfx	z0, z1
**	fmls	z0\.d, p0/m, z2\.d, \1
**	ret
*/
TEST_UNIFORM_Z (mls_2_f64_m_untied, svfloat64_t,
		z0 = svmls_n_f64_m (p0, z1, z2, 2),
		z0 = svmls_m (p0, z1, z2, 2))

/*
** mls_f64_z_tied1:
**	movprfx	z0\.d, p0/z, z0\.d
**	fmls	z0\.d, p0/m, z1\.d, z2\.d
**	ret
*/
TEST_UNIFORM_Z (mls_f64_z_tied1, svfloat64_t,
		z0 = svmls_f64_z (p0, z0, z1, z2),
		z0 = svmls_z (p0, z0, z1, z2))

/*
** mls_f64_z_tied2:
**	movprfx	z1\.d, p0/z, z1\.d
**	fmsb	z1\.d, p0/m, z2\.d, z0\.d
**	ret
*/
TEST_UNIFORM_Z (mls_f64_z_tied2, svfloat64_t,
		z1 = svmls_f64_z (p0, z0, z1, z2),
		z1 = svmls_z (p0, z0, z1, z2))

/*
** mls_f64_z_tied3:
**	movprfx	z2\.d, p0/z, z2\.d
**	fmsb	z2\.d, p0/m, z1\.d, z0\.d
**	ret
*/
TEST_UNIFORM_Z (mls_f64_z_tied3, svfloat64_t,
		z2 = svmls_f64_z (p0, z0, z1, z2),
		z2 = svmls_z (p0, z0, z1, z2))

/*
** mls_f64_z_untied:
**	movprfx	z0\.d, p0/z, z1\.d
**	fmls	z0\.d, p0/m, z2\.d, z3\.d
**	ret
*/
TEST_UNIFORM_Z (mls_f64_z_untied, svfloat64_t,
		z0 = svmls_f64_z (p0, z1, z2, z3),
		z0 = svmls_z (p0, z1, z2, z3))

/*
** mls_x0_f64_z_tied1:
**	mov	(z[0-9]+\.d), x0
**	movprfx	z0\.d, p0/z, z0\.d
**	fmls	z0\.d, p0/m, z1\.d, \1
**	ret
*/
TEST_UNIFORM_ZS (mls_x0_f64_z_tied1, svfloat64_t, double,
		 z0 = svmls_n_f64_z (p0, z0, z1, x0),
		 z0 = svmls_z (p0, z0, z1, x0))

/*
** mls_x0_f64_z_tied2:
**	mov	(z[0-9]+\.d), x0
**	movprfx	z1\.d, p0/z, z1\.d
**	fmsb	z1\.d, p0/m, \1, z0\.d
**	ret
*/
TEST_UNIFORM_ZS (mls_x0_f64_z_tied2, svfloat64_t, double,
		 z1 = svmls_n_f64_z (p0, z0, z1, x0),
		 z1 = svmls_z (p0, z0, z1, x0))

/*
** mls_x0_f64_z_untied: { xfail *-*-* }
**	mov	(z[0-9]+\.d), x0
**	movprfx	z0\.d, p0/z, z1\.d
**	fmls	z0\.d, p0/m, z2\.d, \1
**	ret
*/
TEST_UNIFORM_ZS (mls_x0_f64_z_untied, svfloat64_t, double,
		 z0 = svmls_n_f64_z (p0, z1, z2, x0),
		 z0 = svmls_z (p0, z1, z2, x0))

/*
** mls_d0_f64_z_tied1:
**	mov	(z[0-9]+\.d), d0
**	movprfx	z0\.d, p0/z, z0\.d
**	fmls	z0\.d, p0/m, z1\.d, \1
**	ret
*/
TEST_UNIFORM_ZS (mls_d0_f64_z_tied1, svfloat64_t, double,
		 z0 = svmls_n_f64_z (p0, z0, z1, d0),
		 z0 = svmls_z (p0, z0, z1, d0))

/*
** mls_d0_f64_z_tied2:
**	mov	(z[0-9]+\.d), d0
**	movprfx	z1\.d, p0/z, z1\.d
**	fmsb	z1\.d, p0/m, \1, z0\.d
**	ret
*/
TEST_UNIFORM_ZS (mls_d0_f64_z_tied2, svfloat64_t, double,
		 z1 = svmls_n_f64_z (p0, z0, z1, d0),
		 z1 = svmls_z (p0, z0, z1, d0))

/*
** mls_d0_f64_z_untied: { xfail *-*-* }
**	mov	(z[0-9]+\.d), d0
**	movprfx	z1\.d, p0/z, z0\.d
**	fmls	z1\.d, p0/m, z2\.d, \1
**	ret
*/
TEST_UNIFORM_ZS (mls_d0_f64_z_untied, svfloat64_t, double,
		 z1 = svmls_n_f64_z (p0, z0, z2, d0),
		 z1 = svmls_z (p0, z0, z2, d0))

/*
** mls_f64_x_tied1:
**	fmls	z0\.d, p0/m, z1\.d, z2\.d
**	ret
*/
TEST_UNIFORM_Z (mls_f64_x_tied1, svfloat64_t,
		z0 = svmls_f64_x (p0, z0, z1, z2),
		z0 = svmls_x (p0, z0, z1, z2))

/*
** mls_f64_x_tied2:
**	fmsb	z1\.d, p0/m, z2\.d, z0\.d
**	ret
*/
TEST_UNIFORM_Z (mls_f64_x_tied2, svfloat64_t,
		z1 = svmls_f64_x (p0, z0, z1, z2),
		z1 = svmls_x (p0, z0, z1, z2))

/*
** mls_f64_x_tied3:
**	fmsb	z2\.d, p0/m, z1\.d, z0\.d
**	ret
*/
TEST_UNIFORM_Z (mls_f64_x_tied3, svfloat64_t,
		z2 = svmls_f64_x (p0, z0, z1, z2),
		z2 = svmls_x (p0, z0, z1, z2))

/*
** mls_f64_x_untied:
**	movprfx	z3, z0
**	fmls	z3\.d, p0/m, z1\.d, z2\.d
**	ret
*/
TEST_UNIFORM_Z (mls_f64_x_untied, svfloat64_t,
		z3 = svmls_f64_x (p0, z0, z1, z2),
		z3 = svmls_x (p0, z0, z1, z2))

/*
** mls_x0_f64_x_tied1:
**	mov	(z[0-9]+\.d), x0
**	fmls	z0\.d, p0/m, z1\.d, \1
**	ret
*/
TEST_UNIFORM_ZS (mls_x0_f64_x_tied1, svfloat64_t, double,
		 z0 = svmls_n_f64_x (p0, z0, z1, x0),
		 z0 = svmls_x (p0, z0, z1, x0))

/*
** mls_x0_f64_x_tied2:
**	mov	(z[0-9]+\.d), x0
**	fmsb	z1\.d, p0/m, \1, z0\.d
**	ret
*/
TEST_UNIFORM_ZS (mls_x0_f64_x_tied2, svfloat64_t, double,
		 z1 = svmls_n_f64_x (p0, z0, z1, x0),
		 z1 = svmls_x (p0, z0, z1, x0))

/*
** mls_x0_f64_x_untied:
**	mov	z2\.d, x0
**	fmsb	z2\.d, p0/m, z1\.d, z0\.d
**	ret
*/
TEST_UNIFORM_ZS (mls_x0_f64_x_untied, svfloat64_t, double,
		 z2 = svmls_n_f64_x (p0, z0, z1, x0),
		 z2 = svmls_x (p0, z0, z1, x0))

/*
** mls_d0_f64_x_tied1:
**	mov	(z[0-9]+\.d), d0
**	fmls	z0\.d, p0/m, z1\.d, \1
**	ret
*/
TEST_UNIFORM_ZS (mls_d0_f64_x_tied1, svfloat64_t, double,
		 z0 = svmls_n_f64_x (p0, z0, z1, d0),
		 z0 = svmls_x (p0, z0, z1, d0))

/*
** mls_d0_f64_x_tied2:
**	mov	(z[0-9]+\.d), d0
**	fmsb	z1\.d, p0/m, \1, z0\.d
**	ret
*/
TEST_UNIFORM_ZS (mls_d0_f64_x_tied2, svfloat64_t, double,
		 z1 = svmls_n_f64_x (p0, z0, z1, d0),
		 z1 = svmls_x (p0, z0, z1, d0))

/*
** mls_d0_f64_x_untied:
**	mov	z2\.d, d0
**	fmsb	z2\.d, p0/m, z1\.d, z0\.d
**	ret
*/
TEST_UNIFORM_ZS (mls_d0_f64_x_untied, svfloat64_t, double,
		 z2 = svmls_n_f64_x (p0, z0, z1, d0),
		 z2 = svmls_x (p0, z0, z1, d0))

/*
** mls_2_f64_x_tied1:
**	fmov	(z[0-9]+\.d), #2.0(e\+0)?
**	fmls	z0\.d, p0/m, z1\.d, \1
**	ret
*/
TEST_UNIFORM_Z (mls_2_f64_x_tied1, svfloat64_t,
		z0 = svmls_n_f64_x (p0, z0, z1, 2),
		z0 = svmls_x (p0, z0, z1, 2))

/*
** mls_2_f64_x_tied2:
**	fmov	(z[0-9]+\.d), #2.0(e\+0)?
**	fmsb	z1\.d, p0/m, \1, z0\.d
**	ret
*/
TEST_UNIFORM_Z (mls_2_f64_x_tied2, svfloat64_t,
		z1 = svmls_n_f64_x (p0, z0, z1, 2),
		z1 = svmls_x (p0, z0, z1, 2))

/*
** mls_2_f64_x_untied:
**	fmov	z0\.d, #2.0(e\+0)?
**	fmsb	z0\.d, p0/m, z2\.d, z1\.d
**	ret
*/
TEST_UNIFORM_Z (mls_2_f64_x_untied, svfloat64_t,
		z0 = svmls_n_f64_x (p0, z1, z2, 2),
		z0 = svmls_x (p0, z1, z2, 2))

