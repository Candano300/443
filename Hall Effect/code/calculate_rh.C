{
// Since E = V/d , the equation 
// E_h = R_h * j * B can be rewritten as 
// V/d = R_h * j * B  , which can also be rewritten as 
// R_h = V/B / (d * j) 
// where d = 1.0 cm +- 0.05 cm
// 

// R_h = V/B * t / I  , where 

 t =  1 * 1e-3 ;
 d = 1.0 * 1e-2; // m
 i = 87 * 1e-3; //


// We can simply find R_h with its uncertainty through this equation. 
// Let's plug in the previous findings we had for the V/B , which is 

 vb1 =  0.658 ;
 rh1 = vb1 * t / i ;

// and the other is 

 vb2 =  6.54709*1e-01 ;
 rh2 = vb1 * t / i  ;


cout << "R_h 1: " << vb1 * t / i << endl;
cout << "R_h 2: " << vb2 * t / i  << endl; 

// in order to calculate the uncertainty of R_h, we can model B as a function f where 
// f = X_i * X_y * X_z ... having each of their uncertainties, we can find the uncertainty of f by
// (sigma f / f )^2 = sum (sigma X_i / X_i )^2

sigmavb1 = 0.0175;
sigmavb2 = 0.0337;
sigmat = 0.2 * 1e-3 ;
sigmaI = 0.1 * 1e-3 ;

// Let's calculate the sigmarh1 and rh2 without defining a function since it is unable to be done so in ROOT macros and use the disgusting and unncesessarily long C++ notation
sigmarh1 =  sqrt(pow( sigmavb1 /vb1 ,2)+ pow( sigmat / t ,2) + pow( sigmaI / i ,2) ) * sqrt(pow(rh1,2));
sigmarh2 =  sqrt(pow( sigmavb2 /vb2 ,2)+ pow( sigmat / t ,2) + pow( sigmaI / i ,2)  ) * sqrt(pow(rh2,2));


cout << "Sigma R_h 1 : " << sigmarh1 << endl; 
cout << "Sigma R_h 2 : " << sigmarh2 << endl; 

 w1 = 1 / pow(sigmarh1 , 2 );
 w2 = 1 / pow(sigmarh2 , 2 );

weightedmean = (rh1*w1 + rh2*w2) / (w1 + w2) ; 

cout << "Weighted mean: " <<  weightedmean << endl;

// for the other part where V and I is the variable, the hall current can be calculated with the formula
// R_h = V/I *  t / B , with 
B = 67.6 * 1e-3 ; // Tesla 
sigmaB = B * 0.05 ; 
 
//vi = 5.07055e-01 ; // V / I was calculated in variable_current_calibrated.C

uncalibratedvi = 2.12279e-01; 
uncalibratedrh3 = uncalibratedvi * t / B ; 
sigmauncalibratedrh3 = sqrt(pow( 2.55020e-06 /uncalibratedvi,2)+ pow( sigmat / t ,2) + pow( sigmaB / B ,2)  ) * sqrt(pow(rh1,2));


cout << "Uncalibrated Rh3 : " << uncalibratedrh3 << endl;  
cout << "Sigma Uncalibrated Rh3 : " << sigmauncalibratedrh3 << endl; 


vi = 5.07055e-01;
sigmavi =  6.22248e-04  ;
rh3 = vi * t / B ; 
sigmarh3 =  sqrt(pow( sigmavi /vi ,2)+ pow( sigmat / t ,2) + pow( sigmaB / B ,2)  ) * sqrt(pow(rh1,2));

cout << "R_h 3 : " << rh3 << endl;
cout << "Sigma R_h 3 : " << sigmarh3 << endl; 


final_error = weightedmean - rh3 / sigmarh3 ;
cout << "weightedmean - rh3 : " << weightedmean - rh3 << endl;
cout << "Final error : "  << final_error << endl;




// Also, in order to find Mu_H , mobility of the major charge carriers, we will use the equation 
// mu = conductivity * r_h 
// where conductivity is calculated from the poillet's law as 
// A = 1.0 *1e-2  * 1.0 * 1e-3 
// l = 2.5 * 1e-2
// rho = R * A / l
// conductivity = 1 / rho 
R = 4.48727e+01 ;
A = 1.0 *1e-2  * 1.0 * 1e-3;
l = 2.5 * 1e-2;
rho = R * A / l;
conductivity = 1 / rho ;
mu = conductivity * weightedmean;
cout << "Mu : " <<  mu << endl;

// thickness error 0.2 mm , 
sigmaA =  sqrt(pow( 0.05 /1.0 *1e-2 ,2)+ pow( 0.2e-3 / 1e-3 ,2))* A;
sigmaR = 5.61681e-02;
sigmamu =  sqrt(pow( sigmaA /A ,2)+ pow( sigmaR / R ,2) + pow( 0.05 / l ,2)  ) * sqrt(pow(mu,2));
cout << "Sigma mu : " << sigmamu << endl;

}