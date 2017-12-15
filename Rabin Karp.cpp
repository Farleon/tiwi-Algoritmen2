#define d 256
 
/* pat -> pattern
    txt -> text
    q -> A prime number
*/
void search(char pat[], char txt[], int q)
{
    int M = strlen(pat);
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;
 
    //Bereken de hash
    for (int i = 0; i < M-1; i++)
        h = (h*d)%q;
        
    //Bereken de starthashes
    for (int i = 0; i < M; i++)
    {
        p = (d*p + pat[i])%q;
        t = (d*t + txt[i])%q;
    }
    // Slide over de text
    for (int i = 0; i <= N - M; i++)
    {
        //Is de hash hetzelfde
        if ( p == t )
        {
            //Vergelijk de characters
            for (int j = 0; j < M; j++)
            {
                if (txt[i+j] != pat[j])
                    break;
            }
            //Gevonden
            if (j == M)
                printf("Pattern found at index %d \n", i);
        }
        //Zolang we niet heel de tekst overlopen hebben
        if ( i < N-M )
        {
            //Bereken de nieuwe hash, deze kan negatief zijn
            t = (d*(t - txt[i]*h) + txt[i+M])%q;
            
            if (t < 0)
                t = (t + q);
        }
    }
}