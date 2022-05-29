// NOTE: def, declare executing functions works only in def, public def declarations (example)
//UseFunction() // Doesn't work // will work only global, local declarations
//public def Func()
//		UseFunction() // Will Work
//end
//

// NOTE: YOU CAN CREATE GLOBALS IN FUNCTIONS
// NOTE: NEVER USE () IN KEYWORDS!
// NOTE: 
//		Never use  functions in using function, example: SetInfo(3, Function(1), 1) // if you do this, then you can get MAV or something else (Skynet++ Compiler Bug)
//		Use: .recommend
//			local result = Function(1)
//			SetInfo(3, result, 1)
//
// 		The compiler skips a function in function using and counts arguments only for the function which using
// 		def SetInfo(variable, result, var)
//			print(variable+ " "+ result + " " + var) // Will return "1 4 1" but must "3 4 1", but using .recommend will return "3 4 1"
//		end
//		def Function(val)
//		return val+3
//		end

// NOTE:
// PREDIRECTIVE #PLAYERSCRIPT // REMOVE ERROR ABOUT EXECUTING FUNCTIONS IN MAIN BLOCK
// you need add this to first line of script
// #PLAYERSCRIPT
// or
// #playerscript

//blitz3d function
declare OpenFile:Int(filename:String) //- return stream
declare WriteFile:Int(filename:String) //- return stream
declare ReadFile:Int(filename:String) //- return stream
declare CloseFile(stream:Int)
declare WriteLine(stream:Int, text:String)
declare WriteFloat(stream:Int, value:Float)
declare WriteInt(stream:Int, value:Int)
declare WriteShort(stream:Int, value:Int)
declare WriteByte(stream:Int, value:Int)
declare ReadLine:String(stream:Int)
declare ReadFloat:Float(stream:Int)
declare ReadInt:Int(stream:Int)
declare ReadShort:Int(stream:Int)
declare ReadByte:Int(stream:Int)
declare Chr:String(asc)
declare Asc:Int(chr:String)

declare FileType:Int(filename:String)
declare FileSize:int(filename:String)

declare SeekFile(filehandle, pos)
declare FilePos:Int(filehandle)
declare WriteBytes(bank,stream,offset,count)
declare ReadBytes(bank,stream,offset,count)

declare MilliSecs:Int()
declare Delay:Int()
declare Left:String(str:String, offset:Int)
declare Right:String(str:String, offset:Int)
declare Instr:Int(str:String, strcheck:String, offset:Int)
declare Len:Int(str:String)
declare Int:Int(value:String)
declare Str:Str(value:String)
declare Float:Float(value:String)

#define :Bank :Int

declare CreateBank:Int(size)
declare FreeBank(bank)
declare BankSize:Int(bankHandle)
declare ResizeBank(bankhandle,new_size)
declare CopyBank(src_bank,src_offset,dest_bank,dest_offset,count)
declare PeekByte:Int(bank,offset)
declare PeekShort:Int(bank,offset)
declare PeekInt:Int(bank,offset)
declare PeekFloat:Float(bank,offset)

declare PokeByte(bank,offset,value)
declare PokeShort(bank,offset,value)
declare PokeInt(bank,offset,value)
declare PokeFloat(bank,offset,value:Float)

// call functions and example
	declare callfunction:String(callback:String, params...) // Calling functions in current script
	declare callglobalfunction:String(scriptfilename:String, callback:String, params...) // Finding and call functions in selected script (Can't call in not loaded)
//	Example
//		public def somepublic(c, c2)
//			//code
//			print(message)
//			return int(c)+int(c2)
//		end
//		result = callfunction("somepublic", 23, 1)
//		print(result)


//

// ALL PUBLICS HAVE A RETURN 0 (ITS CANCEL ACTION IN SOME PUBLICS), ALL PUBLICS THAT DIDN'T HAVE IT BEFORE VERSION 1.2.4.1 HAVE IT
// =========================================================== SERVER
declare public OnLostConnectionWithCentralServer()
declare public OnScriptLoaded() // Execute when a script send a "loaded successfully" message
declare public OnServerUpdate()
declare public OnServerStart(port:Int)
declare public OnPlayerChat(playerid:Int, text:String)
declare public OnPlayerConnect(playerid:Int)
declare public OnIncomingConnection(nickname:String, IP:String, SteamID:Int, version:String, ispatron:Int) // return value returns connecting error to client ( Chr(13)+Chr(10) creating \n )
declare public OnBadIncomingConnection(nickname:String, IP:String, SteamID:Int, version:String, ispatron:Int, EBeginAuthSessionResult:Int) // called when the auth ticket is bad // client can't join to server // return 0 does not send a "bad authorization ticket" message to the console 
declare public OnPlayerDisconnect(playerid:Int, message:String)
declare public OnPlayerUpdate(playerid:Int)
declare public OnPlayerRconIncorrect(playerid:Int)
declare public OnPlayerRconAuthorized(playerid:Int)
declare public OnServerRestart(playerid:Int)
declare public OnPlayerMouseHit(playerid:Int, x:Int, y:Int)
declare public OnPlayerBotConnect(playerid:Int, botid:Int)
declare public OnMapUpdate(delta:Float) // Only calling with fixedtimesteps 1
declare public OnConnectionResponse(IP:String, Port:String)
declare public OnPlayerReceiveFile(playerid:Int, filename:String, result:Int)
declare public OnPlayerConsole(playerid:Int, text:String)
declare public OnPlayerRequestFiles(playerid)
declare public OnReceiveRawPacket(playerid:Int, bank:Bnk) // bank removing after public execute
// =========================================================== GAME
declare public OnPlayerSpeaking(playerid:Int, data:Bank)
declare public OnPlayerTriggered096(playerid:Int, npcid:Int)
declare public OnPlayerShoot(playerid:Int, x:Float, y:Float, z:Float, angle:Float, pitch:Float)
declare public OnPlayerShootRocket(playerid, x:Float, y:Float, z:Float, angle:Float, pitch:Float)
declare public OnPlayerRequestNewRole(playerid:Int, playertype:Int)
declare public OnPlayerHitPlayer(playerid:Int, hitid:Int, damage:Float, weaponid:Int)
declare public OnPlayerKillPlayer(playerid:Int, killid:Int, weaponid:Int)
declare public OnPlayerActivateFemurBreaker(playerid:Int)
declare public OnPlayerRequestExplosion(playerid:Int, timer:Int)
declare public OnPlayAnnouncement(announcementfile:String)
declare public OnPlayerRequestUnlockExits(playerid:Int)
declare public OnPlayerSpawnItem(playerid:Int, itemid:Int)
declare public OnPlayerTakeItem(playerid:Int, itemid:Int, itemtemplateid:Int)
declare public OnPlayerDropItem(playerid:Int, itemid:Int, itemtemplateid:Int)
declare public OnPlayerClickButton(playerid:Int, doorid:Int, open:Int, locked:Int)
declare public OnPlayerRotateLever(playerid:Int, objectid:Int, pitch:Float, yaw:Float, roll:Float)
declare public OnPlayerReleaseSound(playerid:Int, filename:String, volume:Float, dist:Float)
declare public OnPlayerUseItem(playerid:Int, itemid:Int)
declare public OnPlayerUse1162(playerid:Int, itemid:Int, triedtocreatetempid:Int)
declare public OnPlayerRequestNoTarget(playerid:Int)
declare public OnPlayerCreateDecal(playerid:Int)
declare public OnPlayerDropGrenade(playerid:Int, x:Float, y:Float, z:Float, angle:Float, pitch:Float, grenadeType:Int, throwType:int) // grenadetype = weaponid
declare public OnPlayerGetNewRole(playerid, previoustype, newtype)
declare public OnPlayerEscape(playerid, currenttype, previoustype)
declare public OnPlayerEscapeButDead(playerid, currenttype, previoustype)
declare public OnPlayerCuffPlayer(playerid, cuffplayerid)
declare public OnPlayerDeactivateWarheads(playerid)
declare public OnPlayerActivateWarheads(playerid)
declare public OnPlayerSCPContained(playerid, previoustype, newtype) // the return value will replace the sound sent to the players (example: return "SFX\Character\MTF\Announc.ogg") // return "0" won't send anything sound
declare public OnSpawnMTF() // Return value 1 not sending sound to players
declare public OnSpawnChaos() // Return value 1 not sending sound to players
declare public OnActivateWarheads(playerid) // Return value 1 not sending sound to players // public def OnActivateWarheads(playerid) // If player activate the warheads then playerid != 0
declare public OnCreateNPC(npcid:Int)
declare public OnCreateItem(itemid:Int)
declare public OnGenerateWorld() // Return value set map seed while server is starting
declare public OnWarheadsExplosion()
declare public OnRoundStarted()
//central server
declare ConnectToCentralServer(IP:String, Port:Int)
declare ReconnectToCentralServer()
// timers
declare CreateTimer(callback:String, interval, loop, params...) // return id
declare RemoveTimer(id)
// rooms
declare GetRoomName:String(roomid:Int)
declare GetRoomEntity:Int(roomid:Int)
declare GetRoomDoor:Int(roomid:Int, doorid:Int)
declare IsValidRoomDoor:Int(roomid:Int, doorid:Int)
declare IsValidRoom:Int(roomid:Int)
// levers
declare GetRoomObjectEntity(roomid:Int, index:Int)
// doors
declare SetDoorOpenState(doorid:Int, bool:Int)
declare SetDoorLock(doorid:Int, bool:Int)
declare GetDoorLock(doorid:Int)
declare GetDoorOpenState(doorid:Int)
declare GetDoorType:Int(doorid:Int) // return d\dir
declare GetDoorEntity:Int(doorid:Int)
declare IsValidDoor:Int(doorid:Int)
// Events
declare GetEventState1:Float(eventid:Int)
declare GetEventState2:Float(eventid:Int)
declare GetEventState3:Float(eventid:Int)
declare GetEventStr:String(eventid:Int)
declare SetEventState(eventid:Int, state1:Float, state2:Float, state3:Float)
declare SetEventStr(eventid:Int, str:String)
declare GetEventIndex(eventname:String) // Old (not recommended)
declare GetEventName:String(eventid:Int)
declare GetEventRoomID:Int(eventid:Int)
declare RemoveEvent(eventid:Int)
declare IsValidEvent(eventid:Int)
// NPCs
declare CreateNPC:Int(type:Int) // return id
declare GetNPCState1:Float(npcid:Int)
declare GetNPCState2:Float(npcid:Int)
declare GetNPCState3:Float(npcid:Int)
declare SetNPCState(npcid:Int, state1:Float, state2:Float, state3:Float)
declare GetNPCEvent:Int(npcid:Int)
declare GetNPCEntity:Int(npcid:Int)
declare GetNPCType:Int(npcid:iInt)
declare IsValidNPC(npcid:Int)
// Items
declare CreateItem:Int(itemname:String, itemtempname:String) // return id
declare RemoveItem(itemid:Int)
declare GetItemEntity(itemid:Int)
declare GetItemPicker(itemid:Int)
declare IsValidItem(itemid:Int)
declare GetItemTemplate(itemid:Int)
declare SetItemPicker(playerid:Int, itemid:Int)
declare GetItemTemplateName:String(itemtemplate:Int)
declare GetItemTemplateTempName:String(itemtemplate:Int)
// players
declare IsAFakePlayer:Int(playerid:Int)
declare CreateFakePlayer:Int(name:String) //- return playerid - Tip (You can storage game data by this player)
declare SetPlayerFakeHoldingGun(playerid:Int, HOLDING_GUN:Int)
declare SetPlayerFakeAnimation(playerid:Int, PLAYER_ANIM:Int)
declare SetPlayerFakeHazmat(playerid:Int, hazmat:Int)
declare SetPlayerFakeNVG(playerid:Int, nvg:Int)
declare SetPlayerFakeGasMask(playerid:Int, gasmask:Int)
declare SetPlayerFakeVest(playerid:Int, vest:Int)
declare SetPlayerFakeDeadState(playerid:Int, bool:Int)
declare SetPlayerFakeBlinkTimer(playerid:Int, timer:Float)
declare SetPlayerFakeRadioWave(playerid:Int, bool:Int)
declare SetPlayerFakeHealth(playerid:Int, health:Int)
declare SetPlayerFogRange(playerid:Int, range:Float)
declare SetPlayerPing(playerid:Int, ping:Int)
declare SetPlayerAFK(playerid:Int, AFK:Int)
declare SetPlayerPosition(playerid:Int, roomname:String, X:Float, Y:Float, Z:Float)
declare SetPlayersSpawnPosition(roomname:String, X:Float, Y:Float, Z:Float) // teleporting on client-side
declare SetPlayerMessage(playerid:Int, text:String, delay:Int) //- set Msg for players (text in the middle of the screen)
declare SetPlayerHeadPitch:Float(playerid:Int)
declare SetPlayerVelocity(playerid:int, velocity:Float)
declare SetPlayerSpeedMult(playerid:Int, speedmult:Float)
declare SetPlayerHandcuff(playerid:Int, bool:Int)
declare SetPlayerInjuries(playerid:Int, inj:Float) // works only with fullsynchronization 1
declare SetPlayerMute(playerid, bool:int)

declare AddPlayerSpawnPosition(playerid, roomname:String, X:Float, Y:Float, Z:Float) // create spawnpoint for player // return spawnpointer // Removing on player disconnecting
declare AddClassSpawnPosition(RoleType:Int, roomname:String, X:Float, Y:Float, Z:Float) // create spawnpoint for classes // return spawnpointer
declare RemoveSpawnPosition(spawnpointer)
declare IsValidSpawnPosition(spawnpointer)

declare GetPlayerAFK:Int(playerid:Int)
declare GetPlayerNickname:String(playerid:Int)
declare GetPlayerIP:String(playerid:Int)
declare GetPlayerPing:Int(playerid:Int)
declare SetPlayerType(playerid:Int, TYPE_PLAYER:Int) //- set role for player (mp_types.inc)
declare GetPlayerType:Int(playerid:Int) //- get role from player (mp_types.inc)
declare GetPlayerLoadState:Int(playerid:Int)
declare GetPlayerDeadState:Int(playerid:Int)
declare GetPlayerHoldingGun:Int(playerid:Int)
declare GetPlayerRadioWave:Int(playerid:Int)
declare GetPlayerVest:Int(playerid:Int)
declare GetPlayerHazmat:Int(playerid:Int)
declare GetPlayerAnimation:Int(playerid:Int)
declare GetPlayerNVG:Int(playerid:Int)
declare GetPlayerBlinkTimer:Float(playerid:Int)
declare GetPlayerHealth:Int(playerid:Int)
declare GetPlayerRoomID:Int(playerid:Int)
declare GetPlayerReadyState:Int(playerid:Int)
declare GetPlayerVersion:String(playerid:Int)
declare GetPlayerMonitorWidth:int(playerid:Int)
declare GetPlayerMonitorHeight:int(playerid:Int)
declare GetPlayerEntity:Int(playerid:Int)
declare GetPlayerCamera:Int(playerid:Int)
declare GetPlayerHeadPitch:Float(playerid:Int)
declare GetPlayerVelocity:Float(playerid:Int)
declare GetPlayerSteamID(playerid:Int)
declare GetPlayerInjuries(playerid:Int) // works only with fullsynchronization 1
declare GetPlayerZone(playerid)
declare GetPlayerMute(playerid)
declare GetPlayerSpeedMult:Float(playerid:Int)
declare GetPlayerHandcuff:Int(playerid:Int)

declare IsPlayerAdmin:Int(playerid:Int) // get admin access
declare IsPlayerConnected:Int(playerid:Int)
declare IsPlayerPatron(playerid:Int)

declare CreatePlayerSound(playerid:Int, filename:String, X:Float, Y:Float, Z:Float, distance:Float, volume:Float)
declare PlaySound(playerid:Int, filename:String) //- playing local sound for player
declare PlayPlayerSound(playerid:Int, filename:String, distance:Float, volume:Float) //- playing sound on player for all players
declare GiveAdmin(playerid:Int) //- give rcon access
declare RemoveAdmin(playerid:Int) //- remove rcon access

declare Kick(playerid:Int, reason:String)
declare BanIP(ip:String)
declare SendMessage(playerid:Int, text:String)
declare PlayerConsoleCommand(playerid:Int, text:String) //- execute console command for players ( you can see all commands in SCP CB 1.3.11 source code )

declare SendBlinkTimerForPlayer(playerid:Int, timer:Float)
declare ChangePlayerTag(playerid:Int, tag:String, R:Int, G:Int, B:Int) // Max len 255 // Also change color in voice list // Send this to all players so do not abuse
declare ChangePlayerNickname(playerid:Int, name:String) // Max len 255 // Also change color in voice list // Send this to all players so do not abuse
declare AddVersionAccess(string:Version) // cant work for <0.96 versions
declare public OnCheatDetected(playerid:Int, cheatid:Int)

declare ChangePlayerSize(playerid:Int, size:int) // size must be in 0-65535
declare GetPlayerSize:Float(playerid:Int) // if size = 100 then will return 1.0, if size = 150 then will return 1.5, if size in float = 1.0 then size in int = 100

declare ShouldPlayerAnnouncement(playerid:Int, bool:Int)
declare ChangePlayerSteamID(playerid:Int, steamid:Int)
// server

declare ActivateWarheads()
declare DeactivateWarheads()
declare GetBreachTimer()
declare SpawnMTF()
declare SetGameState(state:String)
declare SetServerName(name:String)
declare SetServerDescription(name:String)
declare SetServerCurrentBreachTimer(millisecs:Int)
declare SetServerPassword(pass:String)
declare SetServerNocheat(bool:Int)
declare SetNoTarget(bool:Int)
declare SetMTFtimer(value:Float)
declare SetContained106(bool:Int)
declare SetRemoteDoorOn(bool:Int)
declare SetMTFTickets(tickets:Float)
declare SetChaosTickets(tickets:Float)
declare GetMTFTickets:Float()
declare GetChaosTickets:Float()
declare ActivateFilesSending(bool)
declare SetServerExplodeTimeout(millisecs:Int)
declare SetServerSpawnTimeout(millisecs:Int) // chaos or mtf
declare GetServerExplodeTimeout()
declare GetServerSpawnTimeout() // chaos or mtf

declare GetIncomingConnectionVersion() // Works only in OnIncomingConnection
declare GetIncomingConnectionPatron() // Works only in OnIncomingConnection

declare SetLightVolume(force:Float)
declare GetLightVolume:Float()

declare CreateSound(filename:String, X:Float, Y:Float, Z:Float, distance:Float, volume:Float)
declare Shoot(X:Float, Y:Float, Z:Float, pitch:Float, yaw:Float)
declare CreateRocket(X:Float, Y:Float, Z:Float, pitch:Float, yaw:Float)

declare SetMapSeed(seed:String) //- change map seed and restart server
declare RestartServer()
declare DisableAutoKick()
declare DisableLobby() // starting game and never enable lobby (if server restart then enabled DisableLobby() starting game again)
declare RCONCommand(command:String)
declare GetServerVersion:String()
declare ServerMessage(text:String)

declare EnableAuthKeyOnConnect(bool) // use auth key for steam client on connect (It's checking for invalid client) (Calling OnBadIncomingConnection if auth key is invalid)
declare EnableOldResponse(bool) // in newer versions when you click on the server, certain data is sent, and in older versions, all data about the server is constantly sent, this function turns on the old system (all data is sent) 

declare SetMaxSpawnPlayers(count) // Set maximum count of players on spawn MTF or Chaos
declare GetMaxSpawnPlayers()

declare SetDescriptionLine(DescriptionId, Text:String) // advanced description // max DescriptionId is 19 (< 0 or > 19 = Memory Access Violation)
declare GetDescriptionLine(DescriptionId)
// Steam
declare CreateSteamInstance(SteamID:Int, Tag:String, R:Int, G:Int, B:Int) // which tag player get on connect
declare RemoveSteamInstance(SteamID:Int) // remove all steam instances for this steamid
declare GetSteamInstanceTag:String(SteamID:Int)
//3D
declare PointAt(x:Float, y:Float, z:Float, xAt:Float, yAt:Float, zAt:Float)
declare PointPitch:Float()
declare PointAngle:Float()

declare Move(x:Float, y:Float, z:Float, xV:Float, yV:Float, zV:Float, angle:Float, pitch:Float) //- (xV = velocity)
declare MoveX:Float()
declare MoveY:Float()
declare MoveZ:Float()

// draws
declare CreatePlayerDraw:Int(playerid:Int, X:Int, Y:Int, width:Int, height:Int, TYPE_DRAW:Int, color:Int, filename:String) //- return DRAW pointer for draw for players - COLOR = HEX VALUE! (mp_gui.inc)
declare SetPlayerDrawPos(playerid:Int, drawpointer:Int, X:Int, Y:Int)
declare SetPlayerDrawColor(playerid:Int, drawpointer:Int, color:Int)
declare RemovePlayerDraw(playerid:Int, drawpointer:Int)
// text
declare CreatePlayerText:Int(playerid:Int, txt:String, X:Int, Y:Int, color:Int, fontname:String, fontsize:Float) //- create TEXT pointer for text draw for players - COLOR = HEX VALUE! (mp_gui.inc)
declare SetPlayerTextPos(playerid:Int, textpointer:Int, X:Int, Y:Int)
declare SetPlayerTextString(playerid:Int, textpointer:Int, txt:String)
declare SetPlayerTextColor(playerid:Int, textpointer:Int, color:Int)
declare RemovePlayerText(playerid:Int, textpointer:Int)
// objects
declare CreateObject:Int(modelid:Int, X:Float, Y:Float, Z:Float, range:Float, rawMesh:Int, rawMeshAnimFrames:Int) //- you can edit objects in game - returned object pointer // if range = 0 then objects sending to player always // if you use rawmesh, then you don't need PrepareModelIdentifier for CreateObject in Server scripts (Only player scripts), this also optimize memory using, but some Entity functions won't work properly
declare SetObjectVisibleForPlayer(objectPointer:int, playerid:Int, value:Int)
declare SetObjectInterpolation(objectPointer:Int, Smooth:Int) // smooth 1-255, apply for position and rotate
declare RemoveObject(objectPointer:Int)
declare GetObjectEntity(objectPointer:Int)

declare PrepareModelIdentifier(ID, filename:String) // Using for CreateObject // Use this also in player scripts 
// Entities edit
declare CreateEntityCamera:Int()
declare EntityInView:Int(entity, camera)
declare EntityVisible:Int(entity1, entity2)
declare EntityX:Float(entity)
declare EntityY:Float(entity)
declare EntityZ:Float(entity)
declare EntityPitch:Float(entity)
declare EntityYaw:Float(entity)
declare EntityRoll:Float(entity)

declare PositionEntity(entity, x:Float, y:Float, z:float)
declare RotateEntity(entity, pitch:Float, yaw:Float, roll:float)
declare MoveEntity(entity, vx:Float, vy:float, vz:Float) // velocity
declare ScaleEntity(entity, xyz:Float)
declare SetEntityCollision(entity, bool:Int)
declare RemoveEntity(entity)
declare SetAnimTime(entity, value:Float)
declare EntityPick(entity, radius:Float)

// advanced
declare SendFile(playerid:Int, filepath:String, savepath:String) // Sending a file to player.
declare SendRawData:Int(playerid:Int, data:Packet, bnk:Bank, offset, count) // you can send only GetPacketIndex()
declare SendRawPacket:Int(playerid:Int, bnk:Bank) // sending to player and player receive it in "OnPlayerReceiveRawPacket" (limit 8189 bytes)
declare GetPacketIndex(packet:String) // return packet index for SendRawData() : "voice"

declare ServerWriteByte(value:Int)
declare ServerWriteShort(value:Int)
declare ServerWriteInt(value:Int)
declare ServerWriteFloat(value:Float)

declare CatchError:String() // return current error
declare hexstring:Int(s:String) // Convert String to hex strings
declare plugin_load:Int(pluginname:String)
declare plugin_call:Int(pluginid, functionname:String, returntype:Int) // Execute function from plugin (.dll) and return function returned value
declare plugin_poke(pluginid, value:String, valuetype:Int) // Poke values for function execution // Strings put only information, no final bytes like Chr(13) or byte = 0

// IF YOU DONT WANT USE PLUGIN_LOAD FUNCTIONS
// i use this functions because blitz3d doesn't support loadlibrary
// you can write wrapper and use this functions from wrapper (wrapper library name must be ScriptLib.dll and functions must be B3DPlugin_paramscount)
// using blitz3d decls
// LibName:"ScriptLib.dll";FunctionName:_B3DPlugin_0@0 : EXPORT_DLL(const char*) B3DPluginString_0() // For example
// LibName:"ScriptLib.dll";FunctionName:_B3DPlugin_1@4 : EXPORT_DLL(const char*) B3DPluginString_1(const char* param1) // For example
// LibName:"ScriptLib.dll";FunctionName:_B3DPlugin_2@8 : EXPORT_DLL(const char*) B3DPluginString_2(const char* param1, const char* param2) // For example
// etc..
.
// decls in blitz3d source code:
//DllFunctionVoid_0():"_B3DPluginVoid_0@0"
//DllFunctionVoid_1(param1$):"_B3DPluginVoid_1@4"

// your export name inside .dll must be _B3DPluginVoid_1@4 for example

// C++ Example:
// #define CMDLIB(x) extern "C" __declspec(dllexport) x _stdcall
// FROM:
//CMDLIB(int) ConsoleMessage(const char* message, int color)
//{
//    SetConsoleTextAttribute(stdhandle, color);
//    std::cout << message << "\n";
//    return 8;
//}
// TO:
//CMDLIB(int) B3DPluginInt_2(const char* message, const char* color)
//{
//    SetConsoleTextAttribute(stdhandle, atoi(color));
//    std::cout << message << "\n";
//    return 8;
//}

declare DllFunctionVoid_0() // then export_dll(void) b3dpluginstring_ . . .
declare DllFunctionVoid_1(param1:String = "")
declare DllFunctionVoid_2(param1:String = "",param2:String = "")
declare DllFunctionVoid_3(param1:String = "",param2:String = "",param3:String = "")
declare DllFunctionVoid_4(param1:String = "",param2:String = "",param3:String = "",param4:String = "")
declare DllFunctionVoid_5(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "")
declare DllFunctionVoid_6(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "",param6:String = "")
declare DllFunctionVoid_7(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "",param6:String = "",param7:String = "")
declare DllFunctionVoid_8(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "",param6:String = "",param7:String = "",param8:String = "")
declare DllFunctionVoid_9(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "",param6:String = "",param7:String = "",param8:String = "",param9:String = "")

declare DllFunctionInt_0:Int() // then export_dll(int) b3dpluginint_ . . .
declare DllFunctionInt_1:Int(param1:String = "")
declare DllFunctionInt_2:Int(param1:String = "",param2:String = "")
declare DllFunctionInt_3:Int(param1:String = "",param2:String = "",param3:String = "")
declare DllFunctionInt_4:Int(param1:String = "",param2:String = "",param3:String = "",param4:String = "")
declare DllFunctionInt_5:Int(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "")
declare DllFunctionInt_6:Int(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "",param6:String = "")
declare DllFunctionInt_7:Int(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "",param6:String = "",param7:String = "")
declare DllFunctionInt_8:Int(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "",param6:String = "",param7:String = "",param8:String = "")
declare DllFunctionInt_9:Int(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "",param6:String = "",param7:String = "",param8:String = "",param9:String = "")

declare DllFunctionFloat_0:Float() // then export_dll(float) b3dpluginfloat_ . . .
declare DllFunctionFloat_1:Float(param1:String = "")
declare DllFunctionFloat_2:Float(param1:String = "",param2:String = "")
declare DllFunctionFloat_3:Float(param1:String = "",param2:String = "",param3:String = "")
declare DllFunctionFloat_4:Float(param1:String = "",param2:String = "",param3:String = "",param4:String = "")
declare DllFunctionFloat_5:Float(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "")
declare DllFunctionFloat_6:Float(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "",param6:String = "")
declare DllFunctionFloat_7:Float(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "",param6:String = "",param7:String = "")
declare DllFunctionFloat_8:Float(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "",param6:String = "",param7:String = "",param8:String = "")
declare DllFunctionFloat_9:Float(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "",param6:String = "",param7:String = "",param8:String = "",param9:String = "")

declare DllFunctionString_0:String() // then export_dll(const char*) b3dpluginstring_ . . .
declare DllFunctionString_1:String(param1:String = "")
declare DllFunctionString_2:String(param1:String = "",param2:String = "")
declare DllFunctionString_3:String(param1:String = "",param2:String = "",param3:String = "")
declare DllFunctionString_4:String(param1:String = "",param2:String = "",param3:String = "",param4:String = "")
declare DllFunctionString_5:String(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "")
declare DllFunctionString_6:String(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "",param6:String = "")
declare DllFunctionString_7:String(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "",param6:String = "",param7:String = "")
declare DllFunctionString_8:String(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "",param6:String = "",param7:String = "",param8:String = "")
declare DllFunctionString_9:String(param1:String = "",param2:String = "",param3:String = "",param4:String = "",param5:String = "",param6:String = "",param7:String = "",param8:String = "",param9:String = "")


declare getunixtime:Int()

declare Zlib_Compress(bnk:Bank) // return new bank
declare Zlib_UnCompress(bnk:Bank, fullsize:Int) // return new bank

declare ReloadApp() // Closed server app and starting again.
declare CloseApp() // Closed server app

// INI
declare GetINIValue:String(file:String, section:String, key:String, defaultreturnvalue:String)
declare PutINIValue(file:String, section:String, key:String, value:String)
declare UpdateINIFile(file:String) // Recommended to use after PutINIValue

	//example:
		//local USPDamage = int(GetINIString("ServerConfig\game.ini", "usp", "damage", "1"))
		//print("USP damage: "+USPDamage)
		//PutINIValue("ServerConfig\game.ini", "usp", "damage", "20") // change usp damage value to 20
		//UpdateINIFile("ServerConfig\game.ini")
		
// mysql
		// Return StreamID
		// 	hostname - IP-address or domain of SQL server
		// 	port - port of SQL Server (default is 3306)
		// 	user - username for access to SQL server
		//	password - password for access to SQL server
		// 	database - database name
		// 	flag - type of SQL server (default is 1)
		declare OpenSQLStream:Int(hostname:String, port:Int, user:String, password:String, database:String, flag:Int)
		//
		declare SQLConnected:Int(streamId:Int)
		declare SQLQuery:Int(streamId:Int, query:String) // return queryId
		declare SQLRowCount:Int(queryId:Int)
		declare SQLFetchRow:Int(queryId:Int)
		declare SQLFieldCount:Int(queryId:Int)
		declare ReadSQLField:String(rowId:Int, fieldName:String)
		declare ReadSQLFieldIndex:String(rowId:Int, fieldIndex:Int)
		declare FreeSQLQuery(queryId:Int)
		declare FreeSQLRow(rowId:Int)
		declare CloseSQLStream(streamId:Int) // Closing streamid
		
// sqlite3
	
		declare OpenDatabase(Filename:String, OpenMode, MakeCurrent, ErrorsAreFatal)

		// The database will fail to close if there are SQL statements that
		// have been prepared but not finalised.
		declare CloseDatabase(DatabaseHandle, ErrorsAreFatal)

		// Not required for single user use - TimeOutInMilliSecs = 0 removes timeout
		declare SetDatabaseTimeout(TimeOutInMilliSecs, DatabaseHandle, ErrorsAreFatal)

		declare DatabaseVersion:String()

		// Gets the ID (either the value of the primary key column if there is
		// one, or the internal ID) of the last row inserted into the database.
		declare LastRowIDInserted(DatabaseHandle)

		// Gets the number of rows changed by the last SQL statement run.
		declare RowsChangedByLastStatement(DatabaseHandle)

		// Gets the number of rows changed since the database was opened.
		declare RowsChangedThisSession(DatabaseHandle)

		// The database is always in AutoCommitMode unless you're in the middle of a
		// SQL statement that defines it's own transactions with BEGIN, COMMIT and ROLLBACK.
		declare AutoCommitIsOn(DatabaseHandle)

		// Begins a new transaction.
		declare BeginTransaction(DatabaseHandle, ErrorsAreFatal)

		// Commits the current transaction.
		// If KeepTransactionOpen then it immediately begins a new transaction
		// for you. This is handy if you're commiting in the middle of a large batch
		// of updates but you're not finished yet.
		declare CommitTransaction(KeepTransactionOpen, DatabaseHandle, ErrorsAreFatal)

		// Rolls back the current transaction.
		declare RollbackTransaction(DatabaseHandle, ErrorsAreFatal)

		// If you call any of the declares with ErrorsAreFatal = false and
		// they fail (return 0, "" or false) you can find out what the error
		// code and error message were by calling LastDatabaseErrorCode and
		// LastDatabaseErrorMessage.

		declare LastDatabaseErrorCode(DatabaseHandle)

		declare LastDatabaseErrorMessage:String(DatabaseHandle)

		// Cancels the currently executing SQL. I'd imaging it also rolls back
		// transactions, but the SQLite documentation doesn't say.
		// Note that any prepared SQL will be unusable after this.
		declare InterruptDatabase(DatabaseHandle)

		// Executes the supplied SQL statement but cannot return any results
		// Handy for things like CREATE TABLE, INSERT, UPDATE and DELETE
		declare ExecuteSQL(SQL:String, DatabaseHandle, ErrorsAreFatal)

		// Prepares a SQL statement ready for you to retrieve the data.
		declare PrepareSQL(SQL:String, DatabaseHandle, MakeCurrent, ErrorsAreFatal)

		// Moves to the next row (or first if it's not been called yet for the
		// SQL statement) in the result set of the SQL statement. You can then
		// use the GetColumn???? declares to retrieve the values.
		// If AutomaticallyFinalise is true (the default) then the SQL statement
		// will be automatically finalised when the end of the result set is
		// reached, otherwise you'll have to call FinaliseSQL yourself.
		declare GetNextDataRow(StatementHandle, AutomaticallyFinalise, ErrorsAreFatal)

		// Closes a prepared SQL statement - the database won't close if there
		// are un-finalised SQL statements.
		declare FinaliseSQL(StatementHandle, ErrorsAreFatal)

		// Resets the SQL statement so that data reading (with
		// GetNextDataRow) starts back at the beginning again of the
		// result set.
		// Shouldn't really be combined with the AutomaticallyFinalise
		// parameter of GetNextDataRow as resetting a finalised
		// statement doesn't work.
		declare ResetSQL(StatementHandle, ErrorsAreFatal)

		// Checks to see if the SQL statement has expired (needs to be
		// re-prepared). According to the SQLite docs expiration only usually
		// occurs in circumstances which aren't allowed by this wrapper
		// (ie. some of the more advanced declares which Blitz can't use)
		// so this shouldn't really be required.
		declare SQLHasExpired(StatementHandle)

		// Returns the handle of the database that was used to prepare the
		// SQL statement.
		declare GetDatabaseHandleFromStatementHandle(StatementHandle)

		// Returns the number of columns in the SQL statement's result set.
		declare GetColumnCount(StatementHandle)

		// In the following declares ColumnIndex is zero based.
		// Ie. the first column is 0, the second is 1, etc.

		// Returns the name of the specified of column in the SQL statement's result set.
		declare GetColumnName:String(ColumnIndex, StatementHandle)

		// Returns the type of the specified column in the SQL statement's result set.
		// Returns the type as an integer which you can then compare to the SQLITE_INTEGER,
		// SQLITE_FLOAT, SQLITE_STRING constants.
		declare GetColumnType(ColumnIndex, StatementHandle)

		// Returns the type of the specified column in the SQL statement's result set.
		// Returns the type as a string.
		declare GetColumnDeclaredType:String(ColumnIndex, StatementHandle)

		// Returns the amount of space used to store the column's contents (in bytes).
		declare GetColumnSize(ColumnIndex, StatementHandle)
			
		// In the following declares if the column is actually of a different
		// type to that requested SQLite does its best to convert the contents.

		// Returns the column's contents as an integer.
		declare GetColumnValueAsInteger(ColumnIndex, StatementHandle)

		// Returns the column's contents as a float.
		declare GetColumnValueAsFloat:Float(ColumnIndex, StatementHandle)


		// Returns the column's contents as a string.
		declare GetColumnValueAsString:String(ColumnIndex, StatementHandle)


		// Never tried this - should return the handle to the blob, no idea how to use it though
		declare GetColumnValueAsBlob(ColumnIndex, StatementHandle)

		// SQLite support paramaterised SQL. Parameters can be specified as "?",
		// ":Example" or ":StringExample".
		// See: http://www.sqlite.org/capi3ref.html#sqlite3_bind_blob
		// for more details on parameter naming and binding.

		// Returns the number of parameters in the SQL statement.
		declare SQLParameterCount(StatementHandle)


		// Returns the name of the specified parameter in the SQL statement.
		// Parameters defined as "?" don't have names.
		declare SQLParameterName:String(ParameterIndex, StatementHandle)

		// Returns the index of the parameter with the specified name in the SQL statement.
		declare SQLParameterIndex(ParameterName:String, StatementHandle)

		// Set the specified parameter to null.
		declare BindSQLParameterAsNull(ParameterIndex, StatementHandle)
			

		// Set the specified parameter to the supplied integer value.
		declare BindSQLParameterAsInteger(ParameterIndex, Value, StatementHandle)

		// Should set the specified parameter to the supplied float value.
		// Unfortunately it doesn't seem to work.
		declare BindSQLParameterAsFloat(ParameterIndex, Value:Float, StatementHandle)

		// Set the specified parameter to the supplied string value.
		declare BindSQLParameterAsString(ParameterIndex, Value:String, StatementHandle)

		// Never tried this - no idea if it works or not
		declare BindSQLParameterAsBlob(ParameterIndex, BlobHandle, LengthOfBlob, StatementHandle)


		// Transfers the bindings from one SQL statement to another.
		// Useful I guess if you want to run multiple SQL statements with
		// the same bindings.
		declare TransferSQLBindings(StatementHandle1, StatementHandle2)

		// Just a declare used internally to handle fatal errors.
		declare SQLite3_ErrorHasOccurred(declareName:String, ErrorsAreFatal, Message:String)
//=============================================================================================================



//	plugins:
//		you have to write a ".dll" for these plugins yourself, because the "Blitz3D" doesnt support LoadLibrary()
//		this plugins using CallDLL Blitz3D function
//
//
//		plugin_load:Int(pluginname:String) - Init plugin and return integer plugin value
//		plugin_call:Int(pluginid, functionname:String, returnType) - 
// 		
//			pluginid - plugin id, returned by plugin_load()
//			functionname:String - plugin function name
//			returnType - P_TYPE Consts - type which plugin function return (byte, short...)
//		Example:
//			local console = plugin_load("ConsoleLib.dll")
//			plugin_call(console, "_CreateConsole@4", 0) // creating
//			plugin_poke(console, "just message", P_TYPE_STRING) // add message
//			plugin_poke(console, "just message", P_TYPE_STRING) // add color
// 			plugin_call(console, "_ConsoleLog@8", 0) // call function with added poke data without return type

// ====================================================================================================================================================== PLAYERS SCRIPT

// In-game scripts transmitted to the player via the server and activated on player PC and delete script file. (Not recommended to use this, because it wastes fps in the game, but full recommended for full synchronization)
// You cant use Server functions in Player scripts

// server
declare SendScript(playerid, filename:String, savepath:String) // You need compiled script to use this. // callback - OnPlayerReceiveFile

// game

// NOTE:
// PREDIRECTIVE #PLAYERSCRIPT // ACCESS TO ALLOW EXECUTING FUNCTIONS IN MAIN BLOCK
// you need add this to first line of script
// #PLAYERSCRIPT
// or
// #playerscript

//blitz3d functions
declare OpenFile:Int(filename:String) //- return stream (open only in "multiplayer" folder)
declare WriteFile:Int(filename:String) //- return stream (writing only in "multiplayer" folder)
declare ReadFile:Int(filename:String) //- return stream (reading only in "multiplayer" folder)
declare CloseFile(stream:Int)
declare WriteLine(stream:Int, text:String)
declare WriteFloat(stream:Int, value:Float)
declare WriteInt(stream:Int, value:Int)
declare WriteShort(stream:Int, value:Int)
declare WriteByte(stream:Int, value:Int)
declare ReadLine:String(stream:Int)
declare ReadFloat:Float(stream:Int)
declare ReadInt:Int(stream:Int)
declare ReadShort:Int(stream:Int)
declare ReadByte:Int(stream:Int)
declare Chr:String(asc)
declare Asc:Int(chr:String)

declare FileType:Int(filename:String) // Checking only in "multiplayer" folder
declare FileSize:int(filename:String) // Checking only in "multiplayer" folder

declare SeekFile(filehandle, pos)
declare FilePos:Int(filehandle)
declare WriteBytes(bank,stream,offset,count)
declare ReadBytes(bank,stream,offset,count)

declare MilliSecs:Int()
declare Delay:Int()
declare Left:String(str:String, offset:Int)
declare Right:String(str:String, offset:Int)
declare Instr:Int(str:String, strcheck:String, offset:Int)
declare Len:Int str:String // without () its a keyword
declare Int:Int(value:String)
declare Str:Str(value:String)
declare Float:Float(value:String)

#define :Bank :Int

declare CreateBank:Int(size)
declare FreeBank(bank)
declare BankSize:Int(bankHandle)
declare ResizeBank(bankhandle,new_size)
declare CopyBank(src_bank,src_offset,dest_bank,dest_offset,count)
declare PeekByte:Int(bank,offset)
declare PeekShort:Int(bank,offset)
declare PeekInt:Int(bank,offset)
declare PeekFloat:Float(bank,offset)

declare PokeByte(bank,offset,value)
declare PokeShort(bank,offset,value)
declare PokeInt(bank,offset,value)
declare PokeFloat(bank,offset,value:Float)
//
declare public OnUpdate() // activated per frame
declare public OnRenderWorld() //
declare public OnDead()
declare public OnSpawn()
declare public OnSendMessage(message:String)
declare public OnConsole(message:String)
declare public OnDisconnect(message:String)
declare public OnPressUIButton(x, y, width, height, txt:String) // Doesn't work with DrawUIButton(...) // Only works with original game buttons // return 0 will block pressing

// timers
declare CreateTimer(callback:String, interval, loop, params...) // return id
declare RemoveTimer(id)

// dont work declare CreateItemTemplate(name:String, tempname:String, objpath:String, invimgpath:String, imgpath:String, scale:Float) // DONT WORK // return nothing

declare SetAmbientLight(r,g,b)
declare CameraFogColor(r,g,b)
declare CameraClsColor(r,g,b)
declare HideScreenOcclusion()
declare ShowScreenOcclusion()
declare GetSelectedScreen() // bool
declare ResetSelectedScreen()
declare HideSky()
declare ShowSky()
declare GetRoomName:String()
declare SetCameraShake(shake:Float)
declare ShowPointer()
declare HidePointer()


declare SendMessage(message:String, local:Int)
declare SendConsoleCommand(message:String)
declare LoadAnimMesh(filename:String) // return entity
declare LoadMesh(filename:String) // return entity
declare CreatePivot() // return entity
// float
declare PointAt(x:Float, y:Float, z:Float, xAt:Float, yAt:Float, zAt:Float)
declare PointPitch:Float()
declare PointAngle:Float()

declare Move(x:Float, y:Float, z:Float, xV:Float, yV:Float, zV:Float, angle:Float, pitch:Float) //- (xV = velocity)
declare MoveX:Float()
declare MoveY:Float()
declare MoveZ:Float()

// player
declare GetPlayerCollider()
declare GetPlayerCamera()
declare SetPlayerRoom:Int(roomname:String) // return id
// entities
declare EntityInView:Int(entity, camera)
declare EntityVisible:Int(entity1, entity2)
declare EntityX:Float(entity)
declare EntityY:Float(entity)
declare EntityZ:Float(entity)
declare EntityPitch:Float(entity)
declare EntityYaw:Float(entity)
declare EntityRoll:Float(entity)
declare EntityPick(entity, radius:Float)

declare PositionEntity(entity, x:Float, y:Float, z:float)
declare RotateEntity(entity, pitch:Float, yaw:Float, roll:float)
declare MoveEntity(entity, vx:Float, vy:float, vz:Float) // velocity
declare ScaleEntity(entity, xyz:Float)
declare SetEntityCollision(entity, bool:Int)
declare RemoveEntity(entity)
declare SetAnimTime(entity, value:Float)
//
declare PrepareModelIdentifier(ID, filename:String) // Using for CreateObject in server scripts

// sounds
declare CreateSound3D(filename:String, X:Float, Y:Float, Z:Float, distance:Float, volume:Float)
declare CreateLocalSound(filename:String, volume:Float)
declare Stop3DSounds()
declare StopChannel(channel)
declare ResumeChannel(channel)
declare PauseChannel(channel)
declare ChannelPlaying(channel)
declare ChannelVolume(Channel, volume:Float)
declare ChannelPan(Channel, pan:Float)
declare ChannelPitch(channel, pitch)

// mouse
declare MouseX()
declare MouseY()
declare MouseHit1()
declare MouseHit2()
declare MouseDown1()
declare MouseDown2()
// keys
declare KeyDown(id)
declare KeyHit(id)
declare GetKey() // get pressed key // For Chr or Hex
// drawing // you have to use drawing in OnUpdate(), because each frame erases what was drawn
declare color(r,g,b)
declare loadimage(filename:String)
declare copyimage(image)
declare loadanimimage(filename:String, width, height, first, count)
declare drawimage(img:Int, x, y, frame) // frame for anim image (default is 0)
declare rotateimage(image,value:Float) // 0-360 degress in value:Float
declare handleimage(image,x,y) // image offset
declare resizeimage(image, width, height)
declare oval(x, y, width, height, solid)
declare rect(x, y, width, height, solid)
declare loadfont(fontname:String,size:Int,bold,italic,underlined)
declare setfont(font)
declare text(x, y, txt, centerx, centery)
declare DrawUIButton(x, y, width, height, txt:String, bigFont:Int, waitForMouseUp:Int)
declare DrawUIInputBox:String(x, y, width, height, currentinputboxtext:String, InputBoxID:Int) // return current inputbox text
// please delete everything you created in the "OnDisconnect" callback
declare freefont(font)
declare freeimage(img)
// states
declare Get427Timer:Float()
declare GetBlurTimer:Float()
declare GetStamina:Float()
declare GetBlinkTimer:Float()
declare GetCurrentWeapon:Int()
declare GetCurrentWeaponMagazines()
declare GetCurrentWeaponAmmo()
//items (MAX_ITEMS = 1000)
declare IsValidItem(itemid:Int)
declare GetSelectedItem:Int() // ID
declare GetItemName:String(itemid:Int)
declare GetItemTempName:String(itemid:Int)
declare GetItemState:Float(itemid:Int)
declare GetInventorySlotItemName:String(slot)
declare SetSelectedItemFromInventory(slot)
// intercom
declare GetIntercomTimeout:Int()
declare SetIntercomTimeout(MilliSeconds:Int)
// other
declare disconnect(message:String)
declare connect(ip:String, port, password:String)
declare setgamemessage(msg:String, interval:int) // in seconds
declare getversion:String()
declare getping:Int()
declare getname:String()
declare getdelta:Float()
declare getmonitorwidth:Int()
declare getmonitorheight:Int()
declare getvolume:Float()
declare getfov:Float()

declare caninteract:Int() // if esc menu or hand icon or inventory or keypad etc... not opened
declare ismenuopen:Int()
declare isinventoryopen:Int()
declare isotherinventoryopen:Int()
declare getoptionsmenu:Int()
declare getachievementsmenu:Int()
declare iskeypadopen:Int() 
declare isconsoleopen:Int()
declare iscoffeemachineopen:Int() // scp-294
declare ismainmenuopen:Int() // if game started then returned 0 else returned 1

declare lerp:Float(ToValue:Float, CurrentValue:Float, Smooth:Float) // Using only every frame like in OnUpdate callback
declare lerpangle:Float(ToAngle:Float, CurrentAngle:Float, Smooth:Float) // Using only every frame like in OnUpdate callback

declare lockmouse(bool) // blocking moving and mouse moving // better using with ShowPointer()

// call functions and example
	declare callfunction:String(callback:String, params...) // Calling functions in current script
	declare callglobalfunction:String(scriptfilename:String, callback:String, params...) // Finding and call functions in selected script (Can't call in not loaded)

//	Example
//		public def somepublic(c, c2)
//			//code
//			print(message)
//			return int(c)+int(c2)
//		end
//		result = callfunction("somepublic", 23, 1)
//		print(result)
		
// --------------------------------------------------------------------

// advanced (Plugins is removed due to insecurity)
declare plugin_load:Int(pluginname:String)
declare plugin_call:Int(pluginid, functionname:String, returntype:Int) // Execute function from plugin (.dll) and return function returned value
declare plugin_poke(pluginid, value:String, valuetype:Int) // Poke values for function execution

declare CatchError:String() // return current error
//
declare public OnReceiveRawPacket(bank) // bank removing after public execute
declare SendRawPacket:Int(bnk:Bank) // sending to server and server receive it in "OnReceiveRawPacket" (limit 8189 bytes)

// -------------------------------------------------------------------- For workshop

// Instruction for workshop:
// The scripts files must be in workshop folder with script folder, example: workshop\yourscript\file.gs. You can put as many scripts as you like in the yourscript folder. They will all load
//
declare RedirectFont(OriginalFile:String, WorkshopFont:String) // More comfort // Example: RedirectFont("GFX\fonts\cour\Courier New Rus.ttf", "Tahoma")
declare RedirectFile(OriginalFile:String, WorkshopFile:String) // Example: RedirectFile("SFX\General\BodyFall.ogg", "workshop\yourscript\sounds\BillyHerrington.ogg") // Redirecting original sound to your sound.
declare RedirectText(OriginalText:String, WorkshopText:String) // Example: RedirectText("MULTIPLAYER", "МУЛЬТИПЛЕЕР") // Changing source text to your text (use to translate) // NEED ANSI ENCODER
declare StopRedirectText(OriginalText:String) // Removing RedirectText, use in ondisconnect()
declare StopAllRedirectText()
declare InitLoadingScreens(loadingscreensfile:String)
declare InitInfoClues(cluesfile:String)
declare public OnClickWorkshopLanguage()
declare ReloadFonts()

// All this functions ^^^ return true if successfull, return false is not successfull
declare public OnLoadingFonts() // CALLING ONE TIME!!!
declare public OnLaunchGame() // Some functions doesnt work before this public, example get monitor heights

// for servers:
declare DisableAllWorkshopScripts()