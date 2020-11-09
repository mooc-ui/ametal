/*******************************************************************************
*                                 AMetal
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2018 Guangzhou ZHIYUAN Electronics Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
*******************************************************************************/

/**
 * \file
 * \brief ZSL42x CLK 用户配置文件
 * \sa am_hwconf_zsl42x_clk.c
 *
 * \internal
 * \par Modification history
 * - 1.00 19-09-04  zp, first implementation
 * \endinternal
 */
#include "am_gpio.h"

#include "am_zsl42x_clk.h"
#include "hw/amhw_zsl42x_rcc.h"
#include "zsl42x_pin.h"
/**
 * \addtogroup am_if_src_hwconf_zsl42x_clk
 * \copydoc am_hwconf_zsl42x_clk.c
 * @{
 */
/** \brief CLK 平台初始化 */
static void __zsl42x_clk_plfm_init (void)
{
    /* 外部低速时钟 XTL 晶振驱动能力选择 */
    amhw_zsl42x_rcc_xtl_xtal_driver_set(AMHW_ZSL42x_XTL_XTAL_DRIVER_DEFAULT);

    /* 外部低速时钟 XTL 晶振振荡幅度的调整 */
    amhw_zsl42x_rcc_xtl_xtal_amplitude_set(
    AMHW_ZSL42x_XTL_XTAL_AMPLITUDE_BIG_DEFAULT);

    /* 外部低速时钟 XTL 稳定时间选择 */
    amhw_zsl42x_rcc_xtl_waittime_set(AMHW_ZSL42x_XTL_WAITTIME_16384);

    /* 外部低速时钟 XTL 使能 */
    amhw_zsl42x_rcc_set_start(0x5A5A);
    amhw_zsl42x_rcc_set_start(0xA5A5);
    amhw_zsl42x_rcc_xtl_enable();

    /* 等待外部低速时钟 XTL 稳定*/
    while(amhw_zsl42x_rcc_xtl_state_get() == AM_FALSE);

    /* 不使用 XTH，驱动能力设置为最弱 */
    amhw_zsl42x_rcc_xth_xtal_driver_set(AMHW_ZSL42x_XTH_XTAL_DRIVER_MIN);
}

/** \brief CLK 解平台初始化 */
static void __zsl42x_clk_plfm_deinit (void)
{
}

/*
 * PLL可以选择XTH晶振生成的时钟、XTH从管脚PF00输入的时钟、RCH时钟作为PLL时钟源
 * 还可以设置PLL的倍频系数，输出得到一个频率，从而可以用作系统时钟。
 *
 * 系统时钟源的选择主要有五种，  RCH  ---  内部高速时钟
 *                       XTH  ---  外部高速时钟
 *                       RCL  ---  内部低速时钟
 *                       XTL  ---  外部低速时钟
 *                       PLL  ---  内部PLL输出时钟  = PLL输入时钟 * PLL倍频系数
 *
 * 系统时钟源选定，则得到以下关系
 *
 * SYSCLK = 被选择的系统时钟源
 * HCLK   = SYSCLK / (2 ^ hclk_div)
 * PCLK   = HCLK   / (2 ^ pclk_div)
 *
 * \note 系统进入DeepSleep模式，高速时钟（RCH、XTH）自动关闭，
 *       需手动切换到低速时钟（RCL、XTL）作为系统时钟源。
 */
/** \brief CLK设备信息 */
static const am_zsl42x_clk_devinfo_t __g_clk_devinfo =
{
    /**
     * \brief XTH外部高速时钟晶振频率（Hz）
     */
    32000000,

    /**
     * \brief XTL外部低速时钟晶振频率（Hz）
     */
    32768,

    /**
     * \brief RCH内部高速时钟晶振频率（Hz）
     *
     * \note 频率选择    24M、 22.12M、16M、 8M或4M
     *       设置其他频率，将默认使用4M
     */
    AMHW_ZSL42x_RCH_FRE_4MHz,

    /**
     * \brief RCL内部低速时钟晶振频率（Hz）
     *
     * \note 频率选择    38.4k  或      32.768K
     *       设置其他频率，将默认使用38.4k
     */
    AMHW_ZSL42x_RCl_FRE_38400Hz,

    /** \brief
     *    PLL时钟源选择
     *    -# AMHW_ZSL42x_PLL_INPUT_FRE_SRC_XTH_XTAL : XTH晶振生成的时钟
     *    -# AMHW_ZSL42x_PLL_INPUT_FRE_SRC_XTH_PF00 : XTH从管脚PF00输入的时钟
     *    -# AMHW_ZSL42x_PLL_INPUT_FRE_SRC_RCH      : RCH时钟
     */
    AMHW_ZSL42x_PLL_INPUT_FRE_SRC_RCH,

    /**
     * \brief PLL 倍频系数，允许范围 2 ~ 12
     *        PLLOUT = PLLIN * pll_mul
     */
    12,

    /** \brief
     *    系统 时钟源选择
     *    -# AMHW_ZSL42x_SYSCLK_RCH : 内部高速时钟作为系统时钟
     *    -# AMHW_ZSL42x_SYSCLK_XTH : 外部高速时钟作为系统时钟
     *    -# AMHW_ZSL42x_SYSCLK_RCL : 内部低速时钟作为系统时钟
     *    -# AMHW_ZSL42x_SYSCLK_XTL ：  外部低速时钟作为系统时钟
     *    -# AMHW_ZSL42x_SYSCLK_PLL ： 内部PLL作为系统时钟
     */
    AMHW_ZSL42x_SYSCLK_PLL,

    /**
     * \brief HCLK分频系数，HCLK = SYSCLK / (2 ^ hclk_div)
     */
    0,

    /**
     * \brief PCLK分频系数，PCLK = HCLK / (2 ^ pclk_div)
     */
    1,

    /** \brief 平台初始化函数，配置引脚等工作 */
    __zsl42x_clk_plfm_init,

    /** \brief 平台解初始化函数 */
    __zsl42x_clk_plfm_deinit,
};

/** \brief 时钟设备实例 */
static am_zsl42x_clk_dev_t __g_clk_dev;

/**
 * \brief CLK 实例初始化，初始化系统时钟
 *
 * \retval AM_OK : 时钟成功初始化
 */
int am_zsl42x_clk_inst_init (void)
{
    return am_zsl42x_clk_init(&__g_clk_dev, &__g_clk_devinfo);
}

/**
 * @}
 */

/* end of file */
