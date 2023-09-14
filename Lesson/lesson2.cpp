/*
`/`目录是整个系统的根目录 songjiaxin@SongJiaxin:/$
存放bin   home   lib64       mnt   run   sys  wslBMkmFe
boot  init   libx32      opt   sbin  tmp  wslNmkKkd
dev   lib    lost+found  proc  snap  usr  wslhGIebb
etc   lib32  media       root  srv   var  wslmDMfIi

其中的`home`目录存放用户列表目录, 打开一个子目录才真正进入家目录
songjiaxin@SongJiaxin:/$ cd home/songjiaxin
songjiaxin@SongJiaxin:~$

家目录以`~`表示
`cd ~`切换至/home/songjiaxin
songjiaxin@SongJiaxin:/$ cd ~
songjiaxin@SongJiaxin:~$

cd切换路径
模板: cd ECE2800J/Lesson
`cd dir1/dir1.1/dir1.1.2

root directory根目录
`cd /`
songjiaxin@SongJiaxin:~/Code/ECE2800J/Lesson$ cd /
songjiaxin@SongJiaxin:/$

current directory当前文件夹
`cd .`
songjiaxin@SongJiaxin:~/Code/ECE2800J/Lesson$ cd .
songjiaxin@SongJiaxin:~/Code/ECE2800J/Lesson$

parent directory
`cd ..`
songjiaxin@SongJiaxin:~/Code/ECE2800J/Lesson$ cd ..
songjiaxin@SongJiaxin:~/Code/ECE2800J$

返回上一次访问
`cd -`
songjiaxin@SongJiaxin:~/Code$  (第一个)   cd ~/Code/ECE2800J/Lesson  
songjiaxin@SongJiaxin:~/Code/ECE2800J/Lesson$  (当前) cd -
/home/songjiaxin/Code
songjiaxin@SongJiaxin:~/Code$ (返回上一次访问的)

`cd`只能访问文件夹, 不能访问单个文件
*/

/*
`ls` list
`ls`显示当前文件夹中所有子文件
songjiaxin@SongJiaxin:~/Code/ECE2800J$ ls
Lesson  Projects  README.md  hi  hi.cpp

`ls -l`
`-` is an option
`l` means long
songjiaxin@SongJiaxin:~/Code/ECE2800J$ ls -l
total 52
drwxr-xr-x 2 songjiaxin songjiaxin  4096 Sep 14 14:54 Lesson
drwxr-xr-x 2 songjiaxin songjiaxin  4096 Sep 14 14:54 Projects
-rw-r--r-- 1 songjiaxin songjiaxin    10 Sep 13 12:23 README.md
-rwxr-xr-x 1 songjiaxin songjiaxin 33240 Sep 14 14:16 hi
-rw-r--r-- 1 songjiaxin songjiaxin    98 Sep 14 14:23 hi.cpp
permission + number + owner + group + file size + modification time + file name
第一个字符代表是文件`-`or文件夹`d`
接下来3个字符代表permission from owner 
`r` read
`w` write
`x` execute
下面三个表示permission from group
最后三个表示permission from everyone else

`ls -a`
`a` means all
songjiaxin@SongJiaxin:~/Code/ECE2800J$ ls -a
.  ..  .git  .vscode  Lesson  Projects  README.md  hi  hi.cpp
songjiaxin@SongJiaxin:~/Code/ECE2800J$ ls
Lesson  Projects  README.md  hi  hi.cpp
列出带 `.`和`..`的 hidden file

`ls -la` 把`ls -l`和`ls -a`结合起来
*/

/*
Create directories: mkdir dir
songjiaxin@SongJiaxin:~/Code/ECE2800J$ ls
Lesson  Projects  README.md  hi.cpp
songjiaxin@SongJiaxin:~/Code/ECE2800J$ mkdir dir
songjiaxin@SongJiaxin:~/Code/ECE2800J$ ls
Lesson  Projects  README.md  dir  hi.cpp


Delete directories: rmdir dir
songjiaxin@SongJiaxin:~/Code/ECE2800J$ ls
Lesson  Projects  README.md  dir  hi.cpp
songjiaxin@SongJiaxin:~/Code/ECE2800J$ rmdir dir
songjiaxin@SongJiaxin:~/Code/ECE2800J$ ls
Lesson  Projects  README.md  hi.cpp
Can only remove empty directory

Create an empty file:  touch file
songjiaxin@SongJiaxin:~/Code/ECE2800J/Lesson$ ls
lesson2.cpp
songjiaxin@SongJiaxin:~/Code/ECE2800J/Lesson$ touch lesson3.cpp
songjiaxin@SongJiaxin:~/Code/ECE2800J/Lesson$ ls
lesson2.cpp  lesson3.cpp
songjiaxin@SongJiaxin:~/Code/ECE2800J/Lesson$

*/


/*
Copy Files/Directories
cp file1 file2 :  copy the content of file1 into file2

*/