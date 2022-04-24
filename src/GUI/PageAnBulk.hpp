// $Id: PageAnBulk.hpp 554 2020-09-26 21:53:16Z duncang $

//=================================================================================================
// Original File Name : PageAnBulk.hpp
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
#include <caes/CaesTypes.hpp>
//#include "../Ana/AnBulk.hpp"

class PageAnBulk: public Gtk::Box {
  public:
    enum eAmpType {AT_NUM_SYS_LIN, AT_NUM_SYS_DB, AT_FS_LIN, AT_FS_DB, AT_BITS16, AT_BITS24, AT_INVALID};
                    PageAnBulk      ( void       );
    virtual        ~PageAnBulk      ( void       );
            void    OnCalcStatsRaw  ( void       );
            void    OnCalcStatsFlt  ( void       );
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

            double  ConvertLinAmp   ( double i_v );
  public:
    Gtk::Button              *btAnaRaw;
    Gtk::Button              *btAnaFlt;
    Gtk::RadioButton         *rbtNumSysLin;
    Gtk::RadioButton         *rbtNumSysDb;
    Gtk::RadioButton         *rbtFsLin;
    Gtk::RadioButton         *rbtFsDb;
    Gtk::RadioButton         *rbtBits16;
    Gtk::RadioButton         *rbtBits24;

  private:
//    Signal                   *sigRaw;
//    Signal                   *sigFlt;

    bool                      dirty;
    eAmpType                  ampType;


    Gtk::Box                  hbxStatsBulk;


    Gtk::Box                  vbxStatsCtlOv;
    Gtk::Label                lblCtlPrr;
    Gtk::Entry                ebxCtlPrr;
    Gtk::CheckButton         *ckbIsFlat;
    Gtk::Frame                frmRaw0;
    Gtk::Box                  vbxRaw0;
    Gtk::Frame                frmRaw1;
    Gtk::Box                  vbxRaw1;
    Gtk::Frame                frmFlt0;
    Gtk::Box                  vbxFlt0;
    Gtk::Frame                frmFlt1;
    Gtk::Box                  vbxFlt1;

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

    Gtk::Box                  hbxRawDC1;
    Gtk::Entry                ebxRawDC1;
    Gtk::Box                  hbxRawRms1;
    Gtk::Entry                ebxRawRms1;
    Gtk::Box                  hbxRawPkn1;
    Gtk::Entry                ebxRawPkn1;
    Gtk::Box                  hbxRawOfn1;
    Gtk::Entry                ebxRawOfn1;
    Gtk::Box                  hbxRawPkp1;
    Gtk::Entry                ebxRawPkp1;
    Gtk::Box                  hbxRawOfp1;
    Gtk::Entry                ebxRawOfp1;
    Gtk::Box                  hbxRawPk1;
    Gtk::Entry                ebxRawPk1;

    Gtk::Box                  hbxFltDC0;
    Gtk::Entry                ebxFltDC0;
    Gtk::Box                  hbxFltRms0;
    Gtk::Entry                ebxFltRms0;
    Gtk::Box                  hbxFltPkn0;
    Gtk::Entry                ebxFltPkn0;
    Gtk::Box                  hbxFltOfn0;
    Gtk::Entry                ebxFltOfn0;
    Gtk::Box                  hbxFltPkp0;
    Gtk::Entry                ebxFltPkp0;
    Gtk::Box                  hbxFltOfp0;
    Gtk::Entry                ebxFltOfp0;
    Gtk::Box                  hbxFltPk0;
    Gtk::Entry                ebxFltPk0;

    Gtk::Box                  hbxFltDC1;
    Gtk::Entry                ebxFltDC1;
    Gtk::Box                  hbxFltRms1;
    Gtk::Entry                ebxFltRms1;
    Gtk::Box                  hbxFltPkn1;
    Gtk::Entry                ebxFltPkn1;
    Gtk::Box                  hbxFltOfn1;
    Gtk::Entry                ebxFltOfn1;
    Gtk::Box                  hbxFltPkp1;
    Gtk::Entry                ebxFltPkp1;
    Gtk::Box                  hbxFltOfp1;
    Gtk::Entry                ebxFltOfp1;
    Gtk::Box                  hbxFltPk1;
    Gtk::Entry                ebxFltPk1;

    Gtk::Frame                frmAmpType;
    Gtk::Box                  vbxAmpType;
    Gtk::RadioButtonGroup     rbgpAmpType;

//    AnBulk                   *tAnBulk;

  };

#endif // __PAGE_AN_BULK_HPP_
