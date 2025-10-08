# SmartCompression 💾

**SmartCompression** is a command-line file compression and decompression utility built in C, utilizing the **Huffman Coding** algorithm for lossless data compression. The program is designed to visibly demonstrate the reduction in file size achieved through efficient variable-length encoding by reporting the compression ratio at runtime.

***

## 🚀 How it Works

The project reads an input file, calculates character frequencies, builds an optimal Huffman Tree, generates variable-length codes, and writes the compressed output (as a sequence of '0's and '1's). The `main` program now includes logic to calculate and display the **original size** and **encoded size** at runtime to demonstrate the compression ratio.

***

## 📂 Project Structure

| Directory | Contents | Files |
| :--- | :--- | :--- |
| **src/** | C Source Code (Implementation) | `main.c`, `frequency.c`, `min_heap.c`, `huffman_tree.c`, `code_generation.c`, `encoding.c`, `decoding.c`, **`common_utils.c`** |
| **include/** | C Header Files (Prototypes/Definitions) | `common.h`, `frequency.h`, `min_heap.h`, `huffman_tree.h`, `code_generation.h`, `encoding.h`, `decoding.h` |
| **docs/** | Project Documentation/Reports | `PROJECT_PROPOSAL_DS_.docx` |

*Note: The executable (`SmartCompression`), the input file (`input.txt`), and the output files (`encoded.txt`, `decoded.txt`) reside in the root directory.*

***

## 🔨 Build & Run

### Prerequisites

You need a C compiler installed (like `gcc`).

### Terminal Usage Preview

To build and run the project for a **realistic compression test**, follow these updated steps in your terminal:

1.  **Generate Large Input File:** Execute this single block of commands to create the large `input.txt` file (50KB+) required for testing.

    ```bash
    # Creates a temporary file, repeats its content 200 times into input.txt, and cleans up.
    echo "This is a large file for testing the Huffman Compression algorithm. The quick brown fox jumps over the lazy dog repeatedly. We need sufficient repetition to observe a good compression ratio." > sample.txt && > input.txt && for i in {1..200}; do cat sample.txt >> input.txt; done && rm sample.txt
    ```

2.  **Compile:** Compile all source files, **including the new `common_utils.c`**, and link headers.

    ```bash
    gcc src/*.c src/common_utils.c -I include -o SmartCompression
    ```

3.  **Run:** Execute the program. The runtime output will automatically display the file size comparison and compression summary.

    ```bash
    ./SmartCompression
    ```

### Formatted Terminal Output

```terminal
[STATUS] Original file size: 66000 bytes (64.45 KB)
[RESULT] Encoded file size: 40000 bytes (39.06 KB)
[SUMMARY] Compression Ratio (Encoded/Original): 60.61%
[SUMMARY] Space Saved: 25.39 KB
[STATUS] Decoding encoded file...
[STATUS] Decoding complete. Output in 'decoded.txt'.
After running, two new files will appear in the root directory:
* `encoded.txt`: The raw binary code output (the compressed file).
* `decoded.txt`: The reconstructed, original text.

```

🧹 Cleanup

To remove the compiled executable and the generated output files:

```bash
rm -f SmartCompression encoded.txt decoded.txt
