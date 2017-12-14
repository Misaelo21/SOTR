#include <Arduino_FreeRTOS.h>
#include <semphr.h>  

SemaphoreHandle_t xSerialSemaphore;

// Definir varias tareas digitales y analogas
void TareaLed( void *pvParametros );
void TareaLed1( void *pvParametros );
void TareaLed2( void *pvParametros );
void TareaDigital( void *pvParametros );
void TareaAnaloga( void *pvParametros );

void setup() {

  // Inicializa la comunicacion serial
  Serial.begin(9600);

  if ( xSerialSemaphore == NULL ) 
  {
    xSerialSemaphore = xSemaphoreCreateMutex();
    if ( ( xSerialSemaphore ) != NULL )
      xSemaphoreGive( ( xSerialSemaphore ) ); 

  // Se crean las tareas
  xTaskCreate(
    TareaLed
    ,  (const portCHAR *)"Blink"  
    ,  128  // Tamaño
    ,  NULL
    ,  3  // Priotidad
    ,  NULL );
  xTaskCreate(
    TareaLed1
    ,  (const portCHAR *)"Blink"  
    ,  128  // Tamaño
    ,  NULL
    ,  4  // Prioridad
    ,  NULL );
   xTaskCreate(
    TareaLed2
    ,  (const portCHAR *)"Blink"
    ,  128  // Tamaño
    ,  NULL
    ,  5  // Prioridad
    ,  NULL );
  xTaskCreate(
    TareaDigital
    ,  (const portCHAR *)"DigitalRead" 
    ,  128 
    ,  NULL
    ,  2  
    ,  NULL );

  xTaskCreate(
    TareaAnaloga
    ,  (const portCHAR *) "AnalogRead"
    ,  128  // 
    ,  NULL
    ,  1  // Prioridad
    ,  NULL );

}

void loop()
{

}


//Funcionamiento de las tareas
void TareaDigital( void *pvParametros __attribute__((unused)) )
{
  /*
    Tarea Digital
    Lee la entrada digital del puerto 2 y 
    el resultado lo imprime en la pantalla
  */

  uint8_t pushButton = 2;

  // La variable la hace un pin
  pinMode(pushButton, INPUT);

  for (;;) // La tarea no termina
  {
    // Lee el valor del pin
    int buttonEstado = digitalRead(pushButton);

    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE )
    {
      
      Serial.println(buttonEstado);

      xSemaphoreGive( xSerialSemaphore );
    }

    vTaskDelay(1); 
  }
}

void TareaAnaloga( void *pvParametros __attribute__((unused)) )
{
    /*Tarea Digital
    Lee la entrada analogica del puerto 0 y 
    el resultado lo imprime en la pantalla
    */
  for (;;) //Latarea no termina
  {
    // Lee la enttada analogica de pin 0
    int analogValor = analogRead(A0);

    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE )
    {
      Serial.println(analogValor);

      xSemaphoreGive( xSerialSemaphore );
    }

    vTaskDelay(1); 
  }
}

void TareaLed(void *pvParametros) 
{
  (void) pvParametros;

  // Inicializa el pin digital 13 como salidad.
  pinMode(13, OUTPUT);

  for (;;) // La tarea no termina
  {
    digitalWrite(13, HIGH);   // Prende el led 
    vTaskDelay( 1000 / portTICK_PERIOD_MS ); // Espera un segundo
    digitalWrite(13, LOW);    // Apaga el led
    vTaskDelay( 1000 / portTICK_PERIOD_MS ); // Espera un segundo
  }
}

void TareaLed1(void *pvParametros) 
{
  (void) pvParametros;

  // Inicializa el pin digital 12 como salidad.
  pinMode(12, OUTPUT);

  for (;;) //La tarea no termina
  {
    digitalWrite(12, HIGH);  // Prende el led 
    vTaskDelay( 2000 / portTICK_PERIOD_MS ); // Espera dos segundo
    digitalWrite(12, LOW);    // Apaga el led
    vTaskDelay( 2000 / portTICK_PERIOD_MS ); // Espera dos segundo
  }
}

void TareaLed2(void *pvParametros)
{
  (void) pvParametros;

  // Inicializa el pin digital 8 como salidad.
  pinMode(8, OUTPUT);

  for (;;) // La tarea no termina
  {
    digitalWrite(8, HIGH);   // Prende el led 
    vTaskDelay( 500 / portTICK_PERIOD_MS ); // Espera medio segundo
    digitalWrite(8, LOW);    // Apaga el led
    vTaskDelay( 500 / portTICK_PERIOD_MS ); // Espera medio segundo
  }
}
