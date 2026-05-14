class Graph {
private:
    unordered_map<int, unordered_set<int>> adj_list;
    bool dfs(int curr, int dst, unordered_set<int> &visited) {
        if (curr == dst) return true;
        visited.insert(curr);
        for (const int &neighbor : adj_list[curr]) {
            if (visited.find(neighbor) == visited.end()) {
                if (dfs(neighbor, dst, visited)) return true;
            }
        }
        return false;
    }

    bool bfs(int src, int dst) {
        unordered_set<int> visited;
        deque<int> deq = {src};

        while(!deq.empty()) {
            int curr = deq.front();
            deq.pop_front();
            if (curr == dst) return true;
            visited.insert(curr);
            for (const int &neighbor : adj_list[curr]) {
                if (visited.find(neighbor) == visited.end()) {
                    deq.push_back(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
        return false;
    }



public:
    Graph() {}

    void addEdge(int src, int dst) {
        adj_list[src].insert(dst);
    }

    bool removeEdge(int src, int dst) {
        if (adj_list.find(src) == adj_list.end() ||
            adj_list[src].find(dst) == adj_list[src].end())
            return false;
        adj_list[src].erase(dst);
        return true;
    }

    bool hasPath(int src, int dst) {
        //unordered_set<int> visited;
        return bfs(src, dst);
    }
};
