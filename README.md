# Graph Theory Implementations & Library

This repository contains both graph algorithms implementations as well as a fully-functioning library implementing graphs through adjacency lists.

## 📌 Table of Contents

- [Graph Library](#graph-library)
- [Installation](#installation)
- [Usage](#usage)
- [Contribution](#contribution)

## 🛠 Graph Library

The library provides a comprehensive set of functionalities to:

- Create and manipulate directed and undirected graphs
- Perform basic graph traversals
- Apply graph algorithms

This library implements graphs through adjacency lists, providing efficient operations.

## 💽 Installation and Testing

1. Clone the repository:

```bash
git clone https://github.com/VicAlexandre/graph_theory.git
```

2. Navigate and compile:

```bash
cd graph_theory
make
```

3. Test the library:

```bash
./test
```

This will automatically compile both the library and the driver test code.

## 📝 Usage

To use the library in your project, include the necessary header files and link against the provided static library. As for the implementations, currently only a 'test.c' file is available for testing the library, which is still pretty basic and will be further expanded.

## 👥 Contribution

Contributions to any code here are more than welcome, since it's only the beginning of the project!

Note: This project is a work-in-progress. Feedback, suggestions, and contributions are highly appreciated.

## ✨ Features

- [x] Graph representation through adjacency lists of both directed and undirected graphs
- [x] Simple graph printing
- [x] Insertion and deletion of vertices and edges

## ✅ To-do

- [ ] Implement graph traversals (DFS, BFS)
- [ ] Implement graph algorithms (Dijkstra, Prim, Kruskal, etc.)
- [ ] More generic graph representation
- [ ] Tests
- [ ] Documentation
- [ ] More examples
- [ ] Static allocation options for the whole library with emphasis on embedded systems
