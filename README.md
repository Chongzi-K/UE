# UE

----------
20221019-1

1、上传202204的一个练习项目，内容包括：

   EQS使用与AI行为树练习 
   
   简单实用的攀爬/翻越系统
   
   ActorComponent实现的简单的拾取和背包系统
   


20220916-1

修正:

1、添加了Explosive对Enemy的响应。

2、Explosive 与 Enemy-AgroSphere 不再产生碰撞响应，引起错误的触发。

3、修正Enemy_AttackEnd() ，使Enemy攻击后不再进行错误的等待

----------
20220917-1

修正：

1、修正了Main-CombatTarget不会自动更新的错误，现在Main-CombatTarget会指向进入CombatSphere且离玩家最近的Enemy

----------
20220917-2

添加：

1、修改相关类使得可以基于PickUp类实现药剂(Potion)蓝图

----------
20220917-3

添加：

1、完善SpawnVolume，并完成EnemySpawnVolume_BP 与 PickUpSpawnVolume_BP

----------
20220917-4

新增：

1、新增 LevelTransitionVolume，用于进行Level之间的移动

----------
20220917-5

新增：

1、初见 SaveGame 类，实现一些简单小功能

----------
20220917-6

添加：

1、补全SaveGame的功能，实现所持武器的保存与载入

----------
20220917-7

添加：

1、新增暂停菜单，但功能并未实现

----------
20220918-1

添加：

1、添加PauseMenu进出动画，人物在bPauseMenuVisible=1时不可操作

----------
20220918-2

添加：

1、完善Pausemenu功能

2、完善LevelTransitionVolume功能

----------
20220918-3

新建UE_NET项目，用于摸索UE4网络部分内容

----------
20220921-1

新增：

1、新增 BlowingMachine，用于实现风场+推力
