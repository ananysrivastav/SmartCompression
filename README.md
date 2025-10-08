# SmartCompression 💾

**SmartCompression** is a command-line file compression and decompression utility built in C, utilizing the **Huffman Coding** algorithm for lossless data compression.

## 🚀 How it Works

The project reads an input file, calculates character frequencies, builds an optimal Huffman Tree, generates variable-length codes, and writes the compressed output (as a sequence of '0's and '1's). It can then read the encoded file and decode it back to the original content using the tree structure.

***

## 📂 Project Structure

| Directory | Contents | Files |
| :--- | :--- | :--- |
| **src/** | C Source Code (Implementation) | `main.c`, `frequency.c`, `min_heap.c`, `huffman_tree.c`, `code_generation.c`, `encoding.c`, `decoding.c` |
| **include/** | C Header Files (Prototypes/Definitions) | `common.h`, `frequency.h`, `min_heap.h`, `huffman_tree.h`, `code_generation.h`, `encoding.h`, `decoding.h` |
| **docs/** | Project Documentation/Reports | *e.g., `project_report.pdf`, diagrams* |

*Note: The executable (`SmartCompression`), the input file (`input.txt`), and the output files (`encoded.txt`, `decoded.txt`) reside in the root directory.*

***

## 🔨 Build & Run

### Prerequisites

You need a C compiler installed (like `gcc`).

### 1. Create the Input File

The program expects an input file named `input.txt` to be present in the root directory.

```bash
echo "This is a sample file to be compressed." > input.txt
