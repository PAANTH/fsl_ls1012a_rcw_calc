#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
//#include <linux/bitops.h>

#define SYS_PLL_CFG_pos  0
#define SYS_PLL_CFG_len  2
#define SYS_PLL_CFG_val  0b00

#define SYS_PLL_RAT_pos  2
#define SYS_PLL_RAT_len  5
#define SYS_PLL_RAT_val  0b00100

#define CGA_PLL1_CFG_pos  24
#define CGA_PLL1_CFG_len  (25-CGA_PLL1_CFG_pos+1)
#define CGA_PLL1_CFG_val  0b00

#define CGA_PLL1_RAT_pos  26
#define CGA_PLL1_RAT_len  (31-CGA_PLL1_RAT_pos+1)
#define CGA_PLL1_RAT_val  0b001000

#define C1_PLL_SEL_pos  96
#define C1_PLL_SEL_len  (99-C1_PLL_SEL_pos+1)
#define C1_PLL_SEL_val  0b0000

#define SRDS_PRTCL_S1_pos  128
#define SRDS_PRTCL_S1_len  (143-SRDS_PRTCL_S1_pos+1)
#define SRDS_PRTCL_S1_val  0x3508U

#define SRDS_PLL_REF_CLK_SEL_S1_pos  160
#define SRDS_PLL_REF_CLK_SEL_S1_len  (161-SRDS_PLL_REF_CLK_SEL_S1_pos+1)
#define SRDS_PLL_REF_CLK_SEL_S1_val  0b11

#define SRDS_PLL_PD_S1_pos  168
#define SRDS_PLL_PD_S1_len  (169-SRDS_PLL_PD_S1_pos+1)
#define SRDS_PLL_PD_S1_val  0b00

#define SRDS_DIV_PEX_pos  176
#define SRDS_DIV_PEX_len  (177-SRDS_DIV_PEX_pos+1)
#define SRDS_DIV_PEX_val  0b00

#define RESERVED0_pos  188
#define RESERVED0_len  (188-RESERVED0_pos+1)
#define RESERVED0_val  0b1

#define SerDes_INT_REFCLK_pos  189
#define SerDes_INT_REFCLK_len  (189-SerDes_INT_REFCLK_pos+1)
#define SerDes_INT_REFCLK_val  0b1

#define PBI_SRC_pos  192
#define PBI_SRC_len  (195-PBI_SRC_pos+1)
#define PBI_SRC_val  0b0100                  //!!

#define BOOT_HO_pos  201
#define BOOT_HO_len  (201-BOOT_HO_pos+1)
#define BOOT_HO_val  0b0

#define SB_EN_pos  202
#define SB_EN_len  (202-SB_EN_pos+1)
#define SB_EN_val  0b0

#define SYS_PLL_SPD_pos  242
#define SYS_PLL_SPD_len  (243-SYS_PLL_SPD_pos+1)
#define SYS_PLL_SPD_val  0b01

#define CGA_PLL1_SPD_pos  244
#define CGA_PLL1_SPD_len  (244-CGA_PLL1_SPD_pos+1)
#define CGA_PLL1_SPD_val  0b1

#define HOST_AGT_PEX_pos  264
#define HOST_AGT_PEX_len  (264-HOST_AGT_PEX_pos+1)
#define HOST_AGT_PEX_val  0b1

#define SDHC2_EXT_CLK_pos  354
#define SDHC2_EXT_CLK_len  (354-SDHC2_EXT_CLK_pos+1)
#define SDHC2_EXT_CLK_val  0b0

#define SDHC2_EXT_CMD_pos  355
#define SDHC2_EXT_CMD_len  (355-SDHC2_EXT_CMD_pos+1)
#define SDHC2_EXT_CMD_val  0b0

#define SDHC2_EXT_DAT3_pos  356
#define SDHC2_EXT_DAT3_len  (356-SDHC2_EXT_DAT3_pos+1)
#define SDHC2_EXT_DAT3_val  0b0

#define SDHC2_EXT_DAT2_pos  357
#define SDHC2_EXT_DAT2_len  (357-SDHC2_EXT_DAT2_pos+1)
#define SDHC2_EXT_DAT2_val  0b0

#define SDHC2_EXT_DAT1_pos  358
#define SDHC2_EXT_DAT1_len  (358-SDHC2_EXT_DAT1_pos+1)
#define SDHC2_EXT_DAT1_val  0b0

#define SDHC2_EXT_DAT0_pos  359
#define SDHC2_EXT_DAT0_len  (359-SDHC2_EXT_DAT0_pos+1)
#define SDHC2_EXT_DAT0_val  0b0

#define EC1_EXT_SAI3_pos  360
#define EC1_EXT_SAI3_len  (361-EC1_EXT_SAI3_pos+1)
#define EC1_EXT_SAI3_val  0b00           //!!

#define EC1_EXT_SAI4_pos  362
#define EC1_EXT_SAI4_len  (363-EC1_EXT_SAI4_pos+1)
#define EC1_EXT_SAI4_val  0b00  //!!

#define EC1_EXT_SAI2_TX_pos  364
#define EC1_EXT_SAI2_TX_len  (364-EC1_EXT_SAI2_TX_pos+1)
#define EC1_EXT_SAI2_TX_val  0b0

#define EC1_EXT_SAI2_RX_pos  365
#define EC1_EXT_SAI2_RX_len  (365-EC1_EXT_SAI2_RX_pos+1)
#define EC1_EXT_SAI2_RX_val  0b0

#define EC1_BASE_pos  366
#define EC1_BASE_len  (367-EC1_BASE_pos+1)
#define EC1_BASE_val  0b01

#define UART1_BASE_pos  368
#define UART1_BASE_len  (369-UART1_BASE_pos+1)
#define UART1_BASE_val  0b01

#define UART2_BASE_FLOW_pos  370
#define UART2_BASE_FLOW_len  (371-UART2_BASE_FLOW_pos+1)
#define UART2_BASE_FLOW_val  0b01

#define SDHC1_BASE_pos  372
#define SDHC1_BASE_len  (373-SDHC1_BASE_pos+1)
#define SDHC1_BASE_val  0b01

#define SDHC2_BASE_DAT321_pos  374
#define SDHC2_BASE_DAT321_len  (375-SDHC2_BASE_DAT321_pos+1)
#define SDHC2_BASE_DAT321_val  0b01

#define SDHC2_BASE_BASE_pos  376
#define SDHC2_BASE_BASE_len  (377-SDHC2_BASE_BASE_pos+1)
#define SDHC2_BASE_BASE_val  0b01

#define UART2_BASE_DATA_pos  378
#define UART2_BASE_DATA_len  (378-UART2_BASE_DATA_pos+1)
#define UART2_BASE_DATA_val  0b1

#define EMI1_BASE_pos  379
#define EMI1_BASE_len  (379-EMI1_BASE_pos+1)
#define EMI1_BASE_val  0b1

#define GPIO_FTM_EXTCLK_BASE_pos  380
#define GPIO_FTM_EXTCLK_BASE_len  (381-GPIO_FTM_EXTCLK_BASE_pos+1)
#define GPIO_FTM_EXTCLK_BASE_val  0b00

#define CLK_OUT_BASE_pos  382
#define CLK_OUT_BASE_len  (383-CLK_OUT_BASE_pos+1)
#define CLK_OUT_BASE_val  0b01

#define SDHC1_CD_pos  419
#define SDHC1_CD_len  (419-SDHC1_CD_pos+1)
#define SDHC1_CD_val  0b1

#define SDHC1_WP_pos  420
#define SDHC1_WP_len  (420-SDHC1_WP_pos+1)
#define SDHC1_WP_val  0b1

#define QSPI_DATA0_GPIO_pos  421
#define QSPI_DATA0_GPIO_len  (421-QSPI_DATA0_GPIO_pos+1)
#define QSPI_DATA0_GPIO_val  0b0

#define QSPI_DATA1_GPIO_pos  422
#define QSPI_DATA1_GPIO_len  (423-QSPI_DATA1_GPIO_pos+1)
#define QSPI_DATA1_GPIO_val  0b00

#define QSPI_IIC2_pos  424
#define QSPI_IIC2_len  (425-QSPI_IIC2_pos+1)
#define QSPI_IIC2_val  0b11

#define USB1_DRVVBUS_BASE_pos  429
#define USB1_DRVVBUS_BASE_len  (430-USB1_DRVVBUS_BASE_pos+1)
#define USB1_DRVVBUS_BASE_val  0b01

#define USB1_PWRFAULT_BASE_pos  431
#define USB1_PWRFAULT_BASE_len  (432-USB1_PWRFAULT_BASE_pos+1)
#define USB1_PWRFAULT_BASE_val  0b01

#define SDHC1_VSEL_pos  434
#define SDHC1_VSEL_len  (434-SDHC1_VSEL_pos+1)
#define SDHC1_VSEL_val  0b1

#define EMI1_DMODE_pos  438
#define EMI1_DMODE_len  (438-EMI1_DMODE_pos+1)
#define EMI1_DMODE_val  0b0

#define EVDD_VSEL_pos  439
#define EVDD_VSEL_len  (440-EVDD_VSEL_pos+1)
#define EVDD_VSEL_val  0b00

#define IIC1_BASE_pos  441
#define IIC1_BASE_len  (442-IIC1_BASE_pos+1)
#define IIC1_BASE_val  0b01

#define EMI1_CMODE_pos  444
#define EMI1_CMODE_len  (444-EMI1_CMODE_pos+1)
#define EMI1_CMODE_val  0b0

#define CORE_REFCLK_pos  472
#define CORE_REFCLK_len  (481-CORE_REFCLK_pos+1)
#define CORE_REFCLK_val  0x258U

uint8_t rcw[511/8 + 1];


/**
  \brief mem_dump Функция вывода на терминал дампа памяти.
  \param[in] addr Указатель на адрес в памяти.
  \param[in] len Длина в байтах.
*/
void mem_dump(const void *addr, size_t len)
{
  uint32_t a;
  uint32_t i;
  uint8_t c;

  printf("Memory review:len %08lX", len);

  if ((addr == NULL) || (len == 0)) {
    printf(" -- (null)\r\n");
    return;
  }

  a = 0;

  do {
    printf("\r\n%08X:", a);

    for (i = 0; i < 16; i++) {
      if (i < len) {
        printf(" %02X", *((const uint8_t *)addr + a + i));
      } else {
        printf("   ");
      }
    }

    printf(" ?");
    for (i = 0; i < 16; i++) {
      c = ' ';
      if (len != 0) {
        c = *((const uint8_t *)addr + a++);
        if (c < ' ') {
          c = 0x2E;  // '.'
        }
        len--;
      }
      printf("%c", c);
    }
    printf("?");
  } while (len != 0);

  printf("\r\n");
}

static void clear_val_in_byte(uint8_t byte_index, uint8_t bit_index, int val_len)
{
  uint8_t mask = 0x00;

  uint8_t temp_val = (uint8_t)(pow(2,val_len) - 1);

  mask |= (temp_val << bit_index);
  mask = ~mask;

  rcw[byte_index] &= mask;
}

static void set_val_in_byte(uint8_t byte_index, uint8_t bit_index, uint8_t val)
{
  //printf("byte_index %u, bit_index %u, val %u\n", byte_index, bit_index, val);
  rcw[byte_index] |= (val << bit_index);
}

static uint8_t get_byte_index(int rcw_bit_start_pos, int field_len, uint8_t *is_split)
{
  uint8_t byte_index_start = (uint8_t)(rcw_bit_start_pos / 8);
  uint8_t byte_index_stop = (uint8_t)((rcw_bit_start_pos + field_len - 1) / 8);

  if (byte_index_stop != byte_index_start) {
    *is_split = 1;
  }

  if (byte_index_stop - byte_index_start > 1) {
    printf("ERROR! Field spread across more than two bytes!\r\n");
    exit(0);
  }

  return byte_index_start;
}

static uint8_t get_inbyte_bit_index(int rcw_bit_start_pos, uint8_t byte_index, int field_len, int *second_byte_field_len)
{
  int bit_index = 0;
  int remains = 0;

  remains = rcw_bit_start_pos % 8;
  bit_index = (7 - remains - field_len + 1);

  if (bit_index < 0) {

    *second_byte_field_len = field_len - (8 - remains);
    bit_index = 0;
  }
  // printf("bit_index %u\r\n", bit_index);
  return (uint8_t)bit_index;
}

static void set_rcv_field(int rcw_bit_index, int rcw_field_len, uint16_t rcw_field_val)
{
  uint8_t is_split = 0;
  uint8_t byte_index_start = 0;
  uint8_t inbyte_bit_index = 0;
  int second_byte_field_len = 0;
  //printf("\r\n");
  byte_index_start = get_byte_index(rcw_bit_index, rcw_field_len, &is_split);
  inbyte_bit_index = get_inbyte_bit_index(rcw_bit_index, byte_index_start, rcw_field_len, &second_byte_field_len);

  if (is_split) {
    // printf("Is split across %u and %u!\r\n", byte_index_start, byte_index_start + 1);
    // printf("rcw_field_val 0x%02X\r\n", rcw_field_val);
    uint8_t second_inbyte_bit_index = (uint8_t)(7 - second_byte_field_len + 1);
    uint8_t second_val = rcw_field_val << (7 - second_byte_field_len + 1);
    second_val = second_val >> (7 - second_byte_field_len + 1);

    // printf("second_byte_field_len %d\r\n", second_byte_field_len);
    // printf("second_inbyte_bit_index %u\r\n", second_inbyte_bit_index);
    // printf("second_val %u\r\n", second_val);


    clear_val_in_byte(byte_index_start + 1, second_inbyte_bit_index, second_byte_field_len);
    set_val_in_byte(byte_index_start + 1, second_inbyte_bit_index, second_val);

    rcw_field_len = rcw_field_len - second_byte_field_len;
    rcw_field_val = rcw_field_val >>second_byte_field_len;
    // printf("rcw_field_len %d\r\n", rcw_field_len);
    // printf("rcw_field_val %u\r\n", rcw_field_val);
    // printf("inbyte_bit_index %u\r\n", inbyte_bit_index);
  }


  // printf("Byte index is %u\r\n", byte_index_start);

  clear_val_in_byte(byte_index_start, inbyte_bit_index, rcw_field_len);
  set_val_in_byte(byte_index_start, inbyte_bit_index, rcw_field_val);

}


int main(int argc, char const *argv[])
{
  set_rcv_field(SYS_PLL_CFG_pos, SYS_PLL_CFG_len, SYS_PLL_CFG_val);
  set_rcv_field(SYS_PLL_RAT_pos, SYS_PLL_RAT_len, SYS_PLL_RAT_val);
  set_rcv_field(CGA_PLL1_CFG_pos, CGA_PLL1_CFG_len, CGA_PLL1_CFG_val);
  set_rcv_field(CGA_PLL1_RAT_pos, CGA_PLL1_RAT_len, CGA_PLL1_RAT_val);
  set_rcv_field(C1_PLL_SEL_pos, C1_PLL_SEL_len, C1_PLL_SEL_val);
  set_rcv_field(SRDS_PRTCL_S1_pos, SRDS_PRTCL_S1_len, SRDS_PRTCL_S1_val);
  set_rcv_field(SRDS_PLL_REF_CLK_SEL_S1_pos, SRDS_PLL_REF_CLK_SEL_S1_len, SRDS_PLL_REF_CLK_SEL_S1_val);
  set_rcv_field(SRDS_PLL_PD_S1_pos, SRDS_PLL_PD_S1_len, SRDS_PLL_PD_S1_val);
  set_rcv_field(SRDS_DIV_PEX_pos, SRDS_DIV_PEX_len, SRDS_DIV_PEX_val);
  set_rcv_field(RESERVED0_pos, RESERVED0_len, RESERVED0_val);
  set_rcv_field(SerDes_INT_REFCLK_pos, SerDes_INT_REFCLK_len, SerDes_INT_REFCLK_val);
  set_rcv_field(PBI_SRC_pos, PBI_SRC_len, PBI_SRC_val);
  set_rcv_field(BOOT_HO_pos, BOOT_HO_len, BOOT_HO_val);
  set_rcv_field(SB_EN_pos, SB_EN_len, SB_EN_val);
  set_rcv_field(SYS_PLL_SPD_pos, SYS_PLL_SPD_len, SYS_PLL_SPD_val);
  set_rcv_field(CGA_PLL1_SPD_pos, CGA_PLL1_SPD_len, CGA_PLL1_SPD_val);
  set_rcv_field(HOST_AGT_PEX_pos, HOST_AGT_PEX_len, HOST_AGT_PEX_val);
  set_rcv_field(SDHC2_EXT_CLK_pos, SDHC2_EXT_CLK_len, SDHC2_EXT_CLK_val);
  set_rcv_field(SDHC2_EXT_CMD_pos, SDHC2_EXT_CMD_len, SDHC2_EXT_CMD_val);
  set_rcv_field(SDHC2_EXT_DAT3_pos, SDHC2_EXT_DAT3_len, SDHC2_EXT_DAT3_val);
  set_rcv_field(SDHC2_EXT_DAT2_pos, SDHC2_EXT_DAT2_len, SDHC2_EXT_DAT2_val);
  set_rcv_field(SDHC2_EXT_DAT1_pos, SDHC2_EXT_DAT1_len, SDHC2_EXT_DAT1_val);
  set_rcv_field(SDHC2_EXT_DAT0_pos, SDHC2_EXT_DAT0_len, SDHC2_EXT_DAT0_val);
  set_rcv_field(EC1_EXT_SAI3_pos, EC1_EXT_SAI3_len, EC1_EXT_SAI3_val);
  set_rcv_field(EC1_EXT_SAI4_pos, EC1_EXT_SAI4_len, EC1_EXT_SAI4_val);
  set_rcv_field(EC1_EXT_SAI2_TX_pos, EC1_EXT_SAI2_TX_len, EC1_EXT_SAI2_TX_val);
  set_rcv_field(EC1_EXT_SAI2_RX_pos, EC1_EXT_SAI2_RX_len, EC1_EXT_SAI2_RX_val);
  set_rcv_field(EC1_BASE_pos, EC1_BASE_len, EC1_BASE_val);
  set_rcv_field(UART1_BASE_pos, UART1_BASE_len, UART1_BASE_val);
  set_rcv_field(UART2_BASE_FLOW_pos, UART2_BASE_FLOW_len, UART2_BASE_FLOW_val);
  set_rcv_field(SDHC1_BASE_pos, SDHC1_BASE_len, SDHC1_BASE_val);
  set_rcv_field(SDHC2_BASE_DAT321_pos, SDHC2_BASE_DAT321_len, SDHC2_BASE_DAT321_val);
  set_rcv_field(SDHC2_BASE_BASE_pos, SDHC2_BASE_BASE_len, SDHC2_BASE_BASE_val);
  set_rcv_field(UART2_BASE_DATA_pos, UART2_BASE_DATA_len, UART2_BASE_DATA_val);
  set_rcv_field(EMI1_BASE_pos, EMI1_BASE_len, EMI1_BASE_val);
  set_rcv_field(GPIO_FTM_EXTCLK_BASE_pos, GPIO_FTM_EXTCLK_BASE_len, GPIO_FTM_EXTCLK_BASE_val);
  set_rcv_field(CLK_OUT_BASE_pos, CLK_OUT_BASE_len, CLK_OUT_BASE_val);
  set_rcv_field(SDHC1_CD_pos, SDHC1_CD_len, SDHC1_CD_val);
  set_rcv_field(SDHC1_WP_pos, SDHC1_WP_len, SDHC1_WP_val);
  set_rcv_field(QSPI_DATA0_GPIO_pos, QSPI_DATA0_GPIO_len, QSPI_DATA0_GPIO_val);
  set_rcv_field(QSPI_DATA1_GPIO_pos, QSPI_DATA1_GPIO_len, QSPI_DATA1_GPIO_val);
  set_rcv_field(QSPI_IIC2_pos, QSPI_IIC2_len, QSPI_IIC2_val);
  set_rcv_field(USB1_DRVVBUS_BASE_pos, USB1_DRVVBUS_BASE_len, USB1_DRVVBUS_BASE_val);
  set_rcv_field(USB1_PWRFAULT_BASE_pos, USB1_PWRFAULT_BASE_len, USB1_PWRFAULT_BASE_val);
  set_rcv_field(SDHC1_VSEL_pos, SDHC1_VSEL_len, SDHC1_VSEL_val);
  set_rcv_field(EMI1_DMODE_pos, EMI1_DMODE_len, EMI1_DMODE_val);
  set_rcv_field(EVDD_VSEL_pos, EVDD_VSEL_len, EVDD_VSEL_val);
  set_rcv_field(IIC1_BASE_pos, IIC1_BASE_len, IIC1_BASE_val);
  set_rcv_field(EMI1_CMODE_pos, EMI1_CMODE_len, EMI1_CMODE_val);
  set_rcv_field(CORE_REFCLK_pos, CORE_REFCLK_len, CORE_REFCLK_val);


  mem_dump(rcw, sizeof(rcw));

  return 0;
}
