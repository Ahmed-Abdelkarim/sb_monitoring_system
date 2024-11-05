#include "HouseOwner.h"


HouseOwner::HouseOwner(std::string userName, int userAge, std::string useEmail)
{
    name = userName;
    age = userAge;
    email = useEmail;
    houseId = 0;
    printDetails();
}

void HouseOwner::printDetails(){
    std::cout<<"name: "<< name << "\nage: " << age << "\nemail: " << email << std::endl;
}
void HouseOwner::selectType(int t, std::unique_ptr<Network> network_ptr){
    std::cout<<"Please Select Installation Type: " << std::endl;
    std::cout<<"0: Basic\n1: Standard\n2: Pro" << std::endl;
    type = t;
    if (t > 2 || t < 0){
        throw std::invalid_argument("Type cannot be outside the available options");
    }
    install_ptr = std::make_unique<installation>(houseId, type, std::move(network_ptr));
}

int HouseOwner::getCost(){
    return install_ptr->calcCost(houseId);
}

int HouseOwner::getRevenue(){
    return install_ptr->calcRevenue(houseId);
}