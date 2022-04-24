
// $Id: PageAnSinus.cpp 523 2020-06-24 01:19:56Z duncang $

//=================================================================================================
// Original File Name : PageAnSinus.cpp
// Original Author    : duncang
// Creation Date      : Aug 18, 2012
// Copyright          : Copyright © 2011 - 2019 by Catraeus and Duncan Gray
//
// Description        :
//    The page for the Sinusoid Analyzer.
//
//=================================================================================================

#include "PageAnSinus.hpp"
#include "WinMain.hpp"
#include <caes/CaesString.hpp>
#include <math.h>

        PageAnSinus::PageAnSinus        ( void ) {
  BuildEnv ();
  BuildMain();
  Connect  ();
  return;
  }
        PageAnSinus::~PageAnSinus       ( void         ) {
  }
void    PageAnSinus::FillStats          ( void         ) {
  char   tStr[256];
  double ddd;
  dirty = false;

  ddd = 1004.0;                           sprintf  (tStr, "%lf"  , ddd                  );  ebxZerFrq0    .set_text(tStr);
  ddd = 1.023e-9;                         EngString(tStr,          ddd, 3, (char *)" ui");  ebxZerRmsUi0  .set_text(tStr);
  ddd = 1.023e-12;                        EngString(tStr,          ddd, 3, (char *)"s"  );  ebxZerRmsSec0 .set_text(tStr);
                                          sprintf  (tStr, "%lf"  , 0.0                  );  ebxZerAmpCar0 .set_text(tStr);
                                          sprintf  (tStr, "%lf"  , 0.0                  );  ebxZeraPk0    .set_text(tStr);
  ddd =    0.3273;                        EngString(tStr,          ddd, 3, (char *)"º"  );  ebxZeraPh0    .set_text(tStr);

  if(true) {
    sprintf(tStr, "%lf", 0.0);    ebxPrr.set_text(tStr);

    ddd = 1003.76;                       sprintf  (tStr, "%lf"  , ddd                  );  ebxZerFrq1    .set_text(tStr);
    ddd = 3.237e-7;                      EngString(tStr,          ddd, 3, (char *)" ui");  ebxZerRmsUi1  .set_text(tStr);
    ddd = 3.237e-10;                     EngString(tStr,          ddd, 3, (char *)"s"  );  ebxZerRmsSec1 .set_text(tStr);
                                         sprintf  (tStr, "%lf",   0.0                  );  ebxZerAmpCar1 .set_text(tStr);
                                         sprintf  (tStr, "%lf",   0.0                  );  ebxZeraPk1    .set_text(tStr);
    ddd = -.07898;                       EngString(tStr,          ddd, 3, (char *)"º"  );  ebxZeraPh1    .set_text(tStr);
  }
  else {
    ebxPrr          .set_text("");
    ebxZerFrq1      .set_text("");
    ebxZerRmsUi1    .set_text("");
    ebxZerRmsSec1   .set_text("");
    ebxZerRmsSec1   .set_text("");
    ebxZerAmpCar1   .set_text("");
    ebxZeraPk1      .set_text("");
    ebxZeraPh1      .set_text("");
  }

  return;
}
double  PageAnSinus::ConvertJitUi       ( llong   i_ch ) {
  return 0.0767;
}
double  PageAnSinus::ConvertJitSec      ( llong   i_ch ) {
  return 0.1093;
}
void    PageAnSinus::CalcEstZerXrs      ( void         ) {
//  tAnSin->EstZerXcr();
  dirty = true;
  FillStats();
  return;
}
void    PageAnSinus::CalcDemod          ( void         ) {
//  tAnSin->EstDemod();
  return;
}
void    PageAnSinus::ReScale            ( void         ) {
  FillStats();
  return;
}
void    PageAnSinus::ClearStats         ( void         ) {

  if(!dirty)
    return;
  dirty = false;

  ebxPrr          .set_text("");

  ebxZerFrq0      .set_text("");
  ebxZerFrq1      .set_text("");
  ebxZerRmsUi0    .set_text("");
  ebxZerRmsUi1    .set_text("");
  ebxZerRmsSec0   .set_text("");
  ebxZerRmsSec1   .set_text("");
  ebxZerAmpCar0   .set_text("");
  ebxZerAmpCar1   .set_text("");
  ebxZeraPk0      .set_text("");
  ebxZeraPk1      .set_text("");



  return;
  }
void    PageAnSinus::BuildEnv           ( void         ) {
//  tAnSin     = new AnSinus(sigRaw, sigFlat, sigDemod0);
  dirty      = true;
  return;
}
void    PageAnSinus::BuildMain          ( void         ) {
  set_orientation(Gtk::ORIENTATION_VERTICAL);
  //========================================================================
  //========================================================================
  //  Set up the whole shebang of the File vertical box

  btCalcEstZerXrs = new Gtk::Button("Est Zer Cross");
  btCalcDemod     = new Gtk::Button("Demod");

  hbxSinus      .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  vbxCtlOv      .set_orientation ( Gtk::ORIENTATION_VERTICAL   );
  hbxSinus      .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  vbxZer0       .set_orientation ( Gtk::ORIENTATION_VERTICAL   );
  vbxZer1       .set_orientation ( Gtk::ORIENTATION_VERTICAL   );
  hbxZerFrq0    .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxZerFrq1    .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxZerRmsUi0  .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxZerRmsUi1  .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxZerRmsSec0 .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxZerRmsSec1 .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxZerAmpCar0 .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxZerAmpCar1 .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxZeraPk0    .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxZeraPk1    .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxZeraPh0    .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );
  hbxZeraPh1    .set_orientation ( Gtk::ORIENTATION_HORIZONTAL );

  frmZer0       .set_label ("Channel 0 - ZC" );
  frmZer1       .set_label ("Channel 1 - ZC" );

  lblPrr       .set_text  ("A/P RR:"        );   lblPrr     .set_width_chars ( 13 );   lblPrr     .set_alignment ( Gtk::ALIGN_START );
  lblFrq       .set_text  ("Freq:"          );   lblFrq     .set_width_chars ( 10 );   lblFrq     .set_alignment ( Gtk::ALIGN_END   );
  lblRmsUi     .set_text  ("RMS(ui):"       );   lblRmsUi   .set_width_chars ( 10 );   lblRmsUi   .set_alignment ( Gtk::ALIGN_END   );
  lblRmsSec    .set_text  ("RMS(sec):"      );   lblRmsSec  .set_width_chars ( 10 );   lblRmsSec  .set_alignment ( Gtk::ALIGN_END   );
  lblAmpCar    .set_text  ("Am Jit (c):"    );   lblAmpCar  .set_width_chars ( 10 );   lblAmpCar  .set_alignment ( Gtk::ALIGN_END   );
  lblaPk       .set_text  ("Pk ch 0:"       );   lblaPk     .set_width_chars ( 10 );   lblaPk     .set_alignment ( Gtk::ALIGN_END   );
  lblaPh       .set_text  ("Φ ch 0:"        );   lblaPh     .set_width_chars ( 10 );   lblaPh     .set_alignment ( Gtk::ALIGN_END   );

  ebxPrr        .set_width_chars ( 13 );   ebxPrr        .set_editable ( false );
  ebxZerFrq0    .set_width_chars ( 13 );   ebxZerFrq0    .set_editable ( false );
  ebxZerFrq1    .set_width_chars ( 13 );   ebxZerFrq1    .set_editable ( false );
  ebxZerRmsUi0  .set_width_chars ( 13 );   ebxZerRmsUi0  .set_editable ( false );
  ebxZerRmsUi1  .set_width_chars ( 13 );   ebxZerRmsUi1  .set_editable ( false );
  ebxZerRmsSec0 .set_width_chars ( 13 );   ebxZerRmsSec0 .set_editable ( false );
  ebxZerRmsSec1 .set_width_chars ( 13 );   ebxZerRmsSec1 .set_editable ( false );
  ebxZerAmpCar0 .set_width_chars ( 13 );   ebxZerAmpCar0 .set_editable ( false );
  ebxZerAmpCar1 .set_width_chars ( 13 );   ebxZerAmpCar1 .set_editable ( false );
  ebxZeraPk0    .set_width_chars ( 13 );   ebxZeraPk0    .set_editable ( false );
  ebxZeraPk1    .set_width_chars ( 13 );   ebxZeraPk1    .set_editable ( false );
  ebxZeraPh0    .set_width_chars ( 13 );   ebxZeraPh0    .set_editable ( false );
  ebxZeraPh1    .set_width_chars ( 13 );   ebxZeraPh1    .set_editable ( false );



//==  Now put it all together
  this                   ->pack_start (  hbxSinus          , Gtk::PACK_SHRINK, 3 );
  hbxSinus                .pack_start (  vbxCtlOv          , Gtk::PACK_SHRINK, 3 );
    vbxCtlOv              .pack_start ( *btCalcEstZerXrs   , Gtk::PACK_SHRINK, 3 );
    vbxCtlOv              .pack_start ( *btCalcDemod       , Gtk::PACK_SHRINK, 3 );
    vbxCtlOv              .pack_start (  lblPrr            , Gtk::PACK_SHRINK, 3 );
    vbxCtlOv              .pack_start (  ebxPrr            , Gtk::PACK_SHRINK, 3 );
  hbxSinus                .pack_start (  frmZer0           , Gtk::PACK_SHRINK, 3 );
    frmZer0               .add        (  vbxZer0                                 );
      vbxZer0             .pack_start (  hbxZerFrq0        , Gtk::PACK_SHRINK, 3 );
        hbxZerFrq0        .pack_start (  lblFrq            , Gtk::PACK_SHRINK, 3 );
        hbxZerFrq0        .pack_start (  ebxZerFrq0        , Gtk::PACK_SHRINK, 3 );
      vbxZer0             .pack_start (  hbxZerRmsUi0      , Gtk::PACK_SHRINK, 3 );
        hbxZerRmsUi0      .pack_start (  lblRmsUi          , Gtk::PACK_SHRINK, 3 );
        hbxZerRmsUi0      .pack_start (  ebxZerRmsUi0      , Gtk::PACK_SHRINK, 3 );
      vbxZer0             .pack_start (  hbxZerRmsSec0     , Gtk::PACK_SHRINK, 3 );
        hbxZerRmsSec0     .pack_start (  lblRmsSec         , Gtk::PACK_SHRINK, 3 );
        hbxZerRmsSec0     .pack_start (  ebxZerRmsSec0     , Gtk::PACK_SHRINK, 3 );
      vbxZer0             .pack_start (  hbxZerAmpCar0     , Gtk::PACK_SHRINK, 3 );
        hbxZerAmpCar0     .pack_start (  lblAmpCar         , Gtk::PACK_SHRINK, 3 );
        hbxZerAmpCar0     .pack_start (  ebxZerAmpCar0     , Gtk::PACK_SHRINK, 3 );
      vbxZer0             .pack_start (  hbxZeraPk0        , Gtk::PACK_SHRINK, 3 );
        hbxZeraPk0        .pack_start (  lblaPk            , Gtk::PACK_SHRINK, 3 );
        hbxZeraPk0        .pack_start (  ebxZeraPk0        , Gtk::PACK_SHRINK, 3 );
      vbxZer0             .pack_start (  hbxZeraPh0        , Gtk::PACK_SHRINK, 3 );
        hbxZeraPh0        .pack_start (  lblaPh            , Gtk::PACK_SHRINK, 3 );
        hbxZeraPh0        .pack_start (  ebxZeraPh0        , Gtk::PACK_SHRINK, 3 );
  hbxSinus                .pack_start (  frmZer1           , Gtk::PACK_SHRINK, 3 );
    frmZer1               .add        (  vbxZer1                                 );
      vbxZer1             .pack_start (  hbxZerFrq1        , Gtk::PACK_SHRINK, 3 );
        hbxZerFrq1        .pack_start (  ebxZerFrq1        , Gtk::PACK_SHRINK, 3 );
      vbxZer1             .pack_start (  hbxZerRmsUi1      , Gtk::PACK_SHRINK, 3 );
        hbxZerRmsUi1      .pack_start (  ebxZerRmsUi1      , Gtk::PACK_SHRINK, 3 );
      vbxZer1             .pack_start (  hbxZerRmsSec1     , Gtk::PACK_SHRINK, 3 );
        hbxZerRmsSec1     .pack_start (  ebxZerRmsSec1     , Gtk::PACK_SHRINK, 3 );
      vbxZer1             .pack_start (  hbxZerAmpCar1     , Gtk::PACK_SHRINK, 3 );
        hbxZerAmpCar1     .pack_start (  ebxZerAmpCar1     , Gtk::PACK_SHRINK, 3 );
      vbxZer1             .pack_start (  hbxZeraPk1        , Gtk::PACK_SHRINK, 3 );
        hbxZeraPk1        .pack_start (  ebxZeraPk1        , Gtk::PACK_SHRINK, 3 );
      vbxZer1             .pack_start (  hbxZeraPh1        , Gtk::PACK_SHRINK, 3 );
        hbxZeraPh1        .pack_start (  ebxZeraPh1        , Gtk::PACK_SHRINK, 3 );



  return;
}
void    PageAnSinus::Connect            ( void         ) {
  btCalcEstZerXrs       -> signal_clicked().connect(sigc::mem_fun(*this, &PageAnSinus   ::CalcEstZerXrs  ));
  btCalcDemod           -> signal_clicked().connect(sigc::mem_fun(*this, &PageAnSinus   ::CalcDemod  ));
  return;
}
