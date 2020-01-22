/*
	Author: Revo

	Description:
	Used by the Enh_TexturFinder GUI. Fills the GUI with all found textures.

	Parameter(s):
	-

	Returns:
	BOOLEAN: true / false
*/

disableSerialization;

private _display = findDisplay 140000;
private _ctrlLB = _display displayCtrl 1500;
private _ctrlProgressList = _display displayCtrl 1800;
private _tooltip = localize "STR_ENH_functions_fillTextureLB_tooltip";
private _index = 0;
private _textureCount = count Enh_TextureFinder_TexturesFound;

private _fnc_addToList =
{
	params ["_texturePath"];
	_index = _ctrlLB lbAdd _texturePath;
	_ctrlLB lbSetPictureRight [_index,_texturePath];
	_ctrlLB lbSetTooltip [_index,_tooltip];
};

lbClear _ctrlLB;
{
	switch (Enh_TextureFinder_Filter) do
	{
		case 0://All
		{
			[_x] call _fnc_addToList;
		};
		case 1://paa
		{
			if !("jpg" in _x) then
			{
				[_x] call _fnc_addToList;
			};
		};
		case 2://jpg
		{
			if !("paa" in _x) then
			{
				[_x] call _fnc_addToList;
			};
		};
	};
	_ctrlProgressList progressSetPosition linearConversion
	[
		0,
		_textureCount,
		lbSize _ctrlLB -1,//_forEachIndex,
		0,
		1
	];
} forEach Enh_TextureFinder_TexturesFound;

lbSort _ctrlLB;

true