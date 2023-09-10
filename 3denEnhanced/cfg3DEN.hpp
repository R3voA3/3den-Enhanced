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
      text = "$STR_ENH_NOTIFICATIONS_ACTIONPERFORMED";
    };
    class ENH_NoEntitiesSelected
    {
      isWarning = 1;
      text = "$STR_ENH_NOTIFICATIONS_NOENTITIESSELECTED";
    };
    class ENH_GetPythiaMod_Warning
    {
      isWarning = 1;
      text = "$STR_ENH_NOTIFICATIONS_GETPYTHIA";
    };
    class ENH_PythiaMissingForBackup
    {
      isWarning = 1;
      text = "$STR_ENH_NOTIFICATIONS_BACKUP_FAILED";
    };
  };
  class EventHandlers
  {
    class ENH
    {
      onTerrainNew = "call ENH_fnc_EH_onTerrainNew";
      onMissionPreviewEnd = "call ENH_fnc_EH_onMissionPreviewEnd";
      onMissionLoad = "call ENH_fnc_EH_onMissionLoad";
      onMissionNew = "call ENH_fnc_EH_onMissionNew";
      onMissionPreview = "call ENH_fnc_EH_onMissionPreview";
      onSelectionChange = "call ENH_fnc_EH_onSelectionChange";
      onMissionSave = "call ENH_fnc_createBackupMissionSQM";
      onMissionAutoSave = "call ENH_fnc_createBackupMissionSQM";
    };
  };
  class Attributes
  {
    //Base class templates
    class Default; //Empty template with pre-defined width and single line height
    class Title: Default
    {
      class Controls
      {
        class Title;
      };
    };
    //Increase height of EditCodeMulti5
    #ifndef ENH_LARGER_EDITBOXES
    class EditMulti3;
    class EditCodeMulti3: EditMulti3
    {
      class Controls
      {
        class Value;
        class Background;
        class Title;
      };
    };
    class EditCodeMulti5: EditCodeMulti3
    {
      h = (5 + 20 * 3.5) * GRID_H;
      class Controls: Controls
      {
        class Background: Background
        {
          h = (20 * 3.5 + 0.6 * 5) * GRID_H;
        };
        class Value: Value
        {
          h = 20 * 3.5 * GRID_H - 1 * GRID_H; //We make this one one grid smaller so text will never overlap the frame
        };
        class Title: Title
        {
          h = (20 * 3.5 + 1 * 5) * GRID_H;
        };
      };
    };
    #endif
    #include "controls\SPR.hpp"
    #include "controls\advancedDamage.hpp"
    #include "controls\airdrop.hpp"
    #include "controls\ambientAnimations.hpp"
    #include "controls\ambientFlyby.hpp"
    #include "controls\dynamicSkill.hpp"
    #include "controls\establishingShot.hpp"
    #include "controls\face.hpp"
    #include "controls\groupMarker.hpp"
    #include "controls\holdAction.hpp"
    #include "controls\introText.hpp"
    #include "controls\mapIndicators.hpp"
    #include "controls\menuStripBlacklist.hpp"
    #include "controls\missionEndingCasualties.hpp"
    #include "controls\subCategoryNoHeader_Fixed.hpp"
    #include "controls\timeMultiplier.hpp"
    #include "controls\unitInsignia.hpp"
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
            #ifndef ENH_HIDE_DYNAMICVIEWDISTANCE
              #include "attributesEditor\dynamicViewDistance.hpp"
            #endif
          };
        };
        class Saving
        {
          class Attributes
          {
            #include "attributesEditor\backupMissionSQM.hpp"
          };
        };
        #ifndef ENH_HIDE_INTERFACE
          #include "attributesEditor\interface.hpp"
        #endif
        #ifndef ENH_HIDE_DEBUGOPTIONS
          #include "attributesEditor\debugOptions.hpp"
        #endif
      };
    };
    class Intel
    {
      class AttributeCategories
      {
        #ifndef ENH_HIDE_VISUALSETTINGS
          #include "attributesMission\timeMultiplier.hpp"
        #endif
        #ifndef ENH_HIDE_TIMEMULTIPLIER
          #include "attributesMission\visualSettings.hpp"
        #endif
      };
    };
    class Scenario
    {
      class AttributeCategories
      {
        #ifndef ENH_HIDE_AIRDROP
          #include "attributesMission\airdrop.hpp"
        #endif
        #ifndef ENH_HIDE_AMBIENTFLYBY
          #include "attributesMission\ambientFlyby.hpp"
        #endif
        #ifndef ENH_HIDE_BRIEFING
          #include "attributesMission\briefings.hpp"
        #endif
        #ifndef ENH_HIDE_ESTABLISHINGSHOT
        #include "attributesMission\establishingShot.hpp"
          #endif
        #ifndef ENH_HIDE_INTROTEXT
          #include "attributesMission\introText.hpp"
        #endif
        #ifndef ENH_HIDE_MISSIONENDING
          #include "attributesMission\missionEnding.hpp"
        #endif
        #ifndef ENH_HIDE_VOLUME
          #include "attributesMission\volume.hpp"
        #endif
        #ifndef ENH_HIDE_SPR
          #include "attributesMission\SPR.hpp"
        #endif
        class Misc
        {
          class Attributes
          {
            #ifndef ENH_HIDE_ADDOBJECTSTOZEUS
              #include "attributesMission\addObjectsToZeus.hpp"
            #endif
            #ifndef ENH_HIDE_MAPINDICATORS
              #include "attributesMission\mapIndicators.hpp"
            #endif
          };
        };
      };
    };
    class Multiplayer
    {
      class AttributeCategories
      {
        #ifndef ENH_HIDE_DYNAMICGROUPS
          #include "attributesMission\dynamicGroups.hpp"
        #endif
        #ifndef ENH_HIDE_DYNAMICSKILL
          #include "attributesMission\dynamicSkill.hpp"
        #endif
        class Respawn
        {
          class Attributes
          {
            #ifndef ENH_HIDE_RESPAWNTICKETS
              #include "attributesMission\respawnTickets.hpp"
            #endif
            #ifndef ENH_HIDE_SAVELOADOUT
              #include "attributesMission\saveLoadout.hpp"
            #endif
          };
        };
      };
    };
  };
  class Group
  {
    class AttributeCategories
    {
      #ifndef ENH_HIDE_GROUPMARKER
        #include "attributesGroup\groupMarker.hpp"
      #endif
      class State
      {
        class Attributes
        {
          #ifndef ENH_HIDE_TASKPATROL
            #include "attributesGroup\taskPatrol.hpp"
          #endif
        };
      };
    };
  };
  class Object
  {
    class AttributeCategories
    {
      #ifndef ENH_HIDE_ADVANCEDDAMAGE
        #include "attributesObject\advancedDamage.hpp"
      #endif
      #ifndef ENH_HIDE_AMBIENTANIMATIONS
        #include "attributesObject\ambientAnimations.hpp"
      #endif
      #ifndef ENH_HIDE_AI
        #include "attributesObject\AI.hpp"
      #endif
      #ifndef ENH_HIDE_UNITTRAITS
        #include "attributesObject\unitTraits.hpp"
      #endif
      #ifndef ENH_HIDE_HOLDACTION
        #include "attributesObject\holdAction.hpp"
      #endif
      class StateSpecial
      {
        class Attributes
        {
          #ifndef ENH_HIDE_SETCAPTIVE
            #include "attributesObject\setCaptive.hpp"
          #endif
          #ifndef ENH_HIDE_ALLOWSPRINT
            #include "attributesObject\allowSprint.hpp"
          #endif
          #ifndef ENH_HIDE_FORCEWALK
            #include "attributesObject\forceWalk.hpp"
          #endif
          #ifndef ENH_HIDE_MAKEHOSTAGE
            #include "attributesObject\makeHostage.hpp"
          #endif
          #ifndef ENH_HIDE_PARACHUTE
            #include "attributesObject\parachute.hpp"
          #endif
          #ifndef ENH_HIDE_ENABLEHEADLIGHTS
            #include "attributesObject\enableHeadlights.hpp"
          #endif
          #ifndef ENH_HIDE_ALLOWCREWINIMMOBILE
            #include "attributesObject\allowCrewInImmobile.hpp"
          #endif
          #ifndef ENH_HIDE_ENGINEON
            #include "attributesObject\engineOn.hpp"
          #endif
          #ifndef ENH_HIDE_DISABLENVGE
            #include "attributesObject\disableNVGE.hpp"
          #endif
          #ifndef ENH_HIDE_DISABLETIE
            #include "attributesObject\disableTIE.hpp"
          #endif
          #ifndef ENH_HIDE_LIMITSPEED
            #include "attributesObject\limitSpeed.hpp"
          #endif
          #ifndef ENH_HIDE_DOSTOP
            #include "attributesObject\doStop.hpp"
          #endif
          #ifndef ENH_HIDE_REMOVEFROMREMAINSCOLLECTOR
            #include "attributesObject\removeFromRemainsCollector.hpp"
          #endif
          #ifndef ENH_HIDE_SPR
            #include "attributesObject\SPRTickets.hpp"
          #endif
        };
      };
      class Transformation
      {
        class Attributes
        {
          #ifndef ENH_HIDE_OBJECTSCALE
            #include "attributesObject\objectScale.hpp"
          #endif
          #ifndef ENH_HIDE_SETMASS
            #include "attributesObject\setMass.hpp"
          #endif
        };
      };
      class Inventory
      {
        class Attributes
        {
          #ifndef ENH_HIDE_ADDGUNLIGHT
            #include "attributesObject\addGunLight.hpp"
          #endif
          #ifndef ENH_HIDE_VIRTUALARSENAL
            #include "attributesObject\arsenal.hpp"
          #endif
        };
      };
      class State
      {
        class Attributes
        {
          #ifndef ENH_HIDE_FEATURETYPE
            #include "attributesObject\featureType.hpp"
          #endif
          #ifndef ENH_HIDE_FORCEFLAG
            #include "attributesObject\forceFlag.hpp"
          #endif
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
          #ifndef ENH_HIDE_MARKERDRAWPRIORITY
            #include "attributesMarker\markerDrawPriority.hpp"
          #endif
        };
      };
      #ifndef ENH_HIDE_MARKERHIDEONSTART
        #include "attributesMarker\markerHideOnStart.hpp"
      #endif
    };
  };
};