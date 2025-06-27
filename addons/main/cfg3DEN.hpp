class Cfg3DEN
{
    class Notifications
    {
        class ENH_DataCopied
        {
            isWarning = 0;
            text = "$STR_A3_RSCDISPLAYARSENAL_MESSAGE_CLIPBOARD";
        };
        class ENH_ActionPerformed
        {
            isWarning = 0;
            text = "$STR_ENH_MAIN_NOTIFICATIONS_ACTIONPERFORMED";
        };
        class ENH_NoEntitiesSelected
        {
            isWarning = 1;
            text = "$STR_ENH_MAIN_NOTIFICATIONS_NOENTITIESSELECTED";
        };
        class ENH_NoEntitiesWithInventorySelected
        {
            isWarning = 1;
            text = "$STR_ENH_MAIN_NOTIFICATIONS_NOENTITIESWITHINVENTORYSELECTED";
        };
        class ENH_GetPythiaMod_Warning
        {
            isWarning = 1;
            text = "$STR_ENH_MAIN_NOTIFICATIONS_GETPYTHIA";
        };
        class ENH_PythiaMissingForBackup
        {
            isWarning = 1;
            text = "$STR_ENH_MAIN_NOTIFICATIONS_BACKUP_FAILED";
        };
        class ENH_SelectSecondPoint
        {
            isWarning = 0;
            text = "$STR_ENH_MAIN_MEASUREDISTANCE_SELECT2NDPOINT";
        };
        class ENH_NotEnoughBuildingPositions
        {
            isWarning = 1;
            text = "$STR_ENH_MAIN_GARRISON_NOTIFICATION";
        };
        class ENH_AlignEntities_WrongIndexValue
        {
            isWarning = 1;
            text = "$STR_ENH_MAIN_NOTIFICATIONS_ALIGN_ENTITIES_WRONG_INDEX";
        };
        class ENH_Garrison2_Disabled
        {
            isWarning = 0;
            text = "$STR_ENH_MAIN_NOTIFICATIONS_GARRISON2_DISABLED";
        };
        class ENH_Garrison2_Enabled
        {
            isWarning = 0;
            text = "$STR_ENH_MAIN_NOTIFICATIONS_GARRISON2_ENABLED";
        };
        class ENH_Garrison2_2D_Not_Supported
        {
            isWarning = 1;
            text = "$STR_ENH_MAIN_NOTIFICATIONS_GARRISON2_2D_NOT_SUPPORTED";
        };
        class ENH_Garrison2_All_Positions_Taken
        {
            isWarning = 1;
            text = "$STR_ENH_MAIN_NOTIFICATIONS_GARRISON2_ALL_POSITIONS_TAKEN";
        };
    };
    class EventHandlers
    {
        class ENH
        {
            init = "call ENH_fnc_EH_init";
            onTerrainNew = "call ENH_fnc_EH_onTerrainNew";
            onMissionPreviewEnd = "call ENH_fnc_EH_onMissionPreviewEnd";
            onMissionLoad = "call ENH_fnc_EH_onMissionLoad";
            onMissionNew = "call ENH_fnc_EH_onMissionNew";
            onMissionPreview = "call ENH_fnc_EH_onMissionPreview";
            onMissionSave = "call ENH_fnc_createBackupMissionSQM";
            onMissionAutoSave = "call ENH_fnc_createBackupMissionSQM";
        };
    };
    class Attributes
    {
        #include "\x\enh\addons\main\controls\base.hpp"
        #include "\x\enh\addons\main\controls\advancedDamage.hpp"
        #include "\x\enh\addons\main\controls\airdrop.hpp"
        #include "\x\enh\addons\main\controls\ambientAnimations.hpp"
        #include "\x\enh\addons\main\controls\ambientFlyby.hpp"
        #include "\x\enh\addons\main\controls\cfgMusic.hpp"
        #include "\x\enh\addons\main\controls\dynamicSkill.hpp"
        #include "\x\enh\addons\main\controls\establishingShot.hpp"
        #include "\x\enh\addons\main\controls\groupMarker.hpp"
        #include "\x\enh\addons\main\controls\holdAction.hpp"
        #include "\x\enh\addons\main\controls\inputList.hpp"
        #include "\x\enh\addons\main\controls\introText.hpp"
        #include "\x\enh\addons\main\controls\largerEditMulti.hpp"
        #include "\x\enh\addons\main\controls\mapIndicators.hpp"
        #include "\x\enh\addons\main\controls\markerColor.hpp"
        #include "\x\enh\addons\main\controls\markerShape.hpp"
        #include "\x\enh\addons\main\controls\missionEndingCasualties.hpp"
        #include "\x\enh\addons\main\controls\sliderMulti120.hpp"
        #include "\x\enh\addons\main\controls\sliderMultiZero.hpp"
        #include "\x\enh\addons\main\controls\SPR.hpp"
        #include "\x\enh\addons\main\controls\subCategoryNoHeader_Fixed.hpp"
    };
    class Mission
    {
        class Preferences
        {
            class AttributeCategories
            {
                class Camera
                {
                    class Attributes
                    {
                        #include "\x\enh\addons\main\attributesEditor\dynamicViewDistance.hpp"
                    };
                };
                class Saving
                {
                    class Attributes
                    {
                        #include "\x\enh\addons\main\attributesEditor\backupMissionSQM.hpp"
                    };
                };
                class Misc
                {
                    class Attributes
                    {
                        #include "\x\enh\addons\main\attributesEditor\holdActionIcons.hpp"
                    };
                };
                #include "\x\enh\addons\main\attributesEditor\interface.hpp"
                #include "\x\enh\addons\main\attributesEditor\garrison2.hpp"
                #include "\x\enh\addons\main\attributesEditor\debugOptions.hpp"
            };
        };
        class Intel
        {
            class AttributeCategories
            {
                #include "\x\enh\addons\main\attributesMission\timeMultiplier.hpp"
                #include "\x\enh\addons\main\attributesMission\visualSettings.hpp"
            };
        };
        class Scenario
        {
            class AttributeCategories
            {
                #include "\x\enh\addons\main\attributesMission\airdrop.hpp"
                #include "\x\enh\addons\main\attributesMission\ambientFlyby.hpp"
                #include "\x\enh\addons\main\attributesMission\briefings.hpp"
                #include "\x\enh\addons\main\attributesMission\establishingShot.hpp"
                #include "\x\enh\addons\main\attributesMission\introText.hpp"
                #include "\x\enh\addons\main\attributesMission\missionEndingCasualties.hpp"
                #include "\x\enh\addons\main\attributesMission\volume.hpp"
                #include "\x\enh\addons\main\attributesMission\SPR.hpp"
                #include "\x\enh\addons\main\attributesMission\missionEventHandlersGlobal.hpp"
                #include "\x\enh\addons\main\attributesMission\missionEventHandlersServer.hpp"
                #include "\x\enh\addons\main\attributesMission\musicEventHandlers.hpp"
                class Misc
                {
                    class Attributes
                    {
                        #include "\x\enh\addons\main\attributesMission\backupMissionSQMDisable.hpp"
                        #include "\x\enh\addons\main\attributesMission\addObjectsToZeus.hpp"
                        #include "\x\enh\addons\main\attributesMission\mapIndicators.hpp"
                    };
                };
            };
        };
        class Multiplayer
        {
            class AttributeCategories
            {
                #include "\x\enh\addons\main\attributesMission\dynamicGroups.hpp"
                #include "\x\enh\addons\main\attributesMission\dynamicSkill.hpp"
                class Respawn
                {
                    class Attributes
                    {
                        #include "\x\enh\addons\main\attributesMission\respawnTickets.hpp"
                        #include "\x\enh\addons\main\attributesMission\saveLoadout.hpp"
                    };
                };
            };
        };
    };
    class Group
    {
        class AttributeCategories
        {
            #include "\x\enh\addons\main\attributesGroup\groupMarker.hpp"
            #include "\x\enh\addons\main\attributesGroup\eventHandlers.hpp"
            class State
            {
                class Attributes
                {
                    #include "\x\enh\addons\main\attributesGroup\taskPatrol.hpp"
                };
            };
        };
    };
    class Object
    {
        class AttributeCategories
        {
            #include "\x\enh\addons\main\attributesObject\advancedDamage.hpp"
            #include "\x\enh\addons\main\attributesObject\ambientAnimations.hpp"
            #include "\x\enh\addons\main\attributesObject\AI.hpp"
            #include "\x\enh\addons\main\attributesObject\unitTraits.hpp"
            #include "\x\enh\addons\main\attributesObject\holdAction.hpp"
            #include "\x\enh\addons\main\attributesObject\eventHandlers.hpp"
            class StateSpecial
            {
                class Attributes
                {
                    #include "\x\enh\addons\main\attributesObject\setCaptive.hpp"
                    #include "\x\enh\addons\main\attributesObject\allowSprint.hpp"
                    #include "\x\enh\addons\main\attributesObject\forceWalk.hpp"
                    #include "\x\enh\addons\main\attributesObject\makeHostage.hpp"
                    #include "\x\enh\addons\main\attributesObject\parachute.hpp"
                    #include "\x\enh\addons\main\attributesObject\enableHeadlights.hpp"
                    #include "\x\enh\addons\main\attributesObject\allowCrewInImmobile.hpp"
                    #include "\x\enh\addons\main\attributesObject\engineOn.hpp"
                    #include "\x\enh\addons\main\attributesObject\disableNVGE.hpp"
                    #include "\x\enh\addons\main\attributesObject\disableTIE.hpp"
                    #include "\x\enh\addons\main\attributesObject\doStop.hpp"
                    #include "\x\enh\addons\main\attributesObject\removeFromRemainsCollector.hpp"
                    #include "\x\enh\addons\main\attributesObject\SPRTickets.hpp"
                };
            };
            class Transformation
            {
                class Attributes
                {
                    #include "\x\enh\addons\main\attributesObject\objectScale.hpp"
                };
            };
            class Inventory
            {
                class Attributes
                {
                    #include "\x\enh\addons\main\attributesObject\addGunLight.hpp"
                    #include "\x\enh\addons\main\attributesObject\arsenal.hpp"
                };
            };
            class State
            {
                class Attributes
                {
                    #include "\x\enh\addons\main\attributesObject\featureType.hpp"
                    #include "\x\enh\addons\main\attributesObject\forceFlag.hpp"
                    #include "\x\enh\addons\main\attributesObject\setMass.hpp"
                    #include "\x\enh\addons\main\attributesObject\waterLeakiness.hpp"
                    #include "\x\enh\addons\main\attributesObject\limitSpeed.hpp"
                    #include "\x\enh\addons\main\attributesObject\fuelConsumptionCoef.hpp"
                };
            };
        };
    };
    class Marker
    {
        class AttributeCategories
        {
            class Transformation
            {
                class Attributes
                {
                    class Position
                    {
                        tooltip = "$STR_3DEN_OBJECT_ATTRIBUTE_POSITION_TOOLTIP";
                        control = "EditXYZ";
                    };
                    #include "\x\enh\addons\main\attributesMarker\markerDrawPriority.hpp"
                };
            };
            class Style
            {
                class Attributes
                {
                    #include "\x\enh\addons\main\attributesMarker\markerColor.hpp"
                    #include "\x\enh\addons\main\attributesMarker\markerShape.hpp"
                };
            };
            #include "\x\enh\addons\main\attributesMarker\markerHideOnStart.hpp"
        };
    };
    class ENH_3DENCommandPalette
    {
        JSONFilePaths[] =
        {
            ".3DENCommandPalette.json"
        };
        class ENH_Command_Base
        {
            action = "";
            picture = "";
            shortcuts[] = {};
            text = "";
            opensNewWindow = 0;
        };
        class ENH_ShowProductInfo: ENH_Command_Base
        {
            action = "call ENH_fnc_productInfo";
            text = "Show Product Info";
        };
    };
};
