_____ [SERVER HELP] _____
[Don't create these things anymore than their constants ( if you create, then you will get MAV ) ]
MAX_ITEMS = 500
MAX_DOORS = 500
MAX_NPCs = 255

[MAXIMUMS]
Maximum players = 32
Maximum time out = 120000
Maximum gravity = -100
Maximum port = 65535

[MINIMUMS]
Minimum port = 80
Minimum players = 1
Minimum time out = 5000

[STANDARTS]
STANDART PLAYERS = 16
STANDART TIME OUT = 15000
STANDART NOCHEAT = 0
STANDART JUMPMODE = 0
STANDART GRAVITY = 0.023
STANDART VOICE = 1
STANDART PORT = 50021
STANDART HOSTNAME = "SCP Server [version]"
STANDART PASSWORD = ""
STANDART BREACH = 0
STANDART BREACH LIGHT = 0
STANDART BREACH TIME = 900000
STANDART TICKRATE = 64

[COMMANDS]
password - Set password. [STANDART PASSWORD]
eventprob - Set eventprob. [RANDOM]
timeout - Set time out time. [STANDART TIME OUT]
nocheat - Turn on/off nocheat mode on the server. No cheat disable opening the console, as a result, no one can use cheats. [STANDART NOCHEAT]
mapseed - Set map seed. Leave blank if you want random seed [RANDOM]
hostname - Set server name. [STANDART HOSTNAME]
port - Set server port. [STANDART PORT]
introenabled - Turn on/off intro. [STANDART INTRO ENABLED]
voice - Turn on/off voice on the server. [STANDART VOICE]
jumpmode - Turn on/off jumping on the server. [STANDART TIME OUT]
gravity - Set gravity. [STANDART GRAVITY]
maxplayers - Set max players. [STANDART PLAYERS]
breach - Set breach mode. [STANDART BREACH]
breachlight - Turn on light in facility if breach mode is true. [not recommended] [STANDART BREACH LIGHT]
breachtime - Set time to breach mode [STANDART BREACH TIME]
tickrate - Set tickrate to server [STANDART TICKRATE]
rconpassword - RCON Password for give admin
breach_onlydeathmatch - Set only deathmatch round for breach mode
keepinventory - Make drop items after dead
description - Setting server description in server menu
gamestate - Setting server game state in colorized oval at server list
custommap - Loading map from .cbmap2 file
voice_quality(0-2) - Set server voice quality (Doesn't work) (Always spend maximum 200 bytes)
disableauthkey - Disable auth key on incoming connection
disabletimestamp - Disable timestamp in log
centralserver - Using central server or use SteamGameServer which need Steam
centralservertcprequest - Send TCP or UDP request on incoming connection

[SCRIPTS]
You can edit your server a little bit by scripts.
To compile use compiler.exe
To use scripts type in server.cfg - script filename (GSC compiled file)
or 
scripttext filename (GS file)


[HELP]
The jump increases if you decrease the gravity value on the cfg server.
If version doesn't match with game version, then you give "Server not responding" error
The server has tickrates. 2, 4, 8, 16, 32, 64, 128 - The more, the less FPS, but better synchronization. Tickrate affects on NPCs, Items, Players, Chat, Doors, Events

To start the server, you must put the server in the game folder, and download DirectPlay if you get errors.
To formatting text, you must use % %
Example in ServerConfig folder.