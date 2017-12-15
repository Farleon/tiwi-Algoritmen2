class BoyerMoore{
    vector<int> BCTable;
    vector<int> GSTable;
    string naald;
};

BoyerMoore::BoyerMoore(const string& naald) : naald(naald), BCTable(256, -1) {
    BCConstruction(naald);
    GSConstruction(naald);
}
void BoyerMoore::BCConstruction(const string &naald) {
    //Alle values van BCTable staan default op -1, dit betekent dat ze niet voorkomen
    for (int i=0; i<naald.length(); i++) {
        //Zet voor elk karakter dat voorkomt zijn index waarop hij voorkomt
        //Indien hij meerdere malen voorkomt willen we de hoogste index
        BCTable[naald.at(i)] = i;
    }
}
void BoyerMoore::GSConstruction(const string &naald) {
    vector<int> suffix(naald.length()+1);
    suffix[naald.length()] = naald.length() + 1;
    //Overloop elk karakter van de naald, van achter naar voor
    for(int i=naald.length()-1; i>=0; i--) {
        //Methode die naald.length in de suffix tabel steekt, tenzij een pattern
        //herhaald wordt, dan steekt het lengte naald - lengte herhaald erin
        int vorigIndex = suffix[i+1];
        while (vorigIndex <= naald.length() && naald.at(vorigIndex-1) != naald.at(i)) {
            vorigIndex = suffix[vorigIndex];
        }
        suffix[i] = vorigIndex - 1;
    }
    //We willen in de suffix niet de getallen die we hierboven hebben, maar de hoeveelheid
    //dat we moeten verschuiven van vanachter
for (int i=0; i<naald.length(); i++) {
        suffix[i] = naald.length() - suffix[i];
    }
    //In GSTable opslaan hoeveel daadwerkelijk moet worden opgeschoven indien de BC op die index zit
    GSTable = vector<int>(naald.length()+1, naald.length() - suffix[0]);
    for (int j=0; j<naald.length(); j++) {
        int i = naald.length() - suffix[j] - 1;
        int verplaatsing = i+1-j;
        if (GSTable[naald.length()] > verplaatsing) {
            GSTable[i+1] = verplaatsing; // alles 1 plek naar rechts verschuiven dan komt -1 op plek 0
        }
    }
}
std::queue<int> BoyerMoore::zoek(const string &hooiberg) {
    queue<int> gevondenPosities;
    int indexText = 0;
    while (indexText <= hooiberg.length() - naald.length()) {
        //Zoek de index in de naald van de bad character
        int indexBC = BCZoek(indexText, hooiberg);
        int BCInTekst = indexText + indexBC;
        int verschuifBC;
        //Als zijn index -1 is, hebben we hem gevonden
        if (indexBC == -1) {
            gevondenPosities.push(indexText);
            verschuifBC = 1;
        } 
        //Anders moeten we aangeven hoeveel we moeten verschuiven
        else {
            verschuifBC = indexBC - BCTable[hooiberg.at(BCInTekst)];
        }
        int verschuifGS = GSTable[indexBC+1];
        indexText += (verschuifBC < verschuifGS ? verschuifGS : verschuifBC);
    }
    return gevondenPosities;
}
int BoyerMoore::BCZoek(long int indexText, const string &tekst) {
    int indexPattern = naald.length() - 1;
    indexText += naald.length()-1;
    //Vergelijk van achter naar voor
    while (indexPattern >= 0 && naald.at(indexPattern) == tekst.at(indexText)) {
        indexPattern--;
        indexText--;
    }
    return indexPattern;
}