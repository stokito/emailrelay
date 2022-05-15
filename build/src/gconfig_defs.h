/* src/gconfig_defs.h.  Generated from gconfig_defs.h.in by configure.  */
/* src/gconfig_defs.h.in.  Generated from configure.ac by autoheader.  */

/* Define true to use epoll */
#define GCONFIG_ENABLE_EPOLL 1

/* Define true to use IPv6 */
#define GCONFIG_ENABLE_IPV6 1

/* Define true to use std::thread */
#define GCONFIG_ENABLE_STD_THREAD 1

/* Define true if arpa/inet.h is available */
#define GCONFIG_HAVE_ARPA_INET_H 1

/* Define true if compiler has std::align() */
#define GCONFIG_HAVE_CXX_ALIGNMENT 1

/* Define true if compiler has std::make_unique */
#define GCONFIG_HAVE_CXX_MAKE_UNIQUE 0

/* Define true if compiler has std::thread */
#define GCONFIG_HAVE_CXX_STD_THREAD 1

/* Define true to enable use of epoll */
#define GCONFIG_HAVE_EPOLL 1

/* Define true if errno.h is available */
#define GCONFIG_HAVE_ERRNO_H 1

/* Define true if errno_t type definition in error.h */
#define GCONFIG_HAVE_ERRNO_T 0

/* Define true if have execvpe() in unistd.h */
#define GCONFIG_HAVE_EXECVPE 1

/* Define true if extended fstream::open() is available */
#define GCONFIG_HAVE_EXTENDED_OPEN 0

/* Define true if _fsopen() is available */
#define GCONFIG_HAVE_FSOPEN 0

/* Define true if gai_strerror() is available */
#define GCONFIG_HAVE_GAISTRERROR 1

/* Define true if getenv_s in stdlib.h */
#define GCONFIG_HAVE_GETENV_S 0

/* Define true if getgrnam in pwd.h */
#define GCONFIG_HAVE_GETGRNAM 1

/* Define true if getgrnam_r in pwd.h */
#define GCONFIG_HAVE_GETGRNAM_R 1

/* Define true if getpwnam in pwd.h */
#define GCONFIG_HAVE_GETPWNAM 1

/* Define true if getpwnam_r in pwd.h */
#define GCONFIG_HAVE_GETPWNAM_R 1

/* Define true to use gettext */
#define GCONFIG_HAVE_GETTEXT 1

/* Define true if gid_t is a type */
#define GCONFIG_HAVE_GID_T 1

/* Define true if gmtime_r in time.h */
#define GCONFIG_HAVE_GMTIME_R 1

/* Define true if gmtime_s in time.h */
#define GCONFIG_HAVE_GMTIME_S 0

/* Define true if grp.h is available */
#define GCONFIG_HAVE_GRP_H 1

/* Define true if if_nametoindex() is available */
#define GCONFIG_HAVE_IFNAMETOINDEX 1

/* Define true if ConvertInterfaceNameToLuid() is available */
#define GCONFIG_HAVE_IFNAMETOLUID 0

/* Define true if inet_ntop() is available */
#define GCONFIG_HAVE_INET_NTOP 1

/* Define true if inet_pton() is available */
#define GCONFIG_HAVE_INET_PTON 1

/* Define true if compiler has int16_t in stdint.h */
#define GCONFIG_HAVE_INT16 1

/* Define true if compiler has int32_t in stdint.h */
#define GCONFIG_HAVE_INT32 1

/* Define true if compiler has int64_t in stdint.h */
#define GCONFIG_HAVE_INT64 1

/* Define true if inttypes.h is available */
#define GCONFIG_HAVE_INTTYPES_H 1

/* Define true if struct iovec has a simple layout */
#define GCONFIG_HAVE_IOVEC_SIMPLE 1

/* Define true if ipv6 is available */
#define GCONFIG_HAVE_IPV6 1

/* Define true if localtime_r in time.h */
#define GCONFIG_HAVE_LOCALTIME_R 1

/* Define true if localtime_s in time.h */
#define GCONFIG_HAVE_LOCALTIME_S 0

/* Define true to enable mbedtls */
#define GCONFIG_HAVE_MBEDTLS 1

/* Define true to use deprecated mbedtls/net.h */
#define GCONFIG_HAVE_MBEDTLS_NET_H 0

/* Define true if netdb.h is available */
#define GCONFIG_HAVE_NETDB_H 1

/* Define true if netinet/in.h is available */
#define GCONFIG_HAVE_NETINET_IN_H 1

/* Define true to enable use of bsd routing sockets */
#define GCONFIG_HAVE_NETROUTE 0

/* Define true if net/if.h is available */
#define GCONFIG_HAVE_NET_IF_H 1

/* Define true to enable openssl */
#define GCONFIG_HAVE_OPENSSL 1

/* Define true if openssl has SSL_set_min_proto_version */
#define GCONFIG_HAVE_OPENSSL_MIN_MAX 1

/* Define true if openssl has TLS_method */
#define GCONFIG_HAVE_OPENSSL_TLS_METHOD 1

/* Define true to use pam */
#define GCONFIG_HAVE_PAM 1

/* Define true to include pam_appl.h as-is */
#define GCONFIG_HAVE_PAM_IN_INCLUDE 0

/* Define true to include pam_appl.h from pam */
#define GCONFIG_HAVE_PAM_IN_PAM 0

/* Define true to include pam_appl.h from security */
#define GCONFIG_HAVE_PAM_IN_SECURITY 1

/* Define true if pid_t is a type */
#define GCONFIG_HAVE_PID_T 1

/* Define true if have OSX proc_pidpath() */
#define GCONFIG_HAVE_PROC_PIDPATH 0

/* Define true if pthread_sigmask() is available */
#define GCONFIG_HAVE_PTHREAD_SIGMASK 1

/* Define true if putenv_s in stdlib.h */
#define GCONFIG_HAVE_PUTENV_S 0

/* Define true if pwd.h is available */
#define GCONFIG_HAVE_PWD_H 1

/* Define true if have readlink() in unistd.h */
#define GCONFIG_HAVE_READLINK 1

/* Define true to enable use of linux rtnetlink */
#define GCONFIG_HAVE_RTNETLINK 1

/* Define true if setgroups is available */
#define GCONFIG_HAVE_SETGROUPS 1

/* Define true if setpgrp has two parameters */
#define GCONFIG_HAVE_SETPGRP_BSD 0

/* Define true if sigprocmask() is available */
#define GCONFIG_HAVE_SIGPROCMASK 1

/* Define true if sockaddr_in6 has a sin6_len member */
#define GCONFIG_HAVE_SIN6_LEN 0

/* Define true if socklen_t type definition in sys/socket.h */
#define GCONFIG_HAVE_SOCKLEN_T 1

/* Define true if _sopen() is available */
#define GCONFIG_HAVE_SOPEN 0

/* Define true if _sopen_s() is available */
#define GCONFIG_HAVE_SOPEN_S 0

/* Define true if ssize_t type is defined */
#define GCONFIG_HAVE_SSIZE_T 1

/* Define true if statbuf has a st_atim.tv_nsec member */
#define GCONFIG_HAVE_STATBUF_NSEC 1

/* Define true if statbuf has a st_atimespec member */
#define GCONFIG_HAVE_STATBUF_TIMESPEC 0

/* Define true if stdint.h is available */
#define GCONFIG_HAVE_STDINT_H 1

/* Define true if strncpy_s in string.h */
#define GCONFIG_HAVE_STRNCPY_S 0

/* Define true if sys/mman.h is available */
#define GCONFIG_HAVE_SYS_MMAN_H 1

/* Define true if sys/select.h is available */
#define GCONFIG_HAVE_SYS_SELECT_H 1

/* Define true if sys/socket.h is available */
#define GCONFIG_HAVE_SYS_SOCKET_H 1

/* Define true if sys/stat.h is available */
#define GCONFIG_HAVE_SYS_STAT_H 1

/* Define true if sys/types.h is available */
#define GCONFIG_HAVE_SYS_TYPES_H 1

/* Define true if sys/utsname.h is available */
#define GCONFIG_HAVE_SYS_UTSNAME_H 1

/* Define true if sys/wait.h is available */
#define GCONFIG_HAVE_SYS_WAIT_H 1

/* Define true to use unix domain sockets */
#define GCONFIG_HAVE_UDS 1

/* Define true if uid_t is a type */
#define GCONFIG_HAVE_UID_T 1

/* Define true if uintptr_t type is defined stdint.h */
#define GCONFIG_HAVE_UINTPTR_T 1

/* Define true if unistd.h is available */
#define GCONFIG_HAVE_UNISTD_H 1

/* Define true if windows CreateEventEx is available */
#define GCONFIG_HAVE_WINDOWS_CREATE_EVENT_EX 0

/* Define true if windows CreateWaitableTimerEx is available */
#define GCONFIG_HAVE_WINDOWS_CREATE_WAITABLE_TIMER_EX 0

/* Define true if windows InitCommonControlsEx is available */
#define GCONFIG_HAVE_WINDOWS_INIT_COMMON_CONTROLS_EX 0

/* Define true if iphlpapi.h is available */
#define GCONFIG_HAVE_WINDOWS_IPHLPAPI_H 0

/* Define true if versionhelpers.h is available */
#define GCONFIG_HAVE_WINDOWS_VERSIONHELPERS_H 0

/* Define true for a windows build using the mingw tool chain */
#define GCONFIG_MINGW 0

/* Define to disable the G_LOG macro */
/* #undef GCONFIG_NO_LOG */

/* Define true if the PAM API uses const */
#define GCONFIG_PAM_CONST 1

/* Define true for a windows build */
#define GCONFIG_WINDOWS 0

/* define if the compiler supports basic C++11 syntax */
#define HAVE_CXX11 1

/* Define to 1 if the system has the type `gid_t'. */
#define HAVE_GID_T 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if the system has the type `pid_t'. */
#define HAVE_PID_T 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdio.h> header file. */
#define HAVE_STDIO_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if the system has the type `uid_t'. */
#define HAVE_UID_T 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME "E-MailRelay"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "E-MailRelay 2.4dev1"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "emailrelay"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "2.4dev1"

/* Define to 1 if all of the C90 standard headers exist (not just the ones
   required in a freestanding environment). This macro is provided for
   backward compatibility; new code need not use it. */
#define STDC_HEADERS 1

/* Define to enable debug messages at compile-time */
/* #undef _DEBUG */
