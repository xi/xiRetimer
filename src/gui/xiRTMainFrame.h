#ifndef __xiRTMainFrame__
#define __xiRTMainFrame__

/**
@file
Subclass of MainFrame, which is generated by wxFormBuilder.
*/

#include "xiRetimer_wxfb.h"
#include "../marker.h"
#include "../sample.h"
#include "../playback.h"
#include "../curve.h"

#include <wx/progdlg.h>
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>
#include <wx/string.h>
#include <wx/filedlg.h>

/** Implementing MainFrame */
class xiRTMainFrame : public MainFrame
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
  void OnEndClick( wxCommandEvent& event );
  // general
  void OnExitClick( wxCommandEvent& event );
  void OnHelpClick( wxCommandEvent& event );
  // marker
  void OnClearClick( wxCommandEvent& event );
  // misc
  void OnPrefsClick( wxCommandEvent& event );
  void OnProcessClick( wxCommandEvent& event );
  void OnPaint( wxUpdateUIEvent& event );
  void OnSize( wxSizeEvent& event );

  void paint();
  bool _updateWaveform;
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
	xiRTMainFrame( wxWindow* parent );
	~xiRTMainFrame(  );
};

#endif // __xiRTMainFrame__
