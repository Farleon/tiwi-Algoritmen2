void KMPSearch(char *pat, char *txt){
    int M = strlen(pat);
    int N = strlen(txt);
    // longest prefix suffix wordt in lps opgeslaan
    //For the pattern "AABAACAABAA", lps[] is [0, 1, 0, 1, 2, 0, 1, 2, 3, 4, 5]	
    int lps[M];
 
    // Bereken de lps van het te zoeken pattern
    computeLPSArray(pat, M, lps);
 
    int i = 0;  // index for txt[]
    int j  = 0;  // index for pat[] 
	//Overloop heel de text
    while (i < N)
    {
		//Als pattern gelijk is met text, schuif op
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
		//Als gevonden
        if (j == M)
        {
            printf("Found pattern at index %d n", i-j);
			//Schuif pattern op
            j = lps[j-1];
        }
		//Als we niet op het einde zijn en er is een mismatch
        else if (i < N && pat[j] != txt[i])
        {
            // Do not match lps[0..lps[j-1]] characters
            // they will match anyway
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
}

void computeLPSArray(char *pat, int M, int *lps)
{
    // length of the previous longest prefix suffix
    int len = 0;
 
    lps[0] = 0; // lps[0] is always 0
 
    // Overloop alle karakters
    int i = 1;
    while (i < M)
    {
	//Als de karakters hetzelfde zijn, is er een langere prefix suffix
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
	//De karakters zijn verschillend
        else{
            //Als de lengte niet nul is, kijken we of een kortere mogelijk is
            if (len != 0){
                len = lps[len-1];
            }
	    //De lengte is nul, we zoeken naar een volgende prefix suffix
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}