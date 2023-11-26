{

YELLOW = "\033[33m";
BOLD = "\033[1m";
RESET = "\033[0m";
cout << YELLOW << BOLD << "\nCALCULATIONS FOR THE EXPERIMENT : APPLICATIONS OF LASERS " << RESET << endl;

// DATA ; PART 1

vector <double> y_025mm_left    = {0.4 , 0.8 , 1.2 , 1.6 }  ;
vector <double> y_025mm_right   = {0.4 , 0.8 , 1.2 , 1.6 }  ;

vector <double> y_050mm_left    = {0.2 , 0.4 ,  0.6 , 0.8 } ; 
vector <double> y050mm_right    = {0.1 , 0.3 ,  0.5 , 0.7 } ;

vector <double> y_single_left   = {1.1 , 2.0 , 2.7 , 3.3 }  ;
vector <double> y_single_right  = {0.6 , 1.2 , 1.7 , 2.5 }  ;

vector <double> y_hair_left     = {0.7 , 1.5 , 2.3 , 3.1 }  ;
vector <double> y_hair_right    = {0.8 , 1.6 , 2.2 , 3.1 }  ;

// taking the average of each vaue from left and right, we get ; 

vector <double> y025mm      =  {0.4 , 0.8 , 1.2 , 1.6 }  ;
vector <double> y050mm      =  {0.2 , 0.4 ,  0.6 , 0.8 } ;
vector <double> ysingleslit =  {0.9 , 1.6 , 2.2 , 2.7 }  ;
vector <double> yhair       =  {0.8 , 1.6 , 2.3 , 3.1 }  ;

double sigmay = 0.1e-2;  // sigma y is the same for each y value , 0.1 cm


double lambda , d , D , n , y , sigmalambda;
double sumoflambdas = 0 , sumofweights = 0 ; 
double sigmaD = 0.1e-2;

// lambda = d*y / D*n 
// if sigmay = 0.1 cm , sigmaD = 0.1 cm , sigmad = 0  and sigmaD = 0 , from error propogation formula :
// sigmalambda = sqrt(pow(d/D*n,2) * pow(sigmay,2) + pow( - d * y / n * ( - 1 / D^2) , 2) * pow(sigmaD,2) )

// Weighted mean and the definition of its sigma is from : https://en.wikipedia.org/wiki/Weighted_arithmetic_mean

cout << BOLD <<  "\nLambda Values for Double Slit with d = 0.25 mm , D = 150.3 cm" << RESET << endl; 
for ( size_t i = 0 ; i < y025mm.size() ; ++ i  ){
    d = 0.25e-3;
    D = 150.3e-2;
    n = i + 1;
    y = y025mm[i]*1e-2;
    
    lambda = d * y / (D * n) ;
    sigmalambda = sqrt(pow((d / D * n), 2) * pow(sigmay, 2) + pow(d * y / n * (1 / pow(D,2)) , 2 ) * pow(sigmaD, 2));
    cout  << "n = " << n << " : "  << lambda << "\t+-\t" << sigmalambda << " m" << endl;

    sumoflambdas += lambda * (1 / pow(sigmalambda,2));
    sumofweights += (1 / pow(sigmalambda,2));
};

cout << "\nmean     : " << sumoflambdas/sumofweights << "\t+-\t" << sqrt(1/sumofweights)  << " m" << endl;
cout << "expected : " << 650e-9  << "\t\t\t    m" << endl;
cout << "error    : " << ((sumoflambdas/sumofweights)- 650e-9)/sqrt(1/sumofweights) << "\t\t\t    m"  << endl;



cout << BOLD <<  "\nLambda Values for Double Slit with d = 0.50 mm , D = 150.3 cm " << RESET << endl; 
sumoflambdas = 0 , sumofweights = 0 ; 
for ( size_t i = 0 ; i < y050mm.size() ; ++ i  ){
    d = 0.50e-3;
    D = 150.3e-2;
    n = i + 1;
    y = y050mm[i]*1e-2;
    
    lambda = d * y / (D * n) ;
    sigmalambda = sqrt(pow((d / D * n), 2) * pow(sigmay, 2) + pow(d * y / n * (1 / pow(D,2)) , 2 ) * pow(sigmaD, 2));
    cout  << "n = " << n  << " : "  << lambda << "\t+-\t" << sigmalambda << " m"<< endl;

    sumoflambdas += lambda * (1 / pow(sigmalambda,2));
    sumofweights += (1 / pow(sigmalambda,2));
};

cout << "\nmean     : " << sumoflambdas/sumofweights << "\t+-\t" << sqrt(1/sumofweights) << " m" << endl;
cout << "expected : " << 650e-9 << "\t\t\t    m" << endl;
cout << "error    : " << ((sumoflambdas/sumofweights)- 650e-9)/sqrt(1/sumofweights) << "\t\t\t    m" << endl;



cout << BOLD << "\nLambda Values for Single Slit with d = 0.16 mm , D = 150.3 cm " << RESET << endl; 
sumoflambdas = 0 , sumofweights = 0 ; 
for ( size_t i = 0 ; i < ysingleslit.size() ; ++ i  ){
    d = 0.16e-3;
    D = 150.3e-2;
    n = i+1 + 0.5 ;
    y = ysingleslit[i]*1e-2;
    lambda = d * y / (D * n) ;
    sigmalambda = sqrt(pow((d / D * n), 2) * pow(sigmay, 2) + pow(d * y / n * (1 / pow(D,2)) , 2 ) * pow(sigmaD, 2));
    cout  << "n = " <<  n << " : "  << lambda << "\t+-\t" << sigmalambda << " m"<< endl;

    sumoflambdas += lambda * (1 / pow(sigmalambda,2));
    sumofweights += (1 / pow(sigmalambda,2));
};

cout << "\nmean     : " << sumoflambdas/sumofweights << "\t+-\t" << sqrt(1/sumofweights) << " m" << endl;
cout << "expected : " << 650e-9 << "\t\t\t    m"<< endl;
cout << "error    : " << ((sumoflambdas/sumofweights)- 650e-9)/sqrt(1/sumofweights)  << "\t\t\t    m" << endl;


// for hair; 
// thickness = n * lambda  * D / y
// sigmathickness = sqrt(pow( n * lambda / y ,2 ) * pow(sigmaD,2) + pow( n * lambda * D / pow(y,2) , 2) * pow(sigmay,2)  ) 


cout << BOLD << "\nThickness of hair from Single Slit with d = 0.16 mm , D = 91.2 cm " << RESET << endl; 
double sumofthickness = 0 , sumofweight = 0 ;
double thickness, sigmathickness; 
for ( size_t i = 0 ; i < yhair.size() ; ++ i  ){
    D = 91.2e-2;
    lambda = 6501e-9;
    n = i + 1 ; 
    y = yhair[i]*1e-2;
    thickness = n * lambda * D / y ;
    sigmathickness = sqrt(pow( n * lambda / y , 2 ) * pow(sigmaD,2) + pow( n * lambda * D / pow(y,2) , 2) * pow(sigmay,2)  );
    cout << "n = " << i + 1 << " : " << thickness << "\t+-\t" << sigmathickness << " m"<< endl;

    sumofthickness += thickness * (1 / pow(sigmathickness,2));
    sumofweight += (1 / pow(sigmathickness,2));
};

cout << "\nmean  : " << sumofthickness/sumofweight << "\t+-\t" << sqrt(1/sumofweight) << " m" << endl;


// DATA ; PART 2 

vector<double> count = { 20  , 30  , 40  , 50  , 60  , 70  , 90  ,  100  , 110};
vector<double> degree = {5.0 , 6.0 , 7.0 , 8.0 , 8.5 , 9.3 , 10.1 , 11.1 , 12.1 } ; 
d = 0.55 * 1e-2 ; 
lambda = 632.8 * 1e-9;


vector<double> calibrated_degree ; 
for ( size_t i = 0 ; i < degree.size() ; ++ i ){
    calibrated_degree.push_back(degree[i] - 0.6);
};


cout << BOLD << "\nRefractive Index of Glass " << RESET << endl; // expected value is 1.515 
double sumn = 0 , sumweight = 0 ;
for (size_t i = 0 ; i < count.size() ; ++ i ){
    double m = count[i]; 
    double degree = calibrated_degree[i];
    double cos = TMath::Cos(degree * M_PI / 180); // convert to radians 
    n = (d - m*lambda/2 )*(1 - cos) / ( d*(1-cos)-m*lambda / 2);

    double sin = TMath::Sin(degree * M_PI / 180); 
    double sigmam = 2 ; 
    double sigmatheta = 0.1 * M_PI / 180; // 0.1 degree error in theta , in radians!

    // Calculate the error in n ;
    double dndtheta = ( ((d - m * lambda / 2) * sin)* (d*(1-cos) - m*lambda/2) - ( (d-m*lambda/2)*(1-cos)* d*sin ) )  / pow(d*(1-cos)-m*lambda/2 , 2) ; 
    double dndm = (1-cos)*(-lambda/2)*(d*(1-cos) - m*lambda/2) + (d-m*lambda/2)*(1-cos)*lambda/2 / pow(d * (1-cos) - m * lambda /2 , 2) ;
    double sigman = sqrt(pow(dndtheta,2) * pow(sigmatheta,2) + pow(dndm,2) * pow(sigmam,2));

    cout << i +1 << " : " << "n = " << n << " \t+-\t " << sigman << endl;
    
    sumn += n * (1 / pow(sigman,2));
    sumweight += (1 / pow(sigman,2));

};

cout << "\nmean     : " << sumn/sumweight << "\t+-\t" << sqrt(1/sumweight) << endl;
cout << "expected : " << 1.515 << endl;
cout << "error    : " << ( 1.515 - (sumn/sumweight))/sqrt(1/sumweight) << endl;

//  pfund's method; 

double glassthickness = 0.55 * 1e-2; // cm
double diameter = 2.0 * 1e-2; // cm
double nwater = 1.33; // refractive index of water

cout << BOLD << "\nRefractive Index of Glass using Pfund's Method " << RESET << endl; // expected value is 1.515

n =  sqrt( 1 + pow(4 * glassthickness/diameter, 2));

cout << "n = " << n  << "\n" << endl;


    
 };