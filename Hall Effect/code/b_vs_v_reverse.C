{

    vector <double> b = {12.45,	30.9,	43.7,	62.2,	71.4,	84.5,	19.4,	68.0,	79.8,	41.4};  
    vector <double> v = {-56.5,	-43.9,	-35.7,	-23.9, -18.0,	-8.7,	-52.2,	-20.1,	-12.5,	-37.7};
    vector<double> sv ; 

    for (double i : voltage){
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
	fitfonksiyonu -> SetParameters(1,0);
	graph -> Fit(fitfonksiyonu);

	

	graph -> Draw("AP");
	fitfonksiyonu -> Draw("SAME");



    c1->SaveAs("~/Desktop/b_vs_v_reverse.C.pdf");
    c1->SaveAs("~/Desktop/b_vs_v_reverse.C.png");








}