#include <Wire.h> // Memanggil library untuk komunikasi I2C
#define alamatSlave 0x50 // Alamat Slave untuk Arduino 
int dataSlave = 0; // menampung data komunikasi antara master dan slave 

void setup() {
  SystemClock_Config();
  Wire.begin(alamatSlave); // Memulai komunikasi I2C pada PIN A4 dan PIN A5
  Wire.onRequest(requestEvents); // Memanggil fungsi ketika Slave menerima nilai dari Master
  Wire.onReceive(receiveEvents); // Memanggil fungsi ketika Master meminta nilai dari Slave
  Serial.println("ProgressTech");
  Serial.begin(115200); // Memulai komunikasi serial pada baud rate 9600
  
}

void requestEvents() {
  dataSlave = dataSlave + 1; // Menambahkan angka satu ke variabel komunikasi antara master dan slave
  Serial.println("Slave menerima permintaan dari Master");
  Serial.print("Mengirimkan nilai : "); // Menampilkan konten pada Serial Monitor 
  Serial.println(dataSlave); // Menampilkan konten pada Serial Monitor 
  Wire.write(dataSlave); // Slave mengirimkan data kepada Master
}

void receiveEvents(int jumlahByte) {
  while (Wire.available()) {
    char dataSlava = Wire.read();
    Serial.print("Nilai diterima : "); // Menampilkan konten pada Serial Monitor
    Serial.println(dataSlava); // Menampilkan konten pada Serial Monitor
  }
}

void loop() {
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

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}
