/*
  Author: Revo

  Description:
  Automatically creates a mission description for Steam.

  Parameter(s):
  -

  Returns:
  BOOLEAN: true
*/

["ENH_DataCopied"] call BIS_fnc_3DENNotification;
sleep 0.5;
do3DENAction 'OpenSteamPublishDialog';

private _export = "";
//Steam formatting has been removed due to incompatibility issues. Code stays for now.
/*_fnc_addLine =
{
	params [["_text",""],["_value",""],["_bold",true],["_headline",false]];
	if !(_value isEqualType "") then {_value = str _value};
	if (_bold) then {_text = "[b]" + _text + "[/b]"};
	if (_headline) then {_text = "[h1]" + _text + "[/h1]"};
	_export = _export + _text + " " + _value + endl;
};*/

_fnc_addLine = 
{
  params [["_text",""],["_value",""]];
  if !(_value isEqualType "") then {_value = str _value};
  _export = _export + _text + " " + _value + endl;
};
//General
_description = "Scenario" get3DENMissionAttribute "OverviewText";
//DLC
_appID = "Scenario" get3DENMissionAttribute "AppID";

switch _appID do
{
  case 275700: {_appID = "Zeus"};
  case 288520: {_appID = "Karts"};
  case 304380: {_appID = "Helicopters"};
  case 332350: {_appID = "Marksmen"};
  case 395180: {_appID = "Apex"};
  case 571710: {_appID = "Laws of War"};
  case 601670: {_appID = "Jets"};
  case 744950: {_appID = "Tac Ops"};
  case 798390: {_appID = "Tanks"};
};
//Multiplayer
_gameType = "Multiplayer" get3DENMissionAttribute "GameType";
_minPlayers = "Multiplayer" get3DENMissionAttribute "MinPlayers";
_maxPlayers = "Multiplayer" get3DENMissionAttribute "MaxPlayers";
_respawn = "Multiplayer" get3DENMissionAttribute "Respawn";
if (_respawn > 0) then {_respawn = "Yes"} else {_respawn = "No"};
_revive = "Multiplayer" get3DENMissionAttribute "ReviveMode";
if (_revive > 0) then {_revive= "Yes"} else {_revive = "No"};
_bleedOutTime = "Multiplayer" get3DENMissionAttribute "ReviveBleedOutDelay";
_simulationDetail = "Multiplayer" get3DENMissionAttribute "ReviveUnconsciousStateMode";
if (_simulationDetail > 0) then {_simulationDetail = "Advanced"} else {_simulationDetail = "Basic"};
//Environment
_time = ("Intel" get3DENMissionAttribute "IntelTime") call BIS_fnc_TimetoString;
_fog = ("Intel" get3DENMissionAttribute "IntelFogStart") # 0;
_rain = ("Intel" get3DENMissionAttribute "IntelRainStart");
_date = ("Intel" get3DENMissionAttribute "IntelDate");
_date = (str (_date # 1) + "-" + str (date # 2) + "-" + str (date # 0));

["Mission Description",""] call _fnc_addLine;
["",_description,false,false] call _fnc_addLine;

if !(_appID == 0) then
{
  ["","",false,false] call _fnc_addLine;//Empty line because of Steam formatting
  ["Required DLC:",_appID] call _fnc_addLine;
};

if !(_gameType == "Unknown") then
{
  ["","",false,false] call _fnc_addLine;
  ["Multiplayer","",false,true] call _fnc_addLine;
  ["Game Type:",_gameType] call _fnc_addLine;
  ["min. Players:",_minPlayers] call _fnc_addLine;
  ["max. Players:",_maxPlayers] call _fnc_addLine;
};
if (_respawn == "Yes") then
{
  ["","",false,false] call _fnc_addLine;//Empty line because of Steam formatting
  ["Respawn System","",false,true] call _fnc_addLine;
  ["Respawn enabled?",_respawn] call _fnc_addLine;
};
if (_revive == "Yes") then
{
  ["","",false,false] call _fnc_addLine;//Empty line because of Steam formatting
  ["Revive System","",false,true] call _fnc_addLine;
  ["Revive enabled?",_revive] call _fnc_addLine;
  ["Bleed Out Time:",format ["%1 seconds",_bleedOutTime]] call _fnc_addLine;
  ["Simulation Detail:",_simulationDetail] call _fnc_addLine;
};
["","",false,false] call _fnc_addLine;//Empty line because of Steam formatting
["Environment","",false,true] call _fnc_addLine;
["Date:",_date] call _fnc_addLine;
["Time:",_time] call _fnc_addLine;
["Fog:",format ["%1%2",round (_fog * 100),"%"]] call _fnc_addLine;
["Rain:",format ["%1%2",round (_rain * 100),"%"]] call _fnc_addLine;
["Map:",getText (configfile >> "CfgWorlds" >> worldName >> "description")] call _fnc_addLine;
["","",false,false] call _fnc_addLine;
["[img]https://i.imgur.com/p7Fv1Z6.gif[/img]","",false,false] call _fnc_addLine;
["","",false,false] call _fnc_addLine;
["Rate, favorite and comment! Feedback is always appreciated!","",false,true] call _fnc_addLine;

copyToClipboard _export;

true