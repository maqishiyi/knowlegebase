1. idea连接tomcat时出现无法复制配置文件的情况，如何处理
将tomcat软件包文件的使用者改为当前用户，使用命令chown.

2. idea导入新的pom文件时出现红色错误
maven 骨架生成项目速度慢的令人发指，都在Generating project in Batch mode等待，Idea状态显示栏还在不行runing，并没有卡死。查看debug信息发现，是maven获取archetype-catalog.xml导致。 跟网络状态也有关系，网络好的话可以导入成功。

3. idea mysql 5.7.24 jdbc驱动如何导入
idea连接mysql，view -> tool windows -> database -> mysql 
download mysql driver
test connection success