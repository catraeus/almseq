// $Id: PageMidiMsg.cpp 554 2020-09-26 21:53:16Z duncang $

//=================================================================================================
// Original File Name : PageMidiMsg.cpp
// Original Author    : duncang
// Creation Date      : Aug 18, 2012
// Copyright          : Copyright © 2011 by Catraeus and Duncan Gray
//
// Description        :
//    The one and only
//
//=================================================================================================

#include "PageMidiMsg.hpp"
#include "WinMain.hpp"
#include <math.h>
#include <caesbase/CaesString.hpp>

        PageMidiMsg::PageMidiMsg         ( void        ) {
  BuildEnv();
  BuildMain();
  Connect();
  }
        PageMidiMsg::~PageMidiMsg        ( void        ) {
  }
void    PageMidiMsg::ReFormat           ( void        ) {
  eDir newDir;
  if(rbtRTTx->get_active())
    newDir = ID_TX;
  else
    newDir = ID_RX;

  if(newDir == theDir) {
    if(!dirty)
      return;
    }
  theDir = newDir;
  return;
}
void    PageMidiMsg::FillStatsRaw       ( void        ) {
  char tStr[256];
  ReFormat();
  dirty = false;

  sprintf(tStr, "%lf", 1.0  );
  ebxRawDC0.set_text(tStr);
  sprintf(tStr, "%lf", 1.0  );
  ebxRawRms0.set_text(tStr);
  sprintf(tStr, "%lf", 1.0  );
  ebxRawPkn0.set_text(tStr);
  IntWithComma       (tStr,                1.0)   ;
  ebxRawOfn0.set_text(tStr);
  sprintf(tStr, "%lf", 1.0  );
  ebxRawPkp0.set_text(tStr);
  IntWithComma       (tStr,                1.0)   ;
  ebxRawOfp0.set_text(tStr);
  double bb;
  bb = 0.0;
  sprintf(tStr, "%lf", bb);
  ebxRawPk0.set_text(tStr);


  return;
  }
void    PageMidiMsg::FillStatsFlt       ( void        ) {
  ReFormat();
  dirty = false;
  return;
}
void    PageMidiMsg::ClearStats         ( void        ) {
  ReFormat();
  if(!dirty)
    return;
  dirty = false;

  ebxRawDC0.set_text("");
  ebxRawRms0.set_text("");
  ebxRawPkn0.set_text("");
  ebxRawOfn0.set_text("");
  ebxRawPkp0.set_text("");
  ebxRawOfp0.set_text("");
  ebxRawPk0.set_text("");

  return;
  }
void    PageMidiMsg::BuildEnv           ( void        ) {
//  tAnBulk  = new AnBulk(sigRaw, sigFlt);
  dirty    = true;
  theDir   = ID_RX;
  return;
}
void    PageMidiMsg::BuildMain          ( void        ) {
  rbtRTTx       = new Gtk::RadioButton("MIDI TX"         );
  rbtRTRx       = new Gtk::RadioButton("MIDI RX"          );

  frmMidiIf           .set_label("MIDI Interface");
  this                ->set_orientation ( Gtk::ORIENTATION_VERTICAL   );
  vbxMsgAll            .set_orientation ( Gtk::ORIENTATION_VERTICAL );
  hbxDir               .set_orientation ( Gtk::ORIENTATION_HORIZONTAL   );
  hbxMidiIf            .set_orientation ( Gtk::ORIENTATION_HORIZONTAL   );
  vbxRaw0              .set_orientation ( Gtk::ORIENTATION_HORIZONTAL   );

  hbxRawDC0            .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxRawRms0           .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxRawPkn0           .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxRawOfn0           .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxRawPkp0           .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxRawOfp0           .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxRawPk0            .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );

  frmMidiIf           .set_label("MIDI Interface");
  lblMidiIfName       .set_label("IF Name");

  frmRaw0              .set_label("Channel 0 - Raw");

  lblRawDC0        .set_text("DC:"         );  lblRawDC0       .set_width_chars( 7);  lblRawDC0       .set_alignment(Gtk::ALIGN_END);
                                               ebxRawDC0       .set_width_chars(13);                                                   ebxRawDC0       .set_editable(false);

  lblRawRms0       .set_text("RMS:"        );  lblRawRms0      .set_width_chars( 7);  lblRawRms0      .set_alignment(Gtk::ALIGN_END);
                                               ebxRawRms0      .set_width_chars(13);                                                   ebxRawRms0      .set_editable(false);

  lblRawPkn0       .set_text("Pk N:"       );  lblRawPkn0      .set_width_chars( 7);  lblRawPkn0      .set_alignment(Gtk::ALIGN_END);
                                               ebxRawPkn0      .set_width_chars(13);                                                   ebxRawPkn0      .set_editable(false);
  lblRawOfn0       .set_text("Off N:"      );  lblRawOfn0      .set_width_chars( 7);  lblRawOfn0      .set_alignment(Gtk::ALIGN_END);
                                               ebxRawOfn0      .set_width_chars(13);                                                   ebxRawOfn0      .set_editable(false);

  lblRawPkp0       .set_text("Pk P:"       );  lblRawPkp0      .set_width_chars( 7);  lblRawPkp0      .set_alignment(Gtk::ALIGN_END);
                                               ebxRawPkp0      .set_width_chars(13);                                                   ebxRawPkp0      .set_editable(false);
  lblRawOfp0       .set_text("Off P:"      );  lblRawOfp0      .set_width_chars( 7);  lblRawOfp0      .set_alignment(Gtk::ALIGN_END);
                                               ebxRawOfp0      .set_width_chars(13);                                                   ebxRawOfp0      .set_editable(false);

  lblRawPk0        .set_text("Pk Abs:"     );  lblRawPk0       .set_width_chars( 7);  lblRawPk0       .set_alignment(Gtk::ALIGN_END);
                                               ebxRawPk0       .set_width_chars(13);                                                   ebxRawPk0       .set_editable(false);

  rbgpDir = rbtRTTx->get_group();
  rbtRTRx     ->set_group(rbgpDir);
  rbtRTTx     ->set_group(rbgpDir);


  this                         ->pack_start   (  vbxMsgAll           , Gtk::PACK_SHRINK, 3);
    vbxMsgAll                   .pack_start   (  frmMidiIf            , Gtk::PACK_SHRINK, 3);
      frmMidiIf                 .add          (  hbxDir                               );
        hbxDir                  .pack_start   ( *rbtRTTx             , Gtk::PACK_SHRINK, 3);
        hbxDir                  .pack_start   ( *rbtRTRx             , Gtk::PACK_SHRINK, 3);
    vbxMsgAll                   .pack_start   (  hbxMidiIf            , Gtk::PACK_SHRINK, 3);
      hbxMidiIf                 .pack_start   (  lblMidiIfName        , Gtk::PACK_SHRINK, 3);
      hbxMidiIf                 .pack_start   (  cbxMidiIfName        , Gtk::PACK_SHRINK, 3);
    vbxMsgAll                   .pack_start   (  frmRaw0             , Gtk::PACK_SHRINK, 3);
      frmRaw0                   .add          (  vbxRaw0                                  );
        vbxRaw0                 .pack_start   (  hbxRawDC0           , Gtk::PACK_SHRINK, 3);
          hbxRawDC0             .pack_start   (  lblRawDC0           , Gtk::PACK_SHRINK, 3);
          hbxRawDC0             .pack_start   (  ebxRawDC0           , Gtk::PACK_SHRINK, 3);
        vbxRaw0                 .pack_start   (  hbxRawRms0          , Gtk::PACK_SHRINK, 3);
          hbxRawRms0            .pack_start   (  lblRawRms0          , Gtk::PACK_SHRINK, 3);
          hbxRawRms0            .pack_start   (  ebxRawRms0          , Gtk::PACK_SHRINK, 3);
        vbxRaw0                 .pack_start   (  hbxRawPkn0          , Gtk::PACK_SHRINK, 3);
          hbxRawPkn0            .pack_start   (  lblRawPkn0          , Gtk::PACK_SHRINK, 3);
          hbxRawPkn0            .pack_start   (  ebxRawPkn0          , Gtk::PACK_SHRINK, 3);
        vbxRaw0                 .pack_start   (  hbxRawOfn0          , Gtk::PACK_SHRINK, 3);
          hbxRawOfn0            .pack_start   (  lblRawOfn0          , Gtk::PACK_SHRINK, 3);
          hbxRawOfn0            .pack_start   (  ebxRawOfn0          , Gtk::PACK_SHRINK, 3);
        vbxRaw0                 .pack_start   (  hbxRawPkp0          , Gtk::PACK_SHRINK, 3);
          hbxRawPkp0            .pack_start   (  lblRawPkp0          , Gtk::PACK_SHRINK, 3);
          hbxRawPkp0            .pack_start   (  ebxRawPkp0          , Gtk::PACK_SHRINK, 3);
        vbxRaw0                 .pack_start   (  hbxRawOfp0          , Gtk::PACK_SHRINK, 3);
          hbxRawOfp0            .pack_start   (  lblRawOfp0          , Gtk::PACK_SHRINK, 3);
          hbxRawOfp0            .pack_start   (  ebxRawOfp0          , Gtk::PACK_SHRINK, 3);
        vbxRaw0                 .pack_start   (  hbxRawPk0           , Gtk::PACK_SHRINK, 3);
          hbxRawPk0             .pack_start   (  lblRawPk0           , Gtk::PACK_SHRINK, 3);
          hbxRawPk0             .pack_start   (  ebxRawPk0           , Gtk::PACK_SHRINK, 3);
  return;
}
void    PageMidiMsg::Connect            ( void        ) {

  rbtRTTx         -> signal_clicked().connect(sigc::mem_fun(*this,  &PageMidiMsg    ::ReScale         ));
  rbtRTRx         -> signal_clicked().connect(sigc::mem_fun(*this,  &PageMidiMsg    ::ReScale         ));
  return;
}
