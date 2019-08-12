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

void bind_BinLDrivers_Marker(py::module &);
void bind_BinLDrivers_DocumentSection(py::module &);
void bind_BinLDrivers_VectorOfDocumentSection(py::module &);
void bind_BinLDrivers_DocumentRetrievalDriver(py::module &);
void bind_BinLDrivers_DocumentStorageDriver(py::module &);
void bind_BinLDrivers(py::module &);

PYBIND11_MODULE(BinLDrivers, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.PCDM");
py::module::import("OCCT.CDM");
py::module::import("OCCT.Storage");
py::module::import("OCCT.BinMDF");
py::module::import("OCCT.Message");
py::module::import("OCCT.TDF");
py::module::import("OCCT.BinObjMgt");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TDocStd");

bind_BinLDrivers_Marker(mod);
bind_BinLDrivers_DocumentSection(mod);
bind_BinLDrivers_VectorOfDocumentSection(mod);
bind_BinLDrivers_DocumentRetrievalDriver(mod);
bind_BinLDrivers_DocumentStorageDriver(mod);
bind_BinLDrivers(mod);

}
