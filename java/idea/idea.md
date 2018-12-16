1. idea连接tomcat时出现无法复制配置文件的情况，如何处理
将tomcat软件包文件的使用者改为当前用户，使用命令chown.

2. idea导入新的pom文件时出现红色错误
maven 骨架生成项目速度慢的令人发指，都在Generating project in Batch mode等待，Idea状态显示栏还在不行runing，并没有卡死。查看debug信息发现，是maven获取archetype-catalog.xml导致。 跟网络状态也有关系，网络好的话可以导入成功。

3. idea mysql 5.7.24 jdbc驱动如何导入
idea连接mysql，view -> tool windows -> database -> mysql 
download mysql driver
test connection success

4. http://mybatis.org/dtd/mybatis-generator-config_1_0.dtd   uri is not registerd.
按照提示,在File -> Settings ...Schemas and DTDs中将"http://mybatis.org/dtd/mybatis-generator-config_1_0.dtd"复制进去即可

5. mybatis generator配置
驱动与IP地址要填写准确，创建和更新时间调用数据库内部函数now()

6. mybatic plugin配置
