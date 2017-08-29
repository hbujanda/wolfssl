#ifndef _NETOS_USER_SETTINGS_H_
#define _NETOS_USER_SETTINGS_H_

/* Verify this is NetOS */
/*
#ifndef _NETOS
#error This user_settings.h header is only designed for NetOS
#endif
*/

/* Configurations */
#if defined(HAVE_FIPS)
    /* FIPS */
    #define OPENSSL_EXTRA
    #define HAVE_THREAD_LS
    #define WOLFSSL_KEY_GEN
    #define HAVE_AESGCM
    #define HAVE_HASHDRBG
    #define WOLFSSL_SHA384
    #define WOLFSSL_SHA512
    #define NO_PSK
    #define NO_HC128
    #define NO_RC4
    #define NO_RABBIT
    #define NO_DSA
    #define NO_MD4
#elif defined(WOLFSSL_LIB)
    /* The lib */
    #define THREADX
    #define BIG_ENDIAN_ORDER
    #define OPENSSL_EXTRA
    #define WOLFSSL_RIPEMD
    #define WOLFSSL_SHA512
    #define NO_PSK
    #define HAVE_EXTENDED_MASTER
    #define BUILD_TLS_RSA_WITH_AES_128_CBC_SHA
    #define BUILD_TLS_RSA_WITH_AES_256_CBC_SHA
    #define HAVE_TLS_EXTENSIONS
    #define HAVE_SECURE_RENEGOTIATION
    #define NO_WRITEV
    #define NO_WOLFSSL_DIR
    #define DEBUG_WOLFSSL
    #define NO_DEV_RANDOM
    #define NETOS
    #define HAVE_STUNNEL
#else
    /* The servers and clients */
    #define THREADX
    #define BIG_ENDIAN_ORDER
    #define OPENSSL_EXTRA
    #define NO_PSK
    #define NO_WRITEV
    #define NO_WOLFSSL_DIR
    #define WOLFSSL_NO_CURRDIR
    #define DEBUG_WOLFSSL
    #define NETOS
    #define HAVE_STUNNEL
#endif /* HAVE_FIPS */

#endif /* _NETOS_USER_SETTINGS_H_ */
