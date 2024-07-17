class ParkingSystem {
private:
    int Big;
    int Meduim;
    int Small ;   
public:
    ParkingSystem(int big, int medium, int small) : Big(big),Meduim(medium),Small(small){
        
    }
    
    bool addCar(int carType) {
        bool flag;
        switch(carType){
            case 1:
                if(Big==0){
                    flag =false;
                }
                else{
                    Big--;
                    flag= true;
                }
            break;
            case 2:
                if(Meduim==0){
                    flag= false;
                }
                else{
                    Meduim--;
                    flag= true;
                }
            break;
            case 3:
                if(Small==0){
                   flag= false;
                }
                else{
                    Small--;
                   flag= true;
                }
            break;    
        }
        return flag;
    }
};

