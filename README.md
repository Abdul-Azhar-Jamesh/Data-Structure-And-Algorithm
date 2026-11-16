# Data Structures and Algorithms in C++

C++17 implementations and demonstrations of stacks, queues, a priority queue, heap sort, graphs and a binary search tree.

## Project map

| Directory | Topic |
| --- | --- |
| `stack/` | Stack implementations and demos |
| `queue/` | Linked queue and demo |
| `priority_queue/` | Priority queue and demo |
| `heap_sort/` | Heap sort and demo |
| `Graph/` | Graph representation and demo |
| `BST/` | Binary search tree and demo |

`main.c++` selects the demonstration. The current entry point runs the BST demo; other demo calls are commented out.

## Build status

Use CMake with a C++17 compiler:

```sh
cmake -S . -B build
cmake --build build
```

The executable is named `DsaCodeRepo`; its location depends on the generator and configuration. Use a C++17 compiler and CMake.

## Learning goals

Read each implementation alongside its demo. Document the supported operations, ownership/copy behavior, expected complexity and error behavior. Useful checks include empty operations, one-element transitions, repeated insert/remove cycles and duplicate BST values.

Generated build files and binaries are excluded from source control.
