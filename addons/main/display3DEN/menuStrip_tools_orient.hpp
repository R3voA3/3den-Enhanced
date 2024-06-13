class ENH_Folder_Orient
{
	text = "$STR_ENH_MAIN_FOLDER_ORIENT";
	picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
	items[] +=
	{
		"ENH_SetRandomDir",
		"ENH_ReverseDirection",
		"Separator",
		"ENH_OrientateNorth",
		"ENH_OrientateEast",
		"ENH_OrientateSouth",
		"ENH_OrientateWest"
	};
};
class ENH_SetRandomDir
{
	Text = "$STR_ENH_MAIN_TOOLS_RANDOMDIR";
	picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_rotation_off_ca.paa";
	action = "-1 call ENH_fnc_setOrientation";
	conditionShow = "selectedObject + selectedWaypoint + selectedLogic + selectedMarker";
	shortcuts[] = {INPUT_CTRL_OFFSET + DIK_NUMPAD3};
	wikiDescription = "Randomises direction of all selected entities.";
};
class ENH_ReverseDirection
{
	text = "$STR_ENH_MAIN_TOOLS_REVERSEDIRECTION";
	picture = "\A3\ui_f\data\igui\rsctitles\mpprogress\respawn_ca.paa";
	action = "-2 call ENH_fnc_setOrientation";
	shortcuts[] = {INPUT_CTRL_OFFSET + DIK_NUMPAD7};
	wikiDescription = "Reverses direction of all selected entities.";
};
class ENH_OrientateNorth
{
	text = "$STR_ENH_MAIN_TOOLS_ORIENTATENORTH";
	picture = "\A3\ui_f\data\igui\cfg\simpleTasks\letters\N_ca.paa";
	action = "0 call ENH_fnc_setOrientation";
	shortcuts[] = {INPUT_CTRL_OFFSET + DIK_NUMPAD8};
	wikiDescription = "Orients all selected entities to north.";
};
class ENH_OrientateEast: ENH_OrientateNorth
{
	text = "$STR_ENH_MAIN_TOOLS_ORIENTATEEAST";
	picture = "\A3\ui_f\data\igui\cfg\simpleTasks\letters\E_ca.paa";
	action = "90 call ENH_fnc_setOrientation";
	shortcuts[] = {INPUT_CTRL_OFFSET + DIK_NUMPAD6};
	wikiDescription = "Orients all selected entities to east.";
};
class ENH_OrientateSouth: ENH_OrientateNorth
{
	text = "$STR_ENH_MAIN_TOOLS_ORIENTATESOUTH";
	picture = "\A3\ui_f\data\igui\cfg\simpleTasks\letters\S_ca.paa";
	action = "180 call ENH_fnc_setOrientation";
	shortcuts[] = {INPUT_CTRL_OFFSET + DIK_NUMPAD2};
	wikiDescription = "Orients all selected entities to south.";
};
class ENH_OrientateWest: ENH_OrientateNorth
{
	text = "$STR_ENH_MAIN_TOOLS_ORIENTATEWEST";
	picture = "\A3\ui_f\data\igui\cfg\simpleTasks\letters\W_ca.paa";
	action = "270 call ENH_fnc_setOrientation";
	shortcuts[] = {INPUT_CTRL_OFFSET + DIK_NUMPAD4};
	wikiDescription = "Orients all selected entities to west.";
};