.equ PLAYER_STARTER_NUM,      VAR_TEMP_1
.equ PLAYER_STARTER_SPECIES,  VAR_TEMP_2

WondrousLab_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, WondrousLab_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, WondrousLab_OnFrame
	.byte 0

WondrousLab_OnWarp::
	map_script_2 VAR_WONDROUS_LAB_STATE, 0, WondrousLab_EventScript_ReadyPlayerForStarterScene
	.2byte 0

WondrousLab_EventScript_ReadyPlayerForStarterScene::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

WondrousLab_OnFrame::
	map_script_2 VAR_WONDROUS_LAB_STATE, 0, WondrousLab_ChooseStarterScene
	.2byte 0

WondrousLab_ChooseStarterScene::
	lockall
	setvar VAR_WONDROUS_LAB_STATE, 1
	msgbox WondrousLab_Text_ProfFiveMonsChooseOne
	msgbox WondrousLab_Text_MomExciting
	closemessage
	releaseall
	end

WondrousLab_EventScript_WhereAreYouGoingDown::
	lockall
	msgbox WondrousLab_Text_MomWhereAreYouGoing
	applymovement LOCALID_PLAYER, WondrousLab_Movement_WhereAreYouGoingDown
	waitmovement 0
	release
	end

WondrousLab_EventScript_WhereAreYouGoingRight::
	lockall
	msgbox WondrousLab_Text_MomWhereAreYouGoing
	applymovement LOCALID_PLAYER, WondrousLab_Movement_WhereAreYouGoingRight
	waitmovement 0
	release
	end

WondrousLab_EventScript_WhereAreYouGoingUp::
	lockall
	msgbox WondrousLab_Text_MomWhereAreYouGoing
	applymovement LOCALID_PLAYER, WondrousLab_Movement_WhereAreYouGoingUp
	waitmovement 0
	release
	end

WondrousLab_EventScript_ReimuOrb::
	lock
	faceplayer
	setvar PLAYER_STARTER_NUM, 0
	setvar PLAYER_STARTER_SPECIES, SPECIES_BULBASAUR
	goto WondrousLab_EventScript_ConfirmStarterChoice
	release
	end

WondrousLab_EventScript_MarisaOrb::
	lock
	faceplayer
	setvar PLAYER_STARTER_NUM, 1
	setvar PLAYER_STARTER_SPECIES, SPECIES_SQUIRTLE
	goto WondrousLab_EventScript_ConfirmStarterChoice
	release
	end

WondrousLab_EventScript_SakuyaOrb::
	lock
	faceplayer
	setvar PLAYER_STARTER_NUM, 2
	setvar PLAYER_STARTER_SPECIES, SPECIES_CYNDAQUIL
	goto WondrousLab_EventScript_ConfirmStarterChoice
	release
	end

WondrousLab_EventScript_YoumuOrb::
	lock
	faceplayer
	setvar PLAYER_STARTER_NUM, 3
	setvar PLAYER_STARTER_SPECIES, SPECIES_CHARMANDER
	goto WondrousLab_EventScript_ConfirmStarterChoice
	release
	end

WondrousLab_EventScript_SanaeOrb::
	lock
	faceplayer
	setvar PLAYER_STARTER_NUM, 4
	setvar PLAYER_STARTER_SPECIES, SPECIES_TORCHIC
	goto WondrousLab_EventScript_ConfirmStarterChoice
	release
	end

WondrousLab_EventScript_ConfirmStarterChoice::
	applymovement LOCALID_WLAB_PROF, Common_Movement_FaceRight
	waitmovement 0
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	textcolor NPC_TEXT_COLOR_MALE
	goto_if_eq PLAYER_STARTER_NUM, 0, WondrousLab_EventScript_ConfirmReimu
	goto_if_eq PLAYER_STARTER_NUM, 1, WondrousLab_EventScript_ConfirmMarisa
	goto_if_eq PLAYER_STARTER_NUM, 2, WondrousLab_EventScript_ConfirmSakuya
	goto_if_eq PLAYER_STARTER_NUM, 3, WondrousLab_EventScript_ConfirmYoumu
	goto_if_eq PLAYER_STARTER_NUM, 4, WondrousLab_EventScript_ConfirmSanae
	end

WondrousLab_EventScript_ConfirmReimu::
	msgbox WondrousLab_Text_ProfChoosingReimu, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, WondrousLab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, WondrousLab_EventScript_DeclinedStarter
	end

WondrousLab_EventScript_ConfirmMarisa::
	msgbox WondrousLab_Text_ProfChoosingMarisa, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, WondrousLab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, WondrousLab_EventScript_DeclinedStarter
	end

WondrousLab_EventScript_ConfirmSakuya::
	msgbox WondrousLab_Text_ProfChoosingSakuya, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, WondrousLab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, WondrousLab_EventScript_DeclinedStarter
	end

WondrousLab_EventScript_ConfirmYoumu::
	msgbox WondrousLab_Text_ProfChoosingYoumu, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, WondrousLab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, WondrousLab_EventScript_DeclinedStarter
	end

WondrousLab_EventScript_ConfirmSanae::
	msgbox WondrousLab_Text_ProfChoosingSanae, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, WondrousLab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, WondrousLab_EventScript_DeclinedStarter
	end

WondrousLab_EventScript_DeclinedStarter::
	hidemonpic
	release
	end

WondrousLab_EventScript_ChoseStarter::
	hidemonpic
	removeobject VAR_LAST_TALKED
	msgbox WondrousLab_Text_ProfThisMonIsEnergetic
	call EventScript_RestorePrevTextColor
	setflag FLAG_SYS_POKEMON_GET
	createmon side=0, slot=6, species=PLAYER_STARTER_SPECIES, level=5, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31
	copyvar VAR_STARTER_MON, PLAYER_STARTER_NUM
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	message WondrousLab_Text_ReceivedMonFromProf
	waitmessage
	setflag FLAG_SYS_B_DASH
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	waitfanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, WondrousLab_EventScript_GiveNicknameToStarter
	closemessage
	goto WondrousLab_EventScript_AfterStarterChoice
	end

WondrousLab_EventScript_GiveNicknameToStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto WondrousLab_EventScript_AfterStarterChoice
	end

WondrousLab_EventScript_AfterStarterChoice::
	applymovement LOCALID_WLAB_PROF, WondrousLab_Movement_ProfTakesExtraStarters
	msgbox WondrousLab_Text_AfterStarterChoice
	waitmovement 0
	removeobject LOCALID_REIMU_ORB
	removeobject LOCALID_MARISA_ORB
	removeobject LOCALID_SAKUYA_ORB
	removeobject LOCALID_YOUMU_ORB
	removeobject LOCALID_SANAE_ORB
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	special EnableNationalPokedex
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message WondrousLab_Text_ReceivedDex
	waitmessage
	waitfanfare
	applymovement LOCALID_WLAB_PROF, WondrousLab_Movement_ProfWalksBack
	applymovement LOCALID_LAB_MOM, WondrousLab_Movement_MomGifts
	waitmovement 0
	msgbox WondrousLab_Text_MomGifts
	giveitem_msg WondrousLab_Text_ReceivedFivePuppetOrbs, ITEM_POKE_BALL, 5
	giveitem_msg WondrousLab_Text_ReceivedSafariVoucher, ITEM_POKE_BALL, 1
	msgbox WondrousLab_Text_MomLeave
	closemessage
	applymovement LOCALID_LAB_MOM, WondrousLab_Movement_MomLeave
	waitmovement 0
	removeobject LOCALID_LAB_MOM
	setvar VAR_WONDROUS_LAB_STATE, 2
	release
	end

WondrousLab_EventScript_Prof::
	lockall
	msgbox WondrousLab_Text_ProfFiveMonsChooseOne
	closemessage
	releaseall
	end

WondrousLab_EventScript_MomExciting::
	lockall
	msgbox WondrousLab_Text_MomExciting
	closemessage
	releaseall
	end

WondrousLab_Movement_ProfTakesExtraStarters::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_down
	step_end

WondrousLab_Movement_ProfWalksBack::
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end

WondrousLab_Movement_WhereAreYouGoingDown::
	walk_down
	step_end

WondrousLab_Movement_WhereAreYouGoingRight::
	walk_right
	step_end

WondrousLab_Movement_WhereAreYouGoingUp::
	walk_up
	step_end

WondrousLab_Movement_MomGifts::
	walk_right
	step_end

WondrousLab_Movement_MomLeave::
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

WondrousLab_Text_ProfFiveMonsChooseOne::
	.string "Here, {PLAYER}.\p"
	.string "There are five Puppets here.\p"
	.string "Haha!\p"
	.string "The Puppets are held inside\n"
	.string "these Puppet Orbs.\p"
	.string "You can have one.\n"
	.string "Go on, choose!$"

WondrousLab_Text_MomExciting::
	.string "Mom: Oooh, this is exciting!\n"
	.string "Which one will you choose?$"

WondrousLab_Text_MomWhereAreYouGoing::
	.string "Mom: Where are you going?\n"
	.string "Don't you want a Puppet?$"

WondrousLab_Text_ProfChoosingReimu::
	.string "Ah! Reimu is your choice.\n"
	.string "You should raise it patiently.\p"
	.string "So, {PLAYER}, you've decided on the\n"
	.string "Miko Puppet Reimu?$"

WondrousLab_Text_ProfChoosingMarisa::
	.string "Hm! Marisa is your choice.\n"
	.string "It's one worth raising.\p"
	.string "So, {PLAYER}, you're claiming the\n"
	.string "Witch Puppet Marisa?$"

WondrousLab_Text_ProfChoosingSakuya::
	.string "I see! Sakuya is your choice.\n"
	.string "You should raise it patiently.\p"
	.string "So, {PLAYER}, you want to go with\n"
	.string "the Maid Puppet Sakuya?$"

WondrousLab_Text_ProfChoosingYoumu::
	.string "I see! Youmu is your choice.\n"
	.string "It's very easy to raise.\p"
	.string "So, {PLAYER}, you've decided on the\n"
	.string "Half-Ghost Puppet Youmu?$"

WondrousLab_Text_ProfChoosingSanae::
	.string "I see! Sanae is your choice.\n"
	.string "It's one worth raising.\p"
	.string "So, {PLAYER}, you want to go with\n"
	.string "the Miko Puppet Sanae?$"

WondrousLab_Text_ProfThisMonIsEnergetic::
	.string "This Puppet is really quite\n"
	.string "energetic!$"

WondrousLab_Text_ReceivedMonFromProf::
	.string "{PLAYER} received the {STR_VAR_1}\n"
	.string "from Prof. Oak!$"

WondrousLab_Text_AfterStarterChoice::
	.string "Okay, I'll just put these\n"
	.string "orbs away.\p"
	.string "Oh, right!\n"
	.string "I have a request for you.\p"
	.string "This is my invention,\n"
	.string "the Puppet Dex!\p"
	.string "It automatically records data on\n"
	.string "Puppets you've seen or caught.\p"
	.string "It's a high-tech encyclopedia!\p"
	.string "To make a complete guide on all\n"
	.string "the Puppets in the world…\p"
	.string "That was my dream!\p"
	.string "But, I'm too old.\n"
	.string "I can't get the job done.\p"
	.string "So, I want you to fulfill my\n"
	.string "dream for me.$"

WondrousLab_Text_MomGifts::
	.string "Mom: To celebrate the start of\n"
	.string "your adventure…\p"
	.string "I have some gifts for you!$"

WondrousLab_Text_MomLeave::
	.string "MOM: I'm sure you know what\n"
	.string "Puppet Orbs are used for.\p"
	.string "As for the Safari Voucher…\p"
	.string "You can use that to get into the\n"
	.string "Safari Zone in Reflecting City.\p"
	.string "It isn't open to the public yet,\n"
	.string "but you can enter with that.\p"
	.string "It's only good for one use though.\p"
	.string "And speakng of Reflecting City…\p"
	.string "That's where you should head to\n"
	.string "get your first gym badge!\p"
	.string "You just need to head east,\n"
	.string "pass through Record Town,\l"
	.string "and through Fairy Forest\l"
	.string "to get to Reflecting City.\p"
	.string "I'll be at home rooting for you.\p"
	.string "Take care, honey!$"

WondrousLab_Text_ReceivedDex::
	.string "{PLAYER} received the Puppet Dex.$"

WondrousLab_Text_ReceivedFivePuppetOrbs::
	.string "{PLAYER} received five Puppet Orbs.$"

WondrousLab_Text_ReceivedSafariVoucher::
	.string "{PLAYER} received the Safari Voucher.$"
