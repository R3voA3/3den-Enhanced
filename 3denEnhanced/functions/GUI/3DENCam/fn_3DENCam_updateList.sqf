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

private _ctrlLnB = _displayOrControl displayCtrl 1000;
lbClear _ctrlLnB;
_ctrlLnB lnbSetColumnsPos [0,0.1,0.75,0.9];
{
	_x params ["_world","_cam3DENPosition","","","_description",["_systemTime",[2020,01,01,00,00]]];

		if (count _description > 45) then
		{
			_description = ((_description select [0,45]) + "...");
		};

		_date = format
		[
			"%1/%2/%3",
			(_systemTime # 2) call ENH_fnc_twoDigitsStr,
			(_systemTime # 1) call ENH_fnc_twoDigitsStr,
			(_systemTime # 0) call ENH_fnc_twoDigitsStr
		];

		_time = format
		[
			"%1:%2",
			(_systemTime # 3) call ENH_fnc_twoDigitsStr,
			(_systemTime # 4) call ENH_fnc_twoDigitsStr
		];

		
		private _index = _ctrlLnB lnbAddRow ["",_description,_date,_time];
		
		_ctrlLnB lnbSetPicture [[_index,0],getText (configFile >> "CfgWorlds" >> _world >> "pictureMap")];
		_ctrlLnB lnbSetData [[_index,0],str _x];
		
		private _number = ((_index + 1) call ENH_fnc_twoDigitsStr) + ".";
		_ctrlLnB lnbSetText [[_index,0],_number];

		_cam3DENPosition params ["_xC","_yC","_zC"];
		_ctrlLnB lbSetTooltip
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
} forEach (profileNamespace getVariable ["ENH_Cam3DENSavedPositions",[]]);

true