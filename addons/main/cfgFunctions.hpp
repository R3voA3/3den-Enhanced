class CfgFunctions
{
    class 3denEnhanced
    {
        tag = "ENH";
        class 3DENRadio
        {
            file = "x\enh\addons\main\functions\GUI\3DENRadio";
            class 3DENRadio_exportClassname;
            class 3DENRadio_handlePlaylist;
            class 3DENRadio_onLoad;
            class 3DENRadio_playNewSong;
            class 3DENRadio_searchList;
            class 3DENRadio_timelineControl;
            class 3DENRadio_toggleRadio;
        };
        class Garrison
        {
            file = "x\enh\addons\main\functions\GUI\garrison";
            class garrison_onLoad;
            class garrison_draw;
            class garrison_fillBuildings;
            class garrison_onUnload;
            class garrison_updateValues;
        };
        class TextureFinder
        {
            file = "x\enh\addons\main\functions\GUI\TextureFinder";
            class textureFinder_fillList;
            class textureFinder_findTextures;
            class textureFinder_updatePreview;
        };
        class FunctionsViewer
        {
            file = "x\enh\addons\main\functions\GUI\functionsViewer";
            class functionsViewer_copy;
            class functionsViewer_fillCtrlTV;
            class functionsViewer_getFunctionsData;
            class functionsViewer_incrementKey;
            class functionsViewer_onLoad;
            class functionsViewer_onTreeSelChanged;
            class functionsViewer_recompileSelected;
            class functionsViewer_searchkey;
            class functionsViewer_setUpMenuStrip;
            class functionsViewer_togglePanel;
        };
        class AttributeSearch
        {
            file = "x\enh\addons\main\functions\GUI\attributeSearch";
            class attributeSearch_onLoad;
        };
        class BriefingEditor
        {
            file = "x\enh\addons\main\functions\GUI\briefingEditor";
            class briefingEditor;
        };
        class PlacementTools
        {
            file = "x\enh\addons\main\functions\GUI\placementTools";
            class placementTools;
        };
        class SAM
        {
            file = "x\enh\addons\main\functions\GUI\SAM";
            class SAM;
        };
        class NameObjects
        {
            file = "x\enh\addons\main\functions\GUI\nameObjects";
            class nameObjects_name;
            class nameObjects_onLoad;
        };
        class ModuleInformation
        {
            file = "x\enh\addons\main\functions\GUI\moduleInformation";
            class moduleInformation_onLoad;
        };
        class VariableViewer
        {
            file = "x\enh\addons\main\functions\GUI\variableViewer";
            class variableViewer_delete;
            class variableViewer_fillLNB;
            class variableViewer_getNamespace;
            class variableViewer_messageConfirm;
            class variableViewer_onFilterChanged;
            class variableViewer_onLNBSelChanged;
            class variableViewer_onLoad;
            class variableViewer_setOrCreate;
        };
        class ESE
        {
            file = "x\enh\addons\main\functions\GUI\ESE";
            class ESE_addItem;
            class ESE_applyAttribute;
            class ESE_changeFilter;
            class ESE_clearInventory;
            class ESE_close;
            class ESE_export;
            class ESE_fullArsenal;
            class ESE_getConfigValues;
            class ESE_handleTemplates;
            class ESE_importToFilter;
            class ESE_lbAdd;
            class ESE_lnbAdd;
            class ESE_loadAttributeValue;
            class ESE_onModFilterChanged;
            class ESE_open;
            class ESE_parseClipboardValues;
            class ESE_removeItem;
            class ESE_resetSearch;
            class ESE_resetStorage;
            class ESE_resetToAllItems;
            class ESE_search;
            class ESE_sort;
            class ESE_toggleVirtual;
        };
        class CfgSentencesBrowser
        {
            file = "x\enh\addons\main\functions\GUI\CFGS";
            class CFGS_changeFilter;
            class CFGS_changePage;
            class CFGS_getCfgSentences;
            class CFGS_getSentenceDataFromConfig;
            class CFGS_handleFavorites;
            class CFGS_onLoad;
            class CFGS_playOrCopy;
        };
        class SelectionFilter
        {
            file = "x\enh\addons\main\functions\GUI\selectionFilter";
            class selectionFilter_init;
        };
        class 3DENShortcuts
        {
            file = "x\enh\addons\main\functions\GUI\3DENShortcuts";
            class 3DENShortcuts_init;
            class 3DENShortcuts_fillList;
        };
        class RPTViewer
        {
            file = "x\enh\addons\main\functions\GUI\RPTViewer";
            class RPTViewer;
        };
        class ZeusAddons
        {
            file = "x\enh\addons\main\functions\GUI\ZeusAddons";
            class zeusAddons;
        };
        class MoveToLayer
        {
            file = "x\enh\addons\main\functions\GUI\moveTolayer";
            class moveToLayer_onLoad;
            class moveToLayer_move;
        };
        class Misc
        {
            file = "x\enh\addons\main\functions\Misc";
            class VHCTools;
            class alignEntities;
            class all3DENSelected;
            class centerMapOnSelection;
            class createBackupMissionSQM;
            class deleteCrew;
            class deleteEmptyLayers;
            class floatToTime;
            class getAllItems;
            class getConfigSourceAddon;
            class hasStorage;
            class loadoutTool;
            class measureDistance;
            class pylonTools;
            class removeGear;
            class setOrientation;
            class spaceEqually;
            class switchTime;
            class systemTimeFormatted;
            class toggleAttributes;
            class toggleGrass;
        };
        class Interface
        {
            file = "x\enh\addons\main\functions\interface";
            class 3DENMinimap;
            class assetBrowser_collapse;
            class entityList_addTooltips;
            class favoritesList;
            class locationList_enhanced;
        };
        class Log
        {
            file = "x\enh\addons\main\functions\log";
            class 3DENLog;
            class exportGUIDefines;
            class exportLoadout;
            class exportWithLB;
        };
        class Debug
        {
            file = "x\enh\addons\main\functions\debug";
            class productInfo;
        };
        class EventHandlers
        {
            file = "x\enh\addons\main\functions\eventHandlers";
            class EH_init;
            class EH_onMissionLoad;
            class EH_onMissionNew;
            class EH_onMissionPreview;
            class EH_onMissionPreviewEnd;
            class EH_onTerrainNew;
        };
        class Attributes
        {
            file = "x\enh\addons\main\functions\attributes";
            class advancedDamage_onAttributeLoad;
            class advancedDamage_onAttributeSave;
            class airdrop_onAttributeLoad;
            class airdrop_onAttributeSave;
            class ambientAnimations_initInEditor;
            class ambientAnimations_onAttributeLoad;
            class ambientAnimations_onAttributeSave;
            class ambientFlyby_onAttributeLoad;
            class ambientFlyby_onAttributeSave;
            class debugOptions_init;
            class dynamicSkill_onAttributeLoad;
            class dynamicSkill_onAttributeSave;
            class establishingShot_onAttributeLoad;
            class establishingShot_onAttributeSave;
            class groupMarker_onAttributeLoad;
            class groupMarker_onAttributeSave;
            class groupMarker_onLoad;
            class holdAction_onAttributeLoad;
            class holdAction_onAttributeSave;
            class inputList_onAttributeLoad;
            class inputList_onAttributeSave;
            class inputList_add;
            class inputList_remove;
            class introText_onAttributeLoad;
            class introText_onAttributeSave;
            class mapIndicators_onAttributeLoad;
            class mapIndicators_onAttributeSave;
            class missionEndingCasualties_initDebriefingCombo;
            class missionEndingCasualties_onAttributeLoad;
            class missionEndingCasualties_onAttributeSave;
            class slider_onAttributeLoad;
            class slider_onAttributeSave;
            class SPR_onAttributeLoad;
            class SPR_onAttributeSave;
        };
        // class Internal
        // {
        //     file = "x\enh\addons\main\functions\internal";
        //     class checkShortCutsDuplicates;
        //     class exportAttributesToGitHub;
        //     class exportContextMenuToGitHub;
        //     class exportMenuStripToGitHub;
        //     class testDisplays;
        // };
    };
};
