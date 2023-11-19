{

    vector <double> current = {3*1e-3,5*1e-3,11*1e-3,19*1e-3,24*1e-3,30*1e-3 , 35*1e-3,40*1e-3,46*1e-3,50*1e-3,55*1e-3,60*1e-3,65*1e-3 ,70*1e-3}; // mA 
    vector <double> voltage = {0.162 , 0.247 , 0.512 , 0.831 , 1.057 , 1.324 , 1.546 , 1.774 , 2.038 , 2.240 , 2.462 , 2.716 , 2.923, 3.168 };
    vector <double> sigmacurrent(current.size() , 0.1 * 1e-3);

    vector<double> sigmavolt ; 

    for (double i : voltage){
       sigmavolt.push_back(i * 0.3 / 100 / 1000 );
    } 

    TCanvas *c1 = new TCanvas("V vs I", "V vs I");
    c1 -> SetGrid();

    TGraphErrors *graph  = new TGraphErrors(voltage.size() , current.data() , voltage.data() , sigmacurrent.data() , sigmavolt.data()) ;
    graph->SetTitle("Voltage vs Current");
    graph->GetXaxis()->SetTitle("Current (A)");
    graph->GetYaxis()->SetTitle("Voltage (V)");



	graph -> SetMarkerColor(kBlue);

	graph -> SetMarkerSize(1);
	graph -> SetLineWidth(1);


	
	TF1 *fitfonksiyonu = new TF1("fitfunc" , "[0]*x + [1]" , 0 , 5);
    fitfonksiyonu -> SetLineColor(kBlue);
    fitfonksiyonu -> SetLineWidth(2);
	fitfonksiyonu -> SetParameters(1,0);
	graph -> Fit(fitfonksiyonu);

	

	graph -> Draw("AP");
	fitfonksiyonu -> Draw("SAME");

	gStyle -> SetOptFit(1111);
    c1->SaveAs("~/Desktop/resistance.pdf");
    c1->SaveAs("~/Desktop/resistance.png");








}