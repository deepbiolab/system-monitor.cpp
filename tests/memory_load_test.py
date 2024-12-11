import time
import psutil
import numpy as np

def get_memory_usage():
    return psutil.virtual_memory().percent

def memory_intensive_task(target_percentage=70):
    print("Initial Memory Usage:", get_memory_usage(), "%")
    
    # 获取系统总内存
    total_memory = psutil.virtual_memory().total
    current_usage = psutil.virtual_memory().used
    
    # 计算需要分配多少内存才能达到目标使用率
    target_usage = (total_memory * target_percentage / 100)
    needed_memory = max(0, target_usage - current_usage)
    
    # 创建数组列表以控制内存使用
    arrays = []
    chunk_size = 100 * 1024 * 1024  # 100MB chunks
    
    print("\nGradually increasing memory usage...")
    print("Time     | Memory Usage")
    print("---------|-------------")
    
    try:
        while get_memory_usage() < target_percentage:
            # 分配内存
            arrays.append(np.zeros(chunk_size // 8, dtype=np.float64))
            
            # 打印当前内存使用情况
            current_time = time.strftime("%H:%M:%S")
            memory_usage = get_memory_usage()
            print(f"{current_time} |    {memory_usage:>5.1f}%")
            
            time.sleep(1)
    
    except MemoryError:
        print("Memory allocation failed - system limit reached")
    
    print("\nTarget memory usage reached or exceeded")
    print("Final Memory Usage:", get_memory_usage(), "%")
    
    # 保持内存使用一段时间
    print("\nMaintaining memory usage for 10 seconds...")
    for _ in range(10):
        current_time = time.strftime("%H:%M:%S")
        memory_usage = get_memory_usage()
        print(f"{current_time} |    {memory_usage:>5.1f}%")
        time.sleep(1)
    
    # 清理内存
    print("\nCleaning up...")
    arrays.clear()
    time.sleep(1)
    print("Final Memory Usage:", get_memory_usage(), "%")

if __name__ == "__main__":
    memory_intensive_task(90)  # 目标70%内存使用率
