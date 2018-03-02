#include "VCmagnets.h"
//stl
#include <iostream>
#include <string>

VCmagnets::VCmagnets():
//virtual_VELA_INJ_Magnet_Controller_Obj(nullptr),
//virtual_VELA_BA1_Magnet_Controller_Obj(nullptr),
//virtual_VELA_BA2_Magnet_Controller_Obj(nullptr),
//virtual_CLARA_PH1_Magnet_Controller_Obj(nullptr),
//physical_VELA_INJ_Magnet_Controller_Obj(nullptr),
//physical_VELA_BA1_Magnet_Controller_Obj(nullptr),
//physical_VELA_BA2_Magnet_Controller_Obj(nullptr),
//physical_CLARA_PH1_Magnet_Controller_Obj(nullptr),
//offline_VELA_INJ_Magnet_Controller_Obj(nullptr),
virtual_VELA_INJ_Magnet_Controller_Obj(nullptr),
offline_VELA_INJ_Magnet_Controller_Obj(nullptr),
physical_VELA_INJ_Magnet_Controller_Obj(nullptr),
virtual_CLARA_PH1_Magnet_Controller_Obj(nullptr),
offline_CLARA_PH1_Magnet_Controller_Obj(nullptr),
physical_CLARA_PH1_Magnet_Controller_Obj(nullptr),
withEPICS(true),
withoutEPICS(false),
withoutVM(false),
withVM(true),
VELA_INJ (VELA_ENUM::MACHINE_AREA::VELA_INJ),
VELA_BA1 (VELA_ENUM::MACHINE_AREA::VELA_BA1),
VELA_BA2 (VELA_ENUM::MACHINE_AREA::VELA_BA2),
CLARA_PH1(VELA_ENUM::MACHINE_AREA::CLARA_PH1),
USER(VELA_ENUM::MACHINE_AREA::USER),
UNKNOWN_AREA(VELA_ENUM::MACHINE_AREA::UNKNOWN_AREA),
shouldShowDebugMessage(false),//default is quiet mode
shouldShowMessage(false)//default is quiet mode
{
    std::cout <<"Instantiated a VCmagnets in Quiet Mode" <<std::endl;
    //ctor
}
//______________________________________________________________________________
VCmagnets::~VCmagnets()
{
//    //dtor
//    if(virtual_VELA_INJ_Magnet_Controller_Obj)
//    {
//        delete virtual_VELA_INJ_Magnet_Controller_Obj;
//               virtual_VELA_INJ_Magnet_Controller_Obj = nullptr;
//    }
//    if(offline_VELA_INJ_Magnet_Controller_Obj)
//    {
//        delete offline_VELA_INJ_Magnet_Controller_Obj;
//               offline_VELA_INJ_Magnet_Controller_Obj = nullptr;
//    }
//    if(physical_VELA_INJ_Magnet_Controller_Obj)
//    {
//        delete physical_VELA_INJ_Magnet_Controller_Obj;
//               physical_VELA_INJ_Magnet_Controller_Obj = nullptr;
//    }
//
//
//    if(virtual_VELA_BA1_Magnet_Controller_Obj)
//    {
//        delete virtual_VELA_BA1_Magnet_Controller_Obj;
//               virtual_VELA_BA1_Magnet_Controller_Obj = nullptr;
//    }
//    if(offline_VELA_BA2_Magnet_Controller_Obj)
//    {
//        delete offline_VELA_BA2_Magnet_Controller_Obj;
//               offline_VELA_BA2_Magnet_Controller_Obj = nullptr;
//    }
//    if(physical_VELA_BA2_Magnet_Controller_Obj)
//    {
//        delete physical_VELA_BA2_Magnet_Controller_Obj;
//               physical_VELA_BA2_Magnet_Controller_Obj = nullptr;
//    }
//
//    if(virtual_CLARA_PH1_Magnet_Controller_Obj)
//    {
//        delete virtual_CLARA_PH1_Magnet_Controller_Obj;
//               virtual_CLARA_PH1_Magnet_Controller_Obj = nullptr;
//    }
//    if(offline_CLARA_PH1_Magnet_Controller_Obj)
//    {
//        delete offline_CLARA_PH1_Magnet_Controller_Obj;
//               offline_CLARA_PH1_Magnet_Controller_Obj = nullptr;
//    }
//    if(physical_CLARA_PH1_Magnet_Controller_Obj)
//    {
//        delete physical_CLARA_PH1_Magnet_Controller_Obj;
//               physical_CLARA_PH1_Magnet_Controller_Obj = nullptr;
//    }
//
//        if(virtual_VELA_INJ_Magnet_Controller_Obj)
//    {
//        delete virtual_VELA_INJ_Magnet_Controller_Obj;
//               virtual_VELA_INJ_Magnet_Controller_Obj = nullptr;
//    }
//    if(offline_VELA_INJ_Magnet_Controller_Obj)
//    {
//        delete offline_VELA_INJ_Magnet_Controller_Obj;
//               offline_VELA_INJ_Magnet_Controller_Obj = nullptr;
//    }
//    if(physical_VELA_INJ_Magnet_Controller_Obj)
//    {
//        delete physical_VELA_INJ_Magnet_Controller_Obj;
//               physical_VELA_INJ_Magnet_Controller_Obj = nullptr;
//    }

}
//______________________________________________________________________________
void VCmagnets::setQuiet()
{
    std::cout <<"VCmagnets Quiet Mode Set." <<std::endl;
    shouldShowDebugMessage = false;
    shouldShowMessage = false;
}
//______________________________________________________________________________
void VCmagnets::setVerbose()
{
    std::cout <<"VCmagnets Verbose Mode Set." <<std::endl;
    shouldShowDebugMessage = true;
    shouldShowMessage = true;
}
//______________________________________________________________________________
void VCmagnets::setMessage()
{
    std::cout <<"VCmagnets Message Mode Set." <<std::endl;
    shouldShowDebugMessage = false;
    shouldShowMessage = true;
}
//______________________________________________________________________________
void VCmagnets::setDebugMessage()
{
    std::cout <<"VCmagnets DebugMessage Mode Set." <<std::endl;
    shouldShowDebugMessage = true;
    shouldShowMessage = false;
}
//______________________________________________________________________________
magnetController& VCmagnets::physical_CLARA_PH1_Magnet_Controller()
{
    std::string mconf = UTL::APCLARA1_CONFIG_PATH + UTL::CLARA_PH1_MAG_CONFIG;
    std::string name  = "physical_CLARA_PH1_Magnet_Controller";
    return getController(physical_CLARA_PH1_Magnet_Controller_Obj,mconf,name,withoutVM,withEPICS,CLARA_PH1);
}
//______________________________________________________________________________
magnetController& VCmagnets::virtual_CLARA_PH1_Magnet_Controller()
{
    std::string mconf = UTL::APCLARA1_CONFIG_PATH + UTL::CLARA_PH1_MAG_CONFIG;
    std::string name  = "virtual_CLARA_PH1_Magnet_Controller";
    return getController(virtual_CLARA_PH1_Magnet_Controller_Obj,mconf,name,withVM,withEPICS,CLARA_PH1);
}
//______________________________________________________________________________
magnetController& VCmagnets::offline_CLARA_PH1_Magnet_Controller()
{
    std::string mconf = UTL::APCLARA1_CONFIG_PATH + UTL::CLARA_PH1_MAG_CONFIG;
    std::string name  = "offline_CLARA_PH1_Magnet_Controller";
    return getController(offline_CLARA_PH1_Magnet_Controller_Obj,mconf,name,withoutVM,withoutEPICS,CLARA_PH1);
}
//______________________________________________________________________________
magnetController& VCmagnets::virtual_VELA_INJ_Magnet_Controller()
{
    std::string mconf = UTL::APCLARA1_CONFIG_PATH + UTL::VELA_INJ_MAG_CONFIG;
    std::string name  = "virtual_VELA_INJ_Magnet_Controller_Obj";
    return getController(virtual_VELA_INJ_Magnet_Controller_Obj,mconf,name,withVM,withEPICS,VELA_INJ);
}
//______________________________________________________________________________
magnetController& VCmagnets::offline_VELA_INJ_Magnet_Controller()
{
    std::string mconf = UTL::APCLARA1_CONFIG_PATH + UTL::VELA_INJ_MAG_CONFIG;
    std::string name  = "offline_VELA_INJ_Magnet_Controller_Obj";
    return getController(offline_VELA_INJ_Magnet_Controller_Obj,mconf,name,withoutVM,withoutEPICS,VELA_INJ);
}
//______________________________________________________________________________
magnetController& VCmagnets::physical_VELA_INJ_Magnet_Controller()
{
    std::string mconf = UTL::APCLARA1_CONFIG_PATH + UTL::VELA_INJ_MAG_CONFIG;
    std::string name  = "physical_VELA_INJ_Magnet_Controller_Obj";
    return getController(physical_VELA_INJ_Magnet_Controller_Obj,mconf,name,withoutVM,withEPICS,VELA_INJ);
}
//______________________________________________________________________________
magnetController& VCmagnets::virtual_VELA_BA1_Magnet_Controller()
{
    std::string mconf = UTL::CONFIG_PATH + UTL::VELA_BA1_MAG_CONFIG;
    std::string name  = "virtual_VELA_INJ_Magnet_Controller_Obj";
    return getController(virtual_VELA_BA1_Magnet_Controller_Obj,mconf,name,withVM,withEPICS,VELA_BA1);
}
//______________________________________________________________________________
magnetController& VCmagnets::offline_VELA_BA1_Magnet_Controller()
{
    std::string mconf = UTL::APCLARA1_CONFIG_PATH + UTL::VELA_BA1_MAG_CONFIG;
    std::string name  = "offline_VELA_INJ_Magnet_Controller_Obj";
    return getController(offline_VELA_BA1_Magnet_Controller_Obj,mconf,name,withoutVM,withoutEPICS,VELA_BA1);
}
//______________________________________________________________________________
magnetController& VCmagnets::physical_VELA_BA1_Magnet_Controller()
{
    std::string mconf = UTL::APCLARA1_CONFIG_PATH + UTL::VELA_BA1_MAG_CONFIG;
    std::string name  = "physical_VELA_INJ_Magnet_Controller_Obj";
    return getController(physical_VELA_BA1_Magnet_Controller_Obj,mconf,name,withoutVM,withEPICS,VELA_BA1);
}
//______________________________________________________________________________
magnetController& VCmagnets::virtual_VELA_BA2_Magnet_Controller()
{
    std::string mconf = UTL::APCLARA1_CONFIG_PATH + UTL::VELA_BA2_MAG_CONFIG;
    std::string name  = "virtual_VELA_INJ_Magnet_Controller_Obj";
    return getController(virtual_VELA_BA2_Magnet_Controller_Obj,mconf,name,withVM,withEPICS,VELA_BA2);
}
//______________________________________________________________________________
magnetController& VCmagnets::offline_VELA_BA2_Magnet_Controller()
{
    std::string mconf = UTL::CONFIG_PATH + UTL::VELA_BA2_MAG_CONFIG;
    std::string name  = "offline_VELA_INJ_Magnet_Controller_Obj";
    return getController(offline_VELA_BA2_Magnet_Controller_Obj,mconf,name,withoutVM,withoutEPICS,VELA_BA2);
}
//______________________________________________________________________________
magnetController& VCmagnets::physical_VELA_BA2_Magnet_Controller()
{
    std::string mconf = UTL::APCLARA1_CONFIG_PATH + UTL::VELA_BA2_MAG_CONFIG;
    std::string name  = "physical_VELA_INJ_Magnet_Controller_Obj";
    return getController(physical_VELA_BA2_Magnet_Controller_Obj,mconf,name,withoutVM,withEPICS,VELA_BA2);
}
//______________________________________________________________________________
magnetController& VCmagnets::virtual_USER_Magnet_Controller(const std::string& config_path)
{
    std::string name  = "virtual_USER_Magnet_Controller_Obj";
    return getController(physical_USER_Magnet_Controller_Obj,config_path,name,withVM,withEPICS,USER);
}
//______________________________________________________________________________
magnetController& VCmagnets::offline_USER_Magnet_Controller(const std::string& config_path)
{
    std::string name  = "offline_USER_Magnet_Controller_Obj";
    return getController(physical_USER_Magnet_Controller_Obj,config_path,name,withoutVM,withoutEPICS,USER);
}
//______________________________________________________________________________
magnetController& VCmagnets::physical_USER_Magnet_Controller(const std::string& config_path)
{
    std::string name  = "physical_USER_Magnet_Controller_Obj";
    return getController(physical_USER_Magnet_Controller_Obj,config_path,name,withoutVM,withEPICS,USER);
}
//______________________________________________________________________________
magnetController& VCmagnets::getController(magnetController * cont,const std::string& conf,const std::string & name, const bool shouldVM, const bool shouldEPICS, const VELA_ENUM::MACHINE_AREA myMachineArea)
{
    if(cont)
    {
        std::cout <<name  <<" object already exists," <<std::endl;
    }
    else
    {
        std::cout <<"Creating " <<name <<" object" <<std::endl;
        cont = new magnetController(shouldShowMessage, shouldShowDebugMessage, conf, shouldVM, shouldEPICS, myMachineArea);
    }
    return *cont;
}
////______________________________________________________________________________
//magnetController& VCmagnets::virtual_VELA_INJ_Magnet_Controller()
////void VCmagnets::virtual_VELA_INJ_Magnet_Controller()
//{
//    std::string mconf = UTL::CONFIG_PATH + UTL::VELA_INJ_MAG_CONFIG;
//    std::string nconf = UTL::CONFIG_PATH + UTL::VELA_INJ_MAG_NR_PSU_CONFIG;
//
//    if(virtual_VELA_INJ_Magnet_Controller_Obj)
//    {
//        std::cout <<"virtual_VELA_INJ_Magnet_Controller object already exists," <<std::endl;
//    }
//    else
//    {
//        std::cout <<"Creating virtual_VELA_INJ_Magnet_Controller object" <<std::endl;
//        virtual_VELA_INJ_Magnet_Controller_Obj = new magnetController(shouldShowMessage, shouldShowDebugMessage, mconf, nconf, withVM, withEPICS,VELA_INJ);
//    }
//    return *virtual_VELA_INJ_Magnet_Controller_Obj;
//}
////______________________________________________________________________________
////magnetController VCmagnets::offline_VELA_INJ_Magnet_Controller()
//magnetController& VCmagnets::physical_VELA_INJ_Magnet_Controller()
//{
//    std::string mconf = UTL::CONFIG_PATH + UTL::VELA_INJ_MAG_CONFIG;
//    std::string nconf = UTL::CONFIG_PATH + UTL::VELA_INJ_MAG_NR_PSU_CONFIG;
//    if(physical_VELA_INJ_Magnet_Controller_Obj)
//    {
//        std::cout <<"physical_VELA_INJ_Magnet_Controller object already exists," <<std::endl;
//    }
//    else
//    {
//        std::cout <<"Creating physical_VELA_INJ_Magnet_Controller object" <<std::endl;
//        physical_VELA_INJ_Magnet_Controller_Obj = new magnetController(shouldShowMessage, shouldShowDebugMessage, mconf, nconf, withoutVM, withEPICS,VELA_INJ);
//    }
//    return *physical_VELA_INJ_Magnet_Controller_Obj;
//}
////______________________________________________________________________________
//magnetController& VCmagnets::offline_VELA_INJ_Magnet_Controller()
//{
//    std::string mconf = UTL::CONFIG_PATH + UTL::VELA_INJ_MAG_CONFIG;
//    std::string nconf = UTL::CONFIG_PATH + UTL::VELA_INJ_MAG_NR_PSU_CONFIG;
//    if(offline_VELA_INJ_Magnet_Controller_Obj)
//    {
//        std::cout <<"offline_VELA_INJ_Magnet_Controller_Obj object already exists," <<std::endl;
//    }
//    else
//    {
//        std::cout <<"Creating offline_VELA_INJ_Magnet_Controller object" <<std::endl;
//        offline_VELA_INJ_Magnet_Controller_Obj = new magnetController(shouldShowMessage, shouldShowDebugMessage, mconf, nconf, withoutVM, withoutEPICS,VELA_INJ);
//    }
//    return *offline_VELA_INJ_Magnet_Controller_Obj;
//}
////______________________________________________________________________________
//magnetController& VCmagnets::virtual_VELA_BA1_Magnet_Controller()
//{
//    std::string mconf = UTL::CONFIG_PATH + UTL::VELA_BA1_MAG_CONFIG;
//    std::string nconf = UTL::CONFIG_PATH + UTL::VELA_BA1_MAG_NR_PSU_CONFIG;
//
//    if(virtual_VELA_BA1_Magnet_Controller_Obj)
//    {
//        std::cout <<"virtual_VELA_BA1_Magnet_Controller object already exists," <<std::endl;
//    }
//    else
//    {
//        std::cout <<"Creating virtual_VELA_BA1_Magnet_Controller object" <<std::endl;
//        virtual_VELA_BA1_Magnet_Controller_Obj = new magnetController(shouldShowMessage, shouldShowDebugMessage, mconf, nconf, withVM, withEPICS,VELA_BA1);
//    }
//    return *virtual_VELA_BA1_Magnet_Controller_Obj;
//}
////______________________________________________________________________________
//magnetController& VCmagnets::offline_VELA_BA1_Magnet_Controller()
//{
//    std::string mconf = UTL::CONFIG_PATH + UTL::VELA_BA1_MAG_CONFIG;
//    std::string nconf = UTL::CONFIG_PATH + UTL::VELA_BA1_MAG_NR_PSU_CONFIG;
//    if(offline_VELA_BA1_Magnet_Controller_Obj)
//    {
//        std::cout <<"offline_VELA_BA1_Magnet_Controller object already exists," <<std::endl;
//    }
//    else
//    {
//        std::cout <<"Creating offline_VELA_BA1_Magnet_Controller object" <<std::endl;
//        offline_VELA_BA1_Magnet_Controller_Obj = new magnetController(shouldShowMessage, shouldShowDebugMessage, mconf, nconf, withVM, withoutEPICS,VELA_BA1);
//    }
//    return *offline_VELA_BA1_Magnet_Controller_Obj;
//}
////______________________________________________________________________________
//magnetController& VCmagnets::physical_VELA_BA1_Magnet_Controller()
//{
//    std::string mconf = UTL::CONFIG_PATH + UTL::VELA_INJ_MAG_CONFIG;
//    std::string nconf = UTL::CONFIG_PATH + UTL::VELA_INJ_MAG_NR_PSU_CONFIG;
//    if(physical_VELA_BA1_Magnet_Controller_Obj)
//    {
//        std::cout <<"physical_VELA_BA1_Magnet_Controller object already exists," <<std::endl;
//    }
//    else
//    {
//        std::cout <<"Creating physical_VELA_BA1_Magnet_Controller object" <<std::endl;
//        physical_VELA_BA1_Magnet_Controller_Obj = new magnetController(shouldShowMessage, shouldShowDebugMessage, mconf, nconf, withoutVM, withEPICS,VELA_BA1);
//    }
//    return *physical_VELA_BA1_Magnet_Controller_Obj;
//}
////______________________________________________________________________________
//magnetController& VCmagnets::virtual_VELA_BA2_Magnet_Controller()
//{
//    std::cout <<"creating virtual_VELA_BA2_Magnet_Controller object" <<std::endl;
//    std::string mconf = UTL::CONFIG_PATH + UTL::VELA_BA2_MAG_CONFIG;
//    std::string nconf = UTL::CONFIG_PATH + UTL::VELA_BA2_MAG_NR_PSU_CONFIG;
//
//    if(virtual_VELA_BA2_Magnet_Controller_Obj)
//    {
//        std::cout <<"virtual_VELA_BA2_Magnet_Controller_Obj object already exists," <<std::endl;
//    }
//    else
//    {
//        std::cout <<"Creating virtual_VELA_BA2_Magnet_Controller_Obj object" <<std::endl;
//        virtual_VELA_BA2_Magnet_Controller_Obj = new magnetController(shouldShowMessage, shouldShowDebugMessage, mconf, nconf, withVM, withEPICS,VELA_BA2);
//    }
//    return *virtual_VELA_BA2_Magnet_Controller_Obj;
//}
////______________________________________________________________________________
//magnetController& VCmagnets::offline_VELA_BA2_Magnet_Controller()
//{
//    std::cout <<"creating offline_VELA_BA2_Magnet_Controller object" <<std::endl;
//    std::string mconf = UTL::CONFIG_PATH + UTL::VELA_BA2_MAG_CONFIG;
//    std::string nconf = UTL::CONFIG_PATH + UTL::VELA_BA2_MAG_NR_PSU_CONFIG;
//    if(offline_VELA_BA2_Magnet_Controller_Obj)
//    {
//        std::cout <<"virtual_VELA_BA2_Magnet_Controller_Obj object already exists," <<std::endl;
//    }
//    else
//    {
//        offline_VELA_BA2_Magnet_Controller_Obj = new magnetController(shouldShowMessage, shouldShowDebugMessage, mconf, nconf, withoutVM, withoutEPICS,VELA_BA2);
//    }
//    return *offline_VELA_BA2_Magnet_Controller_Obj;
//}
////______________________________________________________________________________
//magnetController& VCmagnets::physical_VELA_BA2_Magnet_Controller()
//{
//
//    std::string mconf = UTL::CONFIG_PATH + UTL::VELA_INJ_MAG_CONFIG;
//    std::string nconf = UTL::CONFIG_PATH + UTL::VELA_INJ_MAG_NR_PSU_CONFIG;
//    if(physical_VELA_BA1_Magnet_Controller_Obj)
//    {
//        std::cout <<"virtual_VELA_BA2_Magnet_Controller_Obj object already exists," <<std::endl;
//    }
//    else
//    {
//        std::cout <<"Creating physical_VELA_BA2_Magnet_Controller object" <<std::endl;
//        physical_VELA_BA1_Magnet_Controller_Obj = new magnetController(shouldShowMessage, shouldShowDebugMessage, mconf, nconf, withoutVM, withEPICS,VELA_BA2);
//    }
//    return *physical_VELA_BA1_Magnet_Controller_Obj;
//}
////______________________________________________________________________________
//magnetController& VCmagnets::virtual_CLARA_PH1_Magnet_Controller()
//{
//
//    std::string mconf = UTL::CONFIG_PATH + UTL::CLARA_PH1_MAG_CONFIG;
////    std::string nconf = UTL::CONFIG_PATH + UTL::CLARA_PH1_MAG_NR_PSU_CONFIG;
//
//    if(virtual_CLARA_PH1_Magnet_Controller_Obj)
//    {
//        std::cout <<"virtual_CLARA_PH1_Magnet_Controller object already exists," <<std::endl;
//    }
//    else
//    {
//        std::cout <<"Creating virtual_CLARA_PH1_Magnet_Controller object" <<std::endl;
//        virtual_CLARA_PH1_Magnet_Controller_Obj = new magnetController(shouldShowMessage, shouldShowDebugMessage, mconf,  UTL::NO_CONFIG_FILE, withVM, withEPICS,CLARA_PH1);
//    }
//    return *virtual_CLARA_PH1_Magnet_Controller_Obj;
//}
////______________________________________________________________________________
//magnetController& VCmagnets::offline_CLARA_PH1_Magnet_Controller()
//{
//    std::string mconf = UTL::CONFIG_PATH + UTL::CLARA_PH1_MAG_CONFIG;
//    //std::string nconf = UTL::CONFIG_PATH + UTL::CLARA_PH1_MAG_NR_PSU_CONFIG;
//    if(offline_CLARA_PH1_Magnet_Controller_Obj)
//    {
//        std::cout <<"offline_CLARA_PH1_Magnet_Controller object already exists," <<std::endl;
//    }
//    else
//    {
//        std::cout <<"Creating offline_CLARA_PH1_Magnet_Controller object" <<std::endl;
//        offline_CLARA_PH1_Magnet_Controller_Obj = new magnetController(shouldShowMessage, shouldShowDebugMessage, mconf,  UTL::NO_CONFIG_FILE, withoutVM, withoutEPICS,CLARA_PH1);
//    }
//    return *offline_CLARA_PH1_Magnet_Controller_Obj;
//}
////______________________________________________________________________________
//magnetController& VCmagnets::physical_CLARA_PH1_Magnet_Controller()
//{
//
//    std::string mconf = UTL::CONFIG_PATH + UTL::CLARA_PH1_MAG_CONFIG;
//    //std::string nconf = UTL::CONFIG_PATH + UTL::CLARA_PH1_MAG_NR_PSU_CONFIG;
//    if(physical_CLARA_PH1_Magnet_Controller_Obj)
//    {
//        std::cout <<"physical_CLARA_PH1_Magnet_Controller object already exists," <<std::endl;
//    }
//    else
//    {
//        std::cout <<"creating physical_CLARA_PH1_Magnet_Controller object" <<std::endl;
//        physical_CLARA_PH1_Magnet_Controller_Obj = new magnetController(shouldShowMessage, shouldShowDebugMessage, mconf,  UTL::NO_CONFIG_FILE, withoutVM, withEPICS,CLARA_PH1);
//    }
//    return *physical_CLARA_PH1_Magnet_Controller_Obj;
//}
//______________________________________________________________________________
magnetController& VCmagnets::getMagnetController(VELA_ENUM::MACHINE_MODE mode, VELA_ENUM::MACHINE_AREA area)
{
    if(mode == VELA_ENUM::OFFLINE && area == VELA_ENUM::VELA_INJ)
        return offline_VELA_INJ_Magnet_Controller();
    else if(mode == VELA_ENUM::VIRTUAL && area == VELA_ENUM::VELA_INJ)
        return virtual_VELA_INJ_Magnet_Controller();
    else if(mode == VELA_ENUM::PHYSICAL && area == VELA_ENUM::VELA_INJ)
        return physical_VELA_INJ_Magnet_Controller();
    else if(mode == VELA_ENUM::OFFLINE && area == VELA_ENUM::VELA_BA1)
        return offline_VELA_BA1_Magnet_Controller();
    else if(mode == VELA_ENUM::VIRTUAL && area == VELA_ENUM::VELA_BA1)
        return virtual_VELA_BA1_Magnet_Controller();
    else if(mode == VELA_ENUM::PHYSICAL && area == VELA_ENUM::VELA_BA1)
        return physical_VELA_BA1_Magnet_Controller();
    else if(mode == VELA_ENUM::OFFLINE && area == VELA_ENUM::VELA_BA2)
        return offline_VELA_BA2_Magnet_Controller();
    else if(mode == VELA_ENUM::VIRTUAL && area == VELA_ENUM::VELA_BA2)
        return virtual_VELA_BA2_Magnet_Controller();
    else if(mode == VELA_ENUM::PHYSICAL && area == VELA_ENUM::VELA_BA2)
        return physical_VELA_BA2_Magnet_Controller();
    else if(mode == VELA_ENUM::OFFLINE && area == VELA_ENUM::CLARA_PH1)
        return offline_CLARA_PH1_Magnet_Controller();
    else if(mode == VELA_ENUM::VIRTUAL && area == VELA_ENUM::CLARA_PH1)
        return virtual_CLARA_PH1_Magnet_Controller();
    else if(mode == VELA_ENUM::PHYSICAL && area == VELA_ENUM::CLARA_PH1)
        return physical_CLARA_PH1_Magnet_Controller();

}
//
//















