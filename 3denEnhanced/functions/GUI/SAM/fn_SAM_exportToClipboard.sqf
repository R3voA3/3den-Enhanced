/*
  Author: R3vo

  Date: 2019-05-24

  Description:
  Used by the ENH_ENH_ScenarioAttributesManager_TemplateData GUI. Exports attributes from selected template.

  Parameter(s):
  0: CONTROL - Control button

  Returns:
  ARRAY: Array with attribute values, if not templates was selected it returns an empty array
*/

#include "\3denEnhanced\ENH_defineCommon.hpp"

disableSerialization;
params ["_ctrlButton"];

private _display = ctrlParent _ctrlButton;
private _ctrlLB = CTRL(IDC_SAM_TEMPLATES);
private _index = lbCurSel _ctrlLB;

if (_index isEqualTo -1) exitWith {[]};

//Data is string but needs to be array
_data = call compile (_ctrlLB lbData _index);
_data # 2 apply {_x resize 2};

//We only need the attribute value not title and description of the template
_data = [_data # 2] call ENH_fnc_exportWithLB;

copyToClipboard _data;
["ENH_DataCopied"] call BIS_fnc_3DENNotification;

_data