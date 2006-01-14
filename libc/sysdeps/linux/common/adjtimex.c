/* vi: set sw=4 ts=4: */
/*
 * adjtimex() for uClibc
 *
 * Copyright (C) 2000-2004 by Erik Andersen <andersen@codepoet.org>
 *
 * GNU Library General Public License (LGPL) version 2 or later.
 */

#include "syscalls.h"
#include <sys/timex.h>

_syscall1(int, adjtimex, struct timex *, buf);
libc_hidden_proto(adjtimex)
libc_hidden_def(adjtimex)
strong_alias(adjtimex,ntp_adjtime)
