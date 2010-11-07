#ifndef __RetimerMainFrame__
#define __RetimerMainFrame__

/**
@file
Subclass of MainFrame, which is generated by wxFormBuilder.
*/

#include "retimer_wx.h"
#include "../marker.h"
#include "../sample.h"
#include "../playback.h"
#include "../curve.h"

#include <wx/progdlg.h>
#include <wx/msgdlg.h>
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>
#include <wx/string.h>
#include <wx/filedlg.h>
#include <wx/timer.h>

#include <iostream>

/** Implementing MainFrame */
class RetimerMainFrame : public MainFrame
{
protected:
  // mouse
  void OnLeftDown( wxMouseEvent& event );
  void OnLeftUp( wxMouseEvent& event );
  void OnLeftDClick( wxMouseEvent& event );
  void OnMotion( wxMouseEvent& event );
  // file
  void OnOpenClick( wxCommandEvent& event );
  void OnExportClick( wxCommandEvent& event );
  // playback
  void OnStartClick( wxCommandEvent& event );
  void OnPlayClick( wxCommandEvent& event );
  // general
  void OnExitClick( wxCommandEvent& event );
  void OnHelpClick( wxCommandEvent& event );
  // marker
  void OnClearClick( wxCommandEvent& event );
  // misc
  void OnPrefsClick( wxCommandEvent& event );
  void OnProcessClick( wxCommandEvent& event );
  void OnPaint( wxPaintEvent& event );
  void OnSize( wxSizeEvent& event );

  void paint(wxDC* dc);
  wxTimer timer;
  void OnTimer(wxTimerEvent& event);

  void process();
  bool _updateWaveform;
  void reportError(wxString string);
  static const int MARKERWIDTH=15;
  static const int BEAT=15;
  
  int width;
  int height;
  bool Marker_move;
  bool Seeker_move;

Marker* marker;
Sample* sample;
Playback* playback;
Curve* curve;

wxBrush* brushbg;
wxPen* penCurve;
wxPen* penSeeker;
wxPen* penMarker;
wxBitmap waveform;

public:
	/** Constructor */
	RetimerMainFrame( wxWindow* parent );
	~RetimerMainFrame(  );
};

#endif // __RetimerMainFrame__
