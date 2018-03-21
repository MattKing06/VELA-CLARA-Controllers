/*
//              This file is part of VELA-CLARA-Controllers.                          //
//------------------------------------------------------------------------------------//
//    VELA-CLARA-Controllers is free software: you can redistribute it and/or modify  //
//    it under the terms of the GNU General Public License as published by            //
//    the Free Software Foundation, either version 3 of the License, or               //
//    (at your option) any later version.                                             //
//    VELA-CLARA-Controllers is distributed in the hope that it will be useful,       //
//    but WITHOUT ANY WARRANTY; without even the implied warranty of                  //
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                   //
//    GNU General Public License for more details.                                    //
//                                                                                    //
//    You should have received a copy of the GNU General Public License               //
//    along with VELA-CLARA-Controllers.  If not, see <http://www.gnu.org/licenses/>. //
//
//  Author:      DJS
//  Last edit:   19-03-2018
//  FileName:    gunProtController.h
//  Description:
//
//
//*/
#ifndef allGunProts_CONTROLLER_H_
#define allGunProts_CONTROLLER_H_
// stl
#include <string>
#include <vector>
#include <map>
// project
#include "gunProtInterface.h"
#include "controller.h"
// boost.python
#ifdef BUILD_DLL
#endif

class gunProtController : public controller
{
    public:
        // just have 1 constructor, but we have a higher level class that create these objects
        gunProtController();
        gunProtController(const bool show_messages, const bool show_debug_messagese,
                          const std::string &allGunProtsConf, const bool startVirtualMachine,
                          const bool shouldStartEPICs );
        ~gunProtController();

      // These are pure virtual methods, so need to have some implmentation in derived classes
        double get_CA_PEND_IO_TIMEOUT();
        void   set_CA_PEND_IO_TIMEOUT(double val);
        std::map<HWC_ENUM::ILOCK_NUMBER,HWC_ENUM::ILOCK_STATE> getILockStates(const std::string& name);
        std::map<HWC_ENUM::ILOCK_NUMBER,std::string> getILockStatesStr(const std::string& name);

        bool isGood(const std::string & name);
        bool isNotGood(const std::string & name);
        bool isBad(const std::string & name);

        bool reset(const std::string& name);
        bool reset(const std::vector<std::string>& names);

        bool enable(const std::string& name);
        bool enable(const std::vector<std::string>& names);
        bool enable();

        bool disable(const std::string& name);
        bool disable(const std::vector<std::string>& names);

        std::string getGeneralProtName();
        std::string getEnableProtName();
        std::string getCurrentModeProtName();

        const rfProtStructs::rfGunProtObject& getRFProtObjConstRef(const std::string& name);

    protected:
    private:
        void initialise();
        const bool shouldStartEPICs;
        gunProtInterface localInterface;
};
#endif // allGunProts_CONTROLLER_H_
