1. applicationContext-datasource.xml 配置时读不到datasource.properties里的配置
如果用intelij的话，把resources的目录mark一下，右键resources->mark directry as ->sources root

2. IDEA applicationContext-datasource.xml 无法读取datasource.properties的值cannot resolve property key

MVC application context in module mmall.File is included in 4 contexts.
将MVC application context该为Local File.

3. maven项目无法连接数据库
在pom.xml中配置数据库驱动版本，maven reimport自动下载数据库驱动jar包，就可以正常连接数据库了
