# Makefile for es ($Revision: 1.5 $)

# Some of the advice here is rather old and out of date.  The
# configuration of es will be improved by 0.9beta, but I didn't
# want to hunt out machines from now til eternity.

# see config.h for command-line -D flags you may want to use.
# if you're using SunOS 5 (Solaris 2), be sure to include
# -DSOLARIS in the CFLAGS, since sun made it difficult to
# detect which system you're running.  also, since sun really
# seems to have screwed up and removed both getrusage() and
# wait3() in Solaris 2, you should probably add -DBUILTIN_TIME=0
# to the cflags.  if you're running an OSF1 derivative, try -DOSF1.
# if you're using HP/UX do a -DHPUX.

# also, please use whatever -D flags you need to in order
# to get definitions of all signals from <sys/signal.h>.
# _POSIX_SOURCE, _XOPEN_SOURCE are the obvious ones.

prefix  = /usr/local
exec_prefix	= ${prefix}
mandir	= ${prefix}/share/man
bindir	= ${exec_prefix}/bin
srcdir  = .


SHELL	= /bin/sh
CC	= gcc
INSTALL	= /usr/bin/install -c


## Bison is generating incorrect parsers.  So do not use, for now
# YACC = bison -y

CFLAGS	= $(ADDCFLAGS) -I. -I$(srcdir) -g -O2
LDFLAGS	= $(ADDLDFLAGS) 
LIBS	= $(ADDLIBS) 



HFILES	= config.h es.h gc.h input.h prim.h print.h sigmsgs.h \
	  stdenv.h syntax.h var.h
CFILES	= access.c closure.c conv.c dict.c eval.c except.c fd.c gc.c glob.c \
	  glom.c input.c heredoc.c list.c main.c match.c open.c opt.c \
	  prim-ctl.c prim-etc.c prim-io.c prim-sys.c prim.c print.c proc.c \
	  sigmsgs.c signal.c split.c status.c str.c syntax.c term.c token.c \
	  tree.c util.c var.c vec.c version.c y.tab.c dump.c
OFILES	= access.o closure.o conv.o dict.o eval.o except.o fd.o gc.o glob.o \
	  glom.o input.o heredoc.o list.o main.o match.o open.o opt.o \
	  prim-ctl.o prim-etc.o prim-io.o prim-sys.o prim.o print.o proc.o \
	  sigmsgs.o signal.o split.o status.o str.o syntax.o term.o token.o \
	  tree.o util.o var.o vec.o version.o y.tab.o
OTHER	= Makefile parse.y mksignal
GEN	= esdump y.tab.c y.tab.h y.output token.h sigmsgs.c initial.c

SIGFILES = /usr/include/_types.h /usr/include/i386/_structs.h /usr/include/i386/_types.h /usr/include/i386/signal.h /usr/include/mach/i386/_structs.h /usr/include/machine/_structs.h /usr/include/machine/_types.h /usr/include/machine/signal.h /usr/include/signal.h /usr/include/sys/_posix_availability.h /usr/include/sys/_structs.h /usr/include/sys/_symbol_aliasing.h /usr/include/sys/_types.h /usr/include/sys/appleapiopts.h /usr/include/sys/cdefs.h /usr/include/sys/signal.h 

es	: ${OFILES} initial.o
	${CC} -o es ${LDFLAGS} ${OFILES} initial.o ${LIBS}

esdump	: ${OFILES} dump.o
	${CC} -o esdump ${LDFLAGS} ${OFILES} dump.o ${LIBS}

clean	:
	rm -f es ${OFILES} ${GEN} dump.o initial.o

distclean:	clean
	rm -f config.cache config.log config.h Makefile cscope.out tags TAGS core cs.out config.status

MANIFEST:
	find . -type f | sed s/..// > MANIFEST

install : es
	$(INSTALL) $(srcdir)/es $(bindir)
	$(INSTALL) $(srcdir)/doc/es.1 $(mandir)/man1

test	: trip

trip	: es $(srcdir)/trip.es
	./es < $(srcdir)/trip.es

src	:
	@echo ${OTHER} ${CFILES} ${HFILES}

y.tab.c y.tab.h : parse.y
	${YACC} -vd $(srcdir)/parse.y

token.h : y.tab.h
	-cmp -s y.tab.h token.h || cp y.tab.h token.h

initial.c : esdump $(srcdir)/initial.es
	./esdump < $(srcdir)/initial.es > initial.c

sigmsgs.c : mksignal $(SIGFILES)
	sh $(srcdir)/mksignal $(SIGFILES) > sigmsgs.c

config.h  : config.h.in
	./configure
# for linux use:

# --- dependencies ---

access.o : access.c es.h config.h stdenv.h prim.h 
closure.o : closure.c es.h config.h stdenv.h gc.h 
conv.o : conv.c es.h config.h stdenv.h print.h 
dict.o : dict.c es.h config.h stdenv.h gc.h 
eval.o : eval.c es.h config.h stdenv.h 
except.o : except.c es.h config.h stdenv.h print.h 
fd.o : fd.c es.h config.h stdenv.h 
gc.o : gc.c es.h config.h stdenv.h gc.h 
glob.o : glob.c es.h config.h stdenv.h gc.h 
glom.o : glom.c es.h config.h stdenv.h gc.h 
input.o : input.c es.h config.h stdenv.h input.h 
heredoc.o : heredoc.c es.h config.h stdenv.h gc.h input.h syntax.h 
list.o : list.c es.h config.h stdenv.h gc.h 
main.o : main.c es.h config.h stdenv.h 
match.o : match.c es.h config.h stdenv.h 
open.o : open.c es.h config.h stdenv.h 
opt.o : opt.c es.h config.h stdenv.h 
prim.o : prim.c es.h config.h stdenv.h prim.h 
prim-ctl.o : prim-ctl.c es.h config.h stdenv.h prim.h 
prim-etc.o : prim-etc.c es.h config.h stdenv.h prim.h 
prim-io.o : prim-io.c es.h config.h stdenv.h gc.h prim.h 
prim-sys.o : prim-sys.c es.h config.h stdenv.h prim.h 
print.o : print.c es.h config.h stdenv.h print.h 
proc.o : proc.c es.h config.h stdenv.h prim.h 
signal.o : signal.c es.h config.h stdenv.h sigmsgs.h 
split.o : split.c es.h config.h stdenv.h gc.h 
status.o : status.c es.h config.h stdenv.h
str.o : str.c es.h config.h stdenv.h gc.h print.h 
syntax.o : syntax.c es.h config.h stdenv.h input.h syntax.h token.h 
term.o : term.c es.h config.h stdenv.h gc.h  
token.o : token.c es.h config.h stdenv.h input.h syntax.h token.h 
tree.o : tree.c es.h config.h stdenv.h gc.h 
util.o : util.c es.h config.h stdenv.h 
var.o : var.c es.h config.h stdenv.h gc.h var.h
vec.o : vec.c es.h config.h stdenv.h gc.h 
version.o : version.c es.h config.h stdenv.h 
