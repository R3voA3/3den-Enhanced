/*
   Author: Revo

   Description:
   Used by the Enh_FunctionViewer GUI.

   Parameter(s):
   STRING - mode to be used, can be "ONLOAD", "RECOMPILE_SELECTED", "SELCHANGED", "COPY", "CLOSE"

   Returns:
   BOOLEAN - true
*/

private ["_disp","_ctrlTV","_ctrlCode","_ctrlFncName","_ctrlFncPath","_logo","_input","_parameter","_indexConfig","_nameConfig","_indexTAG","_nameTAG","_valueTAG","_mod","_valueTag","_indexCategory","_nameCategory","_path","_indexFnc","_fileExtension","_pathFunction","_preInit","_preStart","_postInit","_recompile","_key","_ctrl","_export","_data","_fncName","_fncPath","_code","_ctrlCodePos"];

disableSerialization;

//define display and all controls once
_disp = findDisplay 180000;
_ctrlTV = _disp displayCtrl 1500;
_ctrlCode = _disp displayCtrl 1401;
_ctrlFncName = _disp displayCtrl 1402;
_ctrlFncPath = _disp displayCtrl 1403;
_logo = "";

params [["_input","ONLOAD"],["_parameter",[]]];

switch (_input) do
{
	case "ONLOAD":
	{
		if (round (ctrlfade ((findDisplay 313) displayctrl 1023)) < 1) then
		{
			"showinterface" call BIS_fnc_3DENInterface
		};

		with missionnamespace do//Make sure functions are compiled
		{
			if (isnil {bis_fnc_init}) then {4 call (uinamespace getvariable "bis_fnc_recompile")};
		};

		if (getNumber(missionconfigfile >> "allowFunctionsRecompile") == 0) then//Disable recompile buttons if recompiling isn't allowed
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
						_preInit = getNumber (_x >> "preInit");
						if (_preInit > 0) then {_preInit = "preInit: Enabled"} else {_preInit = "preInit: Disabled"};

						_preStart = getNumber (_x >> "preStart");
						if (_preStart > 0) then {_preStart = "preStart: Enabled"} else {_preStart = "preStart: Disabled"};

						_postInit = getNumber (_x >> "postInit");
						if (_postInit > 0) then {_postInit  = "postInit: Enabled"} else {_postInit  = "postInit: Disabled"};

						_recompile = getNumber (_x >> "recompile");
						if (_recompile > 0) then {_recompile  = "recompile: Enabled"} else {_recompile  = "recompile: Disabled"};

						_ctrlTV tvSetTooltip [[_indexConfig,_indexTAG,_indexCategory,_indexFnc],_preInit + endl + _preStart + endl + _postInit + endl + _recompile];

					} forEach ((_nameConfig >> "CfgFunctions" >> _nameTAG >> _nameCategory) call BIS_fnc_returnChildren);
					_ctrlTV tvSort [[_indexConfig,_indexTAG,_indexCategory],false];//Sort
				} forEach ((_nameConfig >> "CfgFunctions" >> configName _x) call BIS_fnc_returnChildren);
				_ctrlTV tvSort [[_indexConfig,_indexTAG],false];//Sort
			} forEach ((_nameConfig >> "CfgFunctions") call BIS_fnc_returnChildren);
			_ctrlTV tvSort [[_indexConfig],false];//Sort
		} foreach [[configFile,"configFile"],[missionConfigFile,"missionConfigFile"],[campaignConfigFile,"campaignConfigFile"]];

		_disp displayAddEventHandler ["keyDown",//Focus Search
		{
			params ["_disp", "_key", "_shift", "_ctrl", "_alt"];
			if (_key isEqualTo 33 && _ctrl) then
			{
				ctrlSetFocus (_disp displayCtrl 1400);
			}
		}];

		_disp displayAddEventHandler ["keyDown",//Copy
		{
			params ["_disp", "_key", "_shift", "_ctrl", "_alt"];
			if (_key isEqualTo 45 && _ctrl) then
			{
				"COPY" call Enh_fnc_functionsViewer;
			}
		}];

		_disp displayAddEventHandler ["keyDown",//Make sure ESC Button triggers onClose script
		{
			params ["_disp", "_key", "_shift", "_ctrl", "_alt"];
			if (_key isEqualTo 1) then
			{
				"CLOSE" call Enh_fnc_functionsViewer;
			}
		}];
	};
	case "CLOSE":
	{
		_disp closeDisplay 0;
		"showinterface" call BIS_fnc_3DENInterface;
	};
	case "COPY":
	{
		_export = "/*" + ctrlText _ctrlFncName + "*/" + endl + "/*" + ctrlText _ctrlFncPath + "*/" + endl + endl + ctrlText _ctrlCode;
		copyToClipboard _export;
		playSound "FD_Finish_F";
	};
	case "RECOMPILE_SELECTED":
	{
		(ctrlText _ctrlFncName) call BIS_fnc_recompile;
		playSound "FD_Finish_F";
	};
	case "SELCHANGED":
	{
		_ctrlTV = _parameter # 0;
		_path = _parameter # 1;
		if (count _path < 4) exitWith {false};
		_disp = (findDisplay 180000);

		_data = _ctrlTV tvData _path;
		_fncName = (_data splitString "%") # 0;
		_fncPath = (_data splitString "%") # 1;

		_ctrlFncName ctrlSetText _fncName;
		_ctrlFncPath ctrlSetText _fncPath;

		_code = loadFile _fncPath;
		_ctrlCode ctrlSetText _code;

		//When new function is selected, change scroll width and height dynamically
		_ctrlCodePos = ctrlposition _ctrlCode;
		_ctrlCodePos set [3,1.1 max (ctrlTextHeight _ctrlCode)];//Limit to min 1.1 so control area is always filled
		_ctrlCode ctrlsetposition _ctrlCodePos;
		_ctrlCode ctrlcommit 0;
	};
};

true