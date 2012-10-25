#ifndef REGISTERAPPINTERFACE_RESPONSEMARSHALLER_INCLUDE
#define REGISTERAPPINTERFACE_RESPONSEMARSHALLER_INCLUDE

#include <string>
#include <json/value.h>
#include <json/reader.h>
#include <json/writer.h>

#include "../../include/JSONHandler/ALRPCObjects/RegisterAppInterface_response.h"


/*
  interface	Ford Sync RAPI
  version	1.2
  date		2011-05-17
  generated at	Thu Oct 25 06:32:04 2012
  source stamp	Thu Oct 25 06:28:28 2012
  author	robok0der
*/


struct RegisterAppInterface_responseMarshaller
{
  static bool checkIntegrity(RegisterAppInterface_response& e);
  static bool checkIntegrityConst(const RegisterAppInterface_response& e);

  static bool fromString(const std::string& s,RegisterAppInterface_response& e);
  static const std::string toString(const RegisterAppInterface_response& e);

  static bool fromJSON(const Json::Value& s,RegisterAppInterface_response& e);
  static Json::Value toJSON(const RegisterAppInterface_response& e);
};
#endif
