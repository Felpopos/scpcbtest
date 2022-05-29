#include "includes\multiplayer_core.inc" // Including variables
#define public function = def
#define function def

global PlayerRocketTime = [MAX_PLAYERS, SE_INT]
global PlayerGrenadeTime = [MAX_PLAYERS, SE_INT]
global PlayerHealth = [MAX_PLAYERS, SE_INT]
global PlayerFlood = [MAX_PLAYERS, SE_INT]
global ServerItemsClear = 0
global ServerItemsSetting = 0
global ItemWasPicked = [MAX_ITEMS, SE_INT]

public function OnScriptLoaded()
	LoadClearItems()
end

public function OnPlayerConnect(playerid)
	PlayerRocketTime[playerid] = 0
	PlayerGrenadeTime[playerid] = 0
end

public function OnPlayerChat(playerid, text)
	if PlayerFlood[playerid] > MilliSecs() then return 0
	PlayerFlood[playerid] = MilliSecs()+1000
	return 1
end

public function OnPlayerRequestExplosion(playerid, timer)
	return 1
end

public function OnPlayerConsole(playerid, text)
	if not IsPlayerAdmin(playerid) then
		RCONCommand("banip "+GetPlayerIP(playerid))
	end
end

public function OnIncomingConnection(name, ip)
	local trimmed = ""
	trimmed = Trim(name)
	if trimmed != name then return "Please change your name"+Chr(13)+Chr(10)+"The name can contain"+Chr(13)+Chr(10)+"only english letters"+Chr(13)+Chr(10)+"or numbers"+Chr(13)+Chr(10)+"Double spaces are not available."
end

function IsValidChar(char)
	local byte = 0
	byte = Asc(char)
	if byte > 32 and byte < 48 then return 1
	if byte > 64 and byte < 91 then return 1
	if byte > 191 and byte < 256 then return 1
	if byte > 96 and byte < 123 then return 1
	if byte > 47 and byte < 58 then return 1
	return 0
end

public function OnPlayerShootRocket(playerid, x, y, z, yaw, pitch)
	if PlayerRocketTime[playerid] == 0 then
		PlayerRocketTime[playerid] = MilliSecs()+1000
	else
		if MilliSecs() < PlayerRocketTime[playerid] and GetPlayerPing(playerid) < 1000 then Kick(playerid, GetPlayerNickname(playerid)+" kicked due to cheats")
	end
end

public function OnPlayerDropGrenade(playerid, x, y, z, yaw, pitch)
	if PlayerGrenadeTime[playerid] == 0 then
		PlayerGrenadeTime[playerid] = MilliSecs()+500
	else
		if MilliSecs() < PlayerGrenadeTime[playerid] and GetPlayerPing(playerid) < 500 then Kick(playerid, GetPlayerNickname(playerid)+" kicked due to cheats")
	end
end

function GivePlayerHealth(playerid, hp)
	PlayerHealth[playerid] = PlayerHealth[playerid]+hp
	if PlayerHealth[playerid] < 0 then SetPlayerType(playerid, 0)
end

function SetPlayerHealth(playerid, hp)
	PlayerHealth[playerid] = hp
end

public function OnPlayerTakeItem(playerid, itemid, templateid)
	ItemWasPicked[itemid] = true
end

public function OnPlayerDropItem(playerid, itemid, templateid) // If item not registered in items clear system
	ItemWasPicked[itemid] = true
end

public function OnSpawnMTF()
	if ServerItemsClear == 0 then SetClearTimer(MilliSecs()+(ServerItemsSetting*60*1000))
end

public function OnServerUpdate()
	if ServerItemsClear != 0 then
		if ServerItemsClear < MilliSecs() then
			local cleareditems = 0
			for i = 1; i < MAX_ITEMS; i++
				if IsValidItem(i) then
					if GetItemPicker(i) < 1 then
						if ItemWasPicked[i] then 
							RemoveItem(i)
							ItemWasPicked[i] = 0
							cleareditems++
						end
					end
				end
			end
			print("Unnecessary items have been successfully cleaned! ("+cleareditems+" items)")
			ResetClearTimer()
		end
	end
end

public function OnPlayerGetNewRole(playerid, prevbreachtype, breachtype)
	for i = 1; i < MAX_ITEMS; i++
		if IsValidItem(i) then
			if GetItemPicker(i) == playerid then
				ItemWasPicked[i] = true
			end
		end
	end
end

public function OnServerStart()
	OnServerRestart()
end

public function OnServerRestart()
	ResetClearTimer()
	ResetClearItems()
end

function getserversettings(command, filename)
	local f = ReadFile(filename), stats = "", msg=""
	while not eof(f)
		msg = ReadLine(f)
		stats = Trim(Left(msg, Instr(msg, " ", 1)))
		if stats == command then
			stats = replace(msg, stats+" ", "")
			break
		end
	end
	closefile(f)
	return stats
end



function SetClearTimer(time)
	ServerItemsClear = time
end

function ResetClearTimer()
	ServerItemsClear = 0
end
function ResetClearItems()
	for i = 1; i < MAX_ITEMS; i++
		ItemWasPicked[i] = false
	end
end
function LoadClearItems()
	ServerItemsSetting = int(getserversettings("itemstimeclear", "server.cfg"))
	if ServerItemsSetting == 0 then ServerItemsSetting = 10
	print("Items clearing time: "+ServerItemsSetting+" min")
end