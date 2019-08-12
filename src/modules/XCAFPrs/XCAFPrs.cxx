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

void bind_XCAFPrs_Style(py::module &);
void bind_XCAFPrs_IndexedDataMapOfShapeStyle(py::module &);
void bind_XCAFPrs_DataMapIteratorOfIndexedDataMapOfShapeStyle(py::module &);
void bind_XCAFPrs_DataMapOfStyleTransient(py::module &);
void bind_XCAFPrs_DataMapIteratorOfDataMapOfStyleTransient(py::module &);
void bind_XCAFPrs(py::module &);
void bind_XCAFPrs_AISObject(py::module &);
void bind_XCAFPrs_DataMapOfStyleShape(py::module &);
void bind_XCAFPrs_DataMapIteratorOfDataMapOfStyleShape(py::module &);
void bind_XCAFPrs_Driver(py::module &);

PYBIND11_MODULE(XCAFPrs, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Quantity");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.TDF");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.AIS");
py::module::import("OCCT.Graphic3d");
py::module::import("OCCT.PrsMgr");
py::module::import("OCCT.Prs3d");
py::module::import("OCCT.TPrsStd");

bind_XCAFPrs_Style(mod);
bind_XCAFPrs_IndexedDataMapOfShapeStyle(mod);
bind_XCAFPrs_DataMapIteratorOfIndexedDataMapOfShapeStyle(mod);
bind_XCAFPrs_DataMapOfStyleTransient(mod);
bind_XCAFPrs_DataMapIteratorOfDataMapOfStyleTransient(mod);
bind_XCAFPrs(mod);
bind_XCAFPrs_AISObject(mod);
bind_XCAFPrs_DataMapOfStyleShape(mod);
bind_XCAFPrs_DataMapIteratorOfDataMapOfStyleShape(mod);
bind_XCAFPrs_Driver(mod);

}
