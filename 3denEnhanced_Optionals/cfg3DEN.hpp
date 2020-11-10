class Cfg3DEN
{
  class EventHandlers
  {
    class ENH_Optionals
    {
      onTerrainNew = "call ENHO_fnc_removeItemsFromMenu";
    };
  };
   class Mission
  {
    class Preferences
    {
      class AttributeCategories
      {
        #ifdef HIDE_ENH_INTERFACE
          delete ENH_Interface;
        #endif
        class Misc
        {
          class Attributes
          {
            #ifdef HIDE_ENH_DEBUGOPTIONS
              delete ENH_DebugOptions;
            #endif
          };
        };
      };
    };
    class Intel
    {
      class AttributeCategories
      {
        #ifdef HIDE_ENH_VISUALSETTINGS
          delete ENH_VisualSettings;
        #endif
        class Date
        {
          class Attributes
          {
            #ifdef HIDE_ENH_TIMEMULTIPLIER
              delete ENH_TimeMultiplier;
            #endif
          };
        };
      };
    };
    class Scenario
    {
      class AttributeCategories
      {
        #ifdef HIDE_ENH_AIRDROP
          delete ENH_Airdrop;
        #endif
        #ifdef HIDE_ENH_AMBIENTFLYBY
          delete ENH_AmbientFlyby;
        #endif
        #ifdef HIDE_ENH_ESTABLISHINGSHOT
          delete ENH_EstablishingShot;
        #endif
        #ifdef HIDE_ENH_INTROTEXT
          delete ENH_IntroText;
        #endif
        #ifdef HIDE_ENH_MAPINDICATORS
          delete ENH_MapIndicators;
        #endif
        #ifdef HIDE_ENH_MISSIONENDING
          delete ENH_MissionEnding;
        #endif
        #ifdef HIDE_ENH_SPR
          delete ENH_SPR;
        #endif
        #ifdef HIDE_ENH_VOLUME
          delete ENH_Volume;
        #endif
        class Misc
        {
          class Attributes
          {
            #ifdef HIDE_ENH_ADDOBJECTSTOZEUS
              delete ENH_AddObjectsToZeus;
            #endif
          };
        };
      };
    };
    class Multiplayer
    {
      class AttributeCategories
      {
        #ifdef HIDE_ENH_DYNAMICSKILL
          delete ENH_DynamicSkill;
        #endif
        #ifdef HIDE_ENH_DYNAMICGROUPS
          delete ENH_DynamicGroups;
        #endif
        class Respawn
        {
          class Attributes
          {//Doesn't work yet
            #ifdef HIDE_ENH_TICKETSBLUFOR
              delete ENH_TicketsBLUFOR;
            #endif
            #ifdef HIDE_ENH_TICKETSOPFOR
              delete ENH_TicketsOPFOR;
            #endif
            #ifdef HIDE_ENH_TICKETSINDFOR
              delete ENH_TicketsINDFOR;
            #endif
            #ifdef HIDE_ENH_TICKETSCIVFOR
              delete ENH_TicketsCIVFOR;
            #endif
            #ifdef HIDE_ENH_SAVELOADOUT
              delete ENH_SaveLoadout;
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
      #ifdef HIDE_ENH_GROUPMARKER
        delete ENH_GroupMarker;
      #endif
      class State
      {
        class Attributes
        {
          #ifdef HIDE_ENH_TASKPATROL
            delete ENH_TaskPatrol;
          #endif
        };
      };
    };
  };
  class Object
  {
    class AttributeCategories
    {
      #ifdef HIDE_ENH_ADVANCEDDAMAGEUNIT
        delete ENH_AdvancedDamageUnit;
      #endif
      #ifdef HIDE_ENH_ADVANCEDDAMAGEVEHICLE
        delete ENH_AdvancedDamageVehicle;
      #endif
      #ifdef HIDE_ENH_ADVANCEDSKILL
        delete ENH_AdvancedSkill;
      #endif
      #ifdef HIDE_ENH_DISABLEAI
        delete ENH_DisableAI;
      #endif
      #ifdef HIDE_ENH_HOLDACTION
        delete ENH_HoldAction;
      #endif
      #ifdef HIDE_ENH_UNITTRAITS
        delete ENH_UnitTraits;
      #endif
      class StateSpecial
      {
        class Attributes
        {
          #ifdef HIDE_ENH_ALLOWCREWINIMMOBILE
            delete ENH_AllowCrewInImmobile;
          #endif
          #ifdef HIDE_ENH_ALLOWSPRINT
            delete ENH_AllowSprint;
          #endif
          #ifdef HIDE_ENH_DEBUGPATH
            delete ENH_debugPath;
          #endif
          #ifdef HIDE_ENH_DISABLENVGE
            delete ENH_DisableNVGE;
          #endif
          #ifdef HIDE_ENH_DISABLETIE
            delete ENH_DisableTIE;
          #endif
          #ifdef HIDE_ENH_DOSTOP
            delete ENH_DoStop;
          #endif
          #ifdef HIDE_ENH_ENABLEHEADLIGHTS
            delete ENH_EnableHeadlights;
          #endif
          #ifdef HIDE_ENH_ENGINEON
            delete ENH_EngineOn;
          #endif
          #ifdef HIDE_ENH_FORCEWALK
            delete ENH_ForceWalk;
          #endif
          #ifdef HIDE_ENH_LIMITSPEED
            delete ENH_LimitSpeed;
          #endif
          #ifdef HIDE_ENH_MAKEHOSTAGE
            delete ENH_MakeHostage;
          #endif
          #ifdef HIDE_ENH_PARACHUTE
            delete ENH_Parachute;
          #endif
          #ifdef HIDE_ENH_REMOVEFROMREMAINSCOLLECTOR
            delete ENH_removeFromRemainsCollector;
          #endif
          #ifdef HIDE_ENH_SETCAPTIVE
            delete ENH_SetCaptive;
          #endif
          #ifdef HIDE_ENH_SPR
            delete ENH_SPR_Tickets;
          #endif
        };
      };
      class Inventory
      {
        class Attributes
        {
          #ifdef HIDE_ENH_ADDGUNLIGHT
            delete ENH_AddGunLight;
          #endif
          #ifdef HIDE_ENH_VIRTUALARSENAL
            delete ENH_VirtualArsenal;
          #endif
          #ifdef HIDE_ENH_TURRETMAGAZINES
            delete ENH_TurretMagazines;
          #endif
        };
      };
      class State
      {
        class Attributes
        {
          #ifdef HIDE_ENH_ALLOWFLEEING
            delete ENH_AllowFleeing;
          #endif
          #ifdef HIDE_ENH_AMBIENTANIMATIONS
            delete ENH_AmbientAnimations;
          #endif
          #ifdef HIDE_ENH_FEATURETYPE
            delete ENH_FeatureType;
          #endif
          #ifdef HIDE_ENH_FORCEFLAG
            delete ENH_ForceFlag;
          #endif
          #ifdef HIDE_ENH_SETMASS
            delete ENH_SetMass;
          #endif
        };
      };
    };
  };
};