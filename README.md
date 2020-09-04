# samp-delayed-kick

[![sampctl](https://img.shields.io/badge/sampctl-samp--advanced--kicks-2f2f2f.svg?style=for-the-badge)](https://github.com/Mergevos/samp-advanced-kicks)

<!--
Short description of your library, why it's useful, some examples, pictures or
videos. Link to your forum release thread too.

Remember: You can use "forumfmt" to convert this readme to forum BBCode!

What the sections below should be used for:

`## Installation`: Leave this section un-edited unless you have some specific
additional installation procedure.

`## Testing`: Whether your library is tested with a simple `main()` and `print`,
unit-tested, or demonstrated via prompting the player to connect, you should
include some basic information for users to try out your code in some way.

And finally, maintaining your version number`:

* Follow [Semantic Versioning](https://semver.org/)
* When you release a new version, update `VERSION` and `git tag` it
* Versioning is important for sampctl to use the version control features

Happy Pawning!
-->

## Installation

Simply install to your project:

```bash
sampctl package install Mergevos/samp-advanced-kicks
```

Include in your code and begin using the library:

```pawn
#include < advanced_kicks >
```
## Dependencies

IllidanS4 - PawnPlus

## Usage

<!--
Write your code documentation or examples here. If your library is documented in
the source code, direct users there. If not, list your API and describe it well
in this section. If your library is passive and has no API, simply omit this
section.
-->
To use this include, simply include it. There's no need for fixing kick and SendClientMessage(etc...) due to its problems.
There're a few functions. 
```pawn
Kick(playerid)
```  
Very famous function, already known.
```pawn
KickEx(playerid, string: reason[], bool:usecallback=false)  
```  
Sister function of famous Kick. You may now kick with reason, that's going to be send like a message  
```pawn
AdvancedKick(playerid, targetid, string: reason[], time);  
```  
This function will check whether the playerid or targetid are connected, returning a `OnPlayerKicked` callback. Allowing you to choose interval after which will player get kicked.  
```pawn
public OnlayerKicked(playerid, kickerid, string: reason[], time, responselevel)
```  
Allows player to choose and create their own response if the either player or target's not connected  

```pawn 
enum {
	KICK_SUCCESS = 1, // Kick's successful  
	KICK_KICKEROFFLINE, // Player offline, target id not player id  
	KICK_TARGETOFFLINE // Target offline, player id not kicker id  
}
```
Theese're the response levels used by a responselevel param in OnPlayerKicked callback


## Testing

<!--
Depending on whether your package is tested via in-game "demo tests" or
y_testing unit-tests, you should indicate to readers what to expect below here.
-->

To test, simply run the package:

```bash
sampctl package run
```
