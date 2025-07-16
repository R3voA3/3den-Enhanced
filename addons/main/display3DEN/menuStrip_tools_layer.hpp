class ENH_Folder_Layer
{
    text = "$STR_3DEN_LAYER_TEXTPLURAL";
    picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
    items[] +=
    {
        "ENH_SelectAllLayers",
        "Separator",
        "ENH_DeleteEmptyLayers",
        "Separator",
        "ENH_EnableLayer",
        "ENH_ShowLayer",
    };
};

class ENH_SelectAllLayers
{
    action = "set3DENSelected (all3DENEntities # 6)";
    picture = "\x\enh\addons\main\data\selectAllLayers_ca.paa";
    text = "$STR_ENH_MAIN_TOOLS_SELECTALLLAYERS";
};
class ENH_DeleteEmptyLayers
{
    action = "call ENH_fnc_deleteEmptyLayers";
    picture = "\x\enh\addons\main\data\trash_ca.paa";
    text = "$STR_ENH_MAIN_TOOLS_DELETEEMPTYLAYERS";
};
class ENH_EnableLayer
{
    action = "'EnableLayer' call bis_fnc_3DENInterface";
    picture = "\a3\3DEN\Data\Displays\Display3DEN\PanelLeft\entityList_layerEnable_ca.paa";
    text = "$STR_3DEN_DISPLAY3DEN_ENABLELAYER_TOOLTIP";
};
class ENH_ShowLayer
{
    action = "'ShowLayer' call bis_fnc_3DENInterface";
    picture = "\a3\3DEN\Data\Displays\Display3DEN\PanelLeft\entityList_layerShow_ca.paa";
    text = "$STR_3DEN_DISPLAY3DEN_SHOWLAYER_TOOLTIP";
};
