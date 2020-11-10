class ENH_TicketsBLUFOR
{
  displayName = $STR_ENH_RESPAWNTICKETS_BLUFOR_DISPLAYNAME;
  tooltip = "";
  property = "ENH_respawnTickets_west";
  control = "Edit";
  expression = "if (!is3DEN && isMultiplayer && isServer) then {[west,_value] call BIS_fnc_respawnTickets}";
  defaultValue = "0";
  typeName = "NUMBER";
};
class ENH_TicketsOPFOR
{
  displayName = $STR_ENH_RESPAWNTICKETS_OPFOR_DISPLAYNAME;
  property = "ENH_respawnTickets_east";
  control = "Edit";
  expression = "if (!is3DEN && isMultiplayer && isServer) then {[east,_value] call BIS_fnc_respawnTickets}";
  defaultValue = "0";
  typeName = "NUMBER";
};
class ENH_TicketsINDFOR
{
  displayName = $STR_ENH_RESPAWNTICKETS_INDFOR_DISPLAYNAME;
  property = "ENH_respawnTickets_independent";
  control = "Edit";
  expression = "if (!is3DEN && isMultiplayer && isServer) then {[independent,_value] call BIS_fnc_respawnTickets}";
  defaultValue = "0";
  typeName = "NUMBER";
};
class ENH_TicketsCIVFOR
{
  displayName = $STR_ENH_RESPAWNTICKETS_CIVFOR_DISPLAYNAME;
  property = "ENH_respawnTickets_civilian";
  control = "Edit";
  expression = "if (!is3DEN && isMultiplayer && isServer) then {[civilian,_value] call BIS_fnc_respawnTickets}";
  defaultValue = "0";
  typeName = "NUMBER";
};