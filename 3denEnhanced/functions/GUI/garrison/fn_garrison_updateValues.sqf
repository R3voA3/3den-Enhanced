#include "\3denEnhanced\defines\ENH_defineCommon.hpp"
disableSerialization;

params ["_object"];

private _display = findDisplay IDD_3DEN;
private _positionCount = 0;
private _classes = toLower (ctrlText CTRL(IDC_GARRISON_BLACKLIST_VALUE));
private _isBlackList = lbCurSel CTRL(IDC_GARRISON_BLACKLIST_TOGGLE);
private _coverage = [10, 4, 2, 1] select (lbCurSel CTRL(IDC_GARRISON_COVERAGE));

_classes = _classes splitString ", ";
_isBlacklist = [true, false] select _isBlacklist;

ENH_Garrison_AreaHelper_A = (_object get3DENAttribute "Size2") select 0 select 0;
ENH_Garrison_AreaHelper_B = (_object get3DENAttribute "Size2") select 0 select 1;
ENH_Garrison_AreaHelper_ROTATATION_Z = (_object get3DENAttribute "Rotation") select 0 select 2;
ENH_Garrison_AreaHelper_Diameter = sqrt(ENH_Garrison_AreaHelper_A ^ 2 + ENH_Garrison_AreaHelper_A ^ 2);
ENH_Garrison_ValidBuildings = (ENH_Garrison_AreaHelper nearObjects ["Building", ENH_Garrison_AreaHelper_Diameter]) select {_x buildingPos -1 isNotEqualTo [] && _isBlackList != (toLower (typeOf _x) in _classes)};
ENH_Garrison_Buildigns_InArea = ENH_Garrison_ValidBuildings inAreaArray [getPosWorld _object, ENH_Garrison_AreaHelper_A, ENH_Garrison_AreaHelper_B, ENH_Garrison_AreaHelper_ROTATATION_Z];

ENH_Garrison_Buildigns_InArea apply {_positionCount = _positionCount + count (_x buildingPos -1)};
private _text = parseText format ["<t color='#1F8AD2'>%1</t> buildings with <t color='#517923'>%2</t> positions.<br/><t color='#C38114'>%3</t> entities selected.", count ENH_Garrison_Buildigns_InArea, round (_positionCount / _coverage), count ENH_Garrison_SelectedEntities];
CTRL(IDC_GARRISON_INFO) ctrlSetStructuredText _text;