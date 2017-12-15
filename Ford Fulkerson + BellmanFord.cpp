struct Edge {
  int head;
  long cost;
};

using Graph = vector<vector<Edge>>; g[src][0] = head=dest, cost=weight;

Johnson(Graph &g){
	int s = 1;
	g.add(s);
	vector<int> s_to_all; //de afstanden van s naar iedere destination
	s_to_all = BellmanFord(g,s); //Bepaal met bellman ford de afstanden
	
	//Overloop alle verbindingen
	for(int i = 0; i < g.size(); i++)
		for (auto &e : g[i]) {
			//nieuwe cost is originele cost + cost naar i - cost naar dest
			e.cost = e.cost + s_to_all[i] - s_to_all[e.head];
	
	//Vind korste paden met dijkstra
	vector<vecotr<int> result;
	for(int i = 0; i < g.size(); i++)
		result[i] = dijkstra(g,i) //geeft een vector<int> : d[dest] = weight vanuit src
	
	//Overloop terug alle verbindingen
	for(int i = 0; i < g.size(); i++)
		for(int j = 0; j < g[src].size(); j++)
			if(result[i][j] != MAX_INT)
				result[i][j] += ssp[i] - ssp[j];
			
	//result
}

vector<int> BellmanFord(Graph &g, int src ){
	vector<int> dist(g.size(), INT_MAX);
	dist[src] = 0;
	queue<int> q;
    q.push( src );
	//zolang de queue niet leeg is
    while( !q.empty() ) {
			//haal eentje van de queue
            int curr = q.front();
            q.pop();
			//als deze meer dan n-1 keer bezocht is hebben we een lus, stop ma
            if( ++count[curr] > n - 1 ) return 0;  
			//als het gewicht niet oneindig is, kunnen we kijken of we ev. buren 
			//kunnen verbeteren
            if(dist[curr] != INT_MAX) {
					//overloop alle verbindingen van de current
					for (auto &e : g[i]) {
						int dest = e.first;
						int weight = e.second;
						//als de nieuwe afstand beter is
                         if( dist[dest] > dist[curr] + weight) {
                             dist[dest] = dist[curr] + weight; //update
                             q.push( y ); //bekijk ook deze jongen zijn buren eens
                         }
                 }
            }
	return dist;
}