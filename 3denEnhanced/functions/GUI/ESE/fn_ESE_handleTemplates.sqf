#include "\3denEnhanced\defines\ENH_defineCommon.hpp"

params ["_mode"];
disableSerialization;

private _display = uiNamespace getVariable "ENH_Display_ESE";

switch (_mode) do
{
  case "openCreateGUI":
  {
    _display createDisplay "ENH_ESE_TemplateData";
  };
  case "create":
  {
    private _templates = profileNamespace getVariable ["ENH_VIM_Templates", []];
    private _displayTemplateData = findDisplay IDD_ESE_TEMPLATEDATA;

    //Return inventory data
    private _value = [true] call ENH_fnc_ESE_applyAttribute;
    private _templateTitle = ctrlText (_displayTemplateData displayCtrl IDC_ESE_TEMPLATEDATA_TITLE);
    private _templateDescription = ctrlText (_displayTemplateData displayCtrl IDC_ESE_TEMPLATEDATA_DESCRIPTION);
    if !(_templateTitle isEqualTo "") then
    {
      _templates pushBack [_templateTitle, _templateDescription, _value];
      profileNamespace setVariable ["ENH_VIM_Templates", _templates];
      _displayTemplateData closeDisplay 1;
      "update" call ENH_fnc_ESE_handleTemplates;
    };
  };
  case "delete":
  {
    private _ctrlItems = CTRL(IDC_ESE_TEMPLATESLIST);
    private _row = lbCurSel _ctrlItems;

    _ctrlItems lbDelete _row;

    //Update templates variable
    private _templates = profileNamespace getVariable ["ENH_VIM_Templates", []];
    _templates deleteAt _row;
    profileNamespace setVariable ["ENH_VIM_Templates", _templates];
  };
  case "preview":
  {
    //Get template data from listbox
    private _ctrlItems = CTRL(IDC_ESE_TEMPLATESLIST);
    private _row = lbCurSel _ctrlItems;

    if (_row isEqualTo -1) exitWith {};

    private _value = _ctrlItems lbData lbCurSel _ctrlItems;
    [false, _value] call ENH_fnc_ESE_loadAttributeValue;
  };
  case "update":
  {
    private _lbTemplates = CTRL(IDC_ESE_TEMPLATESLIST);
    lbClear _lbTemplates;
    {
      _x params ["_name", "_description", "_data", ["_date", systemTime]];
      [_lbTemplates, _name, _data, "", "", _description, [_date] call ENH_fnc_systemTimeFormatted] call ENH_fnc_ESE_lbAdd;
    } foreach (profileNamespace getVariable ["ENH_VIM_Templates", []]);
  };
};