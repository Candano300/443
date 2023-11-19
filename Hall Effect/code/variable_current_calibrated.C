{

    vector <double> current = {11,	25,	37,	48,	52,	60,	68,	77,	84,	70,	56,	42,	64,	72,	81,	84}; // mA 
    vector <double> voltage = {1.9,	4.2,	6.3,	8.2,	9.0,	10.4,	11.9,	13.7,	15.5,	12.9,	10.0,	7.5,	11.5,	13.1,	14.9,	15.9 };

    // calibrated voltage = observed voltage - the voltage caused by the assymetry of the probes, which is modeled as
    // calibrated voltage = V1 - R*I 
    vector<double> calibrated_voltage;
 
        for (size_t i = 0; i < current.size(); ++i) {
            calibrated_voltage.push_back(voltage[i] - current[i]* 6.96787*1e-01);
        };


    vector <double> sigmacurrent = {0.1 , 0.1 , 0.1 , 0.1 , 0.1 , 0.1 , 0.1,0.1,0.1,0.1,0.1,0.1 } ;
    
    vector<double> sv ; 

    for (double i : voltage){
       sv.push_back(std::sqrt(std::pow(i * 0.3 / 100 , 2 ) + std::pow( 9.73697*1e-04 ,2) ) );
    } 


    TCanvas *c1 = new TCanvas("V vs I", "V vs I");
    c1 -> SetGrid();

    TGraphErrors *graph  = new TGraphErrors(voltage.size() , current.data() , calibrated_voltage.data() , sigmacurrent.data() , sv.data()) ;
    graph->SetTitle("Voltage vs Current");
    graph->GetXaxis()->SetTitle("Current (mA)");
    graph->GetYaxis()->SetTitle("Voltage (mV)");
	graph -> SetMarkerColor(kBlue);
	graph -> SetMarkerSize(1);
	graph -> SetLineWidth(1);


	
	TF1 *fitfonksiyonu = new TF1("fitfunc" , "[0]*x + [1]", 0, 90 );
    fitfonksiyonu -> SetLineColor(kBlue);
    fitfonksiyonu -> SetLineWidth(2);
	fitfonksiyonu -> SetParameters(-1,0);
	
    
    graph -> Fit(fitfonksiyonu);
	graph -> Draw("AP");
	fitfonksiyonu -> Draw("SAME");

	gStyle -> SetOptFit(1111);

    c1->SaveAs("~/Desktop/variable_current_calibrated.pdf");
    c1->SaveAs("~/Desktop/variable_current_calibrated.png");








}