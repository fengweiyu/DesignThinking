/*****************************************************************************
* Copyright (C) 2017-2018 Hanson Yu  All rights reserved.
------------------------------------------------------------------------------
* File Module		: 	TemplateMethodPattern.h
* Description		: 	ģ�淽��ģʽ
						��Ҫ��ģ�淽����ͬʱģ�淽�����ø�����������
						������Ҳ���Ը���ΪTemplateMethod.c
						Ϊͳһ����,���ļ�Ҳ��ģ�淽��ģʽ�ĺ��Ĺʻ���
						����ΪTemplateMethodPattern.c
									
* Created			: 	2017.07.12.
* Author			: 	Yu Weifeng
* Function List 		: 	
* Last Modified 	: 	
* History			: 	
******************************************************************************/
#ifndef TEMPLATE_METHOD_PATTERN_H
#define TEMPLATE_METHOD_PATTERN_H

typedef struct HummerModel//�����캷��Ϊ��
{
	void (*Start)();
	void (*EngineBoom)();
	void (*Alarm)();
	void (*Stop)();	
}T_HummerModel;//������ģ��


typedef struct HummerDemonstration//����ģ����ʾ
{//���ϻ���������ģ�淽���ϲ���ͨ���̳���չ(ֻ��д��������),C��super this�޷����ʹ��,
	void (*Run)(T_HummerModel *i_ptHummerModel);//�����ʾ���ģ���಻�ϲ�����,����ϲ����ʼ��ʱ��Ҫ����
}T_HummerDemonstration;//��ʾ���ģ����Ķ���,����Ҫ���ǵ�ģ�Ͷ������ʱ
//��Ҫ�ٴζ���ʾ���ģ����ĺϲ��۸�ֵ������޸ĺϲ���(�ϲ�����������ʾ��Ҳ����ģ�淽��)
//������޸�ģ�淽��(Ҳ��¶��ģ�淽��),��Ȼ���ǲ����ʵ�(�����Ŷӹ涨���е�ģ�淽�����ɸ�д,����Ȼ��������������)
//ģ�淽��һ���ǹ̶���,�ǲ�����д���޸ĵ�
//ͬʱ��Ϊ����������ģ�淽��������,Ҳʵ���˻���������չ
//ģ�淽���ر��޸�(����ģʽ���޷��޸�)

//void HummerRun(T_HummerModel *i_ptHummerModel);
//#define newHummerDemonstration {HummerRun}
extern const T_HummerDemonstration g_tHummerDemonstration;//ʹ�õ���ģʽ��ֹ�����޸Ĺ̶��߼���ģ�淽��



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

