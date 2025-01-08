#include <Wire.h>

// MPU6050 I2C address
const int MPU = 0x68; 

int16_t gyroX, gyroY, gyroZ;

void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B); // Access power management register
  Wire.write(0);    // Wake up the MPU6050
  Wire.endTransmission(true);
  
  Serial.begin(9600);
}

void loop() {
  // Start transmission to MPU6050
  Wire.beginTransmission(MPU);
  Wire.write(0x43); // Starting register address for gyroscope data
  Wire.endTransmission(false);
  
  // Request 6 bytes of gyroscope data
  Wire.requestFrom(MPU, 6, true);

  // Read raw gyroscope data
  gyroX = Wire.read() << 8 | Wire.read(); // Combine high and low bytes
  gyroY = Wire.read() << 8 | Wire.read();
  gyroZ = Wire.read() << 8 | Wire.read();
  
  // Print gyroscope data to the Serial Monitor
  Serial.print("Gyro X: ");
  Serial.print(gyroX);
  Serial.print(" | Gyro Y: ");
  Serial.print(gyroY);
  Serial.print(" | Gyro Z: ");
  Serial.println(gyroZ);

  delay(500); // Add a delay for better readability
}
