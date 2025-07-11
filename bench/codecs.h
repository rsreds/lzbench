/*
 * Copyright (c) Przemyslaw Skibinski <inikep@gmail.com>
 * All rights reserved.
 *
 * This source code is dual-licensed under the GPLv2 and GPLv3 licenses.
 * For additional details, refer to the LICENSE file located in the root
 * directory of this source tree.
 */

#ifndef LZBENCH_COMPRESSORS_H
#define LZBENCH_COMPRESSORS_H

#include <stdlib.h>
#include <stdint.h> // int64_t

typedef struct
{
    int level;
    int additional_param;
    char* work_mem;
//    int threads;
} codec_options_t;



int64_t lzbench_memcpy(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);


#ifndef BENCH_REMOVE_BRIEFLZ
    char* lzbench_brieflz_init(size_t insize, size_t level, size_t);
    void lzbench_brieflz_deinit(char* workmem);
    int64_t lzbench_brieflz_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_brieflz_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_brieflz_init NULL
    #define lzbench_brieflz_deinit NULL
    #define lzbench_brieflz_compress NULL
    #define lzbench_brieflz_decompress NULL
#endif


#ifndef BENCH_REMOVE_KANZI
    int64_t lzbench_kanzi_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_kanzi_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_kanzi_compress NULL
    #define lzbench_kanzi_decompress NULL
#endif // BENCH_REMOVE_KANZI


#ifndef BENCH_REMOVE_BROTLI
    int64_t lzbench_brotli_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_brotli_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_brotli_compress NULL
    #define lzbench_brotli_decompress NULL
#endif


#ifndef BENCH_REMOVE_BSC
    char* lzbench_bsc_init(size_t insize, size_t level, size_t);
    int64_t lzbench_bsc_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_bsc_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);

    #ifdef BENCH_HAS_CUDA
        int64_t lzbench_bsc_cuda_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
        int64_t lzbench_bsc_cuda_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    #else
        #define lzbench_bsc_cuda_compress NULL
        #define lzbench_bsc_cuda_decompress NULL
    #endif
#else
    #define lzbench_bsc_init NULL
    #define lzbench_bsc_compress NULL
    #define lzbench_bsc_decompress NULL
    #define lzbench_bsc_cuda_compress NULL
    #define lzbench_bsc_cuda_decompress NULL
#endif // BENCH_REMOVE_BSC


#ifndef BENCH_REMOVE_BZIP2
    int64_t lzbench_bzip2_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_bzip2_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_bzip2_compress NULL
    #define lzbench_bzip2_decompress NULL
#endif // BENCH_REMOVE_BZIP2


#ifndef BENCH_REMOVE_BZIP3
    int64_t lzbench_bzip3_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_bzip3_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_bzip3_compress NULL
    #define lzbench_bzip3_decompress NULL
#endif // BENCH_REMOVE_BZIP3


#ifndef BENCH_REMOVE_CRUSH
    int64_t lzbench_crush_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_crush_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_crush_compress NULL
    #define lzbench_crush_decompress NULL
#endif


#ifndef BENCH_REMOVE_CSC
    int64_t lzbench_csc_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_csc_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_csc_compress NULL
    #define lzbench_csc_decompress NULL
#endif


#ifndef BENCH_REMOVE_DENSITY
    char*   lzbench_density_init(size_t insize, size_t level, size_t);
    void    lzbench_density_deinit(char* workmem);
    int64_t lzbench_density_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_density_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_density_init NULL
    #define lzbench_density_deinit NULL
    #define lzbench_density_compress NULL
    #define lzbench_density_decompress NULL
#endif



#ifndef BENCH_REMOVE_FASTLZ
    int64_t lzbench_fastlz_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_fastlz_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_fastlz_compress NULL
    #define lzbench_fastlz_decompress NULL
#endif


#ifndef BENCH_REMOVE_FASTLZMA2
    int64_t lzbench_fastlzma2_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_fastlzma2_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_fastlzma2_compress NULL
    #define lzbench_fastlzma2_decompress NULL
#endif


#ifndef BENCH_REMOVE_GIPFELI
    int64_t lzbench_gipfeli_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_gipfeli_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_gipfeli_compress NULL
    #define lzbench_gipfeli_decompress NULL
#endif


#ifndef BENCH_REMOVE_GLZA
    int64_t lzbench_glza_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_glza_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_glza_compress NULL
    #define lzbench_glza_decompress NULL
#endif


#ifndef BENCH_REMOVE_LIBDEFLATE
    int64_t lzbench_libdeflate_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_libdeflate_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_libdeflate_compress NULL
    #define lzbench_libdeflate_decompress NULL
#endif


#ifndef BENCH_REMOVE_LIZARD
    int64_t lzbench_lizard_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lizard_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_lizard_compress NULL
    #define lzbench_lizard_decompress NULL
#endif


#ifndef BENCH_REMOVE_LZ4
    int64_t lzbench_lz4_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lz4fast_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lz4hc_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lz4_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_lz4_compress NULL
    #define lzbench_lz4fast_compress NULL
    #define lzbench_lz4hc_compress NULL
    #define lzbench_lz4_decompress NULL
#endif


#ifndef BENCH_REMOVE_LZAV
    int64_t lzbench_lzav_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lzav_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_lzav_compress NULL
    #define lzbench_lzav_decompress NULL
#endif


#ifndef BENCH_REMOVE_LZF
    int64_t lzbench_lzf_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lzf_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_lzf_compress NULL
    #define lzbench_lzf_decompress NULL
#endif


#ifndef BENCH_REMOVE_LZFSE
    char* lzbench_lzfse_init(size_t insize, size_t level, size_t);
    void lzbench_lzfse_deinit(char* workmem);
    int64_t lzbench_lzfse_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lzfse_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_lzfse_init NULL
    #define lzbench_lzfse_deinit NULL
    #define lzbench_lzfse_compress NULL
    #define lzbench_lzfse_decompress NULL
#endif


#ifndef BENCH_REMOVE_LZFSE
    char* lzbench_lzvn_init(size_t insize, size_t level, size_t);
    void lzbench_lzvn_deinit(char* workmem);
    int64_t lzbench_lzvn_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lzvn_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_lzvn_init NULL
    #define lzbench_lzvn_deinit NULL
    #define lzbench_lzvn_compress NULL
    #define lzbench_lzvn_decompress NULL
#endif


#ifndef BENCH_REMOVE_LZG
    int64_t lzbench_lzg_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lzg_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_lzg_compress NULL
    #define lzbench_lzg_decompress NULL
#endif


#ifndef BENCH_REMOVE_LZHAM
    int64_t lzbench_lzham_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lzham_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_lzham_compress NULL
    #define lzbench_lzham_decompress NULL
#endif


#ifndef BENCH_REMOVE_LZJB
    int64_t lzbench_lzjb_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lzjb_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_lzjb_compress NULL
    #define lzbench_lzjb_decompress NULL
#endif


#ifndef BENCH_REMOVE_LZLIB
    int64_t lzbench_lzlib_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lzlib_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_lzlib_compress NULL
    #define lzbench_lzlib_decompress NULL
#endif


#ifndef BENCH_REMOVE_LZMA
    int64_t lzbench_lzma_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lzma_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_lzma_compress NULL
    #define lzbench_lzma_decompress NULL
#endif


#ifndef BENCH_REMOVE_LZMAT
    int64_t lzbench_lzmat_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lzmat_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_lzmat_compress NULL
    #define lzbench_lzmat_decompress NULL
#endif


#ifndef BENCH_REMOVE_LZO
    char* lzbench_lzo_init(size_t insize, size_t level, size_t);
    void lzbench_lzo_deinit(char* workmem);
    int64_t lzbench_lzo1_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lzo1_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lzo1a_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lzo1a_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lzo1b_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lzo1b_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lzo1c_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lzo1c_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lzo1f_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lzo1f_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lzo1x_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lzo1x_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lzo1y_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lzo1y_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lzo1z_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lzo1z_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lzo2a_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lzo2a_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_lzo_init NULL
    #define lzbench_lzo_deinit NULL
    #define lzbench_lzo1_compress NULL
    #define lzbench_lzo1_decompress NULL
    #define lzbench_lzo1a_compress NULL
    #define lzbench_lzo1a_decompress NULL
    #define lzbench_lzo1b_compress NULL
    #define lzbench_lzo1b_decompress NULL
    #define lzbench_lzo1c_compress NULL
    #define lzbench_lzo1c_decompress NULL
    #define lzbench_lzo1f_compress NULL
    #define lzbench_lzo1f_decompress NULL
    #define lzbench_lzo1x_compress NULL
    #define lzbench_lzo1x_decompress NULL
    #define lzbench_lzo1y_compress NULL
    #define lzbench_lzo1y_decompress NULL
    #define lzbench_lzo1z_compress NULL
    #define lzbench_lzo1z_decompress NULL
    #define lzbench_lzo2a_compress NULL
    #define lzbench_lzo2a_decompress NULL
#endif


#ifndef BENCH_REMOVE_LZRW
    char* lzbench_lzrw_init(size_t insize, size_t level, size_t);
    void lzbench_lzrw_deinit(char* workmem);
    int64_t lzbench_lzrw_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lzrw_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_lzrw_init NULL
    #define lzbench_lzrw_deinit NULL
    #define lzbench_lzrw_compress NULL
    #define lzbench_lzrw_decompress NULL
#endif


#ifndef BENCH_REMOVE_LZSSE
    char* lzbench_lzsse2_init(size_t insize, size_t level, size_t);
    void lzbench_lzsse2_deinit(char* workmem);
    int64_t lzbench_lzsse2_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lzsse2_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    char* lzbench_lzsse4_init(size_t insize, size_t level, size_t);
    void lzbench_lzsse4_deinit(char* workmem);
    int64_t lzbench_lzsse4_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lzsse4_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    char* lzbench_lzsse4fast_init(size_t insize, size_t level, size_t);
    void lzbench_lzsse4fast_deinit(char* workmem);
    int64_t lzbench_lzsse4fast_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    char* lzbench_lzsse8_init(size_t insize, size_t level, size_t);
    void lzbench_lzsse8_deinit(char* workmem);
    int64_t lzbench_lzsse8_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_lzsse8_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    char* lzbench_lzsse8fast_init(size_t insize, size_t level, size_t);
    void lzbench_lzsse8fast_deinit(char* workmem);
    int64_t lzbench_lzsse8fast_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_lzsse2_init NULL
    #define lzbench_lzsse2_deinit NULL
    #define lzbench_lzsse2_compress NULL
    #define lzbench_lzsse2_decompress NULL
    #define lzbench_lzsse4_init NULL
    #define lzbench_lzsse4_deinit NULL
    #define lzbench_lzsse4_compress NULL
    #define lzbench_lzsse4_decompress NULL
    #define lzbench_lzsse4fast_init NULL
    #define lzbench_lzsse4fast_deinit NULL
    #define lzbench_lzsse4fast_compress NULL
    #define lzbench_lzsse8_init NULL
    #define lzbench_lzsse8_deinit NULL
    #define lzbench_lzsse8_compress NULL
    #define lzbench_lzsse8_decompress NULL
    #define lzbench_lzsse8fast_init NULL
    #define lzbench_lzsse8fast_deinit NULL
    #define lzbench_lzsse8fast_compress NULL
#endif


#ifndef BENCH_REMOVE_PPMD
    int64_t lzbench_ppmd_compress(char* inbuf, size_t insize, char* outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_ppmd_decompress(char* inbuf, size_t insize, char* outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_ppmd_compress NULL
    #define lzbench_ppmd_decompress NULL
#endif // BENCH_REMOVE_PPMD


#ifndef BENCH_REMOVE_QUICKLZ
    int64_t lzbench_quicklz_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_quicklz_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_quicklz_compress NULL
    #define lzbench_quicklz_decompress NULL
#endif


#ifndef BENCH_REMOVE_SLZ
    int64_t lzbench_slz_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_slz_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_slz_compress NULL
    #define lzbench_slz_decompress NULL
#endif


#ifndef BENCH_REMOVE_SNAPPY
    int64_t lzbench_snappy_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_snappy_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_snappy_compress NULL
    #define lzbench_snappy_decompress NULL
#endif


#ifndef BENCH_REMOVE_TORNADO
    int64_t lzbench_tornado_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_tornado_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_tornado_compress NULL
    #define lzbench_tornado_decompress NULL
#endif


#ifndef BENCH_REMOVE_UCL
    int64_t lzbench_ucl_nrv2b_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_ucl_nrv2b_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_ucl_nrv2d_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_ucl_nrv2d_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_ucl_nrv2e_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_ucl_nrv2e_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_ucl_nrv2b_compress NULL
    #define lzbench_ucl_nrv2b_decompress NULL
    #define lzbench_ucl_nrv2d_compress NULL
    #define lzbench_ucl_nrv2d_decompress NULL
    #define lzbench_ucl_nrv2e_compress NULL
    #define lzbench_ucl_nrv2e_decompress NULL
#endif


#ifndef BENCH_REMOVE_WFLZ
    char* lzbench_wflz_init(size_t insize, size_t level, size_t);
    void lzbench_wflz_deinit(char* workmem);
    int64_t lzbench_wflz_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_wflz_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_wflz_init NULL
    #define lzbench_wflz_deinit NULL
    #define lzbench_wflz_compress NULL
    #define lzbench_wflz_decompress NULL
#endif


#ifndef BENCH_REMOVE_XZ
extern "C"
{
    int64_t lzbench_xz_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_xz_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
}
#else
    #define lzbench_xz_compress NULL
    #define lzbench_xz_decompress NULL
#endif


#ifndef BENCH_REMOVE_YALZ77
    int64_t lzbench_yalz77_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_yalz77_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_yalz77_compress NULL
    #define lzbench_yalz77_decompress NULL
#endif


#ifndef BENCH_REMOVE_YAPPY
    char* lzbench_yappy_init(size_t insize, size_t level, size_t);
    int64_t lzbench_yappy_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_yappy_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_yappy_init NULL
    #define lzbench_yappy_compress NULL
    #define lzbench_yappy_decompress NULL
#endif


#ifndef BENCH_REMOVE_ZLIB
    int64_t lzbench_zlib_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_zlib_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_zlib_compress NULL
    #define lzbench_zlib_decompress NULL
#endif


#ifndef BENCH_REMOVE_ZLIB_NG
    int64_t lzbench_zlib_ng_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_zlib_ng_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_zlib_ng_compress NULL
    #define lzbench_zlib_ng_decompress NULL
#endif


#ifndef BENCH_REMOVE_ZLING
    int64_t lzbench_zling_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_zling_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_zling_compress NULL
    #define lzbench_zling_decompress NULL
#endif

#ifndef BENCH_REMOVE_ZPAQ
    int64_t lzbench_zpaq_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_zpaq_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_zpaq_compress NULL
    #define lzbench_zpaq_decompress NULL
#endif


#ifndef BENCH_REMOVE_ZSTD
    char* lzbench_zstd_init(size_t insize, size_t level, size_t);
    void lzbench_zstd_deinit(char* workmem);
    int64_t lzbench_zstd_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_zstd_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    char* lzbench_zstd_LDM_init(size_t insize, size_t level, size_t);
    int64_t lzbench_zstd_LDM_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_zstd_init NULL
    #define lzbench_zstd_deinit NULL
    #define lzbench_zstd_compress NULL
    #define lzbench_zstd_decompress NULL
    #define lzbench_zstd_LDM_init NULL
    #define lzbench_zstd_LDM_compress NULL
#endif


#ifdef BENCH_HAS_CUDA
    char* lzbench_cuda_init(size_t insize, size_t, size_t);
    void lzbench_cuda_deinit(char* workmem);
    int64_t lzbench_cuda_memcpy(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_cuda_init NULL
    #define lzbench_cuda_deinit NULL
    #define lzbench_cuda_memcpy NULL
#endif

#ifdef BENCH_HAS_NVCOMP
    char* lzbench_nvcomp_init(size_t insize, size_t level, size_t);
    void lzbench_nvcomp_deinit(char* workmem);
    int64_t lzbench_nvcomp_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_nvcomp_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_nvcomp_init NULL
    #define lzbench_nvcomp_deinit NULL
    #define lzbench_nvcomp_compress NULL
    #define lzbench_nvcomp_decompress NULL
#endif

#ifndef BENCH_REMOVE_TAMP
    char* lzbench_tamp_init(size_t, size_t level, size_t);
    void lzbench_tamp_deinit(char* workmem);
    int64_t lzbench_tamp_compress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
    int64_t lzbench_tamp_decompress(char *inbuf, size_t insize, char *outbuf, size_t outsize, codec_options_t *codec_options);
#else
    #define lzbench_tamp_init NULL
    #define lzbench_tamp_deinit NULL
    #define lzbench_tamp_compress NULL
    #define lzbench_tamp_decompress NULL
#endif

#endif // LZBENCH_COMPRESSORS_H
