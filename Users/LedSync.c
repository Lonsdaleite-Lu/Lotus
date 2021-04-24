/**
  ******************************************************************************
  * @file    LedSync.c
  * @author  Albert
  * @version V0.0.0
  * @date    2021-4
  * @brief   This file is used to synchronize LEDs and audio.
  ******************************************************************************
**/


/** include  ------------------------------------------------------------------*/

#include "LedSync.h"
#include "Stm8s.h"
#include "timebase.h"
#include "WS2812B.h"
#include "ColorConvert.h"
#include <math.h>

/** Private typedef -----------------------------------------------------------*/

typedef enum _tColorCycle
{
    eLSCC_Cycle_1,
    eLSCC_Cycle_2,
    eLSCC_Cycle_3,
    eLSCC_Cycle_4,
    eLSCC_Cycle_5,
    eLSCC_TOTAL_CYCLES
}tColorCycle;

typedef enum _tWordsCycle
{
    eLSWC_Cycle_1,
    eLSWC_Cycle_2,
    eLSWC_Cycle_3,
    eLSWC_Cycle_4,
    eLSWC_TOTAL_CYCLES
}tWordsCycle;


/** Private define ------------------------------------------------------------*/

#define COLOR_CYCLE_TABLE COLOR_WHITE,COLOR_AMARANTH,COLOR_BLUE,COLOR_GOLD,COLOR_LIME

/** Private variables ---------------------------------------------------------*/

const uint32_t ColorCycleTable[eLSCC_TOTAL_CYCLES] = {COLOR_CYCLE_TABLE};

static bool bStartColorCycle = false;
static bool bStartColorCycleReady = false;
static uint16_t uiCountColorCycle;

static bool bUpdateWordsCycle = false;
static uint16_t uiCountWordsCycle;

static tColor_RGB s_rgb;
static tColor_HSV s_hsv;
static tColor_HSV s_hsv_bak;

// static uint8_t r;
// static uint8_t g;
// static uint8_t b;

// static float h;
// static float s;
// static float v;

// static float h_bak;
// static float s_bak;
// static float v_bak;

static uint16_t count = 0;

static bool bLightIncrease = false;
static bool bLightDecrease = false;

static tWordsCycle eWordsCycle = eLSWC_TOTAL_CYCLES;
static tColorCycle eColorCycle;

static float k; //[eLSWC_TOTAL_CYCLES];
static const float WordsCycleTimeBrighten[eLSWC_TOTAL_CYCLES] = {10.5,10.7,10.0,10.0};  // unit: sec
static const float WordsCycleTimeDim[eLSWC_TOTAL_CYCLES] = {0.1,0.1,0.1,0.1};       // unit: sec

static const uint8_t  ucColorCycleTimeIdle[eLSCC_TOTAL_CYCLES] = {50,50,30,30,40};            // unit: 0.01sec, e.g. 50 means 0.5s



/** export variables ----------------------------------------------------------*/


/** Private function prototypes -----------------------------------------------*/

static void LS_Calculat_k(float v,tWordsCycle eCycle);
static void LS_LedOff(void);


/** Private functions ---------------------------------------------------------*/

static void LS_Calculat_k(float v,tWordsCycle eCycle)
{
    //float WordsCycleTime[eCycle]
    k = (float)(v/sqrt(WordsCycleTimeBrighten[eCycle]));
}

static void LS_LedOff(void)
{
    RGB_Refresh(COLOR_BLACK, MAX_LED_NUMBER);
}

/** Export functions -- -------------------------------------------------------*/

void LS_Init(void)
{
    s_rgb.r = 255;
    s_rgb.g = 10;
    s_rgb.b = 120;
    rgb2hsv(&s_rgb,&s_hsv);
    // rgb2hsv(&s_rgb,&s_hsv_bak);
    s_hsv_bak = s_hsv;

    bLightDecrease = true;
}

void LS_UpdateColor(const uint32_t ulColor)
{
    s_rgb.r = (uint8_t)(ulColor >> 16);
    s_rgb.g = (uint8_t)(ulColor >> 8);
    s_rgb.b = (uint8_t)(ulColor);

    rgb2hsv(&s_rgb,&s_hsv);
    s_hsv_bak = s_hsv;
}

void LS_HandleColorCycle(void)
{
    if (bStartColorCycle == true)
    {
        if(TimeBase_Get10msSystemTimeDelta())
        {
            uiCountColorCycle++;
            uiCountWordsCycle++;
        }

        switch (eColorCycle)
        {
            case eLSCC_Cycle_1 :
            case eLSCC_Cycle_2 :
            case eLSCC_Cycle_3 :
            case eLSCC_Cycle_4 :
            case eLSCC_Cycle_5 :
            default:
                nop();

            if (eColorCycle < eLSCC_TOTAL_CYCLES)
            {
                if (uiCountWordsCycle == ucColorCycleTimeIdle[eWordsCycle])
                {
                    LS_UpdateColor(ColorCycleTable[eColorCycle]);
                    LS_Calculat_k(s_hsv_bak.v,eWordsCycle);
                    eWordsCycle = eLSWC_Cycle_1;

                    bLightIncrease = true;
                }
            }
            else
            {
                // end 
            }
            
        
        }

        // switch (eWordsCycle)
        // {
        //     case eLSWC_Cycle_1 :
        //     {
        //         // if (uiCountWordsCycle == ucColorCycleTimeIdle[eWordsCycle])
        //         // {
        //         //     LS_UpdateColor(COLOR_WHITE);
        //         //     LS_Calculat_k(s_hsv_bak.v,eWordsCycle);

        //         //     bLightIncrease = true;
        //         // }
        //     }
        //     break;
        //     case eLSWC_Cycle_2 :
        //     case eLSWC_Cycle_3 :
        //     case eLSWC_Cycle_4 :
        //     default:
        //         nop();
        // }
    
        ColorWave();


        if (bUpdateWordsCycle == true)
        {
            eWordsCycle++;

            if (eWordsCycle < eLSWC_TOTAL_CYCLES)
            {
                LS_Calculat_k(s_hsv_bak.v,eWordsCycle);
                // uiCountWordsCycle = 0;

                bLightIncrease = true;
            }

            else
            {
                // update color cycle
                uiCountWordsCycle = 0;
                eColorCycle++;
            }
            bUpdateWordsCycle = false;
        }


    }
    else
    {
        if (bStartColorCycleReady == false)
        {
            // LS_UpdateColor(COLOR_RED_AMARANTH);
            uiCountColorCycle = 0;
            uiCountWordsCycle = 0;
            LS_LedOff();

            bStartColorCycleReady = true;
        }
        else
        {
            // bStartColorCycle = true;
        }
    }
    
}



void ColorWave(void)
{
    bool bUpdateColor = false;

    if(TimeBase_Get10msSystemTimeDelta())
    {
        count++;
        float t = (float) (count/100.0);

        if(bLightIncrease == true)
        {
            // 
            // TODO: add flags for scheme changes
            // For Scheme 1:
            s_hsv.v = k*sqrt(t);

            // max v limitation
            if( s_hsv.v > s_hsv_bak.v )
            {
                s_hsv.v = s_hsv_bak.v;
            }

            // max time limitation
            if(t >= WordsCycleTimeBrighten[eWordsCycle])
            {
                t = WordsCycleTimeBrighten[eWordsCycle];

                s_hsv.v = s_hsv_bak.v;

                bLightDecrease = true;
                bLightIncrease = false;

                count = 0;
            }

            // For Scheme 2:
        }

        if( bLightDecrease == true)
        {
            // TODO: add flags for scheme changes
            // For Scheme 1:
            if(t < WordsCycleTimeDim[eWordsCycle])
            {
                s_hsv.v = (float)(t / WordsCycleTimeDim[eWordsCycle]) * s_hsv_bak.v;
            }
            else
            {
                s_hsv.v = 0;
                count = 0;

                bLightDecrease = false;

                bUpdateWordsCycle = true;
            }
            

            // if( s_hsv.v >= (float)0.2 )
            // {
            //     s_hsv.v -= (float)0.2;
            // }
            // else
            // {
            //     s_hsv.v = 0;
            //     count = 0;
                
            //     bLightDecrease = false;
                // bLightIncrease = true;
                
                // LS_Calculat_k(s_hsv_bak.v,eLSWC_Cycle_1);
            // }

            // For Scheme 2:

        }

        // v_bak -= (float)0.01;
        hsv2rgb(&s_hsv, &s_rgb);
        bUpdateColor = true;
    }

    if (bUpdateColor == true)
    {
        uint32_t ulRGB = 0;
        // ulRGB = (((uint32_t)(r)) << 16) | ((uint32_t)(g << 8)) | ((uint32_t)(b));

        ulRGB |= s_rgb.r;
        ulRGB = (ulRGB << 8) | s_rgb.g;
        ulRGB = (ulRGB << 8) | s_rgb.b;

        RGB_Refresh(ulRGB, MAX_LED_NUMBER);
    }
}


bool LS_StartColorCycle(void)
{
    bool bReturn = false;

    if (bStartColorCycleReady == true)
    {
        bStartColorCycle = true;
        bReturn = true;
    }

    return bReturn;
}


