#include "\3denEnhanced\ENH_defineCommon.hpp"

params ["_mode"];
disableSerialization;

private _display = uiNamespace getVariable "ENH_Display_VIM";

switch (_mode) do
{
  case "openCreateGUI":
  {
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
      "update" call ENH_fnc_VIM_handleTemplates;
    };
  };
  case "delete":
  {
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
    private _templatesVisible = _display getVariable ["ENH_VIM_templatesVisible", false];
    if (_templatesVisible) then
    {
      CTRL(IDC_VIM_MENU) menuSetText [[3, 0], localize "STR_ENH_VIM_SHOWTEMPLATES"];
      CTRL(IDC_VIM_AVAILABLEITEMSTEXT) ctrlSetText localize "STR_ENH_VIM_AVAILABLEITEMS";
      [CTRL(IDC_VIM_MENU), [2, 0]] call ENH_fnc_VIM_changeFIlter; //Use default path. Workaround because I am lazy. Sue me if you want.
    }
    else
    {
      CTRL(IDC_VIM_MENU) menuSetText [[3, 0], localize "STR_ENH_VIM_HIDETEMPLATES"];
      CTRL(IDC_VIM_AVAILABLEITEMSTEXT) ctrlSetText localize "STR_ENH_VIM_TEMPLATES";
      "update" call ENH_fnc_VIM_handleTemplates;
    };

    //Disable template options
    CTRL(IDC_VIM_MENU) menuEnable [[3, 1], !_templatesVisible];
    CTRL(IDC_VIM_MENU) menuEnable [[3, 2], !_templatesVisible];
    CTRL(IDC_VIM_MENU) menuEnable [[3, 3], !_templatesVisible];
    CTRL(IDC_VIM_MENU) menuEnable [[3, 5], !_templatesVisible];

    for "_i" from 0 to ((CTRL(IDC_VIM_MENU) menuSize [2]) - 1) do
    {
      CTRL(IDC_VIM_MENU) menuEnable [[2, _i], _templatesVisible];
    };

    _display setVariable ["ENH_VIM_templatesVisible", !_templatesVisible];
  };
  case "preview":
  {
    //Get template data from listbox
    private _ctrlItems = CTRL(IDC_VIM_AVAILABLEITEMSLIST);
    private _row = lbCurSel _ctrlItems;

    if (_row isEqualTo -1) exitWith {};

    private _value = _ctrlItems lbData lbCurSel _ctrlItems;
    [false, _value] call ENH_fnc_VIM_loadAttributeValue;
  };
  case "update":
  {
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