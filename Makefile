CROSS_COMPILE = # 交叉编译工具头,如：arm-linux-gnueabihf-
AS      = $(CROSS_COMPILE)as # 把汇编文件生成目标文件
LD      = $(CROSS_COMPILE)ld # 链接器，为前面生成的目标代码分配地址空间，将多个目标文件链接成一个库或者一个可执行文件
CC      = $(CROSS_COMPILE)gcc # 编译器，对 C 源文件进行编译处理，生成汇编文件
CPP    = $(CC) -E            #C 预处理器，用于执行 C 文件的预处理操作
AR      = $(CROSS_COMPILE)ar # 打包器，用于库操作，可以通过该工具从一个库中删除或则增加目标代码模块
NM     = $(CROSS_COMPILE)nm # 查看静态库文件中的符号表
 
STRIP      = $(CROSS_COMPILE)strip # 指定了剥离工具，用于去除可执行文件或库文件中的调试信息和符号表等内容，以减小文件大小
OBJCOPY  = $(CROSS_COMPILE)objcopy # 复指定了目标文件复制工具，用于将一个目标文件的内容复制到另一个文件中，通常用于不同格式、不同类型的文件之间的转换。
OBJDUMP = $(CROSS_COMPILE)objdump # 指定了目标文件反汇编工具，用于查看静态库或动态库的签名方法、符号表信息以及反汇编代码。
 
# 共享到sub-Makefile
export AS LD CC CPP AR NM
export STRIP OBJCOPY OBJDUMP
 
# -Wall ： 允许发出 GCC 提供的所有有用的报警信息
# -O2 : “-On”优化等级
# -g : 在可执行程序中包含标准调试信息
# -I : 指定头文件路径（可多个）
CFLAGS := -Wall -O3 -g
CFLAGS += -I $(shell pwd)/include
 
# LDFLAGS是告诉链接器从哪里寻找库文件，这在本Makefile是链接最后应用程序时的链接选项。
LDFLAGS := 
 
# 共享到sub-Makefile
export CFLAGS LDFLAGS
 
# 顶层路径
TOPDIR := $(shell pwd)#调用shell的pwd程序获得
export TOPDIR

#程序输出路径
OUTPUTDIR := ./out
 
# 最终目标可执行文件名
TARGET := phone

#软件版本
APPVERSION = 1.0
 
# 本次整个编译需要源 文件 和 目录
# 这里的“obj-y”是自己定义的一个格式，和“STRIP”这些一样，*但是 一般内核会搜集 ”obj-”的变量*
# obj-y += main.o # 需要把当前目录下的 main.c 编进程序里
# obj-y += sub.o # 需要把当前目录下的 sub.c 编进程序里
# 需要进入 subdir 这个子目录去寻找文件来编进程序里，具体是哪些文件，由 subdir 目录下的 Makefile 决定。
obj-y += src/com/\
src/func/\
src/view/

obj-y += $(patsubst %.c,%.o,$(shell ls *.c))

# 第一个目标
all : start_recursive_build $(TARGET)
	@echo $(TARGET) "has been built !"
# 处理第一个依赖，**转到 Makefile.build 执行**
start_recursive_build:
	make -C ./ -f $(TOPDIR)/Makefile.build

# 处理最终目标，把前期处理得出的 built-in.o 用上
$(TARGET) : built-in.o
	$(CC) -o $(OUTPUTDIR)/$(TARGET).$(APPVERSION) built-in.o $(LDFLAGS)
    
# 清理
clean:
	rm -f $(shell find -name "*.o")
	rm -f $(TARGET)
    
# 彻底清理
distclean:
	rm -f $(shell find -name "*.o")
	rm -f $(shell find -name "*.d")
	rm -f $(TARGET)
