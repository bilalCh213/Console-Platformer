# Console-Platformer

 Programmer Cheema's First Ever Game that is made in C++.
 Just compile the Main.cpp only, no need to link other cpp files.

 The text down below used to be at the top of Main.cpp.
 I am leaving it there just so you can see how dedicated I was in this 'text-video' game.

             *-*~ ConsolePlatformer ~*-*
            
                     ( A Game Concept )
                     
 - SORRY! THE PROJECT IS CLOSED! BUT THIS IS A KIND OF PRETTY FINE GAME CONCEPT! UNDERSTANDING IT WILL HELP YOU ALOT IN MAKING YOUR FIRST GAME! IT CONTAINS ALL BASIC GAME ELEMENTS!
 
 ______________________________________
 Present Features:- -------------------------------------------
 Version: 2.7f_b
 Dev Version: 2.8.1b_05
 
 (BUGS TO FIX:
 Graved enemies mixed up with non-graved enemies,
 
 Room changing changes the properties of enemies,
 
 Room changing may kills some of wrong enemies even not touched by player,
 
 Initial Enemy display glitch when changing room,
 
 Room changing may result in enemy passing the solid tiles,
 
 Zero HP without player hitting enemies give player some loots,
 
 Too much memory used by temp. decreases the performance,
 
 All player bullets not damaging alike
 )

 :::BETA:::
 ---------

 0.1: {Starting Beta: More Bullets Update} (Bug Fix Update)
-More types of bullets for player.
-Important Bug Fix: Player bullets stuck with enemy ones.

[ 0.1 MOVEMENT NOTE: No Advanced enemy AI but different enemies have different movement AI. For now, better enemies with their RandomMove AI. (The Advanced Enemy AI so, called is now, ConstantMove Enemy AI in which enemy always try to chase the player. It is still buggy now!) ]

0.2/0.3/0.4: {Better Bullets Update} (Include Bug Fix Updates)
-Some enemy types now, use Constant Movement AI. Still, it have some bugs!
-Improvements in player bullets by addition of factors: Bullet Speed, Rate Of Fire and Limitness of Bullets.

0.5/0.6: {Looting Update} (Include Bug Fix Updates)
-Bullets gets even more better! Some types have some specific properties.
-Enemies give you loots! For now, only SlowPow and bullets of all types.

0.7: {Unintended Movement Update} (Bug Fix Update)
-Added Platform Movement AI in which enemy remains on his platform while watching for player. Also fix more Constant Move AI.

[ 0.7 MOVEMENT NOTE: Bugs, bugs and bugs! It is realized so late that except for _empty finding factor and entity checking, no condition coorporates with enemy path finding! ]

0.8: {Movement Fix 1 Update} (Bug Fix Update)
-Many bug fixes of ConstantMove AI but PlatformMove AI have some bugs.

0.9: {Movement Fix 2 Update} (Bug Fix Update)
-Fixed almost all bugs of ConstantMove AI and PlatformMove AI. Now, walls are detected by enemies!
-Small status bar improvement.

1.0: {Player Passable Wall Update}
-A new tile set through which only player can pass!
-Level 4 rebuilded and level 5 built!

1.1: {Shop Preparin' 1 Update}
-Now, player gets gold/money from enemies!
-Status Bar double display!

1.2/1.3/1.4: {notSolid arrays Update} (Include Bug Fix Updates)
-Rewriting whole code for convenient notSolid checking.

[ 1.2/1.3/1.4 NOT_SOLID NOTE: This update do not introduce any new thing or feature accept some more bugs! But now, making notSolid tiles is very easy and convenient. Almost all bugs are related with Enemy Movement AI. (One Important Bug Recreation is: Enemies do not detect walls for now) ]

1.5/1.6: {Bug Shoot Out 2 Update} (Include Bug Fix Updates)
-Many many Movement AI bug fixes!
-Important Bug Fixes: Enemies do not detect walls for notSolid arrays.

1.7: {Shop Preparin' 2 Update}
-Now, an unfunctional shop has been added with its pointers running good.

[ 1.7 SHOP NOTE: First, it was decided to make an "Only Buy stuff" shop. But, later, it was decided to make a "Buy/Sell shop"! Therefore, extensive work on it is still required! ]

1.8: {Functional Shop Update}
  > 1.8.1: {Shop Preparin' 3 Update}
  -Now, you can buy Powers (slowPow) and Bullets from the shop and also, sadly, added scrolling in it.
  [ 1.8.1 SHOP NOTE: For the first time, version number gets more extensive. Also, we removed 'Slash and Join Version' method. E.G: Method used for notSolid arrays Update. Till 1.8f (1.8.2, and then, {final}1.8f), Shop will be completely added! ]
  > 1.8.2: {Shop Preparin' 4 Update} (Bug Fix Update)
  -Now, you can buy as well as sell all present game items from the shop and also, happily, removed scrolling from it!
  > 1.8f: {Shop Update} (Bug Fix Update)
  -Added Shop Place where you can do some trading. It will not be freely available but only to few levels.
  -Better Status Bar double display!

1.9: {Spikes Update} (Bug Fix Update)
-Added a new tile set called Spikes on which player lose HP in delay.
-Important Bug Fix: Dead Enemy top-left corner shooting!

2.0: {Start UI Update}
  > 2.0.1: {Start UI 1 Update}
  -Added a Simple Starting UI having very little animation but without menu (pointers). (Ofcourse, humble game should have a humble UI!)
  > 2.0.2: {Start UI 2 Update}
  -Better position of the title, now.
  -Added BAC Development Title screen. (Hehe! At last, some credit!)
  -You can skip the screen and animation as well.
  > 2.0.3: {Start UI 3 Update}
  -Now, we have a menu with working pointers! (Help is _empty for now! It is in our later tasks!)
  -UI looks almost complete!
  > 2.0f: {Start UI 4 Update} (Bug Fix Update)
  -Added a random charm on the starting menu.
  -Important Bug Fixes: Complication with ESC Menu and Start UI, Player Jump in the start of next level.

2.1: {Bug Fix in Beta 1 Update} (Bug Fix Update)
-Found as well as fixed many bugs!
-Fixed many bugs associated with shooting.
-Now, there is no shoot effect when hits an enemy.
-Degraded Status Bar to single display as double is not needed now. (or may be, in future as well)
-Important Bug Fixes: Enemy double damage, Wrong enemy position, Enemy going through, Bullet passes bullet (much reduced).
[ 2.1 BUG FIX NOTE: We put an update without even a smallest of feature change(There's a feature degrade!) . Previously, 0.8b is such an update. It only, contains bug fixes! Such updates are very important! Also, like Alpha, Beta will be ended when 3.0 version reaches. ]

2.2: {Generation Update}
  > 2.2.1: {Uncounted Score Update} (Bug Fix Update)
  -Added the last parameter of our game: Score. It is not counted and will only show 5 zeros. (Single Static Status Bar Display will remain in future)
  -Level 6 rebuilded. (Its all about jumping correct else go to killing grounds!)
  -Some bug fixes related to UI.
  > 2.2.2: {Regeneration 1 Update} (Bug Fix Update)
  -Added new Power: Regeneration that increases player's health when active! (You can get it by looting, not available in shop)
  -Important Bug Fix: Wrong initial value set for new game.
  -Fix more bugs (some related with looting) as well as, may introduced some old bugs!
  > 2.2.3: {Regeneration 2 Update} (Bug Fix Update)
  -Now, you can buy Regeneration in Shop! Same price as of SlowPow.
  -Important Bug Fixes: Wrong Enemies give Regen. Loot, Ghost Enemies.
  > 2.2f: {Regeneration 3 Update}
  -Now, health will not lost if regeneration is active and you are with enemy(no prox. damage) or on spikes!

2.3: {Better Combat Update}
  > 2.3.1: {Empty means Cycling Update} (Bug Fix Update)
  -When you shoot with _empty bullets or use power having zero value, the bullet or power type cycle once. If you repeat the action, it will reach the one with a value other than zero where it will no longer cycles!
  > 2.3.2: {Stabbing 1 Update} (Bug Fix Update)
  -Enemy near Player can be killed without using bullets(a bug fix) and with stabbing i.e health of enemy decreases by one when you tap attack key, repeatedly!
  > 2.3f: {Stabbing 2 Update} (Bug Fix Update)
  -Important Bug Fixes: Enemy keep moving even when it reaches the player, Enemies combine (Now, enemies only combine when jumps).

2.4: {Freak Aid Update}
  > 2.4.1: {BreakBrick Failure Update}
  -Added BreakBrick and REMOVED it! Sorry! Nothing here accept a lesson for us (read the note below!)
  [ 2.4.1 BREAKBRICK NOTE: Concept of BreakBrick is not hard! Its implementation is not hard! It worked good as well! But the problem is the scanning of blocks which take so much time or memory that it creates lag in the game! For the very first time, we encounter a serious performance issue which means that we must take every feature more carefully! It may be possible that we add breakbricks some time later! But for now, its a complete failure! ]
  > 2.4.2: {Usable Invulnerability 1 Update}
  -New Power: Invulnerability from the old vulnerablilty factor. (No looting and not a shop element)
  -Unlike other powers, invulnerability will be completely consumed at the start of every level! It can be prevented by turning it off at the very start of every next level!
  > 2.4.3: {Usable Invulnerablility 2 Update} (Bug Fix Update)
  -Now, you can get Invulnerability in shop and as a loot!
  -Some bugs fixes about invulnerability, level system and stabbing!
  > 2.4.4: {Power Aid 1 Update}
  -Now, when your power gets active, you will get an in-game indicator of that power! Flashing indicator means you have low power! ( It may look ugly to you so, we will put an option of power indicator and its position modification in future! )
  > 2.4f: {Power Aid 2 Update} (Bug Fix Update)
  -Added an input to switch off all active powers!
  -Important Bug Fix: Power Indicator not acting as notSolid tile.

2.5: {Connected Rooms Update}
  > 2.5.1: {Connected Rooms 1 Update}
  -Added Connected Rooms System: Now, levels can have multiple rooms connected to each other by 'hole in the wall'!
  -Operational for tiles and player for now!(not for shooting and enemies)
  > 2.5.2: {Connected Rooms 2 Update} (Bug Fix Update)
  -Made Connected Room System so convenient, accordant and bug free!
  -Now, shooting and enemies sync with the room you are standing in!
  > 2.5.3: {Connected Rooms 3 Update} (Bug Fix Update)
  -Level 6 rebuilded with Connected Rooms System! (Works pretty good!)
  -Important Bug Fix: Get loots when changing room.
  > 2.5f: {Connected Rooms 4 Update} (Bug Fix Update)
  -Level 7 builded. (Ofcourse, this as well as all next levels will be with Connected Rooms System! )
  -Important Bug Fix: Wrong Initial Enemy Position when changing room.

2.6: {Killer Update}
  > 2.6.1: {Nuke 1 Update}
  -New Power: Nuke which destructs health of all enemies on the screen! (Done with looting but yet, not a shop element)
  > 2.6.2: {Nuke 2 Update} (Bug Fix Update)
  -Now, you can buy expensive Nukes in shop! (Added bad little shop scrolling)
  -Level 8 builded.
  > 2.6f: {Jump-Assassination Update}
  -Added Jump-Assassination Skill by which you can sharply damage your enemy by jumping and reaching beneath it! (If you use it, game will get much easier)

2.7: {Grave Update}
  > 2.7.1: {Grave 1 Update}
  -Added Grave(notSolid) Tile Set from which new enemies arises after regular intervals! (Very buggy, now!)
  > 2.7f: {Grave 2 + Better Rooms Update} (Bug Fix Update)
  -Fixed many bugs related with Grave. (Still Buggy!)
  -Now, total number of enemies per level is the total number of enemies per room of a level! (Buggy!)
  -Now, a room saves the position, HP and count of enemies(non-graved as well as graved enemies). (Buggy!)
  -Important Bug Fix: Wrong room when playing after death.
  [ 2.7f BETTER ROOMS NOTE: Yes! This is actually, what we want! Better Rooms... But this caused a headache! Now, we have introduced some of very nasty enemy spawning and setting bugs! Also, the performance is quite decreased and seriously, need optimizations! It will take time to fix all things! But we would not step back like we did for BreakBrick Tile Set! ]

 - SORRY! THE PROJECT IS CLOSED! BUT THIS IS A KIND OF UNCOMPLETE GAME CONCEPT! UNDERSTANDING IT WILL HELP YOU ALOT IN MAKING YOUR FIRST GAME! IT CONTAINS ALL BASIC GAME ELEMENTS!

2.8: {Bug Fix in Beta 2 Update} (Bug Fix Update)
  > 2.8.1: {Bug Fix in Beta 2 - 1 Update} (Bug Fix Update)
  > 2.8.2: {Bug Fix in Beta 2 - 2 Update} (Bug Fix Update)
  > 2.8f: {Bug Fix in Beta 2 - 3 Update} (Bug Fix Update)

2.9: {Teleporter Update}
  > 2.9.1: {Teleporter 1 Update}

  > 2.9.2: {Teleporter 2 Update}

  > 2.9f: {Teleporter 3 Update}

3.0: {Beta Final: Assisting the Future Update}
  > 3.0.1: {Tutorial 1 Update}

  > 3.0.2: {Tutorial 2 Update}

  > 3.0.3: {Assistive UI 1 Update}

  > 3.0f: {Assistive UI 2 Update}



 ______________________________________

 ______________________________________
 Bugs:- -------------------------------------------
 -Enemies combine when jump at the same time.
 
 -Initial display glitch of dead enemies when changing room. (Will be fixed in 2.8b)
 
 -Enemy passes through solid blocks when refreshing rooms. (More Info: May be due to VERY nearby enemies) (Will be fixed in 2.8b)
 
 -Little Shop Scrolling. (Will be fixed in 3.0b)
 
 -Non-graved enemies spawn again when changing room.
   -------------------------------------------

 ______________________________________
 Features from Bugs:-
 (Features that can be removed in future) -------------------------------------------
 0.10a Bug:
 -Sometimes, player bullet passes straight away through the enemy without harming it.
 ( This was the bug as it sometimes caused crashes but now it is 'Cut Through' feature and this causes damage more than normal. It is much reduced. )
 
 0.4b Bug:
 -Sometimes, enemy bullets destroyed by player's bullets on its way.
 ( This is good because this is the only way to stop enemy bullets from reaching you other than Jump Dodge, SlowPow, Permeable Wall Cover and Invulnerable Factor. It is much reduced. )
 -------------------------------------------

 ______________________________________
 Upcoming Features:- (With Version mentioned) -------------------------------------------
 
 BETA:
 
 2.8b: {Bug Fix in Beta 2 Update} [Ext.]
 (includes bug fixing mostly related to connected rooms system and grave)
 
 2.9b: [Ext.]
 -{New Tile Set: Teleporter(NotSolid)} which teleports you to other position of the same level.
 -Level 10 and 11 build!
 
 3.0b: [Ext.]
 -3(12,13,14) more levels containing Grave and Teleporter.
 -Perfornance Improvement by setting eNumb, the max limit of no. of enemies per room instead of per level.
 -Some UI changes and Bug Fixing!
 
 STABLE:
 
 1.0: [Ext.]
 -More better and assistive UI. Example: In main menu, at bottom-left, "Press w or s to select".
 -Settings to modify:
    >Controls
    >In-Game Indicators
    >Game Difficulty
       *Effects hpSet.
       *Effects Enemy bullet damage to player.
       *Effects looting of enemy.
    >Amount Of Chances
       *First make a Chance System.
    >Theme (Change of Display of Tile Sets)
 
 2.0: [Ext.]
 -Score system:
   >Time consuming decreases score!
   >Shooting decreases score!
   >Killing enemy increases score!
   >Completing level increases score!
   >After a level ends, display level score!
   >After all level ends, display all levels individual and total score!
 
 3.0: [Ext.]
 -{New Tile Set: Switch} and {Another New Tile Set: Powered Gate}. Turning switches on or off changes the position of powered gates to horizontal or vertical.
 -{New Tile Set: BreakBricks} which breaks when player steps on it (without performance issues i.e block scanning).
 -5(15,16,17,18,19) more levels containing switch, powered gates and breakbricks.
 
 4.0: [Ext.]
 -Obtain more kinds of Powers, Skills and Bullets as you progress through the levels! (They are hidden or locked for previous levels)
 -Help Menu for Complete Instructions
   >Will have multiple options in it.
   >Will NOT show hidden or locked things.
 -5(20,21,22,23,24) more levels.
 
 5.0: [Ext.]
 -Final Level is a Boss Level: make a destructive static but animated robot that fires terribly after some intervals.
 A kind of image:
           *-----*
          (  +   ×  )
          (  ----  )
       ——————
       |  | |    v   | |  |
       ^^^|    v   | ^^^
            ------
            
 -------------------------------------------

 ______________________________________
 Most wanted feature but also not possible (by standard libraries):- -------------------------------------------
 -Mechanism to save the game and load it on next startup.
 
 -Input to work only at the time of working, not before.
 -------------------------------------------
 
 DEV ONLY:-
 ******************************************
 >>>How to make/modify/add a level?
 ******************************************
 -Change/Check 'maxLv' in 'Main.cpp'.
 
 -Modify/Add in 'room' vars, the room number, total rooms and, a room for shop and door (Connected Room System).

 -Modify/Add in 'doorlv_' vars, the position of door, in 'Main.cpp'.
 
 -Modify/Add in 'shoplv_' vars, the position of shop, in 'Main.cpp' (not necessary).

 -Modify function 'customTileSet()' in 'CustomTileSet.cpp' where you set tiles in the level and rooms.

 -Modify function 'notSolidTileSet()' for positions of notSolid tiles in the level and rooms (exception to doors and shops) which is in 'customTileSet.cpp'.
 
 -Modify function 'plSet()' in 'PlayerSet.cpp' where you set initial position of player in the level.

 -Modify function 'eSet()' in 'EnemySet.cpp' where you set initial and variable positions of enemies in the level.
 
 ******************************************
 >>>How to make/modify/add (a type of) enemy?
 ******************************************
 -Check/Change all enemy type or 'eType' vars in 'Main.cpp' (For amount of enemies, check single 'eNumb' variable only).
 
 -Mention enemy type in the variable position set in function 'eSet()' (Level modification) in 'EnemySet.cpp'.
 
 ******************************************
 >>>How to make/modify/add any kind of tile?
 ******************************************
 -Declare the tile with its display in 'Main.cpp' (If its notSolid, put it in notSolid string array and increase its total number by 1).
 
 -Make passing through properties in 'GameCont.cpp' at functions 'emptyAtFactor()' and 'e_emptyAtFactor()'.
 
 -Can make more properties by the relationship with other variables.
 
 -Put it through function 'customTileSet()' [or if notSolid then, 'notSolidTileSet()'] (Level modification) in 'CustomTileSet.cpp'.

***Exception to doors and shops
================================
