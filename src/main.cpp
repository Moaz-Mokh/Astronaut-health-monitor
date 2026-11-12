#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    // initialize the variables

    int systBP, diaBP, hr, rr, bs, spO2 ;
    double t , sleep , riskper , totalhr , totalrr , totalbs , totalspO2 , totalt , totalsleep, totalriskper , totalriskp ;
    double riskp=0.0;
    int Tdays=0;
    string date;

    cout << "Welcome Astronaut! Enter the date: ";
    cin >> date;

    cout << "\nIt is " << date << "." << endl;
    cout << "Let's check your vitals for the day!" << endl;


    // Enter the vitals and there status

    cout << "\nEnter your Systolic Blood Pressure: ";
    cin >> systBP;

    cout << "Enter your Diastolic Blood Pressure: ";
    cin >> diaBP;

    cout << "Your Blood Pressure is "
         << systBP << "/" << diaBP << " mmHg" << endl;

    if (systBP < 90 || diaBP < 60)
    {
        cout << "Blood Pressure Status: LOW" << endl;
    }
    else if (systBP > 120 || diaBP > 80)
    {
        cout << "Blood Pressure Status: HIGH" << endl;
    }
    else
    {
        cout << "Blood Pressure Status: NORMAL" << endl;
    }

 
    cout << "\nEnter your Respiratory Rate: ";
    cin >> rr;

    cout << "Your Respiratory Rate is "
         << rr << " breaths/min" << endl;

    if (rr < 12)
    {
        cout << "Respiratory Rate Status: LOW" << endl;
    }
    else if (rr > 20)
    {
        cout << "Respiratory Rate Status: HIGH" << endl;
    }
    else
    {
        cout << "Respiratory Rate Status: NORMAL" << endl;
    }

    cout << "\nEnter your Temperature (C): ";
    cin >> t;

    cout << "Your Temperature is "
         << t << " C" << endl;

    if (t < 36.1)
    {
        cout << "Temperature Status: LOW" << endl;
    }
    else if (t > 37.2)
    {
        cout << "Temperature Status: HIGH" << endl;
    }
    else
    {
        cout << "Temperature Status: NORMAL" << endl;
    }

    cout << "\nEnter your Heart Rate: ";
    cin >> hr;

    cout << "Your Heart Rate is "
         << hr << " bpm" << endl;

    if (hr < 60)
    {
        cout << "Heart Rate Status: LOW" << endl;
    }
    else if (hr > 100)
    {
        cout << "Heart Rate Status: HIGH" << endl;
    }
    else
    {
        cout << "Heart Rate Status: NORMAL" << endl;
    }

    cout << "\nEnter your Blood Sugar: ";
    cin >> bs;

    cout << "Your Blood Sugar is "
         << bs << " mg/dL" << endl;

    if (bs < 70)
    {
        cout << "Blood Sugar Status: LOW" << endl;
    }
    else if (bs > 100)
    {
        cout << "Blood Sugar Status: HIGH" << endl;
    }
    else
    {
        cout << "Blood Sugar Status: NORMAL" << endl;
    }

    cout << "\nEnter your Sleep Hours: ";
    cin >> sleep;

    cout << "You slept for "
         << sleep << " hours" << endl;

    if (sleep < 7)
    {
        cout << "Sleep Status: INSUFFICIENT" << endl;
    }
    else if (sleep > 9)
    {
        cout << "Sleep Status: OVERSLEEPING" << endl;
    }
    else
    {
        cout << "Sleep Status: BALANCED" << endl;
    }

    cout << "\nEnter your Blood Oxygen (SpO2): ";
    cin >> spO2;

    cout << "Your Blood Oxygen is "
         << spO2 << "%" << endl;

    if (spO2 < 95)
    {
        cout << "Blood Oxygen Status: LOW" << endl;
    }
    else
    {
        cout << "Blood Oxygen Status: NORMAL" << endl;
    }

    // Risk percentage 

    if(systBP<=120 && systBP>=90 && diaBP>=60 && diaBP<=80)
    {
        riskp+=0;

    }
    else if ( ( systBP<=89 && systBP>=85 ) || (systBP>=121 && systBP<=130) || ( diaBP>=55 && diaBP <=59 ) || ( diaBP >=81 && diaBP<=85) )
    {
        riskp+=0.5;
    }
    else if((systBP<=84 && systBP>=80 ) || ( systBP<=140 && systBP>=131) || ( diaBP<=54 && diaBP>= 50 ) || ( diaBP<=90 && diaBP>=86))
    {
        riskp+=1;
    }
    else
    {
        riskp+=3;
    }
    
    if((hr<=100)&&(hr>=60))
    {
        riskp+=0;
    }
    else if((hr<=110 && hr>=101) || (hr<= 59 && hr>=50 ))
    {
        riskp+=0.5;
    
    }
    else if((hr<=130 && hr>=111) || (hr<=49 && hr>=40))
    {
        riskp+=1 ;

    }
        
    else
    {
        riskp+=3;
    }


    if((rr>=12&&rr<=20))
    {
        riskp+=0;
    }
    else if((rr<=24 && rr>=21) || (rr<=11  && rr>=10))
    {
        riskp+=0.5;
    }
    else if ((rr<=30 && rr>=25) || ( rr<=9 && rr>= 8))
    {
        riskp+=1;
    }
    else
    {
        riskp+=3;

    }

    if((t<=37.2 && t>= 36.1))
    {
        riskp+=0;
    }
    else if ((t<=37.8 && t>=37.3) || (t<=36 && t>=35.5))
    {
        riskp+=0.5;
    }
    else if ((t<=38.5 && t>=37.9) || (t<=35.4 && t>=35))
    {
        riskp+=1;

    }
    else
    {
        riskp+=3;
    }    


    if((bs<=100 && bs>=70))
    {
        riskp+=0;

    }
    else if((bs<=110 && bs>=101) || (bs<=69 && bs>=60))
    {
        riskp+=0.5;
    }

    else if((bs<=59 && bs>=50) || ( bs<= 125 && bs>= 111 ))
    {
        riskp+=1;
    }

    else
    {
        riskp+=3;
    }

    if ((sleep<=9 && sleep>=7 ))
    {
        riskp+=0;
    }
    else if ((sleep<= 6.9 && sleep >= 6) || (sleep<= 10 && sleep>=9.1))
    {
        riskp+=0.5;
    }
    else if ((sleep<=5.9 && sleep>= 5) || ( sleep<=11 && sleep>=10.1))
    {
        riskp+=1;
    }
    else
    {
        riskp+=3;
    }

    if((spO2<=100 && spO2>=95))
    {
        riskp+=0;
    }
    else if ((spO2<=94 && spO2>=92))
    {
        riskp+=0.5;
    }
    else if ((spO2<=91 && spO2>=88))
    {
        riskp+=1;
    }
    else
    {
        riskp+=3;
    }

    cout<<" Your risk score is "<<riskp<<"/24";
    riskper=(riskp/24.0)*100;
    cout<<" Your risk percentage is " <<riskper;


    ofstream storefile("astronaut-data.csv",ios::app);   // storing the data in the CSV file 

    storefile<<date<<","
    <<systBP<<","
    <<diaBP<<","
    <<hr<<","
    <<rr<<","
    <<bs<<","
    <<spO2<<","
    <<t<<","
    <<sleep<<","
    <<riskper<<","
    <<riskp
    <<endl;

    storefile.close();
    cout<<"\n Data is stored in the data base"<<endl;


   ifstream readFile("astronaut-data.csv"); // reading the stored data in the CSV file

string line;

getline(readFile, line);

while(getline(readFile, line))
{
    cout << line << endl;

    stringstream ss(line);     //splits the stored data

    string value;
    int column=0;

    cout << "\nSPLIT VALUES:\n";

    while(getline(ss, value, ','))   // Takes the needed data and find the total then adds the days and finds the average
    {
        if(column==3)
        {
            totalhr+=stod(value);
        }
        if(column==4)
        {
            totalrr+=stod(value);
        }
        if(column==5)
        {
            totalbs+=stod(value);
        }
        if(column==6)
        {
            totalspO2+=stod(value);
        }
        if(column==7)
        {
            totalt+=stod(value);
        }
        if(column==8)
        {
            totalsleep+=stod(value);
        }
        if(column==9)
        {
            totalriskper+=stod(value);
        }
        if(column==10)
        {
            totalriskp+=stod(value);
        }
        
        column++;
        cout << "[" << value << "]" << endl;
    }
    Tdays+=1;
}
readFile.close();
double avghr=totalhr/Tdays , avgrr=totalrr/Tdays , avgbs=totalbs/Tdays , avgspO2=totalspO2/Tdays, avgt=totalt/Tdays , avgsleep=totalsleep/Tdays ,avgriskper=totalriskper/Tdays , avgriskp=totalriskp/Tdays ;
cout  
<<"\nAverage hear rate = " <<avghr
<<"\nAverage respiratory rate =" <<avgrr
<<"\nAverage blood sugare =" <<avgbs
<<"\nAverage oxygen in the blood "<<avgspO2
<<"\nAverage temperature ="<<avgt
<<"\nAverage sleep =" <<avgsleep
<<"\nAverage risk points =" <<avgriskp
<<"\nDays since mission = "<<Tdays
<<endl;




return 0;
}











