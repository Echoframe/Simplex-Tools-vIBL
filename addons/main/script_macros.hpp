#include "\x\cba\addons\main\script_macros_common.hpp"
#define DFUNC(var1) TRIPLES(ADDON,fnc,var1)
#ifdef DISABLE_COMPILE_CACHE
	#undef PREP
	#define PREP(fncName) DFUNC(fncName) = compile preprocessFileLineNumbers QPATHTOF(functions\DOUBLES(fnc,fncName).sqf)
#else
	#undef PREP
	#define PREP(fncName) [QPATHTOF(functions\DOUBLES(fnc,fncName).sqf), QFUNC(fncName)] call CBA_fnc_compileFunction
#endif

///////////////////////////////////////////////////////////////////////////////////////////////////

#define PVAR(VAR) DOUBLES(PREFIX,VAR)
#define QPVAR(VAR) QUOTE(PVAR(VAR))

#define ALERT(MSG) \
	diag_log format ["%1: %2",__FILE__,MSG]; \
	systemChat format ["%1: %2",__FILE__,MSG]
#define ZEUS_MESSAGE(MSG) MSG call EFUNC(common,zeusMessage)
#define LOG_MSG(MESSAGE) diag_log FORMAT_2("%1 %2",QUOTE(ADDON),MESSAGE)
#define CHAT_MSG(MESSAGE) systemChat FORMAT_2("%1 %2",QUOTE(ADDON),MESSAGE)
#define USER_DEBUG(MESSAGE) if (EGVAR(main,debug)) then { \
	private _index = __FILE__ find "fnc_"; \
	private _msg = if (_index > -1) then { \
		format ["%1_%2: %3",QUOTE(ADDON),__FILE__ select [_index,(__FILE__ find ".sqf") - _index],MESSAGE] \
	} else { \
		format ["%1: %2",QUOTE(ADDON),MESSAGE] \
	}; \
	diag_log _msg; \
	systemChat _msg; \
}

#define USER_DEBUG_1(MESSAGE,A1) 							USER_DEBUG(FORMAT_1(MESSAGE,A1))
#define USER_DEBUG_2(MESSAGE,ARG1,ARG2) 					USER_DEBUG(FORMAT_2(MESSAGE,ARG1,ARG2))
#define USER_DEBUG_3(MESSAGE,ARG1,ARG2,ARG3) 				USER_DEBUG(FORMAT_3(MESSAGE,ARG1,ARG2,ARG3))
#define USER_DEBUG_4(MESSAGE,ARG1,ARG2,ARG3,ARG4) 			USER_DEBUG(FORMAT_4(MESSAGE,ARG1,ARG2,ARG3,ARG4))
#define USER_DEBUG_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) 		USER_DEBUG(FORMAT_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5))

#define LOG_INFO(MESSAGE) 									LOG_MSG(FORMAT_1("Info: %1",MESSAGE))
#define LOG_INFO_1(MESSAGE,A1) 								LOG_INFO(FORMAT_1(MESSAGE,A1))
#define LOG_INFO_2(MESSAGE,ARG1,ARG2) 						LOG_INFO(FORMAT_2(MESSAGE,ARG1,ARG2))
#define LOG_INFO_3(MESSAGE,ARG1,ARG2,ARG3) 					LOG_INFO(FORMAT_3(MESSAGE,ARG1,ARG2,ARG3))
#define LOG_INFO_4(MESSAGE,ARG1,ARG2,ARG3,ARG4) 			LOG_INFO(FORMAT_4(MESSAGE,ARG1,ARG2,ARG3,ARG4))
#define LOG_INFO_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) 		LOG_INFO(FORMAT_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5))

#define LOG_WARNING(MESSAGE) 								LOG_MSG(FORMAT_1("Warning: %1",MESSAGE))
#define LOG_WARNING_1(MESSAGE,A1) 							LOG_WARNING(FORMAT_1(MESSAGE,A1))
#define LOG_WARNING_2(MESSAGE,ARG1,ARG2) 					LOG_WARNING(FORMAT_2(MESSAGE,ARG1,ARG2))
#define LOG_WARNING_3(MESSAGE,ARG1,ARG2,ARG3) 				LOG_WARNING(FORMAT_3(MESSAGE,ARG1,ARG2,ARG3))
#define LOG_WARNING_4(MESSAGE,ARG1,ARG2,ARG3,ARG4) 			LOG_WARNING(FORMAT_4(MESSAGE,ARG1,ARG2,ARG3,ARG4))
#define LOG_WARNING_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) 	LOG_WARNING(FORMAT_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5))

#define LOG_ERROR(MESSAGE) 									LOG_MSG(FORMAT_1("Error: %1",MESSAGE))
#define LOG_ERROR_1(MESSAGE,A1) 							LOG_ERROR(FORMAT_1(MESSAGE,A1))
#define LOG_ERROR_2(MESSAGE,ARG1,ARG2) 						LOG_ERROR(FORMAT_2(MESSAGE,ARG1,ARG2))
#define LOG_ERROR_3(MESSAGE,ARG1,ARG2,ARG3) 				LOG_ERROR(FORMAT_3(MESSAGE,ARG1,ARG2,ARG3))
#define LOG_ERROR_4(MESSAGE,ARG1,ARG2,ARG3,ARG4) 			LOG_ERROR(FORMAT_4(MESSAGE,ARG1,ARG2,ARG3,ARG4))
#define LOG_ERROR_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5)		LOG_ERROR(FORMAT_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5))

#define CHAT_WARNING(MESSAGE) 								CHAT_MSG(FORMAT_1("Warning: %1",MESSAGE))
#define CHAT_WARNING_1(MESSAGE,A1) 							CHAT_WARNING(FORMAT_1(MESSAGE,A1))
#define CHAT_WARNING_2(MESSAGE,ARG1,ARG2) 					CHAT_WARNING(FORMAT_2(MESSAGE,ARG1,ARG2))
#define CHAT_WARNING_3(MESSAGE,ARG1,ARG2,ARG3) 				CHAT_WARNING(FORMAT_3(MESSAGE,ARG1,ARG2,ARG3))
#define CHAT_WARNING_4(MESSAGE,ARG1,ARG2,ARG3,ARG4) 		CHAT_WARNING(FORMAT_4(MESSAGE,ARG1,ARG2,ARG3,ARG4))
#define CHAT_WARNING_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) 	CHAT_WARNING(FORMAT_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5))

#ifdef DEBUG_MODE_FULL
	#define DEBUG_R(P1,P2) [{drawLine3D _this},{},[ASLToATL P1,ASLToATL P2,[1,0,0,1]],10] call CBA_fnc_waitUntilAndExecute;
	#define DEBUG_G(P1,P2) [{drawLine3D _this},{},[ASLToATL P1,ASLToATL P2,[0,1,0,1]],10] call CBA_fnc_waitUntilAndExecute;
	#define DEBUG_B(P1,P2) [{drawLine3D _this},{},[ASLToATL P1,ASLToATL P2,[0,0,1,1]],10] call CBA_fnc_waitUntilAndExecute;
	#define DEBUG(MESSAGE) 									CHAT_MSG(MESSAGE)
	#define DEBUG_1(MESSAGE,A1) 							DEBUG(FORMAT_1(MESSAGE,A1))
	#define DEBUG_2(MESSAGE,ARG1,ARG2) 						DEBUG(FORMAT_2(MESSAGE,ARG1,ARG2))
	#define DEBUG_3(MESSAGE,ARG1,ARG2,ARG3) 				DEBUG(FORMAT_3(MESSAGE,ARG1,ARG2,ARG3))
	#define DEBUG_4(MESSAGE,ARG1,ARG2,ARG3,ARG4) 			DEBUG(FORMAT_4(MESSAGE,ARG1,ARG2,ARG3,ARG4))
	#define DEBUG_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) 		DEBUG(FORMAT_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5))
#else
	#define DEBUG_R(P1,P2)
	#define DEBUG_G(P1,P2)
	#define DEBUG_B(P1,P2)
	#define DEBUG(MESSAGE)
	#define DEBUG_1(MESSAGE,A1)
	#define DEBUG_2(MESSAGE,ARG1,ARG2)
	#define DEBUG_3(MESSAGE,ARG1,ARG2,ARG3)
	#define DEBUG_4(MESSAGE,ARG1,ARG2,ARG3,ARG4)
	#define DEBUG_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5)
#endif