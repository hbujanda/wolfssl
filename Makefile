######################################################################
#
#    Child Makefile used to build wolfssl Engine library.
#
######################################################################

# Root directory for netos.
BASEDIR=../..

# Include the parent makefile.
all: localall
-include $(BASEDIR)/Makefile.inc

# Add stuff here for additional cleanup
localclean: clean_my_objs

component_clobber: clean_my_libs

# clean up
clean:
	rm -f $(C_OBJ)

# Location of object files.
OBJS = ./objs/$(PROCESSOR)/$(ENDIANDIR)/$(TOOLSET)

#
# The list of source directories.
#
SRCDIR=$(BASEDIR)/src/wolfssl/wolfcrypt/src:$(BASEDIR)/src/wolfssl/src

#
# The name and path of the library to be built.
#
ifeq ($(DEBUG), on)
LOCAL_LIB = $(BASEDIR)/$(LIBDIR)/libwolfssldbg.a
else
LOCAL_LIB = $(BASEDIR)/$(LIBDIR)/libwolfssl.a
endif

#
# Search path for source header files, specific to this library
#
INCDIRS +=  -I. -I./../../h -I./../../h/threadx -I./../../h/tcpip -I./IDE/NETOS

#
# List of C object files for this library.
#
C_OBJ=	$(OBJS)/aes.o\
	$(OBJS)/arc4.o\
	$(OBJS)/asn.o\
	$(OBJS)/blake2b.o\
	$(OBJS)/camellia.o\
	$(OBJS)/coding.o\
	$(OBJS)/chacha.o\
	$(OBJS)/chacha20_poly1305.o\
	$(OBJS)/crl.o\
	$(OBJS)/des3.o\
	$(OBJS)/dh.o\
	$(OBJS)/dsa.o\
	$(OBJS)/ecc.o\
	$(OBJS)/error.o\
	$(OBJS)/hash.o\
	$(OBJS)/hc128.o\
	$(OBJS)/hmac.o\
	$(OBJS)/integer.o\
	$(OBJS)/internal.o\
	$(OBJS)/wolfio.o\
	$(OBJS)/keys.o\
	$(OBJS)/logging.o\
	$(OBJS)/md4.o\
	$(OBJS)/md5.o\
	$(OBJS)/memory.o\
	$(OBJS)/ocsp.o\
	$(OBJS)/pkcs7.o\
	$(OBJS)/pkcs12.o\
	$(OBJS)/poly1305.o\
	$(OBJS)/wc_port.o\
	$(OBJS)/pwdbased.o\
	$(OBJS)/rabbit.o\
	$(OBJS)/random.o\
	$(OBJS)/ripemd.o\
	$(OBJS)/rsa.o\
	$(OBJS)/sha.o\
	$(OBJS)/sha256.o\
	$(OBJS)/sha512.o\
	$(OBJS)/signature.o\
	$(OBJS)/ssl.o\
	$(OBJS)/tls.o\
	$(OBJS)/wc_encrypt.o\
	$(OBJS)/wolfevent.o

#
# List of C++ object files.
#
CC_OBJ=

#
# List of assembly object files.
#
S_OBJ=	

#
# Any extra compilier flags.
#
MY_CFLAGS =

#
# Any extra defines go here
#
MY_DEFINES = -DWOLFSSL_LIB -DWOLFSSL_USER_SETTINGS -DCYASSL_USER_SETTINGS

-include $(BASEDIR)/Makefile.bld


