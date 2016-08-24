/*============================================================================
  CMake - Cross Platform Makefile Generator
  Copyright 2000-2013 Kitware, Inc.

  Distributed under the OSI-approved BSD License (the "License");
  see accompanying file Copyright.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/
#ifndef cmCTestP4_h
#define cmCTestP4_h

#include <cmConfigure.h>

#include "cmCTestGlobalVC.h"

#include <iosfwd>
#include <map>
#include <string>
#include <vector>

class cmCTest;

/** \class cmCTestP4
 * \brief Interaction with the Perforce command-line tool
 *
 */
class cmCTestP4 : public cmCTestGlobalVC
{
public:
  /** Construct with a CTest instance and update log stream.  */
  cmCTestP4(cmCTest* ctest, std::ostream& log);

  ~cmCTestP4() CM_OVERRIDE;

private:
  std::vector<std::string> ChangeLists;

  struct User
  {
    std::string UserName;
    std::string Name;
    std::string EMail;
    std::string AccessTime;

    User()
      : UserName()
      , Name()
      , EMail()
      , AccessTime()
    {
    }
  };
  std::map<std::string, User> Users;
  std::vector<std::string> P4Options;

  User GetUserData(const std::string& username);
  void SetP4Options(std::vector<char const*>& options);

  std::string GetWorkingRevision();
  void NoteOldRevision() CM_OVERRIDE;
  void NoteNewRevision() CM_OVERRIDE;
  bool UpdateImpl() CM_OVERRIDE;
  bool UpdateCustom(const std::string& custom);

  void LoadRevisions() CM_OVERRIDE;
  void LoadModifications() CM_OVERRIDE;

  class ChangesParser;
  class DescribeParser;
  class DiffParser;
  // Parsing helper classes.
  class IdentifyParser;
  class UserParser;

  friend class IdentifyParser;
  friend class ChangesParser;
  friend class UserParser;
  friend class DescribeParser;
  friend class DiffParser;
};

#endif
