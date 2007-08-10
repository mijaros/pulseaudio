#ifndef foopulseoncehfoo
#define foopulseoncehfoo

/* $Id$ */

/***
  This file is part of PulseAudio.

  Copyright 2006 Lennart Poettering

  PulseAudio is free software; you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as
  published by the Free Software Foundation; either version 2 of the
  License, or (at your option) any later version.

  PulseAudio is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with PulseAudio; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
  USA.
***/

#include <pulsecore/mutex.h>
#include <pulsecore/atomic.h>

typedef struct pa_once {
    pa_atomic_ptr_t mutex;
    pa_atomic_t ref, done;
} pa_once;

#define PA_ONCE_INIT                                                    \
    {                                                                   \
        .mutex = PA_ATOMIC_PTR_INIT(NULL),                              \
        .ref = PA_ATOMIC_INIT(0),                                       \
        .done = PA_ATOMIC_INIT(0)                                       \
    }

typedef void (*pa_once_func_t) (void);

void pa_run_once(pa_once *o, pa_once_func_t f);

#endif
