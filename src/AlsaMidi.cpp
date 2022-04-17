
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

#include "AlsaMidi.hpp"
#include "Cfg/CfgVersion.hpp"
#include <stdio.h>

AlsaMidi::AlsaMidi() {
  fprintf(stdout, "hi\n"); fflush(stdout);
}

AlsaMidi::~AlsaMidi() {
  fprintf(stdout, "bye\n"); fflush(stdout);
}

snd_seq_t *AlsaMidi::OpenSeq(void) {

  snd_seq_t *theSeq;
  int portNo;

  if (snd_seq_open(&theSeq, "default", SND_SEQ_OPEN_INPUT, 0) < 0) {
    fprintf(stderr, "Error opening ALSA sequencer.\n");
    exit(1);
  }
  snd_seq_set_client_name(theSeq, APP_NAME);
  if ((portNo = snd_seq_create_simple_port(theSeq, "MIDI_IN_0",
            SND_SEQ_PORT_CAP_WRITE|SND_SEQ_PORT_CAP_SUBS_WRITE,
            SND_SEQ_PORT_TYPE_APPLICATION)) < 0) {
    fprintf(stderr, "Error creating sequencer port.\n");
    exit(1);
  }
  return(theSeq);
}


void AlsaMidi::MidiAction(snd_seq_t *theSeq) {

  snd_seq_event_t *ev;

  do {
    snd_seq_event_input(theSeq, &ev);
    switch (ev->type) {
      case SND_SEQ_EVENT_CONTROLLER:
        fprintf(stderr, "Control event on Channel %2d: %5d       \n",
                ev->data.control.channel, ev->data.control.value);
        break;
      case SND_SEQ_EVENT_PITCHBEND:
        fprintf(stderr, "Pitchbender event on Channel %2d: %5d   \n",
                ev->data.control.channel, ev->data.control.value);
        break;
      case SND_SEQ_EVENT_NOTEON:
        fprintf(stderr, "NoteOn  ch%02d: %5d\n", ev->data.control.channel, ev->data.note.note);
        break;
      case SND_SEQ_EVENT_NOTEOFF:
        fprintf(stderr, "NoteOff ch%02d: %5d\n",
                ev->data.control.channel, ev->data.note.note);
        break;
    }
    snd_seq_free_event(ev);
  } while (snd_seq_event_input_pending(theSeq, 0) > 0);
  return;
}
