// $Id: PageFileRd.cpp 551 2020-07-07 02:46:02Z duncang $

//=================================================================================================
// Original File Name : WinMain.cpp
// Original Author    : duncang
// Creation Date      : Jun 1, 2012
// Copyright          : Copyright © 2011 by Catraeus and Duncan Gray
//
// Description        :
//    The one and only
//
//=================================================================================================

#include <caesbase/CaesString.hpp>
#include "PageFileRd.hpp"


      PageFileRd::PageFileRd               ( Gtk::Window *i_winMain )
:winMain(i_winMain) {
  BuildEnv     ();
  BuildMain    ();
  BuildDialogs ();
  Connect      ();
  if(strlen(ce->GetFileNameAbs()) != 0) {
	  SetFileName(ce->GetFileNameAbs());
  }
  return;
}
      PageFileRd::~PageFileRd              ( void ) {
  return;
}
void  PageFileRd::OnFileOpenRd           ( void ) {
  int  result;
  char tStr[32768];
  char rStr[32768];
  strcpy(tStr, (char *)ce->GetWorkingDir());
  dlgOpenRd->set_current_folder(tStr);
  result = dlgOpenRd->run();
  dlgOpenRd->hide();
  switch(result) {
    case(Gtk::RESPONSE_OK):
      strcpy(rStr, (char *)dlgOpenRd->get_filename().c_str());
      ClearFileInfo();
      ce->SetFileName(rStr);
      SetFileName(rStr);
      if(MSU_NewFileSelect != NULL) MSU_NewFileSelect->Execute(NULL);
      break;
    case(Gtk::RESPONSE_CANCEL):
      return;
      break;
    default:
      return;
      break;
    }

  return;
  }
void  PageFileRd::OnFileOpenWr           ( void ) {
  int result;
  char tStr[32768];
  char rStr[32768];
  strcpy(tStr, (char *)ce->GetWorkingDir());
  dlgOpenWr->set_current_folder(tStr);
  result = dlgOpenWr->run();
  dlgOpenWr->hide();
  switch(result) {
    case(Gtk::RESPONSE_OK):
      strcpy(rStr, (char *)dlgOpenWr->get_filename().c_str());
      ce->SetFileName(rStr);
      SetFileName(rStr);
      if(MSU_ChangeFileName != NULL) MSU_ChangeFileName->Execute(NULL);
      break;
    case(Gtk::RESPONSE_CANCEL):
      return;
      break;
    default:
      return;
      break;
    }

  return;
  }
void  PageFileRd::OnFileParse            ( void ) {
  char   bbb[1024];
  char  *tStr;
  ullong tUll;
  ullong fmtSize;
  double tDbl;
//  AudioFiler::eStatus fStat;

  tStr = &bbb[0];
  strcpy(tStr, ebxCtlFileName.get_tooltip_text().c_str());

  //===============================================================================================
  tUll = 11231987;
  IntWithComma(tStr, tUll);
  ebxRiffFileSize.set_text(tStr);
  //==
  tStr = (char *)("RIFF");
  ebxRiffRiff.set_text(tStr);
  tStr = &bbb[0];
  //==
  tUll = 16;
  IntWithComma(tStr, tUll);
  ebxRiffChunkSize.set_text(tStr);
  //==
  tUll = 4343433;
  IntWithComma(tStr, tUll);
  ebxRiffRemainder.set_text(tStr);
  //==
  tStr = (char *)("wave");
  ebxRiffWave.set_text(tStr);
  tStr = &bbb[0];

  //===============================================================================================
  tStr = (char *)("fmt ");
  ebxFmt.set_text(tStr);
  tStr = &bbb[0];
  //==
  tUll = 21;
  sprintf(tStr, "%Lu", tUll);
  ebxFmtSize.set_text(tStr);
  //==
  tUll = 0xdeadbeefU;
  cbxFmtCode.set_active(tUll);
  //================================================================================================
  tUll = 2;
  sprintf(tStr, "%lld", tUll);
  ebxFmtNumChan.set_text(tStr);
  //==
  tDbl = 48001.0;
  IntWithComma(tStr, tDbl);
  ebxFmtFrmRate.set_text(tStr);
  //==
  tUll = 3;
  IntWithComma(tStr, tUll);
  ebxFmtByteRate.set_text(tStr);
  //==
  tUll = 7;
  sprintf(tStr, "%lld", tUll);
  ebxFmtBlockAlign.set_text(tStr);
  //==
  tUll = 113;
  sprintf(tStr, "%lld", tUll);
  ebxFmtBitDepth.set_text(tStr);

  //===============================================================================================
  fmtSize = 33;
  if(fmtSize == 40) {
    tUll = 1;
    sprintf(tStr, "%lld", tUll);
    ebxFmtExtSize.set_text(tStr);
    //==
    tUll = 54;
    sprintf(tStr, "%lld", tUll);
    ebxExtValBits.set_text(tStr);
    //==
    tUll = 45;
    sprintf(tStr, "0x%08llx", tUll);
    ebxExtChMask.set_text(tStr);
    //==
    tStr = (char *)("la-tee-da");
    ebxExtWaveGUID.set_text(tStr);
    tStr = &bbb[0];
    }
  else if(fmtSize == 18) {
    tUll = 11;
    sprintf(tStr, "%lld", tUll);
    ebxFmtExtSize.set_text(tStr);
    }
  else {
    ebxFmtExtSize.set_text("");
    ebxExtValBits.set_text("");
    ebxExtChMask.set_text("");
    ebxExtWaveGUID.set_text("");
    }

  //===============================================================================================
  if(true) {
    ebxFact.set_text("fact");
    //==
    sprintf(tStr, "%lld", 8LL);
    ebxFactSize.set_text(tStr);
    //==
    IntWithComma(tStr, 323432);
    ebxFactNumSmps.set_text(tStr);
  }
  //==
  ebxData.set_text("data");
  //==
  IntWithComma(tStr, 9876543);
  ebxDataSize.set_text(tStr);

  //===============================================================================================
  IntWithComma(tStr, 121);
  ebxWaveNumByte.set_text(tStr);
  //==
  IntWithComma(tStr, 545454);
  ebxWaveNumFrms.set_text(tStr);
  //==
  SecToHMS(tStr, 123.4567, false);
  ebxWaveTimeDur.set_text(tStr);
  //==
  strcpy(tStr, "how");
  ebxWaveType.set_text(tStr);

  if(MSU_FileReRead != NULL)
    MSU_FileReRead->Execute(NULL);
  return;
  }
void  PageFileRd::SetFileName            ( char *i_fileName) {
  char *tStr = new char[32768];

  PathExtractFileName(i_fileName, tStr);
  ebxCtlFileName.set_text(tStr);
  ebxCtlFileName.set_tooltip_text(i_fileName);
  delete tStr;
  return;
  }
void  PageFileRd::ClearFileInfo          ( void ) {

//  twi->Reset();

  ebxRiffFileSize.set_text("");
  ebxRiffRiff.set_text("");
  ebxRiffChunkSize.set_text("");
  ebxRiffRemainder.set_text("");
  ebxRiffWave.set_text("");
  ebxFmt.set_text("");
  ebxFmtSize.set_text("");
  //cbxFmtCode.set_text("");
  cbxFmtCode.set_active(0);

  //==
  ebxFact.set_text("");
  ebxFactSize.set_text("");
  ebxFactNumSmps.set_text("");
  ebxData.set_text("");
  ebxDataSize.set_text("");


  //==
  ebxFmtNumChan.set_text("");
  ebxFmtFrmRate.set_text("");
  ebxFmtByteRate.set_text("");
  ebxFmtBlockAlign.set_text("");
  ebxFmtBitDepth.set_text("");

  //==
  ebxWaveNumByte.set_text("");
  ebxWaveNumFrms.set_text("");
  ebxWaveTimeDur.set_text("");

  //==
  ebxExtValBits.set_text("");
  ebxExtChMask.set_text("");
  ebxExtWaveGUID.set_text("");
  ebxWaveType.set_text("");
  }
void  PageFileRd::BuildEnv               ( void ) {
  ce  = CfgEnv     ::GetInstance();

  return;
}
void  PageFileRd::BuildDialogs           ( void ) {
  dlgOpenRd = new Gtk::FileChooserDialog("Please choose a wave file", Gtk::FILE_CHOOSER_ACTION_OPEN);
  dlgOpenRd->set_transient_for(*winMain);
  dlgOpenRd->add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
  dlgOpenRd->add_button(Gtk::Stock::OK,     Gtk::RESPONSE_OK);

  dlgOpenWr = new Gtk::FileChooserDialog("Please choose a wave file or enter a name", Gtk::FILE_CHOOSER_ACTION_SAVE);
  dlgOpenWr->set_transient_for(*winMain);
  dlgOpenWr->add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
  dlgOpenWr->add_button(Gtk::Stock::OK,     Gtk::RESPONSE_OK);
  return;
}
void  PageFileRd::BuildMain              ( void ) {
  //========================================================================
  //  Set up the whole shebang of the File vertical box
  set_orientation(Gtk::ORIENTATION_VERTICAL);

  //========================================================================
  //  File Name
  hbxCtlFileName.set_orientation(Gtk::ORIENTATION_HORIZONTAL);
  frmCtlFileName.add(hbxCtlFileName);
  lblCtlFileName.set_text("File Name:");
  ebxCtlFileName.set_width_chars(64);
  ebxCtlFileName.set_editable(false);
  lblCtlFileName.set_has_tooltip(true);
  btnCtlFileParse = new Gtk::Button("_Parse", true);

  hbxCtlFileName.pack_start(lblCtlFileName, Gtk::PACK_SHRINK, 3);
  hbxCtlFileName.pack_start(ebxCtlFileName, Gtk::PACK_SHRINK);
  hbxCtlFileName.pack_start(*btnCtlFileParse, Gtk::PACK_SHRINK, 3);

  //========================================================================
  //========================================================================
  //  file, RIFF & Wave chunk info
  hbxCtlRiffWave.set_orientation(Gtk::ORIENTATION_HORIZONTAL);
  frmCtlRiffWave.add(hbxCtlRiffWave);

  lblRiffFileSize.set_text("File size:");
  ebxRiffFileSize.set_alignment(Gtk::ALIGN_END);
  ebxRiffFileSize.set_width_chars(22);
  ebxRiffFileSize.set_editable(false);

  lblRiffRiff.set_text("RIFF:");
  ebxRiffRiff.set_alignment(Gtk::ALIGN_CENTER);
  ebxRiffRiff.set_width_chars(4);
  ebxRiffRiff.set_editable(false);

  lblRiffChunkSize.set_text("RIFF size:");
  ebxRiffChunkSize.set_alignment(Gtk::ALIGN_END);
  ebxRiffChunkSize.set_width_chars(12);
  ebxRiffChunkSize.set_editable(false);

  lblRiffRemainder.set_text("RIFF remainder:");
  ebxRiffRemainder.set_alignment(Gtk::ALIGN_END);
  ebxRiffRemainder.set_width_chars(12);
  ebxRiffRemainder.set_editable(false);
  ebxRiffRemainder.set_tooltip_text("But I don't know how modified");

  lblRiffWave.set_text("WAVE:");
  ebxRiffWave.set_alignment(Gtk::ALIGN_CENTER);
  ebxRiffWave.set_width_chars(6);
  ebxRiffWave.set_editable(false);

  hbxCtlRiffWave.pack_start(lblRiffFileSize, Gtk::PACK_SHRINK, 3);
  hbxCtlRiffWave.pack_start(ebxRiffFileSize, Gtk::PACK_SHRINK, 3);
  hbxCtlRiffWave.pack_start(lblRiffRiff, Gtk::PACK_SHRINK, 3);
  hbxCtlRiffWave.pack_start(ebxRiffRiff, Gtk::PACK_SHRINK, 3);
  hbxCtlRiffWave.pack_start(lblRiffChunkSize, Gtk::PACK_SHRINK, 3);
  hbxCtlRiffWave.pack_start(ebxRiffChunkSize, Gtk::PACK_SHRINK, 3);
  hbxCtlRiffWave.pack_start(lblRiffRemainder, Gtk::PACK_SHRINK, 3);
  hbxCtlRiffWave.pack_start(ebxRiffRemainder, Gtk::PACK_SHRINK, 3);
  hbxCtlRiffWave.pack_start(lblRiffWave, Gtk::PACK_SHRINK, 3);
  hbxCtlRiffWave.pack_start(ebxRiffWave, Gtk::PACK_SHRINK, 3);


  //========================================================================
  //========================================================================
  //  fmt chunk info
  vbxCtlFmt.set_orientation(Gtk::ORIENTATION_VERTICAL);
  frmCtlFmt.add(vbxCtlFmt);

  hbxCtlFmt1.set_orientation(Gtk::ORIENTATION_HORIZONTAL);

  lblFmt.set_text("fmt_:");
  ebxFmt.set_alignment(Gtk::ALIGN_CENTER);
  ebxFmt.set_width_chars(4);
  ebxFmt.set_editable(false);

  lblFmtSize.set_text("fmt_ size:");
  ebxFmtSize.set_alignment(Gtk::ALIGN_END);
  ebxFmtSize.set_width_chars(4);
  ebxFmtSize.set_editable(false);

  lblFmtCode.set_text("fmt_ code:");
  cbxFmtCode.set_halign(Gtk::ALIGN_START);
  //cbxFmtCode.set_width_chars(34);
  //cbxFmtCode.set_editable(false);

  fmtTable = Gtk::ListStore::create(fmtRow);
  ullong K = 1;
  Gtk::TreeModel::Row row;
  char *cc;
  ullong ccode;
  cbxFmtCode.set_model(fmtTable);
  for(ullong i = 0; i < K; i++) {
    row = *(fmtTable->append());
    ccode = 33;
    cc = new char[11];
    sprintf(cc, "0x%08LX", ccode);
    row[fmtRow.code] = cc;
    cc = (char *)"me";
    row[fmtRow.name] = cc;
  }
  cbxFmtCode.pack_start(fmtRow.code);
  cbxFmtCode.pack_start(fmtRow.name);
  cbxFmtCode.set_active(0);


  hbxCtlFmt1.pack_start(lblFmt,     Gtk::PACK_SHRINK, 3);
  hbxCtlFmt1.pack_start(ebxFmt,     Gtk::PACK_SHRINK, 3);
  hbxCtlFmt1.pack_start(lblFmtSize, Gtk::PACK_SHRINK, 3);
  hbxCtlFmt1.pack_start(ebxFmtSize, Gtk::PACK_SHRINK, 3);
  hbxCtlFmt1.pack_start(lblFmtCode, Gtk::PACK_SHRINK, 3);
  hbxCtlFmt1.pack_start(cbxFmtCode, Gtk::PACK_SHRINK, 3);


  //========================================================================
  //========================================================================
  //  fmt parameters, row 2
  hbxCtlFmt2.set_orientation(Gtk::ORIENTATION_HORIZONTAL);

  lblFmtNumChan.set_text("Channels:");
  ebxFmtNumChan.set_alignment(Gtk::ALIGN_END);
  ebxFmtNumChan.set_width_chars(4);
  ebxFmtNumChan.set_editable(false);

  lblFmtSmplRate.set_text("Frame Rate:");
  ebxFmtFrmRate.set_alignment(Gtk::ALIGN_END);
  ebxFmtFrmRate.set_width_chars(9);
  ebxFmtFrmRate.set_editable(false);

  lblFmtByteRate.set_text("Byte Rate:");
  ebxFmtByteRate.set_alignment(Gtk::ALIGN_END);
  ebxFmtByteRate.set_width_chars(9);
  ebxFmtByteRate.set_editable(false);

  lblFmtBlockAlign.set_text("Block Align:");
  ebxFmtBlockAlign.set_alignment(Gtk::ALIGN_END);
  ebxFmtBlockAlign.set_width_chars(2);
  ebxFmtBlockAlign.set_editable(false);

  lblFmtBitDepth.set_text("Bit Depth:");
  ebxFmtBitDepth.set_alignment(Gtk::ALIGN_END);
  ebxFmtBitDepth.set_width_chars(2);
  ebxFmtBitDepth.set_editable(false);

  lblFmtExtSize.set_text("Ext Size:");
  ebxFmtExtSize.set_alignment(Gtk::ALIGN_END);
  ebxFmtExtSize.set_width_chars(2);
  ebxFmtExtSize.set_editable(false);



  hbxCtlFmt2.pack_start(lblFmtNumChan,    Gtk::PACK_SHRINK, 3);
  hbxCtlFmt2.pack_start(ebxFmtNumChan,    Gtk::PACK_SHRINK, 3);
  hbxCtlFmt2.pack_start(lblFmtSmplRate,   Gtk::PACK_SHRINK, 3);
  hbxCtlFmt2.pack_start(ebxFmtFrmRate,    Gtk::PACK_SHRINK, 3);
  hbxCtlFmt2.pack_start(lblFmtByteRate,   Gtk::PACK_SHRINK, 3);
  hbxCtlFmt2.pack_start(ebxFmtByteRate,   Gtk::PACK_SHRINK, 3);
  hbxCtlFmt2.pack_start(lblFmtBlockAlign, Gtk::PACK_SHRINK, 3);
  hbxCtlFmt2.pack_start(ebxFmtBlockAlign, Gtk::PACK_SHRINK, 3);
  hbxCtlFmt2.pack_start(lblFmtBitDepth,   Gtk::PACK_SHRINK, 3);
  hbxCtlFmt2.pack_start(ebxFmtBitDepth,   Gtk::PACK_SHRINK, 3);
  hbxCtlFmt2.pack_start(lblFmtExtSize,    Gtk::PACK_SHRINK, 3);
  hbxCtlFmt2.pack_start(ebxFmtExtSize,    Gtk::PACK_SHRINK, 3);
  //________________________________________________________________________
  vbxCtlFmt.pack_start(hbxCtlFmt1, Gtk::PACK_SHRINK, 3);
  vbxCtlFmt.pack_start(hbxCtlFmt2, Gtk::PACK_SHRINK, 3);

  //========================================================================
  //========================================================================
  //  ext fmt parameters
  vbxCtlFmtExt.set_orientation(Gtk::ORIENTATION_VERTICAL);
  frmCtlFmtExt.add(vbxCtlFmtExt);

  hbxCtlFmt3.set_orientation(Gtk::ORIENTATION_HORIZONTAL);

  lblExtValBits.set_text("Valid Bits:");
  ebxExtValBits.set_alignment(Gtk::ALIGN_END);
  ebxExtValBits.set_width_chars(2);
  ebxExtValBits.set_editable(false);

  lblExtChMask.set_text("Ch Mask:");
  ebxExtChMask.set_alignment(Gtk::ALIGN_END);
  ebxExtChMask.set_width_chars(7);
  ebxExtChMask.set_editable(false);

  lblExtWaveGUID.set_text("GUID:");
  ebxExtWaveGUID.set_alignment(Gtk::ALIGN_END);
  ebxExtWaveGUID.set_width_chars(34);
  ebxExtWaveGUID.set_editable(false);


  hbxCtlFmt3.pack_start(lblExtValBits,   Gtk::PACK_SHRINK, 3);
  hbxCtlFmt3.pack_start(ebxExtValBits,   Gtk::PACK_SHRINK, 3);
  hbxCtlFmt3.pack_start(lblExtChMask,    Gtk::PACK_SHRINK, 3);
  hbxCtlFmt3.pack_start(ebxExtChMask,    Gtk::PACK_SHRINK, 3);
  hbxCtlFmt3.pack_start(lblExtWaveGUID,  Gtk::PACK_SHRINK, 3);
  hbxCtlFmt3.pack_start(ebxExtWaveGUID,  Gtk::PACK_SHRINK, 3);
  //________________________________________________________________________
  vbxCtlFmtExt.pack_start(hbxCtlFmt3, Gtk::PACK_SHRINK, 3);

  //========================================================================
  //========================================================================
  //  fact and data chunk info
  hbxCtlFactData.set_orientation(Gtk::ORIENTATION_HORIZONTAL);

  hbxCtlFact.set_orientation(Gtk::ORIENTATION_HORIZONTAL);
  frmCtlFact.add(hbxCtlFact);

  lblFact.set_text("fact:");
  ebxFact.set_alignment(Gtk::ALIGN_CENTER);
  ebxFact.set_width_chars(4);
  ebxFact.set_editable(false);

  lblFactSize.set_text("fact size:");
  ebxFactSize.set_alignment(Gtk::ALIGN_END);
  ebxFactSize.set_width_chars(4);
  ebxFactSize.set_editable(false);

  lblFactNumSmps.set_text("fact frms:");
  ebxFactNumSmps.set_alignment(Gtk::ALIGN_END);
  ebxFactNumSmps.set_width_chars(13);
  ebxFactNumSmps.set_editable(false);

  hbxCtlFact.pack_start(lblFact,        Gtk::PACK_SHRINK, 3);
  hbxCtlFact.pack_start(ebxFact,        Gtk::PACK_SHRINK, 3);
  hbxCtlFact.pack_start(lblFactSize,    Gtk::PACK_SHRINK, 3);
  hbxCtlFact.pack_start(ebxFactSize,    Gtk::PACK_SHRINK, 3);
  hbxCtlFact.pack_start(lblFactNumSmps, Gtk::PACK_SHRINK, 3);
  hbxCtlFact.pack_start(ebxFactNumSmps, Gtk::PACK_SHRINK, 3);

  hbxCtlData.set_orientation(Gtk::ORIENTATION_HORIZONTAL);
  frmCtlData.add(hbxCtlData);

  lblData.set_text("data:");
  ebxData.set_alignment(Gtk::ALIGN_CENTER);
  ebxData.set_width_chars(4);
  ebxData.set_editable(false);

  lblDataSize.set_text("data size:");
  ebxDataSize.set_alignment(Gtk::ALIGN_END);
  ebxDataSize.set_width_chars(14);
  ebxDataSize.set_editable(false);

  hbxCtlData.pack_start(lblData,        Gtk::PACK_SHRINK, 3);
  hbxCtlData.pack_start(ebxData,        Gtk::PACK_SHRINK, 3);
  hbxCtlData.pack_start(lblDataSize,    Gtk::PACK_SHRINK, 3);
  hbxCtlData.pack_start(ebxDataSize,    Gtk::PACK_SHRINK, 3);

  hbxCtlFactData.pack_start(frmCtlFact,         Gtk::PACK_SHRINK,        0);
  hbxCtlFactData.pack_start(hbxCtlFactDataSep,  Gtk::PACK_SHRINK,        2);
  hbxCtlFactData.pack_start(frmCtlData,         Gtk::PACK_EXPAND_WIDGET, 0);
  //========================================================================
  //========================================================================
  //  stream parameters

  hbxCtlStream.set_orientation(Gtk::ORIENTATION_HORIZONTAL);
  frmCtlStream.add(hbxCtlStream);

  lblWaveNumByte.set_text("Bytes:");
  ebxWaveNumByte.set_alignment(Gtk::ALIGN_END);
  ebxWaveNumByte.set_width_chars(13);
  ebxWaveNumByte.set_editable(false);

  lblWaveNumFrms.set_text("Frames:");
  ebxWaveNumFrms.set_alignment(Gtk::ALIGN_END);
  ebxWaveNumFrms.set_width_chars(13);
  ebxWaveNumFrms.set_editable(false);

  lblWaveTimeDur.set_text("Duration:");
  ebxWaveTimeDur.set_alignment(Gtk::ALIGN_END);
  ebxWaveTimeDur.set_width_chars(20);
  ebxWaveTimeDur.set_editable(false);

  lblWaveType.set_text("Type:");
  ebxWaveType.set_width_chars(12);
  ebxWaveType.set_editable(false);

  hbxCtlStream.pack_start(lblWaveNumByte, Gtk::PACK_SHRINK, 3);
  hbxCtlStream.pack_start(ebxWaveNumByte, Gtk::PACK_SHRINK, 3);
  hbxCtlStream.pack_start(lblWaveNumFrms, Gtk::PACK_SHRINK, 3);
  hbxCtlStream.pack_start(ebxWaveNumFrms, Gtk::PACK_SHRINK, 3);
  hbxCtlStream.pack_start(lblWaveTimeDur, Gtk::PACK_SHRINK, 3);
  hbxCtlStream.pack_start(ebxWaveTimeDur, Gtk::PACK_SHRINK, 3);
  hbxCtlStream.pack_start(lblWaveType,    Gtk::PACK_SHRINK, 3);
  hbxCtlStream.pack_start(ebxWaveType,    Gtk::PACK_SHRINK, 3);

  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  pack_start(frmCtlFileName, Gtk::PACK_SHRINK, 3);
  pack_start(frmCtlRiffWave, Gtk::PACK_SHRINK, 3);
  pack_start(frmCtlFmt,      Gtk::PACK_SHRINK, 3);
  pack_start(frmCtlFmtExt,   Gtk::PACK_SHRINK, 3);
  pack_start(hbxCtlFactData, Gtk::PACK_SHRINK, 0);
  pack_start(frmCtlStream,   Gtk::PACK_SHRINK, 3);

  return;
}
void  PageFileRd::Connect                ( void ) {
  btnCtlFileParse  -> signal_clicked ().connect(sigc::mem_fun(*this,    &PageFileRd      ::OnFileParse   ));

  MSU_NewFileSelect   = NULL;
  MSU_FileReRead      = NULL;
  MSU_ChangeFileName  = NULL;
  return;
}
