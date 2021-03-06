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
 * \brief ZLG116 SPI 用户配置文件
 * \sa am_hwconf_zlg116_spi_dma.c
 *
 * \internal
 * \par Modification history
 * - 1.00 15-10-23  ari, first implementation.
 * \endinternal
 */

#include "ametal.h"
#include "am_zlg116.h"
#include "am_zlg_spi_dma.h"
#include "am_gpio.h"
#include "hw/amhw_zlg_spi.h"
#include "am_clk.h"
#include "zlg116_dma_chan.h"

/**
 * \addtogroup am_if_src_hwconf_zlg116_spi_dma
 * \copydoc am_hwconf_zlg116_spi_dma.c
 * @{
 */

/** \brief SPI1 平台初始化 */
static void __zlg116_plfm_spi1_dma_init (void)
{
    am_gpio_pin_cfg(__SPI1_SCK,  __GPIO_SPI1_SCK);
    am_gpio_pin_cfg(__SPI1_MISO, __GPIO_SPI1_MISO);
    am_gpio_pin_cfg(__SPI1_MOSI, __GPIO_SPI1_MOSI);

    am_clk_enable(CLK_SPI1);
}

/** \brief 解除SPI1 平台初始化 */
static void __zlg116_plfm_spi1_dma_deinit (void)
{

    /* 释放引脚为输入模式 */
    am_gpio_pin_cfg(__SPI1_SCK,  AM_GPIO_INPUT);
    am_gpio_pin_cfg(__SPI1_MISO, AM_GPIO_INPUT);
    am_gpio_pin_cfg(__SPI1_MOSI, AM_GPIO_INPUT);

    am_clk_disable(CLK_SPI1);
}

/**
 * \brief SPI1 设备信息
 */
const  struct am_zlg_spi_dma_devinfo  __g_spi1_dma_devinfo = {
    ZLG116_SPI1_BASE,               /**< \brief SPI1寄存器指针 */
    CLK_SPI1,                       /**< \brief 时钟ID号 */
    INUM_SPI1,                      /**< \brief SPI1中断号 */
    0,                              /**< \brief SPI1配置标识 */
    DMA_CHAN_SPI1_TX,
    DMA_CHAN_SPI1_RX,
    __zlg116_plfm_spi1_dma_init,    /**< \brief SPI1平台初始化函数 */
    __zlg116_plfm_spi1_dma_deinit   /**< \brief SPI1平台解初始化函数 */
};

/** \brief SPI1 设备实例 */
static am_zlg_spi_dma_dev_t __g_spi1_dma_dev;

/** \brief SPI1 实例初始化，获得SPI标准服务句柄 */
am_spi_handle_t am_zlg116_spi1_dma_inst_init (void)
{
    return am_zlg_spi_dma_init(&__g_spi1_dma_dev, &__g_spi1_dma_devinfo);
}

/** \brief SPI1 实例解初始化 */
void am_zlg116_spi1_dma_inst_deinit (am_spi_handle_t handle)
{
    am_zlg_spi_dma_deinit(handle);
}

#if 0
/** \brief SPI2 平台初始化 */
static void __zlg116_plfm_spi2_dma_init (void)
{
    am_gpio_pin_cfg(PIOB_13, PIOB_13_SPI2_MISO | PIOB_13_INPUT_FLOAT);
    am_gpio_pin_cfg(PIOB_14, PIOB_14_SPI2_MOSI | PIOB_14_AF_PP);
    am_gpio_pin_cfg(PIOB_15, PIOB_15_SPI2_SCK  | PIOB_15_AF_PP);

    am_clk_enable(CLK_SPI2);
}

/** \brief 解除 SPI2 平台初始化 */
static void __zlg116_plfm_spi2_dma_deinit (void)
{
    am_gpio_pin_cfg(PIOB_13, AM_GPIO_INPUT);
    am_gpio_pin_cfg(PIOB_14, AM_GPIO_INPUT);
    am_gpio_pin_cfg(PIOB_15, AM_GPIO_INPUT);

    am_clk_disable(CLK_SPI2);
}

/**
 * \brief SPI2 设备信息
 */
static const struct am_zlg116_spi_dma_devinfo  __g_spi2_dma_devinfo = {
    ZLG116_SPI2_BASE,                /**< \brief SPI2 寄存器指针 */
    CLK_SPI2,                        /**< \brief 时钟 ID 号 */
    INUM_SPI2,                       /**< \brief SPI2中断号 */
    0,                               /**< \brief SPI2 配置标识 */

    DMA_CHAN_SPI2_TX,
    DMA_CHAN_SPI2_RX,
    __zlg116_plfm_spi2_dma_init,     /**< \brief SPI2 平台初始化函数 */
    __zlg116_plfm_spi2_dma_deinit    /**< \brief SPI2 平台解初始化函数 */
};

/** \brief SPI2 设备实例 */
static am_zlg116_spi_dma_dev_t __g_spi2_dma_dev;

/** \brief SPI2 实例初始化，获得 SPI 标准服务句柄 */
am_spi_handle_t am_zlg116_spi2_dma_inst_init (void)
{
    return am_zlg116_spi_dma_init(&__g_spi2_dma_dev, &__g_spi2_dma_devinfo);
}

/** \brief SPI2 实例解初始化 */
void am_zlg116_spi2_dma_inst_deinit (am_spi_handle_t handle)
{
    am_zlg116_spi_dma_deinit(handle);
}
#endif

/**
 * @}
 */

/* end of file */
