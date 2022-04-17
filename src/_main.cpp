
// $Id: A $

//=================================================================================================
// Original File Name : _main.cpp
// Original Author    : catraeus
// Creation Date      : Apr 17, 2022
// Copyright          : Copyright © 2022 by Catraeus and Duncan Gray
//
// Description        :
/*
   The one and only main()
*/
//
//=================================================================================================
/*
This file is part of almseq.

almseq is free software: you can redistribute it and/or modify it under the terms of
  the GNU Lesser General Public License as published by the Free Software Foundation, either
  version 3 of the License, or (at your option) any later version.

almseq is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without
  even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See
  the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with dmmsnoop.
  If not, see <https://www.gnu.org/licenses/>.
*/
//=================================================================================================

#include <stdio.h>
#include "AlsaMidi.hpp"

int main() {
  int a;

         AlsaMidi   *theMidi;
         snd_seq_t  *seq_handle;
         int         npfd;
  struct pollfd     *pfd;

  theMidi = new AlsaMidi;

  a = 57;
  fprintf(stdout, "Gotcha %d!\n", a); fflush(stdout);



  seq_handle = theMidi->OpenSeq();
  npfd = snd_seq_poll_descriptors_count(seq_handle, POLLIN);
  pfd = (struct pollfd *)alloca(npfd * sizeof(struct pollfd));
  snd_seq_poll_descriptors(seq_handle, pfd, npfd, POLLIN);
  while (1) {
    if (poll(pfd, npfd, 100000) > 0) {
      theMidi->MidiAction(seq_handle);
    }
  }


  delete theMidi;
  return 0;
}
