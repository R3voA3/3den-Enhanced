class Cfg3DEN
{
/*    class Group
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
    }; */
    class Marker
    {
        class AttributeCategories
        {
            delete ENH_MarkerHideOnStart;
        };
    };
};
