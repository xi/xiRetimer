#include "xiRTPrefsDialog.h"
#include <iostream>

xiRTPrefsDialog::xiRTPrefsDialog(Marker* m, Sample* s, Curve* c) : PrefsDialog( (wxWindow*)NULL )
{
  marker=m;
  sample=s;
  curve=c;
  
  oldInterpolationMode=marker->getInterpolationMode();
  oldStretchMode=sample->getStretchMode();
  oldTempo=curve->getTempo();
  oldBeatResolution=curve->getBeatResolution();

  c_intmode->SetSelection(oldInterpolationMode);
  c_stretchmode->SetSelection(oldStretchMode);

  wxString wxs4;
  wxs4 << oldTempo;
  t_tempo->SetValue(wxs4);

  wxString wxs5;
  wxs5 << oldBeatResolution;
  t_beatres->SetValue(wxs5);
}

void xiRTPrefsDialog::OnIntModeChange( wxCommandEvent& event ) {
  marker->setInterpolationMode(c_intmode->GetSelection());
}

void xiRTPrefsDialog::OnStretchModeChange( wxCommandEvent& event ) {
  sample->setStretchMode(c_stretchmode->GetSelection());
}

void xiRTPrefsDialog::OnTempoEnter( wxCommandEvent& event ) {
  long tempo;
  if (event.GetString().ToLong(&tempo))
    curve->setTempo(tempo);
  else
    std::cout << "Please insert an interger " << curve->getTempo() << std::endl;
}

void xiRTPrefsDialog::OnBeatResEnter( wxCommandEvent& event ) {
  double beatres;
  if (event.GetString().ToDouble(&beatres))
    curve->setBeatResolution(beatres);
  else
    std::cout << "Please insert a float " << std::endl;
}

void xiRTPrefsDialog::OnOKClick( wxCommandEvent& event ) {
  Close();
}

void xiRTPrefsDialog::OnCancelClick( wxCommandEvent& event ) {
  marker->setInterpolationMode(oldInterpolationMode);
  sample->setStretchMode(oldStretchMode);
  curve->setTempo(oldTempo);
  curve->setBeatResolution(oldBeatResolution);
  Close();
}
