#ifndef _VELA_BPM_STRUCTS_H_
#define _VELA_BPM_STRUCTS_H_
//
#include "structs.h"
#include "configDefinitions.h"
//stl
#include <string>
#include <map>
//epics
#ifndef __CINT__
#include <cadef.h>
#endif
//boost
#include <boost/circular_buffer.hpp>

class beamPositionMonitorInterface;


namespace beamPositionMonitorStructs
{
    /// Forward declare structs, gcc seems to like this...

    struct monitorStruct;
    struct bpmObject;
    struct bpmDataObject;
    struct rawDataStruct;
    struct pvStruct;

    DEFINE_ENUM_WITH_STRING_CONVERSIONS( BPM_PV_TYPE, (SA1) (SA2) (SD1) (SD2) (RA1) (RA2) (RD1) (RD2) (X) (Y) (DATA) )
    enum dataCollectionResult {  waiting, collected, timeout };

    /// monType could be used to switch in the staticCallbackFunction
    /// For the bpm this is basically redundant, there is only one monitor: "Sta"
    /// (apart from interlocks, these are handled in the base class)

    struct monitorStruct
    {
        BPM_PV_TYPE        monType;
        bpmObject*         bpmObject;
        std::string        objName;
        chtype             CHTYPE;
        void *             val;
        beamPositionMonitorInterface *interface;
        evid               EVID;
    };

    struct pvStruct
    {
        BPM_PV_TYPE         pvType;
        chid                CHID;
        std::string         pvSuffix;
        unsigned long       COUNT, MASK;
        chtype              CHTYPE;
        evid                EVID;
    };

    struct rawDataStruct
    {
        rawDataStruct() : shotCount( 0 ),
                          numShots( 1 ),
                          buffer( UTL::BUFFER_TEN ) {}
        std::string name;
        int shotCount, numShots;
        bool isAContinuousMonitorStruct, isATemporaryMonitorStruct, appendingData;
        size_t buffer;
        std::vector< double > p1, p2, pu1, pu2, pu3, pu4, c1, c2, x, y, q;
        std::vector< double > timeStamps;
        std::vector< std::vector< double > > rawBPMData;
        std::vector< std::string > strTimeStamps;
        boost::circular_buffer< double > xBuffer, yBuffer, qBuffer;
        boost::circular_buffer< double > timeStampsBuffer;
        boost::circular_buffer< std::string > strTimeStampsBuffer;
        boost::circular_buffer< std::vector< double > > rawDataBuffer;
    };

    struct bpmDataObject
    {
        bpmDataObject() : shotCount( 0 ),
                          numShots( 1 ),
                          buffer( UTL::BUFFER_TEN ) {}
        std::string name, pvRoot;
        bool isAContinuousMonitorStruct, isATemporaryMonitorStruct;
        bool appendingData;
        int shotCount, numShots; /// we allow -1 values here so NOT a size_t
        double xPV, yPV;
        double att1cal, att2cal, v1cal, v2cal, qcal, mn, xn, yn;
        double awak, rdy, q;
        long sa1, sa2, ra1, ra2, sd1, sd2, rd1, rd2;
        size_t buffer;
        rawDataStruct bpmRawData;
        std::vector< double > timeStamps;
        std::vector< std::string > strTimeStamps;
        std::vector< std::vector< double > > bpmData;
        boost::circular_buffer< double > xPVBuffer, yPVBuffer;
        VELA_ENUM::TRIG_STATE bpmState;
        VELA_ENUM::MACHINE_AREA machineArea;
        VELA_ENUM::MACHINE_MODE machineMode;
    #ifndef __CINT__
        std::map< BPM_PV_TYPE, pvStruct > pvMonStructs;
        std::map< BPM_PV_TYPE, pvStruct > pvComStructs;
    #endif
    };

    struct bpmObject
    {
        std::string name;
        std::map< std::string, bpmDataObject > dataObjects; /// There are nine bpm data objects
        std::map< VELA_ENUM::ILOCK_NUMBER , VELA_ENUM::ILOCK_STATE > iLockStates;
        std::map< VELA_ENUM::ILOCK_NUMBER, VELA_ENUM::iLockPVStruct > iLockPVStructs;

    };

}
#endif
