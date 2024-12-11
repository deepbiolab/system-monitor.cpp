import time
import multiprocessing
import psutil

def cpu_intensive_task():
    # 计算密集型任务
    while True:
        [x**2 for x in range(10000)]

def monitor_cpu():
    print("Initial CPU Usage:", psutil.cpu_percent(interval=1), "%")
    
    # 创建与 CPU 核心数量相同的进程
    processes = []
    cpu_count = multiprocessing.cpu_count()
    
    print(f"\nStarting {cpu_count} CPU intensive processes...")
    for _ in range(cpu_count):
        p = multiprocessing.Process(target=cpu_intensive_task)
        p.start()
        processes.append(p)
    
    # 监控 10 秒
    print("\nMonitoring CPU Usage:")
    print("Time     | CPU Usage")
    print("---------|----------")
    
    for _ in range(10):
        cpu_usage = psutil.cpu_percent(interval=1)
        current_time = time.strftime("%H:%M:%S")
        print(f"{current_time} |   {cpu_usage:>5.1f}%")
    
    # 结束所有进程
    print("\nStopping CPU intensive processes...")
    for p in processes:
        p.terminate()
        p.join()
    
    print("\nFinal CPU Usage:", psutil.cpu_percent(interval=1), "%")

if __name__ == "__main__":
    monitor_cpu()
