/*
   Author: R3vo

   Date: 2020-01-16

   Description:
   Updates listbox of 3DENCameraPositions UI.

   Parameter(s):
   0: DISPLAY or CONTROL - Display or control to get parent display

   Returns:
   BOOLEAN: true
*/

params ["_displayOrControl"];

if (_displayOrControl isEqualType controlNull) then 
{
	_displayOrControl = ctrlParent _displayOrControl;
};

private _ctrlLB = _displayOrControl displayCtrl 1000;
lbClear _ctrlLB;

{
	_x params ["_world","_cam3DENPosition","","","_description"];

	private _icon = getText (configFile >> "CfgWorlds" >> _world >> "pictureMap");
	private _worldDisplayName = getText (configFile >> "CfgWorlds" >> _world >> "description");
	private _index = 0;
	
	if (count _description > 50) then
	{
		_index = _ctrlLB lbAdd ((_description select [0,50]) + "...");
	}
	else
	{
		_index = _ctrlLB lbAdd _description;
	};
		
	//Format position and add it as tooltip
	_cam3DENPosition params ["_xC","_yC","_zC"];
	_ctrlLB lbSetTooltip 
	[
		_index,
		format 
		[
			"X: %1 Y: %2 Z: %3\n\n%4\n\n%5\n%6",
			_xC,
			_yC,
			_zC,
			_description,
			localize "STR_ENH_3DENCAM_HELPDELETE",
			localize "STR_ENH_3DENCAM_HELPMOVETO"
		]
	];

	_ctrlLB lbSetPictureRight [_index,_icon];
	_ctrlLB lbSetTextRight [_index,_worldDisplayName];

	//Save whole data set to listbox. It's used to update the profileNamespace variable later
	_ctrlLB lbSetData [_index,str _x];

	if !(_world isEqualTo worldName) then
	{
		_ctrlLB lbSetColor [_index,[1,0,0,1]];
		_ctrlLB lbSetColorRight [_index,[1,0,0,1]];
	};
} forEach (profileNamespace getVariable ["ENH_Cam3DENSavedPositions",[]]);

lbSort [_ctrlLB,"DESC"];

true