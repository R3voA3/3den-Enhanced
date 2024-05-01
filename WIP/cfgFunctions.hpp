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
      class garrison_draw;
      class garrison_fillBuildings;
      class garrison_onUnload;
      class garrison_updateValues;
    };
    class TextureFinder
    {
      file = "3denEnhanced\functions\GUI\TextureFinder";
      class textureFinder_fillList;
      class textureFinder_findTextures;
      class textureFinder_updatePreview;
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
    class AttributeSearch
    {
      file = "3denEnhanced\functions\GUI\attributeSearch";
      class attributeSearch_onLoad;
    };
    class BriefingEditor
    {
      file = "3denEnhanced\functions\GUI\briefingEditor";
      class briefingEditor;
    };
    class PlacementTools
    {
      file = "3denEnhanced\functions\GUI\placementTools";
      class placementTools;
    };
    class SAM
    {
      file = "3denEnhanced\functions\GUI\SAM";
      class SAM;
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
    class VariableViewer
    {
      file = "3denEnhanced\functions\GUI\variableViewer";
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
      file = "3denEnhanced\functions\GUI\ESE";
      class ESE_addItem;
      class ESE_applyAttribute;
      class ESE_changeFilter;
      class ESE_clearInventory;
      class ESE_close;
      class ESE_export;
      class ESE_fullArsenal;
      class ESE_handleTemplates;
      class ESE_lbAdd;
      class ESE_lnbAdd;
      class ESE_loadAttributeValue;
      class ESE_onModFilterChanged;
      class ESE_open;
      class ESE_removeItem;
      class ESE_resetSearch;
      class ESE_resetStorage;
      class ESE_search;
      class ESE_sort;
      class ESE_toggleVirtual;
    };
    class VAM
    {
      file = "3denEnhanced\functions\GUI\VAM";
      class VAM_arsenalPrototype;
      class VAM_applyAttribute;
      class VAM_selectCompatibleItems;
      class VAM_switchNodeState;
      class VAM_tvItemInit;
      class VAM_exportToSQF;
      class VAM_handleItemStats;
      class VAM_loadObject;
      class VAM_loadSelectHashMap;
      class VAM_openCloseACCTV;
      class VAM_accTVItemInsert;
      class VAM_openPresetsMenu;
    }
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
      class VHCTools;
      class alignEntities;
      class all3DENSelected;
      class centerMapOnSelection;
      class compatibleItems;
      class createBackupMissionSQM;
      class deleteCrew;
      class deleteEmptyLayers;
      class dynamicViewDistance;
      class floatToTime;
      class getAllItems;
      class getConfigSourceAddon;
      class hasStorage;
      class highlightAreaMarkers;
      class loadoutTool;
      class measureDistance;
      class pylonTools;
      class removeGear;
      class setOrientation;
      class spaceEqually;
      class statBarStatement_accuracy;
      class statBarStatement_default;
      class statBarStatement_impact;
      class statBarStatement_rateOfFIre;
      class statTextStatement_accuracy;
      class statTextStatement_explosionTime;
      class statTextStatement_mass;
      class statTextStatement_rateOfFire;
      class statTextStatement_scopeMag;
      class statTextStatement_scopeVisionMode;
      class switchTime;
      class systemTimeFormatted;
      class toggleAttributes;
      class toggleDrawBuildingPositions;
      class toggleDrawDLCIcons;
      class toggleDrawHitpoints;
      class toggleGrass;
      class toggleMarkerAlpha;
    };
    class Interface
    {
      file = "3denEnhanced\functions\interface";
      class assetBrowser_collapse;
      class entityList_addTooltips;
      class favoritesList;
      class locationList_enhanced;
      class menuStrip_removeItems;
      class statusbar_entityCounter;
      class statusbar_sessionTimer;
      class 3DENMinimap;
    };
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
      class SPR_onAttributeLoad;
      class SPR_onAttributeSave;
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
      class introText_onAttributeLoad;
      class introText_onAttributeSave;
      class mapIndicators_onAttributeLoad;
      class mapIndicators_onAttributeSave;
      class menuStripBlacklist_onAttributeLoad;
      class missionEndingCasualties_initDebriefingCombo;
      class missionEndingCasualties_onAttributeLoad;
      class missionEndingCasualties_onAttributeSave;
      class slider_onAttributeLoad;
      class slider_onAttributeSave;
    };
    class Internal
    {
      file = "3denEnhanced\functions\internal";
      class checkShortCutsDuplicates;
      class exportAttributesToGitHub;
      class exportMenuStripToGitHub;
      class testDisplays;
    };
  };
};