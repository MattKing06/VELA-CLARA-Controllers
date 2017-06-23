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

#ifndef VELA_MAG_INTERFACE_H
#define VELA_MAG_INTERFACE_H
// djs
#include "interface.h"
#include "magnetStructs.h"
#include "structs.h"
#include "magnetConfigReader.h"
//stl
#include <vector>
#include <string>
#include <atomic>
#include <map>

class magnetInterface : public interface
{
    public:

        typedef std::vector<bool> vec_b;
        typedef std::vector< std::string > vec_s;
        typedef std::vector<double> vec_d;
        typedef std::map<VELA_ENUM::ILOCK_NUMBER, VELA_ENUM::ILOCK_STATE> IlockMap1;
        typedef std::map<VELA_ENUM::ILOCK_NUMBER,std::string> IlockMap2;

        magnetInterface::magnetInterface();
        magnetInterface( const std::string &magConf,
                         const bool startVirtualMachine,
                         const bool* show_messages_ptr,
                         const bool* show_debug_messages_ptr,
                         const bool shouldStartEPICs,
                         const VELA_ENUM::MACHINE_AREA myMachineArea );

        ~magnetInterface();
      //  magnetInterface(const magnetInterface& origin, const bool* show_messages_ptr, const bool * show_debug_messages_ptr); // add this line

        /// These are pure virtual methods, so need to have some implmentation in derived classes
        IlockMap1 getILockStates( const std::string & name   ){ IlockMap1 r;return r; }
        IlockMap2 getILockStatesStr( const std::string & name){ IlockMap2 r;return r; }

        // /existentital quantifiers, and the like....
        bool isAQuad( const std::string & magName );
        bool isABSol( const std::string & magName );
        bool isAHCor( const std::string & magName );
        bool isAVCor( const std::string & magName );
        bool isADip ( const std::string & magName );
        bool isASol ( const std::string & magName );
        bool isACor ( const std::string & magName );
//        bool isBipolar( const std::string & magName );
//        bool isNR( const std::string & magName );
//        bool isNRGanged( const std::string & magName );
//        bool isNRorNRGanged( const std::string & magName );
        bool isDegaussing( const std::string & magName );
        bool isNotDegaussing( const std::string & magName );
        bool entryExistsAndIsDegaussing( const std::string & magName );
        bool entryExistsAndIsNotDegaussing( const std::string & magName );
//        bool isON_psuN( const std::string & magName );
//        bool isON_psuR( const std::string & magName );
        bool isON(const std::string &magName);
//        bool isOFF_psuN( const std::string & magName );
//        bool isOFF_psuR( const std::string & magName );
        bool isOFF(const std::string &magName);

        bool isRIequalVal( const std::string & magName, const  double value, const double tolerance );
        bool isRIequalSI( const std::string & magName);
        /// RI tolerances set how many decimal places on RI values (irl EPICS has 9 and they are continually changing)
        void setRITolerance( const std::string & magName, const double val);
        void setRITolerance(const vec_s & magNames, const vec_d & vals );
        double getRITolerance( const std::string & magName );
        std::vector< double >  getRITolerance( const std::vector< std::string > & magNames );

        /// main getters for magnet currents
        double getSI( const std::string & magName );
        double getRI( const std::string & magName );
        vec_d getSI( const vec_s & magNames );
        vec_d getRI( const vec_s & magNames );

        /// getters for names
        vec_s getMagnetNames();
        vec_s getQuadNames();
        vec_s getHCorNames();
        vec_s getVCorNames();
        vec_s getDipNames();
        vec_s getSolNames();

        /// setters for magnet current, in different flavours
        bool setSI(const std::string & magName,const double value);
        bool setSI(const vec_s & magNames     ,const vec_d& values );
        bool setSI (const std::string &magName, const double value  , const double tolerance  , const size_t timeOUT );
        vec_s setSI(const vec_s &magNames     , const vec_d & values, const vec_d & tolerances, const size_t timeOUT );
//
        /// These functions return wether the commands were sent to EPICS correctly, not if the oiperation was succesful
        bool switchONpsu (const std::string &magName );
        bool switchOFFpsu(const std::string &magName );
        bool switchONpsu (const vec_s       &magNames);
        bool switchOFFpsu(const vec_s       &magNames);
//
//        /// degaussing functions
        size_t deGauss( const std::string & mag, bool resetToZero = true );
        size_t deGauss( const vec_s & mag, bool resetToZero = true );
        size_t degaussAll( bool resetToZero = true );
        /// Force kill a degaussing thread, if you know its ID number
        void killDegaussThread( size_t N );
//
        /// get the states of the magnets: here in real life
        magnetStructs::magnetStateStruct getCurrentMagnetState();
        magnetStructs::magnetStateStruct getCurrentMagnetState(const vec_s &s);

        /// and get the states of the magnets: here from a file
        magnetStructs::magnetStateStruct getDBURT( const std::string & fileName );
        magnetStructs::magnetStateStruct getDBURTCorOnly( const std::string & fileName );
        magnetStructs::magnetStateStruct getDBURTQuadOnly( const std::string & fileName );

        /// apply a state struct to the machine
        void applyMagnetStateStruct( const magnetStructs::magnetStateStruct & ms  );
        /// applyt a DBURT to the machine
        void applyDBURT( const std::string & fileName );
        void applyDBURTCorOnly( const std::string & fileName );
        void applyDBURTQuadOnly( const std::string & fileName );
        /// Write a DBURT
        bool writeDBURT(const magnetStructs::magnetStateStruct & ms, const std::string & fileName = "", const std::string & comments = ""  ,const std::string & keywords = "");
        bool writeDBURT(const std::string &fileName = "",const std::string &comments="",const std::string & keywords="");
        /// These versions are for c++ applictions, we allow c++ users to have full read access to the entire magnetObject data
        const magnetStructs::magnetObject &getMagObjConstRef(const std::string& magName);
        const magnetStructs::magnetObject *getMagObjConstPtr(const std::string& magName);

//      /// Reverse types
//        magnetStructs::MAG_REV_TYPE                  getMagRevType( const std::string & magName );
//        std::vector<  magnetStructs::MAG_REV_TYPE >  getMagRevType( const std::vector< std::string > & magNames );
//      ///
        magnetStructs::MAG_TYPE              getMagType( const std::string & magName );
        std::vector<magnetStructs::MAG_TYPE> getMagType( const std::vector< std::string > & magNames );
//      ///
        magnetStructs::MAG_PSU_STATE              getMagPSUState(const std::string &magName);
        std::vector<magnetStructs::MAG_PSU_STATE> getMagPSUState(const std::vector<std::string> &magNames);

        std::vector< double >                getDegValues( const std::string & magName );
        std::vector< std::vector< double > > getDegValues( const std::vector< std::string > & magNames );


        size_t                getNumDegSteps( const std::string & magName );
        std::vector< size_t > getNumDegSteps( const std::vector< std::string > & magNames );

        /// BJAS ADDITIONS
      ///
        std::vector< double >              getFieldIntegralCoefficients( const std::string & magName );
        std::vector<std::vector< double >> getFieldIntegralCoefficients( const std::vector< std::string > & magNames );
      ///
        double                getPosition( const std::string & magName );
        std::vector< double > getPosition( const std::vector< std::string > & magNames );
      ///
        double                getMagneticLength( const std::string & magName );
        std::vector< double > getMagneticLength( const std::vector< std::string > & magNames );
      ///
        std::string              getManufacturer( const std::string & magName );
        std::vector<std::string> getManufacturer( const std::vector< std::string > & magNames );
      ///
        std::string               getSerialNumber(const std::string & magName );
        std::vector<std::string>  getSerialNumber(const std::vector< std::string > & magName );
      ///
        std::string               getMagnetBranch(const std::string & magName );
        std::vector<std::string>  getMagnetBranch(const std::vector< std::string > & magName );
      ///
        std::string               getMeasurementDataLocation( const std::string & magName );
        std::vector<std::string>  getMeasurementDataLocation( const std::vector< std::string > & magName );

    private:
        // what flavor of controller am i ?
        const VELA_ENUM::MACHINE_AREA myMachineArea;
        // MOVE TO BASE CLASS
        const bool shouldStartEPICs;
        /// AllmagnetData gets a dummy magnet to return
        std::string dummyName;

        const unsigned short PSU_ON,PSU_OFF;

        std::map<std::string, magnetStructs::magnetObject> allMagnetData;
        magnetConfigReader configReader; /// class member so we can pass in file path in ctor

        void killMonitor(magnetStructs::monitorStruct* ms);

        void initialise();
        bool initObjects();
        void addDummyElementToAllMAgnetData();
        void initChids();

        bool Is_PSU_PV( magnetStructs::MAG_PV_TYPE pv);
        bool Is_psuRoot_SAME_AS_PV_ROOT(const std::string& root);

        void addChannel(const std::string& pvRoot,magnetStructs::pvStruct &pv);
        void startMonitors();
//
//        magnetStructs::degaussValues degStruct;
        std::vector<magnetStructs::monitorStruct*> continuousMonitorStructs; /// vector of monitors to pass along with callback function

        static void staticEntryMagnetMonitor(const event_handler_args args);
//
        void updateRI(const double value,const std::string&magName);
        void updateGetSI(const double value,const std::string&magName);
//
//        void updateRI_WithPol( const std::string & magName );
//        void updateSI_WithPol( const std::string & magName );
        void updatePSUSta(const unsigned short value,const std::string&magName);
        void updateRILK(const unsigned short value,const std::string&magName);

        void updateRPower(const unsigned short value,const std::string&magName);
//
//
        bool setSI_MAIN(const vec_s & magNames, const vec_d& values );

        // THE MAIN TOGGLE PSU function
        bool togglePSU(const vec_s &magNames, magnetStructs::MAG_PSU_STATE newState);
        vec_s waitForMagnetsToSettle( const vec_s & mags, const vec_d & values,
                                     const vec_d & tolerances, const time_t waitTime = 45 ); /// MAGIC_NUMBER
//        /// DEGAUSS STUFF
        static void staticEntryDeGauss(const magnetStructs::degaussStruct & ds );
        size_t degaussNum;
//
        std::map< size_t, magnetStructs::degaussStruct > degaussStructsMap;
        std::map< std::string,  std::atomic< bool > > isDegaussingMap; // std::atomic< bool > are not CopyConstructible, so this is held locally
       // std::map< size_t, std::thread* > degaussThreadMap;
//
        void killFinishedDegaussThreads();
//
        void printDegaussResults(const vec_s & magToDegSuccess, const vec_s & magToDegOriginal );
        void getDegaussValues(vec_s & magToDeg, vec_d & values, vec_d & tolerances, size_t step);
//
        void printDegauss();
        void printFinish();
        void printVec( const std::string & p1, const vec_s & v, size_t numPerLine );
//
        ///message
};
#endif // VELA_MAG_INTERFACE_H
