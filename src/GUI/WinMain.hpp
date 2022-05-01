
// $Id: WinMain.hpp 551 2020-07-07 02:46:02Z duncang $

//=================================================================================================
// Original File Name : WinMain.hpp
// Original Author    : duncang
// Creation Date      : Jun 1, 2012
// Copyright          : Copyright © 2012 by Catraeus and Duncan Gray
//
// Description        :
//    Pretty self descriptive, eh!?
//
//=================================================================================================

#ifndef __WIN_MAIN_HPP_
#define __WIN_MAIN_HPP_

#include <gtkmm.h>

#include <caesbase/CaesTypes.hpp>
#include <caesbase/CaesCallBack.hpp>
//#include <caes/AudioFile/Signal.hpp>
//#include <caes/AudioFile/WaveFiler.hpp>

#include "../Cfg/CfgEnv.hpp"
#include "../Cfg/CfgParticles.hpp"
#include "../Cfg/CfgStrings.hpp"

#include "../Ctl/CtlMsgDspch.hpp"

#include "PageMidiMsg.hpp"
#include "PageAnSinus.hpp"
#include "PageFileRd.hpp"
#include "PageFileWr.hpp"


class WinMain: public Gtk::Window {
  public:
                    WinMain           ( void );
    virtual        ~WinMain           ( void );
            void    OnFileSave        ( void );
            void    MenuMainHelpAbout ( void );
  protected:
            void    OnHelpAbout       ( void );
            void    OnQuit            ( void );
    virtual void    on_hide           ( void );



  private:
            void    BuildEnv          ( void );
            void    BuildMenus        ( void );
            void    BuildDialogs      ( void );
            void    BuildMain         ( void );
            void    Connect           ( void );
            void    Setup             ( void );

            bool    OnNewFileSelect   ( void *i_ch);
            bool    StatusWork        ( void *i_ch);
            bool    StatusCmpl        ( void *i_ch);
  public:
  protected:
    Gtk::Box                  vbx_Main;
    Gtk::Notebook             ntbMain;
    Gtk::Frame                frmMain;
    Gtk::Box                  hbxMainInner;


    //==========================================================
    // Menu-like things
    Gtk::MenuBar     *mbarMain;

    Gtk::Menu        *menuMainFile;
    Gtk::Menu        *menuMainConfig;
    Gtk::Menu        *menuMainHelp;

    Gtk::MenuItem    *mitmMainFile;
    Gtk::MenuItem    *mitmMainFileOpen;
    Gtk::MenuItem    *mitmMainFileSave;
    Gtk::MenuItem    *mitmMainFileSaveAs;
    Gtk::MenuItem    *mitmMainFileClose;
    Gtk::MenuItem    *mitmMainFileQuit;
    Gtk::MenuItem    *mitmMainConfig;
    Gtk::MenuItem    *mitmMainHelp;
    Gtk::MenuItem    *mitmMainHelpAbout;


    //==========================================================
    // Toolbar-like things
    Gtk::Toolbar     *tbarMain;
    Gtk::ToolButton  *tbtnAppQuit;
    Gtk::ToolButton  *tbtnFileNew;
    Gtk::ToolButton  *tbtnFileOpen;
    Gtk::ToolButton  *tbtnFileSave;
    Gtk::ToolButton  *tbtnFileSaveAs;
    Gtk::ToolButton  *tbtnFileClose;


    //==========================================================
    // Some day we'll have a rich Statusbar experience
    Gtk::Statusbar *sbarMain;
    Gtk::Frame      frmSbarL;
    Gtk::Box        hbxSbarL;
    Gtk::Label      lblSbarL;
    Gtk::Frame      frmSbarC;
    Gtk::Box        hbxSbarC;
    Gtk::Label      lblSbarC;
    Gtk::Frame      frmSbarR;
    Gtk::Box        hbxSbarR;
    Gtk::Label      lblSbarR;

    //==========================================================
    // The pages that we have made
    PageFileRd               *theFilePageRd;
    PageFileWr               *theFilePageWr;
    PageMidiMsg              *theMsgPage;
    PageAnSinus              *theAnPageSinus;

  private:
    //==========================================================
    // The important machinery
    CfgEnv                   *ce;
    CfgStrings               *cs;
    CfgParticles             *cp;

  //  WaveFiler                *twi;
  //  WaveFiler                *two;

//    Signal                   *sigRaw;
//    Signal                   *sigFlat;
//    Signal                   *sigDemod0;
//    Signal                   *sigDemod1;

//    WaveFiler                *twi;
//    WaveFiler                *two;

    CbT<WinMain>             *MRU_NewFileSelect;
    CbT<WinMain>             *MRU_StatusWork;
    CbT<WinMain>             *MRU_StatusCmpl;

    CtlMsgDspch              *ctMd;

};

#endif // __WIN_MAIN_HPP_
