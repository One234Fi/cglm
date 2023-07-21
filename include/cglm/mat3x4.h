/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLM_MAT3X4_ZERO_INIT
   GLM_MAT3X4_ZERO

 Functions:
   CGLM_INLINE void  glm_mat3x4_make(float * restrict src, mat3x4 dest)
 */

#ifndef cglm_mat3x4_h
#define cglm_mat3x4_h

#include "common.h"

#define GLM_MAT3X4_ZERO_INIT {{0.0f, 0.0f, 0.0f, 0.0f}, \
                              {0.0f, 0.0f, 0.0f, 0.0f}, \
                              {0.0f, 0.0f, 0.0f, 0.0f}}

/* for C only */
#define GLM_MAT3X4_ZERO GLM_MAT3X4_ZERO_INIT

/*!
 * @brief copy all members of [mat] to [dest]
 *
 * @param[in]  mat  source
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_mat3x4_copy(mat3x4 mat, mat3x4 dest) {
  glm_vec4_ucopy(mat[0], dest[0]);
  glm_vec4_ucopy(mat[1], dest[1]);
  glm_vec4_ucopy(mat[2], dest[2]);
}

/*!
 * @brief make given matrix zero.
 *
 * @param[in, out]  mat  matrix
 */
CGLM_INLINE
void
glm_mat3x4_zero(mat3x4 mat) {
  CGLM_ALIGN_MAT mat3x4 t = GLM_MAT3X4_ZERO_INIT;
  glm_mat3x4_copy(t, mat);
}

/*!
 * @brief Create mat3x4 matrix from pointer
 *
 * @param[in]  src  pointer to an array of floats
 * @param[out] dest matrix
 */
CGLM_INLINE
void
glm_mat3x4_make(float * __restrict src, mat3x4 dest) {
  dest[0][0] = src[0];
  dest[0][1] = src[1];
  dest[0][2] = src[2];
  dest[0][3] = src[3];

  dest[1][0] = src[4];
  dest[1][1] = src[5];
  dest[1][2] = src[6];
  dest[1][3] = src[7];

  dest[2][0] = src[8];
  dest[2][1] = src[9];
  dest[2][2] = src[10];
  dest[2][3] = src[11];
}

#endif
