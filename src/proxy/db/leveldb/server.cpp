/*  Copyright (C) 2014-2020 FastoGT. All right reserved.

    This file is part of FastoNoSQL.

    FastoNoSQL is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    FastoNoSQL is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FastoNoSQL. If not, see <http://www.gnu.org/licenses/>.
*/

#include "proxy/db/leveldb/server.h"

#include <string>

#include "proxy/db/leveldb/database.h"
#include "proxy/db/leveldb/driver.h"

namespace fastonosql {
namespace proxy {
namespace leveldb {

Server::Server(IConnectionSettingsBaseSPtr settings) : IServerLocal(new Driver(settings)) {}

std::string Server::GetPath() const {
  Driver* ldrv = static_cast<Driver*>(drv_);
  return ldrv->GetPath();
}

IDatabaseSPtr Server::CreateDatabase(core::IDataBaseInfoSPtr info) {
  return IDatabaseSPtr(new Database(shared_from_this(), info));
}

}  // namespace leveldb
}  // namespace proxy
}  // namespace fastonosql
