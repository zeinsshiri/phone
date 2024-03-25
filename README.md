#phone
C实现的电话本管理系统

功能实现基于链表的增删查；
主要是拿大一时实现的一个C学习项目来练习buildsystem：这套makefile是参考linux内核项目的一个通用模板(参考韦东山老师)；可直接用于以后的开源以及商业项目
```
└─ phone
   ├─ build
   ├─ business process.png
   ├─ inc
   │  ├─ com
   │  │  ├─ create.h
   │  │  ├─ delete.h
   │  │  ├─ init.h
   │  │  ├─ list.h
   │  │  └─ search.h
   │  ├─ func
   │  │  └─ display.h
   │  ├─ phone.h
   │  └─ view
   │     └─ menu.h
   ├─ lib
   │  ├─ inc
   │  └─ libs
   ├─ LICENSE
   ├─ main.c
   ├─ Makefile
   ├─ Makefile.build
   ├─ out
   │  ├─ a.out
   │  └─ phone.1.0
   ├─ pathconfig.mk
   ├─ src
   │  ├─ com
   │  │  ├─ create.c
   │  │  ├─ delete.c
   │  │  ├─ init.c
   │  │  ├─ Makefile
   │  │  └─ search.c
   │  ├─ func
   │  │  ├─ display.c
   │  │  └─ Makefile
   │  └─ view
   │     ├─ Makefile
   │     └─ menu.c
   └─ test

```
