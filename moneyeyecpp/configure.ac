AC_INIT([MonEyeyeCpp], [0.1], [youremail@some.local])

m4_include([m4/ax_gnu_autotest.m4])
m4_include([m4/ax_boost_base.m4])
m4_include([m4/ax_boost_unit_test_framework.m4])

AC_PREREQ([2.59])
AC_CONFIG_AUX_DIR(config)
AM_INIT_AUTOMAKE([foreign -Wall -Werror])
AC_PROG_CXX
AC_PROG_CC

# by autoscan
AC_CHECK_FUNCS([localeconv])
AC_CHECK_FUNCS([memset])   
AC_CHECK_FUNCS([fesetround])
AC_CHECK_FUNCS([rint])
AC_CHECK_HEADERS([float.h]) 
AC_CHECK_HEADERS([limits.h])
AC_CHECK_HEADERS([locale.h])
AC_CHECK_HEADERS([stddef.h])
AC_CHECK_HEADERS([stdlib.h])
AC_CHECK_HEADERS([string.h])
AC_CHECK_HEADERS([unistd.h])
AC_CHECK_HEADER_STDBOOL     
AC_FUNC_MALLOC              
AC_FUNC_REALLOC             
AC_FUNC_STRTOD              
AC_TYPE_SIZE_T              

AX_BOOST_BASE([1.58])
AX_BOOST_UNIT_TEST_FRAMEWORK
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile src/Makefile t/Makefile])
AC_OUTPUT
