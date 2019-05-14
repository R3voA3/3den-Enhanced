/*
   Author: Revo

   Description:
   Adds more entries to the location list in Eden editor.

   Parameter(s):
   -
   Returns:
   BOOLEAN - true
*/

disableSerialization;

private _disp = findDisplay 313;
private _ctrlTV = _disp displayCtrl 75;

//Defines world size variables
private _r = sqrt (2) * worldSize;
private _centerMap = [worldSize / 2,worldSize / 2,0];

tvClear _ctrlTV;

private _fn_addItems =
{
   params ["_types","_parentName","_isLocation"];

   private _locations = nearestTerrainObjects [_centerMap,_types,_r,false,true];
   if (_locations isEqualTo []) exitWith {false};

   private _parentIndex = _ctrlTV tvAdd [[],/* localize  */_parentName];
   {
      private _name = getText (configfile >> "CfgVehicles" >> typeOf _x >> "displayName");
      private _index = _ctrlTV tvAdd [[_parentIndex],_name];
      _ctrlTV tvSetData [[_parentIndex,_index],str position _x];
      _ctrlTV tvSetPicture [[_parentIndex,_index],"a3\3den\data\displays\display3den\panelleft\locationlist_ca.paa"];
   } forEach _locations;

   _ctrlTV tvSort [[_parentIndex],false];
};

//Add cities to tree view, they aren't map objects, but locations
private _parentIndex = _ctrlTV tvAdd [[],"Cities & Villages"/* localize "STR_ENH_locationList_locations" */];
{
   private _index = _ctrlTV tvAdd [[_parentIndex],text _x];
   _ctrlTV tvSetData [[_parentIndex,_index],str position _x];
   _ctrlTV tvSetPicture [[_parentIndex,_index],"a3\3den\data\displays\display3den\panelleft\locationlist_ca.paa"];
} forEach (nearestLocations [_centerMap,["NameCity","NameVillage","VegetationVineyard","Strategic","Name"],_r]);

//Add airports
private _parentIndex = _ctrlTV tvAdd [[],"Airports"/* localize "STR_ENH_locationList_locations" */];
{
   private _index = _ctrlTV tvAdd [[_parentIndex],text _x];
   _ctrlTV tvSetData [[_parentIndex,_index],str position _x];
   _ctrlTV tvSetPicture [[_parentIndex,_index],"a3\3den\data\displays\display3den\panelleft\locationlist_ca.paa"];
} forEach (nearestLocations [_centerMap,["Airport"],_r]);

//Get all locations
[["Chapel"],"Chapels",false] call _fn_addItems;
[["Church"],"Churches",false] call _fn_addItems;
[["Transmitter"],"Transmitters",false] call _fn_addItems;
[["Hospital"],"Hospitals",false] call _fn_addItems;
[["Powersolar","Powerwind","Powerwave"],"Power Production",false] call _fn_addItems;
[["FuelStation"],"Fuel Stations",false] call _fn_addItems;

_ctrlTV tvSort [[0],false];

true