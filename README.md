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
| **docs/** | Project Documentation/Reports | `PROJECT_PROPOSAL_DS_.docx` |

*Note: The executable (`SmartCompression`), the input file (`input.txt`), and the output files (`encoded.txt`, `decoded.txt`) reside in the root directory.*

***

## 🔨 Build & Run

### Prerequisites

You need a C compiler installed (like `gcc`).

### Terminal Usage Preview

To build and run the project, follow these steps in your terminal:

1.  **Create Input File:** The project requires a file named `input.txt`.
    ```bash
    echo "This is a sample file to compress." > input.txt
    ```

2.  **Compile:** Compile all source files (`src/*.c`) and include headers (`-I include`).
    ```bash
    gcc src/*.c -I include -o SmartCompression
    ```

3.  **Run:** Execute the program. It automatically compresses `input.txt` to `encoded.txt` and then decodes it to `decoded.txt`.
    ```bash
    ./SmartCompression
    ```

### Output

After running, two new files will appear in the root directory:
* `encoded.txt`: The raw binary code output.
* `decoded.txt`: The reconstructed, original text.

***

## 🧹 Cleanup

To remove the compiled executable and the generated output files:

```bash
rm -f SmartCompression encoded.txt decoded.txt
