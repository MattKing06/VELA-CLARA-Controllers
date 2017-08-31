#ifndef vela_QSCOPE_CONTROLLER_H
#define vela_QSCOPE_CONTROLLER_H

// project
#include "scopeController.h"
// stl
#include <string>
#include <vector>
#include <map>
#include <list>
//boost
#include <boost/python/detail/wrap_python.hpp>
#define BOOST_PYTHON_STATIC_LIB /// !!! This should come before  #include <boost/python.hpp>
#define BOOST_LIB_DIAGNOSTIC
#include <boost/config.hpp>
#include <boost/python.hpp>
#include <boost/python/class.hpp>
#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include <boost/python/object/function.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include <boost/python/suite/indexing/map_indexing_suite.hpp>
#include <boost/python/docstring_options.hpp>

class VCscopes// : public beamPositionMonitorController
{
    public:

        /// we have overloaded constructors to specify config-file location
//        velaINJBeamPositionMonitorController( const bool show_messages = true, const bool show_debug_messages = true, const std::string configFileLocation );
        VCscopes();
        ~VCscopes();

        scopeController & virtual_VELA_INJ_Scope_Controller();
        scopeController & offline_VELA_INJ_Scope_Controller();
        scopeController & physical_VELA_INJ_Scope_Controller();
        scopeController & virtual_VELA_BA1_Scope_Controller();
        scopeController & offline_VELA_BA1_Scope_Controller();
        scopeController & physical_VELA_BA1_Scope_Controller();
        scopeController & virtual_VELA_BA2_Scope_Controller();
        scopeController & offline_VELA_BA2_Scope_Controller();
        scopeController & physical_VELA_BA2_Scope_Controller();
        scopeController & virtual_CLARA_S01_Scope_Controller();
        scopeController & offline_CLARA_S01_Scope_Controller();
        scopeController & physical_CLARA_S01_Scope_Controller();
        scopeController & virtual_CLARA_PH1_Scope_Controller();
        scopeController & offline_CLARA_PH1_Scope_Controller();
        scopeController & physical_CLARA_PH1_Scope_Controller();
        scopeController & getScopeController( VELA_ENUM::MACHINE_MODE mode, VELA_ENUM::MACHINE_AREA area );

        void setQuiet();
        void setVerbose();
        void setMessage();
        void setDebugMessage();

#ifdef BUILD_DLL
#endif // BUILD_DLL

    protected:
    private:

        bool withEPICS;
        bool withoutEPICS;
        bool withVM;
        bool withoutVM;
        bool showDebugMessages;
        bool showMessages;
        VELA_ENUM::MACHINE_AREA VELA_INJ;
        VELA_ENUM::MACHINE_AREA VELA_BA1;
        VELA_ENUM::MACHINE_AREA VELA_BA2;
        VELA_ENUM::MACHINE_AREA CLARA_S01;
        VELA_ENUM::MACHINE_AREA CLARA_PH1;
        VELA_ENUM::MACHINE_AREA CLARA_2_VELA;
        VELA_ENUM::MACHINE_AREA UNKNOWN_AREA;

        scopeController * virtual_VELA_INJ_Scope_Controller_Obj;
        scopeController * offline_VELA_INJ_Scope_Controller_Obj;
        scopeController * physical_VELA_INJ_Scope_Controller_Obj;
        scopeController * virtual_VELA_BA1_Scope_Controller_Obj;
        scopeController * offline_VELA_BA1_Scope_Controller_Obj;
        scopeController * physical_VELA_BA1_Scope_Controller_Obj;
        scopeController * virtual_VELA_BA2_Scope_Controller_Obj;
        scopeController * offline_VELA_BA2_Scope_Controller_Obj;
        scopeController * physical_VELA_BA2_Scope_Controller_Obj;
        scopeController * virtual_CLARA_S01_Scope_Controller_Obj;
        scopeController * offline_CLARA_S01_Scope_Controller_Obj;
        scopeController * physical_CLARA_S01_Scope_Controller_Obj;
        scopeController * virtual_CLARA_PH1_Scope_Controller_Obj;
        scopeController * offline_CLARA_PH1_Scope_Controller_Obj;
        scopeController * physical_CLARA_PH1_Scope_Controller_Obj;

};

#ifdef BUILD_DLL

/// Boost has incorporated an "autolink" feature.
/// http://www.codeproject.com/Articles/11597/Building-Boost-libraries-for-Visual-Studio
/// or do it yourself!

#define BOOST_LIB_DIAGNOSTIC

/// FUNCTION OVERLOADING, if you have overloaded functions:
/// Create a load of different function pointers and use them in the bindings
/// For examples See magnets...

/// As another example we have overloaded constructors to enable / disable messages
/// and / or debug messages when instantiating. See here
/// http://www.boost.org/doc/libs/1_59_0/libs/python/doc/tutorial/doc/html/python/exposing.html
/// and beware of: http://stackoverflow.com/questions/8140155/boost-python-confused-about-similar-constructor


using namespace boost::python;

//BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS( vvvc_overloads1, openAndWait_Py , 0, 1 );
//BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS( vvvc_overloads2, closeAndWait_Py , 0, 1 );

BOOST_PYTHON_MODULE( VELA_CLARA_Scope_Control )
{

    docstring_options local_docstring_options(true, true, false);
    local_docstring_options.disable_cpp_signatures();
    /// Include ALL the enums you want to expose to Python

//    class_< std::map< scopeStructs::SCOPE_PV_TYPE, std::vector< double > > > ("v2_map")
//        .def( map_indexing_suite< std::map< scopeStructs::SCOPE_PV_TYPE, std::vector< double > > >());
//
//    class_< std::map< scopeStructs::SCOPE_PV_TYPE, std::vector< std::vector< double > > > >("vv2_map")
//        .def( map_indexing_suite< std::map< scopeStructs::SCOPE_PV_TYPE, std::vector< std::vector< double > > > >());
//
//    class_< std::map< scopeStructs::SCOPE_PV_TYPE, bool > >("bool_map")
//        .def( map_indexing_suite< std::map< scopeStructs::SCOPE_PV_TYPE, bool > >());

    boost::python::type_info info = boost::python::type_id< std::vector< std::string > > ();
    const boost::python::converter::registration* reg = boost::python::converter::registry::query(info);
    if (reg == NULL)  {
        class_< std::vector< std::string > >("std_vector_string")
            .def(vector_indexing_suite< std::vector< std::string > > ())
            ;
    } else if ((*reg).m_to_python == NULL) {
        class_< std::vector< std::string > >("std_vector_string")
            .def(vector_indexing_suite< std::vector< std::string > > ())
            ;
    }

    info = boost::python::type_id< std::vector< double > > ();
    reg = boost::python::converter::registry::query(info);
    if (reg == NULL)  {
        class_< std::vector< double > >("std_vector_double")
            .def(vector_indexing_suite< std::vector< double > > ())
            ;
    } else if ((*reg).m_to_python == NULL) {
        class_< std::vector< double > >("std_vector_double")
            .def(vector_indexing_suite< std::vector< double > > ())
            ;
    }

    info = boost::python::type_id< std::vector< std::vector< double > > > ();
    reg = boost::python::converter::registry::query(info);
    if (reg == NULL)  {
        class_< std::vector< std::vector< double > > >("std_vector_vector_double")
            .def(vector_indexing_suite< std::vector< std::vector< double > > > ())
            ;
    } else if ((*reg).m_to_python == NULL) {
        class_< std::vector< std::vector< double > > >("std_vector_vector_double")
            .def(vector_indexing_suite< std::vector< std::vector< double > > > ())
            ;
    }

    info = boost::python::type_id< std::map< scopeStructs::SCOPE_PV_TYPE, bool > > ();
    reg = boost::python::converter::registry::query(info);
    if (reg == NULL)  {
        class_< std::map< scopeStructs::SCOPE_PV_TYPE, std::vector< double > > >("std_scope_map_bool")
            .def( map_indexing_suite< std::map< scopeStructs::SCOPE_PV_TYPE, bool > >())
            ;
    } else if ((*reg).m_to_python == NULL) {
        class_< std::map< scopeStructs::SCOPE_PV_TYPE, std::vector< double > > >("std_scope_map_bool")
            .def( map_indexing_suite< std::map< scopeStructs::SCOPE_PV_TYPE, bool > >())
            ;
    }

    info = boost::python::type_id< std::map< scopeStructs::SCOPE_PV_TYPE, std::vector< double > > >();
    reg = boost::python::converter::registry::query(info);
    if (reg == NULL)  {
        class_< std::map< scopeStructs::SCOPE_PV_TYPE, std::vector< double > > >("std_scope_map_vector_double")
            .def( map_indexing_suite< std::map< scopeStructs::SCOPE_PV_TYPE, std::vector< double > > >())
            ;
    } else if ((*reg).m_to_python == NULL) {
        class_< std::map< scopeStructs::SCOPE_PV_TYPE, std::vector< double > > >("std_scope_map_vector_double")
            .def( map_indexing_suite< std::map< scopeStructs::SCOPE_PV_TYPE, std::vector< double > > >())
            ;
    }

    info = boost::python::type_id< std::map< scopeStructs::SCOPE_PV_TYPE, std::vector< std::vector< double > > > > ();
    reg = boost::python::converter::registry::query(info);
    if (reg == NULL)  {
        class_< std::map< scopeStructs::SCOPE_PV_TYPE, std::vector< std::vector< double > > > >("std_scope_map_vector_vector_double")
            .def( map_indexing_suite< std::map< scopeStructs::SCOPE_PV_TYPE, std::vector< std::vector< double > > > >())
            ;
    } else if ((*reg).m_to_python == NULL) {
        class_< std::map< scopeStructs::SCOPE_PV_TYPE, std::vector< std::vector< double > > > >("std_scope_map_vector_vector_double")
            .def( map_indexing_suite< std::map< scopeStructs::SCOPE_PV_TYPE, std::vector< std::vector< double > > > >())
            ;
    }

    enum_<VELA_ENUM::MACHINE_MODE>("MACHINE_MODE")
            .value("OFFLINE",   VELA_ENUM::MACHINE_MODE::OFFLINE  )
            .value("VIRTUAL",   VELA_ENUM::MACHINE_MODE::VIRTUAL  )
            .value("PHYSICAL",  VELA_ENUM::MACHINE_MODE::PHYSICAL )
            ;

    enum_<VELA_ENUM::MACHINE_AREA>("MACHINE_AREA")
            .value("VELA_INJ",  VELA_ENUM::MACHINE_AREA::VELA_INJ  )
            .value("VELA_BA1",  VELA_ENUM::MACHINE_AREA::VELA_BA1  )
            .value("VELA_BA2",  VELA_ENUM::MACHINE_AREA::VELA_BA2  )
            .value("CLARA_S01", VELA_ENUM::MACHINE_AREA::CLARA_S01 )
            .value("CLARA_S01", VELA_ENUM::MACHINE_AREA::CLARA_PH1 )
            .value("CLARA_S02", VELA_ENUM::MACHINE_AREA::CLARA_S02 )
            .value("C2V",       VELA_ENUM::MACHINE_AREA::CLARA_2_VELA )
            ;

    enum_<VELA_ENUM::ILOCK_STATE>("ILOCK_STATE")
            .value("ILOCK_BAD",   VELA_ENUM::ILOCK_STATE::ILOCK_BAD   )
            .value("ILOCK_GOOD",  VELA_ENUM::ILOCK_STATE::ILOCK_GOOD  )
            .value("ILOCK_ERROR", VELA_ENUM::ILOCK_STATE::ILOCK_ERROR )
            ;

    enum_<scopeStructs::SCOPE_PV_TYPE>("SCOPE_PV_TYPE")
            .value("TR1", scopeStructs::SCOPE_PV_TYPE::TR1 )
            .value("TR2", scopeStructs::SCOPE_PV_TYPE::TR2 )
            .value("TR3", scopeStructs::SCOPE_PV_TYPE::TR3 )
            .value("TR4", scopeStructs::SCOPE_PV_TYPE::TR4 )
            .value("P1",  scopeStructs::SCOPE_PV_TYPE::P1  )
            .value("P2",  scopeStructs::SCOPE_PV_TYPE::P2  )
            .value("P3",  scopeStructs::SCOPE_PV_TYPE::P3  )
            .value("P4",  scopeStructs::SCOPE_PV_TYPE::P4  )
            .value("UNKNOWN",  scopeStructs::SCOPE_PV_TYPE::UNKNOWN  )
            ;

    enum_<VELA_ENUM::DIAG_TYPE>("DIAG_TYPE")
            .value("WCM",     VELA_ENUM::DIAG_TYPE::WCM       )
            .value("ICT1",    VELA_ENUM::DIAG_TYPE::ICT2      )
            .value("ICT2",    VELA_ENUM::DIAG_TYPE::ICT2      )
            .value("FCUP",    VELA_ENUM::DIAG_TYPE::FCUP      )
            .value("ED_FCUP", VELA_ENUM::DIAG_TYPE::ED_FCUP   )
            ;
    char const* scopeNumObjectStructString = "This struct contains data for the four channels on the scope - e.g. p1 contains the P1 value from the scope.\n"
                                       "This will only contain real-time data if scope number data is being submitted to EPICS - you will need to check this on the scope.\n"
                                       "p1Vec contains a vector of values after monitorNumsForNShots, and numData contains a vector of vectors, with data from all four channels on the scope.\n"
                                       "Timestamps can also be accessed.";
    boost::python::class_<scopeStructs::scopeNumObject,boost::noncopyable>
        ("scopeNumObject",scopeNumObjectStructString,boost::python::no_init)
        .def_readonly("isMonitoringMap", &scopeStructs::scopeNumObject::isMonitoringMap)
        .def_readonly("name",            &scopeStructs::scopeNumObject::name           )
        .def_readonly("p1",              &scopeStructs::scopeNumObject::p1             )
        .def_readonly("p2",              &scopeStructs::scopeNumObject::p2             )
        .def_readonly("p3",              &scopeStructs::scopeNumObject::p3             )
        .def_readonly("p4",              &scopeStructs::scopeNumObject::p4             )
        .def_readonly("p1TimeStamp",     &scopeStructs::scopeNumObject::p1TimeStamp    )
        .def_readonly("p2TimeStamp",     &scopeStructs::scopeNumObject::p2TimeStamp    )
        .def_readonly("p3TimeStamp",     &scopeStructs::scopeNumObject::p3TimeStamp    )
        .def_readonly("p4TimeStamp",     &scopeStructs::scopeNumObject::p4TimeStamp    )
        .def_readonly("p1TimeStamps",    &scopeStructs::scopeNumObject::p1TimeStamps   )
        .def_readonly("p2TimeStamps",    &scopeStructs::scopeNumObject::p2TimeStamps   )
        .def_readonly("p3TimeStamps",    &scopeStructs::scopeNumObject::p3TimeStamps   )
        .def_readonly("p4TimeStamps",    &scopeStructs::scopeNumObject::p4TimeStamps   )
        .def_readonly("p1Vec",           &scopeStructs::scopeNumObject::p1Vec          )
        .def_readonly("p2Vec",           &scopeStructs::scopeNumObject::p2Vec          )
        .def_readonly("p3Vec",           &scopeStructs::scopeNumObject::p3Vec          )
        .def_readonly("p4Vec",           &scopeStructs::scopeNumObject::p4Vec          )
        .def_readonly("numData",         &scopeStructs::scopeNumObject::numData        )
        .def_readonly("numTimeStamps",   &scopeStructs::scopeNumObject::numTimeStamps  )
        .def_readonly("shotCounts",      &scopeStructs::scopeNumObject::shotCounts     )
        .def_readonly("buffer",          &scopeStructs::scopeNumObject::buffer         )
        ;

    char const* scopeTraceDataStructString = "This struct contains trace data for the four channels on the scope - e.g. tr1TraceData contains a vector of the EPICS PV for channel 1 on the scope.\n"
                                             "This will only contain real-time data if scope trace data is being submitted to EPICS - you will need to check this on the scope.\n";
                                             "traceData contains a vector of vectors, with data from all four channels on the scope.\n"
                                             "Timestamps can also be accessed.";
    boost::python::class_<scopeStructs::scopeTraceData,boost::noncopyable>
        ("scopeTraceData",scopeTraceDataStructString,boost::python::no_init)
        .def_readonly("isMonitoringMap", &scopeStructs::scopeTraceData::isMonitoringMap)
        .def_readonly("name",            &scopeStructs::scopeTraceData::name           )
        .def_readonly("pvRoot",          &scopeStructs::scopeTraceData::pvRoot         )
        .def_readonly("tr1TraceData",    &scopeStructs::scopeTraceData::tr1TraceData   )
        .def_readonly("tr2TraceData",    &scopeStructs::scopeTraceData::tr1TraceData   )
        .def_readonly("tr3TraceData",    &scopeStructs::scopeTraceData::tr1TraceData   )
        .def_readonly("tr4TraceData",    &scopeStructs::scopeTraceData::tr1TraceData   )
        .def_readonly("traceData",       &scopeStructs::scopeTraceData::traceData      )
        .def_readonly("tr1TimeStamps",   &scopeStructs::scopeTraceData::tr1TimeStamps  )
        .def_readonly("tr2TimeStamps",   &scopeStructs::scopeTraceData::tr2TimeStamps  )
        .def_readonly("tr3TimeStamps",   &scopeStructs::scopeTraceData::tr3TimeStamps  )
        .def_readonly("tr4TimeStamps",   &scopeStructs::scopeTraceData::tr4TimeStamps  )
        .def_readonly("shotCounts",      &scopeStructs::scopeTraceData::shotCounts     )
        .def_readonly("timebase",        &scopeStructs::scopeTraceData::timebase       )
        .def_readonly("timeStamps",      &scopeStructs::scopeTraceData::timeStamps     )
        ;

    boost::python::class_<baseObject, boost::noncopyable>("baseObject", boost::python::no_init)
        ;

    /// we have to tell boost.python about pure virtual methods in abstract base classes

    boost::python::class_<controller, boost::python::bases<baseObject>,  boost::noncopyable> ("controller", boost::python::no_init)
//        .def("get_CA_PEND_IO_TIMEOUT", boost::python::pure_virtual(&controller::get_CA_PEND_IO_TIMEOUT) )
//        .def("set_CA_PEND_IO_TIMEOUT", boost::python::pure_virtual(&controller::set_CA_PEND_IO_TIMEOUT) )
        .def("getILockStatesStr",      boost::python::pure_virtual(&controller::getILockStatesStr)      )
        .def("getILockStates",         boost::python::pure_virtual(&controller::getILockStates)         )
		;
    /// member functiosn to expose to python, remmeber to include enum deifntions as boost::python::dict <int, string>

    char const* getScopeTraceDataStructString = "Returns the scope trace data struct for str(scopeName). See documentation on the scopeTraceData struct for what this contains.";
    char const* getScopeNumDataStructString = "Returns the scope number data struct for str(scopeName). See documentation on the scopeNumData struct for what this contains.";
    char const* isMonitoringTraceDocString = "Returns true if str(scopeName) traces are being monitored - these are defined in the config file.";
    char const* isMonitoringNumDocString = "Returns true if str(scopeName) P values are being monitored - these are defined in the config file.";
    char const* isNotMonitoringTraceDocString = "Returns true if str(scopeName) traces are not being monitored - these are defined in the config file.";
    char const* isNotMonitoringNumDocString = "Returns true if str(scopeName) P values are not being monitored - these are defined in the config file.";
    char const* setBufferSizeDocString = "Set size of buffer for continuous monitor.";
    char const* setNumBufferSizeDocString = "Set size of buffer for continuous P values monitor.";
    char const* setTraceBufferSizeDocString = "Set size of buffer for continuous trace monitor.";
    char const* restartMonitoringDocString = "Restarts continuous monitoring of scope parameters. !!!!!!!WILL RESET ALL VALUES!!!!!!!.";
    char const* getScopeNumsDocString = "Returns a vector of doubles for str(scopeName), for the channel SCOPE_PV_TYPE(pvType), after using monitorNumsForNShots.";
    char const* getScopeP1VecDocString = "Returns a vector of doubles for str(scopeName), for channel P1, after using monitorNumsForNShots.";
    char const* getScopeP2VecDocString = "Returns a vector of doubles for str(scopeName), for channel P2, after using monitorNumsForNShots.";
    char const* getScopeP3VecDocString = "Returns a vector of doubles for str(scopeName), for channel P3, after using monitorNumsForNShots.";
    char const* getScopeP4VecDocString = "Returns a vector of doubles for str(scopeName), for channel P4, after using monitorNumsForNShots.";
    char const* getScopeP1DocString = "Returns a double containing the value for channel P1 for str(scopeName).";
    char const* getScopeP2DocString = "Returns a double containing the value for channel P2 for str(scopeName).";
    char const* getScopeP3DocString = "Returns a double containing the value for channel P3 for str(scopeName).";
    char const* getScopeP4DocString = "Returns a double containing the value for channel P4 for str(scopeName).";
    char const* getScopeNumBufferDocString = "Returns a vector containing the last (buffersize) values for a given channel for str(scopeName).";
    char const* getScopeTraceBufferDocString = "Returns a vector of vectors containing the last (buffersize) traces for a given channel for str(scopeName).";
    char const* getWCMQDocString = "Returns a double containing the current value for the WCM, provided that the WCM channel is defined in the config file.\n"
                          "This should work regardless of whether traces or P values are being submitted to EPICS (not for dark current measurements).";
    char const* getICT1QDocString = "Returns a double containing the current value for the ICT1, provided that the ICT1 channel is defined in the config file.\n"
                          "This should work regardless of whether traces or P values are being submitted to EPICS.";
    char const* getICT2QDocString = "Returns a double containing the current value for the ICT2, provided that the ICT2 channel is defined in the config file.\n"
                          "This should work regardless of whether traces or P values are being submitted to EPICS.";
    char const* getFCUPQDocString = "Returns a double containing the current value for the FCUP, provided that the FCUP channel is defined in the config file.\n"
                          "This should work regardless of whether traces or P values are being submitted to EPICS.";
    char const* getEDFCUPQDocString = "Returns a double containing the current value for the ED-FCUP, provided that the ED-FCUP channel is defined in the config file.\n"
                          "This should work regardless of whether traces or P values are being submitted to EPICS.";
    char const* getScopeTracesDocString = "Returns a vector of vectors of doubles for str(scopeName), for the channel SCOPE_PV_TYPE(pvType), after using monitorTracesForNShots.";
    char const* getPartOfTraceDocString = "Returns a vector of vectors of doubles for str(scopeName), for the channel SCOPE_PV_TYPE(pvType), of a user-specified portion of the trace (between part1 and part2), after using monitorTracesForNShots.";
    char const* getAreaUnderTracesDocString = "Returns a vector of doubles for str(scopeName), for the channel SCOPE_PV_TYPE(pvType), containing the area under each trace.\n"
                                              "This function should only be used after using monitorTracesForNShots.";
    char const* getAreaUnderPartOfTraceDocString = "Returns a vector of doubles for str(scopeName), for the channel SCOPE_PV_TYPE(pvType), containing the area under a user-specified portion of the trace (between part1 and part2).\n"
                                              "The user should specify part1 and part2 to be regions of the trace where there is no signal (it may be good to check the array size first).";
                                              "This function should only be used after using monitorTracesForNShots.";
    char const* getAvgNoiseDocString = "Returns a vector of doubles for str(scopeName), for the channel SCOPE_PV_TYPE(pvType), containing the average noise in a user-specified portion of the trace (between part1 and part2).\n"
                                              "This function should only be used after using monitorTracesForNShots.";
    char const* getMaxOfTracesDocString = "Returns a vector of doubles for str(scopeName), for the channel SCOPE_PV_TYPE(pvType), containing the maximum value of each trace\n"
                                              "This function should only be used after using monitorTracesForNShots.";
    char const* getMinOfTracesDocString = "Returns a vector of doubles for str(scopeName), for the channel SCOPE_PV_TYPE(pvType), containing the minimum value of each trace\n"
                                              "This function should only be used after using monitorTracesForNShots.";
    char const* getTimeStampsDocString = "Returns a vector containing the timestamps as doubles for str(scope), for the channel SCOPE_PV_TYPE(pvType) - these are defined in the config file.\n"
                                         "To be used in conjunction with functions monitorNumsForNShots or monitorTracesForNShots.";
    char const* getStrTimeStampsDocString = "Returns a vector containing the timestamps as strings (if that's your thing) for str(scope), for the channel SCOPE_PV_TYPE(pvType) - these are defined in the config file.\n"
                                         "To be used in conjunction with functions monitorNumsForNShots or monitorTracesForNShots.";
    char const* monitorNumsDocString = "Monitors P values (see scope) for str(scopeName) - these should be defined in the config file. This will fill four vectors of doubles with scope data.\n"
                                      "Data can be accessed using getScopeNums, or getScopeP(1/2/3/4)Vec.\n";
    char const* monitorTracesDocString = "Monitors traces (see scope) for str(scopeName) - these should be defined in the config file. This will fill four vectors of vectors of doubles with scope trace data.\n"
                                      "Data can be accessed using getScopeTraces - see documentation.\n";
    char const* monitorATraceDocString = "Monitors a specific trace (see scope) for channel (pvType) of str(scopeName) - these should be defined in the config file. This will fill a vectors of vectors of doubles with scope trace data.\n"
                                      "Data can be accessed using getScopeTraces - see documentation.\n";
    char const* monitorANumDocString = "Monitors a specific P value (see scope) for channel (pvType) of str(scopeName) - these should be defined in the config file. This will fill a vector of doubles with scope data.\n"
                                      "Data can be accessed using getScopeTraces - see documentation.\n";

	boost::python::class_<scopeController, boost::python::bases<controller>, boost::noncopyable>
            ("scopeController","scopeController Doc String",boost::python::no_init)
//            .def(boost::python::init<const std::string, const std::string, optional<  const bool, const bool > >())
//            .def(boost::python::init< optional<const bool, const bool, const bool> >())
//            .def("getScopeStateDefinition",         &scopeController::getScopeStateDefinition                   )
//            .def("getILockStatesDefinition",        &scopeController::getILockStatesDefinition                  )
            .def("get_CA_PEND_IO_TIMEOUT",          &scopeController::get_CA_PEND_IO_TIMEOUT                    )
            .def("set_CA_PEND_IO_TIMEOUT",          &scopeController::set_CA_PEND_IO_TIMEOUT                    )
//            .def("getScopeState",                   &velaChargeScopeController::getScopeState_Py                          )
//            .def("getILockStates",                  &velaChargeScopeController::getILockStates_Py                         )
//            .def("hasNoTrig",                       &velaChargeScopeController::hasNoTrig_Py, boost::python::args("name") )
//            .def("hasTrig",                         &velaChargeScopeController::hasTrig_Py, boost::python::args("name")   )
            .def("getScopeTraceDataStruct",         &scopeController::getScopeTraceDataStruct, getScopeTraceDataStructString, return_value_policy<reference_existing_object>())
            .def("getScopeNumDataStruct",           &scopeController::getScopeNumDataStruct, getScopeNumDataStructString, return_value_policy<reference_existing_object>()  )
            .def("isMonitoringScopeTrace",          &scopeController::isMonitoringScopeTrace, isMonitoringTraceDocString           )
            .def("isMonitoringScopeNum",            &scopeController::isMonitoringScopeNum, isMonitoringNumDocString               )
            .def("isNotMonitoringScopeTrace",       &scopeController::isNotMonitoringScopeTrace, isNotMonitoringNumDocString       )
            .def("isNotMonitoringScopeNum",         &scopeController::isNotMonitoringScopeNum, isNotMonitoringNumDocString         )
            .def("setBufferSize",                   &scopeController::setBufferSize, setBufferSizeDocString                        )
            .def("setNumBufferSize",                &scopeController::setBufferSize, setNumBufferSizeDocString                     )
            .def("setTraceBufferSize",              &scopeController::setBufferSize, setTraceBufferSizeDocString                   )
            .def("restartContinuousMonitoring",     &scopeController::restartContinuousMonitoring, restartMonitoringDocString      )
            .def("getScopeNums",                    &scopeController::getScopeNums_Py, getScopeNumsDocString                       )
            .def("getScopeP1Vec",                   &scopeController::getScopeP1Vec_Py, getScopeP1VecDocString                     )
            .def("getScopeP2Vec",                   &scopeController::getScopeP2Vec_Py, getScopeP2VecDocString                     )
            .def("getScopeP3Vec",                   &scopeController::getScopeP3Vec_Py, getScopeP3VecDocString                     )
            .def("getScopeP4Vec",                   &scopeController::getScopeP4Vec_Py, getScopeP4VecDocString                     )
            .def("getScopeP1Buffer",                &scopeController::getScopeP1Buffer_Py, getScopeNumBufferDocString              )
            .def("getScopeP2Buffer",                &scopeController::getScopeP2Buffer_Py, getScopeNumBufferDocString              )
            .def("getScopeP3Buffer",                &scopeController::getScopeP3Buffer_Py, getScopeNumBufferDocString              )
            .def("getScopeP4Buffer",                &scopeController::getScopeP4Buffer_Py, getScopeNumBufferDocString              )
            .def("getScopeTR1Buffer",               &scopeController::getScopeTR1Buffer_Py, getScopeTraceBufferDocString           )
            .def("getScopeTR2Buffer",               &scopeController::getScopeTR2Buffer_Py, getScopeTraceBufferDocString           )
            .def("getScopeTR3Buffer",               &scopeController::getScopeTR3Buffer_Py, getScopeTraceBufferDocString           )
            .def("getScopeTR4Buffer",               &scopeController::getScopeTR4Buffer_Py, getScopeTraceBufferDocString           )
            .def("getScopeP1",                      &scopeController::getScopeP1, getScopeP1DocString                              )
            .def("getScopeP2",                      &scopeController::getScopeP2, getScopeP2DocString                              )
            .def("getScopeP3",                      &scopeController::getScopeP3, getScopeP3DocString                              )
            .def("getScopeP4",                      &scopeController::getScopeP4, getScopeP4DocString                              )
            .def("getWCMQ",                         &scopeController::getWCMQ, getWCMQDocString                                    )
            .def("getICT1Q",                        &scopeController::getICT1Q, getICT1QDocString                                  )
            .def("getICT2Q",                        &scopeController::getICT2Q, getICT2QDocString                                  )
            .def("getFCUPQ",                        &scopeController::getFCUPQ, getFCUPQDocString                                  )
            .def("getEDFCUPQ",                      &scopeController::getEDFCUPQ, getEDFCUPQDocString                              )
            .def("getScopeTraces",                  &scopeController::getScopeTraces, getScopeTracesDocString                      )
            .def("getMinOfTraces",                  &scopeController::getMinOfTraces_Py, getMinOfTracesDocString                   )
            .def("getMaxOfTraces",                  &scopeController::getMaxOfTraces_Py, getMaxOfTracesDocString                   )
            .def("getAreaUnderTraces",              &scopeController::getAreaUnderTraces_Py, getAreaUnderTracesDocString           )
            .def("getAreaUnderPartOfTrace",         &scopeController::getAreaUnderPartOfTrace_Py, getAreaUnderPartOfTraceDocString )
            .def("getAvgNoise",                     &scopeController::getAvgNoise_Py, getAvgNoiseDocString                         )
            .def("getPartOfTrace",                  &scopeController::getPartOfTrace, getPartOfTraceDocString                      )
            .def("getTimeStamps",                   &scopeController::getTimeStamps_Py, getTimeStampsDocString                     )
            .def("getStrTimeStamps",                &scopeController::getStrTimeStamps_Py, getStrTimeStampsDocString               )
            .def("monitorNumsForNShots",            &scopeController::monitorNumsForNShots, monitorNumsDocString                   )
            .def("monitorANumForNShots",            &scopeController::monitorANumForNShots, monitorANumDocString                   )
            .def("monitorTracesForNShots",          &scopeController::monitorTracesForNShots, monitorTracesDocString               )
            .def("monitorATraceForNShots",          &scopeController::monitorATraceForNShots, monitorATraceDocString               )
            .def("getScopeNames",                   &scopeController::getScopeNames_Py                                             )
            .def("getScopePVs",                     &scopeController::getScopePVs_Py                                               )
            .def("getScopeTracePVs",                &scopeController::getScopeTracePVs_Py                                          )
            .def("getScopeNumPVs",                  &scopeController::getScopeNumPVs_Py                                            )
            /// Don't forget functions in the base class we want to expose....
            .def("debugMessagesOff",                &scopeController::debugMessagesOff                       )
            .def("debugMessagesOn",                 &scopeController::debugMessagesOn                        )
            .def("messagesOff",                     &scopeController::messagesOff                            )
            .def("messagesOn",                      &scopeController::messagesOn                             )
            .def("silence",                         &scopeController::silence                                )
            .def("verbose",                         &scopeController::verbose                                )
		;

    boost::python::class_<VCscopes,boost::noncopyable> ("init")
        .def("virtual_VELA_INJ_Scope_Controller",   &VCscopes::virtual_VELA_INJ_Scope_Controller, return_value_policy<reference_existing_object>())
        .def("offline_VELA_INJ_Scope_Controller",   &VCscopes::offline_VELA_INJ_Scope_Controller, return_value_policy<reference_existing_object>())
        .def("physical_VELA_INJ_Scope_Controller",  &VCscopes::physical_VELA_INJ_Scope_Controller, return_value_policy<reference_existing_object>())
        .def("virtual_VELA_BA1_Scope_Controller",   &VCscopes::virtual_VELA_BA1_Scope_Controller, return_value_policy<reference_existing_object>())
        .def("offline_VELA_BA1_Scope_Controller",   &VCscopes::offline_VELA_BA1_Scope_Controller, return_value_policy<reference_existing_object>())
        .def("physical_VELA_BA1_Scope_Controller",  &VCscopes::physical_VELA_BA1_Scope_Controller, return_value_policy<reference_existing_object>())
        .def("virtual_VELA_BA2_Scope_Controller",   &VCscopes::virtual_VELA_BA2_Scope_Controller, return_value_policy<reference_existing_object>())
        .def("offline_VELA_BA2_Scope_Controller",   &VCscopes::offline_VELA_BA2_Scope_Controller, return_value_policy<reference_existing_object>())
        .def("physical_VELA_BA2_Scope_Controller",  &VCscopes::physical_VELA_BA2_Scope_Controller, return_value_policy<reference_existing_object>())
        .def("virtual_CLARA_S01_Scope_Controller",  &VCscopes::virtual_CLARA_S01_Scope_Controller, return_value_policy<reference_existing_object>())
        .def("offline_CLARA_S01_Scope_Controller",  &VCscopes::offline_CLARA_S01_Scope_Controller, return_value_policy<reference_existing_object>())
        .def("physical_CLARA_S01_Scope_Controller", &VCscopes::physical_CLARA_S01_Scope_Controller, return_value_policy<reference_existing_object>())
        .def("virtual_CLARA_PH1_Scope_Controller",  &VCscopes::virtual_CLARA_PH1_Scope_Controller, return_value_policy<reference_existing_object>())
        .def("offline_CLARA_PH1_Scope_Controller",  &VCscopes::offline_CLARA_PH1_Scope_Controller, return_value_policy<reference_existing_object>())
        .def("physical_CLARA_PH1_Scope_Controller", &VCscopes::physical_CLARA_PH1_Scope_Controller, return_value_policy<reference_existing_object>())
        .def("getScopeController",                  &VCscopes::getScopeController, return_value_policy<reference_existing_object>())
        ;

};

#endif // BUILD_DLL

#endif // velaChrageScopeController_H

