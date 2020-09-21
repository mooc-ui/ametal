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
 *   1. �� SPI �� MOSI ���ź� MISO ��������������ģ��ӻ��豸���ػ����ԣ���
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
 * \snippet demo_hk32f103rbt6_std_spi_master_poll.c src_hk32f103rbt6_std_spi_master_poll
 *
 * \internal
 * \par History
 * - 1.00 19-07-23  ari, first implementation.
 * \endinternal
 */

/**
 * \addtogroup demo_if_hk32f103rbt6_std_spi_master_poll
 * \copydoc demo_hk32f103rbt6_std_spi_master_poll.c
 */

/** [src_hk32f103rbt6_std_spi_master_poll] */
#include "ametal.h"
#include "am_vdebug.h"
#include "hk32f103rbt6_pin.h"
#include "demo_std_entries.h"
#include "am_hk32f103rbt6_inst_init.h"
#include "demo_hk32f103rbt6_core_entries.h"

/**
 * \brief �������
 */
void demo_hk32f103rbt6_core_std_spi_master_poll_entry (void)
{
    AM_DBG_INFO("demo hk32f103rbt6_core std spi master poll!\r\n");

    demo_std_spi_master_entry(am_hk32f103rbt6_spi2_poll_inst_init(), PIOB_12);
}
/** [src_hk32f103rbt6_std_spi_master_poll] */

/* end of file */