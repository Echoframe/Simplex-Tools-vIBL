#include "script_component.hpp"

params ["_group","_wpPos","_attachedObject"];

private _vehicle = vehicle leader _group;

if (!(driver _vehicle in units _group) || isNull _attachedObject) exitWith {true};

_group allowFleeing 0;
_vehicle engineOn true;
[_vehicle,[0,0,0]] call EFUNC(common,pilotHelicopter);

private _moveTick = 0;

waitUntil {
	if (CBA_missionTime > _moveTick) then {
		_moveTick = CBA_missionTime + 3;

		if (isTouchingGround _vehicle && _vehicle distance2D _wpPos < 200) then {
			_vehicle doMove (_vehicle getPos [200,getDir _vehicle]);
		} else {
			_vehicle doMove _wpPos
		};
	};

	sleep 0.2;

	!isTouchingGround _vehicle && _vehicle distance2D _wpPos < HELO_TAKEOVER_DISTANCE
};

if (isNull _attachedObject) exitWith {true};

[_vehicle,_attachedObject,GVAR(slingloadMassOverride)] call FUNC(slingloadPickup);

waitUntil {
	sleep 0.5;
	!isNull (_vehicle getVariable [QEGVAR(common,slingloadCargo),objNull]) ||
	!(_vehicle getVariable [QEGVAR(common,pilotHelicopter),false]) ||
	_vehicle getVariable [QEGVAR(common,pilotHelicopterCompleted),false]
};

true
