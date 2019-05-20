/*
   Author: Revo

   Description:
   Used by the Enh_FunctionViewer GUI. Called onLoad.

   Parameter(s):
   0: DISPLAY - Display

   Returns:
   BOOLEAN: true
*/

disableSerialization;

private ["_ctrlTV", "_logo", "_indexConfig", "_nameConfig", "_indexTAG", "_nameTAG", "_valueTAG", "_mod", "_valueTag", "_indexCategory", "_nameCategory", "_pathCategory", "_indexFnc", "_fileExtension", "_pathFunction", "_path", "_attributes"];

params ["_disp"];
_ctrlTV = _disp displayCtrl 1500;
_logo = "";

if (round (ctrlfade (findDisplay 313 displayctrl 1023)) < 1) then
{
	"showinterface" call BIS_fnc_3DENInterface
};

if (isnil "BIS_fnc_init") then {4 call (uinamespace getvariable "BIS_fnc_recompile")};
//Disable recompile buttons if recompiling isn't allowed
if (getNumber (missionConfigfile >> "allowFunctionsRecompile") == 0) then
{
	(_disp displayCtrl 1600) ctrlEnable false;
	(_disp displayCtrl 1601) ctrlEnable false;
};

{//Config
	_indexConfig = _forEachIndex;
	_nameConfig = _x # 0;
	_ctrlTV tvAdd [[], _x # 1];
	{//Tags
		_ctrlTV tvAdd [[_indexConfig],configName _x];
		_indexTAG = _forEachIndex;
		_nameTAG = configName _x;
		_valueTAG = getText (_x >> "tag");
		_mod = configSourceMod (configfile >> "CfgFunctions" >> _nameTAG);
		_logo = modParams [_mod,["logoSmall"]] param [0,""];
		_ctrlTV tvSetPictureRight [[_indexConfig,_indexTAG],_logo];

		if (_valueTAG == "") then {_valueTag = configName _x};
		{//Categories
			_ctrlTV tvAdd [[_indexConfig,_indexTAG],configName _x];
			_indexCategory = _forEachIndex;
			_nameCategory = configName _x;
			_pathCategory= getText (_x >> "file");

			{//Functions
				_indexFnc = _ctrlTV tvAdd [[_indexConfig,_indexTAG,_indexCategory],configName _x];
				_fileExtension = getText (_x >> "ext");
				if (_fileExtension == "") then {_fileExtension = ".sqf"};
				_pathFunction = getText (_x >> "file");//Some paths are defined per file not per category
				_path = "";
				if (_pathFunction == "") then
				{
					_path = _pathCategory + "\fn_" + configName _x + _fileExtension;
				}
				else
				{
					_path = _pathFunction;
				};

				//Data has to be string but will be split with splitString "%" to get the actual values
				_ctrlTV tvSetData [[_indexConfig,_indexTAG,_indexCategory,_indexFnc],_valueTag + "_fnc_" + configName _x + "%" + _path];

				//Get attributes and set tooltip accordingly
				_attributes = format ["preStart = %1",getNumber (_x >> "PreStart")] + endl +
				format ["PreInit = %1",getNumber (_x >> "preInit")] + endl +
				format ["PostInit = %1",getNumber (_x >> "postInit")] + endl +
				format ["Recompile = %1",getNumber (_x >> "recompile")];
				
				_ctrlTV tvSetTooltip [[_indexConfig,_indexTAG,_indexCategory,_indexFnc],_attributes];
 
			} forEach ((_nameConfig >> "CfgFunctions" >> _nameTAG >> _nameCategory) call BIS_fnc_returnChildren);
			_ctrlTV tvSort [[_indexConfig,_indexTAG,_indexCategory],false];//Sort
		} forEach ((_nameConfig >> "CfgFunctions" >> configName _x) call BIS_fnc_returnChildren);
		_ctrlTV tvSort [[_indexConfig,_indexTAG],false];//Sort
	} forEach ((_nameConfig >> "CfgFunctions") call BIS_fnc_returnChildren);
	_ctrlTV tvSort [[_indexConfig],false];//Sort
} foreach [[configFile,"configFile"],[missionConfigFile,"missionConfigFile"],[campaignConfigFile,"campaignConfigFile"]];

_ctrlTV tvSetCurSel (profileNamespace getVariable ["Enh_FunctionsViewer_LastViewed",[0,0,0,0]]);

_disp displayAddEventHandler ["keyDown",//Focus Search
{
	params ["_disp", "_key", "_shift", "_ctrl"];
	if (_key isEqualTo 33 && _ctrl) then
	{
		ctrlSetFocus (_disp displayCtrl 1400);
	}
}];

_disp displayAddEventHandler ["keyDown",//Copy
{
	params ["_disp", "_key", "_shift", "_ctrl"];
	if (_key isEqualTo 45 && _ctrl) then
	{
		call Enh_fnc_functionsViewer_copy;
	}
}];

true