#include "\x\enh\addons\main\script_component.hpp"

disableSerialization;

if isNull ENH_Garrison_AreaHelper exitWith {};

private _display = findDisplay IDD_DISPLAY3DEN;
private _classes = toLower (ctrlText CTRL(IDC_GARRISON_BLACKLIST_VALUE));

_classes = _classes splitString ", ";
private _isBlacklist = [true, false] select lbCurSel CTRL(IDC_GARRISON_BLACKLIST_TOGGLE);

(ENH_Garrison_AreaHelper get3DENAttribute "Size3") select 0 params ["_a", "_b"];

private _r = selectMax [_a, _b] * 3;

ENH_Garrison_ValidBuildings = (ENH_Garrison_AreaHelper nearObjects ["Building", _r]) + all3DENEntities # 0 select
{
    _x buildingPos -1 isNotEqualTo [] &&
    _isBlacklist != (toLower typeOf _x in _classes) &&
    _x inArea ENH_Garrison_AreaHelper
};

private _positionCount = 0;
ENH_Garrison_ValidBuildings apply {_positionCount = _positionCount + count (_x buildingPos -1)};

private _coverage = [10, 4, 2, 1] select lbCurSel CTRL(IDC_GARRISON_COVERAGE);

private _text = parseText format
[
    "<t color='#1F8AD2'>%1</t> buildings with <t color='#517923'>%2</t> positions.<br/><t color='#C38114'>%3</t> entities selected.",
    count ENH_Garrison_ValidBuildings,
    round (_positionCount / _coverage),
    count ENH_Garrison_SelectedEntities
];

CTRL(IDC_GARRISON_INFO) ctrlSetStructuredText _text;
