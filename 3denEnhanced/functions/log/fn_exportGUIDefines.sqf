/*
  Author: R3vo

  Date: 2020-11-24

  Description:
  Exports all commonly used GUI defines using either the class keyword or import keyword. Furthermore, the kind of classes to export can also be defined.
  The function will also include commonly used files like control styles and types and will also add links to the documentation.

  Parameter(s):
  0: STRING - Used keyword, can be "mod" for config or "mission" for missionConfig (Default: "mission")
  1: STRING - Which classes should be exported (Default: "")
    ""        - all GUI base classes, including more exotic ones and Eden Editor ones
    "3DEN"    - Eden Editor base classes like ctrlStatic or ctrlStaticPicture
    "classic" - classic base classes like RscText or RscPicture

  Returns:
  STRING: Returns generated text on success otherwise "" and error message with expected input
*/

params [["_mode","mission"], ["_classes", "classic"]];

if !(_mode in ["mission","mod"]) exitWith {["Mode was ""%1"", expected was ""mission"" or ""mod""",_mode] call BIS_fnc_error; ""};
if !(_classes in ["","3DEN","classic"]) exitWith {["Classes was ""%1"", expected was """", ""3DEN"" or ""classic""",_mode] call BIS_fnc_error; ""};

private _return = "//- GUI Documenation: https://community.bistudio.com/wiki/Arma:_GUI_Configuration" + endl;
_return = _return + "//- Control Types:    https://community.bistudio.com/wiki/Arma:_GUI_Configuration#Control_Types" + endl;
_return = _return + "//- Control Styles:   https://community.bistudio.com/wiki/Arma:_GUI_Configuration#Control_Styles" + endl + endl;
_mode = if (_mode == "mission") then {"import"} else {"class"};
private _baseControls =
[
    "RscActivePicture",
    "RscActivePictureKeepAspect",
    "RscActiveText",
    "RscButton",
    "RscButtonMenu",
    "RscButtonMenuCancel",
    "RscButtonMenuOK",
    "RscButtonMenuSteam",
    "RscButtonTextOnly",
    "RscCheckBox",
    "RscCombo",
    "RscControlsGroup",
    "RscControlsGroupNoHScrollbars",
    "RscControlsGroupNoScrollbars",
    "RscControlsGroupNoVScrollbars",
    "RscEdit",
    "RscFrame",
    "RscHTML",
    "RscLine",
    "RscListBox",
    "RscListNBox",
    "RscMapControl",
    "RscMapControlEmpty",
    "RscObject",
    "RscPicture",
    "RscPictureKeepAspect",
    "RscProgress",
    "RscShortcutButton",
    "RscSlider",
    "RscStructuredText",
    "RscText",
    "RscToolbox",
    "RscTree",
    "RscVideo",
    "RscXListBox",
    "RscXSliderH",
    "Scrollbar"
];

_return = _return + "//Eden Editor macros such as background colour and pixel grid" + endl + "#include ""\a3\3DEN\UI\macros.inc""" + endl;
_return = _return + "//GRIDs" + endl + "#include ""\a3\ui_f\hpp\definecommongrids.inc""" + endl;
_return = _return + "//DIK Key Codes" + endl + "#include ""\a3\ui_f\hpp\definedikcodes.inc""" + endl;
_return = _return + "//Eden Editor IDDs and IDCs as well as control types, styles and macros" + endl + "#include ""\a3\3den\ui\resincl.inc""" + endl + endl;

if (_classes in ["","3DEN"]) then
{
  private _3DENBaseControls = [];
  {
    _3DENBaseControls pushBack configName _x;
  } forEach ("isClass _x &&
              configName _x select [0,4] == ""ctrl"" &&
              isNumber (_x >> ""deletable"") &&
              count (_x >> ""controls"") == 0" configClasses configFile);

  _3DENBaseControls sort true;

  _return = _return + "//Eden Editor Base Controls" + endl;
  {
      _return = _return + _mode + " " + _x + ";" + endl;
  } forEach _3DENBaseControls;
};

if (_classes in ["","classic"]) then
{
  _return = _return + endl + "//Classic Base Controls" + endl;
  {
    _return = _return + _mode + " " + _x + ";" + endl;
  } forEach _baseControls;
};

if (_classes in [""]) then
{
  private _exoticClassed = [];
  {
    _exoticClassed pushBack configName _x;
  } forEach ("isClass _x &&
              isNumber (_x >> ""deletable"") &&
              count (_x >> ""controls"") == 0" configClasses configFile);

  _exoticClassed sort true;

  _return = _return + endl + "//Excotic Base Controls" + endl;

  {
    _return = _return + _mode + " " + _x  + ";" + endl;
  } forEach (_exoticClassed - _baseControls);
};

copyToClipboard _return;

if (is3DEN) then {[localize "STR_A3_RSCDISPLAYARSENAL_MESSAGE_CLIPBOARD"] call BIS_fnc_3DENNotification} else {hint localize "STR_A3_RSCDISPLAYARSENAL_MESSAGE_CLIPBOARD"};

_return
