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

void bind_BinTObjDrivers(py::module &);
void bind_BinTObjDrivers_DocumentRetrievalDriver(py::module &);
void bind_BinTObjDrivers_DocumentStorageDriver(py::module &);
void bind_BinTObjDrivers_IntSparseArrayDriver(py::module &);
void bind_BinTObjDrivers_ModelDriver(py::module &);
void bind_BinTObjDrivers_ObjectDriver(py::module &);
void bind_BinTObjDrivers_ReferenceDriver(py::module &);
void bind_BinTObjDrivers_XYZDriver(py::module &);

PYBIND11_MODULE(BinTObjDrivers, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TDocStd");
py::module::import("OCCT.BinMDF");
py::module::import("OCCT.Message");
py::module::import("OCCT.BinLDrivers");
py::module::import("OCCT.TDF");
py::module::import("OCCT.BinObjMgt");

bind_BinTObjDrivers(mod);
bind_BinTObjDrivers_DocumentRetrievalDriver(mod);
bind_BinTObjDrivers_DocumentStorageDriver(mod);
bind_BinTObjDrivers_IntSparseArrayDriver(mod);
bind_BinTObjDrivers_ModelDriver(mod);
bind_BinTObjDrivers_ObjectDriver(mod);
bind_BinTObjDrivers_ReferenceDriver(mod);
bind_BinTObjDrivers_XYZDriver(mod);

}
