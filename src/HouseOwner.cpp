#include "HouseOwner.h"

HouseOwner::HouseOwner(/* args */)
{
    name = "John Doe";
    age = 40;
    email = "johnDoe@example.com";
    printDetails();
}
HouseOwner::HouseOwner(std::string userName, int userAge, std::string useEmail)
{
    name = userName;
    age = userAge;
    email = useEmail;
    printDetails();
}
HouseOwner::~HouseOwner()
{
}
void HouseOwner::printDetails(){
    std::cout<<"name: "<< name << "\nage: " << age << "\nemail: " << email << std::endl;
}
void HouseOwner::browseTypes(){
    std::cout<<"Please Select Installation Type: " << std::endl;
    std::cout<<"0: Basic\n1: Standard\n2: Pro" << std::endl;
    std::cout<<"Selected type: ";
    std::cin >> type;
    //input validation required
}
void HouseOwner::installSB(){
    std::unique_ptr<installation> install_ptr(new installation(0, type));
    install_ptr->calcCost(0);
    install_ptr->calcRevenue(0);
    std::cout<<"SB installed Successfully!" << std::endl;
    //response msg/return
}