# C++控制台字符游戏 Terminal Character Game by C++

## Description
一个简单的控制台字符游戏，你可以自行修改代码以创建新的角色以及修改控制方式。
A simple terminal character game using C++. And you can modify it to make your own game.

由于使用了`conio.h`库，所以兼容性不怎么好，只能在Windows上运行。
Because it includes `conio.h` and 'windows.h`, it's compatibility is not good(On most windows system, it's ok).

## Instructions

1. 添加`xx.img`来添加新图片, 格式应当符合：首先是两个整数，分别代表高和宽，然后就是具体的字符内容，最后要以回车结尾。可以自行参考已有的.img文件。You can add new files named `xx.img` to add new images, and the content of the file should be as follows: Initially two integers, which present height and width of the image respectively, and then follows height lines, which is the main part of the image, and the file should end up with an enter.
2. 编辑`program.cpp`并修改其中的`Init()`, `Handle()`和`Update()`以添加新的角色和修改控制方式。You can edit the `program.cpp` to add new actors and modify the `Init()`, `Handle()` and `Update()` functions.
3. 输入`make`（要确保make工具已经在系统PATH中）。Finally, enter `make` in your terminal (make sure you have added the `make` tool to `PATH`).
4. 得到了所需要的`game.exe`。Then you will get `game.exe`, that is what we want.
5. 确保你的终端Terminal尺寸足够大，不然会闪屏。Before you run `game.exe` in your terminal, make sure your terminal's size is big enough to contain the screen, or there will a mess.
