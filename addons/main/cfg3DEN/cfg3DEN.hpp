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
            onEditableEntityAdded = "call ENH_fnc_EH_onEditableEntityAdded";
            onMissionAutoSave = "call ENH_fnc_createBackupMissionSQM";
            onMissionLoad = "call ENH_fnc_EH_onMissionLoad";
            onMissionNew = "call ENH_fnc_EH_onMissionNew";
            onMissionPreview = "call ENH_fnc_EH_onMissionPreview";
            onMissionPreviewEnd = "call ENH_fnc_EH_onMissionPreviewEnd";
            onMissionSave = "call ENH_fnc_createBackupMissionSQM";
            onTerrainNew = "call ENH_fnc_EH_onTerrainNew";
        };
    };
    class Attributes
    {
        #include "\x\enh\addons\main\cfg3DEN\controls\base.hpp"

        #include "\x\enh\addons\main\cfg3DEN\controls\advancedDamage.hpp"
        #include "\x\enh\addons\main\cfg3DEN\controls\airdrop.hpp"
        #include "\x\enh\addons\main\cfg3DEN\controls\ambientAnimations.hpp"
        #include "\x\enh\addons\main\cfg3DEN\controls\ambientFlyby.hpp"
        #include "\x\enh\addons\main\cfg3DEN\controls\cfgMusic.hpp"
        #include "\x\enh\addons\main\cfg3DEN\controls\dynamicSkill.hpp"
        #include "\x\enh\addons\main\cfg3DEN\controls\establishingShot.hpp"
        #include "\x\enh\addons\main\cfg3DEN\controls\groupMarker.hpp"
        #include "\x\enh\addons\main\cfg3DEN\controls\holdAction.hpp"
        #include "\x\enh\addons\main\cfg3DEN\controls\inputList.hpp"
        #include "\x\enh\addons\main\cfg3DEN\controls\introText.hpp"
        #include "\x\enh\addons\main\cfg3DEN\controls\largerEditMulti.hpp"
        #include "\x\enh\addons\main\cfg3DEN\controls\mapIndicators.hpp"
        #include "\x\enh\addons\main\cfg3DEN\controls\markerColor.hpp"
        #include "\x\enh\addons\main\cfg3DEN\controls\markerShape.hpp"
        #include "\x\enh\addons\main\cfg3DEN\controls\missionEndingCasualties.hpp"
        #include "\x\enh\addons\main\cfg3DEN\controls\sliderMulti120.hpp"
        #include "\x\enh\addons\main\cfg3DEN\controls\sliderMultiZero.hpp"
        #include "\x\enh\addons\main\cfg3DEN\controls\SPR.hpp"
        #include "\x\enh\addons\main\cfg3DEN\controls\subCategoryNoHeader_Fixed.hpp"
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
                        #include "\x\enh\addons\main\cfg3DEN\attributesEditor\dynamicViewDistance.hpp"
                    };
                };
                class Saving
                {
                    class Attributes
                    {
                        #include "\x\enh\addons\main\cfg3DEN\attributesEditor\backupMissionSQM.hpp"
                    };
                };
                class Misc
                {
                    class Attributes
                    {
                        #include "\x\enh\addons\main\cfg3DEN\attributesEditor\holdActionIcons.hpp"
                    };
                };
                #include "\x\enh\addons\main\cfg3DEN\attributesEditor\interface.hpp"
                #include "\x\enh\addons\main\cfg3DEN\attributesEditor\garrison2.hpp"
                #include "\x\enh\addons\main\cfg3DEN\attributesEditor\debugOptions.hpp"
            };
        };
        class Intel
        {
            class AttributeCategories
            {
                #include "\x\enh\addons\main\cfg3DEN\attributesMission\timeMultiplier.hpp"
                #include "\x\enh\addons\main\cfg3DEN\attributesMission\visualSettings.hpp"
            };
        };
        class Scenario
        {
            class AttributeCategories
            {
                #include "\x\enh\addons\main\cfg3DEN\attributesMission\airdrop.hpp"
                #include "\x\enh\addons\main\cfg3DEN\attributesMission\ambientFlyby.hpp"
                #include "\x\enh\addons\main\cfg3DEN\attributesMission\briefings.hpp"
                #include "\x\enh\addons\main\cfg3DEN\attributesMission\establishingShot.hpp"
                #include "\x\enh\addons\main\cfg3DEN\attributesMission\introText.hpp"
                #include "\x\enh\addons\main\cfg3DEN\attributesMission\missionEndingCasualties.hpp"
                #include "\x\enh\addons\main\cfg3DEN\attributesMission\volume.hpp"
                #include "\x\enh\addons\main\cfg3DEN\attributesMission\SPR.hpp"
                #include "\x\enh\addons\main\cfg3DEN\attributesMission\missionEventHandlersGlobal.hpp"
                #include "\x\enh\addons\main\cfg3DEN\attributesMission\missionEventHandlersServer.hpp"
                #include "\x\enh\addons\main\cfg3DEN\attributesMission\musicEventHandlers.hpp"
                class Misc
                {
                    class Attributes
                    {
                        #include "\x\enh\addons\main\cfg3DEN\attributesMission\backupMissionSQMDisable.hpp"
                        #include "\x\enh\addons\main\cfg3DEN\attributesMission\addObjectsToZeus.hpp"
                        #include "\x\enh\addons\main\cfg3DEN\attributesMission\mapIndicators.hpp"
                    };
                };
            };
        };
        class Multiplayer
        {
            class AttributeCategories
            {
                #include "\x\enh\addons\main\cfg3DEN\attributesMission\dynamicGroups.hpp"
                #include "\x\enh\addons\main\cfg3DEN\attributesMission\dynamicSkill.hpp"
                class Respawn
                {
                    class Attributes
                    {
                        #include "\x\enh\addons\main\cfg3DEN\attributesMission\respawnTickets.hpp"
                        #include "\x\enh\addons\main\cfg3DEN\attributesMission\saveLoadout.hpp"
                    };
                };
            };
        };
    };
    class Group
    {
        class AttributeCategories
        {
            #include "\x\enh\addons\main\cfg3DEN\attributesGroup\groupMarker.hpp"
            #include "\x\enh\addons\main\cfg3DEN\attributesGroup\eventHandlers.hpp"
            class State
            {
                class Attributes
                {
                    #include "\x\enh\addons\main\cfg3DEN\attributesGroup\taskPatrol.hpp"
                };
            };
        };
    };
    class Object
    {
        class AttributeCategories
        {
            #include "\x\enh\addons\main\cfg3DEN\attributesObject\advancedDamage.hpp"
            #include "\x\enh\addons\main\cfg3DEN\attributesObject\ambientAnimations.hpp"
            #include "\x\enh\addons\main\cfg3DEN\attributesObject\AI.hpp"
            #include "\x\enh\addons\main\cfg3DEN\attributesObject\unitTraits.hpp"
            #include "\x\enh\addons\main\cfg3DEN\attributesObject\holdAction.hpp"
            #include "\x\enh\addons\main\cfg3DEN\attributesObject\eventHandlers.hpp"
            class StateSpecial
            {
                class Attributes
                {
                    #include "\x\enh\addons\main\cfg3DEN\attributesObject\setCaptive.hpp"
                    #include "\x\enh\addons\main\cfg3DEN\attributesObject\allowSprint.hpp"
                    #include "\x\enh\addons\main\cfg3DEN\attributesObject\forceWalk.hpp"
                    #include "\x\enh\addons\main\cfg3DEN\attributesObject\makeHostage.hpp"
                    #include "\x\enh\addons\main\cfg3DEN\attributesObject\parachute.hpp"
                    #include "\x\enh\addons\main\cfg3DEN\attributesObject\enableHeadlights.hpp"
                    #include "\x\enh\addons\main\cfg3DEN\attributesObject\allowCrewInImmobile.hpp"
                    #include "\x\enh\addons\main\cfg3DEN\attributesObject\engineOn.hpp"
                    #include "\x\enh\addons\main\cfg3DEN\attributesObject\disableNVGE.hpp"
                    #include "\x\enh\addons\main\cfg3DEN\attributesObject\disableTIE.hpp"
                    #include "\x\enh\addons\main\cfg3DEN\attributesObject\doStop.hpp"
                    #include "\x\enh\addons\main\cfg3DEN\attributesObject\removeFromRemainsCollector.hpp"
                    #include "\x\enh\addons\main\cfg3DEN\attributesObject\SPRTickets.hpp"
                };
            };
            class Transformation
            {
                class Attributes
                {
                    #include "\x\enh\addons\main\cfg3DEN\attributesObject\objectScale.hpp"
                };
            };
            class Inventory
            {
                class Attributes
                {
                    #include "\x\enh\addons\main\cfg3DEN\attributesObject\addGunLight.hpp"
                    #include "\x\enh\addons\main\cfg3DEN\attributesObject\arsenal.hpp"
                };
            };
            class State
            {
                class Attributes
                {
                    #include "\x\enh\addons\main\cfg3DEN\attributesObject\featureType.hpp"
                    #include "\x\enh\addons\main\cfg3DEN\attributesObject\turretStabilization.hpp"
                    #include "\x\enh\addons\main\cfg3DEN\attributesObject\forceFlag.hpp"
                    #include "\x\enh\addons\main\cfg3DEN\attributesObject\setMass.hpp"
                    #include "\x\enh\addons\main\cfg3DEN\attributesObject\waterLeakiness.hpp"
                    #include "\x\enh\addons\main\cfg3DEN\attributesObject\limitSpeed.hpp"
                    #include "\x\enh\addons\main\cfg3DEN\attributesObject\fuelConsumptionCoef.hpp"
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
                    #include "\x\enh\addons\main\cfg3DEN\attributesMarker\markerDrawPriority.hpp"
                };
            };
            class Style
            {
                class Attributes
                {
                    #include "\x\enh\addons\main\cfg3DEN\attributesMarker\markerShape.hpp"
                };
            };
            #include "\x\enh\addons\main\cfg3DEN\attributesMarker\markerHideOnStart.hpp"
        };
    };
    class Layer
    {
        class AttributeCategories
        {
            class Init
            {
                class Attributes
                {
                    #include "\x\enh\addons\main\cfg3DEN\attributesLayer\defaultLayer.hpp"
                };
            };
        };
    };
    class ENH_3DENCommandPalette_Commands
    {
        class ENH_Command_Base
        {
            action = "";
            description = "";
            opensNewWindow = 0;
            picture = "";
            text = "";
            copyToClipboard = 0;
        };
    };
};
