
// $Id: PageAnSinus.hpp 523 2020-06-24 01:19:56Z duncang $

//=================================================================================================
// Original File Name : PageAnSinus.hpp
// Original Author    : duncang
// Creation Date      : Aug 18, 2012
// Copyright          : Copyright © 2011 - 2019 by Catraeus and Duncan Gray
//
// Description        :
//    The page for the Sinusoid Analyzer.
//
/*
Remove DC0, DC1 and DC2 (offset, ramp and parabola) using LMS.
Estimate Carrier Freq, check RMS less than some number. check tilt, check parabola of freq using ZC



 */
//=================================================================================================

#ifndef __PAGE_AN_SINUS_HPP_
#define __PAGE_AN_SINUS_HPP_

#include <gtkmm.h>
//#include <caes/AudioFile/Signal.hpp>
#include <caes/CaesTypes.hpp>
#include <caes/CaesCallBack.hpp>
//#include <caes/CaesStat.hpp>
//#include "../Ana/AnSinus.hpp"

class PageAnSinus: public Gtk::Box {
  public:
    enum eAmpType {AT_RAW, AT_DBFS, AT_LINFS, AT_BITS16, AT_BITS24, AT_INVALID};
                    PageAnSinus     ( void         );
    virtual        ~PageAnSinus     ( void         );
            void    SetCbStWork     ( CbV    *i_CB ) { return;};
            void    SetCbStCmpl     ( CbV    *i_CB ) { return;};

            void    ClearStats      ( void        );
            void    SetClean        ( void        ) { dirty = false; return       ;};
            void    SetDirty        ( void        ) { dirty = true ; return       ;};
            bool    IsDirty         ( void        ) {                return dirty ;};
  private:
            void    BuildEnv        ( void        );
            void    BuildMain       ( void        );
            void    Connect         ( void        );

            void    ReScale         ( void        );
            void    FillStats       ( void        );

            void    CalcEstZerXrs   ( void        );
            void    CalcDemod       ( void        );

            double  ConvertJitUi    ( llong  i_ch );
            double  ConvertJitSec   ( llong  i_ch );
  public:
    Gtk::Button              *btCalcEstZerXrs;
    Gtk::Button              *btCalcDemod;

  private:
//    Stat                     *R; //!< Think the R language
//    Signal                   *sigRaw;
//    Signal                   *sigFlat;
//    Signal                   *sigDemod0;
//    AnSinus                  *tAnSin;

    bool                      dirty;


    Gtk::Box                  hbxSinus;

    Gtk::Box                  vbxCtlOv;

    Gtk::Label                lblPrr;
    Gtk::Entry                ebxPrr;

    Gtk::Box                  vbxZer0;
    Gtk::Box                  vbxZer1;
    Gtk::Frame                frmZer0;
    Gtk::Frame                frmZer1;

    Gtk::Label                lblFrq;
    Gtk::Label                lblRmsUi;
    Gtk::Label                lblRmsSec;
    Gtk::Label                lblAmpCar;
    Gtk::Label                lblaPk;
    Gtk::Label                lblaPh;

    Gtk::Box                  hbxZerFrq0;
    Gtk::Entry                ebxZerFrq0;
    Gtk::Box                  hbxZerRmsUi0;
    Gtk::Entry                ebxZerRmsUi0;
    Gtk::Box                  hbxZerRmsSec0;
    Gtk::Entry                ebxZerRmsSec0;
    Gtk::Box                  hbxZerAmpCar0;
    Gtk::Entry                ebxZerAmpCar0;
    Gtk::Box                  hbxZeraPk0;
    Gtk::Entry                ebxZeraPk0;
    Gtk::Box                  hbxZeraPh0;
    Gtk::Entry                ebxZeraPh0;

    Gtk::Box                  hbxZerFrq1;
    Gtk::Entry                ebxZerFrq1;
    Gtk::Box                  hbxZerRmsUi1;
    Gtk::Entry                ebxZerRmsUi1;
    Gtk::Box                  hbxZerRmsSec1;
    Gtk::Entry                ebxZerRmsSec1;
    Gtk::Box                  hbxZerAmpCar1;
    Gtk::Entry                ebxZerAmpCar1;
    Gtk::Box                  hbxZeraPk1;
    Gtk::Entry                ebxZeraPk1;
    Gtk::Box                  hbxZeraPh1;
    Gtk::Entry                ebxZeraPh1;





  };

#endif // __PAGE_AN_SINUS_HPP_
