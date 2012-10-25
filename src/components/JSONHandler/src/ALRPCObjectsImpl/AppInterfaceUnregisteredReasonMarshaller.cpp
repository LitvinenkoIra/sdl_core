#include <cstring>
#include "../../include/JSONHandler/ALRPCObjects/AppInterfaceUnregisteredReason.h"
#include "AppInterfaceUnregisteredReasonMarshaller.h"
#include "AppInterfaceUnregisteredReasonMarshaller.inc"


/*
  interface	Ford Sync RAPI
  version	1.2
  date		2011-05-17
  generated at	Thu Oct 25 06:32:04 2012
  source stamp	Thu Oct 25 06:28:28 2012
  author	robok0der
*/



const AppInterfaceUnregisteredReason::AppInterfaceUnregisteredReasonInternal AppInterfaceUnregisteredReasonMarshaller::getIndex(const char* s)
{
  if(!s)
    return AppInterfaceUnregisteredReason::INVALID_ENUM;
  const struct PerfectHashTable* p=AppInterfaceUnregisteredReason_intHash::getPointer(s,strlen(s));
  return p ? static_cast<AppInterfaceUnregisteredReason::AppInterfaceUnregisteredReasonInternal>(p->idx) : AppInterfaceUnregisteredReason::INVALID_ENUM;
}


bool AppInterfaceUnregisteredReasonMarshaller::fromJSON(const Json::Value& s,AppInterfaceUnregisteredReason& e)
{
  e.mInternal=AppInterfaceUnregisteredReason::INVALID_ENUM;
  if(!s.isString())
    return false;

  e.mInternal=getIndex(s.asString().c_str());
  return (e.mInternal!=AppInterfaceUnregisteredReason::INVALID_ENUM);
}


Json::Value AppInterfaceUnregisteredReasonMarshaller::toJSON(const AppInterfaceUnregisteredReason& e)
{
  if(e.mInternal==AppInterfaceUnregisteredReason::INVALID_ENUM) 
    return Json::Value(Json::nullValue);
  const char* s=getName(e.mInternal);
  return s ? Json::Value(s) : Json::Value(Json::nullValue);
}


bool AppInterfaceUnregisteredReasonMarshaller::fromString(const std::string& s,AppInterfaceUnregisteredReason& e)
{
  e.mInternal=AppInterfaceUnregisteredReason::INVALID_ENUM;
  try
  {
    Json::Reader reader;
    Json::Value json;
    if(!reader.parse(s,json,false))  return false;
    if(fromJSON(json,e))  return true;
  }
  catch(...)
  {
    return false;
  }
  return false;
}

const std::string AppInterfaceUnregisteredReasonMarshaller::toString(const AppInterfaceUnregisteredReason& e)
{
  Json::FastWriter writer;
  return e.mInternal==AppInterfaceUnregisteredReason::INVALID_ENUM ? "" : writer.write(toJSON(e));

}

const PerfectHashTable AppInterfaceUnregisteredReasonMarshaller::mHashTable[10]=
{
  {"USER_EXIT",0},
  {"IGNITION_OFF",1},
  {"BLUETOOTH_OFF",2},
  {"USB_DISCONNECTED",3},
  {"REQUEST_WHILE_IN_NONE_HMI_LEVEL",4},
  {"TOO_MANY_REQUESTS",5},
  {"DRIVER_DISTRACTION_VIOLATION",6},
  {"LANGUAGE_CHANGE",7},
  {"MASTER_RESET",8},
  {"FACTORY_DEFAULTS",9}
};
