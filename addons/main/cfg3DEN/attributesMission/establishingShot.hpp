class ENH_EstablishingShot
{
    collapsed = 1;
    displayName = "$STR_ENH_MAIN_ATTRIBUTECATEGORY_ESTABLISHINGSHOT";
    class Attributes
    {
        class ENH_EstablishingShot_Subcategory
        {
            description = "$STR_ENH_MAIN_ESTABLISHINGSHOT_DESCRIPTION";
            data = "AttributeSystemSubcategory";
            control = "ENH_SubCategoryNoHeader1_Fixed";
        };
        class ENH_EstablishingShot
        {
            displayName = "$STR_ENH_MAIN_ATTRIBUTECATEGORY_ESTABLISHINGSHOT";
            property = "ENH_establisingShot";
            control = "ENH_EstablishingShot";
            expression = "if (!is3DEN && ((_value # 0) isNotEqualTo [0, 0, 0]) && hasInterface) then {_value spawn BIS_fnc_establishingShot}";
            defaultValue = "[[0, 0, 0], getText (configFile >> 'CfgWorlds' >> worldName >> 'description'), 500, 200, 60, 0]";
        };
    };
};
