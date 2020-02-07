/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the debug options attribute. Called when attribute is saved.

   Parameter(s):
   0: CONTROL - Controls group

   Returns:
   BOOLEAN: true
*/

params ["_ctrlGroup"];

private _ctrlLB = _ctrlGroup controlsGroupCtrl 100;
private _enabledOptions = [];

for "_i" from 0 to lbSize _ctrlLB -1 do
{
	if (_ctrlLB lbValue _i > 0) then
	{
		_enabledOptions pushBack _i;
	};
};

profileNamespace setVariable ["ENH_DebugOptions_Settings",_enabledOptions];

true