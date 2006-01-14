/* Return information about the filesystem on which FILE resides.
   Copyright (C) 1996, 1997, 1998, 1999, 2000 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

#include <features.h>

#if defined _FILE_OFFSET_BITS && _FILE_OFFSET_BITS != 64 
#undef _FILE_OFFSET_BITS
#define	_FILE_OFFSET_BITS   64
#endif
#ifndef __USE_LARGEFILE64
# define __USE_LARGEFILE64	1
#endif
/* We absolutely do _NOT_ want interfaces silently
 * renamed under us or very bad things will happen... */
#ifdef __USE_FILE_OFFSET64
# undef __USE_FILE_OFFSET64
#endif

#include <string.h>
#include <stddef.h>
#include <sys/statfs.h>

libc_hidden_proto(memcpy)
libc_hidden_proto(statfs)

/* Return information about the filesystem on which FILE resides.  */
int statfs64 (const char *file, struct statfs64 *buf)
{
    struct statfs buf32;

    if (statfs (file, &buf32) < 0)
	return -1;

    buf->f_type = buf32.f_type;
    buf->f_bsize = buf32.f_bsize;
    buf->f_blocks = buf32.f_blocks;
    buf->f_bfree = buf32.f_bfree;
    buf->f_bavail = buf32.f_bavail;
    buf->f_files = buf32.f_files;
    buf->f_ffree = buf32.f_ffree;
    buf->f_fsid = buf32.f_fsid;
    buf->f_namelen = buf32.f_namelen;
    memcpy (buf->f_spare, buf32.f_spare, sizeof (buf32.f_spare));

    return 0;
}
libc_hidden_proto(statfs64)
libc_hidden_def(statfs64)
