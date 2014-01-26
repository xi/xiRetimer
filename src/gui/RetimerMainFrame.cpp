#include "RetimerMainFrame.h"
#include "RetimerAboutDialog.h"
#include "RetimerPrefsDialog.h"

#include <iostream>


RetimerMainFrame::RetimerMainFrame(wxWindow* parent) : MainFrame(parent) {
	marker = new Marker();
	sample = new Sample(marker);
	playback = new Playback(sample);
	curve = new Curve(marker, sample, playback);
	width = 100;  // anything greater than 2
	height = 100;
	Marker_move = false;
	Seeker_move = false;

	brushbg = new wxBrush(*wxBLACK);
	penCurve = new wxPen(*wxBLUE, 1);
	penCurve2 = new wxPen(*wxRED, 1);
	penSeeker = new wxPen(*wxWHITE, 1);
	penMarker = new wxPen(wxColor(255, 255, 0), 1);
	wxBitmap waveform;

	timer;
	timer.SetOwner(this);
	Connect(wxEVT_TIMER, wxTimerEventHandler(RetimerMainFrame::OnTimer));
	timer.Start(100);
}


RetimerMainFrame::~RetimerMainFrame() {
	timer.Stop();
	// TODO destroy objects
	// delete[] curve;
	// delete[] playback;
	// delete[] sample;
	// delete[] marker;
}


// ************ mouse **************
void RetimerMainFrame::OnLeftDown(wxMouseEvent& event) {
	// check for Marker Select
	if (event.m_y <= MARKERWIDTH * 4 / 5) {
		for (int i = 0; i < curve->getMarkerLength(); ++i) {
			int n = int(curve->getMarker(i) * (width - 1));
			if (event.m_x <= n + MARKERWIDTH / 2 && event.m_x >= n - MARKERWIDTH / 2) {
				curve->selectMarker(i);
				Marker_move = true;
				return;
			}
		}
	}
	// if not returned set Seeker
	playback->setSeeker(event.m_x / (float)width);
	Seeker_move = true;
	curve->selectMarker(-1);  //deselct
}


void RetimerMainFrame::OnLeftUp(wxMouseEvent& event) {
	Marker_move = false;
	Seeker_move = false;
}


void RetimerMainFrame::OnLeftDClick(wxMouseEvent& event) {
	// check for Marker Select
	if (event.m_y <= MARKERWIDTH * 4 / 5) {
		for (int i = 0; i < curve->getMarkerLength(); ++i) {
			int n = int(curve->getMarker(i) * (width - 1));
			if (event.m_x <= n + MARKERWIDTH / 2 && event.m_x >= n - MARKERWIDTH / 2) {
				curve->selectMarker(i);
				curve->removeMarker();
				curve->_update = true;
				return;
			}
		}
	}
	playback->setSeeker(event.m_x/(float)width);
	curve->addMarker();
}


void RetimerMainFrame::OnMotion(wxMouseEvent& event) {
	if (Marker_move) {
		curve->setMarker(event.m_x / (float)width);
		curve->_update = true;
	}
	if (Seeker_move) {
		playback->setSeeker(event.m_x / (float)width);
	}
}


// ************ file **************
void RetimerMainFrame::OnOpenClick(wxCommandEvent& event) {
	wxFileDialog* dialog = new wxFileDialog((wxWindow*)NULL);
	dialog->Show();

	if (dialog->ShowModal() == wxID_OK) {
		wxString filename = dialog->GetPath();
		if (sample->loadFile(filename.mb_str()) != 0) {
			reportError(_T("Could not read from that file"));
			return;
		}
		process();
		curve->_update = true;
	}
	// else {
	// report Error(_T("Please choose a valid file!"));
	// }
}


void RetimerMainFrame::OnExportClick(wxCommandEvent& event) {
	wxFileDialog* dialog = new wxFileDialog((wxWindow*)NULL, _T("Export As"), _T(""), _T(""), _T("*.wav"), wxSAVE | wxOVERWRITE_PROMPT);
	dialog->Show();

	if (dialog->ShowModal() == wxID_OK) {
		wxString filename = dialog->GetPath();
		process();
		if (sample->writeFile(filename.mb_str()) != 0) {
			reportError(_T("Could not write to File"));
		}
	}
	else {
		reportError(_T("Could not write to File"));
	}
}


// ************ playback **************
void RetimerMainFrame::OnStartClick(wxCommandEvent& event) {
	playback->setSeeker(0);
}


void RetimerMainFrame::OnPlayClick(wxCommandEvent& event) {
	playback->play();
}


// ************ general **************
void RetimerMainFrame::OnPrefsClick(wxCommandEvent& event) {
	RetimerPrefsDialog* dialog = new RetimerPrefsDialog(marker, sample, curve);
	dialog->Show();
}

void RetimerMainFrame::OnExitClick(wxCommandEvent& event) {
	Close();
}

void RetimerMainFrame::OnHelpClick(wxCommandEvent& event) {
	// TODO: create Help
	RetimerAboutDialog* dialog = new RetimerAboutDialog((wxWindow*)NULL);
	dialog->Show();
}

// ************ marker **************
void RetimerMainFrame::OnClearClick(wxCommandEvent& event) {
	curve->clearMarker();
	curve->_update = true;
}


// ************ misc **************
void RetimerMainFrame::OnProcessClick(wxCommandEvent& event) {
	process();
}

void RetimerMainFrame::OnPaint(wxPaintEvent& event) {
	wxPaintDC pdc(this);
	// paint(&pdc);
}

void RetimerMainFrame::OnTimer(wxTimerEvent& event) {
	wxClientDC dc(this);
	paint(&dc);
}

void RetimerMainFrame::paint(wxDC* dc) {
	dc->GetSize(&width,&height);
	wxBufferedDC bdc(dc,wxSize(width,height));
	// waveform
	if (curve->_update) {
		waveform.Create(width, height);
		wxMemoryDC mdc;
		mdc.SelectObject(waveform);
		mdc.SetBackground(*brushbg);
		mdc.Clear();
		mdc.SetPen(*penCurve);
		for (int i = 0; i < width; ++i) {
			// mdc.DrawLine(i, int(curve->get(i/(float)width)*(height-BEAT)+height)/2, i+1, int(curve->get((i+1)/(float)width)*(height-BEAT)+height)/2);
			float min = 1 + curve->getMin(i / (float)width, 1 / (float)width);
			float max = 1 + curve->getMax(i / (float)width, 1 / (float)width);
			mdc.DrawLine(i, int(min * height / 2), i, int(max * height / 2));
		}
		if (curve->_showIntLine) {
			mdc.SetPen(*penCurve2);
			float x1;
			float x2 = marker->new2nnew(marker->old2new(0));
			for (int i = 0; i < height - 1; ++i) {
				x1 = x2;
				x2 = marker->new2nnew(marker->old2new((i + 1) / (float)height));
				mdc.DrawLine(int(x1 * width), i, int(x2 * width), i + 1);
			}
		}
		curve->_update = false;
	}
	bdc.DrawBitmap(waveform,0,0,false);
	// marker
	bdc.SetPen(*penMarker);
	for (int i = 0; i < curve->getMarkerLength(); ++i) {
	int n = int(curve->getMarker(i) * (width - 1));
	bdc.DrawLine(n, 0, n, height);
	wxPoint ps[3];
	wxPoint p0(n - MARKERWIDTH / 2, 0);
	ps[0] = p0;
	wxPoint p1(n + MARKERWIDTH / 2, 0);
	ps[1] = p1;
	wxPoint p2(n + 0, MARKERWIDTH * 4 / 5);
	ps[2] = p2;
	bdc.DrawPolygon(3, ps);
	}
	// seeker
	bdc.SetPen(*penSeeker);
	int seek = int(curve->getSeeker() * (width - 1));
	bdc.DrawLine(seek, 0, seek, height);
	//beats
	bdc.SetPen(*penMarker);
	int step = int(width / curve->getBars() / curve->getBeatResolution());
	for (int i = 0; i < width && step != 0; i += step) {
		bdc.DrawLine(i, 0, i, BEAT);
	}
}


void RetimerMainFrame::OnSize(wxSizeEvent& event) {
	curve->_update = true;
}


// ***********************************
void RetimerMainFrame::process() {
	// sometings wrong here
	if (sample->process() != 0) {
		reportError(_T("Could not process data!"));
	}

	wxProgressDialog* dialog = new wxProgressDialog(_T("processing..."), _T("please wait"));
	dialog->Show();
	while (sample->getProcessing()) {
		dialog->Update(int(sample->getFinished() * 100));
	}
	dialog->Show(false);
	// TODO destroy dialog
}


void RetimerMainFrame::reportError(wxString string) {
	wxMessageDialog* dialog = new wxMessageDialog(this, string, _T("Error"), wxOK | wxICON_ERROR);
	dialog->ShowModal();
}
