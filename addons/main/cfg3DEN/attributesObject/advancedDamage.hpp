class ENH_AdvancedDamage
{
    displayName = "$STR_ENH_MAIN_ATTRIBUTECATEGORY_ADVANCEDDAMAGE";
    collapsed = 1;
    class Attributes
    {
        class ENH_AdvancedDamage_Subcategory
        {
            description = "$STR_ENH_MAIN_ADVANCEDDAMAGE_DESCRIPTION";
            data = "AttributeSystemSubcategory";
            control = "ENH_SubCategoryNoHeader2_Fixed";
        };
        class ENH_AdvancedDamage
        {
            displayName = "$STR_ENH_MAIN_ATTRIBUTECATEGORY_ADVANCEDDAMAGE";
            tooltip = "$STR_ENH_MAIN_ADVANCEDDAMAGE_DESCRIPTION";
            property = "ENH_AdvancedDamage";
            expression = "if (local _this) then {parseSimpleArray _value params ['_hitpoints', '_damage']; {if ((_damage # _forEachIndex) == 0) then {continue}; _this setHitPointDamage [_x, _damage # _forEachIndex, false]} forEach _hitpoints}";
            control = "ENH_AdvancedDamage";
            defaultValue = "if (getAllHitPointsDamage _this isNotEqualTo []) then {str [getAllHitPointsDamage _this # 0, getAllHitPointsDamage _this # 2]} else {str [[], []]}";
            typeName = "STRING";
            condition = "objectVehicle + objectBrain"; // Perhaps this is better to avoid issues with buildings.
        };
    };
};
