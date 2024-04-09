import time
import os
import psutil

class Tracker:
    def __init__(self):
        self.start_time = time.time() * 1000
        self.process = psutil.Process(os.getpid())
        self.start_memory = self.process.memory_info().rss // 1024

    def reset(self):
        self.start_time = time.time() * 1000
        self.start_memory = self.process.memory_info().rss // 1024

    def elapsed_time(self):
        return time.time() * 1000 - self.start_time

    def memory_usage(self):
        return (self.process.memory_info().rss - self.start_memory) // 1024

tracker = Tracker()
# Initialize variables and parse values into BigInteger class
first = 5555123456789987654321
second = 2222987654321123456789

# Calculate execution time and memory usage of sum operation
print("Sum value = " + str(first + second))
print(f"Elapsed time: {tracker.elapsed_time()} ms")
print(f"Memory usage: {tracker.memory_usage()} KB")

# Calculate execution time and memory usage of subtract operation
tracker.reset()
print("Subtract value = " + str(first - second))
print(f"Elapsed time: {tracker.elapsed_time()} ms")
print(f"Memory usage: {tracker.memory_usage()} KB")

# Calculate execution time and memory usage of multiply operation
tracker.reset()
print("Multiply value = " + str(first * second))
print(f"Elapsed time: {tracker.elapsed_time()} ms")
print(f"Memory usage: {tracker.memory_usage()} KB")

# Calculate execution time and memory usage of divide operation
tracker.reset()
print("Divide value = " + str(first // second))
print(f"Elapsed time: {tracker.elapsed_time()} ms")
print(f"Memory usage: {tracker.memory_usage()} KB")

# Calculate execution time and memory usage of modulo operation
tracker.reset()
print("Modulo value = " + str(first % second))
print(f"Elapsed time: {tracker.elapsed_time()} ms")
print(f"Memory usage: {tracker.memory_usage()} KB")

# Calculate execution time and memory usage of power operation
tracker.reset()
print("Power value = " + str(10**1000))
print(f"Elapsed time: {tracker.elapsed_time()} ms")
print(f"Memory usage: {tracker.memory_usage()} KB")
