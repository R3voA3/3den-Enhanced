#include "\userconfig\3denEnhanced_Optionals_MenuStrip.hpp"

private _ctrlMenuStrip = findDisplay 313 displayCtrl 120;
private _toDelete = _menuStripBlacklist apply {localize _x};
_fnc_delete =
{
	if ((_ctrlMenuStrip menuText _this) in _toDelete) then
	{
		_ctrlMenuStrip menuDelete _this
	};
};

for "_i" from 15 to 0 step -1 do
{
    [_i] call _fnc_delete;
	for "_j" from 30 to 0 step -1 do
	{
		[_i,_j] call _fnc_delete;
		for "_k" from 30 to 0 step -1 do
		{
			[_i,_j,_k] call _fnc_delete;
		};
	};
};

true