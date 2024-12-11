#include "linux_parser.h"

#include <dirent.h>
#include <unistd.h>

#include <string>
#include <vector>

using std::stof;
using std::string;
using std::to_string;
using std::vector;

// DONE: An example of how to read data from the filesystem
string LinuxParser::OperatingSystem() {
  string line;
  string key;
  string value;
  std::ifstream filestream(kOSPath);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ' ', '_');
      std::replace(line.begin(), line.end(), '=', ' ');
      std::replace(line.begin(), line.end(), '"', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "PRETTY_NAME") {
          std::replace(value.begin(), value.end(), '_', ' ');
          return value;
        }
      }
    }
  }
  return value;
}

// DONE: An example of how to read data from the filesystem
string LinuxParser::Kernel() {
  string os, version, kernel;
  string line;
  std::ifstream stream(kProcDirectory + kVersionFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> os >> version >> kernel;
  }
  return kernel;
}

// BONUS: Update this to use std::filesystem
vector<int> LinuxParser::Pids() {
  vector<int> pids;
  DIR* directory = opendir(kProcDirectory.c_str());
  struct dirent* file;
  while ((file = readdir(directory)) != nullptr) {
    // Is this a directory?
    if (file->d_type == DT_DIR) {
      // Is every character of the name a digit?
      string filename(file->d_name);
      if (std::all_of(filename.begin(), filename.end(), isdigit)) {
        int pid = stoi(filename);
        pids.push_back(pid);
      }
    }
  }
  closedir(directory);
  return pids;
}

// DONE: Read and return the system memory utilization
float LinuxParser::MemoryUtilization() {
  string line;
  float mem_total{0.0f}, mem_free{0.0f}, buffers{0.0f}, cached{0.0f};
  float shmem{0.0f}, sreclaimable{0.0f};
  string key, value;

  std::ifstream filestream(kProcDirectory + kMeminfoFilename);
  if (!filestream.is_open()) {
    return 0.0;
  }

  while (std::getline(filestream, line)) {
    std::istringstream linestream(line);
    linestream >> key >> value;
    if (key == "MemTotal:") {
      mem_total = stof(value);
    } else if (key == "MemFree:") {
      mem_free = stof(value);
    } else if (key == "Buffers:") {
      buffers = stof(value);
    } else if (key == "Cached:") {
      cached = stof(value);
    } else if (key == "Shmem:") {
      shmem = stof(value);
    } else if (key == "SReclaimable:") {
      sreclaimable = stof(value);
    }

    if (mem_total > 0 && mem_free > 0 && buffers > 0 && cached > 0 &&
        shmem > 0 && sreclaimable > 0) {
      break;
    }
  }

  filestream.close();

  if (mem_total > 0) {
    float cached_memory = cached + sreclaimable - shmem;
    float used = mem_total - mem_free - buffers - cached_memory;
    return used / mem_total;
  }

  return 0.0;
}

// DONE: Read and return the system uptime
long LinuxParser::UpTime() {
  string line;
  long uptime;

  std::ifstream filestream(kProcDirectory + kUptimeFilename);

  if (filestream.is_open()) {
    std::getline(filestream, line);
    std::istringstream linestream(line);
    linestream >> uptime;
    return uptime;  // floor
  }

  return 0;
}

// DONE: Read and return the number of jiffies for the system
long LinuxParser::Jiffies() {
  long idle = IdleJiffies();
  long non_idle = ActiveJiffies();
  return idle + non_idle;
}

// TODO: Read and return the number of active jiffies for a PID
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::ActiveJiffies(int pid [[maybe_unused]]) { return 0; }

// DONE: Read and return the number of active jiffies for the system
long LinuxParser::ActiveJiffies() {
  vector<string> values = CpuUtilization();
  if (!values.empty() && values.size() >= CPUStates::kSteal_) {
    long non_idle = std::stol(values[CPUStates::kUser_]) +
                    std::stol(values[CPUStates::kNice_]) +
                    std::stol(values[CPUStates::kSystem_]) +
                    std::stol(values[CPUStates::kIRQ_]) +
                    std::stol(values[CPUStates::kSoftIRQ_]) +
                    std::stol(values[CPUStates::kSteal_]);
    return non_idle;
  }
  return 0;
}

// DONE: Read and return the number of idle jiffies for the system
long LinuxParser::IdleJiffies() {
  vector<string> values = CpuUtilization();

  if (!values.empty() && values.size() >= CPUStates::kIOwait_) {
    long idle = std::stol(values[CPUStates::kIdle_]) +
                std::stol(values[CPUStates::kIOwait_]);
    return idle;
  }
  return 0;
}

// DONE: Read and return CPU utilization
vector<string> LinuxParser::CpuUtilization() {
  string line;
  std::ifstream filestream(kProcDirectory + kStatFilename);
  if (filestream.is_open()) {
    vector<string> values;
    string cpu, value;
    std::getline(filestream, line);
    std::istringstream linestream(line);
    linestream >> cpu;
    while (linestream >> value) {
      values.push_back(value);
    }
    filestream.close();
    return values;
  }
  return {};
}

// DONE: Read and return the total number of processes
int LinuxParser::TotalProcesses() {
  string line, key;
  int value;
  std::ifstream filestream(kProcDirectory + kStatFilename);

  if (!filestream.is_open()) {
    return 0;
  }

  while (std::getline(filestream, line)) {
    std::istringstream linestream(line);
    linestream >> key >> value;
    if (key == "processes") {
      filestream.close();
      return value;
    }
  }
  filestream.close();
  return 0;
}

// DONE: Read and return the number of running processes
int LinuxParser::RunningProcesses() {
  string line, key;
  int value;
  std::ifstream filestream(kProcDirectory + kStatFilename);

  if (!filestream.is_open()) {
    return 0;
  }

  while (std::getline(filestream, line)) {
    std::istringstream linestream(line);
    linestream >> key >> value;
    if (key == "procs_running") {
      filestream.close();
      return value;
    }
  }
  filestream.close();
  return 0;
}

// TODO: Read and return the command associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Command(int pid [[maybe_unused]]) { return string(); }

// TODO: Read and return the memory used by a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Ram(int pid [[maybe_unused]]) { return string(); }

// TODO: Read and return the user ID associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Uid(int pid [[maybe_unused]]) { return string(); }

// TODO: Read and return the user associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::User(int pid [[maybe_unused]]) { return string(); }

// TODO: Read and return the uptime of a process
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::UpTime(int pid [[maybe_unused]]) { return 0; }
