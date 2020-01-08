/*
LGMP - Looking Glass Memory Protocol
Copyright (C) 2020 Geoffrey McRae <geoff@hostfission.com>
https://looking-glass.hostfission.com

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place, Suite 330, Boston, MA 02111-1307 USA
*/

#include "lgmp/lgmp.h"
#include <time.h>

struct LGMPQueue
{
  LGMPHost      host;
  LGMPClient    client;
  unsigned int  id;
  unsigned int  index;
  uint32_t      position;

  // host only
  unsigned int start;
  uint64_t     msgTimeout;
  uint64_t     timeout[32];
};

struct LGMPMemory
{
  LGMPHost     host;
  unsigned int offset;
  uint32_t     size;
  void        *mem;
};

inline static uint64_t lgmpGetClock()
{
  struct timespec tsnow;
  clock_gettime(CLOCK_MONOTONIC, &tsnow);
  return tsnow.tv_sec * 1000 + tsnow.tv_nsec / 1000000;
}