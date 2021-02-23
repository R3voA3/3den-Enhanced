/*
  Author: R3vo

  Date: 2020-02-11

  Description:
  Used by the ENH_VariableViewer GUI. Called when listNbox selection changed.

  Parameter(s):
  0: DISPLAY - ENH_VariableViewer GUI. Used to fill the listNBox with data.

  Returns:
  -
*/

#include "\3denEnhanced\defineCommon.hpp"
#define SHOW_FNC (profileNamespace getVariable ["ENH_VariableViewer_HideFunctions", false])

disableSerialization;
params ["_display"];

private _ctrlLNB = CTRL(IDC_VARIABLEVIEWER_LIST);
private _namespace = call ENH_fnc_variableViewer_getNamespace;
private _value = "";

lbClear _ctrlLNB;

{
  _value = _namespace getVariable _x;
  if (SHOW_FNC && (_value isEqualType {})) then {continue};//Skip is functions should not be shown
  if !(isNil "_value") then
  {
    _ctrlLNB lnbAddRow
    [
      _x,
      format ["%1", _value],
      typeName _value
    ];
  };
} forEach allVariables _namespace;

CTRL(IDC_VARIABLEVIEWER_VARIABLECOUNT) ctrlSetText format ["#%1", count allVariables _namespace];