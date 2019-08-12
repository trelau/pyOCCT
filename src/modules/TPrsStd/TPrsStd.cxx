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

void bind_TPrsStd_AISPresentation(py::module &);
void bind_TPrsStd_AISViewer(py::module &);
void bind_TPrsStd_Driver(py::module &);
void bind_TPrsStd_AxisDriver(py::module &);
void bind_TPrsStd_ConstraintDriver(py::module &);
void bind_TPrsStd_ConstraintTools(py::module &);
void bind_TPrsStd_DataMapOfGUIDDriver(py::module &);
void bind_TPrsStd_DataMapIteratorOfDataMapOfGUIDDriver(py::module &);
void bind_TPrsStd_DriverTable(py::module &);
void bind_TPrsStd_GeometryDriver(py::module &);
void bind_TPrsStd_NamedShapeDriver(py::module &);
void bind_TPrsStd_PlaneDriver(py::module &);
void bind_TPrsStd_PointDriver(py::module &);

PYBIND11_MODULE(TPrsStd, mod) {

py::module::import("OCCT.TDF");
py::module::import("OCCT.Standard");
py::module::import("OCCT.AIS");
py::module::import("OCCT.Graphic3d");
py::module::import("OCCT.Quantity");
py::module::import("OCCT.TDataXtd");
py::module::import("OCCT.V3d");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.Geom");
py::module::import("OCCT.NCollection");

bind_TPrsStd_AISPresentation(mod);
bind_TPrsStd_AISViewer(mod);
bind_TPrsStd_Driver(mod);
bind_TPrsStd_AxisDriver(mod);
bind_TPrsStd_ConstraintDriver(mod);
bind_TPrsStd_ConstraintTools(mod);
bind_TPrsStd_DataMapOfGUIDDriver(mod);
bind_TPrsStd_DataMapIteratorOfDataMapOfGUIDDriver(mod);
bind_TPrsStd_DriverTable(mod);
bind_TPrsStd_GeometryDriver(mod);
bind_TPrsStd_NamedShapeDriver(mod);
bind_TPrsStd_PlaneDriver(mod);
bind_TPrsStd_PointDriver(mod);

}
