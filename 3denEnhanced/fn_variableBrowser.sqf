[] spawn
{
	disableSerialization;

	_display = findDisplay 46 createDisplay "RscDisplayEmpty";
	
	_edit = _display ctrlCreate ["RscEdit", 645];
	_edit ctrlSetPosition [0,0,1,0.04];
	_edit ctrlSetBackgroundColor [0,0,0,1];
	_edit ctrlCommit 0;
	
	_tv = _display ctrlCreate ["RscTreeSearch", -1];
	_tv ctrlSetFont "EtelkaMonospacePro"; 
	_tv ctrlSetFontHeight 0.03; 
	_tv ctrlSetPosition [0,0.06,1,0.94];
	_tv ctrlSetBackgroundColor [0,0,0,1];
	_tv ctrlCommit 0;
	
	_classes = "true" configClasses (configFile >> "CfgVehicles");
	
	private _index = _tv tvAdd [[],"missionNamespace"];
	{
		_tv tvAdd [[_index],_x];

	} forEach allVariables missionNamespace;
	_tv tvSort [[_index],false];

	private _index = _tv tvAdd [[],"profileNamespace"];
	{
		_tv tvAdd [[_index],_x];

	} forEach allVariables profileNamespace;
	_tv tvSort [[_index],false];

	private _index = _tv tvAdd [[],"uiNamespace"];
	{
		_tv tvAdd [[_index],_x];

	} forEach allVariables uiNamespace;
	_tv tvSort [[_index],false];

	private _index = _tv tvAdd [[],"parsingNamespace"];
	{
		_tv tvAdd [[_index],_x];

	} forEach allVariables parsingNamespace;
	_tv tvSort [[_index],false];
};