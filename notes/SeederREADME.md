**🧪 PRNG Seeder Design & Strategy**
In any pseudorandom number generation (PRNG) system, the seed is the critical initial value that determines the output sequence. The quality and unpredictability of this seed directly impacts the statistical integrity and security of the PRNG. This phase of the project focuses on designing and benchmarking various seeding strategies.

**🔑 Seeding Methodologies**
**1. Explicit Seeding**
Involves manually supplying a predefined seed value.
Ideal for debugging and deterministic testing, as it guarantees reproducible output.
Useful for unit testing and baseline performance comparisons.

**2. Implicit Seeding (System-Driven)**
Relies on external system sources such as:
System time (std::chrono)
CPU cycle counters
Advantage: Automatic variability between runs.
Limitation: If the time resolution is coarse, multiple initializations in quick succession may reuse the same seed, reducing randomness.

**3. Entropy-Based Seeding**
Sources seeds from inherently unpredictable system-level data:
Process ID
Memory addresses
User input timing
Higher randomness, but may still be guessable in controlled environments.

**4. Hashed Hybrid Seeding**
Combines multiple weak entropy sources (e.g., time + PID) and hashes them using a cryptographic hash function (e.g., SHA-256).
Advantage: Strengthens weak inputs and reduces predictability.
Optional: Use libraries like OpenSSL or libsodium for secure, high-performance hash implementations.

**🧱 Seeder Implementation Plan
I will implement three distinct Seeder classes:**
ImplicitSeeder	Uses the current high-resolution system time as a seed source.
EntropySeeder	Combines process-level entropy (e.g., PID, memory data).
HashedSeeder	Aggregates time and entropy sources, then applies a cryptographic hash.
Explicit seeding will be handled manually, as it serves mainly for testing and reproducibility.

**📊 Benchmarking & Evaluation Goals
Each Seeder will be evaluated on:**
Execution Time – How quickly the seed is generated.
Memory Utilization – Overhead introduced during seeding.
Randomness Distribution – Measured by statistical uniformity across repeated runs.
Additional testing will include:
Consistency under stress conditions
Performance under concurrent calls
Pairing performance with different PRNG algorithms
