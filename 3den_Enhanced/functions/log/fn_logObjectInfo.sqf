/*
	Author: Revo

	Description:
	Collects various information about the selected objects and creates display3denCopy from which they can be copied to the clipboard.

	Parameter(s):
	-

	Returns:
	BOOLEAN: true
*/

private _objects = get3DENSelected "Object";
private _text = "";

{
	private _class = typeOf _x;
	private _vehClass = getText (configFile >> "CfgVehicles" >> _class >> "vehicleClass");
	private _name = (configFile >> "CfgVehicles" >> _class) call BIS_fnc_displayName;
	private _size = boundingBoxReal _x;
	private _p1 = _size # 0;
	private _p2 = _size # 1;
	private _maxWidth = abs ((_p2 # 0) - (_p1 # 0));
	private _maxLength = abs ((_p2 # 1) - (_p1 # 1));
	private _maxHeight = abs ((_p2 # 2) - (_p1 # 2));
	_size = str [_maxWidth,_maxLength,_maxHeight];

	private _parents = str ([configfile >> "CfgVehicles" >> _class, true] call BIS_fnc_returnParents);
	private _modelInfo = str getModelInfo _x;

	private _kind = "N/A";
	private _obj = _x;
	{
		if (_obj isKindOf _x) then {_kind = _x};
	} forEach ["Air","Land","Sea","Tank","Man"];

	private _selectionNames = selectionNames _x;

	_selectionNamesFormatted = "";
	{
		if (_forEachIndex != (count _selectionNames) - 1 ) then
		{
			_selectionNamesFormatted = _selectionNamesFormatted + _x + "," + endl;
		}
		else
		{
			_selectionNamesFormatted = _selectionNamesFormatted + _x;
		};
	} forEach _selectionNames;

	private _objType = switch (getObjectType _x) do
	{
		case 1:
		{
			("1 - Primary - " + localize "STR_ENH_functions_logObjectInfo_primary");
		};
		case 2:
		{
			("2 - Network - " + localize "STR_ENH_functions_logObjectInfo_network");
		};
		case 4:
		{
			("4 - Temporary - " + localize "STR_ENH_functions_logObjectInfo_temporary");
		};
		case 8:
		{
			("8 - TypeVehicle - " + localize "STR_ENH_functions_logObjectInfo_typeVehicle");
		};
		case 16:
		{
			("16 - TypeTempVehicle - " + localize "STR_ENH_functions_logObjectInfo_typeTempVehicle");
		};
		case 32:
		{
			("32 - LandDecal - " + localize "STR_ENH_functions_logObjectInfo_landDecal");
		};
	};
	private _materials = str getObjectMaterials _x;
	private _textures = str getObjectTextures _x;
	private _animationNames = str animationNames _x;

	 _text =  _text +
	([
			localize "STR_ENH_functions_logObjectInfo_name" + endl + _name + endl,
			localize "STR_ENH_functions_logObjectInfo_class" + endl + _class + endl,
			localize "STR_ENH_functions_logObjectInfo_vehicleClass" + endl + _vehClass + endl,
			localize "STR_ENH_functions_logObjectInfo_kindOf" + endl + _kind + endl,
			localize "STR_ENH_functions_logObjectInfo_size" + endl + _size + endl,
			localize "STR_ENH_functions_logObjectInfo_selectionNames"  + endl + _selectionNamesFormatted + endl,
			localize "STR_ENH_functions_logObjectInfo_parents" + endl + _parents + endl,
			localize "STR_ENH_functions_logObjectInfo_modelInfo" + endl + _modelInfo + endl,
			localize "STR_ENH_functions_logObjectInfo_objectType" + endl + _objType + endl,
			localize "STR_ENH_functions_logObjectInfo_materials" + endl + _materials + endl,
			localize "STR_ENH_functions_logObjectInfo_textures" + endl + _textures + endl,
			localize "STR_ENH_functions_logObjectInfo_animationNames" + endl + _animationNames + endl,
			endl + endl + endl + endl
		] joinString endl);
} forEach _objects;
//Set variable used by Display3denCopy and create the display
uinamespace setVariable ["Display3DENCopy_data",[localize "STR_ENH_contextMenu_logObjectInfo",_text]];
findDisplay 313 createDisplay "Display3denCopy";

true