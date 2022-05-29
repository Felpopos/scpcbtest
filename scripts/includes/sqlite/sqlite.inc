// Look Example at Example Script in server folder
// Put all .dll in server folder

// Author:		Alan Broad (HappyCat)
// Contact:		alan@broad.ukf.net
// Version:		1.1
// Date:			1 July 2005
// Requirements:	SQLite3.dll		http://www.sqlite.org (3.2.2)

// Most declares take the following parameters:

//	DatabaseHandle or StatementHandle
// 		The OpenDatabase and PrepareSQL declares always remember
//		the last database opened and the last SQL statement prepared
//		(unless you tell them otherwise with the MakeCurrent
//		parameter) so in a simple single database setup you might
//		be able to get away with never actually storing the handles
// 		and letting the declares take care of it.

//	ErrorsAreFatal
//		If true (the default) any SQLite errors will cause a
//		RuntimeError and stop your program. If this is false then
//		errors will simply return 0, "" or false and your program
//		will continue.

// Individual declares are documented where necessary.

// Full SQLite 3 documentation can be found at http://www.sqlite.org/capi3ref.html
// and SQlite's SQL syntax is explained at http://www.sqlite.org/lang.html

// Change History

// v1.1, 1 July 2005
// 	  - Renamed DatabaseInAutoCommitMode to AutoCommitIsOn and added
//		BeginTransaction, CommitTransaction and RollbackTransaction.
//		Handling transactions yourself with these three new declares
//		can massively improve the speed of inserting and updating data.

// v1.0, 30 June 2005
// 	  -	Initial release

// Constants, Variables and Types ------------------------------------

Const SQLITE_OK          =  0   // Successful result
Const SQLITE_ERROR       =  1   // SQL error Or missing database
Const SQLITE_INTERNAL    =  2   // An internal logic error in SQLite
Const SQLITE_PERM        =  3   // Access permission denied
Const SQLITE_ABORT       =  4   // Callback routine requested an abort
Const SQLITE_BUSY        =  5   // The database file is locked
Const SQLITE_LOCKED      =  6   // A table in the database is locked
Const SQLITE_NOMEM       =  7   // A malloc() failed
Const SQLITE_READONLY    =  8   // Attempt To Write a readonly database
Const SQLITE_INTERRUPT   =  9   // Operation terminated by SQLITE_INTERRUPT()
Const SQLITE_IOERR       = 10   // Some kind of disk I/O error occurred
Const SQLITE_CORRUPT     = 11   // The database disk image is malformed
Const SQLITE_NOTFOUND    = 12   // (Internal Only) Table Or record Not found
Const SQLITE_FULL        = 13   // Insertion failed because database is full
Const SQLITE_CANTOPEN    = 14   // Unable To open the database file
Const SQLITE_PROTOCOL    = 15   // Database lock protocol error
Const SQLITE_EMPTY       = 16   // (Internal Only) Database table is empty
Const SQLITE_SCHEMA      = 17   // The database schema changed
Const SQLITE_TOOBIG      = 18   // Too much Data For one row of a table
Const SQLITE_CONSTRAINT  = 19   // Abort due To constraint violation
Const SQLITE_MISMATCH    = 20   // Data type mismatch
Const SQLITE_MISUSE      = 21   // Library used incorrectly
Const SQLITE_NOLFS       = 22   // Uses OS features Not supported on host
Const SQLITE_AUTH        = 23   // Authorization denied
Const SQLITE_ROW         = 100  // sqlite3_step() has another row ready
Const SQLITE_DONE        = 101

Const SQLITE_UNKNOWN  = 0
Const SQLITE_INTEGER  = 1
Const SQLITE_FLOAT    = 2
Const SQLITE_TEXT     = 3
Const SQLITE_STRING   = 3
Const SQLITE_BLOB     = 4
Const SQLITE_NULL     = 5

// declares ---------------------------------------------------------

// OpenDatabase opens or creates a database file.

// OpenMode values:
	Const DBOpenModeCreate = 0		// If database exists open it, otherwise create it, default
	Const DBOpenModeOpen = 1		// If database exists open it, otherwise do nothing
	Const DBOpenModeReplace = 2		// If database exists replace it with new database