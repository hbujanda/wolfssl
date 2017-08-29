#
# All application Makefiles should define the following macros:
#
#   NETOS_DIR       :  relative path to the "netos" toplevel
#   BUILD_RAM_IMAGE :  set to "0" if not desired, and to "1"
#                      if desired (and supported by platform)
#   BUILD_ROM_IMAGE :  set to "0" if not desired, and to "1"
#                      if desired (and supported by platform)
#   APP_C_FILES     :  list of application specific "C" files
#                      (must all have a ".c" suffix)
#   APP_C_FLAGS     :  application specific CFLAGS
#   APP_CC_FILES    :  list of application specific "C++" files
#                      (must all have either a ".cc", ".C", or ".cxx" suffix)
#   APP_CC_FLAGS    :  application specific CFLAGS for C++ compilation
#   APP_ASM_FILES   :  list of application specific assembly files
#                      (must all have either a ".s", ".S", or ".arm" suffix)
#   APP_ASM_FLAGS   :  application specific ASFLAGS for assembly
#   APP_INCDIRS     :  list of application specific include directories
#                      in "-I.." format.
#
#   APP_DESCRIPTION :  Simple one line description of application
#                      (for applicable platforms, will be incorporated
#                      into the binary VPD)
#
#   USE_SIMPLE_WEB_SERVER : set to "1" if desired (used for compatibility
#                           with older examples... links against a different
#                           set of libraries)
#
#   INCLUDE_CXX_STARTUP : set to "1" to include C++ initialization libraries
#
#   APP_OBJ_FILES   :  An optional veriable which can specify "extra"
#                      objects to be linked into an image which are
#                      not derived from c, c++, or assembly.  The
#                      application Makefile bears the burden of providing
#                      rules to build these files if necessary.
#
# The application Makefile should also include VPATH specifications
# for all application source.
#

NETOS_DIR= ../../../../..

BUILD_RAM_IMAGE= 1
BUILD_ROM_IMAGE= 0

APP_DESCRIPTION="WolfSSL Client Example Application"

vpath %.c ..

APP_C_FILES=root.c

APP_CC_FILES=
APP_ASM_FILES=

APP_C_FLAGS= -DWOLFSSL_USER_SETTINGS -DCYASSL_USER_SETTINGS
APP_CC_FLAGS=
APP_ASM_FLAGS=

APP_INCDIRS= -I..
APP_INCDIRS+= -I../../..
APP_INCDIRS +=  -I. -I$(NETOS_DIR)/h -I$(NETOS_DIR)/h/threadx -I$(NETOS_DIR)/h/tcpip -I$(NETOS_DIR)/src/wolfssl/IDE/NETOS


# All libraries needed for this examples:
APP_LIBS = $(NETOS_LIBPATH)/libfilesys.a \
            $(NETOS_BSPLIBPATH)/libbsp.a \
            $(NETOS_LIBPATH)/libcrypto.a \
            $(NETOS_LIBPATH)/libftpsvr.a \
            $(NETOS_LIBPATH)/libflash.a \
            $(NETOS_LIBPATH)/libposix.a \
            $(NETOS_LIBPATH)/libtx.a \
            $(NETOS_LIBPATH)/libdnsclnt.a \
            $(NETOS_LIBPATH)/libaddp.a \
            $(NETOS_LIBPATH)/libssh.a \
            $(NETOS_LIBPATH)/libtelnsvr.a \
            $(NETOS_LIBPATH)/libpppintf.a \
            $(NETOS_LIBPATH)/libtcpip_no_ipsec.a \
            $(NETOS_LIBPATH)/libwps.a \
            $(NETOS_LIBPATH)/libedp.a \
            $(NETOS_LIBPATH)/libsntp.a \
            $(NETOS_LIBPATH)/libz.a \
            $(NETOS_LIBPATH)/libssl.a \
            $(NETOS_LIBPATH)/libwolfssl.a
            

#########################################################
# Makefile.tools requires BASEDIR for appropriate BSP 
#
BASEDIR =$(NETOS_DIR)

#
# Include common compiler tools setup.
#
-include $(NETOS_DIR)/Makefile.tools

#
# Include all libraries for wiwave. 
# These libraries are only available for arm9 and must be listed after Makefile.tools
# for arm9 to be defined. 
#
ifeq '$(CPU)' 'arm9'
APP_LIBS += $(NETOS_LIBPATH)/libusbhub.a \
            $(NETOS_LIBPATH)/libusbwifi.a \
            $(NETOS_LIBPATH)/libusbhost.a \
            $(NETOS_LIBPATH)/libusbprinter.a \
            $(NETOS_LIBPATH)/libusbkeyboard.a \
            $(NETOS_LIBPATH)/libusbmassstorage.a \
            $(NETOS_LIBPATH)/libusbmouse.a
endif

ifneq ($(findstring $(PLATFORM), connectwime9210),)
ifeq '$(CPU)' 'arm9'
APP_LIBS += $(NETOS_LIBPATH)/libredpine.a \
            $(NETOS_LIBPATH)/libwpa_redpine.a

else
APP_LIBS += $(NETOS_LIBPATH)/libwpa.a
endif
else
APP_LIBS += $(NETOS_LIBPATH)/libwpa.a
endif

#
# All "required" elements must be supplied prior to including the
# "core" Makefile and targets.
#

include $(NETOS_DIR)/src/linkerScripts/Makefile.app.inc

#
# Application specific macros and targets can go below here.
#
TARGET_CFLAGS +=-Wno-error


