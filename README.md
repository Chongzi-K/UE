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