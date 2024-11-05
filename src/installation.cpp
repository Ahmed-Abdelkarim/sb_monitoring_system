#include "installation.h"

installation::installation(int id, int selected_setup, std::unique_ptr<Network> network_ptr)
{
    houseId = id;
    sb_setup = (SETUP)selected_setup;
    installationDate = 0;
    totalCost = 0;
    revenue = 0;
    sb_ptr = std::make_unique<sbStorage>(std::move(network_ptr));
    sb_ptr->setup(sb_setup);
    sb_ptr->energeAlgo();
    printDetails();
}
int installation::calcCost(int id){
    totalCost = sb_ptr->getPowerFromGrid() * 10; //where 10 is the price per watt
    std::cout<<"Total energy cost of house #: "<< id << " : " << totalCost << std::endl;
    return totalCost;
}
int installation::calcRevenue(int id){
    revenue = sb_ptr->getPowerToGrid() * 10; //where 10 is the price per watt
    std::cout<<"Total energy revenue of house #: "<< id << " : " << revenue << std::endl;
    return revenue;

}
void installation::printDetails(){
    std::cout << "Installation Details:\nInstallation type: "<< (int)sb_setup << "\ninstallation date: "<<installationDate << std::endl;
}
installation::~installation()
{
}