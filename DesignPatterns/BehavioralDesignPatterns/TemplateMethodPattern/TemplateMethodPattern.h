/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	TemplateMethodPattern.h
* Description		: 	模版方法模式
						主要放模版方法，同时模版方法调用各个基本方法
						，所以也可以改名为TemplateMethod.c
						为统一名称,本文件也是模版方法模式的核心故还是
						命名为TemplateMethodPattern.c
									
* Created			: 	2017.07.12.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#ifndef TEMPLATE_METHOD_PATTERN_H
#define TEMPLATE_METHOD_PATTERN_H

typedef struct HummerModel//以制造悍马为例
{
	void (*Start)();
	void (*EngineBoom)();
	void (*Alarm)();
	void (*Stop)();	
}T_HummerModel;//抽象悍马模型


typedef struct HummerDemonstration//悍马模型演示
{//书上基本方法和模版方法合并，通过继承扩展(只覆写基本方法),C无super this无法如此使用,
	void (*Run)(T_HummerModel *i_ptHummerModel);//因此演示类和模型类不合并更好,如果合并则初始化时需要先有
}T_HummerDemonstration;//演示类和模型类的对象,最重要的是当模型对象更换时
//需要再次对演示类和模型类的合并累赋值，多次修改合并类(合并类里面有演示类也就是模版方法)
//即多次修改模版方法(也暴露了模版方法),显然这是不合适的(除非团队规定类中的模版方法不可覆写,但显然不适用于所有人)
//模版方法一般是固定的,是不允许覆写即修改的
//同时分为基本方法和模版方法两个类,也实现了基本方法扩展
//模版方法关闭修改(单例模式则无法修改)

//void HummerRun(T_HummerModel *i_ptHummerModel);
//#define newHummerDemonstration {HummerRun}
extern const T_HummerDemonstration g_tHummerDemonstration;//使用单例模式防止恶意修改固定逻辑的模版方法



void HummerH1ModelStart();
void HummerH1ModelEngineBoom();
void HummerH1ModelAlarm();
void HummerH1ModelStop();
#define newHummerH1Model {HummerH1ModelStart,HummerH1ModelEngineBoom,\
						    HummerH1ModelAlarm,HummerH1ModelStop}

void HummerH2ModelStart();
void HummerH2ModelEngineBoom();
void HummerH2ModelAlarm();
void HummerH2ModelStop();
#define newHummerH2Model {HummerH2ModelStart,HummerH2ModelEngineBoom,\
						    HummerH2ModelAlarm,HummerH2ModelStop}

#endif

