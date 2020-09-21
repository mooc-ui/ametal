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
 * \brief SPI ���� DMA ��ʽ���̣�ͨ����׼�ӿ�ʵ��
 *
 * - �������裺
 *   1. �� SPI �� MOSI ���ź� MISO ��������������ģ��ӻ��豸���ػ����ԡ�
 *
 * - ʵ������
 *   1. ����ͨ�� MOSI �������ݣ����������ݴ� MOSI ���أ�
 *   2. ���ڴ�ӡ�����Խ����
 *
 * \note
 *    ����۲촮�ڴ�ӡ�ĵ�����Ϣ����Ҫ�� PIOA_10 �������� PC ���ڵ� TXD��
 *    PIOA_9 �������� PC ���ڵ� RXD��
 *
 * \par Դ����
 * \snippet demo_stm32f103rbt6_std_spi_master_dma.c src_stm32f103rbt6_std_spi_master_dma
 *
 * \internal
 * \par History
 * - 1.00 19-07-23  ari, first implementation.
 * \endinternal
 */

/**
 * \addtogroup demo_if_stm32f103rbt6_std_spi_master_dma
 * \copydoc demo_stm32f103rbt6_std_spi_master_dma.c
 */

/** [src_stm32f103rbt6_std_spi_master_dma] */
#include "ametal.h"
#include "am_vdebug.h"
#include "stm32f103rbt6_pin.h"
#include "demo_std_entries.h"
#include "am_stm32f103rbt6_inst_init.h"
#include "demo_stm32f103rbt6_core_entries.h"

/**
 * \brief �������
 */
void demo_stm32f103rbt6_core_std_spi_master_dma_entry (void)
{
    AM_DBG_INFO("demo stm32f103rbt6_core std spi master dma!\r\n");

    demo_std_spi_master_entry(am_stm32f103rbt6_spi2_dma_inst_init(), PIOB_12);
}
/** [src_stm32f103rbt6_std_spi_master_dma] */

/* end of file */