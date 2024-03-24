master i2c obc 
#include <Wire.h> // Memanggil library untuk komunikasi I2C
#define alamatSlave 0x50 // Alamat Slave untuk Arduino 

char dataMaster[] = "I2Ctest"; // Variabel untuk menampung data komunikasi antara master dan slave 

void setup() {
  SystemClock_Config();
  Wire.begin(); // Memulai komunikasi I2C pada PIN A4 dan PIN A5
  Serial.begin(115200); // Memulai komunikasi serial pada baud rate 9600
  Serial.println("ProgressTech");
}

void loop() {
  // Master mengirimkan nilai ke Slave
  Wire.beginTransmission(alamatSlave); // Master memulai pengiriman data ke alamat slave
  Wire.write("I2Ctest"); // Master menuliskan data
  Serial.print("Master mengirimakn nilai Integer : "); // Menampilkan konten pada Serial Monitor 
  Serial.println("annanta"); // Menampilkan konten pada Serial Monitor 
  Wire.endTransmission(); // Mengakiri sesi pengiriman data 
  delay(1000);

  // Meminta nilai dari slave 
  // Wire.requestFrom(alamatSlave, 1); // Master meminta data dari Slave
  // dataMaster = Wire.read(); // Master membaca data yang dikirimkan oleh Slave
  // Serial.print("Slave mengirimkan nilai : "); // Menampilkan konten pada Serial Monitor 
  // Serial.println(dataMaster); // Menampilkan konten pada Serial Monitor
  delay(1000);
}

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL12;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}
