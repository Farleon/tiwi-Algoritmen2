void doDEZ(int currentknoop, std::function<void(const Knoop &, int)> bezoek, Order order, std::vector<bool> &bezocht) {
    bezocht[currentknoop] = true;
    if (order == Order::PREORDER) {
        bezoek(knopen[currentknoop], currentknoop);
    }
    for (auto knoop : knopen[currentknoop]) {
        if (!bezocht[knoop.first]) {
            doDEZ(knoop.first, bezoek, order, bezocht);
        }
    }
    if (order == Order::POSTORDER) {
        bezoek(knopen[currentknoop], currentknoop);
    }
}

void bezoekDEZ(int beginKnoop, std::function<void(const Knoop &, int)> bezoek, Order order) {
    std::vector<bool> bezocht(this->aantalKnopen(), false);
    doDEZ(beginKnoop, bezoek, order, bezocht);
}


void GraafMetKnoopEnTakdata<RT, Knoopdata, Takdata>::wordt_componentengraaf_van(
        GraafMetKnoopEnTakdata<RT, Knoopdata, Takdata> &graaf){
    // stap 1: keer verbindingen graaf om
    GraafMetKnoopEnTakdata<RT, Knoopdata, Takdata> omgekeerde;
    keerom(omgekeerde, graaf);
    *this = graaf;

    // zorg dat graaf zeker samenhangend is door knoop toe te voegen en te verbinden met alle knopen
    int rootKnoop = omgekeerde.voegKnoopToe();
    for (int i=0; i<graaf.aantalKnopen(); i++) {
        omgekeerde.voegVerbindingToe(rootKnoop, i);
    }

    // stap 2: DEZ knopen postorder nummeren op omgekeerde graaf startend vanaf toegevoegde knoop
    std::vector<int> postorder;
    omgekeerde.bezoekDEZ(rootKnoop, [&postorder](const typename Graaf<RT>::Knoop& knoop, int knoopNummer){
        postorder.push_back(knoopNummer);
    }, POSTORDER);

    // haal rootknoop uit resultaat
    postorder.pop_back();

    // stap 3: DEZ in met beginknoop in volgorde van postorder nummering uit vorige stap
    std::vector<bool> bezocht(this->aantalKnopen(), false);
    int componentNummer = 0;
    for (int i=postorder.size()-1; i>=0; i--) {
        if (!bezocht[postorder[i]]) {
            graaf.doDEZ(postorder[i], [this, &componentNummer, &bezocht](const  typename Graaf<RT>::Knoop& knoop, int knoopNummer){
                this->componentnummer[knoopNummer] = componentNummer;
                bezocht[knoopNummer] = true;
            }, POSTORDER, bezocht);
            componentNummer++;
        }
    std::cout << "aantal componenten: " << componentNummer << std::endl;
    }
};
