# UE

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