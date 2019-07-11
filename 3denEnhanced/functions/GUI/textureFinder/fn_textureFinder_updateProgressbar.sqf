
/*
	Author: Revo

	Description:
	Used by the Enh_TexturFinder GUI. Updates the progressbar at anytime.

	Parameter(s):
	-

	Returns:
	BOOLEAN: true / false
*/

private ["_disp","_ctrlProg","_ctrlProgText","_locString"];
disableSerialization;

_disp = findDisplay 140000;
_ctrlProg = _disp displayCtrl 1001;
_ctrlProgText = _disp displayCtrl 1002;

waitUntil {!isNil "Enh_TextureFinder_NumToSearch" && !isNull (findDisplay 140000)};

_locString = localize "STR_ENH_updateProgressbar";

while {!isNull (findDisplay 140000)} do
{
	_ctrlProgText ctrlSetText format [_locString,Enh_TextureFinder_NumSearched,Enh_TextureFinder_NumToSearch,str (count Enh_TextureFinder_Textures)];
	_ctrlProg progressSetPosition (linearConversion [0,Enh_TextureFinder_NumToSearch,Enh_TextureFinder_NumSearched,0,1]);
	sleep 0.05;
};