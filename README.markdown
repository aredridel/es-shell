kes v0.1
---------

**kes** is a fork of the **es** shell created by Paul Haahr and Byron Rakitzis. It is based on the [**rc** command interpreter](http://doc.cat-v.org/plan_9/4th_edition/papers/rc), part of the [**Plan 9**](http://plan9.bell-labs.com/plan9/) operating system.

See the **CHANGES** file for a list of changes to the shell. See the **INSTALL** file for instructions for installing `es`. In all other ways, I believe that this file is up to date.

Why a fork?
-----------
The purpose of **kes** is to improve on performance and implementation details of **es** and keep the project up to date (that is, avoiding code rot). It is based on the 0.9 beta 1 release of es, which can be found here.

The obvious question here is: "What's the purpose of this fork?" and the honest answer is this: I wanted to experiment with the **es** shell, and it wouldn't compile on OS X, and the code was in the public domain. It's really as simple as that. The purpose of this fork isn't so much to *improve* the shell, but to *maintain the codebase.* That said, there are a few things on the "to do" list that I'd like to work on at some point--but that'll be a while, if only because I'm (at best) a mediocre C programmer. Anyway, enjoy! 

Now for the original **es** readme, which is far more informative than the 

About es
--------

Es is an extensible shell. The language was derived from the Plan 9 shell, rc, and was influenced by functional programming languages, such as Scheme, and the Tcl embeddable programming language. This implementation is derived from Byron Rakitzis's public domain implementation of rc.

>**WARNING:** This is an experimental release of es. Some aspects of this release are unstable. If you aren't feeling adventurous, you may want to use version 0.84.

Building and running kes
------------------------

The Makefile should just work; if it doesn't, please let us know. The first few lines include some comments about what might be problematic. Please see config.h for any conditional flags you may have to set on the command line to make es compile. An ANSI C compiler is practically required.

See the file CHANGES for recent changes to the shell. For details on how to use es, please see the man page, which is unfortunately a bit out of date. The file `initial.es`, which is used to build the initial memory state of the es interpreter, can be read to better understand how pieces of the shell interact.

For some background into our motivation for writing es, see our Winter 1993 Usenix paper, ``Es: a shell with higher-order functions,'' available by anonymous ftp as

`ftp.sys.utoronto.ca:/pub/es/usenix-w93.ps.Z`

The paper corresponds to a slightly older version of the shell; see the file ERRATA for changes which affect parts of the paper.

An old version of Paul's .esrc (es startup) file is provided as an example as esrc.haahr; correctness is not guaranteed. A simple debugger for es scripts, `esdebug`, is also included; this is very untested and should be considered little more than a sketch of a few ideas.

A simple history mechanism for this shell (conceptually derived from the Research Eighth Edition Unix =(1) commands) is available in

`ftp.sys.utoronto.ca:/pub/es/history.tar.Z`

readline and editline
---------------------
**kes** supports the use of GNU readline (or compatible) libraries for interactive command-line editing. Readline may be obtained from any of the many GNU project distribution sites, such as `prep.ai.mit.edu`. Simi Turner wrote a much smaller readline clone called editline which Rich Salz has been maintaining; a copy of it is included within the **kes** GitHub repository.

Credits
----------

>Es is in the public domain. We hold no copyrights or patents on the source code, and do not place any restrictions on its distribution. We would appreciate it if any distributions do credit the authors.

>Enjoy!

>-- Paul Haahr & Byron Rakitzis

This **README** was originally written by Soren Dayton, `csdayton@cs.uchicago.edu`.

