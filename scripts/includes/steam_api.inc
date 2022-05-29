const k_EBeginAuthSessionResultOK 					= 0 // The ticket is valid for this game and this SteamID.
const k_EBeginAuthSessionResultInvalidTicket 		= 1 // The ticket is invalid.
const k_EBeginAuthSessionResultDuplicateRequest 	= 2 // A ticket for this SteamID has already been submitted.
const k_EBeginAuthSessionResultInvalidVersion 		= 3 // The ticket belongs to an incompatible version of the surface.
const k_EBeginAuthSessionResultGameMismatch 		= 4 // The ticket does not apply to this game.
const k_EBeginAuthSessionResultExpiredTicket 		= 5 // The ticket has expired.