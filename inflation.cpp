#include <iostream>
using namespace  std;
//array of inflation percentages from 1960 to 2023 from https://www.macrotrends.net/global-metrics/countries/IND/india/inflation-rate-cpi ,2023 data i got month wise i just took the average 2022 data matched it
float info[64]={0.0178, 0.017, 0.0363, 0.0295, 0.1336, 0.0947, 0.108, 0.1306, 0.0324, -0.0058, 0.0509, 0.0308, 0.0644, 0.1694, 0.286, 0.0575, -0.0763, 0.0831, 0.0252, 0.0628, 0.1135, 0.1311, 0.0789, 0.1187, 0.0832, 0.0556, 0.0873, 0.088, 0.0938, 0.0707, 0.0897, 0.1387, 0.1179, 0.0633, 0.1025, 0.1022, 0.0898, 0.0716, 0.1323, 0.0467, 0.0401, 0.0378, 0.043, 0.0381, 0.0377, 0.0425, 0.058, 0.0637, 0.0835, 0.1088, 0.1199, 0.0891, 0.0948, 0.1002, 0.0667, 0.0491, 0.0495, 0.0333, 0.0394, 0.0373, 0.0662, 0.0513, 0.067,0.0565};
void condition(int a){
     while(a<1960 || a >2024){
        cout<<"I cannot make future predictions nor do i have data from before 1960\n";
        cout<<"enter the starting year (between 1960 and 2024) :\n";
        cin>>a;
    }
}
float inflar(){
    int a,b;
    float c,d;
    cout<<"enter the starting year of  investment(investments before 1960 cannot be counted)\n";
    cin>>a;
    condition(a);
    cout<<"enter the initial investment\n";
    cin>>c;
    cout<<"enter the final year of  investment(final year cannot be in the future because we do not know of the inflation in the future)\n";
    cin>>b;
    condition(b);
    cout<<"enter the returns\n";
    cin>>d;
    a=a-1960;
    b=b-1960;
    if(a>b){cout<<"final year of investment cant be before starting year of investment\n";}
    for(int j=a;j<b;j++){ c = c + info[j]*c;}
    if(c>d){
        cout<<"This is a depreciating investment(bad investment)\n";
        cout<<"The value of your investment has DECREASED by "<<c/d<<" times compared to inflation\nThe net loss is "<<((c-d)/c)*100<<"%\n";
    }
    else if(c==d){cout<<"The value of the investment stays the same with the inflation rates\n";}
    else{
        cout<<"This is a good investment\n";
        cout<<"The value of your investment has INCREASED by "<<d/c<<" times compared to inflation\nThe net gain is "<<((d-c)/c)*100<<"%\n";
    }
}
float inflation(){
    cout<<"enter the starting year (between 1960 and 2024) : \n";
    int year1;
    cin>>year1;
    condition(year1);
    cout<<"enter the amount at that year \n";
    float amount1;
    cin>>amount1;
    cout<<"enter the target year \n";
    int year2;
    cin>>year2;
    condition(year2);
    int n=year1-1960;
    int a=year2-1960;
    //swap with no temp
    if(a<n){
        a = a + n;
        n = a - n;
        a = a - n;}
    for(int j=n;j<a;j++){ amount1 = amount1 + info[j]*amount1;}
    cout<<"The amount adjusted for inflation in "<<year2<<"is : "<<amount1<<" rupees\n";   
}

int main(){
    cout << "WELCOME\n";
    cout << "Type 1 for inflation calculation\n";
    cout << "Type 2 to compare your investments to inflation\n";
    cout << "Type 3 to exit\n";
    int a;
    cin>>a;
    while(a<1 || a>3){cout<<"Invalid input. Please enter 1, 2, or 3\n";cin>>a;}
    if(a==1){inflation();}
    else if(a==2){inflar();}
}