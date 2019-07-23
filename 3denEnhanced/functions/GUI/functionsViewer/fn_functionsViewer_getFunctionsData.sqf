/*
   Author: R3vo

   Date: 2019-07-22

   Description:
   Used by Enh_FunctionsViewer GUI. Gets the data of all functions and returns it.

   Parameter(s):
   -

   Returns:
   ARRAY: Array containing arrays in format [_configStr,_addon,_tag,_category,_fncShort,_fncLong,_path,_preInit,_preStart,_postInit,_recompile]
*/

private _functionsData = [];

{
	_x params ["_config","_configStr"];
	{
		private _addon = configName _x;
		private _tag = getText (_config >> "CfgFunctions" >> _addon >> "tag");
		if (_tag isEqualTo "") then {_tag = _addon};
		{
			private _category = configName _x;
			{
				private _fncShort = configName _x;

				private _extension = getText (_config >> "CfgFunctions" >> _addon >> _category >> _fncShort >> "ext");
				if (_extension isEqualTo "") then {_extension = ".sqf"};

				private _path = getText (_config >> "CfgFunctions" >> _addon >> _category >> "file");
				_path = if (_path isEqualTo "") then 
				{
					getText (_config >> "CfgFunctions" >> _addon >> _category >> _fncShort >> "file")
				}
				else
				{
					format ["%1\fn_%2%3",_path,_fncShort,_extension];	
				};
				
				private _fncLong = format ["%1_fnc_%2",_tag,_fncShort];
				private _preInit = getNumber (_config >> "CfgFunctions" >> _addon >> _category >> _fncShort >> "preInit");
				private _preStart = getNumber (_config >> "CfgFunctions" >> _addon >> _category >> _fncShort >> "preStart");
				private _postInit = getNumber (_config >> "CfgFunctions" >> _addon >> _category >> _fncShort >> "postInit");
				private _recompile = getNumber (_config >> "CfgFunctions" >> _addon >> _category >> _fncShort >> "recompile");
				_functionsData pushBack [_configStr,_addon,_tag,_category,_fncShort,_fncLong,_path,_preInit,_preStart,_postInit,_recompile];
			} forEach ("isClass _x" configClasses (_config >> "CfgFunctions" >> _addon >> _category));
		} forEach ("isClass _x" configClasses (_config >> "CfgFunctions" >> _addon));
	} forEach ("isClass _x" configClasses (_config >> "CfgFunctions"));
} forEach [[configFile,"configFile"],[missionConfigFile,"missionConfigFile"],[campaignConfigFile,"campaignConfigFile"]];

_functionsData