#include "RetimerPrefsDialog.h"

RetimerPrefsDialog::RetimerPrefsDialog(Marker* m, Sample* s, Curve* c) : PrefsDialog( (wxWindow*)NULL )
{
  marker=m;
  sample=s;
  curve=c;
  
  oldInterpolationMode=marker->getInterpolationMode();
  oldShowIntLine=curve->_showIntLine;
  oldStretchMode=sample->getStretchMode();
  oldTempo=curve->getTempo();
  oldBeatResolution=curve->getBeatResolution();

  c_intmode->SetSelection(oldInterpolationMode);
  m_showint->SetValue(oldShowIntLine);
  c_stretchmode->SetSelection(oldStretchMode);

  wxString wxs4;
  wxs4 << oldTempo;
  t_tempo->SetValue(wxs4);

  wxString wxs5;
  wxs5 << oldBeatResolution;
  t_beatres->SetValue(wxs5);
}

void RetimerPrefsDialog::OnIntModeChange( wxCommandEvent& event ) {
  marker->setInterpolationMode(c_intmode->GetSelection());
}

void RetimerPrefsDialog::OnCheckShowInt( wxCommandEvent& event ) {
  curve->_showIntLine=m_showint->GetValue();
}

void RetimerPrefsDialog::OnStretchModeChange( wxCommandEvent& event ) {
  sample->setStretchMode(c_stretchmode->GetSelection());
}

void RetimerPrefsDialog::OnTempoEnter( wxCommandEvent& event ) {
  long tempo;
  if (event.GetString().ToLong(&tempo))
    curve->setTempo(tempo);
  else
    std::cout << "Please insert an interger " << curve->getTempo() << std::endl;
}

void RetimerPrefsDialog::OnBeatResEnter( wxCommandEvent& event ) {
  double beatres;
  if (event.GetString().ToDouble(&beatres))
    curve->setBeatResolution(beatres);
  else
    std::cout << "Please insert a float " << std::endl;
}

void RetimerPrefsDialog::OnOKClick( wxCommandEvent& event ) {
  Close();
}

void RetimerPrefsDialog::OnCancelClick( wxCommandEvent& event ) {
  marker->setInterpolationMode(oldInterpolationMode);
  curve->_showIntLine=oldShowIntLine;
  sample->setStretchMode(oldStretchMode);
  curve->setTempo(oldTempo);
  curve->setBeatResolution(oldBeatResolution);
  Close();
}
