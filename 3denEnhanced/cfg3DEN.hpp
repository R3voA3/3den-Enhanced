class Cfg3DEN
{
	class Notifications
	{
		class ENH_DataCopied
		{
			isWarning = 0;
			text = $STR_A3_RSCDISPLAYARSENAL_MESSAGE_CLIPBOARD;
		};
		class ENH_ActionPerformed
		{
			isWarning = 0;
			text = $STR_ENH_NOTIFICATIONS_ACTIONPERFORMED;
		};
		class ENH_NoEntitiesSelected
		{
			isWarning = 1;
			text = $STR_ENH_NOTIFICATIONS_NOENTITIESSELECTED;
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
		};
	};
	class Attributes
	{
		// Base class templates
		class Default;
		class Title: Default
		{
			class Controls
			{
				class Title;
			};
		};
		#include "controls\timeMultiplier.hpp"
		#include "controls\featureType.hpp"
		#include "controls\terrainDetail.hpp"
		#include "controls\ambientAnimations.hpp"
		#include "controls\introText.hpp"
		#include "controls\establishingShot.hpp"
		#include "controls\mapIndicators.hpp"
		#include "controls\groupMarker.hpp"
		#include "controls\airdrop.hpp"
		#include "controls\ambientFlyby.hpp"
		#include "controls\dynamicSkill.hpp"
		#include "controls\holdAction.hpp"
		#include "controls\missionEndingCasualties.hpp"
		#include "controls\taskPatrol.hpp"
		#include "controls\debugOptions.hpp"
		#include "controls\SPR.hpp"
    #include "controls\hideTerrainObjects.hpp"
    #include "controls\magazinesTurrets.hpp"
	};
 	class Mission
	{
		class Preferences
		{
			class AttributeCategories
			{
				class Misc
				{
					class Attributes
					{
						#include "attributesEditor\debugOptions.hpp"
					};
				};
				#include "attributesEditor\interface.hpp"
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
				#include "attributesMission\volume.hpp"
				#include "attributesMission\mapIndicators.hpp"
				#include "attributesMission\ambientFlyby.hpp"
				#include "attributesMission\airdrop.hpp"
				#include "attributesMission\establishingShot.hpp"
				#include "attributesMission\introText.hpp"
				#include "attributesMission\missionEnding.hpp"
				#include "attributesMission\SPR.hpp"
				class Misc
				{
					class Attributes
					{
						#include "attributesMission\addObjectsToZeus.hpp"
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
			class State
			{
				class Attributes
				{
					#include "attributesGroup\taskPatrol.hpp"
				};
			};
		};
	};
 /*  class Trigger
  {
    class AttributeCategories
    {
      #include "attributesTrigger\hideTerrainObjects.hpp"
    };
  }; */
	class Object
	{
		class AttributeCategories
		{
			#include "attributesObject\advancedDamageUnit.hpp"
			#include "attributesObject\advancedDamageVehicle.hpp"
			#include "attributesObject\disableAI.hpp"
			#include "attributesObject\advancedSkill.hpp"
			#include "attributesObject\unitTraits.hpp"
			#include "attributesObject\holdAction.hpp"
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
					#include "attributesObject\limitSpeed.hpp"
					#include "attributesObject\doStop.hpp"
					#include "attributesObject\removeFromRemainsCollector.hpp"
					#include "attributesObject\SPRTickets.hpp"
					#include "attributesObject\debugPath.hpp"
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
					#include "attributesObject\allowFleeing.hpp"
					#include "attributesObject\setMass.hpp"
					#include "attributesObject\featureType.hpp"
					#include "attributesObject\forceFlag.hpp"
					#include "attributesObject\ambientAnimations.hpp"
          #include "attributesObject\magazineTurrets.hpp"
				};
			};
		};
	};
};