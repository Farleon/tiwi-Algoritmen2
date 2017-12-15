using Graph = vector<vector<int>>;//g[src][dest] = cost

Warshall(Graph& g){
	//vector met uitkomst
	vector<vector<int>> path(g.size());
	for(int i = 0 ; i<g.size();i++)
		path[i] = new vector(g.size());
	
	//overloop alle verbindingen
	for (int i = 0; i < g.size(); i++)
		for (int j = 0; j < g.size(); j++)
			path[i][j].head] = g[i][j]; //pad van src naar dest : cost
	
	for (int k = 0; k < g.size(); k++)
        for (int i = 0; i < g.size(); i++)
            if (path[i][k] != 0) //als er een pad is van i naar k
				//overloop dan alles voor i
                for (int j = 0; j < g.size(); j++)
                    path[i][j] = path[i][j] || path[k][j];

	//result zit in path
}