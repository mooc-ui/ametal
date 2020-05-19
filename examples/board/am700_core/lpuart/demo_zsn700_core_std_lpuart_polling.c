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
 * \brief LPUART ��ѯ��ʽ���̣�ͨ����׼�ӿ�ʵ��
 *
 * - ʵ������
 *   1. ������� "STD-UART test in polling mode:"��
 *   2. ����������յ����ַ�����
 *
 * \note
 *    1. ����۲촮�ڴ�ӡ�ĵ�����Ϣ����Ҫ�� PIOA_10 �������� PC ���ڵ� TXD��
 *       PIOA_9 �������� PC ���ڵ� RXD��
 *    2. �� PIOB_12 �������� PC ���ڵ� RXD��PIOB_11 �������� PC ���ڵ� TXD��
 *    3. ������Դ���ʹ���뱾������ͬ����Ӧ�ں�������ʹ�õ�����Ϣ�������
 *      ���磺AM_DBG_INFO()����
 *
 * \par Դ����
 * \snippet demo_zsn700_std_uart_polling.c src_zsn700_std_uart_polling
 *
 * \internal
 * \par Modification History
 * - 1.01 19-09-26  zp, first implementation
 * \endinternal
 */

/**
 * \addtogroup demo_if_zsn700_std_uart_polling
 * \copydoc demo_zsn700_std_uart_polling.c
 */

/** [src_zsn700_std_uart_polling] */
#include "ametal.h"
#include "am_board.h"
#include "am_zsn700_inst_init.h"
#include "demo_std_entries.h"
#include "demo_am700_core_entries.h"

/**
 * \brief �������
 */
void demo_zsn700_core_std_lpuart_polling_entry (void)
{
    AM_DBG_INFO("demo am700_core std lpuart polling!\r\n");

     /* �ȴ������������ */
    am_mdelay(100);

    demo_std_uart_polling_entry(am_zsn700_lpuart0_inst_init());
}
/** [src_zsn700_std_uart_polling] */

/* end of file */