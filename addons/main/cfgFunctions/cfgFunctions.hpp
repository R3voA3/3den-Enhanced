class CfgFunctions
{
    class 3denEnhanced
    {
        tag = "ENH";
        class 3DENCommandPalette
        {
            file = "\x\enh\addons\main\cfgFunctions\3DENCommandPalette";
            class 3DENCommandPalette_addCommand {};
            class 3DENCommandPalette_collectCommands {};
            class 3DENCommandPalette_execCommand {};
            class 3DENCommandPalette_init {};
            class 3DENCommandPalette_readJSONFile {};
            class 3DENCommandPalette_search {};
        };
        class 3DENEventHandlers
        {
            file = "\x\enh\addons\main\cfgFunctions\3DENEventHandlers";
            class EH_init {};
            class EH_onEditableEntityAdded {};
            class EH_onMissionLoad {};
            class EH_onMissionNew {};
            class EH_onMissionPreview {};
            class EH_onMissionPreviewEnd {};
            class EH_onTerrainNew {};
        };
        class 3DENInterface
        {
            file = "\x\enh\addons\main\cfgFunctions\3DENInterface";
            class 3DENMinimap {};
            class 3DENShowCustomMarkerShape {};
            class adjustTitleTextWidth {};
            class assetBrowser_collapse {};
            class assetBrowser_modFilter {};
            class entityList_addTooltips {};
            class favoritesList {};
            class locationList_enhanced {};
        };
        class 3DENLayers
        {
            file = "\x\enh\addons\main\cfgFunctions\3DENLayers";
            class deleteEmptyLayers {};
            class getDefaultLayer {};
            class moveIntoDefaultLayer {};
            class toggleDefaultLayer {};
        };
        class 3DENRadio
        {
            file = "\x\enh\addons\main\cfgFunctions\3DENRadio";
            class 3DENRadio_exportClassname {};
            class 3DENRadio_handlePlaylist {};
            class 3DENRadio_onLoad {};
            class 3DENRadio_playNewSong {};
            class 3DENRadio_searchList {};
            class 3DENRadio_timelineControl {};
            class 3DENRadio_toggleRadio {};
        };
        class 3DENAttributes
        {
            file = "\x\enh\addons\main\cfgFunctions\3DENAttributes";
            class advancedDamage_onAttributeLoad {};
            class advancedDamage_onAttributeSave {};
            class airdrop_onAttributeLoad {};
            class airdrop_onAttributeSave {};
            class ambientAnimations_initInEditor {};
            class ambientAnimations_onAttributeLoad {};
            class ambientAnimations_onAttributeSave {};
            class ambientFlyby_onAttributeLoad {};
            class ambientFlyby_onAttributeSave {};
            class cfgMusic_onAttributeLoad {};
            class cfgMusic_onAttributeSave {};
            class debugOptions_init {};
            class dynamicSkill_onAttributeLoad {};
            class dynamicSkill_onAttributeSave {};
            class dynamicSkill_toggleControlsState {};
            class establishingShot_onAttributeLoad {};
            class establishingShot_onAttributeSave {};
            class groupMarker_onAttributeLoad {};
            class groupMarker_onAttributeSave {};
            class groupMarker_onLoad {};
            class holdAction_onAttributeLoad {};
            class holdAction_onAttributeSave {};
            class inputList_add {};
            class inputList_onAttributeLoad {};
            class inputList_onAttributeSave {};
            class inputList_remove {};
            class introText_onAttributeLoad {};
            class introText_onAttributeSave {};
            class mapIndicators_onAttributeLoad {};
            class mapIndicators_onAttributeSave {};
            class markerColor_fillLBHistory {};
            class markerColor_onAttributeLoad {};
            class markerColor_editChanged {};
            class markerShape_onAttributeLoad {};
            class markerShape_onAttributeSave {};
            class missionEndingCasualties_initDebriefingCombo {};
            class missionEndingCasualties_onAttributeLoad {};
            class missionEndingCasualties_onAttributeSave {};
            class slider_onAttributeLoad {};
            class slider_onAttributeSave {};
            class SPR_onAttributeLoad {};
            class SPR_onAttributeSave {};
        };
        class 3DENAttributeSearch
        {
            file = "\x\enh\addons\main\cfgFunctions\3DENAttributeSearch";
            class attributeSearch_onLoad {};
        };
        class 3DENBriefingEditor
        {
            file = "\x\enh\addons\main\cfgFunctions\3DENBriefingEditor";
            class briefingEditor {};
        };
        class 3DENCFGS
        {
            file = "\x\enh\addons\main\cfgFunctions\3DENCFGS";
            class CFGS_changeFilter {};
            class CFGS_changePage {};
            class CFGS_getCfgSentences {};
            class CFGS_getSentenceDataFromConfig {};
            class CFGS_handleFavorites {};
            class CFGS_onLoad {};
            class CFGS_playOrCopy {};
        };
        class Common
        {
            file = "\x\enh\addons\main\cfgFunctions\common";
            class all3DENSelected {};
            class array3FromClipboard {};
            class createHashValue {};
            class floatToTime {};
            class formatInteger {};
            class getAllItems {};
            class getConfigSourceAddon {};
            class hasStorage {};
            class initSearchControls {};
            class isObjSelectionIdentical {};
            class parseShortcut {};
            class systemTimeFormatted {};
        };
        class Debug
        {
            file = "\x\enh\addons\main\cfgFunctions\debug";
            class productInfo {};
        };
        class 3DENEquipmentStorageEditor
        {
            file = "\x\enh\addons\main\cfgFunctions\3DENEquipmentStorageEditor";
            class ESE_addItem {};
            class ESE_applyAttribute {};
            class ESE_changeFilter {};
            class ESE_clearInventory {};
            class ESE_close {};
            class ESE_export {};
            class ESE_fullArsenal {};
            class ESE_getConfigValues {};
            class ESE_handleTemplates {};
            class ESE_importToFilter {};
            class ESE_lbAdd {};
            class ESE_lnbAdd {};
            class ESE_loadAttributeValue {};
            class ESE_onModFilterChanged {};
            class ESE_open {};
            class ESE_parseClipboardValues {};
            class ESE_removeItem {};
            class ESE_resetSearch {};
            class ESE_resetStorage {};
            class ESE_search {};
            class ESE_sort {};
            class ESE_toggleVirtual {};
        };
        class FunctionsViewer
        {
            file = "\x\enh\addons\main\cfgFunctions\functionsViewer";
            class functionsViewer_copy {};
            class functionsViewer_fillCtrlTV {};
            class functionsViewer_getFunctionsData {};
            class functionsViewer_incrementKey {};
            class functionsViewer_onLoad {};
            class functionsViewer_onTreeSelChanged {};
            class functionsViewer_recompileSelected {};
            class functionsViewer_searchkey {};
            class functionsViewer_setUpMenuStrip {};
            class functionsViewer_togglePanel {};
        };
        class 3DENGarrison2
        {
            file = "\x\enh\addons\main\cfgFunctions\3DENGarrison2";
            class garrison2_draw3D {};
            class garrison2_exit {};
            class garrison2_fillBuildingPositions {};
            class garrison2_main {};
            class garrison2_onEntityDragged {};
            class garrison2_onMouseButtonUp {};
            class garrison2_positionInBoundingBox {};
            class garrison2_isBuildingPositionEmpty {};
        };
        #ifdef ISDEV
        class Internal
        {
            file = "\x\enh\addons\main\cfgFunctions\internal";
            class checkShortCutsDuplicates {};
            class exportAttributesToGitHub {};
            class exportContextMenuToGitHub {};
            class exportMenuStripToGitHub {};
            class iterTree {};
            class log {};
            class logShow {};
            class recompileFunctions {};
            class testDisplays {};
        };
        #endif
        class 3DENLog
        {
            file = "\x\enh\addons\main\cfgFunctions\3DENLog";
            class logEntityInfo {};
            class exportGUIDefines {};
            class exportLoadout {};
            class exportWithLB {};
        };
        class Misc
        {
            file = "\x\enh\addons\main\cfgFunctions\misc";
            class centerMapOnSelection {};
            class createBackupMissionSQM {};
            class deleteCrew {};
            class iconPicker {};
            class measureDistance {};
            class switchTime {};
            class toggleAttributes {};
            class toggleGrass {};
        };
        class 3DENModuleInformation
        {
            file = "\x\enh\addons\main\cfgFunctions\3DENModuleInformation";
            class MI_createSyncPreview {};
            class MI_createSyncPreviewTree {};
            class MI_formatInformationData {};
            class MI_getInformationData {};
            class MI_getModuleIcon {};
            class MI_onLoad {};
            class MI_resizeInformationControl {};
        };
        class 3DENMoveTolayer
        {
            file = "\x\enh\addons\main\cfgFunctions\3DENMoveTolayer";
            class moveToLayer_onLoad {};
            class moveToLayer_move {};
        };
        class 3DENNameObjects
        {
            file = "\x\enh\addons\main\cfgFunctions\3DENNameObjects";
            class nameObjects {};
        };
        class 3DENPlacementTools
        {
            file = "\x\enh\addons\main\cfgFunctions\3DENPlacementTools";
            class alignEntities {};
            class placementToolsUI {};
            class setOrientation {};
            class spaceEqually {};
        };
        class 3DENRPTViewer
        {
            file = "\x\enh\addons\main\cfgFunctions\3DENRPTViewer";
            class RPTViewer {};
        };
        class 3DENSAM
        {
            file = "\x\enh\addons\main\cfgFunctions\3DENSAM";
            class SAM {};
        };
        class 3DENSelectionFilter
        {
            file = "\x\enh\addons\main\cfgFunctions\3DENSelectionFilter";
            class selectionFilter_init {};
        };
        class 3DENTextureFinder
        {
            file = "\x\enh\addons\main\cfgFunctions\3DENTextureFinder";
            class textureFinder_fillList {};
            class textureFinder_findTextures {};
            class textureFinder_updatePreview {};
        };
        class VariableViewer
        {
            file = "\x\enh\addons\main\cfgFunctions\variableViewer";
            class variableViewer_delete {};
            class variableViewer_fillLNB {};
            class variableViewer_getNamespace {};
            class variableViewer_messageConfirm {};
            class variableViewer_onFilterChanged {};
            class variableViewer_onLNBSelChanged {};
            class variableViewer_onLoad {};
            class variableViewer_setOrCreate {};
        };
        class 3DENLoadoutTools
        {
            file = "\x\enh\addons\main\cfgFunctions\3DENLoadoutTools";
            class loadoutTool {};
            class removeGear {};
            class pylonTools {};
            class VHCTools {};
        };
        class 3DENZeusAddons
        {
            file = "\x\enh\addons\main\cfgFunctions\3DENZeusAddons";
            class zeusAddons {};
        };
    };
};
