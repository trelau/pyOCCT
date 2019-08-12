/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>

void bind_CDF_TypeOfActivation(py::module &);
void bind_CDF_TryStoreStatus(py::module &);
void bind_CDF_StoreSetNameStatus(py::module &);
void bind_CDF_SubComponentStatus(py::module &);
void bind_CDF_Application(py::module &);
void bind_CDF(py::module &);
void bind_CDF_Directory(py::module &);
void bind_CDF_DirectoryIterator(py::module &);
void bind_CDF_MetaDataDriver(py::module &);
void bind_CDF_FWOSDriver(py::module &);
void bind_CDF_MetaDataDriverError(py::module &);
void bind_CDF_MetaDataDriverFactory(py::module &);
void bind_CDF_Session(py::module &);
void bind_CDF_Store(py::module &);
void bind_CDF_StoreList(py::module &);

PYBIND11_MODULE(CDF, mod) {

py::module::import("OCCT.CDM");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.PCDM");
py::module::import("OCCT.NCollection");

bind_CDF_TypeOfActivation(mod);
bind_CDF_TryStoreStatus(mod);
bind_CDF_StoreSetNameStatus(mod);
bind_CDF_SubComponentStatus(mod);
bind_CDF_Application(mod);
bind_CDF(mod);
bind_CDF_Directory(mod);
bind_CDF_DirectoryIterator(mod);
bind_CDF_MetaDataDriver(mod);
bind_CDF_FWOSDriver(mod);
bind_CDF_MetaDataDriverError(mod);
bind_CDF_MetaDataDriverFactory(mod);
bind_CDF_Session(mod);
bind_CDF_Store(mod);
bind_CDF_StoreList(mod);

}
