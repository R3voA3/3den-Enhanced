/*
   Author: Revo

   Description:
   Adds more entries to the location list in Eden editor.

   Parameter(s):
   -
   Returns:
   BOOLEAN - true
*/

private ["_disp","_ctrlTV","_r","_y","_fn_getLocations","_type","_fn_addItems","_items","_parentName","_parentIndex","_posString","_index","_chapel","_fuel","_church","_trans","_hospital","_shipWreck","_solar","_wind","_wave"];

disableSerialization;

_disp = findDisplay 313;
_ctrlTV = _disp displayCtrl 75;
//Defines world size variables
_r = sqrt(2 * worldSize^2);
_x = worldSize / 2;
_y = _x;

tvClear _ctrlTV;

_fn_getLocations =
{
 params [["_type","",[""]]];
 nearestTerrainObjects [[_x,_y,0], [_type],_r,false];
};

_fn_addItems =
{
 params [["_items",[],[[]]],["_parentName","",[""]]];

 if (count _items == 0) exitWith {false};

 _parentIndex = _ctrlTV tvAdd [[],localize _parentName];
 {
  _posString = str position _x;

  _name = getText (configfile >> "CfgVehicles" >> typeOf _x >> "displayName");
  //if (_name == "") then {_name = _parentName};
  _index = _ctrlTV tvAdd [[_parentIndex],_name];

  _ctrlTV tvSetData [[_parentIndex,_index],str position _x];
  _ctrlTV tvSetPicture [[_parentIndex,_index],"a3\3den\data\displays\display3den\panelleft\locationlist_ca.paa"];
 } forEach _items;
};
//Get all cities
_city= nearestLocations [[_x,_y,0],["NameCity","NameVillage","VegetationVineyard","Strategic","Name"],_r];
//Add cities to tree view
_parentIndex = _ctrlTV tvAdd [[],localize "STR_ENH_locationList_locations"];
{
 _index = _ctrlTV tvAdd [[_parentIndex],text _x];
 _ctrlTV tvSetData [[_parentIndex,_index],str position _x];
 _ctrlTV tvSetPicture [[_parentIndex,_index],"a3\3den\data\displays\display3den\panelleft\locationlist_ca.paa"];
} forEach _city;
//Get all locations
_chapel = "Chapel" call _fn_getLocations;
_fuel = "FuelStation" call _fn_getLocations;
_church = "Church" call _fn_getLocations;
_trans = "Transmitter" call _fn_getLocations;
_hospital = "Hospital" call _fn_getLocations;
//_shipWreck = "Shipwreck" call _fn_getLocations;
_solar = "Powersolar" call _fn_getLocations;
_wind = "Powerwind" call _fn_getLocations;
_wave = "Powerwave" call _fn_getLocations;
//Add locations to tree view
[_chapel,"STR_ENH_locationList_chapels"] call _fn_addItems;
[_fuel,"STR_ENH_locationList_fuelStations"] call _fn_addItems;
[_church,"STR_ENH_locationList_churches"] call _fn_addItems;
[_trans,"STR_ENH_locationList_transmitters"] call _fn_addItems;
[_hospital,"STR_ENH_locationList_hospitals"] call _fn_addItems;
//[_shipWreck,"STR_ENH_locationList_shipwrecks"] call _fn_addItems;
[_solar,"STR_ENH_locationList_solarDieselPower"] call _fn_addItems;
[_wave,"STR_ENH_locationList_wavePower"] call _fn_addItems;
[_wind,"STR_ENH_locationList_windPower"] call _fn_addItems;
//Sort the whole tree view from a to b
{
	_ctrlTV tvSort [[_x],false];
	true
} count [0,1,2,3,4,5,6,7,8,9];

tvCollapseAll _ctrlTV;
//Workaround to make sure edit search is empty and tree view is displayed
[_disp] spawn
{
	disableSerialization;
	params ["_disp"];
	sleep 0.05;
	(_disp displayCtrl 1042) ctrlSetText " ";
	sleep 0.05;
	(_disp displayCtrl 1042) ctrlSetText "";
};

true