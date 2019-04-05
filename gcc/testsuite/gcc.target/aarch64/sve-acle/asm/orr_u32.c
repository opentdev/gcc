/* { dg-do compile } */
/* { dg-final { check-function-bodies "**" "" "-DCHECK_ASM" } } */

#include "test_sve_acle.h"

/*
** orr_u32_m_tied1:
**	orr	z0\.s, p0/m, z0\.s, z1\.s
**	ret
*/
TEST_UNIFORM_Z (orr_u32_m_tied1, svuint32_t,
		z0 = svorr_u32_m (p0, z0, z1),
		z0 = svorr_m (p0, z0, z1))

/* Bad RA choice: no preferred output sequence.  */
TEST_UNIFORM_Z (orr_u32_m_tied2, svuint32_t,
		z1 = svorr_u32_m (p0, z0, z1),
		z1 = svorr_m (p0, z0, z1))

/*
** orr_u32_m_untied:
**	movprfx	z0, z1
**	orr	z0\.s, p0/m, z0\.s, z2\.s
**	ret
*/
TEST_UNIFORM_Z (orr_u32_m_untied, svuint32_t,
		z0 = svorr_u32_m (p0, z1, z2),
		z0 = svorr_m (p0, z1, z2))

/*
** orr_w0_u32_m_tied1:
**	mov	(z[0-9]+\.s), w0
**	orr	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_ZS (orr_w0_u32_m_tied1, svuint32_t, uint32_t,
		 z0 = svorr_n_u32_m (p0, z0, x0),
		 z0 = svorr_m (p0, z0, x0))

/*
** orr_w0_u32_m_untied:
**	mov	(z[0-9]+\.s), w0
**	movprfx	z0, z1
**	orr	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_ZS (orr_w0_u32_m_untied, svuint32_t, uint32_t,
		 z0 = svorr_n_u32_m (p0, z1, x0),
		 z0 = svorr_m (p0, z1, x0))

/*
** orr_s0_u32_m_tied1:
**	mov	(z[0-9]+\.s), s0
**	orr	z1\.s, p0/m, z1\.s, \1
**	ret
*/
TEST_UNIFORM_ZS (orr_s0_u32_m_tied1, svuint32_t, uint32_t,
		 z1 = svorr_n_u32_m (p0, z1, d0),
		 z1 = svorr_m (p0, z1, d0))

/*
** orr_s0_u32_m_untied:
**	mov	(z[0-9]+\.s), s0
**	movprfx	z1, z2
**	orr	z1\.s, p0/m, z1\.s, \1
**	ret
*/
TEST_UNIFORM_ZS (orr_s0_u32_m_untied, svuint32_t, uint32_t,
		 z1 = svorr_n_u32_m (p0, z2, d0),
		 z1 = svorr_m (p0, z2, d0))

/*
** orr_1_u32_m_tied1:
**	mov	(z[0-9]+\.s), #1
**	orr	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_Z (orr_1_u32_m_tied1, svuint32_t,
		z0 = svorr_n_u32_m (p0, z0, 1),
		z0 = svorr_m (p0, z0, 1))

/*
** orr_1_u32_m_untied:
**	mov	(z[0-9]+\.s), #1
**	movprfx	z0, z1
**	orr	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_Z (orr_1_u32_m_untied, svuint32_t,
		z0 = svorr_n_u32_m (p0, z1, 1),
		z0 = svorr_m (p0, z1, 1))

/*
** orr_m2_u32_m:
**	mov	(z[0-9]+\.s), #-2
**	orr	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_Z (orr_m2_u32_m, svuint32_t,
		z0 = svorr_n_u32_m (p0, z0, -2),
		z0 = svorr_m (p0, z0, -2))

/*
** orr_u32_z_tied1:
**	movprfx	z0\.s, p0/z, z0\.s
**	orr	z0\.s, p0/m, z0\.s, z1\.s
**	ret
*/
TEST_UNIFORM_Z (orr_u32_z_tied1, svuint32_t,
		z0 = svorr_u32_z (p0, z0, z1),
		z0 = svorr_z (p0, z0, z1))

/*
** orr_u32_z_tied2:
**	movprfx	z1\.s, p0/z, z1\.s
**	orr	z1\.s, p0/m, z1\.s, z0\.s
**	ret
*/
TEST_UNIFORM_Z (orr_u32_z_tied2, svuint32_t,
		z1 = svorr_u32_z (p0, z0, z1),
		z1 = svorr_z (p0, z0, z1))

/*
** orr_u32_z_untied:
**	movprfx	z0\.s, p0/z, z1\.s
**	orr	z0\.s, p0/m, z0\.s, z2\.s
**	ret
*/
TEST_UNIFORM_Z (orr_u32_z_untied, svuint32_t,
		z0 = svorr_u32_z (p0, z1, z2),
		z0 = svorr_z (p0, z1, z2))

/*
** orr_w0_u32_z_tied1:
**	mov	(z[0-9]+\.s), w0
**	movprfx	z0\.s, p0/z, z0\.s
**	orr	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_ZS (orr_w0_u32_z_tied1, svuint32_t, uint32_t,
		 z0 = svorr_n_u32_z (p0, z0, x0),
		 z0 = svorr_z (p0, z0, x0))

/*
** orr_w0_u32_z_untied: { xfail *-*-* }
**	mov	(z[0-9]+\.s), w0
**	movprfx	z0\.s, p0/z, z1\.s
**	orr	z0\.s, p0/m, z0\.s, \1
**	ret
*/
TEST_UNIFORM_ZS (orr_w0_u32_z_untied, svuint32_t, uint32_t,
		 z0 = svorr_n_u32_z (p0, z1, x0),
		 z0 = svorr_z (p0, z1, x0))

/*
** orr_s0_u32_z_tied1:
**	mov	(z[0-9]+\.s), s0
**	movprfx	z1\.s, p0/z, z1\.s
**	orr	z1\.s, p0/m, z1\.s, \1
**	ret
*/
TEST_UNIFORM_ZS (orr_s0_u32_z_tied1, svuint32_t, uint32_t,
		 z1 = svorr_n_u32_z (p0, z1, d0),
		 z1 = svorr_z (p0, z1, d0))

/*
** orr_s0_u32_z_untied: { xfail *-*-* }
**	mov	(z[0-9]+\.s), s0
**	movprfx	z1\.s, p0/z, z2\.s
**	orr	z1\.s, p0/m, z1\.s, \1
**	ret
*/
TEST_UNIFORM_ZS (orr_s0_u32_z_untied, svuint32_t, uint32_t,
		 z1 = svorr_n_u32_z (p0, z2, d0),
		 z1 = svorr_z (p0, z2, d0))

/*
** orr_u32_x_tied1:
**	orr	z0\.d, z0\.d, z1\.d
**	ret
*/
TEST_UNIFORM_Z (orr_u32_x_tied1, svuint32_t,
		z0 = svorr_u32_x (p0, z0, z1),
		z0 = svorr_x (p0, z0, z1))

/*
** orr_u32_x_tied2:
**	orr	z1\.d, z0\.d, z1\.d
**	ret
*/
TEST_UNIFORM_Z (orr_u32_x_tied2, svuint32_t,
		z1 = svorr_u32_x (p0, z0, z1),
		z1 = svorr_x (p0, z0, z1))

/*
** orr_u32_x_untied:
**	orr	z2\.d, z0\.d, z1\.d
**	ret
*/
TEST_UNIFORM_Z (orr_u32_x_untied, svuint32_t,
		z2 = svorr_u32_x (p0, z0, z1),
		z2 = svorr_x (p0, z0, z1))

/*
** orr_w0_u32_x_tied1:
**	mov	(z[0-9]+)\.s, w0
**	orr	z0\.d, z0\.d, \1\.d
**	ret
*/
TEST_UNIFORM_ZS (orr_w0_u32_x_tied1, svuint32_t, uint32_t,
		 z0 = svorr_n_u32_x (p0, z0, x0),
		 z0 = svorr_x (p0, z0, x0))

/*
** orr_w0_u32_x_untied:
**	mov	z1\.s, w0
**	orr	z1\.d, z0\.d, z1\.d
**	ret
*/
TEST_UNIFORM_ZS (orr_w0_u32_x_untied, svuint32_t, uint32_t,
		 z1 = svorr_n_u32_x (p0, z0, x0),
		 z1 = svorr_x (p0, z0, x0))

/*
** orr_s0_u32_x_tied1:
**	mov	(z[0-9]+)\.s, s0
**	orr	z1\.d, z1\.d, \1\.d
**	ret
*/
TEST_UNIFORM_ZS (orr_s0_u32_x_tied1, svuint32_t, uint32_t,
		 z1 = svorr_n_u32_x (p0, z1, d0),
		 z1 = svorr_x (p0, z1, d0))

/*
** orr_s0_u32_x_untied:
**	mov	(z[0-9]+)\.s, s0
**	orr	z2\.d, z1\.d, \1\.d
**	ret
*/
TEST_UNIFORM_ZS (orr_s0_u32_x_untied, svuint32_t, uint32_t,
		 z2 = svorr_n_u32_x (p0, z1, d0),
		 z2 = svorr_x (p0, z1, d0))

/*
** orr_1_u32_x_tied1:
**	orr	z0\.s, z0\.s, #0x1
**	ret
*/
TEST_UNIFORM_Z (orr_1_u32_x_tied1, svuint32_t,
		z0 = svorr_n_u32_x (p0, z0, 1),
		z0 = svorr_x (p0, z0, 1))

/*
** orr_1_u32_x_untied:
**	movprfx	z0, z1
**	orr	z0\.s, z0\.s, #0x1
**	ret
*/
TEST_UNIFORM_Z (orr_1_u32_x_untied, svuint32_t,
		z0 = svorr_n_u32_x (p0, z1, 1),
		z0 = svorr_x (p0, z1, 1))

/*
** orr_127_u32_x:
**	orr	z0\.s, z0\.s, #0x7f
**	ret
*/
TEST_UNIFORM_Z (orr_127_u32_x, svuint32_t,
		z0 = svorr_n_u32_x (p0, z0, 127),
		z0 = svorr_x (p0, z0, 127))

/*
** orr_128_u32_x:
**	orr	z0\.s, z0\.s, #0x80
**	ret
*/
TEST_UNIFORM_Z (orr_128_u32_x, svuint32_t,
		z0 = svorr_n_u32_x (p0, z0, 128),
		z0 = svorr_x (p0, z0, 128))

/*
** orr_255_u32_x:
**	orr	z0\.s, z0\.s, #0xff
**	ret
*/
TEST_UNIFORM_Z (orr_255_u32_x, svuint32_t,
		z0 = svorr_n_u32_x (p0, z0, 255),
		z0 = svorr_x (p0, z0, 255))

/*
** orr_256_u32_x:
**	orr	z0\.s, z0\.s, #0x100
**	ret
*/
TEST_UNIFORM_Z (orr_256_u32_x, svuint32_t,
		z0 = svorr_n_u32_x (p0, z0, 256),
		z0 = svorr_x (p0, z0, 256))

/* TODO: Bad code and needs fixing.  */
TEST_UNIFORM_Z (orr_257_u32_x, svuint32_t,
		z0 = svorr_n_u32_x (p0, z0, 257),
		z0 = svorr_x (p0, z0, 257))

/*
** orr_512_u32_x:
**	orr	z0\.s, z0\.s, #0x200
**	ret
*/
TEST_UNIFORM_Z (orr_512_u32_x, svuint32_t,
		z0 = svorr_n_u32_x (p0, z0, 512),
		z0 = svorr_x (p0, z0, 512))

/*
** orr_65280_u32_x:
**	orr	z0\.s, z0\.s, #0xff00
**	ret
*/
TEST_UNIFORM_Z (orr_65280_u32_x, svuint32_t,
		z0 = svorr_n_u32_x (p0, z0, 0xff00),
		z0 = svorr_x (p0, z0, 0xff00))

/*
** orr_m127_u32_x:
**	orr	z0\.s, z0\.s, #0xffffff81
**	ret
*/
TEST_UNIFORM_Z (orr_m127_u32_x, svuint32_t,
		z0 = svorr_n_u32_x (p0, z0, -127),
		z0 = svorr_x (p0, z0, -127))

/*
** orr_m128_u32_x:
**	orr	z0\.s, z0\.s, #0xffffff80
**	ret
*/
TEST_UNIFORM_Z (orr_m128_u32_x, svuint32_t,
		z0 = svorr_n_u32_x (p0, z0, -128),
		z0 = svorr_x (p0, z0, -128))

/*
** orr_m255_u32_x:
**	orr	z0\.s, z0\.s, #0xffffff01
**	ret
*/
TEST_UNIFORM_Z (orr_m255_u32_x, svuint32_t,
		z0 = svorr_n_u32_x (p0, z0, -255),
		z0 = svorr_x (p0, z0, -255))

/*
** orr_m256_u32_x:
**	orr	z0\.s, z0\.s, #0xffffff00
**	ret
*/
TEST_UNIFORM_Z (orr_m256_u32_x, svuint32_t,
		z0 = svorr_n_u32_x (p0, z0, -256),
		z0 = svorr_x (p0, z0, -256))

/*
** orr_m257_u32_x:
**	orr	z0\.s, z0\.s, #0xfffffeff
**	ret
*/
TEST_UNIFORM_Z (orr_m257_u32_x, svuint32_t,
		z0 = svorr_n_u32_x (p0, z0, -257),
		z0 = svorr_x (p0, z0, -257))

/*
** orr_m512_u32_x:
**	orr	z0\.s, z0\.s, #0xfffffe00
**	ret
*/
TEST_UNIFORM_Z (orr_m512_u32_x, svuint32_t,
		z0 = svorr_n_u32_x (p0, z0, -512),
		z0 = svorr_x (p0, z0, -512))

/*
** orr_m32768_u32_x:
**	orr	z0\.s, z0\.s, #0xffff8000
**	ret
*/
TEST_UNIFORM_Z (orr_m32768_u32_x, svuint32_t,
		z0 = svorr_n_u32_x (p0, z0, -0x8000),
		z0 = svorr_x (p0, z0, -0x8000))

/*
** orr_5_u32_x:
**	mov	(z[0-9]+)\.s, #5
**	orr	z0\.d, z0\.d, \1\.d
**	ret
*/
TEST_UNIFORM_Z (orr_5_u32_x, svuint32_t,
		z0 = svorr_n_u32_x (p0, z0, 5),
		z0 = svorr_x (p0, z0, 5))
