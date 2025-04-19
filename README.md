![Quant PRNG Bench Banner](assets/readmeBanner.png)
# Quant PRNG Bench

Modular C++ project featuring:

- 📦 `libprng`: Custom pseudorandom number generators (LCG, Xorshift, etc.)
- 🧪 `libbench`: Microbenchmark utilities to test the performance of the PRNG algorithms
- 🧬 `test/`: Unit tests powered by GoogleTest + CTest
- 🧠 Designed for reproducibility, modularity, and quant-oriented engineering

```bash
mkdir build && cd build
cmake ..
make
ctest      # Run all unit tests
