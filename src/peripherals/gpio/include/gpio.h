/// @file  gpio.h
/// @brief This file contains all the function prototypes for
///        the gpio.c file
///
/// @author Siddhant Modi (sidmodi)

#pragma once
#ifdef __cplusplus
extern "C"
{
#endif

/****************************** Includes ************************************/

/****************************** Types ************************************/
typedef enum gpio_port_e
{
    GPIO_PORT_A = 0U,
    GPIO_PORT_B,
    GPIO_PORT_C,
    GPIO_PORT_D,
    GPIO_PORT_E,
    GPIO_PORT_F,
    GPIO_PORT_G,
    GPIO_PORT_H,
    GPIO_PORT_I,
    GPIO_PORT_COUNT
} gpio_port_t;

typedef enum gpio_pin_e
{
    GPIO_PIN_NUM_0 = 0U,
    GPIO_PIN_NUM_1,
    GPIO_PIN_NUM_2,
    GPIO_PIN_NUM_3,
    GPIO_PIN_NUM_4,
    GPIO_PIN_NUM_5,
    GPIO_PIN_NUM_6,
    GPIO_PIN_NUM_7,
    GPIO_PIN_NUM_8,
    GPIO_PIN_NUM_9,
    GPIO_PIN_NUM_10,
    GPIO_PIN_NUM_11,
    GPIO_PIN_NUM_12,
    GPIO_PIN_NUM_13,
    GPIO_PIN_NUM_14,
    GPIO_PIN_NUM_15,
    GPIO_PIN_COUNT
} gpio_pin_t;

typedef enum GPIO_pin_state_e
{
    GPIO_PIN_STATE_CLEAR = 0U,
    GPIO_PIN_STATE_SET,
    GPIO_PIN_STATE_COUNT
} gpio_pin_state_t;

typedef void ( *GPIO_interruptCB_t )( void );

/****************************** Functions ************************************/
/// @brief Register a callback to call when an interrupt is triggered on the
///        FLT_DAQ_5V GPIO pin
/// @param[in] handler Pointer to the callback function
void GPIO_register_FLT_DAQ_5V_interrupt_cb( GPIO_interruptCB_t handler );

/// @brief Enable the GPIO EXT interrupts
void GPIO_enable_interrupts( void );

/// @brief Disable the GPIO EXT interrupts
void GPIO_disable_interrupts( void );

/// @brief Set the state of the specified GPIO pin
/// @param[in] port Port number for GPIO pin
/// @param[in] pin Pin number to be modified
/// @param[in] state The state to which the pin will be set - set/clear
void GPIO_set_pin_state( gpio_port_t port, gpio_pin_t pin, gpio_pin_state_t state );

/// @brief Read the pin state of the specified GPIO pin
/// @param[in] port Port number for GPIO pin
/// @param[in] pin Pin number to be read
/// @return The current state of the pin
gpio_pin_state_t GPIO_get_pin_state( gpio_port_t port, gpio_pin_t pin );

/// @brief Deinit the GPIO pins for the SPI3 peripheral
void GPIO_SPI3_deinit( void );

/// @brief Deinit the GPIO pins for the USART1 peripheral
void GPIO_USART1_deinit( void );

/// @brief Deinit the GPIO pins for the USART3 peripheral
void GPIO_USART3_deinit( void );

/// @brief Deinit the GPIO pins for the UART4 peripheral
void GPIO_UART4_deinit( void );

/// @brief Deinit the GPIO pins for the I2C2 peripheral
void GPIO_I2C2_deinit( void );

/// @brief Initialize the GPIO pins for the SPI3 peripheral
void GPIO_SPI3_initialize( void );

/// @brief Initialize the GPIO pins for the USART1 peripheral
void GPIO_USART1_initialize( void );

/// @brief Initialize the GPIO pins for the USART3 peripheral
void GPIO_USART3_initialize( void );

/// @brief Initialize the GPIO pins for the UART4 peripheral
void GPIO_UART4_initialize( void );

/// @brief Initialize the GPIO pins for the I2C2 peripheral
void GPIO_I2C2_initialize( void );

/// @brief Initialize the non-specialized GPIO pins
void GPIO_initialize( void );

#ifdef __cplusplus
}
#endif
