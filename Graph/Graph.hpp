#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <stack>
#include <vector>
#include "List.hpp"

enum STATUS {FAILED = 0, SUCCESS = 1};

class Graph {
private:
    struct edgeNode {
        int v;
        edgeNode(int v_) : v{v_} {}
        edgeNode() : v{0} {}
    };

    int n_vertices;
    int n_edges;
    List<edgeNode *> *adjList;

    Graph() : n_vertices{0}, n_edges{0}, adjList{nullptr} {}

public:
    static Graph* create_graph(std::string path);
    void bfs(int s);
    void dfs(int s);
    void print();
    ~Graph() {
        if (adjList) {
            for (int i = 0; i < n_vertices; ++i) {
                edgeNode *node;
                for (bool status = adjList[i].begin(node); status != false; status = adjList[i].getNext(node)) {
                    delete node;
                }
            }
            delete[] adjList;
        }
    }
};

Graph* Graph::create_graph(std::string path)
{
    std::ifstream in{path};

    if (!in) {
        std::cerr << "File Open Failed " << std::endl;
        std::cerr << "Check File : " << path << std::endl;
        return nullptr;
    }

    Graph *G = new Graph();
    std::string line;
    int u, v;
    int n_vertices_, n_edges_;

    if (!std::getline(in, line)) {
        std::cerr << "Vertex Information Missing " << std::endl;
        delete G;
        return nullptr;
    }
    {
        std::istringstream iss(line);
        if (!(iss >> n_vertices_) || (iss >> std::ws && !iss.eof())) {
            std::cerr << "Vertex Information Missing : Instead found " << line << '\n';
            delete G;
            return nullptr;
        }
    }

    if (!std::getline(in, line)) {
        std::cerr << "Edge Information Missing" << std::endl;
        delete G;
        return nullptr;
    }
    {
        std::istringstream iss(line);
        if (!(iss >> n_edges_) || (iss >> std::ws && !iss.eof())) {
            std::cerr << "Edge Information Missing : Instead Found  " << line << '\n';
            delete G;
            return nullptr;
        }
    }

    std::cout << "n_vertices : " << n_vertices_ << " " << "n_edges : " << n_edges_ << std::endl;

    G->adjList = new List<edgeNode *>[n_vertices_];
    G->n_vertices = n_vertices_;
    G->n_edges = n_edges_;

    edgeNode *node;

    while (std::getline(in, line)) {
        std::istringstream iss(line);

        if (!(iss >> u >> v) || (iss >> std::ws && !iss.eof())) {
            std::cerr << "Parsing Failed : Check Content for Format " << std::endl;
            continue;
        }
        if ((u >= n_vertices_) || (v >= n_vertices_)) {
            std::cerr << "Nodes Should be between " << 0 << " and " << n_vertices_ - 1 << std::endl;
            delete G;
            return nullptr;
        }

        node = new edgeNode(v);
        G->adjList[u].add(node);
    }
    return G;
}

void Graph::print()
{
    edgeNode *node;

    for (int u = 0; u < n_vertices; u++) {
        std::cout << u << " : ";
        for (bool status = adjList[u].begin(node); status != false; status = adjList[u].getNext(node)) {
            std::cout << node->v << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::bfs(int s)
{
    std::vector<bool> visited(n_vertices, false);
    std::queue<int> q;

    visited[s] = true;
    q.push(s);

    std::cout << "BFS starting from vertex " << s << ": ";

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        std::cout << u << " ";

        edgeNode *node;
        for (bool status = adjList[u].begin(node); status != false; status = adjList[u].getNext(node)) {
            int v = node->v;
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    std::cout << std::endl;
}

void Graph::dfs(int s)
{
    std::vector<bool> visited(n_vertices, false);
    std::stack<int> st;

    st.push(s);

    std::cout << "DFS starting from vertex " << s << ": ";

    while (!st.empty()) {
        int u = st.top();
        st.pop();

        if (!visited[u]) {
            visited[u] = true;
            std::cout << u << " ";

            edgeNode *node;
            std::vector<int> neighbors;
            for (bool status = adjList[u].begin(node); status != false; status = adjList[u].getNext(node)) {
                neighbors.push_back(node->v);
            }
            for (auto it = neighbors.rbegin(); it != neighbors.rend(); ++it) {
                if (!visited[*it]) {
                    st.push(*it);
                }
            }
        }
    }
    std::cout << std::endl;
}

#endif