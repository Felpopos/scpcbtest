// maybe you can create anticheat with this scripts

//				#define def = public def // DECLARING ALL FUNCTIONS BY PUBLIC, DONT USE IT :)
//				#define + - // REPLACING + on - :)
//				never use alone symbols in defines
// ========================================== all publics and functions in mp_functions.inc
// *Tip: YOU CAN CREATE GLOBALS IN FUNCTIONS
// *Tip: NEVER USE () IN KEYWORDS!
// *Tip: 
//		Never use double functions in using function, example: SetInfo(variable, Function(1, 2), 1) // if you do this, then you can get MAV or something else (Skynet++ Bug)
//		Use:
//			local result = Function(1, 2)
//			SetInfo(variable, result, 1)
// ========================================================================================================================
#define WT = while true
#define exit break

#include "includes\multiplayer_core.inc" // Including variables

global PlayerName = [MAX_PLAYERS, SE_STRING]
global PlayerIP = [MAX_PLAYERS, SE_STRING]

global PlayerLastCoordX = [MAX_PLAYERS, SE_FLOAT]
global PlayerLastCoordY = [MAX_PLAYERS, SE_FLOAT]
global PlayerLastCoordZ = [MAX_PLAYERS, SE_FLOAT]

global PlayerSpeed = [MAX_PLAYERS, SE_FLOAT]

def user_main()

end

public def OnPlayerUpdate(playerid)
	speed_update(playerid)
end

public def OnServerUpdate()
	
end

public def OnServerStart(port)
	SetEventState("alarm", 0.0)
	//timer_example()
end
public def OnGameStarted()

end
public def OnPlayerChat(playerid, text) // If return false then player dont sending Text variable, else sending.
	return true
end
public def OnPlayerConnect(playerid)
	PlayerName[playerid] = GetPlayerNickname(playerid)
	PlayerIP[playerid] = GetPlayerIP(playerid)
end
public def OnPlayerDisconnect(playerid, message)
	if GetPlayerVarValue(playerid, "PlayerAttach") != 0 then removeplayerattach(playerid)
end
public def OnServerRestart(mapseed)
	
end
public def OnPlayerMouseHit(playerid, x, y)

end
// example ----------------------------------------------------------------------
def removeplayerattach(playerid) // in OnPlayerDisconnect public
	RemoveObject(GetPlayerVarValue(playerid, "PlayerAttach"))
end
def createplayerattach(playerid)
	 // Creating SCP-513 Bell for attach (EXAMPLE) (dont use it please)
	SetPlayerVarValue(playerid, "PlayerAttach", CreateObject("GFX\items\513.x", 0,0,0))
	SetObjectScale(GetPlayerVarValue(playerid, "PlayerAttach"), 0.1)
end
def updateplayerattach(playerid) // in PlayerUpdate or ServerUpdate
	SetObjectPosition(GetPlayerVarValue(playerid, "PlayerAttach"), PlayerX(playerid), PlayerY(playerid)+0.65, PlayerZ(playerid)) // set bell position on player head (classd type)
end
// ================================================================ FSOUND PLUGIN EXAMPLE
def FSOUND_Init(rate, channels, flags)
	global fsound_lib = plugin_init("fmod.dll")
	plugin_poke(fsound_lib, rate, P_TYPE_INT)
	plugin_poke(fsound_lib, channels, P_TYPE_INT)
	plugin_poke(fsound_lib, flags, P_TYPE_INT)
	return plugin_call(fsound_lib, "_FSOUND_Init@12", P_TYPE_INT)
end
def FSOUND_Stream_Open(filename)
	plugin_poke(fsound_lib, filename, P_TYPE_STRING)
	Return plugin_call(fsound_lib, "_FSOUND_Stream_Open@16", P_TYPE_INT)
end
def FSOUND_Stream_Play(channel, stream)
	plugin_poke(fsound_lib, channel, P_TYPE_INT)
	plugin_poke(fsound_lib, stream, P_TYPE_INT)
	return plugin_call(fsound_lib, "_FSOUND_Stream_Play@8", P_TYPE_INT)
	// And you have memory access violation (idk why)
end
// ================================================================ Call Function EXAMPLE (There a timer example)
public def SomePublic(firstArgument, secondArgument)
	print("Printed from public "+Str(int(firstArgument)+int(secondArgument)))
end
def callback_example()
	createtimer("SomePublic", 0, 0, 34, 3)
end

// ========================= TIMERS

public def SecondTimer(firststr)
	print("Done "+firststr)
end
def timer_example()
	CreateTimer("SecondTimer", 1000, 1, "Param")
end
// ====================================================================================== Player speed update
def speed_update(playerid)
	PlayerSpeed[playerid] = Distance(PlayerLastCoordX[playerid], PlayerLastCoordY[playerid], PlayerLastCoordZ[playerid], PlayerX(playerid), PlayerY(playerid), PlayerZ(playerid))
	PlayerLastCoordX[playerid] = PlayerX(playerid)
	PlayerLastCoordZ[playerid] = PlayerY(playerid)
	PlayerLastCoordZ[playerid] = PlayerZ(playerid)
end

def Distance(x1, y1, z1, x2, y2, z2)
	return ((x2-x1)**2 + (y2-y1)**2 + (z2-z1)^2)**0.5
end

// ====================================================================================== Memory example
global VOICE_QUALITY = int(getservercfg("voice_quality"))
public def OnPlayerSpeaking(playerid, data)
	playermuted = 0
	if playermuted != false then return false // Don't sending if player is muted
	return true
end
			//filename, data, voice_quality, 1, 8
def CreateWav(filename, data, rate, wav_format, wav_bitrate) // Recording all data that player is speak :)
	local f
	if FileType(filename) != 1 Then // Writing header
		f = WriteFile(filename)
		WriteInt(f,hexstring("RIFF"))
		
		WriteInt(f, BankSize(data)+40)
		
		WriteInt(f,hexstring("WAVE"))
		
		WriteInt(f,hexstring("fmt "))
		
		WriteInt(f, 16)
		WriteShort(f, 1)
		WriteShort(f, wav_format)
		WriteInt(f, rate)
		WriteInt(f, rate*1)
		WriteShort(f, 1)
		WriteShort(f, wav_bitrate)
		
		WriteInt(f,hexstring("data"))
		
		WriteInt(f, BankSize(data))
		CloseFile(f)
	end
	f = OpenFile(filename)
	SeekFile(f, 4) // Updating size in header
	WriteInt(f, ((FileSize(filename)+BankSize(data))-44)+40)
	SeekFile(f, 40) // Updating size in header
	WriteInt(f, (FileSize(filename)-44)+BankSize(data))
	SeekFile(f, FileSize(filename))
	WriteBytes(data, f, 0, BankSize(data))
	CloseFile(f)
end
// ====================================================================================== Recording wav file
global songbot

global PlayerSongMemory = [MAX_PLAYERS, SE_INT]
global PlayerSongRate = [MAX_PLAYERS, SE_INT]
global PlayerSongOffset = [MAX_PLAYERS, SE_INT]

def getservercfg(command)
	local f = ReadFile("server.cfg"),stats = "",msg=""
	while not eof(f)
		msg = ReadLine(f)
		stats = Trim(Left(msg, Instr(msg, " ", 1)))
		if stats == command then
			stats = replace(msg, stats+" ", "")
			exit
		end
	end
	closefile(f)
	return stats
end

def LoadBotSong(playerid, filename, size) // Support only wav // This tested on 44100 khz wave file, 16 bitrate
	// Loading header
	PlayerSongMemory[playerid] = ReadFile(filename)
	local hexdata = "", char = 0
	while not eof(PlayerSongMemory[playerid])
		char = ReadByte(PlayerSongMemory[playerid])
		if char != 0 then hexdata = hexdata+Chr(char)
		if instr(hexdata, "data", 1) != 0 then break
	end
	ReadInt(PlayerSongMemory[playerid])
	PlayerSongRate[playerid] = size
	PlayerSongOffset[playerid] = FilePos(PlayerSongMemory[playerid])
end

def BotSongUpdate(playerid)
	local bank = CreateBank(PlayerSongRate[playerid])
	SeekFile(PlayerSongMemory[playerid], PlayerSongOffset[playerid])
	PlayerSongRate[playerid] = ReadBytes(bank, PlayerSongMemory[playerid], 0, PlayerSongRate[playerid])
	if PlayerSongRate[playerid] < 1 then
		freebank(bank)
		return false
	end
	vcl = int(PlayerSongRate[playerid]/512)
	if OnPlayerSpeaking(playerid, bank) then
		for a = 1; a < MAX_PLAYERS; a++
			if IsPlayerConnected(a) and a != playerid then
				for i = 0; i < vcl; i++
					ServerWriteByte(playerid) // sending botid
					SendRawData(a, GetPacketIndex("voice"), bank, (BankSize(bank)/vcl)*i, BankSize(bank)/vcl)
				end
			end
		end
	end
	FreeBank(bank)
	PlayerSongOffset[playerid] = PlayerSongOffset[playerid]+PlayerSongRate[playerid]
	return true
end

def songexample()
	CreateTimer("SongUpdater", 187, 1)
	songbot = CreateFakePlayer()
	SetPlayerType(songbot, TYPE_CLASSD)
	SetPlayerFakeRadioWave(songbot, 6) // Bot starting speaking in radio
	LoadBotSong(songbot, "Gastello9.wav", 10000)
end

public def SongUpdater()
	if BotSongUpdate(songbot) == false then 
		CloseFile(PlayerSongMemory[songbot])
		LoadBotSong(songbot, "Gastello9.wav", 10000)
	end
end