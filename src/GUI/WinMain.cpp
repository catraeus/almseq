
// $Id: WinMain.cpp 551 2020-07-07 02:46:02Z duncang $

//=================================================================================================
// Original File Name : WinMain.cpp for hematite
// Original Author    : Catraeus & Duncan Gray
// Creation Date      : Jun 1, 2012
// Copyright          : Copyright © 2011-2019 by Catraeus and Duncan Gray
//
// Description        :
//    The one and only
//
//=================================================================================================

#include "WinMain.hpp"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <vector>

#include <gtkmm/entry.h>
#include <gtkmm/notebook.h>

#include <caes/CaesString.hpp>

class AnBulk;

      WinMain::WinMain             ( void ) {
  BuildEnv    ();
  BuildMenus  ();
  BuildDialogs();
  BuildMain   ();
  show_all_children();
  Connect();
  return;
  }
      WinMain::~WinMain            ( void ) {
  fprintf(stdout, "WinMain::~WinMain\n");
  }
void  WinMain::on_hide             ( void ) {
  fprintf(stdout, "WinMain hide event in progress\n");
  return;
  }
void  WinMain::OnFileSave          ( void ) {
  return;
}
void  WinMain::OnHelpAbout         ( void ) {
  char tStr[1024];
  sprintf(tStr, "About %s", ce->appName);
  Glib::ustring uu = ce->strAuthors;
  std::vector<Glib::ustring> tt(1);
  tt[0] = uu;
  Gtk::AboutDialog *theDialog = new Gtk::AboutDialog();
  theDialog->set_copyright(ce->strCopyright);
  theDialog->set_program_name(ce->appName);
  sprintf(tStr, "%d.%d build %d", ce->verMaj, ce->verMin, ce->buildNo);
  theDialog->set_version(tStr);
  theDialog->set_website_label("http://www.catraeus.com");
  theDialog->set_website("http://www.catraeus.com");
  theDialog->set_authors(tt);
  theDialog->set_logo(cp->pxbf_xLogoApp);
  theDialog->run();
  theDialog->hide();
  return;
  }
void  WinMain::OnQuit              ( void ) {
  hide();
  return;
  }



void  WinMain::BuildEnv            ( void ) {
  // - These signals have to be in place before the remainder of the working classes can function.

  ce   =     CfgEnv       ::GetInstance();
  cs   =     CfgStrings   ::GetInstance();
  cp   =     CfgParticles ::GetInstance();

  mbarMain            = NULL;

  menuMainFile        = NULL;
  menuMainConfig      = NULL;
  menuMainHelp        = NULL;

  mitmMainFile        = NULL;
  mitmMainFileOpen    = NULL;
  mitmMainFileSave    = NULL;
  mitmMainFileSaveAs  = NULL;
  mitmMainFileClose   = NULL;

  mitmMainFileQuit    = NULL;
  mitmMainConfig      = NULL;
  mitmMainHelp        = NULL;
  mitmMainHelpAbout   = NULL;
  tbarMain            = NULL;
  sbarMain            = NULL;
  return;
}
void  WinMain::BuildMenus          ( void ) {
//=================================================================================================
  mbarMain           = new Gtk::MenuBar();

  menuMainFile       = new Gtk::Menu();
  menuMainConfig     = new Gtk::Menu();
  menuMainHelp       = new Gtk::Menu();

  mitmMainFile       = new Gtk::MenuItem("_File",      true);
  mitmMainFileOpen   = new Gtk::MenuItem("_Open",      true);
  mitmMainFileSave   = new Gtk::MenuItem("_Save",      true);

  mitmMainFileSaveAs = new Gtk::MenuItem("Save_As",    true);
  mitmMainFileClose  = new Gtk::MenuItem("_Close",     true);
  mitmMainFileQuit   = new Gtk::MenuItem("_Quit",      true);
  mitmMainConfig     = new Gtk::MenuItem("Confi_gure", true);
  mitmMainHelp       = new Gtk::MenuItem("_Help",      true);
  mitmMainHelpAbout  = new Gtk::MenuItem("_About",     true);

  mbarMain->add(*mitmMainFile);
  mbarMain->add(*mitmMainConfig);
  mbarMain->add(*mitmMainHelp);

  mitmMainFile->set_submenu(*menuMainFile);
  mitmMainConfig->set_submenu(*menuMainConfig);
  mitmMainHelp->set_submenu(*menuMainHelp);

  menuMainFile->add(*mitmMainFileOpen);
  menuMainFile->add(*mitmMainFileSave);
  menuMainFile->add(*mitmMainFileSaveAs);
  menuMainFile->add(*mitmMainFileClose);
  menuMainFile->add(*mitmMainFileQuit);
  menuMainHelp->add(*mitmMainHelpAbout);

//=================================================================================================
  tbarMain         = new Gtk::Toolbar();

  tbtnAppQuit      = new Gtk::ToolButton();
  tbtnAppQuit->set_icon_name("application-exit");
  tbtnAppQuit->set_has_tooltip(true);
  tbtnAppQuit->set_tooltip_text(cs->strsAppExit);

  tbtnFileOpen  = new Gtk::ToolButton();
  tbtnFileOpen->set_icon_name("document-open");
  tbtnFileOpen->set_has_tooltip(true);
  tbtnFileOpen->set_tooltip_text(cs->strsFileOpen);

  tbtnFileSave  = new Gtk::ToolButton();
  tbtnFileSave->set_icon_name("document-save");
  tbtnFileSave->set_has_tooltip(true);
  tbtnFileSave->set_tooltip_text(cs->strsFileSaveNone);

  tbtnFileSaveAs  = new Gtk::ToolButton();
  tbtnFileSaveAs->set_icon_name("document-save-as");
  tbtnFileSaveAs->set_has_tooltip(true);
  tbtnFileSaveAs->set_tooltip_text(cs->strsFileSaveNone);

  tbtnFileClose  = new Gtk::ToolButton();
  tbtnFileClose->set_icon_name("window-close");
  tbtnFileClose->set_has_tooltip(true);
  tbtnFileClose->set_tooltip_text(cs->strsFileCloseNone);

  tbarMain     -> append( *tbtnAppQuit  );
  tbarMain     -> append( *tbtnFileOpen );
  tbarMain     -> append( *tbtnFileSave );
  tbarMain     -> append( *tbtnFileSaveAs );
  tbarMain     -> append( *tbtnFileClose );


//=================================================================================================
  sbarMain = new Gtk::Statusbar();

  lblSbarL.set_text("Completion: Done");
  hbxSbarL.set_orientation(Gtk::ORIENTATION_HORIZONTAL);
  hbxSbarL.pack_start(lblSbarL);
  frmSbarL.add(hbxSbarL);

  lblSbarC.set_text("Working: Idle");
  hbxSbarC.set_orientation(Gtk::ORIENTATION_HORIZONTAL);
  hbxSbarC.pack_start(lblSbarC);
  frmSbarC.add(hbxSbarC);

  lblSbarR.set_text("Errors: None");
  hbxSbarR.set_orientation(Gtk::ORIENTATION_HORIZONTAL);
  hbxSbarR.pack_start(lblSbarR);
  frmSbarR.add(hbxSbarR);

  sbarMain->set_homogeneous(false);
  //        pack_start(widget  , expand, fill, padding
  sbarMain->pack_start(frmSbarL, true,  false, 20);
  sbarMain->pack_start(frmSbarC, true,  false, 20);
  sbarMain->pack_start(frmSbarR, true,  false, 20);
  return;
  }
void  WinMain::BuildDialogs        ( void ) {
  return;
}
void  WinMain::BuildMain           ( void ) {
  char tStr[257];

  theFilePageRd        = new PageFileRd  ( this );
  theFilePageWr        = new PageFileWr  ( this );
  theAnPageBulk        = new PageAnBulk  (  );
  theAnPageSinus       = new PageAnSinus (  );
  MRU_NewFileSelect    = new CbT<WinMain>;
  MRU_StatusWork       = new CbT<WinMain>;
  MRU_StatusCmpl       = new CbT<WinMain>;


  sprintf(tStr, "%s %d.%d build %d", ce->appName, ce->verMaj, ce->verMin, ce->buildNo);
  set_title(tStr);
  set_icon(cp->pxbf_xLogoApp);

  frmMain.set_shadow_type(Gtk::SHADOW_IN);

  //========================================================================
  theFilePageRd  ->SetFileName(ce->GetFileNameAbs()); // only at startup
  //theFilePageWr ->SetFileName(ce->GetFileNameAbs()); // only at startup

  //========================================================================
  hbxMainInner.set_orientation(Gtk::ORIENTATION_HORIZONTAL);
  hbxMainInner.pack_start(frmMain, Gtk::PACK_EXPAND_WIDGET, 3);
  ntbMain.set_border_width(10);
  ntbMain.append_page(*theFilePageRd,      "File Rd");
  ntbMain.append_page(*theFilePageWr,      "File Wr");
  ntbMain.append_page(*theAnPageBulk,      "DC & RMS");
  ntbMain.append_page(*theAnPageSinus,     "Sine Impairments");
  frmMain.add(ntbMain);

  //========================================================================
  //========================================================================
  vbx_Main.set_orientation(Gtk::ORIENTATION_VERTICAL);
  vbx_Main.pack_start(*mbarMain,   Gtk::PACK_SHRINK);
  vbx_Main.pack_start(*tbarMain,    Gtk::PACK_SHRINK);
  vbx_Main.pack_start(hbxMainInner, Gtk::PACK_EXPAND_WIDGET, 3);
  vbx_Main.pack_start(*sbarMain,    Gtk::PACK_SHRINK);
  add(vbx_Main);

  set_default_size(800, 400);


  return;
}
void  WinMain::Connect             ( void ) {
//==  Menus  ======================================================================================
  mitmMainHelpAbout                 -> signal_activate().connect(sigc::mem_fun(*this,           &WinMain ::OnHelpAbout       ));
  mitmMainFileOpen                  -> signal_activate().connect(sigc::mem_fun(*theFilePageRd,  &PageFileRd::OnFileOpenRd      ));
  mitmMainFileSaveAs                -> signal_activate().connect(sigc::mem_fun(*theFilePageRd,  &PageFileRd::OnFileOpenWr      ));
  mitmMainFileQuit                  -> signal_activate().connect(sigc::mem_fun(*this,           &WinMain ::OnQuit            ));

  tbtnAppQuit                       -> signal_clicked ().connect(sigc::mem_fun(*this,           &WinMain ::OnQuit            ));
  tbtnFileOpen                      -> signal_clicked ().connect(sigc::mem_fun(*theFilePageRd,  &PageFileRd::OnFileOpenRd      ));
  tbtnFileSave                      -> signal_clicked ().connect(sigc::mem_fun(*theFilePageRd,  &PageFileRd::OnFileOpenWr      ));

  MRU_NewFileSelect    ->SetCallback(this, &WinMain::OnNewFileSelect);
  theFilePageRd        ->MSU_NewFileSelect = MRU_NewFileSelect;
  MRU_StatusWork       ->SetCallback(this, &WinMain::StatusWork);
  theAnPageSinus       ->SetCbStWork(MRU_StatusWork);
  MRU_StatusCmpl       ->SetCallback(this, &WinMain::StatusCmpl);
  theAnPageSinus       ->SetCbStCmpl(MRU_StatusCmpl);

  return;
}






bool  WinMain::OnNewFileSelect(void *d) {
  char tStr[32768];
  theAnPageBulk ->SetDirty();
  theAnPageBulk ->ClearStats();
  theAnPageSinus->SetDirty();
  theAnPageSinus->ClearStats();
  sprintf(tStr, "%s %d.%d build %d  --  %s", ce->appName, ce->verMaj, ce->verMin, ce->buildNo, ce->GetFileNameAbs());
  set_title(tStr);

  return true;
  }

bool  WinMain::StatusWork(void *d) {
  char   *ts;

  ts = (char *)d;
  char tStr[32768];
  sprintf(tStr, "Working: %s", ts);
  lblSbarC.set_text(tStr);
  //fprintf(stderr, "%s\n", tStr);fflush(stderr);
  return true;
  }
bool  WinMain::StatusCmpl(void *d) {
  double tDoneNess;
  double *td;
  td = (double *)d;
  tDoneNess = (double) *td;
  tDoneNess *= 100.0;
  char tStr[32768];
  sprintf(tStr, "Completion: %3.1F%%", tDoneNess);
  lblSbarL.set_text(tStr);
  //fprintf(stderr, "%s\n", tStr);fflush(stderr);
  return true;
  }

