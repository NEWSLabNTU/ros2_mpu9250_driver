#ifndef __LINUXI2CCOMMUNICATOR_H__
#define __LINUXI2CCOMMUNICATOR_H__

#include <chrono>
#include "I2cCommunicator.h"

class LinuxI2cCommunicator final : public I2cCommunicator {
 public:
  LinuxI2cCommunicator(int bus_number = 1);
  ~LinuxI2cCommunicator();
  int read(unsigned char address) final;
  int write(unsigned char address, unsigned char value) final;
  char getFile() final;

 private:
  void reportError(int error);
  int file_;
  std::chrono::steady_clock::time_point last_error_time_ = std::chrono::steady_clock::now();
  static constexpr std::chrono::seconds error_interval_{5}; // Print error every 5 seconds
};

#endif  // __LINUXI2CCOMMUNICATOR_H__