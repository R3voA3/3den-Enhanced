/*
	Author: Revo

	Description:
	Toggles help control in 3denRadio GUI.

	Parameter(s):
	-

	Returns:
	BOOLEAN: true
*/

private _disp = ctrlparent (_this # 0);
private _ctrlHelp = _disp displayCtrl 2400;

if (ctrlFade _ctrlHelp < 1) then
{
	_ctrlHelp ctrlSetFade 1;
	_ctrlHelp ctrlCommit 0;
} else
{
	_ctrlHelp ctrlSetFade 0;
	_ctrlHelp ctrlCommit 0;
};

true