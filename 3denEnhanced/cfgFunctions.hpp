class CfgFunctions
{
  class 3denEnhanced
  {
    tag = "ENH";
    #ifdef DEBUG
    class ENH_Internal
    {
      file = "3denEnhanced\functions\internal";
      class checkShortCutsDuplicates;
      class exportAttributesToGitHub;
      class exportContextMenuToGitHub;
      class exportFunctionsToGitHub;
      class exportMenuStripToGitHub;
    };
    #endif
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
      class garrison_garrison;
      class garrison_onLoad;
    };
    class Extraction
    {
      file = "3denEnhanced\functions\GUI\extraction";
      class extraction_onCheckedChanged;
      class extraction_onLoad;
      class extraction_setup;
    };
    class TextureFinder
    {
      file = "3denEnhanced\functions\GUI\TextureFinder";
      class textureFinder_exportTexturePath;
      class textureFinder_fillList;
      class textureFinder_findTextures;
      class textureFinder_progressText;
    };
    class BatchReplace
    {
      file = "3denEnhanced\functions\GUI\batchReplace";
      class batchReplace;
      class batchReplace_createDisplay;
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
      class functionsViewer_togglePanel;
    };
    class ActionCreator
    {
      file = "3denEnhanced\functions\GUI\actionCreator";
      class actionCreator_export;
      class actionCreator_onLoad;
    };
    class BriefingEditor
    {
      file = "3denEnhanced\functions\GUI\briefingEditor";
      class briefingEditor_addTAG;
      class briefingEditor_createTemplate;
      class briefingEditor_export;
      class briefingEditor_getTemplate;
      class briefingEditor_onLBSelChanged;
      class briefingEditor_onLoad;
      class briefingEditor_onUnload;
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
    class ScenarioAttributesManager
    {
      file = "3denEnhanced\functions\GUI\scenarioAttributesManager";
      class scenarioAttributesManager_applyAttribute;
      class scenarioAttributesManager_applyTemplate;
      class scenarioAttributesManager_createTemplate;
      class scenarioAttributesManager_deleteTemplate;
      class scenarioAttributesManager_exportToClipboard;
      class scenarioAttributesManager_getScenarioAttributes;
      class scenarioAttributesManager_loadTemplate;
      class scenarioAttributesManager_onLoad;
      class scenarioAttributesManager_onUnload;
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
    class IM
    {
      file = "3denEnhanced\functions\GUI\IM";
      class IM_addItem;
      class IM_applyAttribute;
      class IM_applyTemplate;
      class IM_clearInventory;
      class IM_createTemplate;
      class IM_deleteTemplate;
      class IM_filterList;
      class IM_lbAdd;
      class IM_lnbAdd;
      class IM_loadAttributeValue;
      class IM_onModFilterChanged;
      class IM_open;
      class IM_removeItem;
      class IM_resetSearch;
      class IM_resetStorage;
      class IM_search;
      class IM_showTemplates;
      class IM_toggleVirtual;
      class IM_updateTemplateList;
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
    class Misc
    {
      file = "3denEnhanced\functions\Misc";
      class 3DENCollapseAssetBrowser;
      class 3denNotificationNoSound;
      class all3DENSelected;
      class deleteCrew;
      class deleteEmptyLayers;
      class dynamicViewDistance;
      class floatToTime;
      class generateSteamMissionDescription;
      class getAllItems;
      class hasStorage;
      class initAmbientAnimationsInEditor;
      class loadoutTool;
      class locationList;
      class measureDistance;
      class menuStrip_removeItems;
      class removeGear;
      class sessionTimer;
      class setOrientation;
      class statusbar_entityCounter;
      class switchTime;
      class toggleAIFeatures;
      class toggleAttribute;
      class toggleDrawBuildingPositions;
      class toggleDrawDLCIcons;
      class toggleGrass;
      class twoDigitsStr;
    };
    class Log
    {
      file = "3denEnhanced\functions\log";
      class exportGUIDefines;
      class exportLoadout;
      class exportWithLB;
      class log;
    };
    class Debug
    {
      file = "3denEnhanced\functions\debug";
      class activeScripts;
      class debugOptions;
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
    class AttributeControls
    {
      file = "3denEnhanced\functions\attributeControls";
      class SPR_onAttributeLoad;
      class SPR_onAttributeSave;
      class airdrop_onAttributeLoad;
      class airdrop_onAttributeSave;
      class ambientAnimations_onAttributeLoad;
      class ambientAnimations_onAttributeSave;
      class ambientFlyby_onAttributeLoad;
      class ambientFlyby_onAttributeSave;
      class establishingShot_onAttributeLoad;
      class establishingShot_onAttributeSave;
      class groupMarker_onAttributeLoad;
      class groupMarker_onAttributeSave;
      class holdAction_onAttributeLoad;
      class holdAction_onAttributeSave;
      class initDebriefingCombo;
      class introText_onAttributeLoad;
      class introText_onAttributeSave;
      class mapIndicators_onAttributeLoad;
      class mapIndicators_onAttributeSave;
      class menuStripBlacklist_onAttributeLoad;
      class missionEndingCasualties_onAttributeLoad;
      class missionEndingCasualties_onAttributeSave;
      class timeMultiplier_onAttributeLoad;
      class timeMultiplier_onAttributeSave;
    };
  };
};