// $Id: PageAnBulk.cpp 554 2020-09-26 21:53:16Z duncang $

//=================================================================================================
// Original File Name : PageAnBulk.cpp
// Original Author    : duncang
// Creation Date      : Aug 18, 2012
// Copyright          : Copyright © 2011 by Catraeus and Duncan Gray
//
// Description        :
//    The one and only
//
//=================================================================================================

#include "PageAnBulk.hpp"
#include "WinMain.hpp"
#include <math.h>
#include <caes/CaesString.hpp>

        PageAnBulk::PageAnBulk         ( void        ) {
  BuildEnv();
  BuildMain();
  Connect();
  }
        PageAnBulk::~PageAnBulk        ( void        ) {
  }
void    PageAnBulk::ReFormat           ( void        ) {
  eAmpType newAmpType;
  if(rbtNumSysLin->get_active())
    newAmpType = AT_NUM_SYS_LIN;
  else if(rbtNumSysDb->get_active())
    newAmpType = AT_NUM_SYS_DB;
  else if(rbtFsLin->get_active())
    newAmpType = AT_FS_LIN;
  else if(rbtFsDb->get_active())
    newAmpType = AT_FS_DB;
  else if(rbtBits16->get_active())
    newAmpType = AT_BITS16;
  else if(rbtBits24->get_active())
    newAmpType = AT_BITS24;
  else
    newAmpType = AT_INVALID;

  if(newAmpType == ampType) {
    if(!dirty)
      return;
    }
  ampType = newAmpType;
  return;
}
void    PageAnBulk::FillStatsRaw       ( void        ) {
  char tStr[256];
  ReFormat();
  dirty = false;

  sprintf(tStr, "%lf", ConvertLinAmp(      1.0)  );
  ebxRawDC0.set_text(tStr);
  sprintf(tStr, "%lf", ConvertLinAmp(      1.0)  );
  ebxRawRms0.set_text(tStr);
  sprintf(tStr, "%lf", ConvertLinAmp(      1.0)  );
  ebxRawPkn0.set_text(tStr);
  IntWithComma       (tStr,                1.0)   ;
  ebxRawOfn0.set_text(tStr);
  sprintf(tStr, "%lf", ConvertLinAmp(      1.0)  );
  ebxRawPkp0.set_text(tStr);
  IntWithComma       (tStr,                1.0)   ;
  ebxRawOfp0.set_text(tStr);
  double bb;
  bb = 0.0;
  sprintf(tStr, "%lf", ConvertLinAmp(bb));
  ebxRawPk0.set_text(tStr);

  if(true) {
    sprintf(tStr, "%lf", 0.0);
    ebxCtlPrr.set_text(tStr);
    sprintf(tStr, "%lf", ConvertLinAmp(      1.0)  );
    ebxRawDC1.set_text (tStr);
    sprintf(tStr, "%lf", ConvertLinAmp(      1.0)  );
    ebxRawRms1.set_text(tStr);
    sprintf(tStr, "%lf", ConvertLinAmp(      1.0)  );
    ebxRawPkn1.set_text(tStr);
    IntWithComma       (tStr,                1.0)   ;
    ebxRawOfn1.set_text(tStr);
    sprintf(tStr, "%lf", ConvertLinAmp(      1.0)  );
    ebxRawPkp1.set_text(tStr);
    IntWithComma       (tStr,                1.0)   ;
    ebxRawOfp1.set_text(tStr);
    double bb;
    bb = 1.0;
    sprintf(tStr, "%lf", ConvertLinAmp(bb));
    ebxRawPk1.set_text(tStr);
    }
  else {
    ebxCtlPrr.set_text("");
    ebxRawDC1.set_text("");
    ebxRawRms1.set_text("");
    ebxRawPkn1.set_text("");
    ebxRawOfn1.set_text("");
    ebxRawPkp1.set_text("");
    ebxRawOfp1.set_text("");
    ebxRawPk1.set_text("");
    }

  return;
  }
void    PageAnBulk::FillStatsFlt       ( void        ) {
  char tStr[256];
  if(!ckbIsFlat->get_active()) return;
  ReFormat();
  dirty = false;

  sprintf(tStr, "%lf", ConvertLinAmp(      1.0)  );
  ebxFltDC0.set_text(tStr);
  sprintf(tStr, "%lf", ConvertLinAmp(      1.0)  );
  ebxFltRms0.set_text(tStr);
  sprintf(tStr, "%lf", ConvertLinAmp(      1.0)  );
  ebxFltPkn0.set_text(tStr);
  IntWithComma       (tStr,                1.0)   ;
  ebxFltOfn0.set_text(tStr);
  sprintf(tStr, "%lf", ConvertLinAmp(      1.0)  );
  ebxFltPkp0.set_text(tStr);
  IntWithComma       (tStr,                1.0)   ;
  ebxFltOfp0.set_text(tStr);
  double bb;
  bb = 1.0;
  sprintf(tStr, "%lf", ConvertLinAmp(bb));
  ebxFltPk0.set_text(tStr);

  if(true) {
    sprintf(tStr, "%lf", 1.0);
    ebxCtlPrr.set_text(tStr);
    sprintf(tStr, "%lf", ConvertLinAmp(      1.0)  );
    ebxFltDC1.set_text (tStr);
    sprintf(tStr, "%lf", ConvertLinAmp(      1.0)  );
    ebxFltRms1.set_text(tStr);
    sprintf(tStr, "%lf", ConvertLinAmp(      1.0)  );
    ebxFltPkn1.set_text(tStr);
    IntWithComma       (tStr,                1.0)   ;
    ebxFltOfn1.set_text(tStr);
    sprintf(tStr, "%lf", ConvertLinAmp(      1.0)  );
    ebxFltPkp1.set_text(tStr);
    IntWithComma       (tStr,                1.0)   ;
    ebxFltOfp1.set_text(tStr);
    double bb;
    bb = 1.0;
    sprintf(tStr, "%lf", ConvertLinAmp(bb));
    ebxFltPk1.set_text(tStr);
    }
  else {
    ebxCtlPrr.set_text("");
    ebxFltDC1.set_text("");
    ebxFltRms1.set_text("");
    ebxFltPkn1.set_text("");
    ebxFltOfn1.set_text("");
    ebxFltPkp1.set_text("");
    ebxFltOfp1.set_text("");
    ebxFltPk1.set_text("");
    }

  return;
}
double  PageAnBulk::ConvertLinAmp      ( double  i_v ) {
  switch(ampType) {
    case AT_NUM_SYS_LIN:
      return i_v;
      break;
    case AT_NUM_SYS_DB:
      return 20.0 * log10(fabs(i_v));
      break;
    case AT_FS_LIN:
      return i_v * sqrt(2.0);
      break;
    case AT_FS_DB:
      return 20.0 * log10(fabs(i_v) * sqrt(2.0));
      break;
    case AT_BITS16:
      return i_v * pow(2.0, 15.0);
      break;
    case AT_BITS24:
      return i_v * pow(2.0, 23.0);
      break;
    default:
      return 0.0;
      break;
    }
  return 0.0;
  }
void    PageAnBulk::OnCalcStatsRaw     ( void        ) {
//  tAnBulk->CalcRaw();
  if(true) {
    dirty = true;
    FillStatsRaw();
    }
  return;
  }
void    PageAnBulk::OnCalcStatsFlt     ( void        ) {
//  tAnBulk->CalcFlt();
  if(true) {
    dirty = true;
    ckbIsFlat->set_active(true);
    FillStatsFlt();
    }
  return;
}
void    PageAnBulk::ClearStats         ( void        ) {
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

  ebxCtlPrr.set_text("");
  ebxRawDC1.set_text("");
  ebxRawRms1.set_text("");
  ebxRawPkn1.set_text("");
  ebxRawOfn1.set_text("");
  ebxRawPkp1.set_text("");
  ebxRawOfp1.set_text("");
  ebxRawPk1.set_text("");


  ebxFltDC0.set_text("");
  ebxFltRms0.set_text("");
  ebxFltPkn0.set_text("");
  ebxFltOfn0.set_text("");
  ebxFltPkp0.set_text("");
  ebxFltOfp0.set_text("");
  ebxFltPk0.set_text("");

  ebxCtlPrr.set_text("");
  ebxFltDC1.set_text("");
  ebxFltRms1.set_text("");
  ebxFltPkn1.set_text("");
  ebxFltOfn1.set_text("");
  ebxFltPkp1.set_text("");
  ebxFltOfp1.set_text("");
  ebxFltPk1.set_text("");

  return;
  }
void    PageAnBulk::BuildEnv           ( void        ) {
//  tAnBulk  = new AnBulk(sigRaw, sigFlt);
  dirty    = true;
  ampType  = AT_INVALID;
  return;
}
void    PageAnBulk::BuildMain          ( void        ) {
  btAnaRaw      = new Gtk::Button     ("Analyze Raw",   true );
  btAnaFlt      = new Gtk::Button     ("Flatten",       true );
  ckbIsFlat     = new Gtk::CheckButton("Flattened",     false);
  ckbIsFlat->set_state(Gtk::StateType::STATE_INSENSITIVE);
  ckbIsFlat->set_active(false);
  rbtNumSysLin  = new Gtk::RadioButton("Lin Num Sys"         );
  rbtNumSysDb   = new Gtk::RadioButton("dB Num Sys"          );
  rbtFsLin      = new Gtk::RadioButton("Lin FS"              );
  rbtFsDb       = new Gtk::RadioButton("dB FS"               );
  rbtBits16     = new Gtk::RadioButton("bits (16)"           );
  rbtBits24     = new Gtk::RadioButton("bits (24)"           );

  this                ->set_orientation ( Gtk::ORIENTATION_VERTICAL   );
  hbxStatsBulk         .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  vbxStatsCtlOv        .set_orientation ( Gtk::ORIENTATION_VERTICAL   );
  vbxRaw0              .set_orientation ( Gtk::ORIENTATION_VERTICAL   );
  vbxRaw1              .set_orientation ( Gtk::ORIENTATION_VERTICAL   );
  vbxFlt0              .set_orientation ( Gtk::ORIENTATION_VERTICAL   );
  vbxFlt1              .set_orientation ( Gtk::ORIENTATION_VERTICAL   );
  vbxAmpType           .set_orientation ( Gtk::ORIENTATION_VERTICAL   );

  hbxRawDC0            .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxRawRms0           .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxRawPkn0           .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxRawOfn0           .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxRawPkp0           .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxRawOfp0           .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxRawPk0            .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxRawDC1            .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxRawRms1           .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxRawPkn1           .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxRawOfn1           .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxRawPkp1           .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxRawOfp1           .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxRawPk1            .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );

  hbxFltDC0            .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxFltRms0           .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxFltPkn0           .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxFltOfn0           .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxFltPkp0           .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxFltOfp0           .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxFltPk0            .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxFltDC1            .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxFltRms1           .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxFltPkn1           .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxFltOfn1           .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxFltPkp1           .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxFltOfp1           .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxFltPk1            .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );

  frmRaw0              .set_label("Channel 0 - Raw");
  frmRaw1              .set_label("Channel 1 - Raw");
  frmFlt0              .set_label("Channel 0 - Flat");
  frmFlt1              .set_label("Channel 1 - Flat");
  frmAmpType           .set_label("Scale");

  lblCtlPrr        .set_text("Pearson's Corr R:");
                                               ebxCtlPrr  .set_width_chars(13);                                                   ebxCtlPrr  .set_editable(false);

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

                                               ebxRawDC1       .set_width_chars(13);                                                   ebxRawDC1       .set_editable(false);

                                               ebxRawRms1      .set_width_chars(13);                                                   ebxRawRms1      .set_editable(false);

                                               ebxRawPkn1      .set_width_chars(13);                                                   ebxRawPkn1      .set_editable(false);
                                               ebxRawOfn1      .set_width_chars(13);                                                   ebxRawOfn1      .set_editable(false);

                                               ebxRawPkp1      .set_width_chars(13);                                                   ebxRawPkp1      .set_editable(false);
                                               ebxRawOfp1      .set_width_chars(13);                                                   ebxRawOfp1      .set_editable(false);

                                               ebxRawPk1       .set_width_chars(13);                                                   ebxRawPk1       .set_editable(false);



                                               ebxFltDC0       .set_width_chars(13);                                                   ebxFltDC0       .set_editable(false);

                                               ebxFltRms0      .set_width_chars(13);                                                   ebxFltRms0      .set_editable(false);

                                               ebxFltPkn0      .set_width_chars(13);                                                   ebxFltPkn0      .set_editable(false);
                                               ebxFltOfn0      .set_width_chars(13);                                                   ebxFltOfn0      .set_editable(false);

                                               ebxFltPkp0      .set_width_chars(13);                                                   ebxFltPkp0      .set_editable(false);
                                               ebxFltOfp0      .set_width_chars(13);                                                   ebxFltOfp0      .set_editable(false);

                                               ebxFltPk0       .set_width_chars(13);                                                   ebxFltPk0       .set_editable(false);

                                               ebxFltDC1       .set_width_chars(13);                                                   ebxFltDC1       .set_editable(false);

                                               ebxFltRms1      .set_width_chars(13);                                                   ebxFltRms1      .set_editable(false);

                                               ebxFltPkn1      .set_width_chars(13);                                                   ebxFltPkn1      .set_editable(false);
                                               ebxFltOfn1      .set_width_chars(13);                                                   ebxFltOfn1      .set_editable(false);

                                               ebxFltPkp1      .set_width_chars(13);                                                   ebxFltPkp1      .set_editable(false);
                                               ebxFltOfp1      .set_width_chars(13);                                                   ebxFltOfp1      .set_editable(false);

                                               ebxFltPk1       .set_width_chars(13);                                                   ebxFltPk1       .set_editable(false);

  rbgpAmpType = rbtNumSysLin->get_group();
  rbtNumSysDb  ->set_group(rbgpAmpType);
  rbtFsLin     ->set_group(rbgpAmpType);
  rbtFsDb      ->set_group(rbgpAmpType);
  rbtBits16    ->set_group(rbgpAmpType);
  rbtBits24    ->set_group(rbgpAmpType);


  this                         ->pack_start   (  hbxStatsBulk        , Gtk::PACK_SHRINK, 3);
    hbxStatsBulk                .pack_start   (  vbxStatsCtlOv       , Gtk::PACK_SHRINK, 3);
      vbxStatsCtlOv             .pack_start   ( *btAnaRaw            , Gtk::PACK_SHRINK, 3);
      vbxStatsCtlOv             .pack_start   ( *btAnaFlt            , Gtk::PACK_SHRINK, 3);
      vbxStatsCtlOv             .pack_start   (  lblCtlPrr           , Gtk::PACK_SHRINK, 3);
      vbxStatsCtlOv             .pack_start   (  ebxCtlPrr           , Gtk::PACK_SHRINK, 3);
      vbxStatsCtlOv             .pack_start   ( *ckbIsFlat           , Gtk::PACK_SHRINK, 3);
    hbxStatsBulk                .pack_start   (  frmRaw0             , Gtk::PACK_SHRINK, 3);
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
    hbxStatsBulk                .pack_start   (  frmRaw1             , Gtk::PACK_SHRINK, 3);
      frmRaw1                   .add          (  vbxRaw1                                 );
        vbxRaw1                 .pack_start   (  hbxRawDC1           , Gtk::PACK_SHRINK, 3);
          hbxRawDC1             .pack_start   (  ebxRawDC1           , Gtk::PACK_SHRINK, 3);
        vbxRaw1                 .pack_start   (  hbxRawRms1          , Gtk::PACK_SHRINK, 3);
          hbxRawRms1            .pack_start   (  ebxRawRms1          , Gtk::PACK_SHRINK, 3);
        vbxRaw1                 .pack_start   (  hbxRawPkn1          , Gtk::PACK_SHRINK, 3);
          hbxRawPkn1            .pack_start   (  ebxRawPkn1          , Gtk::PACK_SHRINK, 3);
        vbxRaw1                 .pack_start   (  hbxRawOfn1          , Gtk::PACK_SHRINK, 3);
          hbxRawOfn1            .pack_start   (  ebxRawOfn1          , Gtk::PACK_SHRINK, 3);
        vbxRaw1                 .pack_start   (  hbxRawPkp1          , Gtk::PACK_SHRINK, 3);
          hbxRawPkp1            .pack_start   (  ebxRawPkp1          , Gtk::PACK_SHRINK, 3);
        vbxRaw1                 .pack_start   (  hbxRawOfp1          , Gtk::PACK_SHRINK, 3);
          hbxRawOfp1            .pack_start   (  ebxRawOfp1          , Gtk::PACK_SHRINK, 3);
        vbxRaw1                 .pack_start   (  hbxRawPk1           , Gtk::PACK_SHRINK, 3);
          hbxRawPk1             .pack_start   (  ebxRawPk1           , Gtk::PACK_SHRINK, 3);
    hbxStatsBulk                .pack_start   (  frmFlt0             , Gtk::PACK_SHRINK, 3);
      frmFlt0                   .add          (  vbxFlt0                                 );
        vbxFlt0                 .pack_start   (  hbxFltDC0           , Gtk::PACK_SHRINK, 3);
          hbxFltDC0             .pack_start   (  ebxFltDC0           , Gtk::PACK_SHRINK, 3);
        vbxFlt0                 .pack_start   (  hbxFltRms0          , Gtk::PACK_SHRINK, 3);
          hbxFltRms0            .pack_start   (  ebxFltRms0          , Gtk::PACK_SHRINK, 3);
        vbxFlt0                 .pack_start   (  hbxFltPkn0          , Gtk::PACK_SHRINK, 3);
          hbxFltPkn0            .pack_start   (  ebxFltPkn0          , Gtk::PACK_SHRINK, 3);
        vbxFlt0                 .pack_start   (  hbxFltOfn0          , Gtk::PACK_SHRINK, 3);
          hbxFltOfn0            .pack_start   (  ebxFltOfn0          , Gtk::PACK_SHRINK, 3);
        vbxFlt0                 .pack_start   (  hbxFltPkp0          , Gtk::PACK_SHRINK, 3);
          hbxFltPkp0            .pack_start   (  ebxFltPkp0          , Gtk::PACK_SHRINK, 3);
        vbxFlt0                 .pack_start   (  hbxFltOfp0          , Gtk::PACK_SHRINK, 3);
          hbxFltOfp0            .pack_start   (  ebxFltOfp0          , Gtk::PACK_SHRINK, 3);
        vbxFlt0                 .pack_start   (  hbxFltPk0           , Gtk::PACK_SHRINK, 3);
          hbxFltPk0             .pack_start   (  ebxFltPk0           , Gtk::PACK_SHRINK, 3);
    hbxStatsBulk                .pack_start   (  frmFlt1             , Gtk::PACK_SHRINK, 3);
      frmFlt1                   .add          (  vbxFlt1                                 );
        vbxFlt1                 .pack_start   (  hbxFltDC1           , Gtk::PACK_SHRINK, 3);
          hbxFltDC1             .pack_start   (  ebxFltDC1           , Gtk::PACK_SHRINK, 3);
        vbxFlt1                 .pack_start   (  hbxFltRms1          , Gtk::PACK_SHRINK, 3);
          hbxFltRms1            .pack_start   (  ebxFltRms1          , Gtk::PACK_SHRINK, 3);
        vbxFlt1                 .pack_start   (  hbxFltPkn1          , Gtk::PACK_SHRINK, 3);
          hbxFltPkn1            .pack_start   (  ebxFltPkn1          , Gtk::PACK_SHRINK, 3);
        vbxFlt1                 .pack_start   (  hbxFltOfn1          , Gtk::PACK_SHRINK, 3);
          hbxFltOfn1            .pack_start   (  ebxFltOfn1          , Gtk::PACK_SHRINK, 3);
        vbxFlt1                 .pack_start   (  hbxFltPkp1          , Gtk::PACK_SHRINK, 3);
          hbxFltPkp1            .pack_start   (  ebxFltPkp1          , Gtk::PACK_SHRINK, 3);
        vbxFlt1                 .pack_start   (  hbxFltOfp1          , Gtk::PACK_SHRINK, 3);
          hbxFltOfp1            .pack_start   (  ebxFltOfp1          , Gtk::PACK_SHRINK, 3);
        vbxFlt1                 .pack_start   (  hbxFltPk1           , Gtk::PACK_SHRINK, 3);
          hbxFltPk1             .pack_start   (  ebxFltPk1           , Gtk::PACK_SHRINK, 3);
    hbxStatsBulk                .pack_start   (  frmAmpType          , Gtk::PACK_SHRINK, 3);
      frmAmpType                .add          (  vbxAmpType                               );
        vbxAmpType              .pack_start   ( *rbtNumSysLin        , Gtk::PACK_SHRINK, 3);
        vbxAmpType              .pack_start   ( *rbtNumSysDb         , Gtk::PACK_SHRINK, 3);
        vbxAmpType              .pack_start   ( *rbtFsLin            , Gtk::PACK_SHRINK, 3);
        vbxAmpType              .pack_start   ( *rbtFsDb             , Gtk::PACK_SHRINK, 3);
        vbxAmpType              .pack_start   ( *rbtBits16           , Gtk::PACK_SHRINK, 3);
        vbxAmpType              .pack_start   ( *rbtBits24           , Gtk::PACK_SHRINK, 3);
  return;
}
void    PageAnBulk::Connect            ( void        ) {
  btAnaRaw        -> signal_clicked().connect(sigc::mem_fun(*this,  &PageAnBulk    ::OnCalcStatsRaw  ));
  btAnaFlt        -> signal_clicked().connect(sigc::mem_fun(*this,  &PageAnBulk    ::OnCalcStatsFlt  ));

  rbtNumSysLin    -> signal_clicked().connect(sigc::mem_fun(*this,  &PageAnBulk    ::ReScale         ));
  rbtFsLin        -> signal_clicked().connect(sigc::mem_fun(*this,  &PageAnBulk    ::ReScale         ));
  rbtFsDb         -> signal_clicked().connect(sigc::mem_fun(*this,  &PageAnBulk    ::ReScale         ));
  rbtBits16       -> signal_clicked().connect(sigc::mem_fun(*this,  &PageAnBulk    ::ReScale         ));
  rbtFsDb         -> signal_clicked().connect(sigc::mem_fun(*this,  &PageAnBulk    ::ReScale         ));
  return;
}
