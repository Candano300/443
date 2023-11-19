{

    vector <double> v = {31.0,	17.0,	12.3,	37.4,	42.7,	8.2,	11.8,	35.5,	21.3,	25.6}; // mA 
    vector <double> b = {49.6,	71.5,	78.6,	42.0,	33.5,	88.0,	81.4,	42.7,	66.6,	57.7};
    vector<double> sv ; 

    for (double i : v){
       sv.push_back(i * 0.3 / 100 / 1000 );
    } 
    vector <double> sb ; 

    for ( double i : b) {
        sb.push_back( i * 0.05);
    };

    //vector<double> sv ; 

    //for (double i : v){
    //   sv.push_back( std::sqrt(std::pow(i * 5 / 100 , 2)) ) ;
    //};

    TCanvas *c1 = new TCanvas("V vs I", "V vs I");
    c1 -> SetGrid();

    TGraphErrors *graph  = new TGraphErrors(v.size() , b.data() , v.data() , sb.data() , sv.data()) ;
    graph->SetTitle("Voltage vs Magnetic Field at 87 mA");
    graph->GetXaxis()->SetTitle("Magnetic Field (mT)");
    graph->GetYaxis()->SetTitle("Voltage (mV)");



	graph -> SetMarkerColor(kBlue);

	graph -> SetMarkerSize(1);
	graph -> SetLineWidth(1);


	
	TF1 *fitfonksiyonu = new TF1("fitfunc" , "[0]*x + [1]" , 0 , 5);
    fitfonksiyonu -> SetLineColor(kBlue);
    fitfonksiyonu -> SetLineWidth(2);
	fitfonksiyonu -> SetParameters(-1,0);
	graph -> Fit(fitfonksiyonu);

	

	graph -> Draw("AP");
	fitfonksiyonu -> Draw("SAME");

	gStyle -> SetOptFit(1111);

    c1->SaveAs("~/Desktop/b_vs_v.C.pdf");
    c1->SaveAs("~/Desktop/b_vs_v.C.png");






}