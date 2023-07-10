//icluding iostream and the vector and clarifie namespace

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//the parent class
class Product{

    protected:
        string Description;
        float ProductWeight;

    public:
        virtual void PrintDetails() = 0;
        virtual float CalculatePricePerGram() = 0;

        void SetDescription(string Desc){
            Description = Desc;
        }

        void SetProductWeight(float P_W){
            ProductWeight = P_W;
        }

};

//the candie class
class SugarCandies : public Product{

    private:
        float Sugar_percent;
        bool Gluten;

    public:
        float CalculatePricePerGram(){
            float price = 0;
            price = (0.25 * ProductWeight) + (0.05 * Sugar_percent);
            if (Gluten) price += 1;
            
            return price;
        }

        //constructor
        SugarCandies(string Dis, float P_W, float S_p, bool G){
            SetDescription(Dis);
            SetProductWeight(P_W);
            Sugar_percent = S_p;
            Gluten = G;
        }

        void PrintDetails(){
            float price = 0;

            cout << "< Type: candy, " << " Description: " << Description << ",Gluten: ";
            if (!Gluten){
            cout << "Free ,";
            }
            else{
                cout << "Full";
            }
            cout << ", Sugar Percentage: " << Sugar_percent << "%, Weight: " << ProductWeight << "Price: " << CalculatePricePerGram() << endl;
 
        }
};

class Nuts : public Product{

    private:
        float Salt_percent;
        bool Mix;

    public:

        //constractor
        Nuts(string Dis, float P_W, float S_p, bool G){
            SetDescription(Dis);
            SetProductWeight(P_W);
            Salt_percent = S_p;
            Mix = G;
        }

        float CalculatePricePerGram(){
            float price;
            price = (0.15 * ProductWeight) + (0.1 * Salt_percent);
            if (Mix) price += 1;
            
            return price;
        }
        
         void PrintDetails(){
            float price = 0;

            cout << "< Type: candy, " << " Description: " << Description << ",Gluten: ";
            if (Mix){
            cout << "Free ";
            }
            else{
                cout << "Full ";
            }
            cout << ", Sugar Percentage: " << Salt_percent << "%, Weight: " << ProductWeight << ", Price: " << CalculatePricePerGram() << "$" << endl;
            
        }
};

int main(){

    string type, dis, ans;
    float p_w,s_p;
    bool g;
    vector<Product*> prodacts;
    SugarCandies * s_item;
    Nuts * n_item;
    unsigned int i;


    while(true){
        //geting the tipe of product
        cout << "Please give the type of product you want (candy, nut or -1 to exit). \n>";
        cin >> type;
        if (type == "-1")break;
        if(type != "candy" && type != "nut"){ cout << "Wrong impute try again"; continue;}


        if(type == "candi"){ 
            
            //getting disctriptions
            cout << "whats the discription?" << endl << ">";
            getline(cin, dis);
            cout << "whats the prodact waight?"<< endl << ">";
            cin >> p_w;
            cout << "whats the sugar precentage?"<< endl << ">";
            cin >> s_p;
            cout << "does it have gloten?(yes or no)"<< endl << ">";
            cin >> ans;
            if (ans == "yes") g = true;
            else g = false;  
            
            //we pass in a sugan item the addres of the constracted item
            s_item = new SugarCandies(dis, p_w, s_p, g);

            //push to the ector
            prodacts.push_back(s_item);
        }else{
            cout << "whats the discription?"<< endl << ">";
            cin.ignore();
            getline(cin, dis);
            cout << "whats the prodact waight?"<< endl << ">";
            cin >> p_w;
            cout << "whats the salt precentage?"<< endl << ">";
            cin >> s_p;
            cout << "is it mixted?(yes or no)"<< endl << ">";
            cin >> ans;
            if (ans == "yes") g = true;
            else g = false;  

            n_item =  new Nuts(dis, p_w, s_p, g);

            prodacts.push_back(n_item);
        }
    }

    //print the statuses
    for (i = 0; i < prodacts.size(); i++){
        prodacts[i]->PrintDetails();
    }

    return 0;
}
