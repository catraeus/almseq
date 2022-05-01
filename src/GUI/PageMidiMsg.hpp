// $Id: PageMidiMsg.hpp 554 2020-09-26 21:53:16Z duncang $

//=================================================================================================
// Original File Name : PageMidiMsg.hpp
// Original Author    : duncang
// Creation Date      : Aug 18, 2012
// Copyright          : Copyright © 2011 by Catraeus and Duncan Gray
//
// Description        :
//    The one and only
//
//=================================================================================================

#ifndef __PAGE_AN_BULK_HPP_
#define __PAGE_AN_BULK_HPP_

#include <gtkmm.h>
//#include <caes/AudioFile/Signal.hpp>
#include <caesbase/CaesTypes.hpp>
//#include "../Ana/AnBulk.hpp"

class PageMidiMsg: public Gtk::Box {
  public:
    enum eDir {ID_RX, ID_TX};
                    PageMidiMsg     ( void       );
    virtual        ~PageMidiMsg     ( void       );
            void    ReFormat        ( void       );
            void    ReScale         ( void       ) { FillStatsRaw(); FillStatsFlt(); return;};
            void    FillStatsRaw    ( void       );
            void    FillStatsFlt    ( void       );
            void    ClearStats      ( void       );
            void    SetClean        ( void       ) { dirty = false ; return        ;};
            void    SetDirty        ( void       ) { dirty = true  ; return        ;};
            bool    IsDirty         ( void       ) {                 return dirty  ;};
            void    GetAnBulk       ( void       ) {                 return;};
  private:
            void    BuildEnv        ( void       );
            void    BuildMain       ( void       );
            void    Connect         ( void       );

  public:
    Gtk::RadioButton         *rbtRTTx;
    Gtk::RadioButton         *rbtRTRx;

  private:
//    Signal                   *sigRaw;
//    Signal                   *sigFlt;

    bool                      dirty;
    eDir                      theDir;


    Gtk::Box                  vbxMsgAll;

    Gtk::Frame                frmMidiIf;
    Gtk::Box                  hbxDir;
    Gtk::RadioButtonGroup     rbgpDir;
    Gtk::Box                  hbxMidiIf;
    Gtk::Label                lblMidiIfName;
    Gtk::ComboBox             cbxMidiIfName;

    Gtk::Frame                frmRaw0;
    Gtk::Box                  vbxRaw0;

    Gtk::Label                lblRawDC0;
    Gtk::Label                lblRawRms0;
    Gtk::Label                lblRawPkn0;
    Gtk::Label                lblRawOfn0;
    Gtk::Label                lblRawPkp0;
    Gtk::Label                lblRawOfp0;
    Gtk::Label                lblRawPk0;

    Gtk::Box                  hbxRawDC0;
    Gtk::Entry                ebxRawDC0;
    Gtk::Box                  hbxRawRms0;
    Gtk::Entry                ebxRawRms0;
    Gtk::Box                  hbxRawPkn0;
    Gtk::Entry                ebxRawPkn0;
    Gtk::Box                  hbxRawOfn0;
    Gtk::Entry                ebxRawOfn0;
    Gtk::Box                  hbxRawPkp0;
    Gtk::Entry                ebxRawPkp0;
    Gtk::Box                  hbxRawOfp0;
    Gtk::Entry                ebxRawOfp0;
    Gtk::Box                  hbxRawPk0;
    Gtk::Entry                ebxRawPk0;

//    AnBulk                   *tAnBulk;

  };

#endif // __PAGE_AN_BULK_HPP_
