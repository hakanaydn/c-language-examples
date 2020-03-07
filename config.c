#include "stdio.h"
#include "stdbool.h"

// =============================================================================
// Chip version
// =============================================================================
#define TGT_HAL_CHIP_VERSION    10

// =============================================================================
// RF CLK FREQUENCY
// =============================================================================
#define TGT_HAL_RF_CLK_FREQ     26

#define TRUE     1
#define FALSE     0

typedef struct
{
    /// \c TRUE if the corresponding pin is used as a Chip Select.
    bool cs0Used :1;
    bool cs1Used :1;
    bool cs2Used :1;
    bool cs3Used :1;
    /// \c TRUE if the first edge is falling
    bool cs0ActiveLow :1;
    bool cs1ActiveLow :1;
    bool cs2ActiveLow :1;
    bool cs3ActiveLow :1;
    /// \c TRUE if corresponding input is used
    bool di0Used :1;
    bool di1Used :1;
} HAL_CFG_SPI_T;

typedef struct 
{
    /// Chip version
    int  chipVersion;
    /// RF Clock Frequency
    int  rfClkFreq;
    /// \c TRUE if LPS_CO_1 is used as LPS
    int    useLpsCo1;
    /// Bitfield with '1' for keypad pins used as input on the keypad
    int   keyInMask;
    /// Bitfield with '1' for keypad pins used as output on the keypad
    int   keyOutMask;

    HAL_CFG_SPI_T spiCfg[2];

}tsCfgConfig;


#ifndef TGT_HAL_SPI_CFG
#define TGT_HAL_SPI_CFG                                                 \
{                                                                       \
    {                                                                   \
    .cs0Used            = FALSE,                                         \
    .cs1Used            = FALSE,                                        \
    .cs2Used            = FALSE,                                        \
    .cs3Used            = FALSE,                                        \
    .cs0ActiveLow       = TRUE,                                         \
    .cs1ActiveLow       = TRUE,                                         \
    .cs2ActiveLow       = TRUE,                                         \
    .cs3ActiveLow       = TRUE,                                         \
    .di0Used            = TRUE,                                         \
    .di1Used            = FALSE,                                        \
    },                                                                  \
    {                                                                   \
    .cs0Used            = FALSE,                                        \
    .cs1Used            = TRUE ,                                        \
    .cs2Used            = FALSE,                                        \
    .cs3Used            = FALSE,                                        \
    .cs0ActiveLow       = TRUE,                                         \
    .cs1ActiveLow       = TRUE,                                         \
    .cs2ActiveLow       = TRUE,                                         \
    .cs3ActiveLow       = TRUE,                                         \
    .di0Used            = TRUE,                                         \
    .di1Used            = FALSE,                                        \
    },                                                                  \
}
#endif
// =============================================================================
// TGT_HAL_CONFIG
// =============================================================================
#ifndef TGT_HAL_CONFIG
#define TGT_HAL_CONFIG                                                  \
{                                                                       \
    .chipVersion        = TGT_HAL_CHIP_VERSION,                         \
    .rfClkFreq          = TGT_HAL_RF_CLK_FREQ,                          \
    .useLpsCo1          = FALSE,                                        \
    .keyInMask          = 0x00,                                         \
    .keyOutMask         = 0x00,                                         \
    .spiCfg             = TGT_HAL_SPI_CFG,                              \
}
#endif



tsCfgConfig hal_cfg = TGT_HAL_CONFIG;

void hal_BoardSetupGeneral(tsCfgConfig* halCfg)
{
	printf("VERSION %d\n",halCfg->chipVersion);
	printf("rfClkFreq %d\n",halCfg->rfClkFreq);
	printf("useLpsCo1 %d\n",halCfg->useLpsCo1);
	printf("keyInMask %d\n",halCfg->keyInMask);
	printf("keyOutMask %d \n",halCfg->keyOutMask);
	printf("spiCfg cs1Used  %d\n",halCfg->spiCfg[1].cs1Used);
	
}

int main()
{
	hal_BoardSetupGeneral(&hal_cfg);

}


