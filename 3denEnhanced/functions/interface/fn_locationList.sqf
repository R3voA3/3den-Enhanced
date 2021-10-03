/*
  Author: R3vo

  Description:
  Adds more entries to the location list in Eden editor.

  Parameter(s):
  -

  Returns:
  BOOLEAN: true / false
*/

#include "\a3\3DEN\UI\resincl.inc"

disableSerialization;
private _ctrlTV = findDisplay IDD_DISPLAY3DEN displayCtrl IDC_DISPLAY3DEN_LOCATIONS;
tvClear _ctrlTV;

//Clear list and exit in VR map
if (worldName isEqualTo "vr") exitWith {false};

private _icon = getText (configFile >> "cfg3DEN" >> "Default" >> "Draw" >> "locationList");

//Locations
private _idCategory = _ctrlTV tvAdd [[], getText (configFile >> "cfgWorlds" >> worldName >> "description")];
{
  _idLocation = _ctrlTV tvAdd [[_idCategory], text _x];
  _ctrlTV tvSetData [[_idCategory, _idLocation], str locationPosition _x];
  _ctrlTV tvSetPicture [[_idCategory, _idLocation], _icon];
} foreach nearestLocations [[0, 0, 0], ["nameVillage", "nameCity", "nameCityCapital"], worldSize * sqrt 2];

_ctrlTV tvSort [[_idCategory], false];
_ctrlTV tvExpand [_idCategory];

private _fn_addTerrainObjects =
{
  params ["_types", "_parentName", "_isLocation"];

  private _locations = nearestTerrainObjects [[0, 0, 0], _types, worldSize * sqrt 2, false, true];

  if (_locations isEqualTo []) exitWith {false};

  private _parentIndex = _ctrlTV tvAdd [[0], localize _parentName];
  {
    private _name = getText (configfile >> "CfgVehicles" >> typeOf _x >> "displayName");
    if (_name isEqualTo "") then
    {
      //_name = localize "STR_ENH_LOCATIONLIST_UNKNOWN";
      _name = getModelInfo _x # 0;
      _name = _name trim [".p3d", 2];
    };
    private _index = _ctrlTV tvAdd [[0, _parentIndex], _name];

    _ctrlTV tvSetData [[0, _parentIndex, _index], str position _x];
    _ctrlTV tvSetPicture [[0, _parentIndex, _index], "a3\3den\data\displays\display3den\panelleft\locationlist_ca.paa"];
  } forEach _locations;
  _ctrlTV tvSort [[_parentIndex], false];
};

//Add all terrain objects
[["Chapel"], "STR_ENH_LOCATIONLIST_CHAPELS", false] call _fn_addTerrainObjects;
[["Church"], "STR_ENH_LOCATIONLIST_CHURCHES", false] call _fn_addTerrainObjects;
[["FuelStation"], "STR_ENH_LOCATIONLIST_FUELSTATIONS", false] call _fn_addTerrainObjects;
[["Powersolar", "Powerwind", "Powerwave"], "STR_ENH_LOCATIONLIST_POWERPRODUCTION", false] call _fn_addTerrainObjects;
[["Shipwreck"], "STR_ENH_LOCATIONLIST_SHIPWRECKS", false] call _fn_addTerrainObjects;
[["Transmitter"], "STR_ENH_LOCATIONLIST_TRANSMITTERS", false] call _fn_addTerrainObjects;

//Airports need to be added separatly, since they are going into their own folder
private _locations = nearestLocations [[0, 0, 0], ["Airport"], worldSize * sqrt 2];

if (_locations isEqualTo []) exitWith {false};
private _parentIndex = _ctrlTV tvAdd [[0], localize "STR_ENH_LOCATIONLIST_AIRPORTS"];

{
  private _index = _ctrlTV tvAdd [[0, _parentIndex], text _x];
  _ctrlTV tvSetData [[0, _parentIndex, _index], str position _x];
  _ctrlTV tvSetPicture [[0, _parentIndex, _index], _icon];
} forEach _locations;

true