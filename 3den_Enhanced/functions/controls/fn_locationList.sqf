/*
   Author: Revo

   Description:
   Adds more entries to the location list in Eden editor.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true / false
*/

//Exit when Virtual Reality map
if (worldName isEqualTo "vr") exitWith {false};

disableSerialization;

private _ctrlTV = findDisplay 313 displayCtrl 75;

//Defines world size variables
private _l = worldSize / 2;
private _r = sqrt (2) * _l;
private _centerMap = [_l,_l,0];

private _fn_addLocations =
{
   params ["_types","_parentName","_isLocation"];

   private _locations = nearestTerrainObjects [_centerMap,_types,_r,false,true];
 
   if (_locations isEqualTo []) exitWith {false};

   private _parentIndex = _ctrlTV tvAdd [[0],localize _parentName];
   {
      private _name = getText (configfile >> "CfgVehicles" >> typeOf _x >> "displayName");
      if (_name isEqualTo "") then {_name = localize "STR_ENH_locationList_unknown"};
      private _index = _ctrlTV tvAdd [[0,_parentIndex],_name];

      _ctrlTV tvSetData [[0,_parentIndex,_index],str position _x];
      _ctrlTV tvSetPicture [[0,_parentIndex,_index],"a3\3den\data\displays\display3den\panelleft\locationlist_ca.paa"];
   } forEach _locations;

   _ctrlTV tvSort [[_parentIndex],false];
};

//Get all locations
[["Chapel"],"STR_ENH_locationList_chapels",false] call _fn_addLocations;
[["Church"],"STR_ENH_locationList_churches",false] call _fn_addLocations;
[["Transmitter"],"STR_ENH_locationList_transmitters",false] call _fn_addLocations;
[["Powersolar","Powerwind","Powerwave"],"STR_ENH_locationList_powerProduction",false] call _fn_addLocations;
[["FuelStation"],"STR_ENH_locationList_fuelStations",false] call _fn_addLocations;
[["Shipwreck"],"STR_ENH_locationList_shipwrecks",false] call _fn_addLocations;

//Add airports
private _locations = nearestLocations [_centerMap,["Airport"],_r];

if (_locations isEqualTo []) exitWith {false};
private _parentIndex = _ctrlTV tvAdd [[0],localize "STR_ENH_locationList_airports"];

{
   private _index = _ctrlTV tvAdd [[0,_parentIndex],text _x];
   _ctrlTV tvSetData [[0,_parentIndex,_index],str position _x];
   _ctrlTV tvSetPicture [[0,_parentIndex,_index],"a3\3den\data\displays\display3den\panelleft\locationlist_ca.paa"];
} forEach _locations;

true