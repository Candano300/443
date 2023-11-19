{

    vector <double> current = {10, 15,20,25,30,5,40,45,50,55,65,80}; // mA 
    vector <double> voltage = {-7.2,-10.7 , -14.0,-17.5,-20.8,-24.2,-28.1,-31.5,-35.1,-38.7,-46.3,-57.6 };
    vector <double> sigmacurrent = {0.1 , 0.1 , 0.1 , 0.1 , 0.1 , 0.1 , 0.1,0.1,0.1,0.1,0.1,0.1 } ;
    
    vector<double> sigmavolt ; 

    for (double i : voltage){
       sigmavolt.push_back(i * 0.3 / 100 / 1000 );
    } 



    TCanvas *c1 = new TCanvas("V vs I", "V vs I");
    c1 -> SetGrid();

    TGraphErrors *graph  = new TGraphErrors(voltage.size() , current.data() , voltage.data() , sigmacurrent.data() , sigmavolt.data()) ;
    graph->SetTitle("Voltage vs Current");
    graph->GetXaxis()->SetTitle("Current (mA)");
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

    c1->SaveAs("~/Desktop/voltage_vs_current.pdf");
    c1->SaveAs("~/Desktop/voltage_vs_current.png");







}