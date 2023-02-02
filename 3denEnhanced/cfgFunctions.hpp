class CfgFunctions
{
  class 3denEnhanced
  {
    tag = "ENH";
    class 3DENRadio
    {
      file = "3denEnhanced\functions\GUI\3DENRadio";
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
      file = "3denEnhanced\functions\GUI\garrison";
      class garrison_onLoad;
      class garrison_drawBuildingInfo;
      class garrison_fillBuildings;
      class garrison_onUnload;
      class garrison_updateValues;
    };
    class Extraction
    {
      file = "3denEnhanced\functions\GUI\extraction";
      class extraction_onCheckedChanged;
      class extraction_onLoad;
      class extraction_setup;
    };
    class CreateObject
    {
      file = "3denEnhanced\functions\GUI\createObject";
      class createObject_create;
      class createObject_changeFilter;
    };
    class TextureFinder
    {
      file = "3denEnhanced\functions\GUI\TextureFinder";
      class textureFinder_copyPath;
      class textureFinder_fillList;
      class textureFinder_findTextures;
      class textureFinder_progressText;
      class textureFinder_updatePreview;
    };
    class BatchReplace
    {
      file = "3denEnhanced\functions\GUI\batchReplace";
      class batchReplace;
      class batchReplace_onLoad;
      class batchReplace_createDisplay;
      class batchReplace_onTreeSelChanged;
      class batchReplace_initTreeView;
    };
    class FunctionsViewer
    {
      file = "3denEnhanced\functions\GUI\functionsViewer";
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
    class ActionCreator
    {
      file = "3denEnhanced\functions\GUI\actionCreator";
      class actionCreator;
    };
    class AttributeSearch
    {
      file = "3denEnhanced\functions\GUI\attributeSearch";
      class attributeSearch_onLoad;
    };
    class BriefingEditor
    {
      file = "3denEnhanced\functions\GUI\briefingEditor";
      class briefingEditor_addTAG;
      class briefingEditor_handleTemplates;
      class briefingEditor_export;
      class briefingEditor_onLBSelChanged;
      class briefingEditor_onLoad;
      class briefingEditor_onUnload;
      class briefingEditor_htmlHighlight;
    };
    class PlacementTools
    {
      file = "3denEnhanced\functions\GUI\placementTools";
      class placementTools_centralAngle;
      class placementTools_createDisplay;
      class placementTools_fillArea;
      class placementTools_grid;
      class placementTools_initialAngle;
      class placementTools_onLoad;
      class placementTools_onToolBoxSelChanged;
      class placementTools_onUnload;
      class placementTools_radius;
      class placementTools_spacing;
    };
    class SAM
    {
      file = "3denEnhanced\functions\GUI\SAM";
      class SAM_applyAttribute;
      class SAM_applyTemplate;
      class SAM_createTemplate;
      class SAM_deleteTemplate;
      class SAM_exportToClipboard;
      class SAM_getScenarioAttributes;
      class SAM_loadTemplate;
      class SAM_onLoad;
      class SAM_onUnload;
    };
    class NameObjects
    {
      file = "3denEnhanced\functions\GUI\nameObjects";
      class nameObjects_name;
      class nameObjects_onLoad;
    };
    class ModuleInformation
    {
      file = "3denEnhanced\functions\GUI\moduleInformation";
      class moduleInformation_onLoad;
    };
    class 3DENCam
    {
      file = "3denEnhanced\functions\GUI\3DENCam";
      class 3DENCam_deleteEntry;
      class 3DENCam_get3DENCameraParameters;
      class 3DENCam_onKillFocus;
      class 3DENCam_onSetFocus;
      class 3DENCam_saveList;
      class 3DENCam_set3DENCameraParameters;
      class 3DENCam_updateList;
    };
    class VariableViewer
    {
      file = "3denEnhanced\functions\GUI\variableViewer";
      class variableViewer_delete;
      class variableViewer_fillLNB;
      class variableViewer_getNamespace;
      class variableViewer_hideFunctions;
      class variableViewer_messageConfirm;
      class variableViewer_onFilterChanged;
      class variableViewer_onLNBSelChanged;
      class variableViewer_onLoad;
      class variableViewer_onSearch;
      class variableViewer_setOrCreate;
    };
    class VIM
    {
      file = "3denEnhanced\functions\GUI\VIM";
      class VIM_addItem;
      class VIM_applyAttribute;
      class VIM_changeFilter;
      class VIM_clearInventory;
      class VIM_close;
      class VIM_export;
      class VIM_fullArsenal;
      class VIM_handleTemplates;
      class VIM_lbAdd;
      class VIM_lnbAdd;
      class VIM_loadAttributeValue;
      class VIM_onModFilterChanged;
      class VIM_open;
      class VIM_removeItem;
      class VIM_resetSearch;
      class VIM_resetStorage;
      class VIM_search;
      class VIM_sort;
      class VIM_toggleVirtual;
    };
    class CfgSentencesBrowser
    {
      file = "3denEnhanced\functions\GUI\CFGS";
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
      file = "3denEnhanced\functions\GUI\selectionFilter";
      class selectionFilter_init;
    };
    class 3DENShortcuts
    {
      file = "3denEnhanced\functions\GUI\3DENShortcuts";
      class 3DENShortcuts_init;
      class 3DENShortcuts_fillList;
    };
    class RPTViewer
    {
      file = "3denEnhanced\functions\GUI\RPTViewer";
      class RPTViewer;
    };
    class ZeusAddons
    {
      file = "3denEnhanced\functions\GUI\ZeusAddons";
      class zeusAddons;
    };
    class MoveToLayer
    {
      file = "3denEnhanced\functions\GUI\moveTolayer";
      class moveToLayer_onLoad;
      class moveToLayer_move;
    };
    class Misc
    {
      file = "3denEnhanced\functions\Misc";
      class alignEntities;
      class all3DENSelected;
      class deleteCrew;
      class deleteEmptyLayers;
      #ifndef ENH_HIDE_DYNAMICVIEWDISTANCE
      class dynamicViewDistance;
      #endif
      class exportMissionParams;
      class floatToTime;
      class generateSteamMissionDescription;
      class getAllItems;
      class getConfigSourceAddon;
      class hasStorage;
      class loadoutTool;
      class measureDistance;
      class preloadAmmoAttribute;
      class pylonTools;
      class removeGear;
      class setOrientation;
      class spaceEqually;
      class switchTime;
      class systemTimeFormatted;
      class toggleAttributes;
      class toggleDrawBuildingPositions;
      class toggleDrawDLCIcons;
      class toggleDrawHitpoints;
      class toggleGrass;
      class toggleMarkerAlpha;
      class twoDigitsStr;
      class VHCTools;
      class centerMapOnSelection;
    };
    #ifndef ENH_HIDE_INTERFACE
    class Interface
    {
      file = "3denEnhanced\functions\interface";
      class assetBrowser_collapse;
      class assetBrowser_addTooltips;
      class favoritesList;
      class locationList;
      class menuStrip_removeItems;
      class statusbar_entityCounter;
      class statusbar_sessionTimer;
    };
    #endif
    class Log
    {
      file = "3denEnhanced\functions\log";
      class 3DENLog;
      class exportGUIDefines;
      class exportLoadout;
      class exportWithLB;
    };
    class Debug
    {
      file = "3denEnhanced\functions\debug";
      class productInfo;
      class toggleMapIDs;
    };
    class EventHandlers
    {
      file = "3denEnhanced\functions\eventHandlers";
      class EH_onMissionLoad;
      class EH_onMissionNew;
      class EH_onMissionPreview;
      class EH_onMissionPreviewEnd;
      class EH_onSelectionChange;
      class EH_onTerrainNew;
    };
    class Attributes
    {
      file = "3denEnhanced\functions\attributes";
      #ifndef ENH_HIDE_ADVANCEDDAMAGE
      class advancedDamage_onAttributeLoad;
      class advancedDamage_onAttributeSave;
      #endif
      #ifndef ENH_HIDE_AIRDROP
      class airdrop_onAttributeLoad;
      class airdrop_onAttributeSave;
      #endif
      #ifndef ENH_HIDE_AMBIENTANIMATIONS
      class ambientAnimations_initInEditor;
      class ambientAnimations_onAttributeLoad;
      class ambientAnimations_onAttributeSave;
      #endif
      #ifndef ENH_HIDE_AMBIENTFLYBY
      class ambientFlyby_onAttributeLoad;
      class ambientFlyby_onAttributeSave;
      #endif
      #ifndef ENH_HIDE_DEBUGOPTIONS
      class debugOptions_activeScripts;
      class debugOptions_init;
      #endif
      #ifndef ENH_HIDE_DYNAMICSKILL
      class dynamicSkill_onAttributeLoad;
      class dynamicSkill_onAttributeSave;
      #endif
      #ifndef ENH_HIDE_ESTABLISHINGSHOT
      class establishingShot_onAttributeLoad;
      class establishingShot_onAttributeSave;
      #endif
      #ifndef ENH_HIDE_GROUPMARKER
      class groupMarker_onAttributeLoad;
      class groupMarker_onAttributeSave;
      class groupMarker_onLoad;
      #endif
      #ifndef ENH_HIDE_HOLDACTION
      class holdAction_onAttributeLoad;
      class holdAction_onAttributeSave;
      #endif
      #ifndef ENH_HIDE_INTROTEXT
      class introText_onAttributeLoad;
      class introText_onAttributeSave;
      #endif
      #ifndef ENH_HIDE_MAPINDICATORS
      class mapIndicators_onAttributeLoad;
      class mapIndicators_onAttributeSave;
      #endif
      #ifndef ENH_HIDE_INTERFACE
      class menuStripBlacklist_onAttributeLoad;
      #endif
      #ifndef ENH_HIDE_MISSIONENDING
      class missionEndingCasualties_initDebriefingCombo;
      class missionEndingCasualties_onAttributeLoad;
      class missionEndingCasualties_onAttributeSave;
      #endif
      #ifndef ENH_HIDE_SPR
      class SPR_onAttributeLoad;
      class SPR_onAttributeSave;
      #endif
      class slider_onAttributeLoad;
      class slider_onAttributeSave;
    };
    #ifdef __A3_DEBUG__
    class ENH_Internal
    {
      file = "3denEnhanced\functions\internal";
      class checkShortCutsDuplicates;
      class exportAttributesToGitHub;
      class exportMenuStripToGitHub;
    };
    #endif
  };
};