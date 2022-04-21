
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

#include <gtkmm.h>
#include <stdio.h>
#include <string.h>




#include "Cfg/CfgEnv.hpp"
#include "Cfg/CfgStrings.hpp"
#include "Cfg/CfgParticles.hpp"


#include "AlsaMidi.hpp"

class MainConts { // total BS to shut up the warning about setting but not using.
  public:


    CfgEnv         *ce;
    CfgStrings     *cs;
    Glib::ustring  *ss;
    CfgParticles   *cp;
};

//=================================================================================================
int main(int i_argc, char *i_argv[], char *i_envp[]) {
         MainConts      m;
         int            dd_argc;
         int a;

         AlsaMidi   *theMidi;
         snd_seq_t  *seq_handle;
         int         npfd;
  struct pollfd     *pfd;

  m.ce       =     CfgEnv             :: GetInstance  ( i_argc, i_argv, i_envp   );  // Dangerous Singleton  Be very glad it is done here in main before anything else.
  m.cs       =     CfgStrings         :: GetInstance  ( "English", m.ce->buildNo );  // Dangerous Singleton  Be very glad it is done here in main before anything else.
  m.ss       = new Glib               :: ustring      ( m.ce->appId              );
  dd_argc    = 1;
  auto app   =     Gtk::Application   :: create       ( dd_argc, i_argv, *(m.ss), Gio::APPLICATION_FLAGS_NONE);
  m.cp       =     CfgParticles       :: GetInstance  (                          );  // CfgParticles has GdkPixbufs in it so it has to go after app is created.
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
