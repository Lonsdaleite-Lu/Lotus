#ifndef __FY_WS2812B_H
#define __FY_WS2812B_H
 
// #include "fy_includes.h"
#include "stm8s.h"
 
 
// /*��ɫ�궨��*/								/*R G B*/
// #define	COLOR_LIGHTPINK						0xFFB6C1	//	ǳ�ۺ�
// #define	COLOR_PINK							0xFFC0CB	//	�ۺ�
// #define	COLOR_CRIMSON						0xDC143C	//	�ɺ�
// #define	COLOR_LAVENDERBLUSH					0xFFF0F5	//	����ĵ���ɫ
// #define	COLOR_PALEVIOLETRED					0xDB7093	//	�԰׵���������ɫ
// #define	COLOR_HOTPINK						0xFF69B4	//	����ķۺ�
// #define	COLOR_DEEPPINK						0xFF1493	//	���ɫ
// #define	COLOR_MEDIUMVIOLETRED				0xC71585	//	���е���������ɫ
// #define	COLOR_ORCHID						0xDA70D6	//	��������ɫ
// #define	COLOR_THISTLE						0xD8BFD8	//	��
// #define	COLOR_PLUM							0xDDA0DD	//	����
// #define	COLOR_VIOLET						0xEE82EE	//	������
// #define	COLOR_MAGENTA						0xFF00FF	//	���
// #define	COLOR_FUCHSIA						0xFF00FF	//	��������(�Ϻ�ɫ)
// #define	COLOR_DARKMAGENTA					0x8B008B	//	�����ɫ
// #define	COLOR_PURPLE						0x800080	//	��ɫ
// #define	COLOR_MEDIUMORCHID					0xBA55D3	//	���е�������
// #define	COLOR_DARKVOILET					0x9400D3	//	��������ɫ
// #define	COLOR_DARKORCHID					0x9932CC	//	��������
// #define	COLOR_INDIGO						0x4B0082	//	����
// #define	COLOR_BLUEVIOLET					0x8A2BE2	//	������������ɫ
// #define	COLOR_MEDIUMPURPLE					0x9370DB	//	���е���ɫ
// #define	COLOR_MEDIUMSLATEBLUE				0x7B68EE	//	���еİ��Ұ�����ɫ
// #define	COLOR_SLATEBLUE						0x6A5ACD	//	���Ұ�����ɫ
// #define	COLOR_DARKSLATEBLUE					0x483D8B	//	���Ұ�����ɫ
// #define	COLOR_LAVENDER						0xE6E6FA	//	Ѭ�²ݻ��ĵ���ɫ
// #define	COLOR_GHOSTWHITE					0xF8F8FF	//	����İ�ɫ
#define	COLOR_BLUE							0x0000FF	//	����
// #define	COLOR_MEDIUMBLUE					0x0000CD	//	���е���ɫ
// #define	COLOR_MIDNIGHTBLUE					0x191970	//	��ҹ����ɫ
// #define	COLOR_DARKBLUE						0x00008B	//	����ɫ
// #define	COLOR_NAVY							0x000080	//	������
// #define	COLOR_ROYALBLUE						0x4169E1	//	�ʼ���
// #define	COLOR_CORNFLOWERBLUE				0x6495ED	//	ʸ���յ���ɫ
// #define	COLOR_LIGHTSTEELBLUE				0xB0C4DE	//	������
// #define	COLOR_LIGHTSLATEGRAY				0x778899	//	ǳʯ���
// #define	COLOR_SLATEGRAY						0x708090	//	ʯ���
// #define	COLOR_DODERBLUE						0x1E90FF	//	������
// #define	COLOR_ALICEBLUE						0xF0F8FF	//	����˿��
// #define	COLOR_STEELBLUE						0x4682B4	//	����
// #define	COLOR_LIGHTSKYBLUE					0x87CEFA	//	����ɫ
// #define	COLOR_SKYBLUE						0x87CEEB	//	����ɫ
// #define	COLOR_DEEPSKYBLUE					0x00BFFF	//	������
// #define	COLOR_LIGHTBLUE						0xADD8E6	//	����
// #define	COLOR_POWDERBLUE					0xB0E0E6	//	��ҩ��
// #define	COLOR_CADETBLUE						0x5F9EA0	//	��У��
// #define	COLOR_AZURE							0xF0FFFF	//	ε��ɫ
// #define	COLOR_LIGHTCYAN						0xE1FFFF	//	����ɫ
// #define	COLOR_PALETURQUOISE					0xAFEEEE	//	�԰׵��̱�ʯ
// #define	COLOR_CYAN							0x00FFFF	//	��ɫ
// #define	COLOR_AQUA							0x00FFFF	//	ˮ��ɫ
// #define	COLOR_DARKTURQUOISE					0x00CED1	//	���̱�ʯ
// #define	COLOR_DARKSLATEGRAY					0x2F4F4F	//	��ʯ���
// #define	COLOR_DARKCYAN						0x008B8B	//	����ɫ
// #define	COLOR_TEAL							0x008080	//	ˮѼɫ
// #define	COLOR_MEDIUMTURQUOISE				0x48D1CC	//	���е��̱�ʯ
// #define	COLOR_LIGHTSEAGREEN					0x20B2AA	//	ǳ������
// #define	COLOR_TURQUOISE						0x40E0D0	//	�̱�ʯ
// #define	COLOR_AUQAMARIN						0x7FFFAA	//	����\����ɫ
// #define	COLOR_MEDIUMAQUAMARINE				0x00FA9A	//	���еı���ɫ
// #define	COLOR_MEDIUMSPRINGGREEN				0x00FF7F	//	���еĴ������ɫ
// #define	COLOR_MINTCREAM						0xF5FFFA	//	��������
// #define	COLOR_SPRINGGREEN					0x3CB371	//	�������ɫ
// #define	COLOR_SEAGREEN						0x2E8B57	//	������
// #define	COLOR_HONEYDEW						0xF0FFF0	//	����
// #define	COLOR_LIGHTGREEN					0x90EE90	//	����ɫ
// #define	COLOR_PALEGREEN						0x98FB98	//	�԰׵���ɫ
// #define	COLOR_DARKSEAGREEN					0x8FBC8F	//	�����
// #define	COLOR_LIMEGREEN						0x32CD32	//	�����
#define	COLOR_LIME							0x00FF00	//	���ɫ
// #define	COLOR_FORESTGREEN					0x228B22	//	ɭ����
#define	COLOR_GREEN							0x008000	//	����
// #define	COLOR_DARKGREEN						0x006400	//	����ɫ
// #define	COLOR_CHARTREUSE					0x7FFF00	//	���ؾ���
// #define	COLOR_LAWNGREEN						0x7CFC00	//	��ƺ��
// #define	COLOR_GREENYELLOW					0xADFF2F	//	�̻�ɫ
// #define	COLOR_OLIVEDRAB						0x556B2F	//	�������ɫ
// #define	COLOR_BEIGE							0xF5F5DC	//	��ɫ(ǳ��ɫ)
// #define	COLOR_LIGHTGOLDENRODYELLOW			0xFAFAD2	//	ǳ�������
// #define	COLOR_IVORY							0xFFFFF0	//	����
// #define	COLOR_LIGHTYELLOW					0xFFFFE0	//	ǳ��ɫ
// #define	COLOR_YELLOW						0xFFFF00	//	����
// #define	COLOR_OLIVE							0x808000	//	���
// #define	COLOR_DARKKHAKI						0xBDB76B	//	��䲼
// #define	COLOR_LEMONCHIFFON					0xFFFACD	//	���ʱ�ɴ
// #define	COLOR_PALEGODENROD					0xEEE8AA	//	��������
// #define	COLOR_KHAKI							0xF0E68C	//	���䲼
#define	COLOR_GOLD							0xFFD700	//	��
// #define	COLOR_CORNISLK						0xFFF8DC	//	����ɫ
// #define	COLOR_GOLDENROD						0xDAA520	//	������
// #define	COLOR_FLORALWHITE					0xFFFAF0	//	���İ�ɫ
// #define	COLOR_OLDLACE						0xFDF5E6	//	���δ�
// #define	COLOR_WHEAT							0xF5DEB3	//	С��ɫ
// #define	COLOR_MOCCASIN						0xFFE4B5	//	¹ƤЬ
// #define	COLOR_ORANGE						0xFFA500	//	��ɫ
// #define	COLOR_PAPAYAWHIP					0xFFEFD5	//	��ľ��
// #define	COLOR_BLANCHEDALMOND				0xFFEBCD	//	Ư�׵�����
// #define	COLOR_NAVAJOWHITE					0xFFDEAD	//	���߻���
// #define	COLOR_ANTIQUEWHITE					0xFAEBD7	//	�Ŵ��İ�ɫ
// #define	COLOR_TAN							0xD2B48C	//	ɹ��
// #define	COLOR_BRULYWOOD						0xDEB887	//	��ʵ����
// #define	COLOR_BISQUE						0xFFE4C4	//	(Ũ��)��֬,���ѵ�
// #define	COLOR_DARKORANGE					0xFF8C00	//	���ɫ
// #define	COLOR_LINEN							0xFAF0E6	//	���鲼
// #define	COLOR_PERU							0xCD853F	//	��³
// #define	COLOR_PEACHPUFF						0xFFDAB9	//	��ɫ
// #define	COLOR_SANDYBROWN					0xF4A460	//	ɳ��ɫ
// #define	COLOR_CHOCOLATE						0xD2691E	//	�ɿ���
// #define	COLOR_SADDLEBROWN					0x8B4513	//	������ɫ
// #define	COLOR_SEASHELL						0xFFF5EE	//	������
// #define	COLOR_SIENNA						0xA0522D	//	������ɫ
// #define	COLOR_LIGHTSALMON					0xFFA07A	//	ǳ����(����)ɫ
// #define	COLOR_CORAL							0xFF7F50	//	ɺ��
// #define	COLOR_ORANGERED						0xFF4500	//	�Ⱥ�ɫ
// #define	COLOR_DARKSALMON					0xE9967A	//	������(����)ɫ
// #define	COLOR_TOMATO						0xFF6347	//	����
// #define	COLOR_MISTYROSE						0xFFE4E1	//	����õ��
// #define	COLOR_SALMON						0xFA8072	//	����(����)ɫ
// #define	COLOR_SNOW							0xFFFAFA	//	ѩ
// #define	COLOR_LIGHTCORAL					0xF08080	//	��ɺ��ɫ
// #define	COLOR_ROSYBROWN						0xBC8F8F	//	õ����ɫ
// #define	COLOR_INDIANRED						0xCD5C5C	//	ӡ�Ⱥ�
// #define	COLOR_RED							0xFF0000	//	����
// #define	COLOR_BROWN							0xA52A2A	//	��ɫ
// #define	COLOR_FIREBRICK						0xB22222	//	�ͻ�ש
// #define	COLOR_DARKRED						0x8B0000	//	���ɫ
// #define	COLOR_MAROON						0x800000	//	��ɫ
#define	COLOR_WHITE							0xFFFFFF	//	����
// #define	COLOR_WHITESMOKE					0xF5F5F5	//	����
// #define	COLOR_GAINSBORO						0xDCDCDC	//	����ɫ
// #define	COLOR_LIGHTGREY						0xD3D3D3	//	ǳ��ɫ
// #define	COLOR_SILVER						0xC0C0C0	//	����ɫ
// #define	COLOR_DARKGRAY						0xA9A9A9	//	���ɫ
// #define	COLOR_GRAY							0x808080	//	��ɫ
// #define	COLOR_DIMGRAY						0x696969	//	�����Ļ�ɫ
#define	COLOR_BLACK							0x000000	//	����
#define COLOR_AMARANTH                  0xFF0A78
 
//�������ܺ���
void Ws2812b_Configuration(void);
void Ws2812b_Write(u32 color);
 
 
void RGB_Refresh(u32 color,u8 num);

#if 0  // Reduce flash size
void RGB_Cycle(u32 color,u8 num,u16 speed);
void RGB_Wave(u32 color,u8 num,u16 speed);
void RGB_Flash(u32 color,u8 num,u16 speed,u8 cnt);
#endif // #if 0  // Reduce flash size
 
#endif