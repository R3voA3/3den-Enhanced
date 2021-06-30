#include "\3denEnhanced\ENH_defineCommon.hpp"

params ["_mode"];
disableSerialization;

private _display = uiNamespace getVariable "ENH_Display_VIM";

switch (_mode) do
{
  case "openCreateGUI":
  {
    if !(_display getVariable ["ENH_VIM_templatesVisible", false]) then {'toggle' execVM 'handleTemplates.sqf'};
    _display createDisplay "ENH_VIM_TemplateData";
  };
  case "create":
  {
    private _templates = profileNamespace getVariable ["ENH_VIM_Templates", []];
    private _displayTemplateData = findDisplay IDD_VIM_TEMPLATEDATA;

    //Return inventory data
    private _value = [true] call ENH_fnc_VIM_applyAttribute;
    private _templateTitle = ctrlText (_displayTemplateData displayCtrl IDC_VIM_TEMPLATEDATA_TITLE);
    private _templateDescription = ctrlText (_displayTemplateData displayCtrl IDC_VIM_TEMPLATEDATA_DESCRIPTION);
    if !(_templateTitle isEqualTo "") then
    {
      _templates pushBack [_templateTitle, _templateDescription, _value];
      profileNamespace setVariable ["ENH_VIM_Templates", _templates];
      _displayTemplateData closeDisplay 1;
      call ENH_fnc_VIM_updateTemplateList;
    };
  };
  case "delete":
  {
    if !(_display getVariable ["ENH_VIM_templatesVisible", false]) then {'toggle' execVM 'handleTemplates.sqf'};
    private _ctrlItems = CTRL(IDC_VIM_AVAILABLEITEMSLIST);
    private _row = lbCurSel _ctrlItems;

    _ctrlItems lbDelete _row;

    //Update templates variable
    private _templates = profileNamespace getVariable ["ENH_VIM_Templates", []];
    _templates deleteAt _row;
    profileNamespace setVariable ["ENH_VIM_Templates", _templates];
  };
  case "toggle":
  {
    lbClear CTRL(IDC_VIM_AVAILABLEITEMSLIST);

    if (_display getVariable ["ENH_VIM_templatesVisible", false]) then
    {
      CTRL(20) menuSetText [[3, 0], localize "STR_ENH_VIM_SHOWTEMPLATES"];
      CTRL(IDC_VIM_AVAILABLEITEMSTEXT) ctrlSetText localize "STR_ENH_VIM_AVAILABLEITEMS";
      [CTRL(20), [2, 0]] execVM "changeFilter.sqf"; //Use default path. Workaround because I am lazy. Sue me if you want.
      _display setVariable ["ENH_VIM_templatesVisible", false];
    }
    else
    {
      CTRL(20) menuSetText [[3, 0], localize "STR_ENH_VIM_HIDETEMPLATES"];
      CTRL(IDC_VIM_AVAILABLEITEMSTEXT) ctrlSetText localize "STR_ENH_VIM_TEMPLATES";
      'update' execVM 'handleTemplates.sqf';
      _display setVariable ["ENH_VIM_templatesVisible", true];
    };
  };
  case "preview":
  {
    //Make sure to show template list first
    if !(_display getVariable ["ENH_VIM_templatesVisible", false]) then {'toggle' execVM 'handleTemplates.sqf'};

    //Get template data from listbox
    private _ctrlItems = CTRL(IDC_VIM_AVAILABLEITEMSLIST);
    private _row = lbCurSel _ctrlItems;

    if (_row isEqualTo -1) exitWith {};

    private _value = _ctrlItems lbData lbCurSel _ctrlItems;
    [false, _value] call ENH_fnc_VIM_loadAttributeValue;
  };
  case "update":
  {
    //Make sure to show template list first
    if !(_display getVariable ["ENH_VIM_templatesVisible", false]) then {'toggle' execVM 'handleTemplates.sqf'};
    private _ctrlItems = CTRL(IDC_VIM_AVAILABLEITEMSLIST);
    lbClear _ctrlItems;
    {
      _x params ["_name", "_description", "_data", ["_date", systemTime]];
      _ctrlItems lbAdd _name;
      _ctrlItems lbSetData [_forEachIndex, _data];
      _ctrlItems lbSetTextRight [_forEachIndex, [_date] call ENH_fnc_systemTimeFormatted];
      _ctrlItems lbSetTooltip [_forEachIndex, _description];
    } foreach (profileNamespace getVariable ["ENH_VIM_Templates", []]);
  };
};