/*
	Author: Revo

	Description:
	Used by the ENH_TexturFinder GUI. Fills the GUI with all found textures.

	Parameter(s):
	-

	Returns:
	BOOLEAN: true / false
*/

disableSerialization;

private _display = findDisplay 140000;
private _ctrlLB = _display displayCtrl 1500;
private _ctrlProgressList = _display displayCtrl 1800;
private _tooltip = localize "STR_ENH_FUNCTIONS_FILLTEXTURELB_TOOLTIP";
private _index = 0;
private _textureCount = count ENH_TextureFinder_TexturesFound;
private _buttonSearch = _display displayCtrl 1900;
private _buttonUpdateList = _display displayCtrl 1700;
private _toolboxFilter = _display displayCtrl 2000;

//Disable button to prevent user from starting search twice
_buttonSearch ctrlEnable false;
_buttonUpdateList ctrlEnable false;
_toolboxFilter ctrlEnable false;

private _fnc_addToList =
{
	params ["_texturePath"];
	_index = _ctrlLB lbAdd _texturePath;
	_ctrlLB lbSetPictureRight [_index,_texturePath];
	_ctrlLB lbSetTooltip [_index,_tooltip];
};

private _updateProgressBar =
{
	_ctrlProgressList progressSetPosition linearConversion
	[
		0,
		_textureCount,
		lbSize _ctrlLB -1,//_forEachIndex,
		0,
		1
	];
};

private _allowedType = ["all",".jpg",".paa"] select ENH_TextureFinder_Filter;
lbClear _ctrlLB;

if (_allowedType != "all") then
{
	{
		if !(_allowedType in _x) then
		{
			[_x] call _fnc_addToList;
		};
		call _updateProgressBar;
	} forEach ENH_TextureFinder_TexturesFound;
}
else
{
	{
		[_x] call _fnc_addToList;
		call _updateProgressBar;
	} forEach ENH_TextureFinder_TexturesFound;
};

lbSort _ctrlLB;

//Reenable after list was filled
_buttonSearch ctrlEnable true;
_buttonUpdateList ctrlEnable true;
_toolboxFilter ctrlEnable true;

true