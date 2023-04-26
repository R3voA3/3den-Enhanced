params ["_ctrlTV", ctrlNull];

private _display = ctrlParent _ctrlTV;

private _ctrlProgress_1 = _display displayCtrl IDC_PROGRESS_1;
private _ctrlProgress_2 = _display displayCtrl IDC_PROGRESS_2;
private _ctrlProgress_3 = _display displayCtrl IDC_PROGRESS_3;
private _ctrlProgress_4 = _display displayCtrl IDC_PROGRESS_4;
private _ctrlProgress_5 = _display displayCtrl IDC_PROGRESS_5;

private _ctrlProgressText_1 = _display displayCtrl IDC_PROGRESS_TEXT_1;
private _ctrlProgressText_2 = _display displayCtrl IDC_PROGRESS_TEXT_2;
private _ctrlProgressText_3 = _display displayCtrl IDC_PROGRESS_TEXT_3;
private _ctrlProgressText_4 = _display displayCtrl IDC_PROGRESS_TEXT_4;
private _ctrlProgressText_5 = _display displayCtrl IDC_PROGRESS_TEXT_5;

// No item selected
if (count _path != 3) then
{
  _ctrlProgress_1 ctrlShow false;
  _ctrlProgress_2 ctrlShow false;
  _ctrlProgress_3 ctrlShow false;
  _ctrlProgress_4 ctrlShow false;
  _ctrlProgress_5 ctrlShow false;

  _ctrlProgressText_1 ctrlShow false;
  _ctrlProgressText_2 ctrlShow false;
  _ctrlProgressText_3 ctrlShow false;
  _ctrlProgressText_4 ctrlShow false;
  _ctrlProgressText_5 ctrlShow false;
}
else
{
  _ctrlProgress_1 ctrlShow true;
  _ctrlProgress_2 ctrlShow true;
  _ctrlProgress_3 ctrlShow true;
  _ctrlProgress_4 ctrlShow true;
  _ctrlProgress_5 ctrlShow true;

  _ctrlProgressText_1 ctrlShow true;
  _ctrlProgressText_2 ctrlShow true;
  _ctrlProgressText_3 ctrlShow true;
  _ctrlProgressText_4 ctrlShow true;
  _ctrlProgressText_5 ctrlShow true;


  _ctrlProgress_1 progressSetPosition random 1;
  _ctrlProgress_2 progressSetPosition random 1;
  _ctrlProgress_3 progressSetPosition random 1;
  _ctrlProgress_4 progressSetPosition random 1;
  _ctrlProgress_5 progressSetPosition random 1;
};