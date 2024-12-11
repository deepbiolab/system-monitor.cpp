#include "processor.h"

#include "linux_parser.h"

// DONE: Return the aggregate CPU utilization
float Processor::Utilization() {
  long total = LinuxParser::Jiffies();
  long idle = LinuxParser::IdleJiffies();

  if (total < prev_total_ || idle < prev_idle_) {
    prev_idle_ = idle;
    prev_total_ = total;
    return 0.0;
  }

  float totald = total - prev_total_;
  float idled = idle - prev_idle_;

  prev_idle_ = idle;
  prev_total_ = total;

  if (totald <= 0) {
    return 0.0;
  }

  float utilization = (totald - idled) / totald;

  return std::max(0.0f, std::min(1.0f, utilization));
}