/*
  Author: R3vo

  Description:
  Used by ENH_actionCreator GUI.

  Parameter(s):
  INTERNAL

  Returns:
  -
*/

#include "\3denEnhanced\defines\ENH_defineCommon.hpp"

disableSerialization;

params ["_display", "_mode"];

switch (_mode) do
{
  case "onLoad":
  {
    private _save = profileNamespace getVariable ["ENH_ActionCreator_History", []];

    _save params
    [
      ["_title", ""],
      ["_script", ""],
      ["_arguments", "nil"],
      ["_priority", "1.5"],
      ["_showWindow", "true"],
      ["_hideOnUse", "true"],
      ["_shortCut", ""],
      ["_condition", "true"],
      ["_radius", "50"],
      ["_showUnconcious", "false"]
    ];

    CTRL(IDC_ACTIONCREATOR_TITLE) ctrlSetText _title;
    CTRL(IDC_ACTIONCREATOR_SCRIPT) ctrlSetText _script;
    CTRL(IDC_ACTIONCREATOR_ARGUMENTS) ctrlSetText _arguments;

    CTRL(IDC_ACTIONCREATOR_PRIORITY) sliderSetPosition parseNumber _priority;
    CTRL(IDC_ACTIONCREATOR_PRIORITY) ctrlSetTooltip _priority;

    CTRL(IDC_ACTIONCREATOR_SHOWWINDOW) ctrlSetChecked call compile _showWindow;
    CTRL(IDC_ACTIONCREATOR_HIDEONUSE) ctrlSetChecked call compile _hideOnUse;
    CTRL(IDC_ACTIONCREATOR_SHORTCUT) ctrlSetText _shortCut;
    CTRL(IDC_ACTIONCREATOR_CONDITION) ctrlSetText _condition;

    CTRL(IDC_ACTIONCREATOR_RADIUS) sliderSetPosition parseNumber _radius;
    CTRL(IDC_ACTIONCREATOR_RADIUS) ctrlSetTooltip _radius;

    CTRL(IDC_ACTIONCREATOR_SHOWUNCONCIOUS) ctrlSetChecked call compile _showUnconcious;
  };
  case "export":
  {
    private _title = ctrlText CTRL(IDC_ACTIONCREATOR_TITLE);
    private _script = ctrlText CTRL(IDC_ACTIONCREATOR_SCRIPT);
    private _args = ctrlText CTRL(IDC_ACTIONCREATOR_ARGUMENTS);
    private _priority = sliderPosition CTRL(IDC_ACTIONCREATOR_PRIORITY);
    private _showWindow = cbChecked CTRL(IDC_ACTIONCREATOR_SHOWWINDOW);
    private _hideOnUse = cbChecked CTRL(IDC_ACTIONCREATOR_HIDEONUSE);
    private _shortcut = ctrlText CTRL(IDC_ACTIONCREATOR_SHORTCUT);
    private _condition = ctrlText CTRL(IDC_ACTIONCREATOR_CONDITION);
    private _radius = sliderPosition CTRL(IDC_ACTIONCREATOR_RADIUS);
    private _showUnconcious = cbChecked CTRL(IDC_ACTIONCREATOR_SHOWUNCONCIOUS);

    if (_args isEqualTo "") then {_args = "nil"} else {_args = format ["[%1]", _args]};
    if (_condition isEqualTo "") then {_condition = "true"};

    profileNamespace setVariable ["ENH_ActionCreator_History", [_title, _script, _args, str _priority, str _showWindow, str _hideOnUse, _shortcut, _condition, str _radius, str _showUnconcious]];

    private _export = "this addAction" + endl + "[" + endl + "  ";
    _export = _export + format ["""%1"",", _title] + endl + "  ";
    _export = _export + format ["{ %1 },", _script] + endl + "  ";
    _export = _export + format ["%1,", _args] + endl + "  ";
    _export = _export + format ["%1,", _priority] + endl + "  ";
    _export = _export + format ["%1,", _showWindow] + endl + "  ";
    _export = _export + format ["%1,", _hideOnUse] + endl + "  ";
    _export = _export + format ["""%1"",", _shortcut] + endl + "  ";
    _export = _export + format ["""%1"",", _condition] + endl + "  ";
    _export = _export + format ["%1,", _radius] + endl + "  ";
    _export = _export + format ["%1,", _showUnconcious] + endl + "];";

    //Set variable used by display3denCopy and create the display
    uinamespace setVariable ["display3DENCopy_data", ["", _export]];

    findDisplay IDD_ACTIONCREATOR createDisplay "display3denCopy";
  };
};