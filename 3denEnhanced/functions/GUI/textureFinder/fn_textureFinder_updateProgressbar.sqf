
/*
	Author: Revo

	Description:
	Used by the Enh_TexturFinder GUI. Updates the progressbar at anytime.

	Parameter(s):
	-

	Returns:
	BOOLEAN: true / false
*/

disableSerialization;

private _display = findDisplay 140000;
private _ctrlProg = _display displayCtrl 1001;
private _ctrlProgText = _display displayCtrl 1002;

while {!isNull _display} do
{
	sleep 0.1;
	_ctrlProgText ctrlSetText format 
	[
		localize "STR_ENH_updateProgressbar",
		Enh_TextureFinder_ClassesSearched,
		Enh_TextureFinder_ClassesFound,
		count Enh_TextureFinder_TexturesFound
	];
	_ctrlProg progressSetPosition linearConversion 
	[
		0,
		Enh_TextureFinder_ClassesFound,
		Enh_TextureFinder_ClassesSearched,
		0,
		1
	];
};

true