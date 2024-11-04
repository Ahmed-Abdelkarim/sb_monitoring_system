#include "installation.h"

installation::installation(int id, int selected_setup)
{
    houseId = id;
    sb_setup = (SETUP)selected_setup;
    installationDate = 0;
    totalCost = 0;
    revenue = 0;
    sb_ptr = std::make_unique<sbStorage>();
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
    std::cout << "House id: " << houseId << "\ntotal revenue: "<< revenue << "\ntotal cost: "<<totalCost << std::endl;
}
installation::~installation()
{
}