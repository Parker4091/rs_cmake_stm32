/// @brief Mock for HalSys
#include "mock_stm32_hal_driver.h"

#include <cmock/cmock.h>

MockSTM32HAL::MockSTM32HAL()  = default;
MockSTM32HAL::~MockSTM32HAL() = default;

// CRC
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_CRC_Init, ( CRC_HandleTypeDef * hcrc ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_CRC_DeInit, ( CRC_HandleTypeDef * hcrc ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_CRC_MspInit, ( CRC_HandleTypeDef * hcrc ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_CRC_MspDeInit, ( CRC_HandleTypeDef * hcrc ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, uint32_t, HAL_CRC_Accumulate, ( CRC_HandleTypeDef * hcrc, uint32_t pBuffer[], uint32_t BufferLength ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, uint32_t, HAL_CRC_Calculate, ( CRC_HandleTypeDef * hcrc, uint32_t pBuffer[], uint32_t BufferLength ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_CRC_StateTypeDef, HAL_CRC_GetState, ( CRC_HandleTypeDef * hcrc ) );

// HAL System and Overall definitions
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_Init, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_DeInit, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_MspInit, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_MspDeInit, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_InitTick, ( uint32_t TickPriority ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_IncTick, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_Delay, ( uint32_t Delay ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, uint32_t, HAL_GetTick, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, uint32_t, HAL_GetTickPrio, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_SetTickFreq, ( HAL_TickFreqTypeDef Freq ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_TickFreqTypeDef, HAL_GetTickFreq, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_SuspendTick, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_ResumeTick, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, uint32_t, HAL_GetHalVersion, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, uint32_t, HAL_GetREVID, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, uint32_t, HAL_GetDEVID, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, uint32_t, HAL_GetUIDw0, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, uint32_t, HAL_GetUIDw1, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, uint32_t, HAL_GetUIDw2, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_DBGMCU_EnableDBGSleepMode, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_DBGMCU_DisableDBGSleepMode, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_DBGMCU_EnableDBGStopMode, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_DBGMCU_DisableDBGStopMode, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_DBGMCU_EnableDBGStandbyMode, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_DBGMCU_DisableDBGStandbyMode, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_SYSCFG_SRAM2Erase, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_SYSCFG_EnableMemorySwappingBank, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_SYSCFG_DisableMemorySwappingBank, () );
#if defined( VREFBUF )
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_SYSCFG_VREFBUF_VoltageScalingConfig, ( uint32_t VoltageScaling ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_SYSCFG_VREFBUF_HighImpedanceConfig, ( uint32_t Mode ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_SYSCFG_VREFBUF_TrimmingConfig, ( uint32_t TrimmingValue ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_SYSCFG_EnableVREFBUF, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_SYSCFG_DisableVREFBUF, () );
#endif /* VREFBUF */
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_SYSCFG_EnableIOAnalogSwitchBooster, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_SYSCFG_DisableIOAnalogSwitchBooster, () );

// FLASH
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_FLASH_Program, ( uint32_t TypeProgram, uint32_t Address, uint64_t Data ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_FLASH_Program_IT, ( uint32_t TypeProgram, uint32_t Address, uint64_t Data ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_FLASH_IRQHandler, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_FLASH_EndOfOperationCallback, ( uint32_t ReturnValue ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_FLASH_OperationErrorCallback, ( uint32_t ReturnValue ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_FLASH_Unlock, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_FLASH_Lock, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_FLASH_OB_Unlock, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_FLASH_OB_Lock, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_FLASH_OB_Launch, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, uint32_t, HAL_FLASH_GetError, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, FLASH_WaitForLastOperation, ( uint32_t Timeout ) );

// Flash EX
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_FLASHEx_Erase, ( FLASH_EraseInitTypeDef * pEraseInit, uint32_t *PageError ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_FLASHEx_Erase_IT, ( FLASH_EraseInitTypeDef * pEraseInit ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_FLASHEx_OBProgram, ( FLASH_OBProgramInitTypeDef * pOBInit ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_FLASHEx_OBGetConfig, ( FLASH_OBProgramInitTypeDef * pOBInit ) );
#if defined( FLASH_CFGR_LVEN )
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_FLASHEx_ConfigLVEPin, ( uint32_t ConfigLVE ) );
#endif /* FLASH_CFGR_LVEN */
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, FLASH_PageErase, ( uint32_t Page, uint32_t Banks ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, FLASH_FlushCaches, () );

// GPIO
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_GPIO_Init, ( GPIO_TypeDef * GPIOx, GPIO_InitTypeDef *GPIO_Init ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_GPIO_DeInit, ( GPIO_TypeDef * GPIOx, uint32_t GPIO_Pin ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, GPIO_PinState, HAL_GPIO_ReadPin, ( GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_GPIO_WritePin, ( GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_GPIO_TogglePin, ( GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_GPIO_LockPin, ( GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_GPIO_EXTI_IRQHandler, ( uint16_t GPIO_Pin ) );
// CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_GPIO_EXTI_Callback, ( uint16_t GPIO_Pin ) ); // smodi: Disabled because app is overloading the weak definition

// IWDG
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_IWDG_Init, ( IWDG_HandleTypeDef * hiwdg ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_IWDG_Refresh, ( IWDG_HandleTypeDef * hiwdg ) );

// Peripheral Control functions
CMOCK_MOCK_FUNCTION( MockSTM32HAL, uint32_t, HAL_PWREx_GetVoltageRange, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_PWREx_ControlVoltageScaling, ( uint32_t VoltageScaling ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_EnableBatteryCharging, ( uint32_t ResistorSelection ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_DisableBatteryCharging, () );
#if defined( PWR_CR2_USV )
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_EnableVddUSB, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_DisableVddUSB, () );
#endif /* PWR_CR2_USV */
#if defined( PWR_CR2_IOSV )
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_EnableVddIO2, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_DisableVddIO2, () );
#endif /* PWR_CR2_IOSV */
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_EnableInternalWakeUpLine, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_DisableInternalWakeUpLine, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_PWREx_EnableGPIOPullUp, ( uint32_t GPIO, uint32_t GPIONumber ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_PWREx_DisableGPIOPullUp, ( uint32_t GPIO, uint32_t GPIONumber ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_PWREx_EnableGPIOPullDown, ( uint32_t GPIO, uint32_t GPIONumber ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_PWREx_DisableGPIOPullDown, ( uint32_t GPIO, uint32_t GPIONumber ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_EnablePullUpPullDownConfig, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_DisablePullUpPullDownConfig, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_EnableSRAM2ContentRetention, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_DisableSRAM2ContentRetention, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_PWREx_SetSRAM2ContentRetention, ( uint32_t SRAM2Size ) );
#if defined( PWR_CR1_RRSTP )
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_EnableSRAM3ContentRetention, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_DisableSRAM3ContentRetention, () );
#endif /* PWR_CR1_RRSTP */
#if defined( PWR_CR3_DSIPDEN )
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_EnableDSIPinsPDActivation, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_DisableDSIPinsPDActivation, () );
#endif /* PWR_CR3_DSIPDEN */
#if defined( PWR_CR2_PVME1 )
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_EnablePVM1, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_DisablePVM1, () );
#endif /* PWR_CR2_PVME1 */
#if defined( PWR_CR2_PVME2 )
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_EnablePVM2, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_DisablePVM2, () );
#endif /* PWR_CR2_PVME2 */
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_EnablePVM3, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_DisablePVM3, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_EnablePVM4, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_DisablePVM4, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_PWREx_ConfigPVM, ( PWR_PVMTypeDef * sConfigPVM ) );
#if defined( PWR_CR3_ENULP )
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_EnableBORPVD_ULP, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_DisableBORPVD_ULP, () );
#endif /* PWR_CR3_ENULP */
#if defined( PWR_CR4_EXT_SMPS_ON )
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_EnableExtSMPS_0V95, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_DisableExtSMPS_0V95, () );
#endif /* PWR_CR4_EXT_SMPS_ON */

/* Low Power modes configuration functions ************************************/
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_EnableLowPowerRunMode, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_PWREx_DisableLowPowerRunMode, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_EnterSTOP0Mode, ( uint8_t STOPEntry ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_EnterSTOP1Mode, ( uint8_t STOPEntry ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_EnterSTOP2Mode, ( uint8_t STOPEntry ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_EnterSHUTDOWNMode, () );

CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_PVD_PVM_IRQHandler, () );
#if defined( PWR_CR2_PVME1 )
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_PVM1Callback, () );
#endif /* PWR_CR2_PVME1 */
#if defined( PWR_CR2_PVME2 )
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_PVM2Callback, () );
#endif /* PWR_CR2_PVME2 */
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_PVM3Callback, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_PWREx_PVM4Callback, () );

// RCC
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_RCC_DeInit, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_RCC_OscConfig, ( RCC_OscInitTypeDef * RCC_OscInitStruct ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_RCC_ClockConfig, ( RCC_ClkInitTypeDef * RCC_ClkInitStruct, uint32_t FLatency ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_RCC_MCOConfig, ( uint32_t RCC_MCOx, uint32_t RCC_MCOSource, uint32_t RCC_MCODiv ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_RCC_EnableCSS, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, uint32_t, HAL_RCC_GetSysClockFreq, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, uint32_t, HAL_RCC_GetHCLKFreq, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, uint32_t, HAL_RCC_GetPCLK1Freq, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, uint32_t, HAL_RCC_GetPCLK2Freq, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_RCC_GetOscConfig, ( RCC_OscInitTypeDef * RCC_OscInitStruct ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_RCC_GetClockConfig, ( RCC_ClkInitTypeDef * RCC_ClkInitStruct, uint32_t *pFLatency ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_RCC_NMI_IRQHandler, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_RCC_CSSCallback, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, uint32_t, HAL_RCC_GetResetSource, () );

// RCC Extentsion
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_RCCEx_PeriphCLKConfig, ( RCC_PeriphCLKInitTypeDef * PeriphClkInit ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_RCCEx_GetPeriphCLKConfig, ( RCC_PeriphCLKInitTypeDef * PeriphClkInit ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, uint32_t, HAL_RCCEx_GetPeriphCLKFreq, ( uint32_t PeriphClk ) );
#if defined( RCC_PLLSAI1_SUPPORT )
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_RCCEx_EnablePLLSAI1, ( RCC_PLLSAI1InitTypeDef * PLLSAI1Init ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_RCCEx_DisablePLLSAI1, () );
#endif /* RCC_PLLSAI1_SUPPORT */
#if defined( RCC_PLLSAI2_SUPPORT )
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_RCCEx_EnablePLLSAI2, ( RCC_PLLSAI2InitTypeDef * PLLSAI2Init ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_RCCEx_DisablePLLSAI2, () );
#endif /* RCC_PLLSAI2_SUPPORT */
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_RCCEx_WakeUpStopCLKConfig, ( uint32_t WakeUpClk ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_RCCEx_StandbyMSIRangeConfig, ( uint32_t MSIRange ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_RCCEx_EnableLSECSS, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_RCCEx_DisableLSECSS, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_RCCEx_EnableLSECSS_IT, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_RCCEx_LSECSS_IRQHandler, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_RCCEx_LSECSS_Callback, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_RCCEx_EnableLSCO, ( uint32_t LSCOSource ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_RCCEx_DisableLSCO, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_RCCEx_EnableMSIPLLMode, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_RCCEx_DisableMSIPLLMode, () );
#if defined( OCTOSPI1 ) && defined( OCTOSPI2 )
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_RCCEx_OCTOSPIDelayConfig, ( uint32_t Delay1, uint32_t Delay2 ) );
#endif /* OCTOSPI1 && OCTOSPI2 */
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_RCCEx_CRSConfig, ( RCC_CRSInitTypeDef * pInit ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_RCCEx_CRSSoftwareSynchronizationGenerate, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_RCCEx_CRSGetSynchronizationInfo, ( RCC_CRSSynchroInfoTypeDef * pSynchroInfo ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, uint32_t, HAL_RCCEx_CRSWaitSynchronization, ( uint32_t Timeout ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_RCCEx_CRS_IRQHandler, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_RCCEx_CRS_SyncOkCallback, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_RCCEx_CRS_SyncWarnCallback, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_RCCEx_CRS_ExpectedSyncCallback, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_RCCEx_CRS_ErrorCallback, ( uint32_t Error ) );

// Timer
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_Base_Init, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_Base_DeInit, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_TIM_Base_MspInit, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_TIM_Base_MspDeInit, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_Base_Start, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_Base_Stop, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_Base_Start_IT, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_Base_Stop_IT, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_Base_Start_DMA, ( TIM_HandleTypeDef * htim, const uint32_t *pData, uint16_t Length ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_Base_Stop_DMA, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_OC_Init, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_OC_DeInit, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_TIM_OC_MspInit, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_TIM_OC_MspDeInit, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_OC_Start, ( TIM_HandleTypeDef * htim, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_OC_Stop, ( TIM_HandleTypeDef * htim, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_OC_Start_IT, ( TIM_HandleTypeDef * htim, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_OC_Stop_IT, ( TIM_HandleTypeDef * htim, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_OC_Start_DMA,
                     ( TIM_HandleTypeDef * htim, uint32_t Channel, const uint32_t *pData, uint16_t Length ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_OC_Stop_DMA, ( TIM_HandleTypeDef * htim, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_PWM_Init, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_PWM_DeInit, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_TIM_PWM_MspInit, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_TIM_PWM_MspDeInit, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_PWM_Start, ( TIM_HandleTypeDef * htim, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_PWM_Stop, ( TIM_HandleTypeDef * htim, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_PWM_Start_IT, ( TIM_HandleTypeDef * htim, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_PWM_Stop_IT, ( TIM_HandleTypeDef * htim, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_PWM_Start_DMA,
                     ( TIM_HandleTypeDef * htim, uint32_t Channel, const uint32_t *pData, uint16_t Length ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_PWM_Stop_DMA, ( TIM_HandleTypeDef * htim, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_IC_Init, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_IC_DeInit, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_TIM_IC_MspInit, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_TIM_IC_MspDeInit, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_IC_Start, ( TIM_HandleTypeDef * htim, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_IC_Stop, ( TIM_HandleTypeDef * htim, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_IC_Start_IT, ( TIM_HandleTypeDef * htim, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_IC_Stop_IT, ( TIM_HandleTypeDef * htim, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_IC_Start_DMA,
                     ( TIM_HandleTypeDef * htim, uint32_t Channel, uint32_t *pData, uint16_t Length ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_IC_Stop_DMA, ( TIM_HandleTypeDef * htim, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_OnePulse_Init, ( TIM_HandleTypeDef * htim, uint32_t OnePulseMode ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_OnePulse_DeInit, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_TIM_OnePulse_MspInit, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_TIM_OnePulse_MspDeInit, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_OnePulse_Start, ( TIM_HandleTypeDef * htim, uint32_t OutputChannel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_OnePulse_Stop, ( TIM_HandleTypeDef * htim, uint32_t OutputChannel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_OnePulse_Start_IT, ( TIM_HandleTypeDef * htim, uint32_t OutputChannel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_OnePulse_Stop_IT, ( TIM_HandleTypeDef * htim, uint32_t OutputChannel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_Encoder_Init, ( TIM_HandleTypeDef * htim, TIM_Encoder_InitTypeDef *sConfig ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_Encoder_DeInit, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_TIM_Encoder_MspInit, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_TIM_Encoder_MspDeInit, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_Encoder_Start, ( TIM_HandleTypeDef * htim, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_Encoder_Stop, ( TIM_HandleTypeDef * htim, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_Encoder_Start_IT, ( TIM_HandleTypeDef * htim, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_Encoder_Stop_IT, ( TIM_HandleTypeDef * htim, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_Encoder_Start_DMA,
                     ( TIM_HandleTypeDef * htim, uint32_t Channel, uint32_t *pData1, uint32_t *pData2, uint16_t Length ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_Encoder_Stop_DMA, ( TIM_HandleTypeDef * htim, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_TIM_IRQHandler, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_OC_ConfigChannel,
                     ( TIM_HandleTypeDef * htim, const TIM_OC_InitTypeDef *sConfig, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_PWM_ConfigChannel,
                     ( TIM_HandleTypeDef * htim, const TIM_OC_InitTypeDef *sConfig, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_IC_ConfigChannel,
                     ( TIM_HandleTypeDef * htim, const TIM_IC_InitTypeDef *sConfig, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_OnePulse_ConfigChannel,
                     ( TIM_HandleTypeDef * htim, TIM_OnePulse_InitTypeDef *sConfig, uint32_t OutputChannel, uint32_t InputChannel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_ConfigOCrefClear,
                     ( TIM_HandleTypeDef * htim, const TIM_ClearInputConfigTypeDef *sClearInputConfig, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_ConfigClockSource,
                     ( TIM_HandleTypeDef * htim, const TIM_ClockConfigTypeDef *sClockSourceConfig ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_ConfigTI1Input, ( TIM_HandleTypeDef * htim, uint32_t TI1_Selection ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_SlaveConfigSynchro,
                     ( TIM_HandleTypeDef * htim, const TIM_SlaveConfigTypeDef *sSlaveConfig ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_SlaveConfigSynchro_IT,
                     ( TIM_HandleTypeDef * htim, const TIM_SlaveConfigTypeDef *sSlaveConfig ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_DMABurst_WriteStart,
                     ( TIM_HandleTypeDef * htim, uint32_t BurstBaseAddress, uint32_t BurstRequestSrc, const uint32_t *BurstBuffer,
                       uint32_t BurstLength ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_DMABurst_MultiWriteStart,
                     ( TIM_HandleTypeDef * htim, uint32_t BurstBaseAddress, uint32_t BurstRequestSrc, const uint32_t *BurstBuffer,
                       uint32_t BurstLength, uint32_t DataLength ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_DMABurst_WriteStop, ( TIM_HandleTypeDef * htim, uint32_t BurstRequestSrc ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_DMABurst_ReadStart,
                     ( TIM_HandleTypeDef * htim, uint32_t BurstBaseAddress, uint32_t BurstRequestSrc, uint32_t *BurstBuffer, uint32_t BurstLength ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_DMABurst_MultiReadStart,
                     ( TIM_HandleTypeDef * htim, uint32_t BurstBaseAddress, uint32_t BurstRequestSrc, uint32_t *BurstBuffer, uint32_t BurstLength,
                       uint32_t DataLength ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_DMABurst_ReadStop, ( TIM_HandleTypeDef * htim, uint32_t BurstRequestSrc ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_GenerateEvent, ( TIM_HandleTypeDef * htim, uint32_t EventSource ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, uint32_t, HAL_TIM_ReadCapturedValue, ( const TIM_HandleTypeDef *htim, uint32_t Channel ) );
// CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_TIM_PeriodElapsedCallback, ( TIM_HandleTypeDef * htim ) ); // TODO(smodi): This is a __weak function in the HAL - need to figure out  how to do a weak mock
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_TIM_PeriodElapsedHalfCpltCallback, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_TIM_OC_DelayElapsedCallback, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_TIM_IC_CaptureCallback, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_TIM_IC_CaptureHalfCpltCallback, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_TIM_PWM_PulseFinishedCallback, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_TIM_PWM_PulseFinishedHalfCpltCallback, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_TIM_TriggerCallback, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_TIM_TriggerHalfCpltCallback, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_TIM_ErrorCallback, ( TIM_HandleTypeDef * htim ) );
#if( USE_HAL_TIM_REGISTER_CALLBACKS == 1 )
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_RegisterCallback,
                     ( TIM_HandleTypeDef * htim, HAL_TIM_CallbackIDTypeDef CallbackID, pTIM_CallbackTypeDef pCallback ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIM_UnRegisterCallback,
                     ( TIM_HandleTypeDef * htim, HAL_TIM_CallbackIDTypeDef CallbackID ) );
#endif /* USE_HAL_TIM_REGISTER_CALLBACKS */
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_TIM_StateTypeDef, HAL_TIM_Base_GetState, ( const TIM_HandleTypeDef *htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_TIM_StateTypeDef, HAL_TIM_OC_GetState, ( const TIM_HandleTypeDef *htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_TIM_StateTypeDef, HAL_TIM_PWM_GetState, ( const TIM_HandleTypeDef *htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_TIM_StateTypeDef, HAL_TIM_IC_GetState, ( const TIM_HandleTypeDef *htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_TIM_StateTypeDef, HAL_TIM_OnePulse_GetState, ( const TIM_HandleTypeDef *htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_TIM_StateTypeDef, HAL_TIM_Encoder_GetState, ( const TIM_HandleTypeDef *htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_TIM_ActiveChannel, HAL_TIM_GetActiveChannel, ( const TIM_HandleTypeDef *htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_TIM_ChannelStateTypeDef, HAL_TIM_GetChannelState, ( const TIM_HandleTypeDef *htim, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_TIM_DMABurstStateTypeDef, HAL_TIM_DMABurstState, ( const TIM_HandleTypeDef *htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, TIM_Base_SetConfig, ( TIM_TypeDef * TIMx, const TIM_Base_InitTypeDef *Structure ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, TIM_TI1_SetConfig,
                     ( TIM_TypeDef * TIMx, uint32_t TIM_ICPolarity, uint32_t TIM_ICSelection, uint32_t TIM_ICFilter ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, TIM_OC2_SetConfig, ( TIM_TypeDef * TIMx, const TIM_OC_InitTypeDef *OC_Config ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, TIM_ETR_SetConfig,
                     ( TIM_TypeDef * TIMx, uint32_t TIM_ExtTRGPrescaler, uint32_t TIM_ExtTRGPolarity, uint32_t ExtTRGFilter ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, TIM_DMADelayPulseHalfCplt, ( DMA_HandleTypeDef * hdma ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, TIM_DMAError, ( DMA_HandleTypeDef * hdma ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, TIM_DMACaptureCplt, ( DMA_HandleTypeDef * hdma ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, TIM_DMACaptureHalfCplt, ( DMA_HandleTypeDef * hdma ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, TIM_CCxChannelCmd, ( TIM_TypeDef * TIMx, uint32_t Channel, uint32_t ChannelState ) );
#if( USE_HAL_TIM_REGISTER_CALLBACKS == 1 )
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, TIM_ResetCallback, ( TIM_HandleTypeDef * htim ) );
#endif /* USE_HAL_TIM_REGISTER_CALLBACKS */

// Timer Extended
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIMEx_HallSensor_Init,
                     ( TIM_HandleTypeDef * htim, const TIM_HallSensor_InitTypeDef *sConfig ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIMEx_HallSensor_DeInit, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_TIMEx_HallSensor_MspInit, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_TIMEx_HallSensor_MspDeInit, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIMEx_HallSensor_Start, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIMEx_HallSensor_Stop, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIMEx_HallSensor_Start_IT, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIMEx_HallSensor_Stop_IT, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIMEx_HallSensor_Start_DMA,
                     ( TIM_HandleTypeDef * htim, uint32_t *pData, uint16_t Length ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIMEx_HallSensor_Stop_DMA, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIMEx_OCN_Start, ( TIM_HandleTypeDef * htim, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIMEx_OCN_Stop, ( TIM_HandleTypeDef * htim, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIMEx_OCN_Start_IT, ( TIM_HandleTypeDef * htim, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIMEx_OCN_Stop_IT, ( TIM_HandleTypeDef * htim, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIMEx_OCN_Start_DMA,
                     ( TIM_HandleTypeDef * htim, uint32_t Channel, const uint32_t *pData, uint16_t Length ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIMEx_OCN_Stop_DMA, ( TIM_HandleTypeDef * htim, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIMEx_PWMN_Start, ( TIM_HandleTypeDef * htim, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIMEx_PWMN_Stop, ( TIM_HandleTypeDef * htim, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIMEx_PWMN_Start_IT, ( TIM_HandleTypeDef * htim, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIMEx_PWMN_Stop_IT, ( TIM_HandleTypeDef * htim, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIMEx_PWMN_Start_DMA,
                     ( TIM_HandleTypeDef * htim, uint32_t Channel, const uint32_t *pData, uint16_t Length ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIMEx_PWMN_Stop_DMA, ( TIM_HandleTypeDef * htim, uint32_t Channel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIMEx_OnePulseN_Start, ( TIM_HandleTypeDef * htim, uint32_t OutputChannel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIMEx_OnePulseN_Stop, ( TIM_HandleTypeDef * htim, uint32_t OutputChannel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIMEx_OnePulseN_Start_IT, ( TIM_HandleTypeDef * htim, uint32_t OutputChannel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIMEx_OnePulseN_Stop_IT, ( TIM_HandleTypeDef * htim, uint32_t OutputChannel ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIMEx_ConfigCommutEvent,
                     ( TIM_HandleTypeDef * htim, uint32_t InputTrigger, uint32_t CommutationSource ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIMEx_ConfigCommutEvent_IT,
                     ( TIM_HandleTypeDef * htim, uint32_t InputTrigger, uint32_t CommutationSource ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIMEx_ConfigCommutEvent_DMA,
                     ( TIM_HandleTypeDef * htim, uint32_t InputTrigger, uint32_t CommutationSource ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIMEx_MasterConfigSynchronization,
                     ( TIM_HandleTypeDef * htim, const TIM_MasterConfigTypeDef *sMasterConfig ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIMEx_ConfigBreakDeadTime,
                     ( TIM_HandleTypeDef * htim, const TIM_BreakDeadTimeConfigTypeDef *sBreakDeadTimeConfig ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIMEx_ConfigBreakInput,
                     ( TIM_HandleTypeDef * htim, uint32_t BreakInput, const TIMEx_BreakInputConfigTypeDef *sBreakInputConfig ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIMEx_GroupChannel5, ( TIM_HandleTypeDef * htim, uint32_t Channels ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_TIMEx_RemapConfig, ( TIM_HandleTypeDef * htim, uint32_t Remap ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_TIMEx_CommutCallback, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_TIMEx_CommutHalfCpltCallback, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_TIMEx_BreakCallback, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_TIMEx_Break2Callback, ( TIM_HandleTypeDef * htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_TIM_StateTypeDef, HAL_TIMEx_HallSensor_GetState, ( const TIM_HandleTypeDef *htim ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_TIM_ChannelStateTypeDef, HAL_TIMEx_GetChannelNState, ( const TIM_HandleTypeDef *htim, uint32_t ChannelN ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, TIMEx_DMACommutationCplt, ( DMA_HandleTypeDef * hdma ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, TIMEx_DMACommutationHalfCplt, ( DMA_HandleTypeDef * hdma ) );

// HAL Cortex
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_NVIC_SetPriorityGrouping, ( uint32_t PriorityGroup ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_NVIC_SetPriority, ( IRQn_Type IRQn, uint32_t PreemptPriority, uint32_t SubPriority ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_NVIC_EnableIRQ, ( IRQn_Type IRQn ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_NVIC_DisableIRQ, ( IRQn_Type IRQn ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_NVIC_SystemReset, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, uint32_t, HAL_SYSTICK_Config, ( uint32_t TicksNumb ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, uint32_t, HAL_NVIC_GetPriorityGrouping, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_NVIC_GetPriority,
                     ( IRQn_Type IRQn, uint32_t PriorityGroup, uint32_t *pPreemptPriority, uint32_t *pSubPriority ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, uint32_t, HAL_NVIC_GetPendingIRQ, ( IRQn_Type IRQn ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_NVIC_SetPendingIRQ, ( IRQn_Type IRQn ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_NVIC_ClearPendingIRQ, ( IRQn_Type IRQn ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, uint32_t, HAL_NVIC_GetActive, ( IRQn_Type IRQn ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_SYSTICK_CLKSourceConfig, ( uint32_t CLKSource ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_SYSTICK_IRQHandler, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_SYSTICK_Callback, () );

#if( __MPU_PRESENT == 1 )
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_MPU_Enable, ( uint32_t MPU_Control ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_MPU_Disable, () );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_MPU_ConfigRegion, ( MPU_Region_InitTypeDef * MPU_Init ) );
#endif /* __MPU_PRESENT */

// I2C
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_Init, ( I2C_HandleTypeDef * hi2c ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_DeInit, ( I2C_HandleTypeDef * hi2c ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_I2C_MspInit, ( I2C_HandleTypeDef * hi2c ) );
//CMOCK_MOCK_FUNCTION(MockSTM32HAL,void, HAL_I2C_MspDeInit,(I2C_HandleTypeDef *hi2c));
#if( USE_HAL_I2C_REGISTER_CALLBACKS == 1 )
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_RegisterCallback,
                     ( I2C_HandleTypeDef * hi2c, HAL_I2C_CallbackIDTypeDef CallbackID, pI2C_CallbackTypeDef pCallback ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_UnRegisterCallback,
                     ( I2C_HandleTypeDef * hi2c, HAL_I2C_CallbackIDTypeDef CallbackID ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_RegisterAddrCallback,
                     ( I2C_HandleTypeDef * hi2c, pI2C_AddrCallbackTypeDef pCallback ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_UnRegisterAddrCallback, ( I2C_HandleTypeDef * hi2c ) );
#endif /* USE_HAL_I2C_REGISTER_CALLBACKS */
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_Master_Transmit,
                     ( I2C_HandleTypeDef * hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_Master_Receive,
                     ( I2C_HandleTypeDef * hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_Slave_Transmit,
                     ( I2C_HandleTypeDef * hi2c, uint8_t *pData, uint16_t Size, uint32_t Timeout ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_Slave_Receive,
                     ( I2C_HandleTypeDef * hi2c, uint8_t *pData, uint16_t Size, uint32_t Timeout ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_Mem_Write,
                     ( I2C_HandleTypeDef * hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size,
                       uint32_t Timeout ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_Mem_Read,
                     ( I2C_HandleTypeDef * hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size,
                       uint32_t Timeout ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_IsDeviceReady,
                     ( I2C_HandleTypeDef * hi2c, uint16_t DevAddress, uint32_t Trials, uint32_t Timeout ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_Master_Transmit_IT,
                     ( I2C_HandleTypeDef * hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_Master_Receive_IT,
                     ( I2C_HandleTypeDef * hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_Slave_Transmit_IT, ( I2C_HandleTypeDef * hi2c, uint8_t *pData, uint16_t Size ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_Slave_Receive_IT, ( I2C_HandleTypeDef * hi2c, uint8_t *pData, uint16_t Size ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_Mem_Write_IT,
                     ( I2C_HandleTypeDef * hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_Mem_Read_IT,
                     ( I2C_HandleTypeDef * hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_Master_Seq_Transmit_IT,
                     ( I2C_HandleTypeDef * hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t XferOptions ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_Master_Seq_Receive_IT,
                     ( I2C_HandleTypeDef * hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t XferOptions ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_Slave_Seq_Transmit_IT,
                     ( I2C_HandleTypeDef * hi2c, uint8_t *pData, uint16_t Size, uint32_t XferOptions ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_Slave_Seq_Receive_IT,
                     ( I2C_HandleTypeDef * hi2c, uint8_t *pData, uint16_t Size, uint32_t XferOptions ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_EnableListen_IT, ( I2C_HandleTypeDef * hi2c ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_DisableListen_IT, ( I2C_HandleTypeDef * hi2c ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_Master_Abort_IT, ( I2C_HandleTypeDef * hi2c, uint16_t DevAddress ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_Master_Transmit_DMA,
                     ( I2C_HandleTypeDef * hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_Master_Receive_DMA,
                     ( I2C_HandleTypeDef * hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_Slave_Transmit_DMA, ( I2C_HandleTypeDef * hi2c, uint8_t *pData, uint16_t Size ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_Slave_Receive_DMA, ( I2C_HandleTypeDef * hi2c, uint8_t *pData, uint16_t Size ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_Mem_Write_DMA,
                     ( I2C_HandleTypeDef * hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_Mem_Read_DMA,
                     ( I2C_HandleTypeDef * hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_Master_Seq_Transmit_DMA,
                     ( I2C_HandleTypeDef * hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t XferOptions ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_Master_Seq_Receive_DMA,
                     ( I2C_HandleTypeDef * hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t XferOptions ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_Slave_Seq_Transmit_DMA,
                     ( I2C_HandleTypeDef * hi2c, uint8_t *pData, uint16_t Size, uint32_t XferOptions ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2C_Slave_Seq_Receive_DMA,
                     ( I2C_HandleTypeDef * hi2c, uint8_t *pData, uint16_t Size, uint32_t XferOptions ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_I2C_EV_IRQHandler, ( I2C_HandleTypeDef * hi2c ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_I2C_ER_IRQHandler, ( I2C_HandleTypeDef * hi2c ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_I2C_MasterTxCpltCallback, ( I2C_HandleTypeDef * hi2c ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_I2C_MasterRxCpltCallback, ( I2C_HandleTypeDef * hi2c ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_I2C_SlaveTxCpltCallback, ( I2C_HandleTypeDef * hi2c ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_I2C_SlaveRxCpltCallback, ( I2C_HandleTypeDef * hi2c ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_I2C_AddrCallback, ( I2C_HandleTypeDef * hi2c, uint8_t TransferDirection, uint16_t AddrMatchCode ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_I2C_ListenCpltCallback, ( I2C_HandleTypeDef * hi2c ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_I2C_MemTxCpltCallback, ( I2C_HandleTypeDef * hi2c ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_I2C_MemRxCpltCallback, ( I2C_HandleTypeDef * hi2c ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_I2C_ErrorCallback, ( I2C_HandleTypeDef * hi2c ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_I2C_AbortCpltCallback, ( I2C_HandleTypeDef * hi2c ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_I2C_StateTypeDef, HAL_I2C_GetState, ( I2C_HandleTypeDef * hi2c ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_I2C_ModeTypeDef, HAL_I2C_GetMode, ( I2C_HandleTypeDef * hi2c ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, uint32_t, HAL_I2C_GetError, ( I2C_HandleTypeDef * hi2c ) );

// I2c Extended
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2CEx_ConfigAnalogFilter, ( I2C_HandleTypeDef * hi2c, uint32_t AnalogFilter ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2CEx_ConfigDigitalFilter, ( I2C_HandleTypeDef * hi2c, uint32_t DigitalFilter ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2CEx_EnableWakeUp, ( I2C_HandleTypeDef * hi2c ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_I2CEx_DisableWakeUp, ( I2C_HandleTypeDef * hi2c ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_I2CEx_EnableFastModePlus, ( uint32_t ConfigFastModePlus ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_I2CEx_DisableFastModePlus, ( uint32_t ConfigFastModePlus ) );

// DMA
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_DMA_Init, ( DMA_HandleTypeDef * hdma ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_DMA_DeInit, ( DMA_HandleTypeDef * hdma ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_DMA_Start,
                     ( DMA_HandleTypeDef * hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_DMA_Start_IT,
                     ( DMA_HandleTypeDef * hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_DMA_Abort, ( DMA_HandleTypeDef * hdma ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_DMA_Abort_IT, ( DMA_HandleTypeDef * hdma ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_DMA_PollForTransfer,
                     ( DMA_HandleTypeDef * hdma, HAL_DMA_LevelCompleteTypeDef CompleteLevel, uint32_t Timeout ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_DMA_IRQHandler, ( DMA_HandleTypeDef * hdma ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_DMA_RegisterCallback,
                     ( DMA_HandleTypeDef * hdma, HAL_DMA_CallbackIDTypeDef CallbackID, void ( *pCallback )( DMA_HandleTypeDef *_hdma ) ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_DMA_UnRegisterCallback,
                     ( DMA_HandleTypeDef * hdma, HAL_DMA_CallbackIDTypeDef CallbackID ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_DMA_StateTypeDef, HAL_DMA_GetState, ( DMA_HandleTypeDef * hdma ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, uint32_t, HAL_DMA_GetError, ( DMA_HandleTypeDef * hdma ) );

// SPI
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_SPI_Init, ( SPI_HandleTypeDef * hspi ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_SPI_DeInit, ( SPI_HandleTypeDef * hspi ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_SPI_MspInit, ( SPI_HandleTypeDef * hspi ) );
//CMOCK_MOCK_FUNCTION(MockSTM32HAL,void, HAL_SPI_MspDeInit,(SPI_HandleTypeDef *hspi));
#if( USE_HAL_SPI_REGISTER_CALLBACKS == 1U )
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_SPI_RegisterCallback,
                     ( SPI_HandleTypeDef * hspi, HAL_SPI_CallbackIDTypeDef CallbackID, pSPI_CallbackTypeDef pCallback ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_SPI_UnRegisterCallback,
                     ( SPI_HandleTypeDef * hspi, HAL_SPI_CallbackIDTypeDef CallbackID ) );
#endif /* USE_HAL_SPI_REGISTER_CALLBACKS */
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_SPI_Transmit,
                     ( SPI_HandleTypeDef * hspi, uint8_t *pData, uint16_t Size, uint32_t Timeout ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_SPI_Receive,
                     ( SPI_HandleTypeDef * hspi, uint8_t *pData, uint16_t Size, uint32_t Timeout ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_SPI_TransmitReceive,
                     ( SPI_HandleTypeDef * hspi, uint8_t *pTxData, uint8_t *pRxData, uint16_t Size, uint32_t Timeout ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_SPI_Transmit_IT, ( SPI_HandleTypeDef * hspi, uint8_t *pData, uint16_t Size ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_SPI_Receive_IT, ( SPI_HandleTypeDef * hspi, uint8_t *pData, uint16_t Size ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_SPI_TransmitReceive_IT,
                     ( SPI_HandleTypeDef * hspi, uint8_t *pTxData, uint8_t *pRxData, uint16_t Size ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_SPI_Transmit_DMA, ( SPI_HandleTypeDef * hspi, uint8_t *pData, uint16_t Size ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_SPI_Receive_DMA, ( SPI_HandleTypeDef * hspi, uint8_t *pData, uint16_t Size ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_SPI_TransmitReceive_DMA,
                     ( SPI_HandleTypeDef * hspi, uint8_t *pTxData, uint8_t *pRxData, uint16_t Size ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_SPI_DMAPause, ( SPI_HandleTypeDef * hspi ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_SPI_DMAResume, ( SPI_HandleTypeDef * hspi ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_SPI_DMAStop, ( SPI_HandleTypeDef * hspi ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_SPI_Abort, ( SPI_HandleTypeDef * hspi ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_SPI_Abort_IT, ( SPI_HandleTypeDef * hspi ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_SPI_IRQHandler, ( SPI_HandleTypeDef * hspi ) );
//CMOCK_MOCK_FUNCTION(MockSTM32HAL,void, HAL_SPI_TxCpltCallback,(SPI_HandleTypeDef *hspi));
//CMOCK_MOCK_FUNCTION(MockSTM32HAL,void, HAL_SPI_RxCpltCallback,(SPI_HandleTypeDef *hspi));
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_SPI_TxRxCpltCallback, ( SPI_HandleTypeDef * hspi ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_SPI_TxHalfCpltCallback, ( SPI_HandleTypeDef * hspi ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_SPI_RxHalfCpltCallback, ( SPI_HandleTypeDef * hspi ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_SPI_TxRxHalfCpltCallback, ( SPI_HandleTypeDef * hspi ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_SPI_ErrorCallback, ( SPI_HandleTypeDef * hspi ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_SPI_AbortCpltCallback, ( SPI_HandleTypeDef * hspi ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_SPI_StateTypeDef, HAL_SPI_GetState, ( SPI_HandleTypeDef * hspi ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, uint32_t, HAL_SPI_GetError, ( SPI_HandleTypeDef * hspi ) );

// UART
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UART_Init, ( UART_HandleTypeDef * huart ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_HalfDuplex_Init, ( UART_HandleTypeDef * huart ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_LIN_Init, ( UART_HandleTypeDef * huart, uint32_t BreakDetectLength ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_MultiProcessor_Init,
                     ( UART_HandleTypeDef * huart, uint8_t Address, uint32_t WakeUpMethod ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UART_DeInit, ( UART_HandleTypeDef * huart ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_UART_MspInit, ( UART_HandleTypeDef * huart ) );
//CMOCK_MOCK_FUNCTION(MockSTM32HAL,void, HAL_UART_MspDeInit,(UART_HandleTypeDef *huart));
#if( USE_HAL_UART_REGISTER_CALLBACKS == 1 )
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UART_RegisterCallback,
                     ( UART_HandleTypeDef * huart, HAL_UART_CallbackIDTypeDef CallbackID, pUART_CallbackTypeDef pCallback ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UART_UnRegisterCallback,
                     ( UART_HandleTypeDef * huart, HAL_UART_CallbackIDTypeDef CallbackID ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UART_RegisterRxEventCallback,
                     ( UART_HandleTypeDef * huart, pUART_RxEventCallbackTypeDef pCallback ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UART_UnRegisterRxEventCallback, ( UART_HandleTypeDef * huart ) );
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UART_Transmit,
                     ( UART_HandleTypeDef * huart, const uint8_t *pData, uint16_t Size, uint32_t Timeout ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UART_Receive,
                     ( UART_HandleTypeDef * huart, uint8_t *pData, uint16_t Size, uint32_t Timeout ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UART_Transmit_IT, ( UART_HandleTypeDef * huart, const uint8_t *pData, uint16_t Size ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UART_Receive_IT, ( UART_HandleTypeDef * huart, uint8_t *pData, uint16_t Size ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UART_Transmit_DMA, ( UART_HandleTypeDef * huart, const uint8_t *pData, uint16_t Size ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UART_Receive_DMA, ( UART_HandleTypeDef * huart, uint8_t *pData, uint16_t Size ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UART_DMAPause, ( UART_HandleTypeDef * huart ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UART_DMAResume, ( UART_HandleTypeDef * huart ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UART_DMAStop, ( UART_HandleTypeDef * huart ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UART_Abort, ( UART_HandleTypeDef * huart ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UART_AbortTransmit, ( UART_HandleTypeDef * huart ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UART_AbortReceive, ( UART_HandleTypeDef * huart ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UART_Abort_IT, ( UART_HandleTypeDef * huart ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UART_AbortTransmit_IT, ( UART_HandleTypeDef * huart ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UART_AbortReceive_IT, ( UART_HandleTypeDef * huart ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_UART_IRQHandler, ( UART_HandleTypeDef * huart ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_UART_TxHalfCpltCallback, ( UART_HandleTypeDef * huart ) );
//CMOCK_MOCK_FUNCTION(MockSTM32HAL,void, HAL_UART_TxCpltCallback,(UART_HandleTypeDef *huart));
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_UART_RxHalfCpltCallback, ( UART_HandleTypeDef * huart ) );
//CMOCK_MOCK_FUNCTION(MockSTM32HAL,void, HAL_UART_RxCpltCallback,(UART_HandleTypeDef *huart));
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_UART_ErrorCallback, ( UART_HandleTypeDef * huart ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_UART_AbortCpltCallback, ( UART_HandleTypeDef * huart ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_UART_AbortTransmitCpltCallback, ( UART_HandleTypeDef * huart ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_UART_AbortReceiveCpltCallback, ( UART_HandleTypeDef * huart ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_UARTEx_RxEventCallback, ( UART_HandleTypeDef * huart, uint16_t Size ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_UART_ReceiverTimeout_Config, ( UART_HandleTypeDef * huart, uint32_t TimeoutValue ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UART_EnableReceiverTimeout, ( UART_HandleTypeDef * huart ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UART_DisableReceiverTimeout, ( UART_HandleTypeDef * huart ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_LIN_SendBreak, ( UART_HandleTypeDef * huart ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_MultiProcessor_EnableMuteMode, ( UART_HandleTypeDef * huart ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_MultiProcessor_DisableMuteMode, ( UART_HandleTypeDef * huart ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_MultiProcessor_EnterMuteMode, ( UART_HandleTypeDef * huart ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_HalfDuplex_EnableTransmitter, ( UART_HandleTypeDef * huart ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_HalfDuplex_EnableReceiver, ( UART_HandleTypeDef * huart ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_UART_StateTypeDef, HAL_UART_GetState, ( const UART_HandleTypeDef *huart ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, uint32_t, HAL_UART_GetError, ( const UART_HandleTypeDef *huart ) );
#if( USE_HAL_UART_REGISTER_CALLBACKS == 1 )
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, UART_InitCallbacksToDefault, ( UART_HandleTypeDef * huart ) );
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, UART_SetConfig, ( UART_HandleTypeDef * huart ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, UART_CheckIdleState, ( UART_HandleTypeDef * huart ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, UART_WaitOnFlagUntilTimeout,
                     ( UART_HandleTypeDef * huart, uint32_t Flag, FlagStatus Status, uint32_t Tickstart, uint32_t Timeout ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, UART_AdvFeatureConfig, ( UART_HandleTypeDef * huart ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, UART_Start_Receive_IT, ( UART_HandleTypeDef * huart, uint8_t *pData, uint16_t Size ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, UART_Start_Receive_DMA, ( UART_HandleTypeDef * huart, uint8_t *pData, uint16_t Size ) );

// UART Extended
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_RS485Ex_Init,
                     ( UART_HandleTypeDef * huart, uint32_t Polarity, uint32_t AssertionTime, uint32_t DeassertionTime ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_UARTEx_WakeupCallback, ( UART_HandleTypeDef * huart ) );
#if defined( USART_CR1_FIFOEN )
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_UARTEx_RxFifoFullCallback, ( UART_HandleTypeDef * huart ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, void, HAL_UARTEx_TxFifoEmptyCallback, ( UART_HandleTypeDef * huart ) );
#endif /* USART_CR1_FIFOEN */
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UARTEx_StopModeWakeUpSourceConfig,
                     ( UART_HandleTypeDef * huart, UART_WakeUpTypeDef WakeUpSelection ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UARTEx_EnableStopMode, ( UART_HandleTypeDef * huart ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UARTEx_DisableStopMode, ( UART_HandleTypeDef * huart ) );
#if defined( USART_CR3_UCESM )
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UARTEx_EnableClockStopMode, ( UART_HandleTypeDef * huart ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UARTEx_DisableClockStopMode, ( UART_HandleTypeDef * huart ) );
#endif /* USART_CR3_UCESM */
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_MultiProcessorEx_AddressLength_Set,
                     ( UART_HandleTypeDef * huart, uint32_t AddressLength ) );
#if defined( USART_CR1_FIFOEN )
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UARTEx_EnableFifoMode, ( UART_HandleTypeDef * huart ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UARTEx_DisableFifoMode, ( UART_HandleTypeDef * huart ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UARTEx_SetTxFifoThreshold, ( UART_HandleTypeDef * huart, uint32_t Threshold ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UARTEx_SetRxFifoThreshold, ( UART_HandleTypeDef * huart, uint32_t Threshold ) );
#endif /* USART_CR1_FIFOEN */
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UARTEx_ReceiveToIdle,
                     ( UART_HandleTypeDef * huart, uint8_t *pData, uint16_t Size, uint16_t *RxLen, uint32_t Timeout ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UARTEx_ReceiveToIdle_IT, ( UART_HandleTypeDef * huart, uint8_t *pData, uint16_t Size ) );
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_UARTEx_ReceiveToIdle_DMA, ( UART_HandleTypeDef * huart, uint8_t *pData, uint16_t Size ) );

// WWDG
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_WWDG_Init, ( WWDG_HandleTypeDef * hwwdg ) )
CMOCK_MOCK_FUNCTION( MockSTM32HAL, HAL_StatusTypeDef, HAL_WWDG_Refresh, ( WWDG_HandleTypeDef * hwwdg ) )
