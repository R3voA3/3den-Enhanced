class ENH_Folder_Align
{
  text = "$STR_ENH_MAIN_FOLDER_ALIGN";
  picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
  items[] +=
  {
    "ENH_AlignXMax",
    "ENH_AlignXMin",
    "ENH_AlignYMax",
    "ENH_AlignYMin",
    "ENH_AlignZMax",
    "ENH_AlignZMin"
  };
};
class ENH_AlignXMax
{
  text = "$STR_ENH_MAIN_TOOLS_ALIGN_X_MAX";
  action = "[0] call (uiNamespace getVariable 'ENH_fnc_alignEntities')";
  shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_ALT_OFFSET + DIK_NUMPAD6};
};
class ENH_AlignXMin
{
  text = "$STR_ENH_MAIN_TOOLS_ALIGN_X_MIN";
  action = "[0, false] call (uiNamespace getVariable 'ENH_fnc_alignEntities')";
  shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_ALT_OFFSET + DIK_NUMPAD4};
};
class ENH_AlignYMax
{
  text = "$STR_ENH_MAIN_TOOLS_ALIGN_Y_MAX";
  action = "[1] call (uiNamespace getVariable 'ENH_fnc_alignEntities')";
  shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_ALT_OFFSET + DIK_NUMPAD8};
};
class ENH_AlignYMin
{
  text = "$STR_ENH_MAIN_TOOLS_ALIGN_Y_MIN";
  action = "[1, false] call (uiNamespace getVariable 'ENH_fnc_alignEntities')";
  shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_ALT_OFFSET + DIK_NUMPAD2};
};
class ENH_AlignZMax
{
  text = "$STR_ENH_MAIN_TOOLS_ALIGN_Z_MAX";
  action = "[2] call (uiNamespace getVariable 'ENH_fnc_alignEntities')";
  shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_ALT_OFFSET + DIK_NUMPAD9};
};
class ENH_AlignZMin
{
  text = "$STR_ENH_MAIN_TOOLS_ALIGN_Z_MIN";
  action = "[2, false] call (uiNamespace getVariable 'ENH_fnc_alignEntities')";
  shortcuts[] = {INPUT_CTRL_OFFSET + INPUT_ALT_OFFSET + DIK_NUMPAD1};
};