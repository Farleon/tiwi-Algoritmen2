struct Edge {
  int head;
  long cost;
};
using Graph = vector<vector<Edge>>; g[src][0] = head=dest, cost=weight;

void HierholzerEulercirquit(Graph& g)
{
    // bewaar voor elke knoop zijn aantal verbindingen
    unordered_map<int,int> edge_count;
 
    for (int i=0; i<g.size(); i++)
        edge_count[i] = g[i].size();
    
    //De stack van het current path
    stack<int> curr_path;
 
    //Het finale cirquit
    vector<int> circuit;
 
    // start van een willekeurige knoop, de 0e
    curr_path.push(0);
    int huidige = 0; // Current vertex
	
	
    while (!curr_path.empty())
    {
        //Zolang onze huidige knoop verbindingen heeft
        if (edge_count[huidige]){
			//smijt de huidige knoop op het pad
            curr_path.push(huidige);
 
            //de volgende knoop
            int volgende = g[huidige].back();
 
            //haal die verbinding eraf
            edge_count[curr_v]--;
            g[huidige].pop_back();
 
            // Move to next vertex
            huidige = volgende;
        }
        else{
			//voeg toe aan uiteindelijk pad
            circuit.push_back(huidige);
 
            // Back-tracking
            huidige = curr_path.top();
            curr_path.pop();
        }
    }
 
    // we've got the circuit, now print it in reverse
    for (int i=circuit.size()-1; i>=0; i--)
    {
        cout << circuit[i];
        if (i)
           cout<<" -> ";
    }
}