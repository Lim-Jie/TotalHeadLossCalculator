#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class HeadLossMinor {
	double diameter;
	double volumetricFlow;
	double area;
	double KeyValuesArray[6];
	double V_Val;
	double HMinorResult;
	
public:
    
	double main() {
        double K_Val = KValue();
        double A_Val = Calculate_A_Value();
        V_Val = Calculate_V_Value(A_Val);
		
		double KeyValues[6] = {K_Val,getDiameter(),getVolumetricFlow() , V_Val, A_Val , Calculate_H_Minor(K_Val, V_Val) };
		InitializeArray(KeyValues);
		
		
        return Calculate_H_Minor(K_Val, V_Val);
    }

    double Calculate_H_Minor(double k, double v) {
        double g = 9.81;
        double result = (k * pow(v, 2)) / (2 * g);
        HMinorResult= result;
        
        return result;
    }

    double KValue() {
        double K = 0.00;
        double input;

        while (true) {
            cout << "Enter a value to add (enter 0 to stop): ";
            cin >> input;

            if (input == 0.00) {
                break;
            }

            K += input;
        }

        cout << "The sum of all added values is: " << K << std::endl;
        cout << endl;
        return K;
    }

    double Calculate_V_Value(double a) {
        double q;
        double v;
        cout << "Enter q, Volumetric Flow Rate: (Enter 0 to switch insertion to v, velocity): ";
        cin >> q;
        volumetricFlow=q;
        
        if(q==0){
			 cout << "Enter v, velocity: ";
			 cin >> v;
		}else{
			v = q/a;
		}

        
        return v;
    }

    double Calculate_A_Value() {
        double d = 0.00;
        cout << "Enter d, Diameter: ";
        cin >> d;
		diameter=d;
		
        double a = (M_PI * pow(d, 2)) / 4;
        return a;
    }
    

    
    double getDiameter(){
    	return diameter;
	}
	
	double getVelocity(){
		return V_Val;
	}
	
	double getVolumetricFlow(){
		return volumetricFlow;
	}
	
	double getResult(){
		return HMinorResult;
	}
    
   void InitializeArray(const double KeyValues[]) {
        std::copy(KeyValues, KeyValues + 6, KeyValuesArray);
    }
    
   void DisplayHeadLossMinorArray() const {
   		cout << endl;
        string KeyNames[6] = {"K losses", "diameter, d", "volumetric flow rate, q", "velocity, v", "area, a", "Head Loss Minor, h"};

        // Display KeyNames and corresponding values from KeyValuesArray
        for (int i = 0; i < 6; ++i) {
            cout << KeyNames[i] << ": " << KeyValuesArray[i] << endl;
        }
    }
    
    

    
    
    
    
    
};


class HeadLossMajor{
public: 
	double LengthOfPipe;
	double velocity;
	double F;
	double diameter;
	
	void main(){
		
		cout << "Enter Length Of Pipe: ";
 		cin >> LengthOfPipe;
 		
		cout << "Enter Darcy Frictional Force: ";
 		cin >> F;
 		
 		cout << "\n" << endl;
 		
	}
	
	double CalculateHeadLossMajor(){
		double result =  (F*LengthOfPipe* pow(velocity,2))/(2*9.81*diameter);
		
		return result;	
	}
	
	void getDiameter(double Diameter){
		diameter= Diameter;
	}
	void getVelocity(double Velocity){
		velocity= Velocity;
	}
	
	
	
	
};













int main() {
    HeadLossMinor HeadLossMinorObject;
    double result = HeadLossMinorObject.main();
    HeadLossMinorObject.DisplayHeadLossMinorArray();
    cout<< "______________________________________________________________________ \n" << endl;
    
    HeadLossMajor HeadLossMajorObject;
    HeadLossMajorObject.main();
    HeadLossMajorObject.getVelocity(HeadLossMinorObject.getVelocity());
    HeadLossMajorObject.getDiameter(HeadLossMinorObject.getDiameter());
    HeadLossMajorObject.CalculateHeadLossMajor();

    
    double TotalHeadLoss= HeadLossMajorObject.CalculateHeadLossMajor() + HeadLossMinorObject.getResult();
    
    

    cout << "Head Minor Loss Result: " << result << endl;
    
    
    cout << "Head Major Loss Result: " <<  HeadLossMajorObject.CalculateHeadLossMajor() << endl;
    
    cout << "Total Head Loss: " << TotalHeadLoss << endl; 

    return 0;
}
