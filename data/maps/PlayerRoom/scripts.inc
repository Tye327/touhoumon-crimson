PlayerRoom_MapScripts::
	.byte 0


PlayerRoom_EventScript_WallClock::
	lockall
	setvar VAR_0x8004, MALE
	goto PlayerRoom_EventScript_WallClock
	end

PlayerRoom_EventScript_WallClock::
	goto_if_set FLAG_SET_WALL_CLOCK, PlayerRoom_EventScript_CheckWallClock
	msgbox PlayerRoom_Text_ClockIsStopped, MSGBOX_DEFAULT
	call PlayerRoom_EventScript_SetWallClock
	delay 30
	setflag FLAG_SET_WALL_CLOCK
	releaseall
	end

PlayerRoom_EventScript_CheckWallClock::
	incrementgamestat GAME_STAT_CHECKED_CLOCK
	fadescreen FADE_TO_BLACK
	special Special_ViewWallClock
	waitstate
	releaseall
	end

PlayerRoom_EventScript_SetWallClock::
	fadescreen FADE_TO_BLACK
	special StartWallClock
	waitstate
	return

PlayerRoom_EventScript_CheckPlayersPC::
	lockall
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
	releaseall
	end

PlayerRoom_EventScript_TurnOffPlayerPC::
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

PlayerRoom_EventScript_Notebook::
	msgbox PlayerRoom_Text_Notebook, MSGBOX_SIGN
	end

PlayerRoom_EventScript_GameCube::
	msgbox PlayerRoom_Text_ItsAGameCube, MSGBOX_SIGN
	end

PlayerRoom_Text_ClockIsStopped:
	.string "The clock is stopped…\p"
	.string "Better set it and start it!$"

PlayerRoom_Text_Notebook:
	.string "{PLAYER} flipped open the notebook.\p"
	.string "ADVENTURE RULE NO. 1\n"
	.string "Open the MENU with START.\p"
	.string "ADVENTURE RULE NO. 2\n"
	.string "Record your progress with SAVE.\p"
	.string "The remaining pages are blank…$"

PlayerRoom_Text_LookCloserAtMap:
	.string "{PLAYER} took a closer look at the\n"
	.string "{REGION} region map.$"

PlayerRoom_Text_ItsAGameCube:
	.string "It's a Nintendo GameCube.\p"
	.string "A Game Boy Advance is connected to\n"
	.string "serve as the Controller.$"
