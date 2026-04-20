#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2020-02-11

    Description:
    Used by the ENH_VariableViewer GUI. Used to get selected namespace from uiNamespace.

    Parameter(s):
    -

    Returns:
    NAMESPACE
*/

private _namespace = uiNamespace getVariable ["ENH_VariableViewer_LastNamespace", "missionNamespace"];

if (_namespace isEqualType "") then
{
    call compile _namespace;
}
else
{
    _namespace;
};
