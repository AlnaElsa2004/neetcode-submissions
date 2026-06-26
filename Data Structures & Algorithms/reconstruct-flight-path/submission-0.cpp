class Solution {
public:
    unordered_map<string, vector<string>> adj;
    vector<string> res;

    bool dfs(string src, int n) {
        if (res.size() == n + 1)
            return true;

        if (adj.find(src) == adj.end())
            return false;

        vector<string> temp = adj[src];

        for (int i = 0; i < temp.size(); i++) {
            string v = temp[i];

            // Use the ticket
            adj[src].erase(adj[src].begin() + i);
            res.push_back(v);

            if (dfs(v, n))
                return true;

            // Backtrack
            res.pop_back();
            adj[src].insert(adj[src].begin() + i, v);
        }

        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end());

        for (auto& t : tickets) {
            adj[t[0]].push_back(t[1]);
        }

        res.push_back("JFK");
        dfs("JFK", tickets.size());

        return res;
    }
};