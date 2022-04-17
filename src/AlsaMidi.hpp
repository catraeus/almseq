
// $Id: A $

//=================================================================================================
// Original File Name : AlsaMidi.hpp
// Original Author    : catraeus
// Creation Date      : Apr 17, 2022
// Copyright          : Copyright © 2022 by Catraeus and Duncan Gray
//
// Description        :
/*
   The class wrapper of Alsa MIDI Api stuff
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

#ifndef __ALSA_MIDI_HPP_
#define __ALSA_MIDI_HPP_
#include <alsa/asoundlib.h>

class AlsaMidi {
  public:
	               AlsaMidi   (void);
	  virtual     ~AlsaMidi   (void);
    snd_seq_t   *OpenSeq    (void);
    void         MidiAction (snd_seq_t *seq_handle);
	private:

};

#endif
