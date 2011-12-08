/* stdenv.h -- set up an environment we can use ($Revision: 1.25 $) */


/*
 * type qualifiers
 */

#if !USE_CONST
#define	const
#endif

#if !USE_VOLATILE
#define	volatile
#endif


/*
 * protect the rest of es source from the dance of the includes
 */

#if USE_UNISTD
#include <unistd.h>
#endif

#if REQUIRE_PARAM
#include <sys/param.h>
#endif

#include <string.h>
#include <stddef.h>

#if USE_MEMORY
#include <memory.h>
#endif

#if USE_STDARG
#include <stdarg.h>
#else
#include <varargs.h>
#endif

#include <errno.h>
#include <setjmp.h>
#include <signal.h>
#include <ctype.h>

#if REQUIRE_STAT || REQUIRE_IOCTL
#include <sys/types.h>
#endif

#if REQUIRE_IOCTL
#include <sys/ioctl.h>
#endif

#if REQUIRE_STAT
#include <sys/stat.h>
#endif

#if REQUIRE_DIRENT
#if USE_DIRENT
#include <dirent.h>
typedef struct dirent Dirent;
#else
#include <sys/dir.h>
typedef struct direct Dirent;
#endif
/* prototypes for XXXdir functions. comment out if necessary */
#if !HPUX
extern DIR *opendir(const char *);
extern Dirent *readdir(DIR *);
/*extern int closedir(DIR *);*/
#endif
#endif

#if REQUIRE_PWD
#include <pwd.h>
#endif

#if REQUIRE_FCNTL
#include <fcntl.h>
#endif

#include <sys/wait.h>


/*
 * things that should be defined by header files but might not have been
 */

#ifndef	offsetof
#define	offsetof(t, m)	((size_t) (((char *) &((t *) 0)->m) - (char *)0))
#endif

#ifndef	EOF
#define	EOF	(-1)
#endif


/*
 * macros
 */

#define	streq(s, t)		(strcmp(s, t) == 0)
#define	strneq(s, t, n)		(strncmp(s, t, n) == 0)
#define	hasprefix(s, p)		strneq(s, p, (sizeof p) - 1)
#define	arraysize(a)		((int) (sizeof (a) / sizeof (*a)))
#define	memzero(dest, count)	memset(dest, 0, count)
#define	atoi(s)			strtol(s, NULL, 0)

#if SOLARIS
#define	STMT(stmt)		if (1) { stmt; } else
#define	NOP			if (1) ; else
#else
#define	STMT(stmt)		do { stmt; } while (0)
#define	NOP			do ; while (0)
#endif

#if REISER_CPP
#define CONCAT(a,b)	a/**/b
#define STRING(s)	"s"
#else
#define CONCAT(a,b)	a ## b
#define STRING(s)	#s
#endif


/*
 * types we use throughout es
 */

#undef FALSE
#undef TRUE
typedef enum { FALSE, TRUE } Boolean;

#if __GNUC__
typedef volatile void noreturn;
#else
typedef void noreturn;
#endif

#if USE_SIG_ATOMIC_T
typedef volatile sig_atomic_t Atomic;
#else
typedef volatile int Atomic;
#endif

#if VOID_SIGNALS
typedef void Sigresult;
#define	SIGRESULT
#else
typedef int Sigresult;
#define	SIGRESULT	0
#endif

#if GETGROUPS_USES_GID_T
typedef gid_t gidset_t;
#else
typedef int gidset_t;
#endif


/*
 * variable argument lists
 */

#if USE_STDARG

#define	VARARGS				, ...
#define	VARARGS1(t1, v1)		(t1 v1, ...)
#define	VARARGS2(t1, v1, t2, v2)	(t1 v1, t2 v2, ...)
#define	VA_START(ap, v)			va_start(ap, v)

#else	/* !USE_STDARG */

#define	VARARGS
#define	VARARGS1(t1, v1)		(v1, va_alist) t1 v1; va_dcl
#define	VARARGS2(t1, v1, t2, v2)	(v1, v2, va_alist) t1 v1; t2 v2; va_dcl
#define	VA_START(ap, var)		va_start(ap)

#endif


/*
 * assertion checking
 */

#if ASSERTIONS
#define	assert(expr) \
	STMT( \
		if (!(expr)) { \
			eprint("%s:%d: assertion failed (%s)\n", \
				__FILE__, __LINE__, STRING(expr)); \
			abort(); \
		} \
	)
#else
#define	assert(ignore)	NOP
#endif

enum { UNREACHABLE = 0 };
#define	NOTREACHED	STMT(assert(UNREACHABLE))

/*
 * system calls -- can we get these from some standard header uniformly?
 */

#if !USE_UNISTD
extern int chdir(const char *dirname);
extern int close(int fd);
extern int dup(int fd);
extern int dup2(int srcfd, int dstfd);
extern int execve(char *name, char **argv, char **envp);
extern int fork(void);
extern int getegid(void);
extern int geteuid(void);
extern int getpagesize(void);
extern int getpid(void);
extern int pipe(int p[2]);
extern int read(int fd, void *buf, size_t n);
extern int setpgrp(int pid, int pgrp);
extern int umask(int mask);
extern int write(int fd, const void *buf, size_t n);

#if REQUIRE_IOCTL
extern int ioctl(int fd, int cmd, void *arg);
#endif

#if REQUIRE_STAT
extern int stat(const char *, struct stat *);
#endif

#ifdef NGROUPS
extern int getgroups(int, int *);
#endif
#endif	/* !USE_UNISTD */


/*
 * hacks to present a standard system call interface
 */

#ifdef linux
#include "unistd.h"
#define setpgrp(a, b)	setpgid(a, b)
#endif

#if sgi
#define	setpgrp(a, b)	BSDsetpgrp(a,b)
#endif

#if SOLARIS
#define	setpgrp(a, b)	setsid();
#endif

#if HPUX
#define	setpgrp(a, b)	setpgrp()
#endif

#if !HAS_LSTAT
#define	lstat	stat
#endif


/*
 * macros for picking apart statuses
 *	we should be able to use the W* forms from <sys/wait.h> but on
 *	some machines they take a union wait (what a bad idea!) and on
 *	others an integer.  we just renamed the first letter to s and
 *	let things be.  on some systems these could just be defined in
 *	terms of the W* forms.
 */

#define	SIFSIGNALED(status)	(((status) & 0xff) != 0)
#define	STERMSIG(status)	((status) & 0x7f)
#define	SCOREDUMP(status)	((status) & 0x80)
#define	SIFEXITED(status)	(!SIFSIGNALED(status))
#define	SEXITSTATUS(status)	(((status) >> 8) & 0xff)


/*
 * the c library -- these should be in prototypes in standard headers
 */

/* stdlib */

extern noreturn exit(int);
extern noreturn abort(void);
extern long strtol(const char *num, char **end, int base);
extern void *qsort(
	void *base, size_t nmemb, size_t size,
	int (*compar)(const void *, const void *)
);

/* setjmp */

/*
extern int setjmp(jmp_buf env);
extern noreturn longjmp(jmp_buf env, int val);
*/
