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
            isWarning = 1;
            text = "Quick garrison disabled!"; // TODO: Translate 2025-05-02 R3vo
        };
        class ENH_Garrison2_Enabled
        {
            isWarning = 0;
            text = "Quick garrison enabled!"; // TODO: Translate 2025-05-02 R3vo
        };
        class ENH_Garrison2_2D_Not_Supported
        {
            isWarning = 1;
            text = "Quick garrison does not support 2D view."; // TODO: Translate 2025-05-02 R3vo
        };
        class ENH_Garrison2_All_Positions_Taken
        {
            isWarning = 1;
            text = "No more empty positions!"; // TODO: Translate 2025-05-02 R3vo
        };
        class ENH_Garrison2_All_Positions_Taken_Auto_Select
        {
            isWarning = 1;
            text = "No more empty positions! Remaining entities were auto selected."; // TODO: Translate 2025-05-02 R3vo
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
        #include "controls\base.hpp"
        // #include "controls\markerColor.hpp"
        #include "controls\advancedDamage.hpp"
        #include "controls\airdrop.hpp"
        #include "controls\ambientAnimations.hpp"
        #include "controls\ambientFlyby.hpp"
        #include "controls\cfgMusic.hpp"
        #include "controls\dynamicSkill.hpp"
        #include "controls\establishingShot.hpp"
        #include "controls\groupMarker.hpp"
        #include "controls\holdAction.hpp"
        #include "controls\inputList.hpp"
        #include "controls\introText.hpp"
        #include "controls\largerEditMulti.hpp"
        #include "controls\mapIndicators.hpp"
        #include "controls\missionEndingCasualties.hpp"
        #include "controls\sliderMulti120.hpp"
        #include "controls\sliderMultiZero.hpp"
        #include "controls\SPR.hpp"
        #include "controls\subCategoryNoHeader_Fixed.hpp"
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
                        #include "attributesEditor\dynamicViewDistance.hpp"
                    };
                };
                class Saving
                {
                    class Attributes
                    {
                        #include "attributesEditor\backupMissionSQM.hpp"
                    };
                };
                #include "attributesEditor\interface.hpp"
                #include "attributesEditor\garrison2.hpp"
                #include "attributesEditor\debugOptions.hpp"
            };
        };
        class Intel
        {
            class AttributeCategories
            {
                #include "attributesMission\timeMultiplier.hpp"
                #include "attributesMission\visualSettings.hpp"
            };
        };
        class Scenario
        {
            class AttributeCategories
            {
                #include "attributesMission\airdrop.hpp"
                #include "attributesMission\ambientFlyby.hpp"
                #include "attributesMission\briefings.hpp"
                #include "attributesMission\establishingShot.hpp"
                #include "attributesMission\introText.hpp"
                #include "attributesMission\missionEndingCasualties.hpp"
                #include "attributesMission\volume.hpp"
                #include "attributesMission\SPR.hpp"
                #include "attributesMission\missionEventHandlersGlobal.hpp"
                #include "attributesMission\missionEventHandlersServer.hpp"
                #include "attributesMission\musicEventHandlers.hpp"
                class Misc
                {
                    class Attributes
                    {
                        #include "attributesMission\backupMissionSQMDisable.hpp"
                        #include "attributesMission\addObjectsToZeus.hpp"
                        #include "attributesMission\mapIndicators.hpp"
                    };
                };
            };
        };
        class Multiplayer
        {
            class AttributeCategories
            {
                #include "attributesMission\dynamicGroups.hpp"
                #include "attributesMission\dynamicSkill.hpp"
                class Respawn
                {
                    class Attributes
                    {
                        #include "attributesMission\respawnTickets.hpp"
                        #include "attributesMission\saveLoadout.hpp"
                    };
                };
            };
        };
    };
    class Group
    {
        class AttributeCategories
        {
            #include "attributesGroup\groupMarker.hpp"
            #include "attributesGroup\eventHandlers.hpp"
            class State
            {
                class Attributes
                {
                    #include "attributesGroup\taskPatrol.hpp"
                };
            };
        };
    };
    class Object
    {
        class AttributeCategories
        {
            #include "attributesObject\advancedDamage.hpp"
            #include "attributesObject\ambientAnimations.hpp"
            #include "attributesObject\AI.hpp"
            #include "attributesObject\unitTraits.hpp"
            #include "attributesObject\holdAction.hpp"
            #include "attributesObject\eventHandlers.hpp"
            class StateSpecial
            {
                class Attributes
                {
                    #include "attributesObject\setCaptive.hpp"
                    #include "attributesObject\allowSprint.hpp"
                    #include "attributesObject\forceWalk.hpp"
                    #include "attributesObject\makeHostage.hpp"
                    #include "attributesObject\parachute.hpp"
                    #include "attributesObject\enableHeadlights.hpp"
                    #include "attributesObject\allowCrewInImmobile.hpp"
                    #include "attributesObject\engineOn.hpp"
                    #include "attributesObject\disableNVGE.hpp"
                    #include "attributesObject\disableTIE.hpp"
                    #include "attributesObject\doStop.hpp"
                    #include "attributesObject\removeFromRemainsCollector.hpp"
                    #include "attributesObject\SPRTickets.hpp"
                };
            };
            class Transformation
            {
                class Attributes
                {
                    #include "attributesObject\objectScale.hpp"
                };
            };
            class Inventory
            {
                class Attributes
                {
                    #include "attributesObject\addGunLight.hpp"
                    #include "attributesObject\arsenal.hpp"
                };
            };
            class State
            {
                class Attributes
                {
                    #include "attributesObject\featureType.hpp"
                    #include "attributesObject\forceFlag.hpp"
                    #include "attributesObject\setMass.hpp"
                    #include "attributesObject\waterLeakiness.hpp"
                    #include "attributesObject\limitSpeed.hpp"
                    #include "attributesObject\fuelConsumptionCoef.hpp"
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
                    #include "attributesMarker\markerDrawPriority.hpp"
                };
            };
            class Style
            {
                // class Attributes
                // {
                //     #include "attributesMarker\markerColor.hpp"
                // };
            };
            #include "attributesMarker\markerHideOnStart.hpp"
        };
    };
};
