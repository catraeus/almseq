// $Id: PageFileRd.hpp 601 2022-01-15 02:59:32Z duncang $

//=================================================================================================
// Original File Name : PageFileRd.hpp
// Original Author    : duncang
// Creation Date      : Aug 1, 2012
// Copyright          : Copyright © 2011 by Catraeus and Duncan Gray
//
// Description        :
//    The one and only
//
//=================================================================================================

#ifndef __PAGE_FILE_RD_HPP_
#define __PAGE_FILE_RD_HPP_

#include <gtkmm.h>
//#include <caes/AudioFile/WaveFiler.hpp>
#include <caes/CaesTypes.hpp>
#include <caes/CaesCallBack.hpp>

#include "../Cfg/CfgEnv.hpp"

class PageFileRd: public Gtk::Box {
  public:
                    PageFileRd       ( Gtk::Window *i_winMain );
    virtual        ~PageFileRd       ( void );
            void    OnFileOpenRd     ( void );
            void    OnFileOpenWr     ( void );
            void    OnFileParse      ( void );
            void    SetFileName      ( char *i_fileName);
            void    ClearFileInfo    ( void );
  private:
            void    BuildEnv         ( void );
            void    BuildDialogs     ( void );
            void    BuildMain        ( void );
            void    Connect          ( void );
  public:
//    AudioFiler               *taf;
//    RiffMgr                  *trf;
//    NumSys                   *tns;
    Gtk::Window              *winMain;
//    Signal                   *sigRaw;
//    Signal                   *sigFlat;
//    WaveFiler                *twi;
    CfgEnv                   *ce;
  //CbV                      *CbChangeStream;

    //==========================================================
    // It's important to dialogue
    Gtk::FileChooserDialog   *dlgOpenRd;
    Gtk::FileChooserDialog   *dlgOpenWr;


    Gtk::Frame                frmCtlFileName;
    Gtk::Label                lblCtlFileName;
    Gtk::Box                  hbxCtlFileName;
    Gtk::Entry                ebxCtlFileName;
    Gtk::Button              *btnCtlFileParse;

    Gtk::Frame                frmCtlRiffWave;
    Gtk::Box                  hbxCtlRiffWave;
    Gtk::Label                lblRiffFileSize;
    Gtk::Entry                ebxRiffFileSize;
    Gtk::Label                lblRiffRiff;
    Gtk::Entry                ebxRiffRiff;
    Gtk::Label                lblRiffChunkSize;
    Gtk::Entry                ebxRiffChunkSize;
    Gtk::Label                lblRiffRemainder;
    Gtk::Entry                ebxRiffRemainder;
    Gtk::Label                lblRiffWave;
    Gtk::Entry                ebxRiffWave;

    Gtk::Frame                frmCtlFmt;
    Gtk::Box                  vbxCtlFmt;

    Gtk::Box                  hbxCtlFmt1;
    Gtk::Label                lblFmt;
    Gtk::Entry                ebxFmt;
    Gtk::Label                lblFmtSize;
    Gtk::Entry                ebxFmtSize;


    Gtk::Label                lblFmtCode;
    class FmtRow : public Gtk::TreeModel::ColumnRecord {
    public:
      FmtRow(void) {add(code); add(name);};

      Gtk::TreeModelColumn<Glib::ustring>   code;
      Gtk::TreeModelColumn<Glib::ustring>   name;
    };

    FmtRow fmtRow;

    //Child widgets:
    Gtk::ComboBox                cbxFmtCode;
    Glib::RefPtr<Gtk::ListStore> fmtTable;

    Gtk::Box                  hbxCtlFmt2;
    Gtk::Label                lblFmtNumChan;
    Gtk::Entry                ebxFmtNumChan;
    Gtk::Label                lblFmtSmplRate;
    Gtk::Entry                ebxFmtFrmRate;
    Gtk::Label                lblFmtByteRate;
    Gtk::Entry                ebxFmtByteRate;
    Gtk::Label                lblFmtBlockAlign;
    Gtk::Entry                ebxFmtBlockAlign;
    Gtk::Label                lblFmtBitDepth;
    Gtk::Entry                ebxFmtBitDepth;
    Gtk::Label                lblFmtExtSize;
    Gtk::Entry                ebxFmtExtSize;

    Gtk::Frame                frmCtlFmtExt;
    Gtk::Box                  vbxCtlFmtExt;

    Gtk::Box                  hbxCtlFmt3;
    Gtk::Label                lblExtValBits;
    Gtk::Entry                ebxExtValBits;
    Gtk::Label                lblExtChMask;
    Gtk::Entry                ebxExtChMask;
    Gtk::Label                lblExtWaveGUID;
    Gtk::Entry                ebxExtWaveGUID;

    Gtk::Box                  hbxCtlFactData;

    Gtk::Frame                frmCtlFact;
    Gtk::Box                  hbxCtlFact;
    Gtk::Label                lblFact;
    Gtk::Entry                ebxFact;
    Gtk::Label                lblFactSize;
    Gtk::Entry                ebxFactSize;
    Gtk::Label                lblFactNumSmps;
    Gtk::Entry                ebxFactNumSmps;

    Gtk::Box                  hbxCtlFactDataSep;

    Gtk::Frame                frmCtlData;
    Gtk::Box                  hbxCtlData;
    Gtk::Label                lblData;
    Gtk::Entry                ebxData;
    Gtk::Label                lblDataSize;
    Gtk::Entry                ebxDataSize;

    Gtk::Frame                frmCtlStream;
    Gtk::Box                  hbxCtlStream;
    Gtk::Label                lblWaveNumByte;
    Gtk::Entry                ebxWaveNumByte;
    Gtk::Label                lblWaveNumFrms;
    Gtk::Entry                ebxWaveNumFrms;
    Gtk::Label                lblWaveTimeDur;
    Gtk::Entry                ebxWaveTimeDur;
    Gtk::Label                lblWaveType;
    Gtk::Entry                ebxWaveType;

    bool                      dirty;

    CbV                      *MSU_FileReRead;
    CbV                      *MSU_NewFileSelect;
    CbV                      *MSU_ChangeFileName;

  };

#endif // __PAGE_FILE_RD_HPP_
