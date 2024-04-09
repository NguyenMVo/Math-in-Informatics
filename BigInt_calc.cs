using System;
using System.Diagnostics;
using System.Numerics;

public class BigInt_calc
{
    public static void Main()
    {
        // Initialize variables and parse values into BigInteger class
        string first = "5555123456789987654321", second = "2222987654321123456789";
        BigInteger first_num = BigInteger.Parse(first);
        BigInteger second_num = BigInteger.Parse(second);

        Stopwatch stopwatch = new();

        // Calculate execution time and memory usage of sum operation
        long memoryUsageBefore = GC.GetTotalMemory(true);
        stopwatch.Start();
        BigInteger sumValue = BigInteger.Add(first_num, second_num);
        Console.WriteLine("Sum value = " + sumValue);
        stopwatch.Stop();
        TimeSpan elapsedTime = stopwatch.Elapsed;
        Console.WriteLine("Elapsed time: " + (elapsedTime.TotalSeconds * 1000) + " ms");
        Console.WriteLine("Memory usage before: " + memoryUsageBefore / 1024 + " KB");

        // Calculate execution time and memory usage of subtract operation
        memoryUsageBefore = GC.GetTotalMemory(true);
        stopwatch.Start();
        BigInteger subValue = BigInteger.Subtract(first_num, second_num);
        Console.WriteLine("Subtract value = " + subValue);
        stopwatch.Stop();
        elapsedTime = stopwatch.Elapsed;
        Console.WriteLine("Elapsed time: " + (elapsedTime.TotalSeconds * 1000) + " ms");
        Console.WriteLine("Memory usage before: " + memoryUsageBefore / 1024 + " KB");

        // Calculate execution time and memory usage of multiply operation
        memoryUsageBefore = GC.GetTotalMemory(true);
        stopwatch.Start();
        BigInteger mulValue = BigInteger.Multiply(first_num, second_num);
        Console.WriteLine("Multiply value = " + mulValue);
        stopwatch.Stop();
        elapsedTime = stopwatch.Elapsed;
        Console.WriteLine("Elapsed time: " + (elapsedTime.TotalSeconds * 1000) + " ms");
        Console.WriteLine("Memory usage before: " + memoryUsageBefore / 1024 + " KB");

        // Calculate execution time and memory usage of divide operation
        memoryUsageBefore = GC.GetTotalMemory(true);
        stopwatch.Start();
        BigInteger divValue = BigInteger.Divide(first_num, second_num);
        Console.WriteLine("Divide value = " + divValue);
        stopwatch.Stop();
        elapsedTime = stopwatch.Elapsed;
        Console.WriteLine("Elapsed time: " + (elapsedTime.TotalSeconds * 1000) + " ms");
        Console.WriteLine("Memory usage before: " + memoryUsageBefore / 1024 + " KB");

        // Calculate execution time and memory usage of modulo operation
        memoryUsageBefore = GC.GetTotalMemory(true);
        stopwatch.Start();
        BigInteger modValue = BigInteger.ModPow(first_num, 1, second_num);
        Console.WriteLine("Modulo value = " + modValue);
        stopwatch.Stop();
        elapsedTime = stopwatch.Elapsed;
        Console.WriteLine("Elapsed time: " + (elapsedTime.TotalSeconds * 1000) + " ms");
        Console.WriteLine("Memory usage before: " + memoryUsageBefore / 1024 + " KB");

        // Calculate execution time and memory usage of power operation
        memoryUsageBefore = GC.GetTotalMemory(true);
        stopwatch.Start();
        BigInteger powValue = BigInteger.Pow(10, 1000);
        Console.WriteLine("Power value = " + powValue);
        stopwatch.Stop();
        elapsedTime = stopwatch.Elapsed;
        Console.WriteLine("Elapsed time: " + (elapsedTime.TotalSeconds * 1000) + " ms");
        Console.WriteLine("Memory usage before: " + memoryUsageBefore / 1024 + " KB");
    }
}