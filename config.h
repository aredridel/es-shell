/* config.h.  Generated automatically by configure.  */
/* config.h.in.  Generated automatically from configure.in by autoheader.  */

/* Define to empty if the keyword does not work.  */
/* #undef const */

/* Define to the type of elements in the array set by `getgroups'.
   Usually this is either `int' or `gid_t'.  */
#define GETGROUPS_T gid_t

/* Define to `int' if <sys/types.h> doesn't define.  */
/* #undef gid_t */

/* Define if you have a working `mmap' system call.  */
#define HAVE_MMAP 1

/* Define if system calls automatically restart after interruption
   by a signal.  */
/* #undef HAVE_RESTARTABLE_SYSCALLS */

/* Define if you have <sys/wait.h> that is POSIX.1 compatible.  */
#define HAVE_SYS_WAIT_H 1

/* Define if you have the wait3 system call.  */
#define HAVE_WAIT3 1

/* Define as the return type of signal handlers (int or void).  */
#define RETSIGTYPE void

/* Define to `unsigned' if <sys/types.h> doesn't define.  */
/* #undef size_t */

/* Define if you have the ANSI C header files.  */
#define STDC_HEADERS 1

/* Define to `int' if <sys/types.h> doesn't define.  */
/* #undef uid_t */

/* Define if you have the getpagesize function.  */
#define HAVE_GETPAGESIZE 1

/* Do you have a sysconf? */
#define HAVE_SYSCONF 1

/* Define if you have the lstat function.  */
#define HAVE_LSTAT 1

/* Define if you have the setrlimit function.  */
#define HAVE_SETRLIMIT 1

/* Define if you have the strerror function.  */
#define HAVE_STRERROR 1

/* Define if you have the strtol function.  */
#define HAVE_STRTOL 1

/* Define if you have the valloc function.  */
/* #undef HAVE_VALLOC */

/* Define if you have the <dirent.h> header file.  */
#define HAVE_DIRENT_H 1

/* Define if you have the <fcntl.h> header file.  */
#define HAVE_FCNTL_H 1

/* Define if you have the <limits.h> header file.  */
#define HAVE_LIMITS_H 1

/* Define if you have the <memory.h> header file.  */
#define HAVE_MEMORY_H 1

/* Define if you have the <ndir.h> header file.  */
/* #undef HAVE_NDIR_H */

/* Define if you have the <stdarg.h> header file.  */
#define HAVE_STDARG_H 1

/* Define if you have the <sys/dir.h> header file.  */
/* #undef HAVE_SYS_DIR_H */

/* Define if you have the <sys/ioctl.h> header file.  */
#define HAVE_SYS_IOCTL_H 1

/* Define if you have the <sys/ndir.h> header file.  */
/* #undef HAVE_SYS_NDIR_H */

/* Define if you have the <sys/time.h> header file.  */
#define HAVE_SYS_TIME_H 1

/* Define if you have the <unistd.h> header file.  */
#define HAVE_UNISTD_H 1

/* Define if you have the editline library (-leditline).  */
/* #undef HAVE_LIBEDITLINE */

/* Define if you have the readline library (-lreadline).  */
#define HAVE_LIBREADLINE 1

/* Define if you have the sun library (-lsun).  */
/* #undef HAVE_LIBSUN */

/* Define if you have the termcap library (-ltermcap).  */
/* #undef HAVE_LIBTERMCAP */

/* Define if you have the terminfo library (-lterminfo).  */
/* #undef HAVE_LIBTERMINFO */

/* Do you have a /dev/fd/ directory? */
#define HAVE_DEV_FD 1

/* Do you have sighold? */
#define HAVE_SIGHOLD 1

/* Do you have sigrelse? */
#define HAVE_SIGRELSE 1

/* Do you have sigaction? */
#define HAVE_SIGACTION 1

/* Does your kernel support #!? */
#define KERNEL_POUNDBANG 1

/* What type are your signals? */
#define VOID_SIGNALS 1

/* What type are your limits? */
#define LIMIT_T rlim_t 

/* are we solaris? */
/* #undef SOLARIS */

/* Is getenv called by crt*.o or getopt? */
/* #undef ABUSED_GETENV */

/* Do you have setsid? */
#define HAVE_SETSID 1

/* Do you have a new fnagled sys/cdefs.h? */
#define HAVE_SYS_CDEFS_H 1

/* Can I assign to va_lists's */
/* #undef NO_VA_LIST_ASSIGN */

/* does sigsetjmp exist? */
/* #undef HAVE_SIGSETJMP */
