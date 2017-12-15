// Men and women are represented by integers 1...N

// ManPref is the preference list of all men for all women.
// ManPref[m][i] = w : w is at ith position in the preference list of m

// WomanPref is the preference list of all women for all men.
// WomanPref[w][i] = m : m is at ith position in the preference list of w

// Ranking gives the ranking of each man in the preference list of each woman
// Ranking[w][m] = i : WomanPref[w][i] = m

// Current gives the current engagement of each women
// Current[w] = m : w is currently engaged to m

// Next gives the index of next woman to propose to in the preference list of each man
// Next[m] = i : m has proposed to all w s.t. ManPref[m][j] = w for j = 1...i-1 but not ManPref[m][i]
int Ranking[505][505], ManPref[505][505], WomanPref[505][505], Next[505], Current[505];

void GayleShapley()  {
    int T, N, i, j, m, w;

    // list of men who are not currently engaged
    queue <int> freeMen;

	for (i = 0; i <= N; i++) //alle vrouwen
		for (j = 0; j <= N; j++) //alle mannen
			Ranking[i][WomanPref[i][j]] = j; //in de ranking van vrouw i, alle mannen als value rank

	for (i = 0; i <= N; i++) //alle mannen
		freeMen.push(i); //op queue
		Next[i] = 0;	//het volgende aanzoek van de man begint bij zijn nr 1
	

	while (!freeMen.empty()) //zolang niet empty
		m = freeMen.front(); //kopieer man van queue
		w = ManPref[m][Next[m]++]; //zijn volgende vrouw voor aanzoek
		if (Current[w] == 0)   //is ze single, haal man van singles hoop en verloof
			Current[w] = m;
			freeMen.pop();
		 else if (Ranking[w][m] < Ranking[w][Current[w]])  //als niet single, kijk of deze beter
			freeMen.pop(); //als deze beter was, haal hem van de singles hoop
			freeMen.push(Current[w]); //smijt de andere arme afgewezen stakker erop
			Current[w] = m; //verloof

}