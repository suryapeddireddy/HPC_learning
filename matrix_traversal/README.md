# Cache Locality Traversal Benchmark

## 📌 Overview
This mini-project establishes my foundational baseline for **High-Performance Computing (HPC)**. It demonstrates how software memory layouts physically interact with CPU microarchitectures to achieve massive single-core execution speedups.

## 🔬 Core Concept
C++ uses **Row-Major Allocation**, storing 2D matrix rows continuously in a flat 1D memory layout. This benchmark constructs a large `10,000 x 10,000` grid to analyze the extreme performance difference between two layout traversal methods:

* **Row-Major (`matrix[i][j]`):** Iterates along adjacent memory slots. It exploits **64-byte Cache Lines** by loading elements sequentially with high **Cache Hits**.
* **Column-Major (`matrix[i][j]`):** Jumps across columns, skipping chunks of memory. This forces constant **Cache Misses** and expensive roundtrips to main RAM.

## 📊 Local Hardware Benchmark Metrics
*Tested on Local Machine Architecture (Windows PowerShell)*

* **[Row-Major Execution Time]:** **`29.12 ms`** (Optimal Baseline)
* **[Column-Major Execution Time]:** **`826.35 ms`** (**~28x Slower** due to hardware cache line latency)
* **Final Checksum Output:** `100,000,000` (Verified accurate without calculation overflow)

> **HPC Takeaway:** Optimizing single-core memory tracking layouts is a critical prerequisite before introducing multi-threaded parallel complexity. Parallelizing unoptimized layouts will only clog the hardware memory bus.

## 🛠️ Build and Run
```bash
g++ -O3 -std=c++11 src/matrix_benchmark.cpp -o matrix_benchmark.exe
.\matrix_benchmark.exe
```
